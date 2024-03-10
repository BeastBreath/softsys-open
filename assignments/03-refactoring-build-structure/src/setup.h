#pragma once

#include "constants.h"

/**
 * Set up an empty tic-tac-toe board.
 *
 * @param board A pointer to the board to be initialized.
 */
void setup_board(tic_tac_toe_board* board);

/**
 * Set up an initial game state for tic-tac-toe.
 *
 * Given a state and board instance to set up, initialize the board and make the
 * state use the board. Also set up the remainder of the state to make a new
 * game.
 *
 * @param state The game state instance to initialize.
 * @param board The board instance to initialize.
 */
void setup_state(tic_tac_toe_state* state, tic_tac_toe_board* board);
