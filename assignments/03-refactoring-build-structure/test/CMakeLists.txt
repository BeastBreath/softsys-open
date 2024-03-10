# Some compilers warn that the return value of cr_assert gets converted from an
# int to a unsigned char:1. To avoid this error in those compilers, turn off
# conversion warnings for test code.
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-conversion")

# add_executable(test_tic_tac_toe test_tic_tac_toe.c)
add_executable(test_setup test_setup.c)
add_executable(test_move test_move.c)
add_executable(test_is_game_over test_is_game_over.c)

target_link_libraries(test_setup
  PRIVATE setup
  PUBLIC ${CRITERION}
)
target_link_libraries(test_move
  PRIVATE move
  PUBLIC ${CRITERION}
)
target_link_libraries(test_is_game_over
  PRIVATE is_game_over
  PUBLIC ${CRITERION}
)

add_test(
  NAME test_setup
  COMMAND test_setup ${CRITERION_FLAGS}
)
add_test(
  NAME test_move
  COMMAND test_move ${CRITERION_FLAGS}
)
add_test(
  NAME test_is_game_over
  COMMAND test_is_game_over ${CRITERION_FLAGS}
)


