#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <unistd.h> 

// Validates a valid C file and determines between a 
// implmentation file (.c) and header file (.h) 
// RETURN: (.c) 1 | (.h) 2 | IVALID FT (-1) | FILENAME TOO LONG (-2)
int validate_file_type(char *filename) { 
#define MAX_FILE_LEN 32
	if(strlen(filename) > 32)
		return -2; 

	// Find the Dot for ext
	if( (filename[(strlen(filename)-2)]) != '.' )
		return -1; 

	// Extract Extension to save on typing 
	char ext = filename[strlen(filename)-1]; 
	if (ext == 'c')
		return 1; 
	if (ext == 'h')
		return 2; 
	else
		return -1; 

}
int file_exist(char *filename) {
#define DOES_NOT 0
#define DOES 1
	int fd; 
	fd = open(filename, O_RDONLY); 
	if (fd == -1) {
		close(fd); 
		return DOES_NOT; 
	} else {
		close(fd); 
		return DOES; 
	}
}


	
