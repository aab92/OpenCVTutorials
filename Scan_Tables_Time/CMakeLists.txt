cmake_minimum_required(VERSION 2.8)
project( Scan_Tables_Time )
find_package (OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( scanTablesTime source/main.cpp)
target_link_libraries( scanTablesTime  ${OpenCV_LIBS})


