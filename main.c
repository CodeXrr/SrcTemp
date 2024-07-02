//------------=[ main.c ]=------------->
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include "validate_file_type.h"
#include "write_banner.h"
#include "write_includes.h"

void print_usage(char *app_name); 

int main(int argc, char *argv[]) {
	int f_enable = 0, n_enable = 0, o_present = 0, option=0, opt_code=0; 
	char *filename_opt; 
	int skip_writing_header = 0; // In the case we are templating a header file. 
	while((option = getopt(argc, argv, "fno:")) != -1) {
		switch(option) {
			case 'f':
				printf("-f option set!\n");
				f_enable = 1;
				break; 
			case 'n':
				printf("-n option set\n"); 
				n_enable = 1; 
				break; 
			case 'o':
				filename_opt = optarg; 
				printf("-o option set: %s\n", filename_opt); 
				o_present = 1; 
				break; 
			default: print_usage(argv[0]); 
		}
	}
	if (o_present == 0) {
		printf("[!!] Filename Argument Required\n"); 
		print_usage(argv[0]); 
	}
	if ( f_enable == 1) 
		opt_code = 1; 
	if ( n_enable == 1) 	
		opt_code = 2; 

	// C FILE VALIDATION 
	int file_type = validate_file_type(filename_opt); 
	if(file_type == -1) {
		printf("[!!] \'%s\' Invalid File Type [.c/.h]\n", filename_opt); 
		print_usage(argv[0]); 
		exit(-1); 
	}
	if(file_type == -2) {
		printf("[!!] File Name TOO long (must be less then 32 characters)\n"); 
		print_usage(argv[0]); 
		exit(-1);
	}
	if(file_type == 2) {
		skip_writing_header = 1; 
		printf("[*] VALIDATED FILE: \'%s\' (header file)\n", filename_opt); 
		printf("[*] SKIP_WRITING_HEADER = %d (flag-set)\n", skip_writing_header); 
	}
	if(file_type == 1) {
		printf("[*] VALIDATED FILE: \'%s\' (C file)\n", filename_opt); 
	}; 
	
	// See if file already exist. 
	if(file_exist(filename_opt)) {
		printf("[!!] \'%s\' (Already Exist! Aborting to prevent overwriting.)\n", filename_opt); 
		exit(0); 
	}
	//====================================================---------|| 
	// (THIS WOULD BE A LOWKEY SICK LOADBAR. 
	//Preliminary Objectives Completed- Time to start writing shit!
	
	int fd; 
	fd = open(filename_opt, O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR); 
	if (fd == -1) {
		printf("[!!] ERROR: Opening/Creating New File\n"); 
		exit(-1); 
	}
	write_banner(fd, filename_opt); 
	write_headers(fd, opt_code);
	close(fd); 
		
}




		





void print_usage(char *app_name) { 
	printf("Usage: %s [-o output-file] [-fn (file-headers)/(network-headers)]\n", app_name); 
	exit(0); 
}



