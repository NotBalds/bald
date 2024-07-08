# Bald is project-building system for Linux written in c++
#### It uses TOML to declare projects and builds them with YOUR options

# Installation
## Dependencies:
- ```make```
- ```g++```
- ```git```
## Installation progress
- ```curl -s https://git.proggers.ru/NotBalds/bald/raw/branch/main/install.sh | sh```
- I think it works only with normal users and only when ```~/.local/bin``` in your PATH
# Usage
- ```bald init``` - init project in current directory (create baldfile, not source)
- ```bald``` - build and run bald project in current directory
- ```bald build``` - build bald project in current directory
- ```bald run``` - run bald project in current directory

# Configuration
## Projects directory
You can change your projects directory from ```~/coding/``` to another one (edit ```~/.config/bald/bald.config``` file)
## Project configuration
It's easy to understand, just look at baldfile.toml in bald project
