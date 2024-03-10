#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define useful constants needed in the program.
enum {
  /** Dimensions of the tic-tac-toe board. */
  BOARD_DIM = 3,
  /** Number of characters to read from user input. */
  INPUT_BUFFER_SIZE = 5,
  /** Used in strtol to convert user input to decimal ints. */
  DECIMAL_BASE = 10,
};

// C17 doesn't allow char enums, so declare the spaces/players as constants
// instead.
extern const char EMPTY_SPACE;
extern const char X_SPACE;
extern const char O_SPACE;

/** Prompt message shown when getting user input. */
extern const char INPUT_PROMPT[];

/**
 * A pair of integers representing a coordinate on a tic-tac-toe board.
 */
typedef struct {
  int row;
  int col;
} board_space;

/**
 * A tic-tac-toe board, represented by a 2-D array of characters.
 */
typedef struct {
  char spaces[BOARD_DIM][BOARD_DIM];
} tic_tac_toe_board;

/**
 * The state of a tic-tac-toe game, including current board, whose turn it is,
 * and how many moves have been made so far.
 */
typedef struct {
  tic_tac_toe_board* board;
  size_t num_moves;
  char current_turn;
} tic_tac_toe_state;
