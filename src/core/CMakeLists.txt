add_library(core STATIC
    core.h
)

target_link_libraries(core PUBLIC
    Qt6::Core
    Qt6::Concurrent
    Eigen3::Eigen
)

target_include_directories(core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
