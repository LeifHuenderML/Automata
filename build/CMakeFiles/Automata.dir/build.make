# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/leifhuender/Documents/Research/Current/Automata/Automata

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/leifhuender/Documents/Research/Current/Automata/Automata/build

# Include any dependencies generated for this target.
include CMakeFiles/Automata.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Automata.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Automata.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Automata.dir/flags.make

CMakeFiles/Automata.dir/main.cpp.o: CMakeFiles/Automata.dir/flags.make
CMakeFiles/Automata.dir/main.cpp.o: /Users/leifhuender/Documents/Research/Current/Automata/Automata/main.cpp
CMakeFiles/Automata.dir/main.cpp.o: CMakeFiles/Automata.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/leifhuender/Documents/Research/Current/Automata/Automata/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Automata.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Automata.dir/main.cpp.o -MF CMakeFiles/Automata.dir/main.cpp.o.d -o CMakeFiles/Automata.dir/main.cpp.o -c /Users/leifhuender/Documents/Research/Current/Automata/Automata/main.cpp

CMakeFiles/Automata.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Automata.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/leifhuender/Documents/Research/Current/Automata/Automata/main.cpp > CMakeFiles/Automata.dir/main.cpp.i

CMakeFiles/Automata.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Automata.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/leifhuender/Documents/Research/Current/Automata/Automata/main.cpp -o CMakeFiles/Automata.dir/main.cpp.s

# Object files for target Automata
Automata_OBJECTS = \
"CMakeFiles/Automata.dir/main.cpp.o"

# External object files for target Automata
Automata_EXTERNAL_OBJECTS =

Automata: CMakeFiles/Automata.dir/main.cpp.o
Automata: CMakeFiles/Automata.dir/build.make
Automata: /opt/homebrew/Cellar/sfml/2.6.1/lib/libsfml-graphics.2.6.1.dylib
Automata: /opt/homebrew/Cellar/sfml/2.6.1/lib/libsfml-window.2.6.1.dylib
Automata: /opt/homebrew/Cellar/sfml/2.6.1/lib/libsfml-audio.2.6.1.dylib
Automata: /opt/homebrew/Cellar/sfml/2.6.1/lib/libsfml-system.2.6.1.dylib
Automata: CMakeFiles/Automata.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/leifhuender/Documents/Research/Current/Automata/Automata/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Automata"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Automata.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Automata.dir/build: Automata
.PHONY : CMakeFiles/Automata.dir/build

CMakeFiles/Automata.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Automata.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Automata.dir/clean

CMakeFiles/Automata.dir/depend:
	cd /Users/leifhuender/Documents/Research/Current/Automata/Automata/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/leifhuender/Documents/Research/Current/Automata/Automata /Users/leifhuender/Documents/Research/Current/Automata/Automata /Users/leifhuender/Documents/Research/Current/Automata/Automata/build /Users/leifhuender/Documents/Research/Current/Automata/Automata/build /Users/leifhuender/Documents/Research/Current/Automata/Automata/build/CMakeFiles/Automata.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Automata.dir/depend

