#include <stdio.h>
void bubblesort(int n,int arr[])
{
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1])
            {
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            }
    }
}
}
void selectionsort(int n,int arr[])
{
    for(int i=0;i<n;i++){
        int sidx=i;
        for(int j=i+1;j<n;j++){
            if(arr[sidx]>arr[j])
            sidx=j;
      }
    int temp=arr[i];
    arr[i]=arr[sidx];
    arr[sidx]=temp;
}
}
void insertionsort(int n,int arr[])
{
    for(int i=1;i<n;i++){
        int curr=arr[i];
        int prev=i-1;
       while(prev>=0&&arr[prev]>curr){
           arr[prev+1]=arr[prev];
           prev--;
       }
       arr[prev+1]=curr;
    }}
int main() {
   int n;
   scanf("%d",&n);
   int arr[n];
   for(int i=0;i<n;i++)
   {
       scanf("%d",&arr[i]);
   }
 bubblesort(n,arr);
 for(int i=0;i<n;i++)
   {
       printf("%d ",arr[i]);
   }
   printf("\n\n");
 selectionsort(n,arr);
for(int i=0;i<n;i++)
   {
       printf("%d ",arr[i]);
   }
    printf("\n\n");
   insertionsort(n,arr);
    for(int i=0;i<n;i++)
   {
       printf("%d ",arr[i]);
   }
    return 0;
}
