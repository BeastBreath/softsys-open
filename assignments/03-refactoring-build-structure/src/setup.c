#include "setup.h"

const char EMPTY_SPACE = ' ';
const char X_SPACE = 'X';
const char O_SPACE = 'O';

const char INPUT_PROMPT[] =
    "Enter the row and column number of your desired move:\n"
    "+---+---+---+\n"
    "|0 0|0 1|0 2|\n"
    "+---+---+---+\n"
    "|1 0|1 1|1 2|\n"
    "+---+---+---+\n"
    "|2 0|2 1|2 2|\n"
    "+---+---+---+";

void setup_board(tic_tac_toe_board* board) {
  for (int row = 0; row < BOARD_DIM; ++row) {
    for (int col = 0; col < BOARD_DIM; ++col) {
      board->spaces[row][col] = EMPTY_SPACE;
    }
  }
}

void setup_state(tic_tac_toe_state* state, tic_tac_toe_board* board) {
  setup_board(board);
  state->board = board;
  state->current_turn = X_SPACE;
  state->num_moves = 0;
}
