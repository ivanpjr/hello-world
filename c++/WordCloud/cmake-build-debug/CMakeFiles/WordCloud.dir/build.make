# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /snap/clion/19/bin/cmake/bin/cmake

# The command to remove a file.
RM = /snap/clion/19/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/edbipjr/myLab/c++/WordCloud

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/edbipjr/myLab/c++/WordCloud/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/WordCloud.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/WordCloud.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WordCloud.dir/flags.make

CMakeFiles/WordCloud.dir/WordCloud.cpp.o: CMakeFiles/WordCloud.dir/flags.make
CMakeFiles/WordCloud.dir/WordCloud.cpp.o: ../WordCloud.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/edbipjr/myLab/c++/WordCloud/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WordCloud.dir/WordCloud.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WordCloud.dir/WordCloud.cpp.o -c /home/edbipjr/myLab/c++/WordCloud/WordCloud.cpp

CMakeFiles/WordCloud.dir/WordCloud.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WordCloud.dir/WordCloud.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/edbipjr/myLab/c++/WordCloud/WordCloud.cpp > CMakeFiles/WordCloud.dir/WordCloud.cpp.i

CMakeFiles/WordCloud.dir/WordCloud.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WordCloud.dir/WordCloud.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/edbipjr/myLab/c++/WordCloud/WordCloud.cpp -o CMakeFiles/WordCloud.dir/WordCloud.cpp.s

CMakeFiles/WordCloud.dir/WordCloud.cpp.o.requires:

.PHONY : CMakeFiles/WordCloud.dir/WordCloud.cpp.o.requires

CMakeFiles/WordCloud.dir/WordCloud.cpp.o.provides: CMakeFiles/WordCloud.dir/WordCloud.cpp.o.requires
	$(MAKE) -f CMakeFiles/WordCloud.dir/build.make CMakeFiles/WordCloud.dir/WordCloud.cpp.o.provides.build
.PHONY : CMakeFiles/WordCloud.dir/WordCloud.cpp.o.provides

CMakeFiles/WordCloud.dir/WordCloud.cpp.o.provides.build: CMakeFiles/WordCloud.dir/WordCloud.cpp.o


# Object files for target WordCloud
WordCloud_OBJECTS = \
"CMakeFiles/WordCloud.dir/WordCloud.cpp.o"

# External object files for target WordCloud
WordCloud_EXTERNAL_OBJECTS =

WordCloud: CMakeFiles/WordCloud.dir/WordCloud.cpp.o
WordCloud: CMakeFiles/WordCloud.dir/build.make
WordCloud: CMakeFiles/WordCloud.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/edbipjr/myLab/c++/WordCloud/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable WordCloud"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WordCloud.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WordCloud.dir/build: WordCloud

.PHONY : CMakeFiles/WordCloud.dir/build

CMakeFiles/WordCloud.dir/requires: CMakeFiles/WordCloud.dir/WordCloud.cpp.o.requires

.PHONY : CMakeFiles/WordCloud.dir/requires

CMakeFiles/WordCloud.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/WordCloud.dir/cmake_clean.cmake
.PHONY : CMakeFiles/WordCloud.dir/clean

CMakeFiles/WordCloud.dir/depend:
	cd /home/edbipjr/myLab/c++/WordCloud/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/edbipjr/myLab/c++/WordCloud /home/edbipjr/myLab/c++/WordCloud /home/edbipjr/myLab/c++/WordCloud/cmake-build-debug /home/edbipjr/myLab/c++/WordCloud/cmake-build-debug /home/edbipjr/myLab/c++/WordCloud/cmake-build-debug/CMakeFiles/WordCloud.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/WordCloud.dir/depend

