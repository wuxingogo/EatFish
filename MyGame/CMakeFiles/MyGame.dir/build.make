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
CMAKE_SOURCE_DIR = /home/ly/cocos2d-project/MyGame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ly/cocos2d-project/MyGame

# Include any dependencies generated for this target.
include CMakeFiles/MyGame.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MyGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyGame.dir/flags.make

CMakeFiles/MyGame.dir/proj.linux/main.cpp.o: CMakeFiles/MyGame.dir/flags.make
CMakeFiles/MyGame.dir/proj.linux/main.cpp.o: proj.linux/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ly/cocos2d-project/MyGame/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MyGame.dir/proj.linux/main.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MyGame.dir/proj.linux/main.cpp.o -c /home/ly/cocos2d-project/MyGame/proj.linux/main.cpp

CMakeFiles/MyGame.dir/proj.linux/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyGame.dir/proj.linux/main.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ly/cocos2d-project/MyGame/proj.linux/main.cpp > CMakeFiles/MyGame.dir/proj.linux/main.cpp.i

CMakeFiles/MyGame.dir/proj.linux/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyGame.dir/proj.linux/main.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ly/cocos2d-project/MyGame/proj.linux/main.cpp -o CMakeFiles/MyGame.dir/proj.linux/main.cpp.s

CMakeFiles/MyGame.dir/proj.linux/main.cpp.o.requires:
.PHONY : CMakeFiles/MyGame.dir/proj.linux/main.cpp.o.requires

CMakeFiles/MyGame.dir/proj.linux/main.cpp.o.provides: CMakeFiles/MyGame.dir/proj.linux/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/proj.linux/main.cpp.o.provides.build
.PHONY : CMakeFiles/MyGame.dir/proj.linux/main.cpp.o.provides

CMakeFiles/MyGame.dir/proj.linux/main.cpp.o.provides.build: CMakeFiles/MyGame.dir/proj.linux/main.cpp.o

CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o: CMakeFiles/MyGame.dir/flags.make
CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o: Classes/AppDelegate.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ly/cocos2d-project/MyGame/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o -c /home/ly/cocos2d-project/MyGame/Classes/AppDelegate.cpp

CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ly/cocos2d-project/MyGame/Classes/AppDelegate.cpp > CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.i

CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ly/cocos2d-project/MyGame/Classes/AppDelegate.cpp -o CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.s

CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o.requires:
.PHONY : CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o.requires

CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o.provides: CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o.provides.build
.PHONY : CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o.provides

CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o.provides.build: CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o

CMakeFiles/MyGame.dir/Classes/StartLayer.cpp.o: CMakeFiles/MyGame.dir/flags.make
CMakeFiles/MyGame.dir/Classes/StartLayer.cpp.o: Classes/StartLayer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ly/cocos2d-project/MyGame/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MyGame.dir/Classes/StartLayer.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MyGame.dir/Classes/StartLayer.cpp.o -c /home/ly/cocos2d-project/MyGame/Classes/StartLayer.cpp

CMakeFiles/MyGame.dir/Classes/StartLayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyGame.dir/Classes/StartLayer.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ly/cocos2d-project/MyGame/Classes/StartLayer.cpp > CMakeFiles/MyGame.dir/Classes/StartLayer.cpp.i

CMakeFiles/MyGame.dir/Classes/StartLayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyGame.dir/Classes/StartLayer.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ly/cocos2d-project/MyGame/Classes/StartLayer.cpp -o CMakeFiles/MyGame.dir/Classes/StartLayer.cpp.s

CMakeFiles/MyGame.dir/Classes/StartLayer.cpp.o.requires:
.PHONY : CMakeFiles/MyGame.dir/Classes/StartLayer.cpp.o.requires

CMakeFiles/MyGame.dir/Classes/StartLayer.cpp.o.provides: CMakeFiles/MyGame.dir/Classes/StartLayer.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/StartLayer.cpp.o.provides.build
.PHONY : CMakeFiles/MyGame.dir/Classes/StartLayer.cpp.o.provides

