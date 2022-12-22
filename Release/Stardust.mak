################################################################################
# [Oct..2.2022.17:45:16]                                                       #
#                                   Stardust                                   #
#                                                                              #
#                                          Thursday 22 December 2022, 10:26:22 #
################################################################################

##### GROUPS ###################################################################

FG00=\
	Stardust.o\
	dbg.o


##### BUILD ####################################################################

ALL: $(FG00)
	gcc -mwindows -s -o Stardust.EXE $(FG00) -lstdc++ -lkernel32 -user32 -lgdi32 -lcomctl32 -lcomdlg32 -lws2_32

Stardust.EXE: $(FG00)
	gcc -mwindows -s -o Stardust.EXE $(FG00) -lstdc++ -lkernel32 -user32 -lgdi32 -lcomctl32 -lcomdlg32 -lws2_32


##### COMMANDS #################################################################

run:  Stardust.EXE
	Stardust.EXE

debug:  Stardust.EXE
	gdb Stardust.EXE

peview:  Stardust.EXE
	uetools -pe Stardust.EXE

makef: 
	uestudio Stardust.mak


##### COMPILE ##################################################################

INC001=C:\Users\Seclor\Desktop\Stardust\Headers\dbg\dbg.h

Stardust.o: ..\Stardust.c $(INC001)
	gcc -c -I "C:\MinGW\Include" -o Stardust.o ..\Stardust.c


dbg.o: ..\Headers\dbg\dbg.c
	gcc -c -I "C:\MinGW\Include" -o dbg.o ..\Headers\dbg\dbg.c



##### CLEAN ####################################################################

CLEAN:
	-@erase "Stardust.o"
	-@erase "dbg.o"
	-@erase "Stardust.EXE"

