#include <stdio.h>

typedef struct node_tag node;
struct node_tag
{
node *pA, *pB;
int data;
};

/* too lazy to use rand() in a loop */
node Q[16] =
{
{ NULL, &Q[ 1], 37 },
{ &Q[ 0], &Q[ 2], 42 },
{ &Q[ 1], &Q[ 3], 55 },
{ &Q[ 2], &Q[ 4], 11 },
{ &Q[ 3], &Q[ 5], 12 },
{ &Q[ 4], &Q[ 6], 71 },
{ &Q[ 5], &Q[ 7], 34 },
{ &Q[ 6], &Q[ 8], 35 },
{ &Q[ 7], &Q[ 9], 16 },
{ &Q[ 8], &Q[10], 61 },
{ &Q[ 9], &Q[11], 36 },
{ &Q[10], &Q[12], 49 },
{ &Q[11], &Q[13], 48 },
{ &Q[12], &Q[14], 10 },
{ &Q[13], &Q[15], 32 },
{ &Q[14], NULL, 80 },
};
node *pHead = &Q[0];

void PrintNodes(void)
{
const node *p;

p = pHead;
do
{
if (p->pA == NULL)
printf(" ");
else
printf(" [%2d] -> ", p->pA->data);
printf("%2d", p->data);
if (p->pB == NULL)
printf("\n");
else
printf(" -> [%2d]\n", p->pB->data);
p = p->pB;
} while (p);
}

node *HeapSort(node *pList);
int main(void)
{
printf("Before:\n");
PrintNodes();

pHead = HeapSort(pHead);

printf("After:\n");
PrintNodes();

return 0;
}

node *HeapInsert(node *pHead, node *pNew)
{
if (pHead == NULL)
{
pNew->pA = pNew->pB = NULL;
return pNew;
}

if (pNew->data > pHead->data)
{
/* switch A/B to try to maintain balance */
pNew->pB = pHead->pA;
pNew->pA = HeapInsert(pHead->pB, pHead);
return pNew;
}
else
{
pHead->pA = HeapInsert(pHead->pA, pNew);
return pHead;
}
}

node *HeapRemove(node *pHead)
{
if (pHead == NULL)
return NULL;

if (pHead->pA == NULL)
return pHead->pB;
if (pHead->pB == NULL)
return pHead->pA;

if (pHead->pA->data > pHead->pB->data)
{
pHead->pA->pA = HeapRemove(pHead->pA);
pHead->pA->pB = pHead->pB;
return pHead->pA;
}
else
{
pHead->pB->pB = HeapRemove(pHead->pB);
pHead->pB->pA = pHead->pA;
return pHead->pB;
}
}

node *HeapSort(node *pList)
{
node *pIter = pList, *pNext, *pPrev;
node *pHead = NULL;
/* build heap */
while (pIter)
{
/* take one out of the list */
pNext = pIter->pB;
/* put it into the heap */
pHead = HeapInsert(pHead, pIter);
pIter = pNext;
}

/* tear down heap */
pPrev = NULL;
while (pHead)
{
/* take one out of the heap */
pIter = pHead;
pHead = HeapRemove(pHead);
/* put it into the list */
pIter->pA = pPrev;
if (pPrev == NULL)
pList = pIter;
else
pPrev->pB = pIter;
pPrev = pIter;
}
if (pIter)
pIter->pB = NULL;
return pList;
}