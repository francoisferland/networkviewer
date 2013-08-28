
find_package(Qt5Gui REQUIRED)

#Include directories
INCLUDE_DIRECTORIES(
                ${PROJECT_SOURCE_DIR}
                ${CMAKE_CURRENT_BINARY_DIR}
                ${QWT_SRC_DIR}
                ${PROJECT_SOURCE_DIR}/core/src
                )


#CREATE THE SHARED LIBRARY FOR PLUGINS
SET(NETVModuleView_UIS
    NETVModuleView.ui
)

SET(NETVModuleView_SRCS
    NETVModuleView.cpp
)

SET(NETVModuleView_HEADERS
    NETVModuleView.h
)


SET(NETVModuleView_QRC

)


#Generate rules for building source files from the resources
QT5_ADD_RESOURCES(NETVModuleView_QRC_SRCS ${NETVModuleView_QRC})

#This will generate ui_* for Qt
QT5_WRAP_UI(NETVModuleView_UI_SRCS ${NETVModuleView_UIS})

#This will generate moc_* for Qt
QT5_WRAP_CPP(NETVModuleView_MOC_SRCS ${NETVModuleView_HEADERS})

#NETVModuleView Library
add_library(NETVModuleView SHARED ${NETVModuleView_SRCS} ${NETVModuleView_HEADERS} ${NETVModuleView_MOC_SRCS} ${NETVModuleView_UI_SRCS} ${NETVModuleView_QRC_SRCS})
target_link_libraries(NETVModuleView networkViewerCore)
qt5_use_modules(NETVModuleView Core Widgets Gui OpenGL Xml Concurrent Svg PrintSupport Script Network Declarative WebKit WebKitWidgets)

INSTALL(TARGETS NETVModuleView DESTINATION bin)
INSTALL(TARGETS NETVModuleView DESTINATION lib)
