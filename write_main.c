//--------=[  write_main.c ]=------>
//--| Writes blank main(). 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <unistd.h> 


// Define Main Execution Banner.
char *main_exe_banner = "//---=[ START | Main Execution ]=--------->\n";

// Define main() string..
#define MAIN_ARR_SZ 1 
char *main_str = "int main(int argc, char *argv[])"
		    "{\n\n"
		    "\treturn 0;\n"
		    "};\n"; 

// Writes Main Exe. Banner as well as Main() skelton. 
// ====================================================================|
int write_main(int fd) {
	// Add Some space between HEADER and main function. 
	if(write(fd, "\n\n", 2) == 0) {
		printf("[!!] Error: Writing File\n");
		exit(-1); 
	}
	// Write Main Exe Banner (divider to show where execution starts)
	if(write(fd, main_exe_banner, strlen(main_exe_banner)) == 0) {
		printf("[!!] Error: Writing to file\n"); 
		exit(-1); 
	}
	if(write(fd, main_str, strlen(main_str)) == 0) {
		printf("[!!] Error: Writing to file\n");
		exit(-1);
	}
};




//=------=[ write_main-UNIT.c | UNIT EXE ]=-------------> 
/*int main(void) {
	int fd; 

	fd = open(TEST_F, O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR); 
	if(fd == -1) { 
		printf("[!!] ERROR: Opening|Creating File: %s\n", TEST_F);
	       	exit(-1); 	
	}
	printf("%s\n", main_exe_banner); 
	for(int i = 0; i < MAIN_ARR_SZ; i++) {
		printf("LOOP ITERATION: %d\n", i); 
		printf("%s\n", main_str[i]);
	}
	

	if(write(fd, main_exe_banner, strlen(main_exe_banner)) == 0) {
		printf("[!!] ERROR: Writing to \'%s\'\n", TEST_F); 
		exit(-1); 
	}
	if(write(fd, main_str, strlen(main_str)) == 0) {
		printf("[!!] Error: writing to \'%s\'\n", TEST_F); 
		exit(-1); 
	}



	close(fd); 
}
*/
