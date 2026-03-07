<img src="https://r2cdn.perplexity.ai/pplx-full-logo-primary-dark%402x.png" style="height:64px;margin-right:32px"/>

# pman

**Project lifecycle manager for C99.** Bootstraps projects and tracks repository health across the filesystem.[^1_1]

## 🚀 Motivation

Fragmented project setups increase cognitive load and lead to inconsistent environments. `pman` provides a single interface to automate bootstrapping and maintain a centralized index of scattered projects.[^1_1]

## ✨ Core Features

### 📋 Standardization

Ensures every project starts with a consistent structure. Generates boilerplate code, `.gitignore` files, and entry points based on 12 built-in language presets or user-defined templates.[^1_1]

### ⚡ Automation

Replaces repetitive setup tasks with one command.

- Initializes Git repositories with standard branch naming.
- Creates virtual environments and dependency files.
- Generates LICENSE and README files using author metadata.
- Executes language-specific initialization (e.g., `go mod init`, `npm init`).[^1_1]


### 🗂️ Centralization

Maintains a system-wide registry to audit projects across different directories.

- `pman status`: Batch audits Git health for all registered projects.
- `pman list`: Identifies active and missing project paths.
- `pman prune`: Removes dead paths from the index.[^1_1]


### 🔧 Extensibility

Define custom bootstrapping logic by placing shell scripts in `~/.config/pman/templates/`. Scripts receive project metadata via environment variables.[^1_1]

## 📦 Installation

```bash
make
make setup
sudo make install
```


## 🚀 Quick Start

### Initialize Project

In a new directory:

```bash
pman init <lang> <name>
```

Or current directory:

```bash
pman init <lang>
```


### Manage Projects

- `pman status` – Audit all projects.
- `pman list` – List projects.
- `pman prune` – Clean registry.[^1_1]


### Flags

| Flag | Description |
| :-- | :-- |
| `-d, --dir <path>` | Target directory. |
| `-g, --no-git` | Skip Git init. |
| `-r, --no-readme` | Skip README. |
| `-l, --no-license` | Skip LICENSE. |
| `-n, --no-track` | Skip tracking. |
| `-v, --verbose` | Verbose output. |

## 🛠️ Custom Templates

1. `mkdir -p ~/.config/pman/templates/<template_name>`
2. `touch ~/.config/pman/templates/<template_name>/init.sh`
3. `chmod +x ~/.config/pman/templates/<template_name>/init.sh`

**Example `init.sh`:**

```bash
#!/bin/bash
mkdir src docs
touch src/main.c
echo "Created by $PMAN_AUTHOR" > README.md
```

Invoke: `pman init <template_name> [name]`[^1_1]

## ⚙️ Configuration

Edit `~/.pmanrc`:

- `author`: Name for LICENSE/README.
- `email`: Contact info.
- `license`: Default (e.g., MIT).[^1_1]

**Note:** No specific demo images/GIFs for this exact tool were found online, so use placeholders like  for terminal recordings (e.g., via asciinema). Replace with actual captures of `pman init` and `pman status` for best visuals.[^1_2]
<span style="display:none">[^1_10][^1_11][^1_3][^1_4][^1_5][^1_6][^1_7][^1_8][^1_9]</span>

<div align="center">⁂</div>

[^1_1]: README.md

[^1_2]: https://mcpmarket.com/tools/skills/terminal-demo-generator

[^1_3]: https://learn.tearfund.org/-/media/learn/resources/series/roots/2020-tearfund-roots5-project-cycle-management-en.pdf

[^1_4]: https://www.academia.edu/108259266/Product_Life_Cycle_Management

[^1_5]: https://github.com/fffaraz/awesome-cpp

[^1_6]: https://devblogs.microsoft.com/visualstudio/visual-studio-2019-v16-8/

[^1_7]: https://erlang.org/documentation/doc-5.7.1/pdf/pman-2.7.pdf

