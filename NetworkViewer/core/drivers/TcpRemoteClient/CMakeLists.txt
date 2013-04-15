MESSAGE( STATUS "Buiding TcpRemoteClient driver...")


SET(TcpRemoteClient_SRCS
	TcpRemoteClient.cpp
)

SET(TcpRemoteClient_HEADERS 
	TcpRemoteClient.h
)

SET(TcpRemoteClient_UIS
	
)

SET(TcpRemoteClient_QRC 
	
)

# generate rules for building source files from the resources
QT5_ADD_RESOURCES(TcpRemoteClient_QRC_SRCS ${TcpRemoteClient_QRC})

#This will generate moc_* for Qt
QT5_WRAP_CPP(TcpRemoteClient_MOC_SRCS ${TcpRemoteClient_HEADERS})

INCLUDE_DIRECTORIES(${DRIVER_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

add_library(TcpRemoteClientDriver SHARED ${TcpRemoteClient_SRCS} ${TcpRemoteClient_HEADERS} ${TcpRemoteClient_QRC_SRCS} ${TcpRemoteClient_MOC_SRCS})
target_link_libraries(TcpRemoteClientDriver  ${DRIVER_LIBRARIES})
qt5_use_modules(TcpRemoteClientDriver Core Network Xml XmlPatterns Widgets)

INSTALL(TARGETS TcpRemoteClientDriver DESTINATION drivers/TcpRemoteClient)
