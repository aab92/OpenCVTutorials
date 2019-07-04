cmake_minimum_required(VERSION 2.8)
project( Scan_Tables_Time )
find_package (OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include)
set(SOURCE
		${SOURCE}
		${PROJECT_SOURCE_DIR}/source/main.cpp 
		${PROJECT_SOURCE_DIR}/include/scanReduce.cpp
)
add_executable( how_to_scan_images ${SOURCE})
target_link_libraries( how_to_scan_images  ${OpenCV_LIBS})


