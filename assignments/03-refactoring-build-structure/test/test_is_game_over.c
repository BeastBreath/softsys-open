#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <stdio.h>

#include "../src/constants.h"
#include "../src/setup.h"
#include "../src/move.h"
#include "../src/is_game_over.h"

// The player opposite X should be O.
Test(get_opposing_player, x_to_o) {
  cr_assert(eq(chr, get_opposing_player(X_SPACE), O_SPACE));
}

// The player opposite O should be X.
Test(get_opposing_player, o_to_x) {
  cr_assert(eq(chr, get_opposing_player(O_SPACE), X_SPACE));
}

// An empty board should not be considered full.
Test(is_full, empty_board_not_full) {
  tic_tac_toe_board board;
  setup_board(&board);
  cr_assert(zero(int, is_full(&board)));
}

// A partially filled board should not be considered full.
Test(is_full, partial_board_not_full) {
  tic_tac_toe_board board;
  setup_board(&board);
  board.spaces[0][0] = O_SPACE;
  board.spaces[1][1] = X_SPACE;
  cr_assert(zero(int, is_full(&board)));
}

// A full board should be considered full.
Test(is_full, full_board) {
  tic_tac_toe_board board;
  setup_board(&board);
  for (int i = 0; i < BOARD_DIM; ++i) {
    for (int j = 0; j < BOARD_DIM; ++j) {
      board.spaces[i][j] = X_SPACE;
    }
  }
  cr_assert(eq(int, is_full(&board), 1));
}

// Check a no-win case.
Test(is_win, no_win_empty) {
  tic_tac_toe_board board;
  setup_board(&board);
  cr_assert(zero(int, is_win(&board, X_SPACE)));
}

// A full, but drawn game is not considered a win.
Test(is_win, no_win_draw) {
  tic_tac_toe_board board;
  board.spaces[0][0] = X_SPACE;
  board.spaces[0][1] = X_SPACE;
  board.spaces[0][2] = O_SPACE;
  board.spaces[1][0] = O_SPACE;
  board.spaces[1][1] = X_SPACE;
  board.spaces[1][2] = X_SPACE;
  board.spaces[2][0] = X_SPACE;
  board.spaces[2][1] = O_SPACE;
  board.spaces[2][2] = O_SPACE;
  cr_assert(zero(int, is_win(&board, X_SPACE)));
}

// A row win is considered a win.
Test(is_win, row_win) {
  tic_tac_toe_board board;
  setup_board(&board);
  for (int col = 0; col < BOARD_DIM; ++col) {
    board.spaces[0][col] = X_SPACE;
  }
  cr_assert(eq(int, is_win(&board, X_SPACE), 1));
}

// A column win is considered a win.
Test(is_win, col_win) {
  tic_tac_toe_board board;
  setup_board(&board);
  for (int row = 0; row < BOARD_DIM; ++row) {
    board.spaces[row][0] = X_SPACE;
  }
  cr_assert(eq(int, is_win(&board, X_SPACE), 1));
}

// A diagonal win is considered a win.
Test(is_win, diag_win) {
  tic_tac_toe_board board;
  setup_board(&board);
  for (int index = 0; index < BOARD_DIM; ++index) {
    board.spaces[index][index] = X_SPACE;
  }
  cr_assert(eq(int, is_win(&board, X_SPACE), 1));
}


// In an empty board, neither player is winning.
Test(player_win, new_state_no_win) {
  tic_tac_toe_state state;
  tic_tac_toe_board board;
  setup_state(&state, &board);
  cr_assert(zero(int, player_win(&state)));
  state.current_turn = O_SPACE;
  cr_assert(zero(int, player_win(&state)));
}

// If the current player is winning, the state shouldn't report a win.
Test(player_win, current_player_win) {
  tic_tac_toe_state state;
  tic_tac_toe_board board;
  setup_state(&state, &board);
  for (int col = 0; col < BOARD_DIM; ++col) {
    board.spaces[0][col] = X_SPACE;
  }
  cr_assert(zero(int, player_win(&state)));
}

// If the opposing player is winning, the state should report a win.
Test(player_win, opposing_player_win) {
  tic_tac_toe_state state;
  tic_tac_toe_board board;
  setup_state(&state, &board);
  for (int col = 0; col < BOARD_DIM; ++col) {
    board.spaces[0][col] = O_SPACE;
  }
  cr_assert(eq(int, player_win(&state), 1));
}

// A new game should not be over.
Test(game_over, new_game_not_over) {
  tic_tac_toe_state state;
  tic_tac_toe_board board;
  setup_state(&state, &board);
  cr_assert(zero(int, game_over(&state)));
}

// The game should be over when the board is full.
Test(game_over, board_full) {
  tic_tac_toe_state state;
  tic_tac_toe_board board;
  setup_state(&state, &board);
  board.spaces[0][0] = X_SPACE;
  board.spaces[0][1] = X_SPACE;
  board.spaces[0][2] = O_SPACE;
  board.spaces[1][0] = O_SPACE;
  board.spaces[1][1] = X_SPACE;
  board.spaces[1][2] = X_SPACE;
  board.spaces[2][0] = X_SPACE;
  board.spaces[2][1] = O_SPACE;
  board.spaces[2][2] = O_SPACE;
  cr_assert(eq(int, game_over(&state), 1));
}

// The game should be over when a player has won.
Test(game_over, player_won) {
  tic_tac_toe_state state;
  tic_tac_toe_board board;
  setup_state(&state, &board);
  for (int col = 0; col < BOARD_DIM; ++col) {
    board.spaces[0][col] = O_SPACE;
  }
  cr_assert(eq(int, game_over(&state), 1));
}
