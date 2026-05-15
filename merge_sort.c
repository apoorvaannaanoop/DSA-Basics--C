#include <stdio.h>
void merge(int n,int arr[],int lb,int mid,int ub)
{
    int i=lb,j=mid+1,k=lb,brr[n];
    while(i<=mid&&j<=ub)
    {
        if(arr[i]<arr[j])
        {
            brr[k]=arr[i];
            i++;
        }
        else
        {
            brr[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=ub)
        {
            brr[k]=arr[j];
            j++,k++;
        }
    }
   if(j>ub)
   {
       while(i<=mid)
       {
           brr[k]=arr[i];
           i++,k++;
       }
   }
  for(k=lb;k<=ub;k++)
    arr[k]=brr[k];
}
void mergesort(int n,int arr[],int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergesort(n,arr,lb,mid);
        mergesort(n,arr,mid+1,ub);
        merge(n,arr,lb,mid,ub);
    }
}

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    int lb=0,ub=n-1;
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    mergesort(n,arr,lb,ub);
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
    return 0;
}
