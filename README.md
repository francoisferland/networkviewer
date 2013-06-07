networkviewer
=============

NetworkViewer Multi-Protocol Graphical User Interface

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
        

