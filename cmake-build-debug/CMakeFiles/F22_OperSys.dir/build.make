# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ruslan/F22_OperSys

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ruslan/F22_OperSys/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/F22_OperSys.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/F22_OperSys.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/F22_OperSys.dir/flags.make

CMakeFiles/F22_OperSys.dir/week4/ex2.c.o: CMakeFiles/F22_OperSys.dir/flags.make
CMakeFiles/F22_OperSys.dir/week4/ex2.c.o: ../week4/ex2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ruslan/F22_OperSys/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/F22_OperSys.dir/week4/ex2.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/F22_OperSys.dir/week4/ex2.c.o   -c /home/ruslan/F22_OperSys/week4/ex2.c

CMakeFiles/F22_OperSys.dir/week4/ex2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/F22_OperSys.dir/week4/ex2.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ruslan/F22_OperSys/week4/ex2.c > CMakeFiles/F22_OperSys.dir/week4/ex2.c.i

CMakeFiles/F22_OperSys.dir/week4/ex2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/F22_OperSys.dir/week4/ex2.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ruslan/F22_OperSys/week4/ex2.c -o CMakeFiles/F22_OperSys.dir/week4/ex2.c.s

# Object files for target F22_OperSys
F22_OperSys_OBJECTS = \
"CMakeFiles/F22_OperSys.dir/week4/ex2.c.o"

# External object files for target F22_OperSys
F22_OperSys_EXTERNAL_OBJECTS =

F22_OperSys: CMakeFiles/F22_OperSys.dir/week4/ex2.c.o
F22_OperSys: CMakeFiles/F22_OperSys.dir/build.make
F22_OperSys: CMakeFiles/F22_OperSys.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ruslan/F22_OperSys/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable F22_OperSys"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/F22_OperSys.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/F22_OperSys.dir/build: F22_OperSys

.PHONY : CMakeFiles/F22_OperSys.dir/build

CMakeFiles/F22_OperSys.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/F22_OperSys.dir/cmake_clean.cmake
.PHONY : CMakeFiles/F22_OperSys.dir/clean

CMakeFiles/F22_OperSys.dir/depend:
	cd /home/ruslan/F22_OperSys/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ruslan/F22_OperSys /home/ruslan/F22_OperSys /home/ruslan/F22_OperSys/cmake-build-debug /home/ruslan/F22_OperSys/cmake-build-debug /home/ruslan/F22_OperSys/cmake-build-debug/CMakeFiles/F22_OperSys.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/F22_OperSys.dir/depend

