# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/giardinif/C++/Vulkan_Learning

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/giardinif/C++/Vulkan_Learning/build

# Include any dependencies generated for this target.
include CMakeFiles/VKLearn.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/VKLearn.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/VKLearn.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/VKLearn.dir/flags.make

CMakeFiles/VKLearn.dir/first_app.cpp.o: CMakeFiles/VKLearn.dir/flags.make
CMakeFiles/VKLearn.dir/first_app.cpp.o: ../first_app.cpp
CMakeFiles/VKLearn.dir/first_app.cpp.o: CMakeFiles/VKLearn.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/giardinif/C++/Vulkan_Learning/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/VKLearn.dir/first_app.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/VKLearn.dir/first_app.cpp.o -MF CMakeFiles/VKLearn.dir/first_app.cpp.o.d -o CMakeFiles/VKLearn.dir/first_app.cpp.o -c /home/giardinif/C++/Vulkan_Learning/first_app.cpp

CMakeFiles/VKLearn.dir/first_app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VKLearn.dir/first_app.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/giardinif/C++/Vulkan_Learning/first_app.cpp > CMakeFiles/VKLearn.dir/first_app.cpp.i

CMakeFiles/VKLearn.dir/first_app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VKLearn.dir/first_app.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/giardinif/C++/Vulkan_Learning/first_app.cpp -o CMakeFiles/VKLearn.dir/first_app.cpp.s

CMakeFiles/VKLearn.dir/main.cpp.o: CMakeFiles/VKLearn.dir/flags.make
CMakeFiles/VKLearn.dir/main.cpp.o: ../main.cpp
CMakeFiles/VKLearn.dir/main.cpp.o: CMakeFiles/VKLearn.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/giardinif/C++/Vulkan_Learning/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/VKLearn.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/VKLearn.dir/main.cpp.o -MF CMakeFiles/VKLearn.dir/main.cpp.o.d -o CMakeFiles/VKLearn.dir/main.cpp.o -c /home/giardinif/C++/Vulkan_Learning/main.cpp

CMakeFiles/VKLearn.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VKLearn.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/giardinif/C++/Vulkan_Learning/main.cpp > CMakeFiles/VKLearn.dir/main.cpp.i

CMakeFiles/VKLearn.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VKLearn.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/giardinif/C++/Vulkan_Learning/main.cpp -o CMakeFiles/VKLearn.dir/main.cpp.s

CMakeFiles/VKLearn.dir/vkl_device.cpp.o: CMakeFiles/VKLearn.dir/flags.make
CMakeFiles/VKLearn.dir/vkl_device.cpp.o: ../vkl_device.cpp
CMakeFiles/VKLearn.dir/vkl_device.cpp.o: CMakeFiles/VKLearn.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/giardinif/C++/Vulkan_Learning/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/VKLearn.dir/vkl_device.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/VKLearn.dir/vkl_device.cpp.o -MF CMakeFiles/VKLearn.dir/vkl_device.cpp.o.d -o CMakeFiles/VKLearn.dir/vkl_device.cpp.o -c /home/giardinif/C++/Vulkan_Learning/vkl_device.cpp

CMakeFiles/VKLearn.dir/vkl_device.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VKLearn.dir/vkl_device.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/giardinif/C++/Vulkan_Learning/vkl_device.cpp > CMakeFiles/VKLearn.dir/vkl_device.cpp.i

CMakeFiles/VKLearn.dir/vkl_device.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VKLearn.dir/vkl_device.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/giardinif/C++/Vulkan_Learning/vkl_device.cpp -o CMakeFiles/VKLearn.dir/vkl_device.cpp.s

CMakeFiles/VKLearn.dir/vkl_pipeline.cpp.o: CMakeFiles/VKLearn.dir/flags.make
CMakeFiles/VKLearn.dir/vkl_pipeline.cpp.o: ../vkl_pipeline.cpp
CMakeFiles/VKLearn.dir/vkl_pipeline.cpp.o: CMakeFiles/VKLearn.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/giardinif/C++/Vulkan_Learning/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/VKLearn.dir/vkl_pipeline.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/VKLearn.dir/vkl_pipeline.cpp.o -MF CMakeFiles/VKLearn.dir/vkl_pipeline.cpp.o.d -o CMakeFiles/VKLearn.dir/vkl_pipeline.cpp.o -c /home/giardinif/C++/Vulkan_Learning/vkl_pipeline.cpp

