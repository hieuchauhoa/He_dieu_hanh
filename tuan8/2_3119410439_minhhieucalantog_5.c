#include <stdio.h>
#include<pthread.h>
#include<stdlib.h>



long giaithua(int n);
void* ctc(void* arg);
void* ctc2(void* arg);


int main(int a,char* b[])
{
	if(a!=2)
			{
				printf("sai so luong phan tu \n");
				return 1;
			}
	
	int n=atoi(b[1]);
	int d=giaithua(n);
	if(atof(b[1])-atoi(b[1])!=0||atoi(b[1])<0)
		{
			printf("nhap lai so\n");
			return 2;
		}
	pthread_t t1,t2;
	pthread_create(&t1,NULL,ctc,&n);
	pthread_join (t1,NULL);
	pthread_create(&t2,NULL,ctc2,&d);	
	pthread_join (t2,NULL);
}


void* ctc(void* arg)
{
	int *r=(int * )arg;
	int s=1;
	while(*r>0)
	{
		s=s*(*r);

		*r=*r-1;
	}
	printf("Thread factorial: %d\n",s );
}

void* ctc2(void* arg)
{
	int *t=(int * )arg;
	int q=0;
	for(int i=1;i<=*t;i++)
	{
		q=q+i;
	}
	printf("Thread sum: %d\n",q );
}

long giaithua(int n)
{
	int s=1;
	while(n>0)
	{
		s=s*n;
		n--;
	}
	return s;

}



