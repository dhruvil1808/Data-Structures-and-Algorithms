#include<stdio.h>
#include<limits.h>
#define V 7
 
struct dijkstra
{
    int dist,p,visited;
}graph[V];
 
void init(int s)
{
    for(int i=0;i<V;i++)
    {
       graph[i].dist=INT_MAX;
       graph[i].p=-1;
       graph[i].visited=0;
    }
    graph[s].dist=0;
}

void relax(int u, int v, int w) 
{
   if (graph[v].dist>(graph[u].dist + w)) 
   {
       graph[v].dist = graph[u].dist + w;
       graph[v].p = u; 
    }
}

int findMin()
{
    int k=0;
    int min=INT_MAX,i;
    for(i=0;i<V;i++)
    {
        if(graph[i].visited==0)
        {
            if(min>graph[i].dist)
            {
                min=graph[i].dist;
                k=i;
            }
        }
    }
    return k;
}

void dijkstraFun(int G[V][V], int s, int n) 
{
init(s); 
int i=0;
for(int i=0;i<V;i++)
{
    int k=findMin();
    graph[k].visited=1;
    for(int j=0;j<V;j++)
      if(G[k][j]!=0)
        relax(k,j,G[k][j]);
    
}
}


int main()
{    
    int G[V][V]={{0,4,3,0,0,0,0},{4,0,0,0,12,5,0},{3,0,0,7,10,0,0},{0,0,7,0,2,0,0},{0,12,10,2,0,0,5},{0,5,0,0,0,0,16},{0,0,0,0,5,16,0}};

  int s;
  printf("enter the sourse node: ");
  scanf("%d",&s);
    dijkstraFun(G,s,V);

    for(int i=0;i<V;i++)
    {
        printf("dist: %d   parent: %d   visited: %d\n",graph[i].dist,graph[i].p,graph[i].visited);
    }
}