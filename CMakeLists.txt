cmake_minimum_required(VERSION 3.0)
project(pvid_zadanie3)

find_package(OpenCV REQUIRED)
add_executable(main.exe src/main.cpp)

target_link_libraries(main.exe opencv_core opencv_highgui opencv_imgproc opencv_ximgproc opencv_imgcodecs)
 
