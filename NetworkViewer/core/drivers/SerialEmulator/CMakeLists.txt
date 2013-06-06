MESSAGE( STATUS "Buiding SerialEmulator driver...")


SET(SerialEmulator_SRCS
    SerialEmulator.cpp
)

SET(SerialEmulator_HEADERS 
    SerialEmulator.h
)


SET(SerialEmulator_QRC 
	
)


# generate rules for building source files from the resources
QT5_ADD_RESOURCES(SerialEmulator_QRC_SRCS ${SerialEmulator_QRC})

#This will generate moc_* for Qt
QT5_WRAP_CPP(SerialEmulator_MOC_SRCS ${SerialEmulator_HEADERS})

INCLUDE_DIRECTORIES(${DRIVER_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

add_library(SerialEmulatorDriver SHARED ${SerialEmulator_SRCS} ${SerialEmulator_HEADERS} ${SerialEmulator_QRC_SRCS} ${SerialEmulator_MOC_SRCS})
target_link_libraries(SerialEmulatorDriver ${DRIVER_LIBRARIES} )
qt5_use_modules(SerialEmulatorDriver Core Network Xml XmlPatterns Widgets SerialPort)


INSTALL(TARGETS SerialEmulatorDriver DESTINATION drivers/SerialEmulator)
