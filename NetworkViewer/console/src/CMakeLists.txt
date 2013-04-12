MESSAGE( STATUS "Buiding console and osc_generator applications")

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/core/src)

#netvconsole application
add_executable(netvconsole main.cpp)
target_link_libraries(netvconsole networkViewerCore)
qt5_use_modules(netvconsole Core Xml Network)
INSTALL(TARGETS netvconsole DESTINATION bin)


#osc_generator application
add_executable(osc_generator osc_generator.cpp osc_generator.h)
target_link_libraries(osc_generator networkViewerCore)
qt5_use_modules(osc_generator Core Xml Network)
INSTALL(TARGETS osc_generator DESTINATION bin)
