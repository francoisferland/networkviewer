MESSAGE( STATUS "Buiding driver common base ...")

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

SET(DriverCommon_SRCS
    SerialPortSelectionDialog.cpp
)

SET(DriverCommon_HEADERS 
    SerialPortSelectionDialog.h
)

SET(DriverCommon_UIS
    SerialPortSelectionDialog.ui	
)

SET(DriverCommon_QRC 
	
)

# generate rules for building source files from the resources
QT5_ADD_RESOURCES(DriverCommon_QRC_SRCS ${DriverCommon_QRC})

#This will generate ui_* for Qt
QT5_WRAP_UI(DriverCommon_UI_SRCS ${DriverCommon_UIS})

#This will generate moc_* for Qt
QT5_WRAP_CPP(DriverCommon_MOC_SRCS ${DriverCommon_HEADERS})

INCLUDE_DIRECTORIES(${DRIVER_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

add_library(DriverCommon SHARED ${DriverCommon_SRCS} ${DriverCommon_HEADERS} ${DriverCommon_QRC_SRCS} ${DriverCommon_MOC_SRCS} ${DriverCommon_UI_SRCS}  )
target_link_libraries(DriverCommon networkViewerCore QextSerialPort)
qt5_use_modules(DriverCommon Core Network Xml XmlPatterns Widgets)

INSTALL(TARGETS DriverCommon DESTINATION lib)
