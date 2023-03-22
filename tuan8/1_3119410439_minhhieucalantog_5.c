#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<pthread.h>

int n;
void* ctc(void* arg);
void* ctc2(void* arg);
int ngt(int s);

int n;
int main(int a,char *b[])
{   
	if(a!=2)
			{
				printf("sai so luong phan tu \n");
				return 1;
			}
	
	n=atoi(b[1]);
	if(atof(b[1])-atoi(b[1])!=0||atoi(b[1])<0)
		{
			printf("nhap lai so\n");
			return 2;
		}

	pthread_t t1,t2;
	pthread_create(&t1,NULL,ctc,&n);
	pthread_create(&t2,NULL,ctc2,&n);
	pthread_join (t1,NULL);
	pthread_join (t2,NULL);
}

int ngt(int s)
{
	if(s<2) return 3;
	float o =sqrt(s);
	for(int i=2;i<=o;i++)
		if(s%i==0) return 4;
	return 5;

}

void* ctc(void* arg)
{	
	int *t=(int *) arg ;
	FILE *f=fopen("thread.txt","wt");
	fprintf(f,"thread1: \n");
	for(int i=0;i<=*t;i++)
	{
		if(ngt(i)==5) 
			fprintf(f, "%d\n", i);
	}
	

}
void* ctc2(void* arg)
{
	int *p=(int *) arg ;
	FILE *f=fopen("thread.txt","at");
	fprintf(f,"thread2: \n");
	for(int i=0;i<=*p;i++)
	{
		if(i%5==0) 
			fprintf(f, "%d\n", i);

	}
	


}
