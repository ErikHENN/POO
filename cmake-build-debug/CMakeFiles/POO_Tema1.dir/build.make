# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2017.3.4\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2017.3.4\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Erik\CLionProjects\POO-Tema1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Erik\CLionProjects\POO-Tema1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/POO_Tema1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/POO_Tema1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/POO_Tema1.dir/flags.make

CMakeFiles/POO_Tema1.dir/main.cpp.obj: CMakeFiles/POO_Tema1.dir/flags.make
CMakeFiles/POO_Tema1.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Erik\CLionProjects\POO-Tema1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/POO_Tema1.dir/main.cpp.obj"
	D:\CodeBlocks\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\POO_Tema1.dir\main.cpp.obj -c C:\Users\Erik\CLionProjects\POO-Tema1\main.cpp

CMakeFiles/POO_Tema1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/POO_Tema1.dir/main.cpp.i"
	D:\CodeBlocks\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Erik\CLionProjects\POO-Tema1\main.cpp > CMakeFiles\POO_Tema1.dir\main.cpp.i

CMakeFiles/POO_Tema1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/POO_Tema1.dir/main.cpp.s"
	D:\CodeBlocks\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Erik\CLionProjects\POO-Tema1\main.cpp -o CMakeFiles\POO_Tema1.dir\main.cpp.s

CMakeFiles/POO_Tema1.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/POO_Tema1.dir/main.cpp.obj.requires

CMakeFiles/POO_Tema1.dir/main.cpp.obj.provides: CMakeFiles/POO_Tema1.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\POO_Tema1.dir\build.make CMakeFiles/POO_Tema1.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/POO_Tema1.dir/main.cpp.obj.provides

CMakeFiles/POO_Tema1.dir/main.cpp.obj.provides.build: CMakeFiles/POO_Tema1.dir/main.cpp.obj


CMakeFiles/POO_Tema1.dir/BigInt.cpp.obj: CMakeFiles/POO_Tema1.dir/flags.make
CMakeFiles/POO_Tema1.dir/BigInt.cpp.obj: ../BigInt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Erik\CLionProjects\POO-Tema1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/POO_Tema1.dir/BigInt.cpp.obj"
	D:\CodeBlocks\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\POO_Tema1.dir\BigInt.cpp.obj -c C:\Users\Erik\CLionProjects\POO-Tema1\BigInt.cpp

CMakeFiles/POO_Tema1.dir/BigInt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/POO_Tema1.dir/BigInt.cpp.i"
	D:\CodeBlocks\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Erik\CLionProjects\POO-Tema1\BigInt.cpp > CMakeFiles\POO_Tema1.dir\BigInt.cpp.i

CMakeFiles/POO_Tema1.dir/BigInt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/POO_Tema1.dir/BigInt.cpp.s"
	D:\CodeBlocks\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Erik\CLionProjects\POO-Tema1\BigInt.cpp -o CMakeFiles\POO_Tema1.dir\BigInt.cpp.s

CMakeFiles/POO_Tema1.dir/BigInt.cpp.obj.requires:

.PHONY : CMakeFiles/POO_Tema1.dir/BigInt.cpp.obj.requires

CMakeFiles/POO_Tema1.dir/BigInt.cpp.obj.provides: CMakeFiles/POO_Tema1.dir/BigInt.cpp.obj.requires
	$(MAKE) -f CMakeFiles\POO_Tema1.dir\build.make CMakeFiles/POO_Tema1.dir/BigInt.cpp.obj.provides.build
.PHONY : CMakeFiles/POO_Tema1.dir/BigInt.cpp.obj.provides

CMakeFiles/POO_Tema1.dir/BigInt.cpp.obj.provides.build: CMakeFiles/POO_Tema1.dir/BigInt.cpp.obj


# Object files for target POO_Tema1
POO_Tema1_OBJECTS = \
"CMakeFiles/POO_Tema1.dir/main.cpp.obj" \
"CMakeFiles/POO_Tema1.dir/BigInt.cpp.obj"

# External object files for target POO_Tema1
POO_Tema1_EXTERNAL_OBJECTS =

POO_Tema1.exe: CMakeFiles/POO_Tema1.dir/main.cpp.obj
POO_Tema1.exe: CMakeFiles/POO_Tema1.dir/BigInt.cpp.obj
POO_Tema1.exe: CMakeFiles/POO_Tema1.dir/build.make
POO_Tema1.exe: CMakeFiles/POO_Tema1.dir/linklibs.rsp
POO_Tema1.exe: CMakeFiles/POO_Tema1.dir/objects1.rsp
POO_Tema1.exe: CMakeFiles/POO_Tema1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Erik\CLionProjects\POO-Tema1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable POO_Tema1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\POO_Tema1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/POO_Tema1.dir/build: POO_Tema1.exe

.PHONY : CMakeFiles/POO_Tema1.dir/build

CMakeFiles/POO_Tema1.dir/requires: CMakeFiles/POO_Tema1.dir/main.cpp.obj.requires
CMakeFiles/POO_Tema1.dir/requires: CMakeFiles/POO_Tema1.dir/BigInt.cpp.obj.requires

.PHONY : CMakeFiles/POO_Tema1.dir/requires

CMakeFiles/POO_Tema1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\POO_Tema1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/POO_Tema1.dir/clean

CMakeFiles/POO_Tema1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Erik\CLionProjects\POO-Tema1 C:\Users\Erik\CLionProjects\POO-Tema1 C:\Users\Erik\CLionProjects\POO-Tema1\cmake-build-debug C:\Users\Erik\CLionProjects\POO-Tema1\cmake-build-debug C:\Users\Erik\CLionProjects\POO-Tema1\cmake-build-debug\CMakeFiles\POO_Tema1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/POO_Tema1.dir/depend