CMakeFiles/MyGame.dir/Classes/StartLayer.cpp.o.provides.build: CMakeFiles/MyGame.dir/Classes/StartLayer.cpp.o

CMakeFiles/MyGame.dir/Classes/GameLayer.cpp.o: CMakeFiles/MyGame.dir/flags.make
CMakeFiles/MyGame.dir/Classes/GameLayer.cpp.o: Classes/GameLayer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ly/cocos2d-project/MyGame/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MyGame.dir/Classes/GameLayer.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MyGame.dir/Classes/GameLayer.cpp.o -c /home/ly/cocos2d-project/MyGame/Classes/GameLayer.cpp

CMakeFiles/MyGame.dir/Classes/GameLayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyGame.dir/Classes/GameLayer.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ly/cocos2d-project/MyGame/Classes/GameLayer.cpp > CMakeFiles/MyGame.dir/Classes/GameLayer.cpp.i

CMakeFiles/MyGame.dir/Classes/GameLayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyGame.dir/Classes/GameLayer.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ly/cocos2d-project/MyGame/Classes/GameLayer.cpp -o CMakeFiles/MyGame.dir/Classes/GameLayer.cpp.s

CMakeFiles/MyGame.dir/Classes/GameLayer.cpp.o.requires:
.PHONY : CMakeFiles/MyGame.dir/Classes/GameLayer.cpp.o.requires

CMakeFiles/MyGame.dir/Classes/GameLayer.cpp.o.provides: CMakeFiles/MyGame.dir/Classes/GameLayer.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/GameLayer.cpp.o.provides.build
.PHONY : CMakeFiles/MyGame.dir/Classes/GameLayer.cpp.o.provides

CMakeFiles/MyGame.dir/Classes/GameLayer.cpp.o.provides.build: CMakeFiles/MyGame.dir/Classes/GameLayer.cpp.o

CMakeFiles/MyGame.dir/Classes/BaseFishNode.cpp.o: CMakeFiles/MyGame.dir/flags.make
CMakeFiles/MyGame.dir/Classes/BaseFishNode.cpp.o: Classes/BaseFishNode.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ly/cocos2d-project/MyGame/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MyGame.dir/Classes/BaseFishNode.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MyGame.dir/Classes/BaseFishNode.cpp.o -c /home/ly/cocos2d-project/MyGame/Classes/BaseFishNode.cpp

CMakeFiles/MyGame.dir/Classes/BaseFishNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyGame.dir/Classes/BaseFishNode.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ly/cocos2d-project/MyGame/Classes/BaseFishNode.cpp > CMakeFiles/MyGame.dir/Classes/BaseFishNode.cpp.i

CMakeFiles/MyGame.dir/Classes/BaseFishNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyGame.dir/Classes/BaseFishNode.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ly/cocos2d-project/MyGame/Classes/BaseFishNode.cpp -o CMakeFiles/MyGame.dir/Classes/BaseFishNode.cpp.s

CMakeFiles/MyGame.dir/Classes/BaseFishNode.cpp.o.requires:
.PHONY : CMakeFiles/MyGame.dir/Classes/BaseFishNode.cpp.o.requires

CMakeFiles/MyGame.dir/Classes/BaseFishNode.cpp.o.provides: CMakeFiles/MyGame.dir/Classes/BaseFishNode.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/BaseFishNode.cpp.o.provides.build
.PHONY : CMakeFiles/MyGame.dir/Classes/BaseFishNode.cpp.o.provides

CMakeFiles/MyGame.dir/Classes/BaseFishNode.cpp.o.provides.build: CMakeFiles/MyGame.dir/Classes/BaseFishNode.cpp.o

