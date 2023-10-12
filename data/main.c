#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	char *installdir;
	installdir = argv[1];
	FILE *main_c;
	main_c = fopen(installdir, "w");

	fprintf(main_c, "");
	
	fclose(main_c);
}
