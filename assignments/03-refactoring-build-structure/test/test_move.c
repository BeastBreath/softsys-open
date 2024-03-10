#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <stdio.h>

#include "../src/constants.h"
#include "../src/setup.h"
#include "../src/move.h"
#include "../src/is_game_over.h"

// Reading a valid input should indicate success.
Test(get_user_input, valid_input_success) {
  FILE* stdin_file = cr_get_redirected_stdin();
  (void)fprintf(stdin_file, "0 0\n");
  (void)fclose(stdin_file);
  board_space space;
  cr_assert(eq(int, get_user_input(&space), 1));
}

// Reading a valid input should correctly update the output space.
Test(get_user_input, valid_input_update_space) {
  FILE* stdin_file = cr_get_redirected_stdin();
  (void)fprintf(stdin_file, "1 2\n");
  (void)fclose(stdin_file);
  board_space space;
  (void)get_user_input(&space);
  cr_assert(eq(int, space.row, 1));
  cr_assert(eq(int, space.col, 2));
}

// Reading a valid, but too long input (due to trailing characters) should
// indicate failure.
Test(get_user_input, too_long_input_failure) {
  FILE* stdin_file = cr_get_redirected_stdin();
  (void)fprintf(stdin_file, "0 0 \n");
  (void)fclose(stdin_file);
  board_space space;
  cr_assert(zero(int, get_user_input(&space), 0));
}

// Reading an input that is too long should indicate failure.
Test(get_user_input, way_too_long_input_failure) {
  FILE* stdin_file = cr_get_redirected_stdin();
  (void)fprintf(stdin_file, "1111111111111111 0\n");
  (void)fclose(stdin_file);
  board_space space;
  cr_assert(zero(int, get_user_input(&space), 0));
}

// Reading input that is not parseable as ints should indicate failure.
Test(get_user_input, invalid_input_failure) {
  FILE* stdin_file = cr_get_redirected_stdin();
  (void)fprintf(stdin_file, "x y\n");
  (void)fclose(stdin_file);
  board_space space;
  cr_assert(zero(int, get_user_input(&space), 0));
}

// The upper-left corner (row 0, column 0) should always be in the board.
Test(is_valid_space, ul_corner) {
  board_space space = {0, 0};
  cr_assert(eq(int, is_valid_space(space), 1));
}

// The upper-right corner should always be in the board.
Test(is_valid_space, ur_corner) {
  board_space space = {0, BOARD_DIM - 1};
  cr_assert(eq(int, is_valid_space(space), 1));
}

// The lower-left corner should always be in the board.
Test(is_valid_space, ll_corner) {
  board_space space = {BOARD_DIM - 1, 0};
  cr_assert(eq(int, is_valid_space(space), 1));
}

// The lower-right corner should always be in the board.
Test(is_valid_space, lr_corner) {
  board_space space = {BOARD_DIM - 1, BOARD_DIM - 1};
  cr_assert(eq(int, is_valid_space(space), 1));
}

// A coordinate off the left side of the board (negative column) should not be
// in the board.
Test(is_valid_space, too_far_left) {
  board_space space = {0, -1};
  cr_assert(zero(int, is_valid_space(space)));
}

// A coordinate off the right side of the board (column is BOARD_DIM) should not
// be in the board.
Test(is_valid_space, too_far_right) {
  board_space space = {0, BOARD_DIM};
  cr_assert(zero(int, is_valid_space(space)));
}

// A coordinate off the upper side of the board (negative row) should not be
// in the board.
Test(is_valid_space, too_far_up) {
  board_space space = {-1, 0};
  cr_assert(zero(int, is_valid_space(space)));
}

// A coordinate off the bottom side of the board (row is BOARD_DIM) should not
// be in the board.
Test(is_valid_space, too_far_down) {
  board_space space = {BOARD_DIM, 0};
  cr_assert(zero(int, is_valid_space(space)));
}

// is_empty_space should report a new board's spaces as all empty.
Test(is_empty_space, new_board) {
  tic_tac_toe_board board;
  setup_board(&board);
  for (int i = 0; i < BOARD_DIM; ++i) {
    for (int j = 0; j < BOARD_DIM; ++j) {
      board_space space = {i, j};
      cr_assert(eq(int, is_empty_space(&board, space), 1));
    }
  }
}

