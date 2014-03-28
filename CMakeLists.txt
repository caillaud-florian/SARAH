cmake_minimum_required(VERSION 2.8)

#Déclaration du projet
project(SARAH_Project)

#Déclaration de la version
set (SARAH_Project_VERSION_MAJOR 1)
set (SARAH_Project_VERSION_MINOR 0)

#Déclaration de la version de c++ -> C++11 ici
set(CMAKE_CXX_FLAGS "-std=c++0x")

#Génération de la documentation
find_package(Doxygen)
if(DOXYGEN_FOUND)

set(DOXYFILE_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/ CACHE PATH 
    Directory where the documentation is going to be generated)
add_custom_target(doc
                  ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/doc/config.dox
                  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                  COMMENT "Generating API documentation with Doxygen" VERBATIM
)
ENDIF(DOXYGEN_FOUND)

include_directories(src)
add_subdirectory(src)