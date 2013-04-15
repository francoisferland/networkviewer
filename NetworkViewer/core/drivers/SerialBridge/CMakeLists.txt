MESSAGE( STATUS "Buiding SerialBridge driver...")

SET(SerialBridge_SRCS
	SerialBridge.cpp
)

SET(SerialBridge_HEADERS 
	SerialBridge.h
)

SET(SerialBridge_UIS
	
)

SET(SerialBridge_QRC 
	
)


# generate rules for building source files from the resources
QT5_ADD_RESOURCES(SerialBridge_QRC_SRCS ${SerialBridge_QRC})

#This will generate ui_* for Qt
QT5_WRAP_UI(SerialBridge_UI_SRCS ${SerialBridge_UIS})

#This will generate moc_* for Qt
QT5_WRAP_CPP(SerialBridge_MOC_SRCS ${SerialBridge_HEADERS})

INCLUDE_DIRECTORIES(${DRIVER_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} )

add_library(SerialBridgeDriver SHARED ${SerialBridge_SRCS} ${SerialBridge_HEADERS} ${SerialBridge_QRC_SRCS} ${SerialBridge_MOC_SRCS} ${SerialBridge_UI_SRCS}  )
target_link_libraries(SerialBridgeDriver ${DRIVER_LIBRARIES} QextSerialPort)
qt5_use_modules(SerialBridgeDriver Core Network Xml XmlPatterns Widgets)

INSTALL(TARGETS SerialBridgeDriver DESTINATION drivers/SerialBridge)
