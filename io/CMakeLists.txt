project(fruit-machine-io)

set(IO_SOURCES
    include/logging.h
    src/logging.cpp
)

add_library(${PROJECT_NAME} STATIC
    ${IO_SOURCES}
)

target_include_directories(fruit-machine-io
    PUBLIC include
)
