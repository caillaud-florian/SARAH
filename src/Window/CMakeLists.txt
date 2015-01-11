file(GLOB_RECURSE window_files *)

add_library(window SHARED ${window_files})

target_link_libraries(window ${SFML_LIBRARIES})