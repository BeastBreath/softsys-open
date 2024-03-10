#pragma once

#include "constants.h"

/**
 * Get user input representing a pair of coordinates.
 *
 * Read a line of input from the user, generally expected to be a row and column
 * index separated by a space (e.g., "0 2"). Parse this input into a board_space
 * (pair of integers), with appropriate handling of inputs that are invalid or
 * too long. The parsed integers are placed into a premade board_space instance;
 * no new board_space is created. If the input is invalid or too long, the
 * contents of space are undefined.
 *
 * @param space The board_space instance to write the parsed ints into.
 * @return 1 if the input was successfully read and parsed and 0 otherwise.
 */
int get_user_input(board_space* space);

/**
 * Check that a set of coordinates is actually on the tic-tac-toe board.
 *
 * A space on the tic-tac-toe board is represented by a row and column index,
 * with each being 0 to 2 (inclusive) on a typical tic-tac-toe board.
 *
 * @param space A board_space (pair of ints) representing the coordinates.
 * @return 1 if space is on the board and 0 otherwise.
 */
int is_valid_space(board_space space);

/**
 * Check if a space on a tic-tac-toe board is empty.
 *
 * @param board The board to check.
 * @param space The board space (pair of ints) to check.
 * @return 1 if space on board is empty and 0 otherwise.
 */
int is_empty_space(const tic_tac_toe_board* board, board_space space);

/**
 * Print a text representation of the contents of a tic-tac-toe board.
 *
 * @param board The board to print.
 */
void print_board(const tic_tac_toe_board* board);

/**
 * Attempt to make a move in a tic-tac-toe game.
 *
 * Given a game state and a space, attempt to make a move by the current player
 * in that space in the game's board. The space can be invalid (e.g., outside
 * the board or already occupied), in which case the move will fail and the
 * board left unchanged. If the move is successful, the board will be changed
 * and the number of moves so far (kept in the game state) will be incremeneted.
 *
 * @param state The game state to make a move in.
 * @param space The space in the board to attempt the move in.
 * @return 1 if the move was successful and 0 otherwise.
 */
int move(tic_tac_toe_state* state, board_space space);
