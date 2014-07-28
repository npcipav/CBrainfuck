// runner.c
#include "runner.h"
#include "stack.h"
#include "settings.h"
#include "log.h"

#include <stdio.h>
#include <stdlib.h>


#define CELLS_LENGHT 30000


char* cells;
int   cellPtr;
STACK loopPntsStack;
FILE* f;



void initRun(void)
{
	prLog("Running...");

	cells = (char*)calloc(CELLS_LENGHT, sizeof(char));
	loopPntsStack = new_Stack(); // Стек с метками цикла.

	f = fopen(getSorceFile(), "r");
	if(!f) {
		prLog("[!] Error: Sorce file error!");
		crash();
	} else
		prLog("File opened.");
}


void procCom(const char op)
{
	static char comPush;
	static char comPlus;

	static int  comCount; // Количество обработанных команд.
	static int  skip;     // Пропуск тела цикла, если активная ячейка равна нулю.

	comCount++;

	if((op == '>' || op == '<') && skip == 0) {
		if(op == '>')
			comPush++;
		if(op == '<')
			comPush--;
	} else if(comPush != 0) {
		if(cellPtr + comPush < CELLS_LENGHT && cellPtr + comPush >= 0)
			cellPtr += comPush;
	else {
		prLog("Cells ended!\n");
			crash();
		}
		comPush = 0;
	}

	if((op == '+' || op == '-') && skip == 0) {
		if(op == '+')
			comPlus++;
		if(op == '-')
			comPlus--;
	} else if(comPlus != 0) {
		cells[cellPtr] += comPlus;
		comPlus = 0;
	}

	if(op == '[') {
		if(cells[cellPtr] != 0 && skip == 0)
			push_Stack(loopPntsStack, ftell(f) - 1);
		else
			skip++;
	}

	if(op == ']') {
		if(skip == 0) {
			if(!isEmpty_Stack(loopPntsStack))
				fseek(f, pop_Stack(loopPntsStack), SEEK_SET);
			else {
				prLog("[!] Error: Invalide loops: Missid the beginning of the loop!");
				printf("%d\n", comCount);
				crash();
			}
		} else
			skip--;
	}

	if((op == ',') && skip == 0)
		scanf("%c", cells + cellPtr);

	if((op == '.') && skip == 0)
		printf("%c\n", cells[cellPtr]);
}


void run()
{
	initRun();

	while(!feof(f))
		procCom(fgetc(f));

	printf("\n");

	fclose(f);

	if(!isEmpty_Stack(loopPntsStack))
		prLog("[!] Warning: Invalide loops: Expected the ending of the loop!\n");

	delete_Stack(loopPntsStack);
}

