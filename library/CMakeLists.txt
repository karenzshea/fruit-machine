project(fruit-machine-library)

set(fm_SOURCES
    include/player.h
    include/print.h
    include/payout.h
    include/slotmachine.h
    src/player.cpp
    src/print.cpp
    src/payout.cpp
    src/slotmachine.cpp
)

add_library(${PROJECT_NAME} STATIC
    ${fm_SOURCES}
)

target_include_directories(fruit-machine-library
    PUBLIC include
)
