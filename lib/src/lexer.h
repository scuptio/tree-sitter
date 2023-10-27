#ifndef TREE_SITTER_LEXER_H_
#define TREE_SITTER_LEXER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "./length.h"
#include "./subtree.h"
#include "tree_sitter/api.h"
#include "tree_sitter/parser.h"

typedef struct {
  TSLexer data;
  Length current_position;
  Length token_start_position;
  Length token_end_position;

  TSRange *included_ranges;
  const char *chunk;
  TSInput input;
  TSLogger logger;

  uint64_t included_range_count;
  uint64_t current_included_range_index;
  uint64_t chunk_start;
  uint64_t chunk_size;
  uint64_t lookahead_size;
  bool did_get_column;

  char debug_buffer[TREE_SITTER_SERIALIZATION_BUFFER_SIZE];
} Lexer;

void ts_lexer_init(Lexer *);
void ts_lexer_delete(Lexer *);
void ts_lexer_set_input(Lexer *, TSInput);
void ts_lexer_reset(Lexer *, Length);
void ts_lexer_start(Lexer *);
void ts_lexer_finish(Lexer *, uint64_t *);
void ts_lexer_advance_to_end(Lexer *);
void ts_lexer_mark_end(Lexer *);
bool ts_lexer_set_included_ranges(Lexer *self, const TSRange *ranges, uint64_t count);
TSRange *ts_lexer_included_ranges(const Lexer *self, uint64_t *count);

#ifdef __cplusplus
}
#endif

#endif  // TREE_SITTER_LEXER_H_
