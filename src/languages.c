#define _POSIX_C_SOURCE 200112L
#include "languages.h"
#include "templates.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void init_git(bool verbose) {
  run_command("git init", verbose);
  run_command("git branch -m main", verbose);
  run_command("git add .", verbose);
  run_command("git commit -m 'Initial commit from PMan'", verbose);
}

static void create_license(ProjectConfig cfg) {
  if (!cfg.use_license)
    return;
  if (strcmp(cfg.user_config.license, "MIT") == 0 ||
      strcmp(cfg.user_config.license, "mit") == 0) {
    write_formatted("LICENSE", mit_license_template, cfg.user_config.author);
  } else {
    write_formatted("LICENSE", "License: %s\n", cfg.user_config.license);
  }
}

void init_language(ProjectConfig cfg, const LanguagePreset *preset) {
  printf("Initializing %s project: %s\n", preset->display_name,
         cfg.project_name);

  for (int i = 0; i < 4; i++) {
    if (preset->files[i].filename != NULL && preset->files[i].content != NULL) {
      write_to_file(preset->files[i].filename, preset->files[i].content);
    }
  }

  for (int i = 0; i < 3; i++) {
    if (preset->init_cmds[i] != NULL) {
      if (preset->cmd_needs_project_name[i]) {
        char cmd[256];
        snprintf(cmd, sizeof(cmd), preset->init_cmds[i], cfg.project_name);
        run_command(cmd, cfg.verbose);
      } else {
        run_command(preset->init_cmds[i], cfg.verbose);
      }
    }
  }

  if (cfg.use_readme && preset->readme_template != NULL) {
    write_readme("README.md", preset->readme_template, cfg.project_name,
                 cfg.user_config.author, cfg.user_config.email);
  }

  create_license(cfg);

  if (cfg.use_git && !preset->skip_default_git_init) {
    init_git(cfg.verbose);
  }
}

void init_custom(ProjectConfig cfg, const char *script_path) {
  printf("Initializing custom project using: %s\n", script_path);
  setenv("PMAN_PROJECT_NAME", cfg.project_name, 1);
  setenv("PMAN_AUTHOR", cfg.user_config.author, 1);
  setenv("PMAN_EMAIL", cfg.user_config.email, 1);
  setenv("PMAN_LICENSE", cfg.user_config.license, 1);
  run_command(script_path, cfg.verbose);
  if (cfg.use_git)
    init_git(cfg.verbose);
}

const LanguagePreset language_presets[] = {
    {.name = "python",
     .display_name = "Python",
     .files = {{"main.py", python_main_template},
               {".gitignore", python_gitignore_template}},
     .readme_template = python_readme_template,
     .init_cmds = {"touch requirements.txt", "python3 -m venv .venv"},
     .cmd_needs_project_name = {false, false},
     .skip_default_git_init = false},
    {.name = "c",
     .display_name = "C",
     .files = {{"main.c", c_main_template},
               {".gitignore", "*.o\nmain\n"},
               {"Makefile",
                "all:\n\tgcc main.c -o main\nclean:\n\trm -f main\n"}},
     .readme_template = c_readme_template,
     .skip_default_git_init = false},
    {.name = "cpp",
     .display_name = "C++",
     .files = {{"main.cpp", cpp_main_template},
               {".gitignore", "*.o\nmain\n"},
               {"Makefile", cpp_makefile_template}},
     .readme_template = cpp_readme_template,
     .skip_default_git_init = false},
    {.name = "java",
     .display_name = "Java",
     .files = {{"Main.java", java_main_template},
               {".gitignore", java_gitignore_template}},
     .readme_template = java_readme_template,
     .skip_default_git_init = false},
    {.name = "go",
     .display_name = "Go",
     .files = {{"main.go", go_main_template}},
     .readme_template = go_readme_template,
     .init_cmds = {"go mod init %s"},
     .cmd_needs_project_name = {true},
     .skip_default_git_init = false},
    {.name = "rust",
     .display_name = "Rust",
     .readme_template = rust_readme_template,
     .init_cmds = {"cargo init --name %s ."},
     .cmd_needs_project_name = {true},
     .skip_default_git_init = true},
    {.name = "node",
     .display_name = "Node",
     .files = {{"index.js", node_index_template},
               {".gitignore", node_gitignore_template}},
     .readme_template = node_readme_template,
     .init_cmds = {"npm init -y"},
     .cmd_needs_project_name = {false},
     .skip_default_git_init = false},
    {.name = "csharp",
     .display_name = "C#",
     .files = {{".gitignore", "bin/\nobj/\n"}},
     .readme_template = csharp_readme_template,
     .init_cmds = {"dotnet new console --force"},
     .cmd_needs_project_name = {false},
     .skip_default_git_init = false},
    {.name = "ruby",
     .display_name = "Ruby",
     .files = {{"main.rb", ruby_main_template},
               {"Gemfile", "source 'https://rubygems.org'\n"}},
     .readme_template = ruby_readme_template,
     .skip_default_git_init = false},
    {.name = "php",
     .display_name = "PHP",
     .files = {{"index.php", php_index_template}},
     .readme_template = php_readme_template,
     .skip_default_git_init = false},
    {.name = "html",
     .display_name = "HTML/Web",
     .files = {{"index.html", html_index_template},
               {"style.css", html_style_template},
               {"script.js", html_script_template}},
     .readme_template = html_readme_template,
     .skip_default_git_init = false},
    {.name = "bash",
     .display_name = "Bash",
     .files = {{"main.sh", bash_script_template}},
     .readme_template = bash_readme_template,
     .init_cmds = {"chmod +x main.sh"},
     .cmd_needs_project_name = {false},
     .skip_default_git_init = false}};

const int num_language_presets =
    sizeof(language_presets) / sizeof(LanguagePreset);
