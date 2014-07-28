// brainfuck.c

/*
 * Интерпритатор языка Brainfuk.
 *
 * Язык программирования: Си 99.
 */

#include "settings.h"
#include "runner.h"
#include "log.h"



int main(int argc, char** argv)
{
	prLog("\nProgram Started.");

	setSetups(argc, argv);
	run();

	prLog("Program Closed.\n");
}
