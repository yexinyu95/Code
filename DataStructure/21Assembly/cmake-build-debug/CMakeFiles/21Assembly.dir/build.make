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
CMAKE_SOURCE_DIR = D:\Code\DataStructure\21Assembly

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Code\DataStructure\21Assembly\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/21Assembly.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/21Assembly.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/21Assembly.dir/flags.make

CMakeFiles/21Assembly.dir/main.c.obj: CMakeFiles/21Assembly.dir/flags.make
CMakeFiles/21Assembly.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Code\DataStructure\21Assembly\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/21Assembly.dir/main.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\21Assembly.dir\main.c.obj -c D:\Code\DataStructure\21Assembly\main.c

CMakeFiles/21Assembly.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/21Assembly.dir/main.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Code\DataStructure\21Assembly\main.c > CMakeFiles\21Assembly.dir\main.c.i

CMakeFiles/21Assembly.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/21Assembly.dir/main.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Code\DataStructure\21Assembly\main.c -o CMakeFiles\21Assembly.dir\main.c.s

# Object files for target 21Assembly
21Assembly_OBJECTS = \
"CMakeFiles/21Assembly.dir/main.c.obj"

# External object files for target 21Assembly
21Assembly_EXTERNAL_OBJECTS =

21Assembly.exe: CMakeFiles/21Assembly.dir/main.c.obj
21Assembly.exe: CMakeFiles/21Assembly.dir/build.make
21Assembly.exe: CMakeFiles/21Assembly.dir/linklibs.rsp
21Assembly.exe: CMakeFiles/21Assembly.dir/objects1.rsp
21Assembly.exe: CMakeFiles/21Assembly.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Code\DataStructure\21Assembly\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 21Assembly.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\21Assembly.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/21Assembly.dir/build: 21Assembly.exe

.PHONY : CMakeFiles/21Assembly.dir/build

CMakeFiles/21Assembly.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\21Assembly.dir\cmake_clean.cmake
.PHONY : CMakeFiles/21Assembly.dir/clean

CMakeFiles/21Assembly.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Code\DataStructure\21Assembly D:\Code\DataStructure\21Assembly D:\Code\DataStructure\21Assembly\cmake-build-debug D:\Code\DataStructure\21Assembly\cmake-build-debug D:\Code\DataStructure\21Assembly\cmake-build-debug\CMakeFiles\21Assembly.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/21Assembly.dir/depend

