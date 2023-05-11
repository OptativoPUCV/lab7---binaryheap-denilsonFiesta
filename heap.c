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
    return NULL;
}



void heap_push(Heap* pq, void* data, int priority){

}


void heap_pop(Heap* pq){

  return (*(pq->heapArray)).data;
  
}

Heap* createHeap(){

  Heap* new = calloc(1, sizeof(Heap));

  new->size = 0;
  new->capac = 3;
  new->heapArray = calloc(3, sizeof(heapElem) );
  return new;
}
