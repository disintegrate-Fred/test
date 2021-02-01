#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void){
	char buf[4000];
	pid_t pid;
	int status;
	printf("%% ");
	while (fgets(buf, 4000, stdin) != NULL){
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0;
		if ((pid = fork()) < 0){
			printf("fork error");
			exit(1);
		}else if (pid == 0){
			execlp(buf, buf, (char*)0);
			printf("couldn't execute: %s", buf);
			exit(127);
		}
		if ((pid = waitpid(pid, &status, 0)) < 0){
			printf("waitpid error");
			exit(1);
		}
		printf("%% ");
	}
	exit(0);
}
