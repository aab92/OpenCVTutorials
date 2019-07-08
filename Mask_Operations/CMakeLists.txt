cmake_minimum_required(VERSION 2.8)
project( Mask_Operations )
find_package (OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include)
set(SOURCE
		${SOURCE}
		${PROJECT_SOURCE_DIR}/source/mat_mask_operations.cpp
#[		${PROJECT_SOURCE_DIR}/include/scanReduce.cpp	]
)
add_executable( mat_mask_operations ${SOURCE})
target_link_libraries( mat_mask_operations  ${OpenCV_LIBS})
