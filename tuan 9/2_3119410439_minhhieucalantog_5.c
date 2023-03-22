#include<stdio.h>
#include<pthread.h>
#define maxn 100000

struct bt
{
	int c[maxn];
	int d[maxn];
	int max;

};

void* ctc1( void* h);
void* ctc2( void* h);
void* ctc3( void* h);

int main(int a, char *b[])
{
	struct bt data;
	data.max=0;

	if(a!=2)
	{
		printf("sai so luong tham so\n");
		return 1;
	}

	int h; 

	FILE *f= fopen(b[1],"rt");	
	if(f==NULL)
	{
		printf("khong tim thay thu muc\n");
		return 2;
	}	

	for(int i=0;i<100000;i++)
	{
		fscanf(f,"%d",&h);
		data.c[i]=h;
		if(h>data.max) data.max=h;
	}

	for(int i=0;i<100000;i++)
	{
		fscanf(f,"%d",&h);
		data.d[i]=h;
		if(h>data.max) data.max=h;
	}

pthread_t p[3];
pthread_create(&p[0],NULL,ctc1,&data);
pthread_create(&p[1],NULL,ctc2,&data);

pthread_join(p[0],NULL);
pthread_join(p[1],NULL);

pthread_create(&p[2],NULL,ctc3,&data);
pthread_join(p[2],NULL);










fclose(f);
}

void* ctc1( void* h)
{
	struct bt *t=(struct bt *)h;
	for(int i=0;i<100000-1;i++)
 	 for(int j=i+1;j<100000;j++)
   		{
   		 if((t->c[i])>(t->c[j])) 
    		 {
       			int temp=t->c[i];
       			t->c[i]=t->c[j];
      			 t->c[j]=temp;
    		 }
  		 }
}

void* ctc2( void* h)
{
	struct bt *t=(struct bt *)h;
	for(int i=0;i<100000-1;i++)
 	 for(int j=i+1;j<100000;j++)
   		{
   		 if((t->d[i])>(t->d[j])) 
    		 {
       			int temp=t->d[i];
       			t->d[i]=t->d[j];
      			 t->d[j]=temp;
    		 }
  		 }
}

void* ctc3( void* h)
{
	struct bt *t=(struct bt *)h;
	int e=0,l=0;
	FILE *k= fopen("output.txt","wt");

	while(e<100000&&l<100000)
	{
		if((t->c[e])<(t->d[l]))
		{
			fprintf(k, "%d  ",t->c[e] );
			e++;	
		}

		if((t->c[e])>(t->d[l]))
		{
			fprintf(k, "%d  ",t->d[l] );
			l++;
		}
		if((t->c[e])==(t->d[l]))
		{
			fprintf(k, "%d  %d  ",t->d[l], t->c[e]);
			l++;
			e++;
		}
	}

	fprintf(k, "%d\n",t->max );

}