file(GLOB_RECURSE kernel_files *)

add_library(kernel SHARED ${kernel_files})

target_link_libraries( kernel ${SFML_LIBRARIES} utilities)