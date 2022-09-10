#include<stdio.h> 
void quick_sort(int a[100],int low,int high) 
{     
int i,j,temp,key;
     if(low<high)
     {  key=a[low];  i=low;  j=high;   
    //Partition the array into two parts
	while(i<=j)
	{
	while(key>=a[i])
	i++;
	while(key<a[j])
	j--;
	if(i<j)
	{   
	temp=a[i];
	a[i]=a[j];
    a[j]=temp;
	}
	}     //partition completed  
   temp=a[low];
   a[low]=a[j];
   a[j]=temp;  
   //Consider j as mid and cal recursive function.  
   quick_sort(a,low,j-1);
   quick_sort(a,j+1,high);  
    }
}
	//Main Function
void main()
	{     
	int i,n,a[100];
	printf("Enter the value for n\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);                                              
    quick_sort(a,0,n-1);
	printf("The sorted array is\n");
	for(i=0;i<n;i++)
	printf("%d\n",a[i]);
}  