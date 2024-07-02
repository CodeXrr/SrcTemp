#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h> 

#define STD_HEADER_LEN 4
char *std_headers[] = {"#include <stdio.h>\n", 		// 0
	 	        "#include <string.h>\n",	// 1 
			"#include <stdlib.h>\n",	// 2 
			"#include <errno.h>\n",		// 3
			"#include <unistd.h>\n"};	// 4

#define FILE_HEADER_LEN 1
char *file_headers[] = {"#include <fcntl.h>\n",		// 0
			"#include <sys/stat.h>\n"};	// 1

#define NET_HEADER_LEN 2
char *net_headers[] = {"#include <netinet/in.h>\n", 	// 0
		       "#include <sys/socket.h>\n",	// 1
		       "#include <arpa/inet.h>\n"};	// 2 

int write_headers(int fd, int options) {
	// OPT: 0 - STD_HEADERS ONLY
	// OPT: 1 - ADD FILE HEADERS
	// OPT: 2 - ALL
	
	// Write the STD_HEADERS 
	for (int i=0; i < STD_HEADER_LEN; i++) {
		if(write(fd, std_headers[i], strlen(std_headers[i])) == 0) {
			printf("[!!] Error: Writing \'%s\' to file\n", std_headers[i]); 
			exit(-1); 
		}
	}
	if(options == 0)
		return 0;

	// If option is set to just 1 add the file
	// headers.  
	if(options <= 2) {
		for (int i=0; i < FILE_HEADER_LEN; i++) {
			if(write(fd, file_headers[i], strlen(file_headers[i])) == 0) { 
			       printf("[!!] Error: Writing \'%s\' to file\n", file_headers[i]); 	
			       exit(-1); 
			}
		}
	}
	if(options == 1)
		return 0; 
	else {
		for (int i=0; i < NET_HEADER_LEN; i++) { 
			if(write(fd, net_headers[i], strlen(net_headers[i])) == 0) {
				printf("[!!] Error: Writing \'%s\' to file\n", net_headers[i]); 
				exit(-1); 
			}
		}
	}

	return 0; 
}


	                                                                                                                                                                                                                                                                                 

