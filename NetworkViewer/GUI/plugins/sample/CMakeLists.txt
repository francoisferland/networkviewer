MESSAGE( STATUS "Buiding Sample plugin...")

find_package(Qt5Gui REQUIRED)

SET(Plugin_SRCS
	SamplePlugin.cpp
)

SET(Plugin_HEADERS 
	SamplePlugin.h
)

SET(Plugin_UIS
	SamplePlugin.ui
)

SET(Plugin_QRC 
	
)

# generate rules for building source files from the resources
QT5_ADD_RESOURCES(Plugin_QRC_SRCS ${Plugin_QRC})

#This will generate ui_* for Qt
QT5_WRAP_UI(Plugin_UI_SRCS ${Plugin_UIS})

#This will generate moc_* for Qt
QT5_WRAP_CPP(Plugin_MOC_SRCS ${Plugin_HEADERS})

INCLUDE_DIRECTORIES(${PLUGIN_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

add_library(SamplePlugin SHARED ${Plugin_SRCS} ${Plugin_HEADERS} ${Plugin_QRC_SRCS} ${Plugin_MOC_SRCS} ${Plugin_UI_SRCS}  )
target_link_libraries(SamplePlugin ${PLUGIN_LIBRARIES})
qt5_use_modules(SamplePlugin Core Widgets Gui Xml Network)

#Install directory
INSTALL(TARGETS SamplePlugin DESTINATION plugins/sample)	

