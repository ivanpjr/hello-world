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
CMAKE_COMMAND = /snap/clion/17/bin/cmake/bin/cmake

# The command to remove a file.
RM = /snap/clion/17/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/edbipjr/myLab/c++/AccountPtr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/edbipjr/myLab/c++/AccountPtr/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AccountPtr.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AccountPtr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AccountPtr.dir/flags.make

CMakeFiles/AccountPtr.dir/main.cpp.o: CMakeFiles/AccountPtr.dir/flags.make
CMakeFiles/AccountPtr.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/edbipjr/myLab/c++/AccountPtr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AccountPtr.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AccountPtr.dir/main.cpp.o -c /home/edbipjr/myLab/c++/AccountPtr/main.cpp

CMakeFiles/AccountPtr.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AccountPtr.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/edbipjr/myLab/c++/AccountPtr/main.cpp > CMakeFiles/AccountPtr.dir/main.cpp.i

CMakeFiles/AccountPtr.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AccountPtr.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/edbipjr/myLab/c++/AccountPtr/main.cpp -o CMakeFiles/AccountPtr.dir/main.cpp.s

CMakeFiles/AccountPtr.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/AccountPtr.dir/main.cpp.o.requires

CMakeFiles/AccountPtr.dir/main.cpp.o.provides: CMakeFiles/AccountPtr.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/AccountPtr.dir/build.make CMakeFiles/AccountPtr.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/AccountPtr.dir/main.cpp.o.provides

CMakeFiles/AccountPtr.dir/main.cpp.o.provides.build: CMakeFiles/AccountPtr.dir/main.cpp.o


# Object files for target AccountPtr
AccountPtr_OBJECTS = \
"CMakeFiles/AccountPtr.dir/main.cpp.o"

# External object files for target AccountPtr
AccountPtr_EXTERNAL_OBJECTS =

AccountPtr: CMakeFiles/AccountPtr.dir/main.cpp.o
AccountPtr: CMakeFiles/AccountPtr.dir/build.make
AccountPtr: CMakeFiles/AccountPtr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/edbipjr/myLab/c++/AccountPtr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AccountPtr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AccountPtr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AccountPtr.dir/build: AccountPtr

.PHONY : CMakeFiles/AccountPtr.dir/build

CMakeFiles/AccountPtr.dir/requires: CMakeFiles/AccountPtr.dir/main.cpp.o.requires

.PHONY : CMakeFiles/AccountPtr.dir/requires

CMakeFiles/AccountPtr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AccountPtr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AccountPtr.dir/clean

CMakeFiles/AccountPtr.dir/depend:
	cd /home/edbipjr/myLab/c++/AccountPtr/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/edbipjr/myLab/c++/AccountPtr /home/edbipjr/myLab/c++/AccountPtr /home/edbipjr/myLab/c++/AccountPtr/cmake-build-debug /home/edbipjr/myLab/c++/AccountPtr/cmake-build-debug /home/edbipjr/myLab/c++/AccountPtr/cmake-build-debug/CMakeFiles/AccountPtr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AccountPtr.dir/depend

