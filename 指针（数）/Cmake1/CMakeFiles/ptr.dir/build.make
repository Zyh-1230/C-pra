# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zhouyuhan/Desktop/c/指针（数）/Cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zhouyuhan/Desktop/c/指针（数）/Cmake

# Include any dependencies generated for this target.
include CMakeFiles/ptr.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ptr.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ptr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ptr.dir/flags.make

CMakeFiles/ptr.dir/Users/zhouyuhan/Desktop/c/指针（数）/ptr.c.o: CMakeFiles/ptr.dir/flags.make
CMakeFiles/ptr.dir/Users/zhouyuhan/Desktop/c/指针（数）/ptr.c.o: /Users/zhouyuhan/Desktop/c/指针（数）/ptr.c
CMakeFiles/ptr.dir/Users/zhouyuhan/Desktop/c/指针（数）/ptr.c.o: CMakeFiles/ptr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/zhouyuhan/Desktop/c/指针（数）/Cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ptr.dir/Users/zhouyuhan/Desktop/c/指针（数）/ptr.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ptr.dir/Users/zhouyuhan/Desktop/c/指针（数）/ptr.c.o -MF CMakeFiles/ptr.dir/Users/zhouyuhan/Desktop/c/指针（数）/ptr.c.o.d -o CMakeFiles/ptr.dir/Users/zhouyuhan/Desktop/c/指针（数）/ptr.c.o -c /Users/zhouyuhan/Desktop/c/指针（数）/ptr.c

CMakeFiles/ptr.dir/Users/zhouyuhan/Desktop/c/指针（数）/ptr.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ptr.dir/Users/zhouyuhan/Desktop/c/指针（数）/ptr.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/zhouyuhan/Desktop/c/指针（数）/ptr.c > CMakeFiles/ptr.dir/Users/zhouyuhan/Desktop/c/指针（数）/ptr.c.i

CMakeFiles/ptr.dir/Users/zhouyuhan/Desktop/c/指针（数）/ptr.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ptr.dir/Users/zhouyuhan/Desktop/c/指针（数）/ptr.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/zhouyuhan/Desktop/c/指针（数）/ptr.c -o CMakeFiles/ptr.dir/Users/zhouyuhan/Desktop/c/指针（数）/ptr.c.s

# Object files for target ptr
ptr_OBJECTS = \
"CMakeFiles/ptr.dir/Users/zhouyuhan/Desktop/c/指针（数）/ptr.c.o"

# External object files for target ptr
ptr_EXTERNAL_OBJECTS =

ptr: CMakeFiles/ptr.dir/Users/zhouyuhan/Desktop/c/指针（数）/ptr.c.o
ptr: CMakeFiles/ptr.dir/build.make
ptr: CMakeFiles/ptr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/zhouyuhan/Desktop/c/指针（数）/Cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ptr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ptr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ptr.dir/build: ptr
.PHONY : CMakeFiles/ptr.dir/build

CMakeFiles/ptr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ptr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ptr.dir/clean

CMakeFiles/ptr.dir/depend:
	cd /Users/zhouyuhan/Desktop/c/指针（数）/Cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhouyuhan/Desktop/c/指针（数）/Cmake /Users/zhouyuhan/Desktop/c/指针（数）/Cmake /Users/zhouyuhan/Desktop/c/指针（数）/Cmake /Users/zhouyuhan/Desktop/c/指针（数）/Cmake /Users/zhouyuhan/Desktop/c/指针（数）/Cmake/CMakeFiles/ptr.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ptr.dir/depend

