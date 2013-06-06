# Install script for directory: C:/WORK-QT5/networkviewer/NetworkViewer/config

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

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/config" TYPE FILE FILES
    "C:/WORK-QT5/networkviewer/NetworkViewer/config/INTROLAB_J0Pwr.xml"
    "C:/WORK-QT5/networkviewer/NetworkViewer/config/INTROLAB_Unidrive_v1.xml"
    "C:/WORK-QT5/networkviewer/NetworkViewer/config/INTROLAB_Unidrive_v2.xml"
    "C:/WORK-QT5/networkviewer/NetworkViewer/config/INTROLAB_ReddyHead.xml"
    "C:/WORK-QT5/networkviewer/NetworkViewer/config/INTROLAB_dsPICDrive.xml"
    "C:/WORK-QT5/networkviewer/NetworkViewer/config/INTROLAB_Tactile.xml"
    "C:/WORK-QT5/networkviewer/NetworkViewer/config/LoopbackTest.xml"
    "C:/WORK-QT5/networkviewer/NetworkViewer/config/INTROLAB_ADELeg.xml"
    "C:/WORK-QT5/networkviewer/NetworkViewer/config/NETVArduino_Analog.xml"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

