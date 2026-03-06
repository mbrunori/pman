#ifndef LANGUAGES_H
#define LANGUAGES_H

#include <stdbool.h>
#include "config.h"

typedef struct {
    bool use_git;
    bool use_readme;
    bool use_license;
    bool verbose;
    bool track;
    const char *project_name;
    PManConfig user_config;
} ProjectConfig;

typedef struct {
    const char *filename;
    const char *content;
} FileTemplate;

typedef struct {
    const char *name;
    const char *display_name;
    FileTemplate files[4];
    const char *readme_template;
    const char *init_cmds[3];
    bool cmd_needs_project_name[3];
    bool skip_default_git_init;
} LanguagePreset;

void init_language(ProjectConfig cfg, const LanguagePreset *preset);
void init_custom(ProjectConfig cfg, const char *script_path);

extern const LanguagePreset language_presets[];
extern const int num_language_presets;

#endif
