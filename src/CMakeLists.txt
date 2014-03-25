cmake_minimum_required(VERSION 2.8)

#Déclaration du projet
project(SARAH_Project)

#Déclaration de la version
set (SARAH_Project_VERSION_MAJOR 1)
set (SARAH_Project_VERSION_MINOR 0)

#Déclaration de la version de c++ -> C++11 ici
set(CMAKE_CXX_FLAGS "-std=c++0x")

#inclusion des bibliothèques externes
#include_directories(/chemin/vers/boost_x_xx_x)
#link_directories(/chemin/vers/boost_x_xx_x/stage/lib)

file(GLOB_RECURSE all_files 
     			*)

#Déclaration de l'exécutable
add_executable( sarah ${all_files})

#Lien avec les bibliothèques externes
target_link_libraries( sarah sfml-graphics sfml-window sfml-system GL boost_regex)
