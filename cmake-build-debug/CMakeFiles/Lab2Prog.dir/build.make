# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/daria/Documents/clion-2019.3.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/daria/Documents/clion-2019.3.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/daria/Documents/labs2proga2sem/lab2TextFilesProcessing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/daria/Documents/labs2proga2sem/lab2TextFilesProcessing/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab2Prog.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab2Prog.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab2Prog.dir/flags.make

CMakeFiles/Lab2Prog.dir/main.cpp.o: CMakeFiles/Lab2Prog.dir/flags.make
CMakeFiles/Lab2Prog.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daria/Documents/labs2proga2sem/lab2TextFilesProcessing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab2Prog.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab2Prog.dir/main.cpp.o -c /home/daria/Documents/labs2proga2sem/lab2TextFilesProcessing/main.cpp

CMakeFiles/Lab2Prog.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab2Prog.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/daria/Documents/labs2proga2sem/lab2TextFilesProcessing/main.cpp > CMakeFiles/Lab2Prog.dir/main.cpp.i

CMakeFiles/Lab2Prog.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab2Prog.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/daria/Documents/labs2proga2sem/lab2TextFilesProcessing/main.cpp -o CMakeFiles/Lab2Prog.dir/main.cpp.s

# Object files for target Lab2Prog
Lab2Prog_OBJECTS = \
"CMakeFiles/Lab2Prog.dir/main.cpp.o"

# External object files for target Lab2Prog
Lab2Prog_EXTERNAL_OBJECTS =

Lab2Prog: CMakeFiles/Lab2Prog.dir/main.cpp.o
Lab2Prog: CMakeFiles/Lab2Prog.dir/build.make
Lab2Prog: CMakeFiles/Lab2Prog.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/daria/Documents/labs2proga2sem/lab2TextFilesProcessing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lab2Prog"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab2Prog.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab2Prog.dir/build: Lab2Prog

.PHONY : CMakeFiles/Lab2Prog.dir/build

CMakeFiles/Lab2Prog.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab2Prog.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab2Prog.dir/clean

CMakeFiles/Lab2Prog.dir/depend:
	cd /home/daria/Documents/labs2proga2sem/lab2TextFilesProcessing/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/daria/Documents/labs2proga2sem/lab2TextFilesProcessing /home/daria/Documents/labs2proga2sem/lab2TextFilesProcessing /home/daria/Documents/labs2proga2sem/lab2TextFilesProcessing/cmake-build-debug /home/daria/Documents/labs2proga2sem/lab2TextFilesProcessing/cmake-build-debug /home/daria/Documents/labs2proga2sem/lab2TextFilesProcessing/cmake-build-debug/CMakeFiles/Lab2Prog.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab2Prog.dir/depend

