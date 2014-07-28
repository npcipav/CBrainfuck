# make


C = cc
F = -c --std=c99 -Os -Wall

rm = rm -f


################################################################

all: cbf


cbf: \
 brainfuck.o \
 settings.o \
 runner.o \
 log.o \
 stack.o \

	$(C) brainfuck.o settings.o runner.o log.o stack.o -o cbf


brainfuck.o: \
 settings.h \
 runner.h \
 brainfuck.c \

	$(C) $(F) brainfuck.c -o brainfuck.o


settings.o: \
 settings.h \
 settings.c \

	$(C) $(F) settings.c -o settings.o


runner.o: \
 stack.h \
 runner.h \
 runner.c \

	$(C) $(F) runner.c -o runner.o


log.o: \
 log.h \
 log.c \

	$(C) $(F) log.c -o log.o


stack.o: \
 stack.h \
 stack.c \

	$(C) $(F) stack.c -o stack.o


##########################################################################


stack_test: \
 stack.o \
 log.o \
 stack.h \
 log.h \
 stack_test.c \

	$(C) $(F) stack_test.c -o stack_test.o
	$(C) stack_test.o stack.o log.o -o stack_test


##########################################################################


clean:
	$(rm) *.o cbf
