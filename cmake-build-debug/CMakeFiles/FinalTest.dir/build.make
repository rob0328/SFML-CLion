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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.3.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.3.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\rober\CLionProjects\FinalTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\rober\CLionProjects\FinalTest\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/FinalTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FinalTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FinalTest.dir/flags.make

CMakeFiles/FinalTest.dir/main.cpp.obj: CMakeFiles/FinalTest.dir/flags.make
CMakeFiles/FinalTest.dir/main.cpp.obj: CMakeFiles/FinalTest.dir/includes_CXX.rsp
CMakeFiles/FinalTest.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\rober\CLionProjects\FinalTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FinalTest.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\FinalTest.dir\main.cpp.obj -c C:\Users\rober\CLionProjects\FinalTest\main.cpp

CMakeFiles/FinalTest.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FinalTest.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\rober\CLionProjects\FinalTest\main.cpp > CMakeFiles\FinalTest.dir\main.cpp.i

CMakeFiles/FinalTest.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FinalTest.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\rober\CLionProjects\FinalTest\main.cpp -o CMakeFiles\FinalTest.dir\main.cpp.s

CMakeFiles/FinalTest.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/FinalTest.dir/main.cpp.obj.requires

CMakeFiles/FinalTest.dir/main.cpp.obj.provides: CMakeFiles/FinalTest.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\FinalTest.dir\build.make CMakeFiles/FinalTest.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/FinalTest.dir/main.cpp.obj.provides

CMakeFiles/FinalTest.dir/main.cpp.obj.provides.build: CMakeFiles/FinalTest.dir/main.cpp.obj


# Object files for target FinalTest
FinalTest_OBJECTS = \
"CMakeFiles/FinalTest.dir/main.cpp.obj"

# External object files for target FinalTest
FinalTest_EXTERNAL_OBJECTS =

FinalTest.exe: CMakeFiles/FinalTest.dir/main.cpp.obj
FinalTest.exe: CMakeFiles/FinalTest.dir/build.make
FinalTest.exe: C:/Users/rober/Program_Libraries/SFML(1)/lib/libsfml-system-d.a
FinalTest.exe: C:/Users/rober/Program_Libraries/SFML(1)/lib/libsfml-graphics-d.a
FinalTest.exe: C:/Users/rober/Program_Libraries/SFML(1)/lib/libsfml-window-d.a
FinalTest.exe: C:/Users/rober/Program_Libraries/SFML(1)/lib/libsfml-network-d.a
FinalTest.exe: C:/Users/rober/Program_Libraries/SFML(1)/lib/libsfml-audio-d.a
FinalTest.exe: CMakeFiles/FinalTest.dir/linklibs.rsp
FinalTest.exe: CMakeFiles/FinalTest.dir/objects1.rsp
FinalTest.exe: CMakeFiles/FinalTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\rober\CLionProjects\FinalTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable FinalTest.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\FinalTest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FinalTest.dir/build: FinalTest.exe

.PHONY : CMakeFiles/FinalTest.dir/build

CMakeFiles/FinalTest.dir/requires: CMakeFiles/FinalTest.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/FinalTest.dir/requires

CMakeFiles/FinalTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\FinalTest.dir\cmake_clean.cmake
.PHONY : CMakeFiles/FinalTest.dir/clean

CMakeFiles/FinalTest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\rober\CLionProjects\FinalTest C:\Users\rober\CLionProjects\FinalTest C:\Users\rober\CLionProjects\FinalTest\cmake-build-debug C:\Users\rober\CLionProjects\FinalTest\cmake-build-debug C:\Users\rober\CLionProjects\FinalTest\cmake-build-debug\CMakeFiles\FinalTest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FinalTest.dir/depend

