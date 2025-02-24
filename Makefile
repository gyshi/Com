# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/gyshi/wl/Community

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gyshi/wl/Community

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/cmake-gui -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/gyshi/wl/Community/CMakeFiles /home/gyshi/wl/Community/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/gyshi/wl/Community/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Community

# Build rule for target.
Community: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Community
.PHONY : Community

# fast build rule for target.
Community/fast:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/build
.PHONY : Community/fast

# target to build an object file
clique.o:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/clique.o
.PHONY : clique.o

# target to preprocess a source file
clique.i:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/clique.i
.PHONY : clique.i

# target to generate assembly for a file
clique.s:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/clique.s
.PHONY : clique.s

# target to build an object file
condition.o:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/condition.o
.PHONY : condition.o

# target to preprocess a source file
condition.i:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/condition.i
.PHONY : condition.i

# target to generate assembly for a file
condition.s:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/condition.s
.PHONY : condition.s

# target to build an object file
core.o:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/core.o
.PHONY : core.o

# target to preprocess a source file
core.i:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/core.i
.PHONY : core.i

# target to generate assembly for a file
core.s:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/core.s
.PHONY : core.s

# target to build an object file
ego_community.o:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/ego_community.o
.PHONY : ego_community.o

# target to preprocess a source file
ego_community.i:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/ego_community.i
.PHONY : ego_community.i

# target to generate assembly for a file
ego_community.s:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/ego_community.s
.PHONY : ego_community.s

# target to build an object file
file_manage.o:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/file_manage.o
.PHONY : file_manage.o

# target to preprocess a source file
file_manage.i:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/file_manage.i
.PHONY : file_manage.i

# target to generate assembly for a file
file_manage.s:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/file_manage.s
.PHONY : file_manage.s

# target to build an object file
graph.o:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/graph.o
.PHONY : graph.o

# target to preprocess a source file
graph.i:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/graph.i
.PHONY : graph.i

# target to generate assembly for a file
graph.s:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/graph.s
.PHONY : graph.s

# target to build an object file
graph_algorithm.o:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/graph_algorithm.o
.PHONY : graph_algorithm.o

# target to preprocess a source file
graph_algorithm.i:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/graph_algorithm.i
.PHONY : graph_algorithm.i

# target to generate assembly for a file
graph_algorithm.s:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/graph_algorithm.s
.PHONY : graph_algorithm.s

# target to build an object file
include.o:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/include.o
.PHONY : include.o

# target to preprocess a source file
include.i:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/include.i
.PHONY : include.i

# target to generate assembly for a file
include.s:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/include.s
.PHONY : include.s

# target to build an object file
ks_core.o:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/ks_core.o
.PHONY : ks_core.o

# target to preprocess a source file
ks_core.i:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/ks_core.i
.PHONY : ks_core.i

# target to generate assembly for a file
ks_core.s:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/ks_core.s
.PHONY : ks_core.s

# target to build an object file
main.o:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/main.o
.PHONY : main.o

# target to preprocess a source file
main.i:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/main.i
.PHONY : main.i

# target to generate assembly for a file
main.s:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/main.s
.PHONY : main.s

# target to build an object file
tree.o:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/tree.o
.PHONY : tree.o

# target to preprocess a source file
tree.i:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/tree.i
.PHONY : tree.i

# target to generate assembly for a file
tree.s:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/tree.s
.PHONY : tree.s

# target to build an object file
truss.o:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/truss.o
.PHONY : truss.o

# target to preprocess a source file
truss.i:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/truss.i
.PHONY : truss.i

# target to generate assembly for a file
truss.s:
	$(MAKE) -f CMakeFiles/Community.dir/build.make CMakeFiles/Community.dir/truss.s
.PHONY : truss.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... Community"
	@echo "... clique.o"
	@echo "... clique.i"
	@echo "... clique.s"
	@echo "... condition.o"
	@echo "... condition.i"
	@echo "... condition.s"
	@echo "... core.o"
	@echo "... core.i"
	@echo "... core.s"
	@echo "... ego_community.o"
	@echo "... ego_community.i"
	@echo "... ego_community.s"
	@echo "... file_manage.o"
	@echo "... file_manage.i"
	@echo "... file_manage.s"
	@echo "... graph.o"
	@echo "... graph.i"
	@echo "... graph.s"
	@echo "... graph_algorithm.o"
	@echo "... graph_algorithm.i"
	@echo "... graph_algorithm.s"
	@echo "... include.o"
	@echo "... include.i"
	@echo "... include.s"
	@echo "... ks_core.o"
	@echo "... ks_core.i"
	@echo "... ks_core.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... tree.o"
	@echo "... tree.i"
	@echo "... tree.s"
	@echo "... truss.o"
	@echo "... truss.i"
	@echo "... truss.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