CMakeFiles/MyGame.dir/Classes/PlayerFishNode.cpp.o: CMakeFiles/MyGame.dir/flags.make
CMakeFiles/MyGame.dir/Classes/PlayerFishNode.cpp.o: Classes/PlayerFishNode.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ly/cocos2d-project/MyGame/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MyGame.dir/Classes/PlayerFishNode.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MyGame.dir/Classes/PlayerFishNode.cpp.o -c /home/ly/cocos2d-project/MyGame/Classes/PlayerFishNode.cpp

CMakeFiles/MyGame.dir/Classes/PlayerFishNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyGame.dir/Classes/PlayerFishNode.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ly/cocos2d-project/MyGame/Classes/PlayerFishNode.cpp > CMakeFiles/MyGame.dir/Classes/PlayerFishNode.cpp.i

CMakeFiles/MyGame.dir/Classes/PlayerFishNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyGame.dir/Classes/PlayerFishNode.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ly/cocos2d-project/MyGame/Classes/PlayerFishNode.cpp -o CMakeFiles/MyGame.dir/Classes/PlayerFishNode.cpp.s

CMakeFiles/MyGame.dir/Classes/PlayerFishNode.cpp.o.requires:
.PHONY : CMakeFiles/MyGame.dir/Classes/PlayerFishNode.cpp.o.requires

CMakeFiles/MyGame.dir/Classes/PlayerFishNode.cpp.o.provides: CMakeFiles/MyGame.dir/Classes/PlayerFishNode.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/PlayerFishNode.cpp.o.provides.build
.PHONY : CMakeFiles/MyGame.dir/Classes/PlayerFishNode.cpp.o.provides

CMakeFiles/MyGame.dir/Classes/PlayerFishNode.cpp.o.provides.build: CMakeFiles/MyGame.dir/Classes/PlayerFishNode.cpp.o

CMakeFiles/MyGame.dir/Classes/JellyfishNode.cpp.o: CMakeFiles/MyGame.dir/flags.make
CMakeFiles/MyGame.dir/Classes/JellyfishNode.cpp.o: Classes/JellyfishNode.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ly/cocos2d-project/MyGame/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MyGame.dir/Classes/JellyfishNode.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MyGame.dir/Classes/JellyfishNode.cpp.o -c /home/ly/cocos2d-project/MyGame/Classes/JellyfishNode.cpp

CMakeFiles/MyGame.dir/Classes/JellyfishNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyGame.dir/Classes/JellyfishNode.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ly/cocos2d-project/MyGame/Classes/JellyfishNode.cpp > CMakeFiles/MyGame.dir/Classes/JellyfishNode.cpp.i

CMakeFiles/MyGame.dir/Classes/JellyfishNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyGame.dir/Classes/JellyfishNode.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ly/cocos2d-project/MyGame/Classes/JellyfishNode.cpp -o CMakeFiles/MyGame.dir/Classes/JellyfishNode.cpp.s

CMakeFiles/MyGame.dir/Classes/JellyfishNode.cpp.o.requires:
.PHONY : CMakeFiles/MyGame.dir/Classes/JellyfishNode.cpp.o.requires

CMakeFiles/MyGame.dir/Classes/JellyfishNode.cpp.o.provides: CMakeFiles/MyGame.dir/Classes/JellyfishNode.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/JellyfishNode.cpp.o.provides.build
.PHONY : CMakeFiles/MyGame.dir/Classes/JellyfishNode.cpp.o.provides

CMakeFiles/MyGame.dir/Classes/JellyfishNode.cpp.o.provides.build: CMakeFiles/MyGame.dir/Classes/JellyfishNode.cpp.o

CMakeFiles/MyGame.dir/Classes/EnemyFishNode.cpp.o: CMakeFiles/MyGame.dir/flags.make
CMakeFiles/MyGame.dir/Classes/EnemyFishNode.cpp.o: Classes/EnemyFishNode.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ly/cocos2d-project/MyGame/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MyGame.dir/Classes/EnemyFishNode.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MyGame.dir/Classes/EnemyFishNode.cpp.o -c /home/ly/cocos2d-project/MyGame/Classes/EnemyFishNode.cpp

