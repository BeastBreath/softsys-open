#include "is_game_over.h"

char get_opposing_player(char player) {
  return (char)(player == X_SPACE ? O_SPACE : X_SPACE);
}

int is_full(const tic_tac_toe_board* board) {
  for (int row = 0; row < BOARD_DIM; ++row) {
    for (int col = 0; col < BOARD_DIM; ++col) {
      if (board->spaces[row][col] == EMPTY_SPACE) {
        return 0;
      }
    }
  }
  return 1;
}

// Check if a player has won by filling a row of a board.
static int is_row_win(const tic_tac_toe_board* board, char player) {
  for (int row = 0; row < BOARD_DIM; ++row) {
    int row_win = 1;
    for (int col = 0; col < BOARD_DIM; ++col) {
      if (board->spaces[row][col] != player) {
        row_win = 0;
      }
    }
    if (row_win == 1) {
      return 1;
    }
  }
  return 0;
}

// Check if a player has won by filling a column of a board.
static int is_col_win(const tic_tac_toe_board* board, char player) {
  for (int col = 0; col < BOARD_DIM; ++col) {
    int col_win = 1;
    for (int row = 0; row < BOARD_DIM; ++row) {
      if (board->spaces[row][col] != player) {
        col_win = 0;
      }
    }
    if (col_win == 1) {
      return 1;
    }
  }
  return 0;
}

// Check if a player has won by filling a diagonal of a board.
static int is_diag_win(const tic_tac_toe_board* board, char player) {
  int trace_win = 1;
  for (int index = 0; index < BOARD_DIM; ++index) {
    if (board->spaces[index][index] != player) {
      trace_win = 0;
    }
  }
  int cross_win = 1;
  for (int index = 0; index < BOARD_DIM; ++index) {
    if (board->spaces[index][BOARD_DIM - index] != player) {
      cross_win = 0;
    }
  }
  return trace_win || cross_win;
}

int is_win(const tic_tac_toe_board* board, char player) {
  return is_row_win(board, player) || is_col_win(board, player) ||
         is_diag_win(board, player);
}

int player_win(const tic_tac_toe_state* state) {
  // Checking for a win looks at the player who last moved. Since after a
  // successful move the current player switches, the opposing one is the one
  // who last moved.
  return is_win(state->board, get_opposing_player(state->current_turn));
}

int game_over(const tic_tac_toe_state* state) {
  return is_full(state->board) || is_win(state->board, X_SPACE) ||
         is_win(state->board, O_SPACE);
}
