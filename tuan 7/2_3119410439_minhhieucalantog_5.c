#include <stdio.h>
#include<sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int tinh(int a,char b,int c);

int main(int a,char *b[])
{
		if(a!=2)
			{
				printf("chua nhap file\n");
				return 1;
			}

	pid_t p=fork();
	int status;

	if(p>0)
	{
		
		wait(&status);
		if(status!=0)
			{
				printf("child said: file not found!\n");
			}
		FILE *f=fopen(b[1],"rt");

		int h,sot1,sot2;
		char pt;

		while(!feof(f))
			{   
				fscanf(f,"%d %c %d",&sot1,&pt,&sot2) ;
				if(pt=='/') printf("%d %c %d = %f\n",sot1,pt,sot2,(sot1*1.0)/(sot2*1.0) );
				else printf("%d %c %d = %d\n",sot1,pt,sot2,tinh(sot1,pt,sot2));
			}
			fclose(f);

	}

	if(p==0)
	{
		FILE *f=fopen(b[1],"rt");
		if(f==NULL)
			{
				exit(1) ;
			}
		fclose(f);
	}


}
int tinh(int a,char b,int c)
{   
	int kq;
	
	if(b=='+') 
		{
			kq=a+c;
			return kq;
		}
	if(b=='-') 
		{
			kq=a-c;
			return kq;
		}
	if(b=='*') 
		{
			kq=a*c;
			return kq;
		}
	
}