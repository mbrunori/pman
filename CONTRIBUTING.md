# Contributing

## Standards
- C99
- No dependencies
- Input validation via `is_safe_name` and `is_safe_path`
- No comments

## System Architecture

### Execution Flow
1. `main.c` loads `PManConfig` from `~/.pmanrc`.
2. `main.c` matches subcommands against the `COMMANDS` table.
3. `handle_init` parses flags and resolves project name/path.
4. `execute_init` in `main.c` calls `init_language` or `init_custom` in `languages.c`.
5. `register_project` in `registry.c` appends the project to the registry.

### Logic
- Languages are defined in `language_presets[]` as data in `languages.c`. Adding a language requires a new struct in this array.
- The tool uses the filesystem and a flat-file registry (`registry.txt`).
- User-provided names and paths pass through a whitelist filter before execution.

## Data Structures

### `PManConfig`
User preferences from `~/.pmanrc`.
- `char author[128]`: Author name
- `char email[128]`: Author email
- `char license[32]`: License type
- `bool verbose`: Verbosity flag

### `ProjectConfig`
Specific project settings.
- `bool use_git`: Initialize Git
- `bool use_readme`: Create README
- `bool use_license`: Create LICENSE
- `bool verbose`: Show output
- `bool track`: Registry tracking
- `const char *project_name`: Name
- `PManConfig user_config`: User data

### `LanguagePreset`
Defines project bootstrapping.
- `const char *name`: Identifier
- `const char *display_name`: Print name
- `FileTemplate files[4]`: Files to create
- `const char *readme_template`: README content
- `const char *init_cmds[3]`: Shell commands
- `bool cmd_needs_project_name[3]`: Command formatting flag
- `bool skip_default_git_init`: Git override

## Functions

### Configuration (`src/config.c`)
- `PManConfig load_config(void)`: Returns user config from disk.

### Languages (`src/languages.c`)
- `void init_language(ProjectConfig cfg, const LanguagePreset *preset)`: Executes project creation based on preset data.
- `void init_custom(ProjectConfig cfg, const char *script_path)`: Runs external script for project creation.

### Registry (`src/registry.c`)
- `void register_project(...)`: Adds project to registry file.
- `void list_projects(void)`: Lists registry entries.
- `void check_all_status(void)`: Runs `git status` on registry entries.
- `void prune_registry(void)`: Removes missing projects from registry.

### Utilities (`src/utils.c`)
- `int run_command(...)`: Wrapper for `system()`.
- `bool write_to_file(...)`: File writer.
- `bool create_and_enter_dir(...)`: Directory manager.
- `bool is_safe_name(...)`: Name whitelist.
- `bool is_safe_path(...)`: Path whitelist.

## Roadmap
- Parallel status check (pthreads)
- SQLite registry backend
- Command aliases
