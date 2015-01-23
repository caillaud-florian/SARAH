cmake_minimum_required(VERSION 2.8)

#################################################### BUILD OPTIONS ###############################################

#Définition de clang comme compilateur par défaut
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

#Déclaration du type de build : Debug ou Release
if(NOT DEFINED CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE Debug CACHE STRING "L'option de build par défaut est : Debug.")
endif(NOT DEFINED CMAKE_BUILD_TYPE)

#Déclaration des flags commun debug/release
set(CMAKE_CXX_FLAGS "-std=c++0x")

if(CMAKE_BUILD_TYPE STREQUAL Debug)
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${CMAKE_CXX_FLAGS} -Wall")
else(CMAKE_BUILD_TYPE STREQUAL Debug)
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${CMAKE_CXX_FLAGS}")
endif(CMAKE_BUILD_TYPE STREQUAL Debug)

message("======================== ${CMAKE_BUILD_TYPE} CLANG ========================")

if(UNIX)
	find_program( MEMORYCHECK_COMMAND valgrind )
  	set(CTEST_MEMORYCHECK_COMMAND, ${MEMORYCHECK_COMMAND})
  	set(CTEST_MEMORYCHECK_COMMAND_OPTIONS, "--trace-children=yes --leak-check=full")
endif()

#################################################### PROJET #####################################################

#Déclaration du projet
project(SARAH_Project)

#Déclaration de la version
set (SARAH_Project_VERSION_MAJOR 1)
set (SARAH_Project_VERSION_MINOR 0)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

#################################################### PACKAGES #####################################################

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

#Recherche de la librairie OpenGL
find_package(OpenGL)

if(NOT OPENGL_FOUND)
	message(FATAL_ERROR "Impossible to build SARAH : OpenGL unfound.")
endif(NOT OPENGL_FOUND)

include_directories(${OPENGL_INCLUDE_DIR})

####################################

#Recherche de la librairie SFML 2.2
find_package(SFML 2 COMPONENTS system window graphics)

if(NOT SFML_FOUND)
	message(FATAL_ERROR "Impossible to build SARAH : SFML unfound.")
endif(NOT SFML_FOUND)

include_directories(${SFML_INCLUDE_DIR})

####################################

#Recherche de certains composants de la librairie boost
find_package(Boost 1.54 COMPONENTS regex)

if(NOT Boost_FOUND)
	message(FATAL_ERROR "Impossible to build SARAH : Boost Regex unfound.")
endif(NOT Boost_FOUND)

#################################################### INCLUDES ###################################################

include_directories(src)
add_subdirectory(src)

if(CMAKE_BUILD_TYPE STREQUAL Debug)
	include(CTest)
endif(CMAKE_BUILD_TYPE STREQUAL Debug)