MESSAGE( STATUS "Buiding driver common base ...")

add_definitions(-DDRIVERS_COMMON_LIBRARY)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

SET(DriversCommon_SRCS
    SerialPortSelectionDialog.cpp
)

SET(DriversCommon_HEADERS
    DriversCommon.h
    SerialPortSelectionDialog.h
)

SET(DriversCommon_UIS
    SerialPortSelectionDialog.ui	
)

SET(DriversCommon_QRC
	
)

# generate rules for building source files from the resources
QT5_ADD_RESOURCES(DriversCommon_QRC_SRCS ${DriversCommon_QRC})

#This will generate ui_* for Qt
QT5_WRAP_UI(DriversCommon_UI_SRCS ${DriversCommon_UIS})

#This will generate moc_* for Qt
QT5_WRAP_CPP(DriversCommon_MOC_SRCS ${DriversCommon_HEADERS})

INCLUDE_DIRECTORIES(${DRIVER_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

add_library(DriversCommon SHARED ${DriversCommon_SRCS} ${DriversCommon_HEADERS} ${DriversCommon_QRC_SRCS} ${DriversCommon_MOC_SRCS} ${DriversCommon_UI_SRCS}  )
target_link_libraries(DriversCommon networkViewerCore)
qt5_use_modules(DriversCommon Core Network Xml XmlPatterns Widgets SerialPort)

INSTALL(TARGETS DriversCommon DESTINATION lib)
