#include <stdio.h>
#include <stdlib.h>

#include "lib/commands/command_handler.h"
#include "lib/commands/lexer/lexer.h"

int main() {
	char cur_command[1024];
	char *cur_dir;
	char *cur_user;
	char *cur_machine;
	char *sudo_rights;
	int sudo;

	sudo_rights = ">";
	sudo = 0;

	while (1) {
		printf("%s@%s: %s %s ", cur_user, cur_machine, cur_machine, sudo_rights);
		scanf("%s", cur_command);
		handle_command(cur_user, cur_machine, cur_dir, sudo_rights, sudo, cur_command);
	}

	return 0;
}
