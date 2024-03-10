#pragma once

#include "constants.h"

/**
 * Get the opposing player's character (X to O, or O to X).
 *
 * @param The character representing the player ('X' or 'O').
 * @return The character of the opposing player.
 */
char get_opposing_player(char player);

/**
 * Check if every space on a tic-tac-toe board is full.
 *
 * @param board The board to check.
 * @return 1 if every space on board is full and 0 otherwise.
 */
int is_full(const tic_tac_toe_board* board);

/**
 * Check if a player has won on a board.
 *
 * A player is considered to have won on a board if they have three of their
 * character in a row.
 *
 * @param board The board to check.
 * @param player The character representing the player to check (X or O).
 * @return 1 if player has won on board and 0 otherwise.
 */
int is_win(const tic_tac_toe_board* board, char player);

/**
 * Check if the opposing player has won a game of tic-tac-toe.
 *
 * Given a game state instance, determine if the opposing player (i.e., not the
 * current player) has won the game. The opposing player is checked because each
 * time a move is made, the current player is switched, so the winner is
 * typically the player who last moved (i.e., the one opposite the current
 * player).
 *
 * @param state The game state to check.
 * @return 1 if the opposing player has won and 0 otherwise.
 */
int player_win(const tic_tac_toe_state* state);

/**
 * Check if a game of tic-tac-toe is over.
 *
 * A game is defined as being over if one player has won, or the board is full
 * (i.e., a draw). Given a game state, check whether the game is over.
 *
 * @param state The game state to check.
 * @return 1 if the game is over and 0 otherwise.
 */
int game_over(const tic_tac_toe_state* state);
