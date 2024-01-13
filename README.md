# Bal is project-building system for Linux written in c++
#### It uses TOML to declare projects and builds them with YOUR options

# Installation
## Dependencies:
- ```make```
- ```clang++```
## Installation progress
- ```git clone https://github.com/NotBalds/bald```
- ```cd bald```
- ```make```
I think it works only with normal users and only when ```~/.local/bin``` in your PATH
# Usage
```bald project new [name]``` - create a new bald project with name 'name' (creates in [projects directory](#Configuration))
```bald project open [name]``` - opens a bald project with name 'name' (looks for in [projects directory](#Configuration)
```bald``` - build and run bald project in current directory
```bald build``` - build bald project in current directory
```bald run``` - run bald project in current directory

# Configuration
## Projects directory
You can change your projects directory from ```~/coding/``` to another one (edit ```~/.config/bald/bald.config``` file)
## Project configuration
It's easy to understand, just look at baldfile.toml in bald project
