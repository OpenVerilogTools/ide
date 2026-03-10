add_library(gui STATIC
    mainwindow.cc
    mainwindow.h
    sidebar.cc
    sidebar.h
)

target_link_libraries(gui PUBLIC
    Qt6::Widgets
    Qt6::Core
    core
)

target_include_directories(gui PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
