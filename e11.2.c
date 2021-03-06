#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int pthread_create(pthread_t *restrict tidp, const pthread_attr_t *restrict attr, void *(*start_rtn)(void *), void *restrict arg);

pthread_t ntid;

void printids(const char *s){
	pid_t pid;
	pthread_t tid;
	pid = getpid();
	tid = pthread_self();
	printf("%s pid %lu tid %lu (0x%lx)\n", s, (unsigned long)pid, (unsigned long)tid, (unsigned long)tid);
}

void *thr_fn(void *arg){
	printids("new thread: ");
	return ((void *)0);
}

int main(void){
	int err;
	err = pthread_create(&ntid, NULL, thr_fn, NULL);
	if (err != 0){
		printf("can't create thread");
		exit(1);
	}
	printids("main thread:");
	sleep(1);
	exit(0);
}
