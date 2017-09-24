find_package(Qt5Core)

add_definitions(-DNETWORKVIEWER_CORE_LIBRARY)

SET(NETV_CORE_SRCS
    CoreDriver.cpp
    CoreDriverFactory.cpp
    CoreDriverManager.cpp
    CoreMessage.cpp
    CoreSerializer.cpp
    CoreDeserializer.cpp
    NETVMessage.cpp
    CANMessage.cpp
    SerialMessage.cpp
    NETVInterfaceHandler.cpp
    NETVDriverManager.cpp
    NETVScheduler.cpp
    NETVVariable.cpp
    NETVModule.cpp
    NETVModuleConfiguration.cpp
    ModuleVariable.cpp
    ModuleConfiguration.cpp
    NetworkModule.cpp
    NetworkScheduler.cpp
    NETVDevice.cpp
    UserPreferences.cpp
    NETVInterfaceManager.cpp
    NETVRemoteClient.cpp
    NETVRemoteServer.cpp
    NETVBroadcaster.cpp
)

SET(NETV_CORE_HEADERS
    Core.h
    CoreDriverInfo.h
    CoreDriver.h
    CoreDriverFactory.h
    CoreDriverManager.h
    CoreProtocols.h
    CoreMessage.h
    CoreSerializer.h
    CoreDeserializer.h
    NETVMessage.h
    CANMessage.h
    SerialMessage.h
    ModuleConfiguration.h
    ModuleVariable.h
    NETVVariable.h
    NETVModule.h
    NETVModuleConfiguration.h
    NETV_define.h
    NETVDevice.h
    NETVInterfaceHandler.h
    NETVDriverManager.h
    NETVScheduler.h
    NETVInterfaceManager.h
    NETVMessageEvent.h
    NetworkModule.h
    NetworkScheduler.h
    UserPreferences.h
    NETVRemoteClient.h
    NETVRemoteServer.h
    NETVBroadcaster.h
)

#This will generate moc_* for Qt
QT5_WRAP_CPP(NETV_CORE_MOC_SRCS ${NETV_CORE_HEADERS})

#Include directories
INCLUDE_DIRECTORIES(
                ${PROJECT_SOURCE_DIR}
                ${CMAKE_CURRENT_BINARY_DIR}
                ${QWT_SRC_DIR}
                ${PROJECT_SOURCE_DIR}/core/src
)


#NetworkViewer Library
add_library(networkViewerCore SHARED ${NETV_CORE_SRCS} ${NETV_CORE_MOC_SRCS} ${NETV_CORE_HEADERS})
qt5_use_modules(networkViewerCore Core Network Xml XmlPatterns Widgets)

#Install
INSTALL(TARGETS networkViewerCore DESTINATION bin)
INSTALL(TARGETS networkViewerCore DESTINATION lib EXPORT networkViewerCore-export-targets)
INSTALL(EXPORT networkViewerCore-export-targets DESTINATION share/cmake)
