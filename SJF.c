#include<stdio.h>
int left(int i) 
{
return 2*i; 
}
int right(int i) 
{
return (2*i+1); 
}

void swap(int *a, int *b) 
{
int temp = *a; *a = *b;
*b = temp;
}

void minHeapify(int *a, int i, int n) 
{
int l, r, smallest;
l = left(i);
r = right(i);
if ((l<=n) && (a[i]>a[l])) smallest = l;
else
smallest = i;
if ((r<=n) && (a[smallest]>a[r])) smallest = r;
if (i != smallest) {
swap(&a[i], &a[smallest]);
minHeapify(a,smallest, n); }
}

void buildMinHeap(int *a,int n) 
{
int i;
for (i=n/2; i>=1; i--)
minHeapify(a,i,n);
}

int extractMin(int *a, int *n) 
{
int t = *n;
int min = a[1]; 
a[1] = a[t];
t = t - 1; 
minHeapify(a,1,t);
*n = t;
return min; 
}

void doSJF(int *a, int n) 
{
int wt[n-1]; int tt = 0; int t = n; int w[t]; wt[1] = 0; int j = 2;
for (int i=1; i<=t; i++) 
{
int k = extractMin(a,&n);
w[i] = k; 
}
printf("\n\n\t\t\t");
for (int j=1; j<=t; j++)
printf(" %d",w[j]);
wt[0] = 0;
for (int j=1; j<t; j++)
wt[j] = wt[j-1]+w[j];
double awt = 0;
printf("\n Waiting Time Values : "); 
for (int j=1; j<=t; j++)
{
printf(" %d",wt[j]);
awt += wt[j]; 
}
awt = awt/t;
printf("\n Avg. Waiting Time: %lf",awt); 
}


int main() 
{
int a[] = {0, 11, 21, 7, 4, 13, 9, 16, 2, 15, 10, 1}; int n = 11;
printf("\n Initial Array Values :");
for (int i=1; i<=n; i++) 
printf(" %d",a[i]);
buildMinHeap(a,n);
printf("\n Min Heap of given Values : "); 
for(int i=1; i<=n; i++)
printf(" %d",a[i]);
doSJF(a,n); 
}