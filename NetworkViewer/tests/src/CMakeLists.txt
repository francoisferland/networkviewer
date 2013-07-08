MESSAGE( STATUS "Buiding tests applications")

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/core/src
                    ${CMAKE_CURRENT_BINARY_DIR})


SET (TEST_SERIALIZER_HEADERS
    test_Serializer.h
)

QT5_WRAP_CPP(TEST_SERIALIZER_MOC_SRCS ${TEST_SERIALIZER_HEADERS})

#netvconsole application
add_executable(test_Serializer test_Serializer.cpp ${TEST_SERIALIZER_MOC_SRCS} ${TEST_SERIALIZER_HEADERS})
target_link_libraries(test_Serializer networkViewerCore)
qt5_use_modules(test_Serializer Core Xml Network)
INSTALL(TARGETS test_Serializer DESTINATION bin)
