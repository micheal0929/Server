# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = "/mnt/hgfs/All files/epoll"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/hgfs/All files/epoll/build"

# Include any dependencies generated for this target.
include bin/CMakeFiles/epollserver.dir/depend.make

# Include the progress variables for this target.
include bin/CMakeFiles/epollserver.dir/progress.make

# Include the compile flags for this target's objects.
include bin/CMakeFiles/epollserver.dir/flags.make

bin/CMakeFiles/epollserver.dir/epoll.o: bin/CMakeFiles/epollserver.dir/flags.make
bin/CMakeFiles/epollserver.dir/epoll.o: ../src/epoll.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/mnt/hgfs/All files/epoll/build/CMakeFiles" $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object bin/CMakeFiles/epollserver.dir/epoll.o"
	cd "/mnt/hgfs/All files/epoll/build/bin" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/epollserver.dir/epoll.o -c "/mnt/hgfs/All files/epoll/src/epoll.cpp"

bin/CMakeFiles/epollserver.dir/epoll.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/epollserver.dir/epoll.i"
	cd "/mnt/hgfs/All files/epoll/build/bin" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/mnt/hgfs/All files/epoll/src/epoll.cpp" > CMakeFiles/epollserver.dir/epoll.i

bin/CMakeFiles/epollserver.dir/epoll.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/epollserver.dir/epoll.s"
	cd "/mnt/hgfs/All files/epoll/build/bin" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/mnt/hgfs/All files/epoll/src/epoll.cpp" -o CMakeFiles/epollserver.dir/epoll.s

bin/CMakeFiles/epollserver.dir/epoll.o.requires:
.PHONY : bin/CMakeFiles/epollserver.dir/epoll.o.requires

bin/CMakeFiles/epollserver.dir/epoll.o.provides: bin/CMakeFiles/epollserver.dir/epoll.o.requires
	$(MAKE) -f bin/CMakeFiles/epollserver.dir/build.make bin/CMakeFiles/epollserver.dir/epoll.o.provides.build
.PHONY : bin/CMakeFiles/epollserver.dir/epoll.o.provides

bin/CMakeFiles/epollserver.dir/epoll.o.provides.build: bin/CMakeFiles/epollserver.dir/epoll.o

# Object files for target epollserver
epollserver_OBJECTS = \
"CMakeFiles/epollserver.dir/epoll.o"

# External object files for target epollserver
epollserver_EXTERNAL_OBJECTS =

bin/epollserver: bin/CMakeFiles/epollserver.dir/epoll.o
bin/epollserver: bin/CMakeFiles/epollserver.dir/build.make
bin/epollserver: bin/CMakeFiles/epollserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable epollserver"
	cd "/mnt/hgfs/All files/epoll/build/bin" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/epollserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/CMakeFiles/epollserver.dir/build: bin/epollserver
.PHONY : bin/CMakeFiles/epollserver.dir/build

bin/CMakeFiles/epollserver.dir/requires: bin/CMakeFiles/epollserver.dir/epoll.o.requires
.PHONY : bin/CMakeFiles/epollserver.dir/requires

bin/CMakeFiles/epollserver.dir/clean:
	cd "/mnt/hgfs/All files/epoll/build/bin" && $(CMAKE_COMMAND) -P CMakeFiles/epollserver.dir/cmake_clean.cmake
.PHONY : bin/CMakeFiles/epollserver.dir/clean

bin/CMakeFiles/epollserver.dir/depend:
	cd "/mnt/hgfs/All files/epoll/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/hgfs/All files/epoll" "/mnt/hgfs/All files/epoll/src" "/mnt/hgfs/All files/epoll/build" "/mnt/hgfs/All files/epoll/build/bin" "/mnt/hgfs/All files/epoll/build/bin/CMakeFiles/epollserver.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : bin/CMakeFiles/epollserver.dir/depend