CMakeFiles/MyGame.dir/Classes/EnemyFishNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyGame.dir/Classes/EnemyFishNode.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ly/cocos2d-project/MyGame/Classes/EnemyFishNode.cpp > CMakeFiles/MyGame.dir/Classes/EnemyFishNode.cpp.i

CMakeFiles/MyGame.dir/Classes/EnemyFishNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyGame.dir/Classes/EnemyFishNode.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ly/cocos2d-project/MyGame/Classes/EnemyFishNode.cpp -o CMakeFiles/MyGame.dir/Classes/EnemyFishNode.cpp.s

CMakeFiles/MyGame.dir/Classes/EnemyFishNode.cpp.o.requires:
.PHONY : CMakeFiles/MyGame.dir/Classes/EnemyFishNode.cpp.o.requires

CMakeFiles/MyGame.dir/Classes/EnemyFishNode.cpp.o.provides: CMakeFiles/MyGame.dir/Classes/EnemyFishNode.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/EnemyFishNode.cpp.o.provides.build
.PHONY : CMakeFiles/MyGame.dir/Classes/EnemyFishNode.cpp.o.provides

CMakeFiles/MyGame.dir/Classes/EnemyFishNode.cpp.o.provides.build: CMakeFiles/MyGame.dir/Classes/EnemyFishNode.cpp.o

CMakeFiles/MyGame.dir/Classes/BaseEnemyFishNode.cpp.o: CMakeFiles/MyGame.dir/flags.make
CMakeFiles/MyGame.dir/Classes/BaseEnemyFishNode.cpp.o: Classes/BaseEnemyFishNode.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ly/cocos2d-project/MyGame/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MyGame.dir/Classes/BaseEnemyFishNode.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MyGame.dir/Classes/BaseEnemyFishNode.cpp.o -c /home/ly/cocos2d-project/MyGame/Classes/BaseEnemyFishNode.cpp

CMakeFiles/MyGame.dir/Classes/BaseEnemyFishNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyGame.dir/Classes/BaseEnemyFishNode.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ly/cocos2d-project/MyGame/Classes/BaseEnemyFishNode.cpp > CMakeFiles/MyGame.dir/Classes/BaseEnemyFishNode.cpp.i

CMakeFiles/MyGame.dir/Classes/BaseEnemyFishNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyGame.dir/Classes/BaseEnemyFishNode.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ly/cocos2d-project/MyGame/Classes/BaseEnemyFishNode.cpp -o CMakeFiles/MyGame.dir/Classes/BaseEnemyFishNode.cpp.s

CMakeFiles/MyGame.dir/Classes/BaseEnemyFishNode.cpp.o.requires:
.PHONY : CMakeFiles/MyGame.dir/Classes/BaseEnemyFishNode.cpp.o.requires

CMakeFiles/MyGame.dir/Classes/BaseEnemyFishNode.cpp.o.provides: CMakeFiles/MyGame.dir/Classes/BaseEnemyFishNode.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/BaseEnemyFishNode.cpp.o.provides.build
.PHONY : CMakeFiles/MyGame.dir/Classes/BaseEnemyFishNode.cpp.o.provides

CMakeFiles/MyGame.dir/Classes/BaseEnemyFishNode.cpp.o.provides.build: CMakeFiles/MyGame.dir/Classes/BaseEnemyFishNode.cpp.o

