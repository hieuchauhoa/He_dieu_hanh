#include <stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>



int main(int a,char* b[])
{
	int c[2];
	pipe(c);
char e[30];

	pid_t d=fork();
	int status;

	if(d>0)
	{
		write(c[1],&b[1],strlen(b[1]));
		wait(&status);
		char *s;
		read(c[0],s,strlen(b[1])+status);
		printf("%s\n",s );

	}

	if(d==0)
	{
		char *s;
		char pt,kq2;
		int st1,st2,kq;
		read(c[0],&s,strlen(b[1]));
		for(int i=0;i<strlen(b[1]);i++)
		{
			if(s[i]=='+') pt='+';
			if(s[i]=='-') pt='-';
			if(s[i]=='*') pt='*';
			if(s[i]=='/') pt='/';
		}
		 st2= atoi(strrchr(s,pt)+1);
		 st1=atoi(strtok(s,"pt"));

		 if(pt=='+') kq=st1+st2;
		 if(pt=='-') kq=st1-st2;
		 if(pt=='*') kq=st1*st2;
		 if(pt=='/') kq=st1/st2;
		
		 int n=kq,dem=0;
		while(n>0)
		{
			n=n/10;
			dem++;
		}
		
		sprintf(e,"%d",kq);
		strcat(s,"=");
		strcat(s,e);
		write(c[1],s,strlen(b[1])+strlen(e));
		exit(strlen(e));
	}

}