file(GLOB_RECURSE reader_files *)

add_library(reader SHARED ${reader_files})

target_link_libraries(reader utilities boost_regex)