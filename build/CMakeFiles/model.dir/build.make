# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\hakla\OneDrive - Queen's University\23 - Fall Term\ELEC 278\assignment"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\hakla\OneDrive - Queen's University\23 - Fall Term\ELEC 278\assignment\build"

# Include any dependencies generated for this target.
include CMakeFiles/model.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/model.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/model.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/model.dir/flags.make

CMakeFiles/model.dir/model.c.obj: CMakeFiles/model.dir/flags.make
CMakeFiles/model.dir/model.c.obj: C:/Users/hakla/OneDrive\ -\ Queen's\ University/23\ -\ Fall\ Term/ELEC\ 278/assignment/model.c
CMakeFiles/model.dir/model.c.obj: CMakeFiles/model.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\hakla\OneDrive - Queen's University\23 - Fall Term\ELEC 278\assignment\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/model.dir/model.c.obj"
	C:\Users\hakla\ONEDRI~1\23-FAL~1\ELEC27~2\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/model.dir/model.c.obj -MF CMakeFiles\model.dir\model.c.obj.d -o CMakeFiles\model.dir\model.c.obj -c "C:\Users\hakla\OneDrive - Queen's University\23 - Fall Term\ELEC 278\assignment\model.c"

CMakeFiles/model.dir/model.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/model.dir/model.c.i"
	C:\Users\hakla\ONEDRI~1\23-FAL~1\ELEC27~2\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\hakla\OneDrive - Queen's University\23 - Fall Term\ELEC 278\assignment\model.c" > CMakeFiles\model.dir\model.c.i

CMakeFiles/model.dir/model.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/model.dir/model.c.s"
	C:\Users\hakla\ONEDRI~1\23-FAL~1\ELEC27~2\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\hakla\OneDrive - Queen's University\23 - Fall Term\ELEC 278\assignment\model.c" -o CMakeFiles\model.dir\model.c.s

model: CMakeFiles/model.dir/model.c.obj
model: CMakeFiles/model.dir/build.make
.PHONY : model

# Rule to build all files generated by this target.
CMakeFiles/model.dir/build: model
.PHONY : CMakeFiles/model.dir/build

CMakeFiles/model.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\model.dir\cmake_clean.cmake
.PHONY : CMakeFiles/model.dir/clean

CMakeFiles/model.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\hakla\OneDrive - Queen's University\23 - Fall Term\ELEC 278\assignment" "C:\Users\hakla\OneDrive - Queen's University\23 - Fall Term\ELEC 278\assignment" "C:\Users\hakla\OneDrive - Queen's University\23 - Fall Term\ELEC 278\assignment\build" "C:\Users\hakla\OneDrive - Queen's University\23 - Fall Term\ELEC 278\assignment\build" "C:\Users\hakla\OneDrive - Queen's University\23 - Fall Term\ELEC 278\assignment\build\CMakeFiles\model.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/model.dir/depend

