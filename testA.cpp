#include <stdio.h>
#include <math.h>

int min=99999;

void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void printArray(int array[],int length)
{
	for(int i=0;i<length;i++)
		printf("%d ",array[i]);
	printf("\n");
}

int distance(int array[],int d[],int length)
{
	int ans=0;
	for(int i=0;i<length;i++)
	{
		ans+=pow(array[i]-d[i],2);
	}
	return ans;
}

void permute(int *array,int i,int length,int d[]) { 
  if (length == i){
  	int m;
  	 m=distance(array,d,length);
  	 if(m<min)
  	 	min=m;
     //printArray(array,length);
     return;
  }
  int j = i;
  for (j = i; j < length; j++) { 
     swap(array+i,array+j);
     permute(array,i+1,length,d);
     swap(array+i,array+j);
  }
  return;
}

int main()
{
	int array[101];
	int d[101];
	int n;
	int k;
	scanf("%d",&n);
	for(int j=0;j<n;j++)
	{
		min=99999;
		scanf("%d",&k);
		for(int i=0;i<k;i++)
			scanf("%d",&array[i]);
		if(k%2==0)
		for(int i=0;i<k/2;i++)
		{
			d[i]=i;
			d[k-i-1]=i;
		}
		else
		{
			for(int i=0;i<=k/2;i++)
			{
				d[i]=i;
				d[k-i-1]=i;
			}
		}
		permute(array,0,k,d);
		printf("Case #%d: %d\n",j+1,min);
	}
	return 0;
}