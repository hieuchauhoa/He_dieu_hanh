#include <stdio.h>
#include<stdlib.h>


int tim(int n,int k);


int main(int a,char* b[]){
if(a!=4){
	printf("sai so luong tham so\n");
	return 1;
}
if(atoi(b[1])<0||atoi(b[1])>9||atof(b[1])-atoi(b[1])!=0){
	printf("sai tham so thu 1\n");
	return 2;
}
FILE *k=fopen(b[3],"wt");
FILE *f=fopen(b[2],"rt");
if(f==NULL){
	printf("khong tim thay thu muc\n");
	return 3;
}


int h,cout=0;
while(fscanf(f,"%d",&h)!=EOF)
{    
	if(tim(h,atoi(b[1]))!=0)
	{
		fprintf(k,"(%d)\n",h );
	}	
}

	fclose(f);
	fclose(k);
}	
int tim(int n,int k)
{
	while(n>0)
	{
		if(n%10==k) 
		{
			return 0;
		}
		n=n/10;
	}
	return 9;
}