# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xpolas/banska/UASS/projekt/project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xpolas/banska/UASS/projekt/project/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/project.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/project.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project.dir/flags.make

CMakeFiles/project.dir/main.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/main.cpp.o: /home/xpolas/banska/UASS/projekt/project/main.cpp
CMakeFiles/project.dir/main.cpp.o: CMakeFiles/project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/xpolas/banska/UASS/projekt/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project.dir/main.cpp.o -MF CMakeFiles/project.dir/main.cpp.o.d -o CMakeFiles/project.dir/main.cpp.o -c /home/xpolas/banska/UASS/projekt/project/main.cpp

CMakeFiles/project.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/project.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xpolas/banska/UASS/projekt/project/main.cpp > CMakeFiles/project.dir/main.cpp.i

CMakeFiles/project.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/project.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xpolas/banska/UASS/projekt/project/main.cpp -o CMakeFiles/project.dir/main.cpp.s

CMakeFiles/project.dir/Graph.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/Graph.cpp.o: /home/xpolas/banska/UASS/projekt/project/Graph.cpp
CMakeFiles/project.dir/Graph.cpp.o: CMakeFiles/project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/xpolas/banska/UASS/projekt/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/project.dir/Graph.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project.dir/Graph.cpp.o -MF CMakeFiles/project.dir/Graph.cpp.o.d -o CMakeFiles/project.dir/Graph.cpp.o -c /home/xpolas/banska/UASS/projekt/project/Graph.cpp

CMakeFiles/project.dir/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/project.dir/Graph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xpolas/banska/UASS/projekt/project/Graph.cpp > CMakeFiles/project.dir/Graph.cpp.i

CMakeFiles/project.dir/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/project.dir/Graph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xpolas/banska/UASS/projekt/project/Graph.cpp -o CMakeFiles/project.dir/Graph.cpp.s

CMakeFiles/project.dir/TemporalGraph.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/TemporalGraph.cpp.o: /home/xpolas/banska/UASS/projekt/project/TemporalGraph.cpp
CMakeFiles/project.dir/TemporalGraph.cpp.o: CMakeFiles/project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/xpolas/banska/UASS/projekt/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/project.dir/TemporalGraph.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project.dir/TemporalGraph.cpp.o -MF CMakeFiles/project.dir/TemporalGraph.cpp.o.d -o CMakeFiles/project.dir/TemporalGraph.cpp.o -c /home/xpolas/banska/UASS/projekt/project/TemporalGraph.cpp

CMakeFiles/project.dir/TemporalGraph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/project.dir/TemporalGraph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xpolas/banska/UASS/projekt/project/TemporalGraph.cpp > CMakeFiles/project.dir/TemporalGraph.cpp.i

CMakeFiles/project.dir/TemporalGraph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/project.dir/TemporalGraph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xpolas/banska/UASS/projekt/project/TemporalGraph.cpp -o CMakeFiles/project.dir/TemporalGraph.cpp.s

CMakeFiles/project.dir/GraphLoader.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/GraphLoader.cpp.o: /home/xpolas/banska/UASS/projekt/project/GraphLoader.cpp
CMakeFiles/project.dir/GraphLoader.cpp.o: CMakeFiles/project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/xpolas/banska/UASS/projekt/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/project.dir/GraphLoader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project.dir/GraphLoader.cpp.o -MF CMakeFiles/project.dir/GraphLoader.cpp.o.d -o CMakeFiles/project.dir/GraphLoader.cpp.o -c /home/xpolas/banska/UASS/projekt/project/GraphLoader.cpp

CMakeFiles/project.dir/GraphLoader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/project.dir/GraphLoader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xpolas/banska/UASS/projekt/project/GraphLoader.cpp > CMakeFiles/project.dir/GraphLoader.cpp.i

CMakeFiles/project.dir/GraphLoader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/project.dir/GraphLoader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xpolas/banska/UASS/projekt/project/GraphLoader.cpp -o CMakeFiles/project.dir/GraphLoader.cpp.s

# Object files for target project
project_OBJECTS = \
"CMakeFiles/project.dir/main.cpp.o" \
"CMakeFiles/project.dir/Graph.cpp.o" \
"CMakeFiles/project.dir/TemporalGraph.cpp.o" \
"CMakeFiles/project.dir/GraphLoader.cpp.o"

# External object files for target project
project_EXTERNAL_OBJECTS =

project: CMakeFiles/project.dir/main.cpp.o
project: CMakeFiles/project.dir/Graph.cpp.o
project: CMakeFiles/project.dir/TemporalGraph.cpp.o
project: CMakeFiles/project.dir/GraphLoader.cpp.o
project: CMakeFiles/project.dir/build.make
project: CMakeFiles/project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/xpolas/banska/UASS/projekt/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project.dir/build: project
.PHONY : CMakeFiles/project.dir/build

CMakeFiles/project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project.dir/clean

CMakeFiles/project.dir/depend:
	cd /home/xpolas/banska/UASS/projekt/project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xpolas/banska/UASS/projekt/project /home/xpolas/banska/UASS/projekt/project /home/xpolas/banska/UASS/projekt/project/cmake-build-debug /home/xpolas/banska/UASS/projekt/project/cmake-build-debug /home/xpolas/banska/UASS/projekt/project/cmake-build-debug/CMakeFiles/project.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/project.dir/depend

