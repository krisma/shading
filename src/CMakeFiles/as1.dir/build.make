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
include src/CMakeFiles/as1.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/as1.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/as1.dir/flags.make

src/CMakeFiles/as1.dir/example_01.cpp.o: src/CMakeFiles/as1.dir/flags.make
src/CMakeFiles/as1.dir/example_01.cpp.o: src/example_01.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/krisma/Downloads/example_01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/as1.dir/example_01.cpp.o"
	cd /Users/krisma/Downloads/example_01/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/as1.dir/example_01.cpp.o -c /Users/krisma/Downloads/example_01/src/example_01.cpp

src/CMakeFiles/as1.dir/example_01.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/as1.dir/example_01.cpp.i"
	cd /Users/krisma/Downloads/example_01/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/krisma/Downloads/example_01/src/example_01.cpp > CMakeFiles/as1.dir/example_01.cpp.i

src/CMakeFiles/as1.dir/example_01.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/as1.dir/example_01.cpp.s"
	cd /Users/krisma/Downloads/example_01/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/krisma/Downloads/example_01/src/example_01.cpp -o CMakeFiles/as1.dir/example_01.cpp.s

src/CMakeFiles/as1.dir/example_01.cpp.o.requires:

.PHONY : src/CMakeFiles/as1.dir/example_01.cpp.o.requires

src/CMakeFiles/as1.dir/example_01.cpp.o.provides: src/CMakeFiles/as1.dir/example_01.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/as1.dir/build.make src/CMakeFiles/as1.dir/example_01.cpp.o.provides.build
.PHONY : src/CMakeFiles/as1.dir/example_01.cpp.o.provides

src/CMakeFiles/as1.dir/example_01.cpp.o.provides.build: src/CMakeFiles/as1.dir/example_01.cpp.o


# Object files for target as1
as1_OBJECTS = \
"CMakeFiles/as1.dir/example_01.cpp.o"

# External object files for target as1
as1_EXTERNAL_OBJECTS =

as1: src/CMakeFiles/as1.dir/example_01.cpp.o
as1: src/CMakeFiles/as1.dir/build.make
as1: glew/libglew.a
as1: glew/libglew.a
as1: glfw-3.2.1/src/libglfw3.a
as1: src/CMakeFiles/as1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/krisma/Downloads/example_01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../as1"
	cd /Users/krisma/Downloads/example_01/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/as1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/as1.dir/build: as1

.PHONY : src/CMakeFiles/as1.dir/build

src/CMakeFiles/as1.dir/requires: src/CMakeFiles/as1.dir/example_01.cpp.o.requires

.PHONY : src/CMakeFiles/as1.dir/requires

src/CMakeFiles/as1.dir/clean:
	cd /Users/krisma/Downloads/example_01/src && $(CMAKE_COMMAND) -P CMakeFiles/as1.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/as1.dir/clean

src/CMakeFiles/as1.dir/depend:
	cd /Users/krisma/Downloads/example_01 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/krisma/Downloads/example_01 /Users/krisma/Downloads/example_01/src /Users/krisma/Downloads/example_01 /Users/krisma/Downloads/example_01/src /Users/krisma/Downloads/example_01/src/CMakeFiles/as1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/as1.dir/depend

