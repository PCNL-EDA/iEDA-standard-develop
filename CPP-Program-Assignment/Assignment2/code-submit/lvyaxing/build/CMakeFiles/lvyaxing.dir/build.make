# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/litar/template/iEDA-standard-develop/CPP-Program-Assignment/Assignment2/code-submit/lvyaxing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/litar/template/iEDA-standard-develop/CPP-Program-Assignment/Assignment2/code-submit/lvyaxing/build

# Include any dependencies generated for this target.
include CMakeFiles/lvyaxing.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lvyaxing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lvyaxing.dir/flags.make

CMakeFiles/lvyaxing.dir/src/AStar.cpp.o: CMakeFiles/lvyaxing.dir/flags.make
CMakeFiles/lvyaxing.dir/src/AStar.cpp.o: ../src/AStar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/litar/template/iEDA-standard-develop/CPP-Program-Assignment/Assignment2/code-submit/lvyaxing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lvyaxing.dir/src/AStar.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lvyaxing.dir/src/AStar.cpp.o -c /home/litar/template/iEDA-standard-develop/CPP-Program-Assignment/Assignment2/code-submit/lvyaxing/src/AStar.cpp

CMakeFiles/lvyaxing.dir/src/AStar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lvyaxing.dir/src/AStar.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/litar/template/iEDA-standard-develop/CPP-Program-Assignment/Assignment2/code-submit/lvyaxing/src/AStar.cpp > CMakeFiles/lvyaxing.dir/src/AStar.cpp.i

CMakeFiles/lvyaxing.dir/src/AStar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lvyaxing.dir/src/AStar.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/litar/template/iEDA-standard-develop/CPP-Program-Assignment/Assignment2/code-submit/lvyaxing/src/AStar.cpp -o CMakeFiles/lvyaxing.dir/src/AStar.cpp.s

CMakeFiles/lvyaxing.dir/src/Map.cpp.o: CMakeFiles/lvyaxing.dir/flags.make
CMakeFiles/lvyaxing.dir/src/Map.cpp.o: ../src/Map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/litar/template/iEDA-standard-develop/CPP-Program-Assignment/Assignment2/code-submit/lvyaxing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lvyaxing.dir/src/Map.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lvyaxing.dir/src/Map.cpp.o -c /home/litar/template/iEDA-standard-develop/CPP-Program-Assignment/Assignment2/code-submit/lvyaxing/src/Map.cpp

CMakeFiles/lvyaxing.dir/src/Map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lvyaxing.dir/src/Map.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/litar/template/iEDA-standard-develop/CPP-Program-Assignment/Assignment2/code-submit/lvyaxing/src/Map.cpp > CMakeFiles/lvyaxing.dir/src/Map.cpp.i

CMakeFiles/lvyaxing.dir/src/Map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lvyaxing.dir/src/Map.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/litar/template/iEDA-standard-develop/CPP-Program-Assignment/Assignment2/code-submit/lvyaxing/src/Map.cpp -o CMakeFiles/lvyaxing.dir/src/Map.cpp.s

# Object files for target lvyaxing
lvyaxing_OBJECTS = \
"CMakeFiles/lvyaxing.dir/src/AStar.cpp.o" \
"CMakeFiles/lvyaxing.dir/src/Map.cpp.o"

# External object files for target lvyaxing
lvyaxing_EXTERNAL_OBJECTS =

liblvyaxing.a: CMakeFiles/lvyaxing.dir/src/AStar.cpp.o
liblvyaxing.a: CMakeFiles/lvyaxing.dir/src/Map.cpp.o
liblvyaxing.a: CMakeFiles/lvyaxing.dir/build.make
liblvyaxing.a: CMakeFiles/lvyaxing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/litar/template/iEDA-standard-develop/CPP-Program-Assignment/Assignment2/code-submit/lvyaxing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library liblvyaxing.a"
	$(CMAKE_COMMAND) -P CMakeFiles/lvyaxing.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lvyaxing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lvyaxing.dir/build: liblvyaxing.a

.PHONY : CMakeFiles/lvyaxing.dir/build

CMakeFiles/lvyaxing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lvyaxing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lvyaxing.dir/clean

CMakeFiles/lvyaxing.dir/depend:
	cd /home/litar/template/iEDA-standard-develop/CPP-Program-Assignment/Assignment2/code-submit/lvyaxing/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/litar/template/iEDA-standard-develop/CPP-Program-Assignment/Assignment2/code-submit/lvyaxing /home/litar/template/iEDA-standard-develop/CPP-Program-Assignment/Assignment2/code-submit/lvyaxing /home/litar/template/iEDA-standard-develop/CPP-Program-Assignment/Assignment2/code-submit/lvyaxing/build /home/litar/template/iEDA-standard-develop/CPP-Program-Assignment/Assignment2/code-submit/lvyaxing/build /home/litar/template/iEDA-standard-develop/CPP-Program-Assignment/Assignment2/code-submit/lvyaxing/build/CMakeFiles/lvyaxing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lvyaxing.dir/depend

