#define MAX_USER_LENGTH 64
#define MAX_MACHINE_LENGTH 64
#define MAX_DIR_LENGTH 1024
#define MAX_COMMAND_LENGTH 1024

int handle_command(char *current_user, char *current_machine, char *current_dir, char *sudo_rights, int sudo, char *command);
