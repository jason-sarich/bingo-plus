add_executable(Bingo main.cpp
    pattern.cpp
    bingo.cpp
    card.cpp
    caller.cpp
    patternfactory.cpp
    simulator.cpp
    odds.cpp
    column.cpp)

set_target_properties(Bingo PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
