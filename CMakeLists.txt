cmake_minimum_required(VERSION 3.17)

# standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# (debug) compiler flags
add_compile_options(-O1 -g3)
add_compile_options(-Wall -Wextra -pedantic -Werror)
add_compile_options(-fsanitize=address -fno-omit-frame-pointer) # ASAN
add_compile_options(-fsanitize=undefined -fsanitize=integer)    # UBSAN

# to build the application
project(application C)
project(application VERSION 0.0.1)
add_subdirectory(src/hello)
add_executable(application src/main.c src/hello/hello.h)
target_link_options(application PUBLIC "-Wl,-map,output.map") # linker memory map for the application
target_link_libraries(application hello -fsanitize=address -fno-omit-frame-pointer) #

# Packaging support
set(CPACK_PACKAGE_VENDOR "(c) Alexis Rigaud")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "(yet another) CI/CD template for C project")
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/licence.md")
set(CPACK_RESOURCE_FILE_README  "${CMAKE_CURRENT_SOURCE_DIR}/readme.md")
set(CPACK_SOURCE_GENERATOR "TGZ;ZIP")
set(CPACK_SOURCE_IGNORE_FILES /.idea /build)
include(CPack)

# to build the unit test
project(hello C)
add_subdirectory(unity)
target_compile_definitions(unity PUBLIC UNITY_INCLUDE_DOUBLE)
add_executable(unittest src/ut.c src/hello/hello.h)
target_link_libraries(unittest hello unity -fsanitize=address -fno-omit-frame-pointer)

