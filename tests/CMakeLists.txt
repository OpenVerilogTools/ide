find_package(Qt6 REQUIRED COMPONENTS Test)

add_executable(test_core
    test_core.cc
)

target_link_libraries(test_core PRIVATE
    core
    Qt6::Test
)

add_test(NAME CoreTests COMMAND test_core)

add_executable(test_gui
    test_gui.cc
)

target_link_libraries(test_gui PRIVATE
    gui
    core
    Qt6::Test
)

add_test(NAME GUITests COMMAND test_gui)
