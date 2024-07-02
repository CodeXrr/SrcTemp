//---------------=[ write_banner.c ]=-------------------->
// --| Functionality for writing a banner with user-input
// file name as displayed above. Keep It Simple Keep It Simple!
// ======================================================|
//
//-| Basic/Essential Includes |---->
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <errno.h> 
//-| File Based Header Functions |----------------------->
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include "write_includes.h"

#define BANNER_WIDTH 32
#define BANNER_MIDBRK (BANNER_WIDTH/2)

int write_banner(int fd, char *filename) {
	size_t max_banner_sz = strlen(filename) + BANNER_WIDTH + 2; // 2 (space for fname)
	char banner_buffer[max_banner_sz]; 

	// Comment Out Banner First of All!
	strcpy(banner_buffer, "//"); 

	int saved_index=2; 
	for (int i=2; i < BANNER_MIDBRK-2; i++) { 
		banner_buffer[i] = '-'; 
		saved_index++; 
	}
	banner_buffer[saved_index + 1] = '\0'; 
	
	strncat(banner_buffer, "=[ ", strlen(banner_buffer)); 
	strncat(banner_buffer, filename, strlen(banner_buffer)); 
	strncat(banner_buffer, " ]=", strlen(banner_buffer)); 

	saved_index = strlen(banner_buffer); 
	for (int i=saved_index; i < (max_banner_sz-2); i++) {
		banner_buffer[i] = '-'; 
		saved_index++; 
	}

	// ADD THE END CAP ARROW! 
	strncat(banner_buffer, "->\n", strlen(banner_buffer)); 

	if(write(fd, banner_buffer, strlen(banner_buffer)) == -1) {
		perror("[!!] Writing to file: "); 
		exit(-1); 
	}


	// [DEBUG/TEST] 
	printf("banner_buffer @ (%p)/%ld bytes\n%s\n", &banner_buffer, strlen(banner_buffer), banner_buffer); 
}

