#include <stdio.h>

int partiton(int n,int arr[],int lb,int ub)
{
    int st=lb,end=ub,pivot=arr[lb];

    while(st<end)
    {
        while(st<=ub && arr[st]<=pivot)
            st++;

        while(arr[end]>pivot)
            end--;

        if(st<end)
        {
            int temp=arr[st];
            arr[st]=arr[end];
            arr[end]=temp;
        }
    }

    int temp=arr[lb];
    arr[lb]=arr[end];
    arr[end]=temp;

    return end;
}

void quicksort(int n,int arr[],int lb,int ub)
{
    if(lb<ub)
    {
        int loc=partiton(n,arr,lb,ub);

        quicksort(n,arr,lb,loc-1);
        quicksort(n,arr,loc+1,ub);
    }
}

int main()
{
   int n;

   printf("enter an integer n (0 ≤ n ≤ 10^4), representing the number of songs in the library\n");

   scanf("%d",&n);

   int lb=0,ub=n-1;
   int arr[n];

   printf("enter the ID numbers of each song,Each song ID is a positive integer within the range [1, 10^6]\n");

   for(int i=0;i<n;i++)
       scanf("%d",&arr[i]);

   quicksort(n,arr,lb,ub);

   for(int i=0;i<n;i++)
       printf("%d ",arr[i]);

   return 0;
}
