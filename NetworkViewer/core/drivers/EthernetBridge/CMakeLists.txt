MESSAGE( STATUS "Buiding EthernetBridge driver...")


SET(EthernetBridge_SRCS
	EthernetBridge.cpp
)

SET(EthernetBridge_HEADERS 
	EthernetBridge.h
)



SET(EthernetBridge_QRC 
	
)

# generate rules for building source files from the resources
QT5_ADD_RESOURCES(EthernetBridge_QRC_SRCS ${EthernetBridge_QRC})

#This will generate moc_* for Qt
QT5_WRAP_CPP(EthernetBridge_MOC_SRCS ${EthernetBridge_HEADERS})

INCLUDE_DIRECTORIES(${DRIVER_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

add_library(EthernetBridgeDriver SHARED ${EthernetBridge_SRCS} ${EthernetBridge_HEADERS} ${EthernetBridge_QRC_SRCS} ${EthernetBridge_MOC_SRCS})
target_link_libraries(EthernetBridgeDriver  ${DRIVER_LIBRARIES})
qt5_use_modules(EthernetBridgeDriver Core Network Xml XmlPatterns Widgets)

INSTALL(TARGETS EthernetBridgeDriver DESTINATION drivers/EthernetBridge)
