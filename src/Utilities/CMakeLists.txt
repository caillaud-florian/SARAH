file(GLOB_RECURSE utilities_files *)

add_library(utilities SHARED ${utilities_files})

#target_link_libraries(utilities ...)