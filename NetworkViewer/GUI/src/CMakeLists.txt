#GUI/src

find_package(Qt5Gui REQUIRED)



#Include directories
INCLUDE_DIRECTORIES(
                ${PROJECT_SOURCE_DIR}
                ${CMAKE_CURRENT_BINARY_DIR}
                ${QWT_SRC_DIR}
                ${PROJECT_SOURCE_DIR}/core/src
                NETVModuleView
                ${CMAKE_CURRENT_BINARY_DIR}/NETVModuleView
                )

#CREATE THE SHARED LIBRARY FOR PLUGINS
SET(NetworkViewer_Base_UIS
    NetworkView.ui
    ModuleConfigurationView.ui
    TestView.ui
    DeviceSelectorDialog.ui
    PreferencesDialog.ui
    AddVariableDialog.ui
    NETVInterfaceManagerView.ui
    networkviewer.ui
)

SET(NetworkViewer_Base_SRCS
    BasePlugin.cpp
    BasePluginEvent.cpp
    NetworkView.cpp
    ModuleConfigurationView.cpp
    NetworkModuleItem.cpp
    DeviceSelectorDialog.cpp
    PreferencesDialog.cpp
    AddVariableDialog.cpp
    NETVInterfaceManagerView.cpp
)

SET(NetworkViewer_Base_HEADERS
    BasePlugin.h
    BasePluginEvent.h
    NetworkView.h
    ModuleConfigurationView.h
    NetworkModuleItem.h
    DeviceSelectorDialog.h
    NetworkViewerSplashScreen.h
    PreferencesDialog.h
    AddVariableDialog.h
    NETVInterfaceManagerView.h
    networkviewer.h
)


SET(NetworkViewer_Base_QRC
    NetworkViewer.qrc
)

#Generate rules for building source files from the resources
QT5_ADD_RESOURCES(SRCS_QRC ${NetworkViewer_Base_QRC})

#This will generate ui_* for Qt
QT5_WRAP_UI(NetworkViewer_Base_UI_SRCS ${NetworkViewer_Base_UIS})

#This will generate moc_* for Qt
QT5_WRAP_CPP(NetworkViewer_Base_MOC_SRCS ${NetworkViewer_Base_HEADERS})

#NetworkViewer Base Library
add_library(networkViewerBase SHARED ${NetworkViewer_Base_SRCS} ${NetworkViewer_Base_HEADERS} ${NetworkViewer_Base_MOC_SRCS} ${NetworkViewer_Base_UI_SRCS} ${SRCS_QRC})
target_link_libraries(networkViewerBase networkViewerCore NETVModuleView)
qt5_use_modules(networkViewerBase Core Widgets Gui OpenGL Xml Concurrent Svg
    PrintSupport Network
    # WebEngine

)

INSTALL(TARGETS networkViewerBase DESTINATION bin)
INSTALL(TARGETS networkViewerBase DESTINATION lib)

#FIXME EXPORTS
#INSTALL(TARGETS networkViewerBase DESTINATION lib EXPORT networkViewerBase-export-targets)
#INSTALL(EXPORT networkViewerBase-export-targets DESTINATION share/cmake)

#Install headers
INSTALL( FILES ${NetworkViewer_Base_HEADERS} DESTINATION include)
INSTALL( FILES ${NetworkViewer_Base_UI_SRCS} DESTINATION include/ui)


#APPLICATION

#NetworkViewer Executable
add_executable(NetworkViewer main.cpp)
target_link_libraries(NetworkViewer networkViewerCore networkViewerBase NETVModuleView )
qt5_use_modules(NetworkViewer Core Widgets Gui)
INSTALL(TARGETS NetworkViewer DESTINATION bin)

#NetworkViewer Executable
add_executable(networkviewer-test networkviewer.cpp)
target_link_libraries(networkviewer-test networkViewerCore networkViewerBase NETVModuleView )
qt5_use_modules(networkviewer-test Core Widgets Gui)
INSTALL(TARGETS networkviewer-test DESTINATION bin)

#subdirectories
add_subdirectory(NETVModuleView)

