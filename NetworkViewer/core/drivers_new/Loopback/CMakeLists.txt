MESSAGE( STATUS "Buiding Loopback driver v2...")

find_package(Qt5Core)

SET(Loopback_SRCS
    Loopback.cpp
)

SET(Loopback_HEADERS 
    Loopback.h
)

# generate rules for building source files from the resources
QT5_ADD_RESOURCES(Loopback_QRC_SRCS ${Loopback_QRC})

#This will generate moc_* for Qt
QT5_WRAP_CPP(Loopback_MOC_SRCS ${Loopback_HEADERS})

INCLUDE_DIRECTORIES(${DRIVER_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

add_library(Loopback2Driver SHARED ${Loopback_SRCS} ${Loopback_HEADERS} ${Loopback_QRC_SRCS} ${Loopback_MOC_SRCS})
target_link_libraries(Loopback2Driver ${DRIVER_LIBRARIES} )
qt5_use_modules(Loopback2Driver Core Network Xml XmlPatterns)

#Install directory
INSTALL(TARGETS Loopback2Driver DESTINATION drivers_new/Loopback)
