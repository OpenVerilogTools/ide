add_subdirectory(core)
add_subdirectory(gui)

add_executable(IDE
    main.cc
)

target_link_libraries(IDE PRIVATE
    core
    gui
)
