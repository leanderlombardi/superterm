#include <stdlib.h>
#include <string.h>

#include "lexer.h"

lexer *lexer_create(const char *input) {
	lexer *tlexer = (lexer *)malloc(sizeof(lexer));
	tlexer->input = strdup(input);
	tlexer->position = 0;

	return tlexer;
}

void lexer_destroy(lexer *lexer) {
	free(lexer->input);
	free(lexer);
}

static int is_whitespace(char c) {
	return c == ' ' || c == '\t' || c == '\n';
}

token lexer_next_token(lexer *tlexer) {
	token ttoken;
	ttoken.value = NULL;

	if (tlexer->input[tlexer->position] == '\0') {
		return ttoken; // End of input
	}

	while (is_whitespace(tlexer->input[tlexer->position])) {
		tlexer->position++;
	}
	
	if (tlexer->input[tlexer->position] == '"') { // Handle quotes
		tlexer->position++;
		char *start = tlexer->input + tlexer->position;
		while (tlexer->input[tlexer->position] != '"' && tlexer->input[tlexer->position] != '\0') {
			tlexer->position++;	
		}

		if (tlexer->input[tlexer->position] == '"') {
			tlexer->position++;
		}

		ttoken.value = start;
	} else { // Handle non-quotes
		char *start = tlexer->input + tlexer->position;
		while (!is_whitespace(tlexer->input[tlexer->position]) && tlexer->input[tlexer->position] != '\0') {
			tlexer->position++;
		}

		ttoken.value = start;
	}

	return ttoken;
}

