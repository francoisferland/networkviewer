########################
# Configurations
########################

SET(DRIVER_INCLUDES
        ${PROJECT_SOURCE_DIR}/core/src
)

SET(DRIVER_LIBRARIES
    networkViewerCore
)

SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/drivers_new)

ADD_SUBDIRECTORY(Loopback)




