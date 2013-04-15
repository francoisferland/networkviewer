MESSAGE( STATUS "Buiding SocketCAN driver...")


SET(SocketCAN_SRCS
	SocketCAN.cpp
)

SET(SocketCAN_HEADERS 
	SocketCAN.h
)


SET(SocketCAN_QRC 
	
)

# generate rules for building source files from the resources
QT5_ADD_RESOURCES(SocketCAN_QRC_SRCS ${SocketCAN_QRC})

#This will generate moc_* for Qt
QT5_WRAP_CPP(SocketCAN_MOC_SRCS ${SocketCAN_HEADERS})

INCLUDE_DIRECTORIES(${DRIVER_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

add_library(SocketCANDriver SHARED ${SocketCAN_SRCS} ${SocketCAN_HEADERS} ${SocketCAN_QRC_SRCS} ${SocketCAN_MOC_SRCS})
target_link_libraries(SocketCANDriver  ${DRIVER_LIBRARIES} )
qt5_use_modules(SocketCANDriver Core Network Xml XmlPatterns Widgets)

INSTALL(TARGETS SocketCANDriver DESTINATION drivers/SocketCAN)
