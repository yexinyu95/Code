# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Code\DataStructure\13Queue

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Code\DataStructure\13Queue\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/13Queue.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/13Queue.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/13Queue.dir/flags.make

CMakeFiles/13Queue.dir/main.cpp.obj: CMakeFiles/13Queue.dir/flags.make
CMakeFiles/13Queue.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Code\DataStructure\13Queue\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/13Queue.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\13Queue.dir\main.cpp.obj -c D:\Code\DataStructure\13Queue\main.cpp

CMakeFiles/13Queue.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/13Queue.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Code\DataStructure\13Queue\main.cpp > CMakeFiles\13Queue.dir\main.cpp.i

CMakeFiles/13Queue.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/13Queue.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Code\DataStructure\13Queue\main.cpp -o CMakeFiles\13Queue.dir\main.cpp.s

# Object files for target 13Queue
13Queue_OBJECTS = \
"CMakeFiles/13Queue.dir/main.cpp.obj"

# External object files for target 13Queue
13Queue_EXTERNAL_OBJECTS =

13Queue.exe: CMakeFiles/13Queue.dir/main.cpp.obj
13Queue.exe: CMakeFiles/13Queue.dir/build.make
13Queue.exe: CMakeFiles/13Queue.dir/linklibs.rsp
13Queue.exe: CMakeFiles/13Queue.dir/objects1.rsp
13Queue.exe: CMakeFiles/13Queue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Code\DataStructure\13Queue\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 13Queue.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\13Queue.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/13Queue.dir/build: 13Queue.exe

.PHONY : CMakeFiles/13Queue.dir/build

CMakeFiles/13Queue.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\13Queue.dir\cmake_clean.cmake
.PHONY : CMakeFiles/13Queue.dir/clean

CMakeFiles/13Queue.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Code\DataStructure\13Queue D:\Code\DataStructure\13Queue D:\Code\DataStructure\13Queue\cmake-build-debug D:\Code\DataStructure\13Queue\cmake-build-debug D:\Code\DataStructure\13Queue\cmake-build-debug\CMakeFiles\13Queue.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/13Queue.dir/depend

