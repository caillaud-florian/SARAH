file(GLOB_RECURSE model_files *)

add_library(modeling SHARED ${model_files})

target_link_libraries( modeling ${SFML_LIBRARIES} utilities)