#include<stdio.h>
#include<pthread.h>
#include<math.h>
#define maxn 100


struct bt
{
	int n;
	int c[maxn];
	int d[maxn];
	int sum;
	int max;
	int nnt;
	int nt[maxn];
	int tbc;
	char *b;
};

void* ctc1( void* h);
void* ctc2( void* h);
void* ctc3( void* h);
void* ctc4( void* h);
int nt(int n);

int main(int a,char* b[])
{
	struct bt data;
	data.n=0; data.sum=0;data.nnt=0;
	int t;
	data.b=b[2];
	if(a!=3)
	{
		printf("sai so luong tham so\n");
		return 1;
	}

	FILE *f= fopen(b[1],"rt");	
	if(f==NULL)
	{
		printf("khong tim thay thu muc\n");
		return 2;
	}

	while(fscanf(f,"%d",&t)!=EOF)
	{
		data.c[data.n]=t;
		data.d[data.n]=data.c[data.n];
		data.n++;
	}	

pthread_t p[4];
pthread_create(&p[0],NULL,ctc1,&data);
pthread_create(&p[1],NULL,ctc2,&data);
pthread_create(&p[2],NULL,ctc3,&data);
pthread_join(p[1],NULL);
pthread_join(p[0],NULL);
pthread_join(p[2],NULL);

pthread_create(&p[3],NULL,ctc4,&data);
pthread_join(p[3],NULL);

fclose(f);
}

void* ctc1( void* h)
{
	struct bt *t=(struct bt *)h;
	
	for(int i=0;i<t->n;i++)
	{
		t-> sum=t-> sum+t-> c[i];
	}
	t->tbc=t->sum/t->n;
}

void* ctc2( void* h)
{
	struct bt *t=(struct bt *)h;
 for(int i=0;i<(t->n)-1;i++)
  for(int j=i+1;j<(t->n);j++)
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
	for(int i=0;i<(t -> n);i++)
	{
		if(nt(t->c[i])==3)
		{
			
			t->nt[t->nnt]=t->c[i];
			t->nnt++;
		}
	}
}

void* ctc4( void* h)
{
	
	struct bt *t=(struct bt *)h;
	FILE *r= fopen(t->b,"wt");
	fprintf(r, "trung binh cong: %d\n", t->tbc);
	fprintf(r, "so tang dan:\n");
	for(int i=0;i<t->n;i++)
		fprintf(r, "%d  ",t->d[i] );
	fprintf(r, "\ncac so nt: ");
	for(int i=0;i<t->nnt;i++)
		fprintf(r,"%d  ",t->nt[i]);
	fprintf(r, "\n" );
}

int nt(int n)
{
	if(n<2) return 1;
	float k=sqrt(n);
	for(int i=2;i<=k;i++)
	if(n%i==0) return 2;
	return 3;
}
