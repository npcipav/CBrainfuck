// log.c
#include "log.h"

#include <stdio.h>
#include <stdlib.h>


#define LOG_FILE "LOG_FILE"



void prLog(char* msg)
{
	FILE* f = fopen(LOG_FILE, "at");
	if(!f) {
		printf("[!] Error: Opening log file failure!\n");
		exit(1);
	}

	fprintf(f, msg);
	fprintf(f, "\n");

	fclose(f);
}



void crash()
{
	printf("Program crashed!\n");
	printf("Please view log file.\n");
	exit(1);
}
