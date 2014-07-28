// settings.h

/*
 * Сохранение глобальных настроек программы.
 */

#ifndef SETTINGS_H
#define SETTINGS_H

#include <stdio.h>


#define COMPILE 0x01
#define INTERPR 0x10



void  setSetups(int argc, char** argv);
char* getSorceFile();



#endif

