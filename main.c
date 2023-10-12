#include <stdio.h>
#include <stdlib.h>

int main() {
	char cur_command[1024];
	char cur_dir[1024];
	char cur_user[64];
	char cur_machine[64];
	char *sudo_rights;
	int sudo;

	sudo_rights = ">";
	sudo = 0;

	while (1) {
		printf("%s@%s: %s %s ", cur_user, cur_machine, cur_machine, sudo_rights);
		scanf("%s", cur_command);
		
	}
}
