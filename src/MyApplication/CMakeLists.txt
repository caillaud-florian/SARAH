file(GLOB_RECURSE my_app_files *)

#Déclaration de l'exécutable
add_executable(my_sarah ${my_app_files})
target_link_libraries(my_sarah kernel modeling reader utilities)