project(fruit-machine-io)

set(fm_io_SOURCES
    include/logging.h
    src/logging.cpp
)

add_library(${PROJECT_NAME} STATIC
    ${fm_io_SOURCES}
)

target_include_directories(fruit-machine-io
    PUBLIC include
)
