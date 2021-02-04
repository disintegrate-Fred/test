all:e11.2 process shared
e11.2:e11.2.c
	gcc -o e11.2 e11.2.c -lpthread
process:process.c
	gcc -o process process.c
shared:shared.c
	gcc -o shared shared.c
