networkviewer
=============

NetworkViewer is a cross-platform Qt5 GUI used to interact with distributed nodes on multi-protocol Networks. It can be seen as an information aggregator where variables from multiple network types such as CAN bus or RS-232/422/485 
networks are combined in a single GUI application. The tool is used at the IntRoLab (http://introlab.3it.usherbrooke.ca) mobile robotics lab to monitor, configure and quick prototyping of distributed robot controllers.


== Specifications ==
* Support multiple modules/nodes on the bus with multiple types of microcontrollers
* Easy read/write access to distributed variables
** Each module contains its own configuration and variables
** Configurations can be made dynamic and change over time
* Support visualization of multiple variables simultaneously
** Textual visualization is also supported
** Real-Time plot
* User-defined graphical plugins for easier interaction with modules
* Support multiple communication protocols through plug-in drivers


Requirements
============

* Qt5.1 or later
* CMake

Notes for compiling with Qt5
============================

* CMAKE_PREFIX_PATH environment variable must contain the lib/cmake directory of your Qt5 installation.
* In the root directory type :
        
        git submodule init                
        git submodule update

Once done, you can compile NetworkViewer from the NetworkViewer directory. Open the CMakeLists.txt file with QtCreator or run the cmake command from the build directory.

        mkdir build
        cd build
        cmake ../
        make
        

