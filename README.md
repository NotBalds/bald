# NotBalds/bald
## Bald is project build system for *nix systems written in c++
#### It uses TOML to declare projects and builds them with YOUR options

# Installation
## Nix flakes:
Bald provides a ```flake.nix``` with defaultPackage for linux and darwin systems.
## Manual (script):
### Dependencies:
- ```make```
- ```g++```
- ```git```
### Installation progress
- ```curl -L -s https://github.com/NotBalds/bald/raw/main/install.sh | sh```
- It will copy ```bald``` binary to your ~/.local/bin, so, please, make sure that it is in your PATH
# Usage
- ```bald init``` - init project in current directory (create baldfile, not source)
- ```bald``` - build and run bald project in current directory
- ```bald build``` - build bald project in current directory
- ```bald run``` - run bald project in current directory

# Project configuration
It's easy to understand, just look at baldfile.toml in bald project
