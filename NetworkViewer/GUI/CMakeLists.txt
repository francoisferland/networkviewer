MESSAGE( STATUS "Buiding GUI")

find_package(Qt5Gui REQUIRED)

#QWT LIBRARY FROM QWT SUBMODULE

SET(QWT_SRC_DIR ${PROJECT_SOURCE_DIR}/GUI/qwt/qwt/src)
SET(QWT_INCLUDES ${PROJECT_SOURCE_DIR}/GUI/qwt/qwt/src)

#Create a library with the sources and headers
FILE(GLOB QWT_SRCS "${QWT_SRC_DIR}/*.cpp")
FILE(GLOB QWT_HEADERS "${QWT_INCLUDES}/*.h")

#This will generate moc_* for Qt
QT5_WRAP_CPP(QWT_MOC_SRCS ${QWT_HEADERS})

#Include directories for QWT
INCLUDE_DIRECTORIES(${QWT_SRC_DIR} plugins/ScopeView)

#Build library
add_library(qwt-wrap SHARED ${QWT_SRCS} ${QWT_MOC_SRCS} ${QWT_HEADERS})
qt5_use_modules(qwt-wrap Core Widgets Gui OpenGL Concurrent Svg PrintSupport)



INSTALL(TARGETS qwt-wrap DESTINATION bin)
INSTALL(TARGETS qwt-wrap DESTINATION lib EXPORT qwt-wrap-export-targets)
INSTALL(EXPORT qwt-wrap-export-targets DESTINATION share/cmake)

INSTALL(FILES ${QWT_HEADERS} DESTINATION include/qwt)

SET(NETWORKVIEWER_GENERATED_INCLUDE ${CMAKE_CURRENT_BINARY_DIR}/src)


#Subdirectories
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(plugins)
