#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "lexer/lexer.h"
#include "command_handler.h"

int handle_command(char *current_user, char *current_machine, char *current_dir, char *sudo_rights, int sudo, char *command) {
	if (sizeof(current_user) > MAX_USER_LENGTH) {
		fprintf(stderr, "Error 1: sizeof(<argument>) is bigger than maximum\n");
		return 1;
	}

	if (sizeof(current_machine) > MAX_MACHINE_LENGTH) {
		fprintf(stderr, "Error 1: sizeof(<argument>) is bigger than maximum\n");
		return 1;
	}

	if (sizeof(current_dir) > MAX_DIR_LENGTH) {
		fprintf(stderr, "Error 1: sizeof(<argument>) is bigger than maximum\n");
		return 1;
	}

	if (sizeof(command) > MAX_COMMAND_LENGTH) {
		fprintf(stderr, "Error 1: sizeof(<argument>) is bigger than maximum\n");
		return 1;
	}
	
	lexer *tlexer;
	tlexer = lexer_create(command);
	token ttoken;
	while ((ttoken = lexer_next_token(tlexer)).value != NULL) {
		printf("Token: %s\n", ttoken.value);
	}

	lexer_destroy(tlexer);

	return 0;
}

