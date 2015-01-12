cmake_minimum_required(VERSION 2.8)

####################################

#Déclaration du projet
project(SARAH_Project)

#Déclaration de la version
set (SARAH_Project_VERSION_MAJOR 1)
set (SARAH_Project_VERSION_MINOR 0)

enable_testing()

####################################

#Déclaration de la version de c++ -> C++11 ici
set(CMAKE_CXX_FLAGS "-std=c++0x")

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

####################################

#Génération de la documentation
find_package(Doxygen)
if(DOXYGEN_FOUND)

set(DOXYGEN_INPUT_DIR ${PROJECT_SOURCE_DIR})
set(DOXYGEN_OUTPUT_DIR ${PROJECT_BINARY_DIR}/doc)

configure_file(${PROJECT_SOURCE_DIR}/doc/Doxyfile.in ${PROJECT_BINARY_DIR}/doc/Doxyfile @ONLY)

add_custom_target(doc
                  ${DOXYGEN_EXECUTABLE} ${PROJECT_BINARY_DIR}/doc/Doxyfile
                  WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
                  COMMENT "Generating API documentation with Doxygen" VERBATIM
)
ENDIF(DOXYGEN_FOUND)

include_directories(doc)

####################################

#Recherche de la librairie SFML 2.2
find_package(SFML 2 COMPONENTS system window graphics REQUIRED)

if(NOT SFML_FOUND)
	message(FATAL_ERROR "Impossible to build SARAH : SFML unfound.")
endif(NOT SFML_FOUND)

####################################

#Recherche de certains composants de la librairie boost
find_package(Boost 1.54 COMPONENTS regex REQUIRED)

if(NOT Boost_FOUND)
	message(FATAL_ERROR "Impossible to build SARAH : Boost Regex unfound.")
endif(NOT Boost_FOUND)

include_directories(src)
add_subdirectory(src)