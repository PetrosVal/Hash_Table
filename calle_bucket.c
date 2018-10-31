#include <stdio.h>
#include <stdlib.h>
#include "calle_bucket.h"
#include <string.h>

#define second_bucket_size 256

#define max_second_bucket_records second_bucket_size/sizeof(second_record_2)

void swap_1(char** a,char** b)
{
	char* temp=*a;
	*a = *b;
	*b = temp;
}

void bubblesort_1(char* a[21][2])
{
	int i, c;
	do {
		c = 0;
		for (i = 1 ; i < 20 ; i++)
			if (strcmp(a[i][2],a[i-1][2])>0) {
				swap_1(&a[i][2], &a[i-1][2]);
				swap_1(&a[i][1], &a[i-1][1]);
				c = 1;
			}
	} while (c);
}

void reverse_string_3(char *str)
{
    if (str == 0)
    { 
        return;
    }
    if (*str == 0)
    {
        return;
    } 
    char *start = str;
    char *end = start + strlen(str) - 1; 
    char temp;
    while (end > start)
    {
        temp = *start;
        *start = *end;
        *end = temp;
        ++start;
        --end;
    }
}

bucket_record_2* create_record_2_new(record* r){
	bucket_record_2* eggrafi;
	char* destinator;
	destinator=malloc(20*sizeof(char));
	eggrafi=malloc(sizeof(struct bucket_record_2));
	strcpy(destinator,r->destination_number);
	eggrafi->destination_number_2=destinator;
    eggrafi->next_rec=NULL;
    eggrafi->deiktis=malloc(sizeof(struct second_buckets_of_nodes_2));
   
    return eggrafi;
 
}

bucket_record_2* create_record_2(void){
	bucket_record_2* eggrafi;
	char* destinator;
	destinator=malloc(20*sizeof(char));
	eggrafi=malloc(sizeof(struct bucket_record_2));
	strcpy(destinator," ");
	eggrafi->destination_number_2=destinator;
    eggrafi->next_rec=NULL;
    eggrafi->deiktis=malloc(sizeof(struct second_buckets_of_nodes_2));
   
    return eggrafi;
 
}

bucket_node_2* create_node_2(void){
	bucket_node_2* buc;
	buc=malloc(sizeof(struct bucket_node_2));
	buc->number_of_records=0;
	buc->First_rec=NULL;
	buc->next_buc=NULL;

	return buc;

}

Buckets_2 create_buckets_2(void){
	Buckets_2 b=malloc(sizeof(struct buckets_of_nodes_2));
	if(b==NULL){
		printf("(hashtable2)Could not allocate memory!!!\n");
		//return ;
	}
	b->number_of_buckets=0;
	b->First_buc=NULL;


	return b;

}


second_record_2* create_second_record_2(){
	second_record_2* eggrafi;
	eggrafi=malloc(sizeof(struct second_record_2));
	eggrafi->rec=malloc(sizeof( struct rest_of_calle_record));
	strcpy(eggrafi->rec->cdr_uniq_id_2," ");
	strcpy(eggrafi->rec-> originator_number_2," ");
	strcpy(eggrafi->rec->date_2," ");
	strcpy(eggrafi->rec->init_time_2," ");
	strcpy(eggrafi->rec->fault_condition_2," ");
	eggrafi->rec->duration_2=777;
	eggrafi->rec->type_2=777;
	eggrafi->rec->tarrif_2=777;

	eggrafi->next_rec_2=NULL;

	return eggrafi;
 
}

