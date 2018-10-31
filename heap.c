#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

 node* create_node(){

  node* komvos;
  komvos= malloc(sizeof(node));
  komvos->phone= malloc(20*sizeof(char));
  komvos->poso= malloc(10*sizeof(char));
  komvos->right= NULL;
  komvos->left= NULL;

  return komvos;

}



max_heap create_heap(){

  max_heap heap_1;
  heap_1= malloc(sizeof(struct heap));
  heap_1->size=0;
  heap_1->root=NULL;

  return heap_1;
}



void swap_nodes(node* n1,node* n2){

	node* temp_node;
	temp_node=create_node();
    strcpy(temp_node->poso,n1->poso);
    strcpy(temp_node->phone,n1->phone);
    temp_node->right=n1->right;
    temp_node->left=n1->left;
   
    strcpy(n1->phone,n2->phone);
    strcpy(n1->poso,n2->poso);
    //n1->right=n2->right;
    //n1->left=n2->left;
   
    strcpy(n2->phone,temp_node->phone);
    strcpy(n2->poso,temp_node->poso);
    //n2->right=temp_node->right;
    //n2->left=temp_node->left;

}



void heapify(max_heap heap){

	int current_node,i,count=0;
	node* temp;
	current_node=heap->size;
	char* array[9];
	for(i=0;i<9;i++)
		array[i]=malloc(6*sizeof(char));



	while (current_node >1){

		if(current_node%2==1){
			//printf("Eisagwgh sta dexia!!\n");
			strcpy(array[count],"right");
			count++;
		}else if(current_node%2==0){
			//printf("Eisagwgh sta aristera!!\n");
			strcpy(array[count],"left");
			count++;
		}

		current_node=floor(current_node/2);

	}

	count=count-1;
	temp=heap->root;
	 while(1){

       if(!strcmp(array[count],"right")){

       	   if(temp->right!=NULL){
       	   	   if(strcmp(temp->right->poso,temp->poso)>0){
       	   	   	  
       	   	   	   swap_nodes(temp,temp->right);
       	   	   	       	   	   	   
       	   	   }

    	      temp=temp->right;
    	   }
       }else if(!strcmp(array[count],"left")){

       	   if(temp->left!=NULL){
       	   	  
       	   	   if(strcmp(temp->left->poso,temp->poso)>0){
                   
       	   	   	   swap_nodes(temp,temp->left);

       	   	   	    	   	   	       	   	   	
       	   	   }
       	   	   temp=temp->left;
       	   	}   
       	   	   
       }else{
    	   printf("error\n");
       }
       if(count==0)
       	break;
       count--;
    }

    temp=heap->root;

    if(temp->left!=NULL){
       if(strcmp(temp->left->poso,temp->poso)>0)
         	   swap_nodes(temp,temp->left); 
     }

     
    if(temp->right!=NULL){
       if(strcmp(temp->right->poso,temp->poso)>0)
              swap_nodes(temp,temp->right);
    
   }
}

void insert_heap(max_heap heap,node* nd){

	int current_node,i,count=0;
	node* temp,*new_node;
	char* array[9];
	for(i=0;i<9;i++)
		array[i]=malloc(6*sizeof(char));

	current_node=heap->size;

	if (heap->root==NULL){
		printf("Root insert\n");
		heap->root=create_node();
		strcpy(heap->root->phone,nd->phone);
		strcpy(heap->root->poso,nd->poso);
		heap->root->right=NULL;
		heap->root->left=NULL;
		heap->size++;
		return;
	}
	printf("Lets put node in the Heap\n");

	current_node++;

	while (current_node >1){

		if(current_node%2==1){
			printf("Eisagwgh sta dexia!!\n");
			strcpy(array[count],"right");
			count++;
		}else if(current_node%2==0){
			printf("Eisagwgh sta aristera!!\n");
			strcpy(array[count],"left");
			count++;
		}

		current_node=floor(current_node/2);

	}
	count=count-1;
    temp=heap->root;
    while(1){

       if(!strcmp(array[count],"right")){

       	   if(temp->right!=NULL){
    	       temp=temp->right;
    	   }else if(temp->right==NULL){
    	   		new_node=create_node();
    	   	    strcpy(new_node->phone,nd->phone);
    	   	    strcpy(new_node->poso,nd->poso);
    	   	    new_node->right=NULL;
    	   	    new_node->left=NULL;

    	   	    temp->right=new_node;

    	   	    heap->size++;
    	   	    break;
    	   }
       }else if(!strcmp(array[count],"left")){

       	   if(temp->left!=NULL){
    	      temp=temp->left;
    	   }else if(temp->left==NULL){
    	   	  new_node=create_node();
    	   	  strcpy(new_node->phone,nd->phone);
    	   	  strcpy(new_node->poso,nd->poso);
    	   	  new_node->right=NULL;
    	   	  new_node->left=NULL;

    	   	  temp->left=new_node;
    	   	  heap->size++;
    	   	  break;

    	   }
       }else{
    	   printf("error\n");
       }
       if(count==0)
       	break;
       count--;
    }
    heapify(heap);
   
}


void print_all_heap(max_heap heap){

	if(heap->root==NULL)
		return;

    printf("Node with phone: %s and poso:%s \n",heap->root->phone,heap->root->poso);

	if(heap->root->left!=NULL){
		printf("Left node with phone: %s and poso:%s \n",heap->root->left->phone,heap->root->left->poso);
	}

	if(heap->root->right!=NULL){
		printf("Right node with phone: %s and poso:%s \n",heap->root->right->phone,heap->root->right->poso);

	}
}


void print_k_elements(max_heap heap,int k){


}

