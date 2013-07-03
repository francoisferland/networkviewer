MESSAGE( STATUS "Buiding tests applications")

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/core/src)

#netvconsole application
add_executable(test_Serializer test_Serializer.cpp)
target_link_libraries(test_Serializer networkViewerCore)
qt5_use_modules(test_Serializer Core Xml Network)
INSTALL(TARGETS test_Serializer DESTINATION bin)

