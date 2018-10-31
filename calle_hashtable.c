#include "calle_hashtable.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define second_bucket_size 256

#define max_second_bucket_records second_bucket_size/sizeof(second_record_2)

hash_table_2 create_hash_table_2(int size){
	int i;
	Buckets_2* table=malloc(size*sizeof(Buckets_2));
	if(table==NULL){
		printf("(hashtable2)Could not allocate memory!!!\n");
		//return ;
	}
	for (i=0;i<=size-1;i++)
	{
	       
 	 table[i]=create_buckets_2();

    }
    return table;
}



void clean_hash_table_2(hash_table_2 table,int size){
	int i;
	for (i=0;i<=size-1;i++)
	{
        
	 clean_buckets_2(table[i]);  
 	 
	}

	free(table);
}

int hash_function_2(char* key,int size){
	int hash_result=atoi(key);
	 hash_result=hash_result%size;
  return hash_result;
}

void print_all_hash_table_2(hash_table_2 table,int size){
   int i;
   for (i=0;i<=size-1;i++)
   {
	    print_all_from_bucket_2(table[i]);
   }
}

void dump_print_all_hash_table_2(hash_table_2 table,int size,FILE* out){
   int i;
   for (i=0;i<=size-1;i++)
   {
	    dump_print_all_from_bucket_2(table[i],out);
   }
}




bucket_record_2* search_hash_table_2(hash_table_2 table,char* caller,int size){

	int h=hash_function_2(caller,size);
	return search_bucket_2(table[h],caller);
}


void delete_record_hash_table_2(hash_table_2 table,int size,char* caller,char* id){
	int count=0;
	int i,h;
	bucket_record_2* rec_1;
	second_node_2* node_2;
	second_record_2* rec_2,*temp;
	rec_1=search_hash_table_2(table,caller,size);
	//printf("caller: %s  id: %s\n",caller,id);
	if (rec_1==NULL)
	{
	printf("(hashtable2)we dont have this caller \n");
	return;	
	}
	else
	{
		node_2=rec_1->deiktis->First_buc_2;
		if(node_2==NULL){
			printf("(hashtable2)First node in second bucket is NULL");
			return;
		}
		while(node_2!=NULL){
			rec_2=node_2->First_rec_2;
			while(rec_2!=NULL){
				count++;
				if(!strcmp(rec_2->rec->cdr_uniq_id_2,id)){
					printf("(hashtable2)Record with cdr_id %s found,lets delete it!!",id);
					rec_2=node_2->First_rec_2;
					//temp=rec_2;
					for(i=0;i<count-1;i++){
						rec_2=rec_2->next_rec_2;
					}
					if(count==1){
						node_2->number_of_records_2=0;
						temp=rec_2->next_rec_2;
						if(temp==NULL){
							printf("(hashtable2)Mono 1 eggrafi sto bucket,tha meinei keno!!!\n");
							free(rec_2);
							node_2->First_rec_2=NULL;
							return;
						}	
						temp->next_rec_2=rec_2->next_rec_2->next_rec_2;
						free(rec_2);
						node_2->First_rec_2=temp;
					}else if (count==max_second_bucket_records-1){
						temp=rec_2->next_rec_2;
						rec_2->next_rec_2=NULL;
						free(temp);
						node_2->number_of_records_2--;
					}else{
					   temp=rec_2->next_rec_2;
					   rec_2->next_rec_2=temp->next_rec_2;
					   free(temp);
					   node_2->number_of_records_2--;				
				    }   	
                }
                rec_2=rec_2->next_rec_2;
			}
			count=0;
			node_2=node_2->next_buc_2;
		}
   }
}


int insert_hash_table_2(hash_table_2 table,int size,record* rec,int bucket_size_){
	int h;
	second_record_2* r;
	rest_record_2* rest;
	rest=malloc(sizeof(struct rest_of_calle_record));
	r=create_second_record_2();
	bucket_record_2* eggrafi=search_hash_table_2(table,rec->destination_number,size);
	bucket_record_2* new_rec;
	if (eggrafi!=NULL)
	{
	

	strcpy(r->rec->cdr_uniq_id_2,rec->cdr_uniq_id);
	strcpy(r->rec->originator_number_2,rec->originator_number);
	strcpy(r->rec->date_2,rec->date);
	strcpy(r->rec->init_time_2,rec->init_time);
	r->rec->duration_2=rec->duration;
	r->rec->tarrif_2=rec->tarrif;
	r->rec->type_2=rec->type;
	strcpy(r->rec->fault_condition_2,rec->fault_condition);


    insert_to_end_second_2(eggrafi->deiktis,r);
		
	}else{

    h=hash_function_2(rec->originator_number,size);
    new_rec=create_record_2_new(rec);
    //printf("newrec: %s\n",new_rec->originator_number_1);
    insert_to_end_of_bucket_node_2(table[h],new_rec,bucket_size_); 
  
    
   
    
    strcpy(r->rec->cdr_uniq_id_2,rec->cdr_uniq_id);
	strcpy(r->rec->originator_number_2,rec->originator_number);
	strcpy(r->rec->date_2,rec->date);
	strcpy(r->rec->init_time_2,rec->init_time);
	r->rec->duration_2=rec->duration;
	r->rec->tarrif_2=rec->tarrif;
	r->rec->type_2=rec->type;
	strcpy(r->rec->fault_condition_2,rec->fault_condition);
	

	//printf("To second_record: %s %s %s %s %d %d %d %s\n",r->rec->cdr_uniq_id_1,r->rec->destination_number_1,r->rec->date_1,r->rec->init_time_1,r->rec->duration_1,r->rec->tarrif_1,r->rec->type_1,r->rec->fault_condition_1);
    

	insert_to_end_second_2(new_rec->deiktis,r);



    printf("(hashtable2)Record with id: %s was added successfully!!!\n",rec->cdr_uniq_id);
   }
    return 0;

}




