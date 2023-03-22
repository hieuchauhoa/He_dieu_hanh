#include <stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>
#include<unistd.h>
#include <sys/time.h>






int main(int a,char* b[])
{
	if(a!=2)
	{
		printf("sai so luong tham so\n");
		return 1;
	}
	if(atof(b[1])-atoi(b[1])!=0)
	{
		printf("nhap lai so\n");
		return 2;
	}
	pid_t pid=fork();
	struct timeval start, end;

		 gettimeofday(&start,NULL);
	int n=atoi(b[1]);
	

	if(pid>0)
	{
		
		wait(NULL);
		 gettimeofday(&end,NULL);
		 float seconds  = end.tv_sec  - start.tv_sec;
   		 float useconds = end.tv_usec - start.tv_usec;

    	float mtime = ((seconds) * 1000000 + useconds/1000000.0) ;

   		printf("         thoi gian chay: %f giay\n", mtime);

	}

	if(pid==0)
	{
	  int max=n;
	  printf("%d",n );
	  while(n>1)
	   {
		if(n%2==0)
		{
			n=n/2;
			printf(",%d",n );
			if(n>max)
			{
				max=n;
			}

		}
		else
		{
			n=3*n+1;
			printf(",%d",n );
			if(n>max)
			{
				max=n;
			}
		}
	   }
	   printf("    Max %d\n",max );
	}
}