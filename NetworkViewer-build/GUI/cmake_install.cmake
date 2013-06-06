# Install script for directory: C:/WORK-QT5/networkviewer/NetworkViewer/GUI

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
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/WORK-QT5/networkviewer/NetworkViewer/bin/libqwt-wrap.dll.a")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libqwt-wrap.dll.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libqwt-wrap.dll.a")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "C:/Qt/Qt5.1.0/Tools/MinGW/bin/strip.exe" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libqwt-wrap.dll.a")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/WORK-QT5/networkviewer/NetworkViewer/bin/libqwt-wrap.dll")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libqwt-wrap.dll" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libqwt-wrap.dll")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "C:/Qt/Qt5.1.0/Tools/MinGW/bin/strip.exe" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libqwt-wrap.dll")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/WORK-QT5/networkviewer/NetworkViewer/bin/libqwt-wrap.dll.a")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libqwt-wrap.dll.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libqwt-wrap.dll.a")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "C:/Qt/Qt5.1.0/Tools/MinGW/bin/strip.exe" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libqwt-wrap.dll.a")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "C:/WORK-QT5/networkviewer/NetworkViewer/bin/libqwt-wrap.dll")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libqwt-wrap.dll" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libqwt-wrap.dll")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "C:/Qt/Qt5.1.0/Tools/MinGW/bin/strip.exe" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libqwt-wrap.dll")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/qwt-wrap-export-targets.cmake")
    FILE(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/qwt-wrap-export-targets.cmake"
         "C:/WORK-QT5/networkviewer/NetworkViewer-build/GUI/CMakeFiles/Export/share/cmake/qwt-wrap-export-targets.cmake")
    IF(EXPORT_FILE_CHANGED)
      FILE(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/qwt-wrap-export-targets-*.cmake")
      IF(OLD_CONFIG_FILES)
        MESSAGE(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/qwt-wrap-export-targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        FILE(REMOVE ${OLD_CONFIG_FILES})
      ENDIF(OLD_CONFIG_FILES)
    ENDIF(EXPORT_FILE_CHANGED)
  ENDIF()
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake" TYPE FILE FILES "C:/WORK-QT5/networkviewer/NetworkViewer-build/GUI/CMakeFiles/Export/share/cmake/qwt-wrap-export-targets.cmake")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake" TYPE FILE FILES "C:/WORK-QT5/networkviewer/NetworkViewer-build/GUI/CMakeFiles/Export/share/cmake/qwt-wrap-export-targets-release.cmake")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/qwt" TYPE FILE FILES
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_abstract_legend.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_abstract_scale.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_abstract_scale_draw.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_abstract_slider.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_analog_clock.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_arrow_button.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_clipper.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_color_map.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_column_symbol.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_compass.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_compass_rose.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_compat.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_counter.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_curve_fitter.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_date.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_date_scale_draw.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_date_scale_engine.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_dial.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_dial_needle.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_dyngrid_layout.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_event_pattern.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_global.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_graphic.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_interval.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_interval_symbol.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_knob.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_legend.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_legend_data.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_legend_label.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_magnifier.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_math.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_matrix_raster_data.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_null_paintdevice.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_painter.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_painter_command.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_panner.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_picker.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_picker_machine.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_pixel_matrix.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_abstract_barchart.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_barchart.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_canvas.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_curve.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_dict.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_directpainter.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_glcanvas.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_grid.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_histogram.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_intervalcurve.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_item.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_layout.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_legenditem.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_magnifier.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_marker.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_multi_barchart.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_panner.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_picker.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_rasteritem.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_renderer.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_rescaler.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_scaleitem.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_seriesitem.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_shapeitem.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_spectrocurve.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_spectrogram.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_svgitem.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_textlabel.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_tradingcurve.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_zoneitem.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_plot_zoomer.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_point_3d.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_point_data.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_point_mapper.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_point_polar.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_raster_data.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_round_scale_draw.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_samples.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_sampling_thread.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_scale_div.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_scale_draw.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_scale_engine.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_scale_map.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_scale_widget.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_series_data.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_series_store.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_slider.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_spline.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_symbol.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_system_clock.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_text.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_text_engine.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_text_label.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_thermo.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_transform.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_wheel.h"
    "C:/WORK-QT5/networkviewer/NetworkViewer/GUI/qwt/src/qwt_widget_overlay.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("C:/WORK-QT5/networkviewer/NetworkViewer-build/GUI/src/cmake_install.cmake")
  INCLUDE("C:/WORK-QT5/networkviewer/NetworkViewer-build/GUI/plugins/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

