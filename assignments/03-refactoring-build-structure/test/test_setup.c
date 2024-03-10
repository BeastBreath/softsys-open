#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <stdio.h>

#include "../src/constants.h"
#include "../src/setup.h"
#include "../src/move.h"
#include "../src/is_game_over.h"

// A new board's spaces should all be empty.
Test(setup_board, new_board) {
  tic_tac_toe_board board;
  setup_board(&board);
  for (int i = 0; i < BOARD_DIM; ++i) {
    for (int j = 0; j < BOARD_DIM; ++j) {
      cr_assert(eq(chr, board.spaces[i][j], EMPTY_SPACE));
    }
  }
}

// Setting up a state should initialize the board.
Test(setup_state, setup_empty_board) {
  tic_tac_toe_board board;
  tic_tac_toe_state state;
  setup_state(&state, &board);
  for (int i = 0; i < BOARD_DIM; ++i) {
    for (int j = 0; j < BOARD_DIM; ++j) {
      cr_assert(eq(chr, board.spaces[i][j], EMPTY_SPACE));
    }
  }
}

// Setting up a state should set the number of moves to zero.
Test(setup_state, no_moves) {
  tic_tac_toe_board board;
  tic_tac_toe_state state;
  setup_state(&state, &board);
  cr_assert(zero(sz, state.num_moves));
}

// Setting up a state should have X going first.
Test(setup_state, x_starts) {
  tic_tac_toe_board board;
  tic_tac_toe_state state;
  setup_state(&state, &board);
  cr_assert(eq(chr, state.current_turn, X_SPACE));
}
