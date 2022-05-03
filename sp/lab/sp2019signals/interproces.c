#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static int alarm_fired = 0;

void ding(int sig)
{
	alarm_fired = 1;
}

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
			//sleep(5);
			printf("Child proces nesto radi\n");

			kill(getppid(), SIGALRM);
			pause();
			printf("Ovo se ne bi trebalo ispisati\n");
			exit(0);
	}
	/* parent */
	printf("Parent proces nesto radi\n");
	signal(SIGALRM, ding);
	// pause();
	sleep(3);
	// kill(pid, SIGTERM);
	kill(pid, SIGKILL);
	wait(&status);
	if (alarm_fired) printf("Ding!\n");
	printf("Zavrseno.\n");
	exit(0);
}
