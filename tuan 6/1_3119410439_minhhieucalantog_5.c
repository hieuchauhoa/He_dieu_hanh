#include <stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>
#include<unistd.h>




int kiemtra(char c);

int main(int a,char* b[])
{
	if(a!=2)
	{
		printf("sai so luong tham so\n");
		return 1;
	}
	if(strlen(b[1]) <20) 
	{
		printf("sai so luong chu so\n");
		return 2;
	}


	char c[strlen(b[1])],d[strlen(b[1])];
	strcpy(c,b[1]);


	for(int i=0;i<strlen(b[1]);i++)
	{
		if(kiemtra(c[i]) ==4)
		{
			printf("nhap lai so\n");
			return 5;
		}
	}
	pid_t pid=fork();
	
	if(pid>0)
	{
		wait(NULL);
		FILE *f=fopen("out1.txt","rt");
		char s;
		int tong=0;
		while(fscanf(f,"%c",&s)!=EOF)
		{
			tong=tong+(s-48);

		}
		printf("%d\n", tong);
	fclose(f);

	}

	if(pid==0)
	{
			
		FILE *h=fopen("out1.txt","wt");

			for (int i=strlen(b[1])-1;i>=0;i--)
			{
				fprintf(h,"%c",c[i] );
				
			}
		
			
			
		fclose(h)	;
			
	}




}
int kiemtra(char c)
{
	if (c >= '0' && c <= '9')
    		return 3;
    	return 4;
}