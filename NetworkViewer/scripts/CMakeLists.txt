SET (SCRIPT_FILES
	TestScript.js
)

add_custom_target(scripts SOURCES ${SCRIPT_FILES})

INSTALL( FILES ${SCRIPT_FILES} DESTINATION scripts)
