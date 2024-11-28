[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)     

# Template CI/CD

This is a CI/CD template pre-configured for C projects.

It intends to gather the latest best practices and can be used to start an OSS projects.

## Features

It features/support the following :

Name                   | Tools
-----------------------|-------
Language               | C11
SCM                    | git
branching              | gitflow
environment            | posix (linux/macos)
shell                  | zsh
package manager        | TBD
build system           | Cmake
supported compiler     | Clang
cross-compilation      | No
code style enforcement | Clang-format
static-analysis        | Clang-tidy
best practice          | ASAN, UBSAN 
unit-testing           | [unity](https://github.com/ThrowTheSwitch/Unity) framework
packaging              | CPack
CI                     | Jenkins
Cloud SCM              | Bitbucket

## Architecture :

We configure the external tools in a minimal fashion, but they are managed through config files in the codebase. 

The goal is to build & deploy a tested C Application.

## Application Design :

The application does noting but outputting "hello, world." on stdout.

It is build using an external .c/.h module named hello, build as a linked library.

## Dependencies

`unity` framework

## To build :

`mkdir build; cd build ; cmake .. && make`

## To run UT :

`./unittest`

## To run Application :

`./application`

## TODO list :

- move to `cunity` lib framework
- environment checkers 
- make checks
- automatic tagging when building + link to version
- manage app and module versions
- run checks when checking-in
- support non-posix environment (windows)
- dependencies on tools management (package manager)
- mater/develop branch protection
- feature/issue tracking + checker
- front-end automatic checks/operations
    - code style
    - static analysis
- support github/gitlab
- support jenkins build integration
- automatic trigger with wekhooks
- support automatic tagging / versioning
- support pull-request automatic checks
- support C compiler other than clang
- support cross-compilation
- support unit-test / application run on 
    - simulator (renode)
    - hardware farm
- bitbucket pipeline
- dockerfile
- requirement management system integration (codebeamer)
- comprehensive documentation
    - automatic generation with doxygen
    - latex beamer for all CI/CD settings
    - wiki
- rules
    - contributing
    - code style
    - code of conduct
    - embedded development checklist
- manage a contributor mail-list
- CTest, CDash
- manage release notes
