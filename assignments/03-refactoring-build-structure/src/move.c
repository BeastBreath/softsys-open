#include "move.h"

/**
 * Read the remainder of an input line and discard it.
 *
 * In some instances, a line of input read by the user is too long and the
 * unused portion needs to be flushed (discarded). The common call to
 * fflush(stdin) is not guaranteed to do this on all systems, so flush the input
 * by reading it to a buffer until a newline is encountered and do nothing with
 * it.
 */
static void flush_input_line(void) {
  // Create a dummy buffer that we won't do anything with, then repeatedly read
  // out of stdin until a newline shows up.
  char null_buffer[INPUT_BUFFER_SIZE];
  do {
    (void)fgets(null_buffer, sizeof(null_buffer), stdin);
  } while (strchr(null_buffer, '\n') == NULL);
}

int get_user_input(board_space* space) {
  puts(INPUT_PROMPT);
  char input_buffer[INPUT_BUFFER_SIZE];
  (void)fgets(input_buffer, sizeof(input_buffer), stdin);
  // If the input was too large, the newline won't be in the buffer. We already
  // know the input is invalid at this point, so stop processing.
  if (strchr(input_buffer, '\n') == NULL) {
    // Clear the rest of the input line from stdin so it doesn't affect future
    // calls.
    flush_input_line();
    return 0;
  }
  char* read_pos = input_buffer;
  space->row = (int)strtol(input_buffer, &read_pos, DECIMAL_BASE);
  // If the function did not read exactly one digit, then we already know the
  // input is invalid, so stop now.
  if (read_pos != input_buffer + 1) {
    return 0;
  }
  space->col = (int)strtol(read_pos, &read_pos, DECIMAL_BASE);
  return 1;
}

int is_valid_space(board_space space) {
  return space.row >= 0 && space.row < BOARD_DIM && space.col >= 0 &&
         space.col < BOARD_DIM;
}

int is_empty_space(const tic_tac_toe_board* board, board_space space) {
  return board->spaces[space.row][space.col] == EMPTY_SPACE;
}

void print_board(const tic_tac_toe_board* board) {
  const char* row_divider = "+-+-+-+";
  for (int row = 0; row < BOARD_DIM; ++row) {
    printf("%s\n", row_divider);
    for (int col = 0; col < BOARD_DIM; ++col) {
      printf("|%c", board->spaces[row][col]);
    }
    printf("|\n");
  }
  printf("%s\n", row_divider);
}

/** Switch the current player to the opposing player. */
static void next_move(tic_tac_toe_state* state) {
  if (state->current_turn == X_SPACE) {
    state->current_turn = O_SPACE;
  } else {
    state->current_turn = X_SPACE;
  }
}

int move(tic_tac_toe_state* state, board_space space) {
  if (!is_valid_space(space) || !is_empty_space(state->board, space)) {
    return 0;
  }
  state->board->spaces[space.row][space.col] = state->current_turn;
  next_move(state);
  ++(state->num_moves);
  return 1;
}
