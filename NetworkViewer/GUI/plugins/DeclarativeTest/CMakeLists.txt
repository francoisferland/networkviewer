MESSAGE( STATUS "Buiding DeclarativeTest plugin...")

SET(DeclarativeTest_SRCS
	DeclarativeTest.cpp
)

SET(DeclarativeTest_HEADERS 
	DeclarativeTest.h
)

SET(DeclarativeTest_UIS
	DeclarativeTest.ui
)

SET(DeclarativeTest_QRC 
        DeclarativeTest.qrc
)

# generate rules for building source files from the resources
QT5_ADD_RESOURCES(DeclarativeTest_QRC_SRCS ${DeclarativeTest_QRC})

#This will generate ui_* for Qt
QT5_WRAP_UI(DeclarativeTest_UI_SRCS ${DeclarativeTest_UIS})

#This will generate moc_* for Qt
QT5_WRAP_CPP(DeclarativeTest_MOC_SRCS ${DeclarativeTest_HEADERS})

INCLUDE_DIRECTORIES(./ ${PLUGIN_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

add_library(DeclarativeTestPlugin SHARED ${DeclarativeTest_SRCS} ${DeclarativeTest_HEADERS} ${DeclarativeTest_QRC_SRCS} ${DeclarativeTest_MOC_SRCS} ${DeclarativeTest_UI_SRCS}  )
target_link_libraries(DeclarativeTestPlugin ${PLUGIN_LIBRARIES})
qt5_use_modules(DeclarativeTestPlugin Core Widgets Gui OpenGL Concurrent Xml Svg PrintSupport Script Network Declarative WebKit WebKitWidgets)

#Install directory
INSTALL(TARGETS DeclarativeTestPlugin DESTINATION plugins/declarativeTest)	