CMakeFiles/VKLearn.dir/vkl_pipeline.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VKLearn.dir/vkl_pipeline.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/giardinif/C++/Vulkan_Learning/vkl_pipeline.cpp > CMakeFiles/VKLearn.dir/vkl_pipeline.cpp.i

CMakeFiles/VKLearn.dir/vkl_pipeline.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VKLearn.dir/vkl_pipeline.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/giardinif/C++/Vulkan_Learning/vkl_pipeline.cpp -o CMakeFiles/VKLearn.dir/vkl_pipeline.cpp.s

CMakeFiles/VKLearn.dir/vkl_window.cpp.o: CMakeFiles/VKLearn.dir/flags.make
CMakeFiles/VKLearn.dir/vkl_window.cpp.o: ../vkl_window.cpp
CMakeFiles/VKLearn.dir/vkl_window.cpp.o: CMakeFiles/VKLearn.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/giardinif/C++/Vulkan_Learning/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/VKLearn.dir/vkl_window.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/VKLearn.dir/vkl_window.cpp.o -MF CMakeFiles/VKLearn.dir/vkl_window.cpp.o.d -o CMakeFiles/VKLearn.dir/vkl_window.cpp.o -c /home/giardinif/C++/Vulkan_Learning/vkl_window.cpp

CMakeFiles/VKLearn.dir/vkl_window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VKLearn.dir/vkl_window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/giardinif/C++/Vulkan_Learning/vkl_window.cpp > CMakeFiles/VKLearn.dir/vkl_window.cpp.i

CMakeFiles/VKLearn.dir/vkl_window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VKLearn.dir/vkl_window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/giardinif/C++/Vulkan_Learning/vkl_window.cpp -o CMakeFiles/VKLearn.dir/vkl_window.cpp.s

# Object files for target VKLearn
VKLearn_OBJECTS = \
"CMakeFiles/VKLearn.dir/first_app.cpp.o" \
"CMakeFiles/VKLearn.dir/main.cpp.o" \
"CMakeFiles/VKLearn.dir/vkl_device.cpp.o" \
"CMakeFiles/VKLearn.dir/vkl_pipeline.cpp.o" \
"CMakeFiles/VKLearn.dir/vkl_window.cpp.o"

# External object files for target VKLearn
VKLearn_EXTERNAL_OBJECTS =

VKLearn: CMakeFiles/VKLearn.dir/first_app.cpp.o
VKLearn: CMakeFiles/VKLearn.dir/main.cpp.o
VKLearn: CMakeFiles/VKLearn.dir/vkl_device.cpp.o
VKLearn: CMakeFiles/VKLearn.dir/vkl_pipeline.cpp.o
VKLearn: CMakeFiles/VKLearn.dir/vkl_window.cpp.o
VKLearn: CMakeFiles/VKLearn.dir/build.make
VKLearn: /usr/lib/x86_64-linux-gnu/libglfw.so.3.3
VKLearn: CMakeFiles/VKLearn.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/giardinif/C++/Vulkan_Learning/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable VKLearn"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/VKLearn.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/VKLearn.dir/build: VKLearn
.PHONY : CMakeFiles/VKLearn.dir/build

CMakeFiles/VKLearn.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/VKLearn.dir/cmake_clean.cmake
.PHONY : CMakeFiles/VKLearn.dir/clean

CMakeFiles/VKLearn.dir/depend:
	cd /home/giardinif/C++/Vulkan_Learning/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/giardinif/C++/Vulkan_Learning /home/giardinif/C++/Vulkan_Learning /home/giardinif/C++/Vulkan_Learning/build /home/giardinif/C++/Vulkan_Learning/build /home/giardinif/C++/Vulkan_Learning/build/CMakeFiles/VKLearn.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/VKLearn.dir/depend