// is_empty_space should report a space occupied by X as not empty.
Test(is_empty_space, x_not_empty) {
  tic_tac_toe_board board;
  setup_board(&board);
  board.spaces[0][0] = X_SPACE;
  board_space space = {0, 0};
  cr_assert(eq(int, is_empty_space(&board, space), 0));
}

// is_empty_space should report a space occupied by O as not empty.
Test(is_empty_space, o_not_empty) {
  tic_tac_toe_board board;
  setup_board(&board);
  board.spaces[0][0] = O_SPACE;
  board_space space = {0, 0};
  cr_assert(eq(int, is_empty_space(&board, space), 0));
}

// Check that an empty board prints correctly.
Test(print_board, empty_board, .init = cr_redirect_stdout) {
  tic_tac_toe_board board;
  setup_board(&board);
  print_board(&board);
  (void)fflush(stdout);
  (void)fclose(stdout);
  cr_assert_stdout_eq_str(
      "+-+-+-+\n"
      "| | | |\n"
      "+-+-+-+\n"
      "| | | |\n"
      "+-+-+-+\n"
      "| | | |\n"
      "+-+-+-+\n");
}

// Check that an X move prints correctly.
Test(print_board, x_move, .init = cr_redirect_stdout) {
  tic_tac_toe_board board;
  setup_board(&board);
  board.spaces[0][0] = X_SPACE;
  print_board(&board);
  (void)fflush(stdout);
  (void)fclose(stdout);
  cr_assert_stdout_eq_str(
      "+-+-+-+\n"
      "|X| | |\n"
      "+-+-+-+\n"
      "| | | |\n"
      "+-+-+-+\n"
      "| | | |\n"
      "+-+-+-+\n");
}

// Check that an O move prints correctly.
Test(print_board, o_move, .init = cr_redirect_stdout) {
  tic_tac_toe_board board;
  setup_board(&board);
  board.spaces[0][0] = O_SPACE;
  print_board(&board);
  (void)fflush(stdout);
  (void)fclose(stdout);
  cr_assert_stdout_eq_str(
      "+-+-+-+\n"
      "|O| | |\n"
      "+-+-+-+\n"
      "| | | |\n"
      "+-+-+-+\n"
      "| | | |\n"
      "+-+-+-+\n");
}

// A successful move should update that space on the board.
Test(move, update_board) {
  tic_tac_toe_state state;
  tic_tac_toe_board board;
  setup_state(&state, &board);
  board_space space = {0, 0};
  (void)move(&state, space);
  cr_assert(eq(chr, board.spaces[0][0], X_SPACE));
}

// A successful move should return 1 to indicate success.
Test(move, return_success) {
  tic_tac_toe_state state;
  tic_tac_toe_board board;
  setup_state(&state, &board);
  board_space space = {0, 0};
  cr_assert(eq(int, move(&state, space), 1));
}

// A move that fails due to being outside the board should indicate failure.
Test(move, invalid_space_failure) {
  tic_tac_toe_state state;
  tic_tac_toe_board board;
  setup_state(&state, &board);
  board_space space = {-1, 0};
  cr_assert(zero(int, move(&state, space)));
}

// A move that fails due to being outside the board should not change the board.
Test(move, invalid_space_unchanged) {
  tic_tac_toe_state state;
  tic_tac_toe_board board;
  setup_state(&state, &board);
  board_space space = {-1, 0};
  (void)move(&state, space);
  for (int i = 0; i < BOARD_DIM; ++i) {
    for (int j = 0; j < BOARD_DIM; ++j) {
      cr_assert(eq(chr, board.spaces[i][j], EMPTY_SPACE));
    }
  }
}

// A move that fails due to the space being full should indicate failure.
Test(move, space_full_failure) {
  tic_tac_toe_state state;
  tic_tac_toe_board board;
  setup_state(&state, &board);
  board_space space = {0, 0};
  (void)move(&state, space);
  cr_assert(zero(int, move(&state, space)));
}

// A move that fails due to the space being full should not change the space.
Test(move, space_full_unchanged) {
  tic_tac_toe_state state;
  tic_tac_toe_board board;
  setup_state(&state, &board);
  board_space space = {0, 0};
  (void)move(&state, space);
  (void)move(&state, space);
  cr_assert(eq(chr, board.spaces[0][0], X_SPACE));
}