second_record_2* create_second_record_2_new(rest_record_2* rec_){
	second_record_2* eggrafi;
	eggrafi=malloc(sizeof(struct second_record_2));
	eggrafi->rec=rec_;
	eggrafi->next_rec_2=NULL;

	return eggrafi;
 
}

 second_node_2* create_second_node_2(void){
 	 second_node_2* node=malloc(sizeof(struct second_node_2));
 	 node->number_of_records_2=0;
 	 node->First_rec_2=NULL;
 	 node->next_buc_2=NULL;

 	 return node;

 }

 second_Buckets_2 create_second_buckets_2(void){
 	second_Buckets_2 b=malloc(sizeof(struct second_buckets_of_nodes_2));
 	b->number_of_buckets_2=0;
 	b->First_buc_2=NULL;

 	return b;

 }

 void insert_to_end_of_bucket_node_2(Buckets_2 b,bucket_record_2* r,int bucket_size_){
 	bucket_node_2* node=b->First_buc;
 	bucket_node_2* temp_node;
 	bucket_record_2* temp;
 	bucket_record_2* new_temp;
 	int max_bucket_records=bucket_size_/sizeof(bucket_record_2);
 	
 	second_Buckets_2 pointer;
 	int count=0;
 	if(node==NULL){
 		node=create_node_2();
 		b->First_buc=node;
 	}
    while(node->next_buc!=NULL){
 	   	   	node=node->next_buc;
 	   	}
 	temp=node->First_rec;   	

 	if(temp==NULL){
 		//printf("Eisagwgh sthn arxh tou bucket_1\n");
 		temp=create_record_2();
 		strcpy(temp->destination_number_2,r->destination_number_2);
 		temp->next_rec=NULL;
 		temp->deiktis=r->deiktis;
 		node->First_rec=temp;
 	
 	    node->number_of_records++;
  	}else {
  		count++;
 		while(temp->next_rec!=NULL)
	   {
	     temp=temp->next_rec;
	     count++;
	   }
 	   if((count==max_bucket_records-1) && (node->next_buc==NULL)){
 		//   printf("To bucket einai gemato,prepei na ginei allocate ena allo\n");
 		   temp_node=node->next_buc;
 		   temp_node=create_node_2();
 		   temp_node->next_buc=NULL;
 		   node->next_buc=temp_node;
 		   b->number_of_buckets++;
 		   temp=temp_node->First_rec;
 		   temp=create_record_2();
 		   strcpy(temp->destination_number_2,r->destination_number_2);
 		   temp->next_rec=NULL;
 		   temp->deiktis=r->deiktis;;
 		   temp_node->First_rec=temp;
 		   temp_node->number_of_records++;

 	   }
 	   else{
 		  // printf("Xwraei h eggrafi sto bucket\n");
 		   new_temp=temp->next_rec;
 		   new_temp=create_record_2();
 		   temp->next_rec=new_temp;
 		   strcpy(new_temp->destination_number_2,r->destination_number_2);
 		   new_temp->next_rec=NULL;
 		   new_temp->deiktis=r->deiktis;

 		   node->number_of_records++;
 	   }
    }
 }

 void print_all_from_bucket_2(Buckets_2 b ){
	int i;
	int count_rec=0,count_bucs=0;
	bucket_record_2* rec_;
	bucket_node_2* node=b->First_buc;
	while(node==NULL){
		printf("(hashtable2)To node bucket 1 einai NULL sto %d\n",count_bucs);
		return;
	}
	if(node->First_rec==NULL)
		printf("(hashtable2)Buckets are empty");
	else{
	   while(node!=NULL){
	   
		rec_=node->First_rec;
		//printf("Record: %s\n",rec_->originator_number_1);
		while(rec_!=NULL){
			
			printf("(hashtable2)To record sto bucket 1 stin thesi %d: %s \n",count_rec,rec_->destination_number_2);
			print_all_from_first_second_2(rec_->deiktis);
			rec_=rec_->next_rec;
			count_rec++;
		}
		node=node->next_buc;
		count_bucs++;
       }
	}
}


void dump_print_all_from_bucket_2(Buckets_2 b,FILE* out){
	int i;
	int count_rec=0,count_bucs=0;
	bucket_record_2* rec_;
	bucket_node_2* node=b->First_buc;
	while(node==NULL){
		fprintf(out,"(hashtable2)To node bucket 1 einai NULL sto %d\n",count_bucs);
		return;
	}
	if(node->First_rec==NULL)
		fprintf(out,"(hashtable2)Buckets are empty");
	else{
	   while(node!=NULL){
	   
		rec_=node->First_rec;
		//printf("Record: %s\n",rec_->originator_number_1);
		while(rec_!=NULL){
			
			fprintf(out,"(hashtable2)To record sto bucket 1 stin thesi %d: %s \n",count_rec,rec_->destination_number_2);
			dump_print_all_from_first_second_2(rec_->deiktis,out);
			rec_=rec_->next_rec;
			count_rec++;
		}
		node=node->next_buc;
		count_bucs++;
       }
	}
}





