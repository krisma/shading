# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.4.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.4.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/krisma/Downloads/example_01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/krisma/Downloads/example_01

# Include any dependencies generated for this target.
include glfw-3.2.1/tests/CMakeFiles/iconify.dir/depend.make

# Include the progress variables for this target.
include glfw-3.2.1/tests/CMakeFiles/iconify.dir/progress.make

# Include the compile flags for this target's objects.
include glfw-3.2.1/tests/CMakeFiles/iconify.dir/flags.make

glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.o: glfw-3.2.1/tests/CMakeFiles/iconify.dir/flags.make
glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.o: glfw-3.2.1/tests/iconify.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/krisma/Downloads/example_01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.o"
	cd /Users/krisma/Downloads/example_01/glfw-3.2.1/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/iconify.dir/iconify.c.o   -c /Users/krisma/Downloads/example_01/glfw-3.2.1/tests/iconify.c

glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/iconify.dir/iconify.c.i"
	cd /Users/krisma/Downloads/example_01/glfw-3.2.1/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/krisma/Downloads/example_01/glfw-3.2.1/tests/iconify.c > CMakeFiles/iconify.dir/iconify.c.i

glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/iconify.dir/iconify.c.s"
	cd /Users/krisma/Downloads/example_01/glfw-3.2.1/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/krisma/Downloads/example_01/glfw-3.2.1/tests/iconify.c -o CMakeFiles/iconify.dir/iconify.c.s

glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.o.requires:

.PHONY : glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.o.requires

glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.o.provides: glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.o.requires
	$(MAKE) -f glfw-3.2.1/tests/CMakeFiles/iconify.dir/build.make glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.o.provides.build
.PHONY : glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.o.provides

glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.o.provides.build: glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.o


glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.o: glfw-3.2.1/tests/CMakeFiles/iconify.dir/flags.make
glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.o: glfw-3.2.1/deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/krisma/Downloads/example_01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.o"
	cd /Users/krisma/Downloads/example_01/glfw-3.2.1/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/iconify.dir/__/deps/getopt.c.o   -c /Users/krisma/Downloads/example_01/glfw-3.2.1/deps/getopt.c

glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/iconify.dir/__/deps/getopt.c.i"
	cd /Users/krisma/Downloads/example_01/glfw-3.2.1/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/krisma/Downloads/example_01/glfw-3.2.1/deps/getopt.c > CMakeFiles/iconify.dir/__/deps/getopt.c.i

glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/iconify.dir/__/deps/getopt.c.s"
	cd /Users/krisma/Downloads/example_01/glfw-3.2.1/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/krisma/Downloads/example_01/glfw-3.2.1/deps/getopt.c -o CMakeFiles/iconify.dir/__/deps/getopt.c.s

glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.o.requires:

.PHONY : glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.o.requires

glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.o.provides: glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.o.requires
	$(MAKE) -f glfw-3.2.1/tests/CMakeFiles/iconify.dir/build.make glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.o.provides.build
.PHONY : glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.o.provides

glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.o.provides.build: glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.o


glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.o: glfw-3.2.1/tests/CMakeFiles/iconify.dir/flags.make
glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.o: glfw-3.2.1/deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/krisma/Downloads/example_01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.o"
	cd /Users/krisma/Downloads/example_01/glfw-3.2.1/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/iconify.dir/__/deps/glad.c.o   -c /Users/krisma/Downloads/example_01/glfw-3.2.1/deps/glad.c

glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/iconify.dir/__/deps/glad.c.i"
	cd /Users/krisma/Downloads/example_01/glfw-3.2.1/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/krisma/Downloads/example_01/glfw-3.2.1/deps/glad.c > CMakeFiles/iconify.dir/__/deps/glad.c.i

glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/iconify.dir/__/deps/glad.c.s"
	cd /Users/krisma/Downloads/example_01/glfw-3.2.1/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/krisma/Downloads/example_01/glfw-3.2.1/deps/glad.c -o CMakeFiles/iconify.dir/__/deps/glad.c.s

glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.o.requires:

.PHONY : glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.o.requires

glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.o.provides: glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.o.requires
	$(MAKE) -f glfw-3.2.1/tests/CMakeFiles/iconify.dir/build.make glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.o.provides.build
.PHONY : glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.o.provides

glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.o.provides.build: glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.o


# Object files for target iconify
iconify_OBJECTS = \
"CMakeFiles/iconify.dir/iconify.c.o" \
"CMakeFiles/iconify.dir/__/deps/getopt.c.o" \
"CMakeFiles/iconify.dir/__/deps/glad.c.o"

# External object files for target iconify
iconify_EXTERNAL_OBJECTS =

glfw-3.2.1/tests/iconify: glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.o
glfw-3.2.1/tests/iconify: glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.o
glfw-3.2.1/tests/iconify: glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.o
glfw-3.2.1/tests/iconify: glfw-3.2.1/tests/CMakeFiles/iconify.dir/build.make
glfw-3.2.1/tests/iconify: glfw-3.2.1/src/libglfw3.a
glfw-3.2.1/tests/iconify: glfw-3.2.1/tests/CMakeFiles/iconify.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/krisma/Downloads/example_01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable iconify"
	cd /Users/krisma/Downloads/example_01/glfw-3.2.1/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/iconify.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
glfw-3.2.1/tests/CMakeFiles/iconify.dir/build: glfw-3.2.1/tests/iconify

.PHONY : glfw-3.2.1/tests/CMakeFiles/iconify.dir/build

glfw-3.2.1/tests/CMakeFiles/iconify.dir/requires: glfw-3.2.1/tests/CMakeFiles/iconify.dir/iconify.c.o.requires
glfw-3.2.1/tests/CMakeFiles/iconify.dir/requires: glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.o.requires
glfw-3.2.1/tests/CMakeFiles/iconify.dir/requires: glfw-3.2.1/tests/CMakeFiles/iconify.dir/__/deps/glad.c.o.requires

.PHONY : glfw-3.2.1/tests/CMakeFiles/iconify.dir/requires

glfw-3.2.1/tests/CMakeFiles/iconify.dir/clean:
	cd /Users/krisma/Downloads/example_01/glfw-3.2.1/tests && $(CMAKE_COMMAND) -P CMakeFiles/iconify.dir/cmake_clean.cmake
.PHONY : glfw-3.2.1/tests/CMakeFiles/iconify.dir/clean

glfw-3.2.1/tests/CMakeFiles/iconify.dir/depend:
	cd /Users/krisma/Downloads/example_01 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/krisma/Downloads/example_01 /Users/krisma/Downloads/example_01/glfw-3.2.1/tests /Users/krisma/Downloads/example_01 /Users/krisma/Downloads/example_01/glfw-3.2.1/tests /Users/krisma/Downloads/example_01/glfw-3.2.1/tests/CMakeFiles/iconify.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : glfw-3.2.1/tests/CMakeFiles/iconify.dir/depend

