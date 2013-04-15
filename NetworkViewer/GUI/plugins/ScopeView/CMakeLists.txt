MESSAGE( STATUS "Buiding ScopeView plugin...")


SET(Plugin_SRCS
    ScopeCurve.cpp
    ScopeView.cpp
    ScopeVariableConfig.cpp
)	

SET(Plugin_HEADERS 
    ScopeCurve.h
    ScopeView.h
    ScopeVariableConfig.h
)

SET(Plugin_UIS
	ScopeView.ui
    ScopeVariableConfig.ui
)

SET(Plugin_QRC 
	
)

# generate rules for building source files from the resources
QT5_ADD_RESOURCES(Plugin_QRC_SRCS ${Plugin_QRC})

#This will generate ui_* for Qt
QT5_WRAP_UI(Plugin_UI_SRCS ${Plugin_UIS})

#This will generate moc_* for Qt
QT5_WRAP_CPP(Plugin_MOC_SRCS ${Plugin_HEADERS})

INCLUDE_DIRECTORIES(./ ${PLUGIN_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

add_library(ScopeView SHARED ${Plugin_SRCS} ${Plugin_HEADERS} ${Plugin_QRC_SRCS} ${Plugin_MOC_SRCS} ${Plugin_UI_SRCS}  )
target_link_libraries(ScopeView  qwt-wrap ${PLUGIN_LIBRARIES})
qt5_use_modules(ScopeView Core Widgets Gui OpenGL Concurrent Xml Svg PrintSupport Script Network Declarative WebKit WebKitWidgets)

#Install directory
INSTALL(TARGETS ScopeView DESTINATION plugins/ScopeView)