int size_of_buckets_2(Buckets_2 b){

   return b->number_of_buckets;

}

void clean_buckets_2(Buckets_2 b){
	bucket_node_2* ptr;
	bucket_node_2* cleaner;
	ptr=b->First_buc;
	while(ptr!=NULL){
		cleaner=ptr;
		ptr=ptr->next_buc;

		free(cleaner->First_rec);
		free(cleaner->next_buc);
		free(cleaner);
	}
    free(b);
}

bucket_record_2* search_bucket_2(Buckets_2 b,char* x){
	bucket_node_2* node=b->First_buc;
	bucket_record_2* rec_;
	while(node!=NULL){
		rec_=node->First_rec;
		while(rec_!=NULL){
			//printf("%s %s\n",rec_->originator_number_1,x);
			if(!strcmp(rec_->destination_number_2,x)){
				printf("(hashtable2)Record found in bucket 1!!\n");
				return rec_;
			}
			rec_=rec_->next_rec;
		}

        node=node->next_buc;
	}
	//printf("Record not found!!\n");
	//rec_=create_record_1();
    rec_=NULL;
	return rec_;
	
}

int size_of_second_buckets_2(second_Buckets_2 b){
	return b->number_of_buckets_2;

}

void insert_to_end_second_2(second_Buckets_2 b,second_record_2* r){
	second_node_2* node=b->First_buc_2;
	second_node_2* temp_node_2;
 	second_record_2* temp;
 	second_record_2* new_temp_2;
 	int count=0;
    if(node==NULL){
    	node=create_second_node_2();
    	b->First_buc_2=node;
    }
 	while(node->next_buc_2!=NULL){
 	   	   	node=node->next_buc_2;
 	   	}
     
    temp=node->First_rec_2;

 	if(temp==NULL){
 	//	printf("Eisagwgh sthn arxh tou bucket_2\n");
 		temp=create_second_record_2();
 		strcpy(temp->rec->cdr_uniq_id_2,r->rec->cdr_uniq_id_2);
 		strcpy(temp->rec->originator_number_2,r->rec->originator_number_2);
 		strcpy(temp->rec->date_2,r->rec->date_2);
 		strcpy(temp->rec->init_time_2,r->rec->init_time_2);
 		strcpy(temp->rec->fault_condition_2,r->rec->fault_condition_2);
 		temp->rec->duration_2=r->rec->duration_2;
 		temp->rec->type_2=r->rec->type_2;
 		temp->rec->tarrif_2=r->rec->tarrif_2;

 		temp->next_rec_2=NULL;
 		node->First_rec_2=temp;
 		
 	    node->number_of_records_2++;
  	}else {
  		count++;
 		while(temp->next_rec_2!=NULL)
	   {
	     temp=temp->next_rec_2;
	     count++;
	   }
 	   if((count==max_second_bucket_records-1) && (node->next_buc_2==NULL)){
 		//   printf("To second bucket einai gemato,prepei na ginei allocate ena allo\n");
 		   temp_node_2=node->next_buc_2;
 		   temp_node_2=create_second_node_2();
 		   temp_node_2->next_buc_2=NULL;
 		   node->next_buc_2=temp_node_2;
 		   b->number_of_buckets_2++;
 		   temp=temp_node_2->First_rec_2;
 		   temp=create_second_record_2();

 		   strcpy(temp->rec->cdr_uniq_id_2,r->rec->cdr_uniq_id_2);
 		   strcpy(temp->rec->originator_number_2,r->rec->originator_number_2);
 		   strcpy(temp->rec->date_2,r->rec->date_2);
 		   strcpy(temp->rec->init_time_2,r->rec->init_time_2);
 		   strcpy(temp->rec->fault_condition_2,r->rec->fault_condition_2);
 		   temp->rec->duration_2=r->rec->duration_2;
 		   temp->rec->type_2=r->rec->type_2;
 		   temp->rec->tarrif_2=r->rec->tarrif_2;

 		   temp->next_rec_2=NULL;

 		   temp_node_2->First_rec_2=temp;

 		   temp_node_2->number_of_records_2++;

 	   }
 	   else{
 		 //  printf("Xwraei h eggrafi sto second bucket\n");
 		   new_temp_2=temp->next_rec_2;
 		   new_temp_2=create_second_record_2();
 		   
 		   strcpy(new_temp_2->rec->cdr_uniq_id_2,r->rec->cdr_uniq_id_2);
 		   strcpy(new_temp_2->rec->originator_number_2,r->rec->originator_number_2);
 		   strcpy(new_temp_2->rec->date_2,r->rec->date_2);
 		   strcpy(new_temp_2->rec->init_time_2,r->rec->init_time_2);
 		   strcpy(new_temp_2->rec->fault_condition_2,r->rec->fault_condition_2);
 		   new_temp_2->rec->duration_2=r->rec->duration_2;
 		   new_temp_2->rec->type_2=r->rec->type_2;
 		   new_temp_2->rec->tarrif_2=r->rec->tarrif_2;

 		   new_temp_2->next_rec_2=NULL;

 		   temp->next_rec_2=new_temp_2;

 		   node->number_of_records_2++;
 	   }
    }
}

