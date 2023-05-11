#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;

//que se hace aca ???

void* heap_top(Heap* pq){

  if(!pq->size) return NULL;
  
  return (*(pq->heapArray)).data;
}

int parentN(int i){
  if(!i) return -1;
  return (i-1 / 2);
}

void arreglarArriba(Heap* pq, int i){
  
  int parent = parentN(i); 
  
  if(parent == -1) return;

  if( (*(pq->heapArray+i)).priority  <  (*(pq->heapArray+parent)).priority ){
    heapElem temp = (*(pq->heapArray+parent));
    (*(pq->heapArray+parent)) = (*(pq->heapArray+i));
    (*(pq->heapArray+i)) = temp;
    arreglarArriba(pq, parent);
  }
  
}


void heap_push(Heap* pq, void* data, int priority){

  if(pq->size == pq->capac){
    pq->capac = pq->capac*2 + 1; 
    pq->heapArray = realloc(pq->heapArray, pq->capac );
  }

  (*(pq->heapArray+pq->size)).priority = priority;
  (*(pq->heapArray+pq->size)).data = data;

  arreglarArriba(pq, pq->size);
  pq->size++;
  
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){

  Heap* new = calloc(1, sizeof(Heap));

  new->size = 0;
  new->capac = 3;
  new->heapArray = calloc(3, sizeof(heapElem) );
  return new;
}
