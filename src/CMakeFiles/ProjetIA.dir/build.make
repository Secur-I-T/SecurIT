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
CMAKE_SOURCE_DIR = /home/pi/SecurIT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/SecurIT/src

# Include any dependencies generated for this target.
include CMakeFiles/ProjetIA.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ProjetIA.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProjetIA.dir/flags.make

CMakeFiles/ProjetIA.dir/main.cpp.o: CMakeFiles/ProjetIA.dir/flags.make
CMakeFiles/ProjetIA.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/SecurIT/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ProjetIA.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProjetIA.dir/main.cpp.o -c /home/pi/SecurIT/src/main.cpp

CMakeFiles/ProjetIA.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjetIA.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/SecurIT/src/main.cpp > CMakeFiles/ProjetIA.dir/main.cpp.i

CMakeFiles/ProjetIA.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjetIA.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/SecurIT/src/main.cpp -o CMakeFiles/ProjetIA.dir/main.cpp.s

CMakeFiles/ProjetIA.dir/speaker.cpp.o: CMakeFiles/ProjetIA.dir/flags.make
CMakeFiles/ProjetIA.dir/speaker.cpp.o: speaker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/SecurIT/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ProjetIA.dir/speaker.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProjetIA.dir/speaker.cpp.o -c /home/pi/SecurIT/src/speaker.cpp

CMakeFiles/ProjetIA.dir/speaker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjetIA.dir/speaker.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/SecurIT/src/speaker.cpp > CMakeFiles/ProjetIA.dir/speaker.cpp.i

CMakeFiles/ProjetIA.dir/speaker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjetIA.dir/speaker.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/SecurIT/src/speaker.cpp -o CMakeFiles/ProjetIA.dir/speaker.cpp.s

CMakeFiles/ProjetIA.dir/test.cpp.o: CMakeFiles/ProjetIA.dir/flags.make
CMakeFiles/ProjetIA.dir/test.cpp.o: test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/SecurIT/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ProjetIA.dir/test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProjetIA.dir/test.cpp.o -c /home/pi/SecurIT/src/test.cpp

CMakeFiles/ProjetIA.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjetIA.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/SecurIT/src/test.cpp > CMakeFiles/ProjetIA.dir/test.cpp.i

CMakeFiles/ProjetIA.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjetIA.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/SecurIT/src/test.cpp -o CMakeFiles/ProjetIA.dir/test.cpp.s

# Object files for target ProjetIA
ProjetIA_OBJECTS = \
"CMakeFiles/ProjetIA.dir/main.cpp.o" \
"CMakeFiles/ProjetIA.dir/speaker.cpp.o" \
"CMakeFiles/ProjetIA.dir/test.cpp.o"

# External object files for target ProjetIA
ProjetIA_EXTERNAL_OBJECTS =

ProjetIA: CMakeFiles/ProjetIA.dir/main.cpp.o
ProjetIA: CMakeFiles/ProjetIA.dir/speaker.cpp.o
ProjetIA: CMakeFiles/ProjetIA.dir/test.cpp.o
ProjetIA: CMakeFiles/ProjetIA.dir/build.make
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_gapi.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_stitching.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_aruco.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_bgsegm.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_bioinspired.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_ccalib.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_dnn_objdetect.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_dpm.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_face.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_freetype.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_fuzzy.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_hfs.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_img_hash.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_line_descriptor.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_quality.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_reg.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_rgbd.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_saliency.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_stereo.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_structured_light.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_superres.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_surface_matching.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_tracking.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_videostab.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_xfeatures2d.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_xobjdetect.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_xphoto.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_shape.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_datasets.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_plot.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_text.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_dnn.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_ml.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_phase_unwrapping.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_optflow.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_ximgproc.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_video.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_objdetect.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_calib3d.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_features2d.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_flann.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_highgui.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_videoio.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_imgcodecs.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_photo.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_imgproc.so.4.1.0
ProjetIA: /opt/opencv-4.1.0/lib/libopencv_core.so.4.1.0
ProjetIA: CMakeFiles/ProjetIA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/SecurIT/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ProjetIA"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ProjetIA.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProjetIA.dir/build: ProjetIA

.PHONY : CMakeFiles/ProjetIA.dir/build

CMakeFiles/ProjetIA.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ProjetIA.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ProjetIA.dir/clean

CMakeFiles/ProjetIA.dir/depend:
	cd /home/pi/SecurIT/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/SecurIT /home/pi/SecurIT /home/pi/SecurIT/src /home/pi/SecurIT/src /home/pi/SecurIT/src/CMakeFiles/ProjetIA.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ProjetIA.dir/depend

