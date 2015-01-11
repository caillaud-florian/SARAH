
########### TEST MVC ###########
add_executable(test_MVC TestMVCMain.cpp)
target_link_libraries(test_MVC kernel modeling reader utilities)
add_test(test_MVC test_MVC)