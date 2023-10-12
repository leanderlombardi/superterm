#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

	return 0;
}

