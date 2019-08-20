PROJECT(testMedian)

include_directories ("${PROJECT_SOURCE_DIR}/MedianStruct")
add_subdirectory (MedianStruct) 
 
# add the executable
add_executable (TestMedian Test/main.cpp)
target_link_libraries (TestMedian MedianStruct)
