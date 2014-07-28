// settings.c
#include "settings.h"
#include "log.h"

#include <stdio.h>
#include <stdlib.h>



static char* sourceFile;



static void showUsage()
{
	printf(
"Второй и единственный аргумент - имя исполняемого файла!\n"
	);
}


void setSetups(int argc, char** argv)
{
	if(argc != 2) {
		showUsage();
		exit(1);
	}

	sourceFile = argv[1];
}


char* getSorceFile()
{
	return sourceFile;
}