void print_all_from_first_second_2(second_Buckets_2 b){
	int i;
	second_record_2* rec_;
	second_node_2* node=b->First_buc_2;
	if(node==NULL){
		printf("(hashtable2)error node bucket 2 einai NULL\n");
		return;
	}
	if(node->First_rec_2==NULL)
		printf("(hashtable2)Second Buckets are empty\n");
	else{
	   while(node!=NULL){

		rec_=node->First_rec_2;
		while(rec_!=NULL){

			printf("(hashtable2)To second record sto bucket: %s %s  \n",rec_->rec->cdr_uniq_id_2,rec_->rec->originator_number_2);
			rec_=rec_->next_rec_2;
		}
		node=node->next_buc_2;
       }
	}
}


void dump_print_all_from_first_second_2(second_Buckets_2 b,FILE* out){
	int i;
	second_record_2* rec_;
	second_node_2* node=b->First_buc_2;
	if(node==NULL){
		fprintf(out,"(hashtable2)error node bucket 2 einai NULL\n");
		return;
	}
	if(node->First_rec_2==NULL)
		fprintf(out,"(hashtable2)Second Buckets are empty\n");
	else{
	   while(node!=NULL){

		rec_=node->First_rec_2;
		while(rec_!=NULL){

			fprintf(out,"(hashtable2)To second record sto bucket: %s %s  \n",rec_->rec->cdr_uniq_id_2,rec_->rec->originator_number_2);
			rec_=rec_->next_rec_2;
		}
		node=node->next_buc_2;
       }
	}
}





void clean_second_buckets_2(second_Buckets_2 b){
	second_node_2* ptr;
	second_node_2* cleaner;
	ptr=b->First_buc_2;
	while(ptr!=NULL){
		cleaner=ptr;
		ptr=ptr->next_buc_2;

		free(cleaner->First_rec_2);
		free(cleaner->next_buc_2);
		free(cleaner);
	}
    free(b);
}


second_record_2* second_search_bucket_2(second_Buckets_2 b,char* x){
	second_node_2* node=b->First_buc_2;
	second_record_2* rec_;
	while(node!=NULL){
		rec_=node->First_rec_2;
		while(rec_!=NULL){
			if(!strcmp(rec_->rec->originator_number_2,x)){
		//		printf("Record found in bucket 2!!\n");
				return rec_;
			}
			rec_=rec_->next_rec_2;
		}

        node=node->next_buc_2;
	}
	//printf("Record not found!!\n");
}

