#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <math.h>
#include "time.h"

void getTime(struct tm **time_f)
{
time_t sec;
time(&sec);
*time_f = localtime(&sec);
}



int main()
{
struct tm *time;
getTime(&time);
int pid, status, died, i;
int count_of_process=pow(2, time->tm_hour);
for(i=0;i<count_of_process;i++)
{

	printf("\ni=%d\n", i);
	pid=fork();

	if(pid==0)
	{
		getTime(&time);
		sin(3.1415*(time->tm_min)/14); 
		exit(0);
	}
	else {
	printf("pid = %d\n", pid);
	if (pid==-1) printf("Error\n"); 
	if (pid&1)
	died=wait(&status);
	printf("Exit with %d status\n", died);
//printf("Process PID, PPID and status %d, %d, %d\n", getpid(), getppid(), died);
}

		
}


return 0;
}
