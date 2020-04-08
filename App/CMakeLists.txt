cmake_minimum_required(VERSION 2.8)
include(ExternalProject)

# Ajout d'un module cmake personnalisé pour générer boost
list(APPEND CMAKE_MODULE_PATH  "${CMAKE_SOURCE_DIR}/cmake/Modules/")

project (xfoil)

    # Trouver les bibliothèques et interpréteurs python par défaut
    find_package(PythonInterp REQUIRED)
    find_package(PythonLibs REQUIRED)
    include(BuildBoost) # module personnalisé

    include_directories(${Boost_INCLUDE_DIR} ${PYTHON_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIR})

    # Génère et lie le module pyXfoil
    add_library(pyXfoil SHARED pyXfoil.cpp)
    target_link_libraries(pyXfoil ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
    add_dependencies(/Users/fredericnivoix/Library/Preferences/FreeCAD/Mod/AirPlaneDesign/App/XFoil-lib/libXFoil.dylib /Users/fredericnivoix/Developpement/boost_1_72_0/boost)

    # Ajuste le nom de la bibliothèque pour coller à ce qu'attend Python
    set_target_properties(pyXfoil PROPERTIES SUFFIX .o)
    set_target_properties(pyXfoil PROPERTIES PREFIX "")
#/Users/fredericnivoix/Developpement/boost_1_72_0/boost