void print_recs_from_first_second_1_2(second_Buckets_2 b,char* start_time,char* end_time){
 	int i;
 	int hours_init;
	int minutes_init;
	int minutes_final;
	int hours_final;
	int rec_hours;
	int rec_minutes;
	char str[7];
	second_record_2* rec_;
	second_node_2* node=b->First_buc_2;
	strncpy(str,start_time,2);
    hours_init=atoi(str);
	printf("hours_init: %d\n",hours_init);
	reverse_string_3(start_time);
	strncpy(str,start_time,2);
	reverse_string_3(str);
	minutes_init=atoi(str);
	printf("minutes_init: %d\n",minutes_init);

	strncpy(str,end_time,2);
	hours_final=atoi(str);
	printf("hours_final: %d\n",hours_final);
	reverse_string_3(end_time);
	strncpy(str,end_time,2);
	reverse_string_3(str);
	minutes_final=atoi(str);
	printf("minutes_final: %d\n",minutes_final);
  

	if(node==NULL){
		printf("(hashtable2)error node bucket 2 einai NULL\n");
		return;
	}
    if(node->First_rec_2==NULL)
		printf("(hashtable2)Second Buckets are empty\n");
	else{
	   while(node!=NULL){
      
		rec_=node->First_rec_2;
		while(rec_!=NULL){
		   strncpy(str,rec_->rec->init_time_2,2);
           rec_hours=atoi(str);
           printf("rec_hours: %d\n",rec_hours);
           reverse_string_3(rec_->rec->init_time_2);
           strncpy(str,rec_->rec->init_time_2,2);
           reverse_string_3(str);
           rec_minutes=atoi(str);
           printf("rec_minutes: %d\n",rec_minutes);

			if(rec_hours>hours_init && rec_hours<hours_final){
					printf("(hashtable2)To cdr: %s %s %s\n",rec_->rec->cdr_uniq_id_2,rec_->rec->originator_number_2,rec_->rec->date_2);
			}else if(rec_hours==hours_final){
				if(rec_minutes<minutes_final){
					printf("(hashtable2)To cdr: %s %s %s\n",rec_->rec->cdr_uniq_id_2,rec_->rec->originator_number_2,rec_->rec->date_2);
				}
			}else if(rec_hours==hours_init){
				if(rec_minutes>minutes_init){
					printf("(hashtable2)To cdr: %s %s %s\n",rec_->rec->cdr_uniq_id_2,rec_->rec->originator_number_2,rec_->rec->date_2);

				}
			}
  
			rec_=rec_->next_rec_2;
		}
		node=node->next_buc_2;
       }
	}
 }



 void print_recs_from_first_second_2_2(second_Buckets_2 b,time* start_time,time* end_time,date* date_1,date* date_2){
 	int i;
 	int hours_init;
	int minutes_init;
	int minutes_final;
	int hours_final;
	int rec_hours;
	int rec_minutes;
	int rec_day;
	int rec_month;
	int rec_year;
	char str[4];
	char str_1[5];
	strcpy(str,"");
	strcpy(str_1,"");
	second_record_2* rec_;
	second_node_2* node=b->First_buc_2;
	// printf("hours_t_1: %d\n",start_time->hours);
	// printf("minutes_t_1: %d\n",start_time->minutes);

	// printf("hours_t_2: %d\n",end_time->hours);
	// printf("minutes_t_2: %d\n",end_time->minutes);

	
   // printf("Date_1: day:%d month:%d year:%d\n",date_1->day, date_1->month, date_1->year);
    //printf("Date_2: day:%d month:%d year:%d\n",date_2->day, date_2->month, date_2->year);
/*--------------------------------------------------------------------------------------*/
	
	if(node==NULL){
		printf("(hashtable2)error node bucket 2 einai NULL\n");
		return;
	}
    if(node->First_rec_2==NULL)
		printf("(hashtable2)Second Buckets are empty\n");
	else{
	   while(node!=NULL){
      
		rec_=node->First_rec_2;
		while(rec_!=NULL){
			  /* strncpy(str,rec_->rec->init_time_1,2);
               rec_hours=atoi(str);
               printf("rec_hours: %d\n",rec_hours);
               reverse_string_3(rec_->rec->init_time_1);
               strncpy(str,rec_->rec->init_time_1,2);
               reverse_string_3(str);
               rec_minutes=atoi(str);
               printf("rec_minutes: %d\n",rec_minutes);*/


		       strncpy(str_1,rec_->rec->date_2,4);	
	           strncpy(str,str_1,2);
	           rec_day=atoi(str);
	           reverse_string_3(str_1);	            
	           strncpy(str,str_1,2);           
	           reverse_string_3(str);           
	           rec_month=atoi(str);

	           reverse_string_3(rec_->rec->date_2);
	           strncpy(str_1,rec_->rec->date_2,4);
	           reverse_string_3(str_1);
	           rec_year=atoi(str_1);

	          // printf("rec_day:%d\n",rec_day);
	          // printf("rec_month:%d\n",rec_month);
	          // printf("rec_year:%d\n",rec_year);

			/*if(rec_hours>hours_init && rec_hours<hours_final){
					printf("To cdr: %s %s %s\n",rec_->rec->cdr_uniq_id_1,rec_->rec->destination_number_1,rec_->rec->date_1);
			}else if(rec_hours==hours_final){
				if(rec_minutes<minutes_final){
					printf("To cdr: %s %s %s\n",rec_->rec->cdr_uniq_id_1,rec_->rec->destination_number_1,rec_->rec->date_1);
				}
			}else if(rec_hours==hours_init){
				if(rec_minutes>minutes_init){
					printf("To cdr: %s %s %s\n",rec_->rec->cdr_uniq_id_1,rec_->rec->destination_number_1,rec_->rec->date_1);

				}
			}*/
  
			rec_=rec_->next_rec_2;

		}
		node=node->next_buc_2;
       }
	}
 
}


