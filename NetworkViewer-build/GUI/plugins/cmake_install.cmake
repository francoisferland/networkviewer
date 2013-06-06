# Install script for directory: C:/WORK-QT5/networkviewer/NetworkViewer/GUI/plugins

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "C:/NetworkViewer-1.1.17")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("C:/WORK-QT5/networkviewer/NetworkViewer-build/GUI/plugins/sample/cmake_install.cmake")
  INCLUDE("C:/WORK-QT5/networkviewer/NetworkViewer-build/GUI/plugins/ScriptEngine/cmake_install.cmake")
  INCLUDE("C:/WORK-QT5/networkviewer/NetworkViewer-build/GUI/plugins/Logger/cmake_install.cmake")
  INCLUDE("C:/WORK-QT5/networkviewer/NetworkViewer-build/GUI/plugins/ScopeView/cmake_install.cmake")
  INCLUDE("C:/WORK-QT5/networkviewer/NetworkViewer-build/GUI/plugins/dsPICBootloader/cmake_install.cmake")
  INCLUDE("C:/WORK-QT5/networkviewer/NetworkViewer-build/GUI/plugins/DeclarativeTest/cmake_install.cmake")
  INCLUDE("C:/WORK-QT5/networkviewer/NetworkViewer-build/GUI/plugins/Console/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

