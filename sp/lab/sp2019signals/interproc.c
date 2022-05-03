#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>


int main()
{
	pid_t pid;
	printf("Program pokrenut!\n");
	int status;
	pid = fork();
	switch(pid) {
		case -1:
			/* Greska */
			perror("fork failed");
			exit(1);
		case 0:
			/* child */
			printf("Child proces nesto radi\n");

			pause();
			printf("Ovo se ne bi trebalo ispisati\n");
			exit(0);
	}
	/* parent */
	printf("Parent proces nesto radi\n");
	sleep(3);
	kill(pid, SIGKILL);
	wait(&status);
	printf("Zavrseno.\n");
	exit(0);
}