[^1_8]: https://github.com/Moguri/pman/blob/master/README.md

[^1_9]: https://mdbootstrap.com/docs/standard/tools/builders/animations/

[^1_10]: https://github.com/matsune/pman

[^1_11]: https://webdesign.tutsplus.com/how-to-build-an-animated-bootstrap-landing-page-with-material-kit--cms-34267t


---

# pman

**Project lifecycle manager for C99.** Bootstraps projects and tracks repository health across the filesystem.[^2_1]

## 🚀 Motivation

Fragmented project setups increase cognitive load and lead to inconsistent environments. `pman` provides a single interface to automate bootstrapping and maintain a centralized index of scattered projects.[^2_1]

## ✨ Core Features

### 📋 Standardization

Ensures every project starts with a consistent structure. Generates boilerplate code, `.gitignore` files, and entry points based on 12 built-in language presets or user-defined templates.[^2_1]

### ⚡ Automation

Replaces repetitive setup tasks with one command.

- Initializes Git repositories with standard branch naming.
- Creates virtual environments and dependency files.
- Generates LICENSE and README files using author metadata.
- Executes language-specific initialization (e.g., `go mod init`, `npm init`).[^2_1]


### 🗂️ Centralization

Maintains a system-wide registry to audit projects across different directories.

- `pman status`: Batch audits Git health for all registered projects.
- `pman list`: Identifies active and missing project paths.
- `pman prune`: Removes dead paths from the index.[^2_1]


### 🔧 Extensibility

Define custom bootstrapping logic by placing shell scripts in `~/.config/pman/templates/`. Scripts receive project metadata via environment variables.[^2_1]

## 📦 Installation

```bash
git clone <repo-url>
cd pman
make
make setup
sudo make install
```


## 🚀 Quick Start

### Initialize a Project

```
pman init c99 myproject
```

This creates a full C99 project structure with Git, LICENSE, and README.[^2_1]

### Audit Projects

```
pman status
```

Batch check Git status across all registered projects.[^2_1]

### List and Prune

```
pman list
pman prune
```

Manage your project registry.[^2_1]

## 🛠️ Flags Reference

| Flag | Description |
| :-- | :-- |
| `-d, --dir <path>` | Specify target directory |
| `-g, --no-git` | Disable Git initialization |
| `-r, --no-readme` | Disable README generation |
| `-l, --no-license` | Disable LICENSE generation |
| `-n, --no-track` | Disable registry tracking |
| `-v, --verbose` | Verbose output |

## 🎨 Custom Templates

1. Create directory: `mkdir -p ~/.config/pman/templates/mytemplate`
2. Add script: `touch ~/.config/pman/templates/mytemplate/init.sh`
3. Make executable: `chmod +x ~/.config/pman/templates/mytemplate/init.sh`

**Example `init.sh`:**

```bash
#!/bin/bash
mkdir -p src docs tests
touch src/main.c src/utils.c
echo "# MyProject\nCreated by $PMAN_AUTHOR ($PMAN_EMAIL)" > README.md
git add . && git commit -m "Initial bootstrap by pman"
```

Use it: `pman init mytemplate coolproject`[^2_1]

## ⚙️ Configuration (~/.pmanrc)

```
author = "Your Name"
email = "you@example.com"
license = "MIT"
```

Customizes generated files automatically.[^2_1]

## 📊 Commands Overview

| Command | Purpose |
| :-- | :-- |
| `pman init <lang> [name]` | Bootstrap new project |
| `pman status` | Check all projects health |
| `pman list` | Show registered projects |
| `pman prune` | Remove stale entries |

**Pro Tip:** Record demos with `asciinema` for GIFs: `asciinema rec demo.cast` then convert to GIF for GitHub.[^2_2]

<div align="center">⁂</div>

[^2_1]: README.md

[^2_2]: https://mcpmarket.com/tools/skills/terminal-demo-generator

