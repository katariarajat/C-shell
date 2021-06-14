all:
	gcc -g -w prompt.c main.c current_dir.c processstring.c cd.c pwd.c	listfiles.c echo.c execvp.c history.c -o shell
main.o: main.c
	gcc -c main.c
current_dir.o: current_dir.c
	gcc -c current_dir.c
prompt.o: prompt.c
	gcc -c prompt.c
	

