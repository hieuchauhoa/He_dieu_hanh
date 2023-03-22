#include <stdio.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>





int main(int a,char* b[])
{
	char *s=strdup(b[1]);

	for(int i=2;i<a;i++)
		{
			
			strcat(s," ");
			strcat(s,b[i]);			
		}
int c[2];
pipe(c);
pid_t d=fork();
int status;

if(d>0) 
{
	write(c[1],&s,strlen(s));
	wait(NULL);
	char o[4];
	read(c[0],o,10);
	printf("max: %s\n",o);


}

if(d==0)
{
	char *t,*p,*l;
	int max=0;
	read(c[0],&t,strlen(s));
	l=strdup(t);
	for(int i=0;i<a-1;i++)
	{
		p=strtok(l," ");
		l=strtok(NULL,"\0");
		if(atoi(p)>max)
		{
		 	max=atoi(p);
		 	
		}
	}
char e[4];
sprintf(e,"%d",max);
	write(c[1],e,strlen(e));

}
}