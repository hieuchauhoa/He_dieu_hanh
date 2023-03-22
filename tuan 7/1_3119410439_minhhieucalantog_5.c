#include <stdio.h>
#include<sys/wait.h>
#include <unistd.h>

int main()
{
	pid_t p1=fork();

	if(p1>0)
	{
		pid_t p2=fork();

		if(p2>0)
		{
			printf("Process A - PID=%d ; CPID=%d (D)\n",getpid(),p2 );
			wait(NULL);

		}

		if(p2==0)
		{
			printf("Process D - PID=%d ; PPID=%d (A)\n",getpid(),getppid() );

		}
		wait(NULL);

	}
	if(p1==0)
	{
		pid_t p3=fork();
		if(p3>0)
		{
			printf("Process B - PID=%d ; CPID=%d (C)\n",getpid(),p3 );
			wait(NULL);

		}

		if(p3==0)
		{
			printf("Process C - PID=%d ; PPID=%d (B)\n",getpid(),getppid() );

		}

	}
}