void top_dest_bucket_2(second_Buckets_2 b){
	int i,j;
	second_record_2* rec_;
	second_node_2* node=b->First_buc_2;
	char* temp_array[21][2];
	int count=0,count_array=0;
	int plithos;
	char str_count[5];

	for(i=0;i<21;i++){
		for(j=0;j<2;j++){
			temp_array[i][j]=malloc(sizeof(char*));
		}
	}
	for(i=0;i<20;i++){
		   strcpy(temp_array[i][1],"");
		   sprintf(str_count,"%d",0);
		   strcpy(temp_array[i][2],str_count);
	}

	if(node==NULL){
		printf("(hashtable2)error node bucket 2 einai NULL\n");
		return;
	}
	if(node->First_rec_2==NULL)
		printf("(hashtable2)Second Buckets are empty\n");
	else{
	   while(node!=NULL){

		rec_=node->First_rec_2;
		while(rec_!=NULL){
			for(i=0;i<20;i++){
				if(!strcmp(rec_->rec->originator_number_2,temp_array[i][1])){
					printf("(hashtable2)There is this dest_number in table,in position %d !!\n",i);
					plithos=atoi(temp_array[i][2]);
					plithos++;
					sprintf(str_count,"%d",plithos);
					strcpy(temp_array[i][2],str_count);
					break;
				}
			}
			strcpy(temp_array[count_array][1],rec_->rec->originator_number_2);
			sprintf(str_count,"%d",1);
			strcpy(temp_array[count_array][2],str_count);
			count_array++;

			rec_=rec_->next_rec_2;
			count++;
		}
		node=node->next_buc_2;
       }
	}
	/*for(i=0;i<20;i++){
		printf("Dest_number: %s with count %s\n",temp_array[i][1],temp_array[i][2]);
	}*/

	bubblesort_1(temp_array);
	//printf("----------------------------------------\n");

	/*for(i=0;i<20;i++){
		printf("Dest_number: %s with count %s\n",temp_array[i][1],temp_array[i][2]);
	}*/
	for(i=0;i<20;i++){
		if(strcmp(temp_array[i][2],temp_array[0][2])>=0)
		printf("(hashtable2)Dest_number: %s with count %s\n",temp_array[i][1],temp_array[i][2]);
	}

	for(i=0;i<21;i++){
		for(j=0;j<2;j++){
			free(temp_array[i][j]);
		}
	}
}