# Object files for target MyGame
MyGame_OBJECTS = \
"CMakeFiles/MyGame.dir/proj.linux/main.cpp.o" \
"CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o" \
"CMakeFiles/MyGame.dir/Classes/StartLayer.cpp.o" \
"CMakeFiles/MyGame.dir/Classes/GameLayer.cpp.o" \
"CMakeFiles/MyGame.dir/Classes/BaseFishNode.cpp.o" \
"CMakeFiles/MyGame.dir/Classes/PlayerFishNode.cpp.o" \
"CMakeFiles/MyGame.dir/Classes/JellyfishNode.cpp.o" \
"CMakeFiles/MyGame.dir/Classes/EnemyFishNode.cpp.o" \
"CMakeFiles/MyGame.dir/Classes/BaseEnemyFishNode.cpp.o"

# External object files for target MyGame
MyGame_EXTERNAL_OBJECTS =

bin/MyGame: CMakeFiles/MyGame.dir/proj.linux/main.cpp.o
bin/MyGame: CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o
bin/MyGame: CMakeFiles/MyGame.dir/Classes/StartLayer.cpp.o
bin/MyGame: CMakeFiles/MyGame.dir/Classes/GameLayer.cpp.o
bin/MyGame: CMakeFiles/MyGame.dir/Classes/BaseFishNode.cpp.o
bin/MyGame: CMakeFiles/MyGame.dir/Classes/PlayerFishNode.cpp.o
bin/MyGame: CMakeFiles/MyGame.dir/Classes/JellyfishNode.cpp.o
bin/MyGame: CMakeFiles/MyGame.dir/Classes/EnemyFishNode.cpp.o
bin/MyGame: CMakeFiles/MyGame.dir/Classes/BaseEnemyFishNode.cpp.o
bin/MyGame: CMakeFiles/MyGame.dir/build.make
bin/MyGame: lib/libspine.a
bin/MyGame: lib/libcocostudio.a
bin/MyGame: lib/libcocosbuilder.a
bin/MyGame: lib/libaudio.a
bin/MyGame: lib/libcocos2d.a
bin/MyGame: lib/libextensions.a
bin/MyGame: lib/libchipmunk.a
bin/MyGame: lib/libtinyxml2.a
bin/MyGame: lib/libunzip.a
bin/MyGame: lib/libxxhash.a
bin/MyGame: CMakeFiles/MyGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable bin/MyGame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyGame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyGame.dir/build: bin/MyGame
.PHONY : CMakeFiles/MyGame.dir/build

CMakeFiles/MyGame.dir/requires: CMakeFiles/MyGame.dir/proj.linux/main.cpp.o.requires
CMakeFiles/MyGame.dir/requires: CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o.requires
CMakeFiles/MyGame.dir/requires: CMakeFiles/MyGame.dir/Classes/StartLayer.cpp.o.requires
CMakeFiles/MyGame.dir/requires: CMakeFiles/MyGame.dir/Classes/GameLayer.cpp.o.requires
CMakeFiles/MyGame.dir/requires: CMakeFiles/MyGame.dir/Classes/BaseFishNode.cpp.o.requires
CMakeFiles/MyGame.dir/requires: CMakeFiles/MyGame.dir/Classes/PlayerFishNode.cpp.o.requires
CMakeFiles/MyGame.dir/requires: CMakeFiles/MyGame.dir/Classes/JellyfishNode.cpp.o.requires
CMakeFiles/MyGame.dir/requires: CMakeFiles/MyGame.dir/Classes/EnemyFishNode.cpp.o.requires
CMakeFiles/MyGame.dir/requires: CMakeFiles/MyGame.dir/Classes/BaseEnemyFishNode.cpp.o.requires
.PHONY : CMakeFiles/MyGame.dir/requires

CMakeFiles/MyGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MyGame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MyGame.dir/clean

CMakeFiles/MyGame.dir/depend:
	cd /home/ly/cocos2d-project/MyGame && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ly/cocos2d-project/MyGame /home/ly/cocos2d-project/MyGame /home/ly/cocos2d-project/MyGame /home/ly/cocos2d-project/MyGame /home/ly/cocos2d-project/MyGame/CMakeFiles/MyGame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyGame.dir/depend
