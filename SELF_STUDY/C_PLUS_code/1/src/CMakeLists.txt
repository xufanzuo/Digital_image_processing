# SET(OpencvDIR /usr/include/opencv2)
FIND_PACKAGE(OpenCV REQUIRED)

MESSAGE(STATUS "OpenCV libary status:")
MESSAGE(STATUS " version: ${OpenCV_VERSION}")
MESSAGE(STATUS " libaries:${OpenCV_LIBS}")
MESSAGE(STATUS " include path: ${OpenCV_INCLUDE_DIRS}")

# Add OpenCV headers location to your include paths
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})

#Declare the executable target built from your sources
ADD_EXECUTABLE(2_1 2_1.cpp)

TARGET_LINK_LIBRARIES(2_1 ${OpenCV_LIBS})