# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.11

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
CMAKE_COMMAND = D:\ProgramFiles\CMake\bin\cmake.exe

# The command to remove a file.
RM = D:\ProgramFiles\CMake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Dev\primer\17_mouse_events

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Dev\primer\17_mouse_events

# Include any dependencies generated for this target.
include CMakeFiles/SDL2Tutorial.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SDL2Tutorial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SDL2Tutorial.dir/flags.make

CMakeFiles/SDL2Tutorial.dir/17_mouse_events.cpp.obj: CMakeFiles/SDL2Tutorial.dir/flags.make
CMakeFiles/SDL2Tutorial.dir/17_mouse_events.cpp.obj: CMakeFiles/SDL2Tutorial.dir/includes_CXX.rsp
CMakeFiles/SDL2Tutorial.dir/17_mouse_events.cpp.obj: 17_mouse_events.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\primer\17_mouse_events\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SDL2Tutorial.dir/17_mouse_events.cpp.obj"
	D:\ProgramFiles\mingw-w64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SDL2Tutorial.dir\17_mouse_events.cpp.obj -c D:\Dev\primer\17_mouse_events\17_mouse_events.cpp

CMakeFiles/SDL2Tutorial.dir/17_mouse_events.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL2Tutorial.dir/17_mouse_events.cpp.i"
	D:\ProgramFiles\mingw-w64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\primer\17_mouse_events\17_mouse_events.cpp > CMakeFiles\SDL2Tutorial.dir\17_mouse_events.cpp.i

CMakeFiles/SDL2Tutorial.dir/17_mouse_events.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL2Tutorial.dir/17_mouse_events.cpp.s"
	D:\ProgramFiles\mingw-w64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Dev\primer\17_mouse_events\17_mouse_events.cpp -o CMakeFiles\SDL2Tutorial.dir\17_mouse_events.cpp.s

# Object files for target SDL2Tutorial
SDL2Tutorial_OBJECTS = \
"CMakeFiles/SDL2Tutorial.dir/17_mouse_events.cpp.obj"

# External object files for target SDL2Tutorial
SDL2Tutorial_EXTERNAL_OBJECTS =

SDL2Tutorial.exe: CMakeFiles/SDL2Tutorial.dir/17_mouse_events.cpp.obj
SDL2Tutorial.exe: CMakeFiles/SDL2Tutorial.dir/build.make
SDL2Tutorial.exe: D:/usr/x86_64-w64-mingw32/lib/libSDL2main.a
SDL2Tutorial.exe: C:/Windows/System32/SDL2.dll
SDL2Tutorial.exe: C:/Windows/System32/SDL2_image.dll
SDL2Tutorial.exe: C:/Windows/System32/SDL2_ttf.dll
SDL2Tutorial.exe: CMakeFiles/SDL2Tutorial.dir/linklibs.rsp
SDL2Tutorial.exe: CMakeFiles/SDL2Tutorial.dir/objects1.rsp
SDL2Tutorial.exe: CMakeFiles/SDL2Tutorial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Dev\primer\17_mouse_events\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SDL2Tutorial.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SDL2Tutorial.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SDL2Tutorial.dir/build: SDL2Tutorial.exe

.PHONY : CMakeFiles/SDL2Tutorial.dir/build

CMakeFiles/SDL2Tutorial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SDL2Tutorial.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SDL2Tutorial.dir/clean

CMakeFiles/SDL2Tutorial.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Dev\primer\17_mouse_events D:\Dev\primer\17_mouse_events D:\Dev\primer\17_mouse_events D:\Dev\primer\17_mouse_events D:\Dev\primer\17_mouse_events\CMakeFiles\SDL2Tutorial.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SDL2Tutorial.dir/depend

