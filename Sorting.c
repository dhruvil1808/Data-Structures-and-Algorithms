#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)     
 
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
           {
               int temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
           }
}


void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
              min_idx = j;
               int temp=arr[min_idx];
               arr[min_idx]=arr[i];
               arr[i]=temp;
    }
}


void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp=arr[i];
               arr[i]=arr[j];
               arr[j]=temp;
            

        }
        for(int x=0;x<high-1;x++)
        printf(" %d ",arr[x]);
    }
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0;j = 0;k = l;
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}


 
int main()
{
   int lower = 0, upper;
    int arr[100000];
    srand(time(0));
    int n[]={1000,5000,10000,50000,100000};
    double time1[5]={0.0,0.0,0.0,0.0,0.0};
    double time2[5]={0.0,0.0,0.0,0.0,0.0};
    double time3[5]={0.0,0.0,0.0,0.0,0.0};
    double time4[5]={0.0,0.0,0.0,0.0,0.0};
    double time5[5]={0.0,0.0,0.0,0.0,0.0};
    for(int i=0;i<5;i++)
    {clock_t begin,end;
        upper=n[i];
       for (int j = 0; j < upper; j++) 
       {
        arr[j] = (rand() %(10000 - 0 + 1)) + 0;
        
       }
       begin=clock();
       bubbleSort(arr,n[i]);
       end=clock();
       time1[i]+=(double)(end-begin)/CLOCKS_PER_SEC;
       begin=clock();
       selectionSort(arr,n[i]);
       end=clock();
       time2[i]+=(double)(end-begin)/CLOCKS_PER_SEC;
       begin=clock();
       insertionSort(arr,n[i]);
        end=clock();
       time3[i]+=(double)(end-begin)/CLOCKS_PER_SEC;
        begin=clock();
       mergeSort(arr,0,n[i]-1);
        end=clock();
       time4[i]+=(double)(end-begin)/CLOCKS_PER_SEC;
        begin=clock();
       quickSort(arr,0,n[i]-1);
       end=clock();
       time5[i]+=(double)(end-begin)/CLOCKS_PER_SEC;
    }
    for(int i=0;i<5;i++)
    {
    printf("\n%f\t%f\t%f\t%f\t%f\n",time1[i],time2[i],time3[i],time4[i],time5[i]);
    }
    return 0;
}