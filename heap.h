#ifndef _HEAP_
#define _HEAP_

typedef struct node{

   char* phone;
   char* poso;
   struct node* right;
   struct node* left;
}node;


struct heap{

  int size;
  node* root;
};

typedef struct heap* max_heap;


/*SYNARTHSEIS*/

node* create_node();
max_heap create_heap();
void swap_nodes(node* n1,node* n2);
void heapify(max_heap heap);
void insert_heap(max_heap heap,node* nd);
void print_all_heap(max_heap heap);
void delete_node(node *nd);
void delete_heap(max_heap heap);
void print_k_elements(max_heap heap,int k);


#endif