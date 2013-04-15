MESSAGE( STATUS "Buiding PCAN driver...")

IF (WIN32)
	SET(PCAN_SRCS PCANDevice.cpp)
ELSE (WIN32)
	SET(PCAN_SRCS PCANDeviceLinux.cpp)
ENDIF(WIN32)

SET(PCAN_HEADERS
    PCANDevice.h
)


SET(PCAN_QRC

)

# generate rules for building source files from the resources
QT5_ADD_RESOURCES(PCAN_QRC_SRCS ${PCAN_QRC})

#This will generate moc_* for Qt
QT5_WRAP_CPP(PCAN_MOC_SRCS ${PCAN_HEADERS})

INCLUDE_DIRECTORIES(${DRIVER_INCLUDES} ${PROJECT_SOURCE_DIR}/core/drivers/PCAN ${CMAKE_CURRENT_BINARY_DIR})


IF(WIN32)

	MESSAGE( STATUS "Buiding PCAN driver for Windows...")

	add_library(PCANDriver SHARED ${PCAN_SRCS} ${PCAN_HEADERS} ${PCAN_QRC_SRCS} ${PCAN_MOC_SRCS})
    target_link_libraries(PCANDriver  ${DRIVER_LIBRARIES} -L${PROJECT_SOURCE_DIR}/core/drivers/PCAN PCANBasic.dll)
	qt5_use_modules(PCANDriver Core Network Xml XmlPatterns Widgets)

	INSTALL(TARGETS PCANDriver DESTINATION drivers/PCANDriver)

	SET(PCAN_DLL
                PCANBasic.dll
	)

	#Install Windows DLLS
	INSTALL( FILES ${PCAN_DLL} DESTINATION bin)

ENDIF(WIN32)


IF (UNIX AND NOT APPLE)
        FIND_FILE(PCAN_FILE "/usr/include/libpcan.h")
	IF (PCAN_FILE)
        MESSAGE( STATUS "Buiding PCAN driver for Linux... ${PCAN_FILE}")
		add_library(PCANDriver SHARED ${PCAN_SRCS} ${PCAN_HEADERS} ${PCAN_QRC_SRCS} ${PCAN_MOC_SRCS})
        target_link_libraries(PCANDriver  ${DRIVER_LIBRARIES} -L/usr/lib -lpcan)
        qt5_use_modules(PCANDriver Core Network Xml XmlPatterns Widgets)
		INSTALL(TARGETS PCANDriver DESTINATION drivers/PCANDriver)
	ENDIF(PCAN_FILE)
ENDIF(UNIX AND NOT APPLE)


