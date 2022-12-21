################################################################################
# [Oct..2.2022.17:45:16]                                                       #
#                                   Stardust                                   #
#                                                                              #
#                                         Wednesday 21 December 2022, 05:51:38 #
################################################################################

##### GROUPS ###################################################################

FG00=\
	Stardust.o


##### BUILD ####################################################################

ALL: $(FG00)
	gcc -mconsole -s -o Stardust.EXE $(FG00) -lstdc++ -lkernel32 -user32 -lgdi32 -lcomctl32 -lcomdlg32 -lws2_32

Stardust.EXE: $(FG00)
	gcc -mconsole -s -o Stardust.EXE $(FG00) -lstdc++ -lkernel32 -user32 -lgdi32 -lcomctl32 -lcomdlg32 -lws2_32


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

Stardust.o: ..\Stardust.c
	gcc -c -I "C:\MinGW\Include" -o Stardust.o ..\Stardust.c



##### CLEAN ####################################################################

CLEAN:
	-@erase "Stardust.o"
	-@erase "Stardust.EXE"

