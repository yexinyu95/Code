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
CMAKE_SOURCE_DIR = D:\Code\DataStructure\18Exercise

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Code\DataStructure\18Exercise\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/18Exercise.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/18Exercise.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/18Exercise.dir/flags.make

CMakeFiles/18Exercise.dir/main.cpp.obj: CMakeFiles/18Exercise.dir/flags.make
CMakeFiles/18Exercise.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Code\DataStructure\18Exercise\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/18Exercise.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\18Exercise.dir\main.cpp.obj -c D:\Code\DataStructure\18Exercise\main.cpp

CMakeFiles/18Exercise.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/18Exercise.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Code\DataStructure\18Exercise\main.cpp > CMakeFiles\18Exercise.dir\main.cpp.i

CMakeFiles/18Exercise.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/18Exercise.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Code\DataStructure\18Exercise\main.cpp -o CMakeFiles\18Exercise.dir\main.cpp.s

# Object files for target 18Exercise
18Exercise_OBJECTS = \
"CMakeFiles/18Exercise.dir/main.cpp.obj"

# External object files for target 18Exercise
18Exercise_EXTERNAL_OBJECTS =

18Exercise.exe: CMakeFiles/18Exercise.dir/main.cpp.obj
18Exercise.exe: CMakeFiles/18Exercise.dir/build.make
18Exercise.exe: CMakeFiles/18Exercise.dir/linklibs.rsp
18Exercise.exe: CMakeFiles/18Exercise.dir/objects1.rsp
18Exercise.exe: CMakeFiles/18Exercise.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Code\DataStructure\18Exercise\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 18Exercise.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\18Exercise.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/18Exercise.dir/build: 18Exercise.exe

.PHONY : CMakeFiles/18Exercise.dir/build

CMakeFiles/18Exercise.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\18Exercise.dir\cmake_clean.cmake
.PHONY : CMakeFiles/18Exercise.dir/clean

CMakeFiles/18Exercise.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Code\DataStructure\18Exercise D:\Code\DataStructure\18Exercise D:\Code\DataStructure\18Exercise\cmake-build-debug D:\Code\DataStructure\18Exercise\cmake-build-debug D:\Code\DataStructure\18Exercise\cmake-build-debug\CMakeFiles\18Exercise.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/18Exercise.dir/depend

