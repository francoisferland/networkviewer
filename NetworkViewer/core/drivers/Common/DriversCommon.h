#ifndef _DRIVERS_COMMON_H_
#define _DRIVERS_COMMON_H_

    #if defined(DRIVERS_COMMON_LIBRARY)
        #define DRIVERS_COMMON_EXPORT Q_DECL_EXPORT
    #else
        #define DRIVERS_COMMON_EXPORT Q_DECL_IMPORT
    #endif
#endif
