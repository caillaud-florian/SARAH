file(GLOB_RECURSE all_files 
     			*)

#Déclaration de l'exécutable
add_executable( sarah ${all_files})

#Lien avec les bibliothèques externes
target_link_libraries( sarah sfml-graphics sfml-window sfml-system GL boost_regex)
