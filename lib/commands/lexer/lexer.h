typedef struct {
	char *value;
} token;

typedef struct {
	char *input;
	int position;
} lexer;

lexer *lexer_create(const char *input);
void lexer_destroy(lexer *lexer);
token lexer_next_token(lexer *tlexer);

