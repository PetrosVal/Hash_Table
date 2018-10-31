#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "caller_hashtable.h"
#include "calle_hashtable.h"
#include "heap.h"

#define DEFAULT_HASH_SIZE 10
#define MAX_BUFF_SIZE 256

FILE *default_out;
int mhash_size_1=DEFAULT_HASH_SIZE;
int mhash_size_2=DEFAULT_HASH_SIZE;

void reverse_string_1(char *str)
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

int count_spaces(char* a){
    int counter=0;
    int i=0;
    while(a[i]!='\0'){
        if(a[i]==' '){
            counter++;
        }
        i++;
    }
    return counter;
}

void rmn(char * a){
    int i=0;
    while(a[i]!='\0'){
        if(a[i]=='\n'){
            a[i]='\0';
            break;
        }
        i++;
    }
}

void insert_records(hash_table table,int size,record* rec,int bucket_size_){

   int a;
   a=insert_hash_table(table,size,rec,bucket_size_);

}

void insert_records_2(hash_table_2 table,int  size,record* rec,int bucket_size_){
	int a;
	a=insert_hash_table_2(table,size,rec,bucket_size_);

}


void delete_record(hash_table table,int size,char* caller,char* id){

	delete_record_hash_table(table,size,caller,id);
	printf("Record with id:%s deleted!!\n",id);
}

void  print_the_hash_table(hash_table table,int size){

	 print_all_hash_table(table,size);

}

void print_the_hash_table_2(hash_table_2 table,int size){
	 print_all_hash_table_2(table,size);


}

void clean_werhauz(hash_table table,int size){

	clean_hash_table(table,size);

}

void clean_werhauz_2(hash_table_2 table,int size){
	clean_hash_table_2(table,size);

}


void find_cdrs_1(hash_table table,int size,char* caller){
	 bucket_record_1* rec_1;
	 rec_1=search_hash_table(table,caller,size);
	 if(rec_1==NULL){
	 	printf("(hashtable1)There is no cdr with this caller\n");
	 	return ;
	 }
	 print_all_from_first_second(rec_1->deiktis);


}

void find_cdrs_1_2(hash_table_2 table,int size,char* calle){
	 bucket_record_2* rec_1;
	 rec_1=search_hash_table_2(table,calle,size);
	 if(rec_1==NULL){
	 	printf("(hashtable2)There is no cdr with this caller\n");
	 	return ;
	 }
	 print_all_from_first_second_2(rec_1->deiktis);


}


void find_cdrs_2(hash_table table,int size,char* caller,char* init,char* final){
	 bucket_record_1* rec_1;
	 rec_1=search_hash_table(table,caller,size);
	 if(rec_1==NULL){
	 	printf("(hashtable1)There is no cdr with this caller\n");
	 	return ;
	 }
	 print_recs_from_first_second_1(rec_1->deiktis,init,final);
}


void find_cdrs_2_2(hash_table_2 table,int size,char* calle,char* init,char* final){
	 bucket_record_2* rec_1;
	 rec_1=search_hash_table_2(table,calle,size);
	 if(rec_1==NULL){
	 	printf("(hashtable2)There is no cdr with this caller\n");
	 	return ;
	 }
	 print_recs_from_first_second_1_2(rec_1->deiktis,init,final);
}

void find_cdrs_3(hash_table table,int size,char* caller,time* init,time* final,date* date_1,date* date_2){
     bucket_record_1* rec_1;
	 rec_1=search_hash_table(table,caller,size);
	 if(rec_1==NULL){
	 	printf("(hashtable1)There is no cdr with this caller\n");
	 	return ;
	 }
	 print_recs_from_first_second_2(rec_1->deiktis,init,final,date_1,date_2);
}

void find_cdrs_3_2(hash_table_2 table,int size,char* calle,time* init,time* final,date* date_1,date* date_2){
     bucket_record_2* rec_1;
	 rec_1=search_hash_table_2(table,calle,size);
	 if(rec_1==NULL){
	 	printf("(hashtable2)There is no cdr with this caller\n");
	 	return ;
	 }
	 print_recs_from_first_second_2_2(rec_1->deiktis,init,final,date_1,date_2);
}




void top_dest(hash_table table,int size,char* caller){
	bucket_record_1* rec_1;
	 rec_1=search_hash_table(table,caller,size);
	 if(rec_1==NULL){
	 	printf("There is no dest with this caller\n");
	 	return ;
	 }
	 top_dest_bucket(rec_1->deiktis);
}

void indist(hash_table table_1,hash_table_2 table_2,char* call_1,char* call_2,int size_1,int size_2){
  bucket_record_1* rec_1;
  bucket_record_2* rec_2;
  bucket_record_1* rec_3;
  bucket_record_2* rec_4;
  char* array_indist[31];
  second_node_1* node_1;
  second_node_2* node_2;
  second_record_1* rec_;
  second_record_2* recor;
  int i,j;
  int count_array=0;
  for(i=0;i<31;i++){ 
    array_indist[i]=malloc(sizeof(char*));
  }
    for(i=0;i<31;i++){
       strcpy(array_indist[i],"");
    }


  rec_1=search_hash_table(table_1,call_1,size_1);

  if(rec_1==NULL){
    printf("call_1 is not in hashtable_1\n");
    rec_2=search_hash_table_2(table_2,call_1,size_2);
    if(rec_2==NULL){
      printf("call_1 is not in hashtable_2 \n");
    }else{
      printf("O call_1 vrethike sto hashtable2\n");
    }
  }else{
    printf("O call_1 vrethike sto hashtable1\n");
  }

  rec_3=search_hash_table(table_1,call_2,size_1);

  if(rec_3==NULL){
    printf("call_2 is not in hashtable_1\n");
    rec_4=search_hash_table_2(table_2,call_2,size_2);
     if(rec_4==NULL){
      printf("call_2 is not in hashtable_2 \n");
    }
    else{
      printf("O call_2 vrethike sto hashtable2\n");
    }

  }else{
    printf("O call_2 vrethike sto hashtable_1\n");
  }

  /*----------------------------------------------*/

  if((rec_1!=NULL) && (rec_3!=NULL)){

    node_1=rec_1->deiktis->First_buc_2;
    if(node_1==NULL){
    printf("(hashtable1)error node bucket 2 einai NULL\n");
    return;
    }

   if(node_1->First_rec_2==NULL)
     printf("Second Buckets are empty\n");
   else{   
     while(node_1!=NULL){
      rec_=node_1->First_rec_2;    
      while(rec_!=NULL){
        if(second_search_bucket(rec_3->deiktis,rec_->rec->destination_number_1)!=NULL){
           strcpy(array_indist[count_array],rec_->rec->destination_number_1);
           count_array++;
        }

         rec_=rec_->next_rec_2;

      }

      node_1=node_1->next_buc_2;
    }
  }

  /*for(i=0;i<31;i++){
    if(strcmp(array_indist[i],"")){
      printf("O number:%s\n",array_indist[i]); 
   }
  }*/
 }else if((rec_1!=NULL) && (rec_4!=NULL)){
   node_1=rec_1->deiktis->First_buc_2;

    if(node_1==NULL){
    printf("(hashtable1)error node bucket 2 einai NULL\n");
    return;
    }

    if(node_1->First_rec_2==NULL)
     printf("Second Buckets are empty\n");
   else{   
     while(node_1!=NULL){
      rec_=node_1->First_rec_2;    
      while(rec_!=NULL){
        if(second_search_bucket_2(rec_4->deiktis,rec_->rec->destination_number_1)!=NULL){
           strcpy(array_indist[count_array],rec_->rec->destination_number_1);
           count_array++;
        }

         rec_=rec_->next_rec_2;

      }

      node_1=node_1->next_buc_2;
    }
  }
   for(i=0;i<31;i++){
    if(strcmp(array_indist[i],"")){

      //printf("O number:%s\n",array_indist[i]);
      
    }

    }

 }else if((rec_2!=NULL) && (rec_3!=NULL)){

   node_2=rec_2->deiktis->First_buc_2;

    if(node_2==NULL){
    printf("(hashtable2)error node bucket 2 einai NULL\n");
    return;
    }

    if(node_2->First_rec_2==NULL)
     printf("Second Buckets are empty\n");
   else{   
     while(node_2!=NULL){
      recor=node_2->First_rec_2;    
      while(recor!=NULL){
        if(second_search_bucket(rec_3->deiktis,recor->rec->originator_number_2)!=NULL){
           strcpy(array_indist[count_array],recor->rec->originator_number_2);
           count_array++;
        }

         recor=recor->next_rec_2;

      }

      node_2=node_2->next_buc_2;
    }
  }
   /*for(i=0;i<31;i++){
    if(strcmp(array_indist[i],""))
      printf("O number:%s\n",array_indist[i]);

    }*/
 }else if((rec_2!=NULL) && (rec_4!=NULL)){

   node_2=rec_2->deiktis->First_buc_2;

    if(node_2==NULL){
    printf("(hashtable2)error node bucket 2 einai NULL\n");
    return;
    }

    if(node_2->First_rec_2==NULL)
     printf("Second Buckets are empty\n");
   else{   
     while(node_2!=NULL){
      recor=node_2->First_rec_2;    
      while(recor!=NULL){
        if(second_search_bucket_2(rec_4->deiktis,recor->rec->originator_number_2)!=NULL){
           strcpy(array_indist[count_array],recor->rec->originator_number_2);
           count_array++;
        }

         recor=recor->next_rec_2;

      }

      node_2=node_2->next_buc_2;
    }
  }
   /*for(i=0;i<31;i++){
    if(strcmp(array_indist[i],""))
      printf("O number:%s\n",array_indist[i]);

    }*/
 }
}

void dump_1(hash_table table_1,int size,FILE* out){

  dump_print_all_hash_table(table_1,size,out);
}

void dump_2(hash_table_2 table_2,int size,FILE* out){

  dump_print_all_hash_table_2(table_2,size,out);


}







int main(int argc,char *argv[]){
	hash_table pinakas_1;
	hash_table_2 pinakas_2;
  max_heap binary_heap;
  node* komvos_heap;
	record rec_;
  float xrewsi;
	int i,a,nm,bucket_size;
	int hash_flag_1=0,hash_flag_2=0,file_flag=0;
  int flag_indist;
	FILE *stream=stdin;
	char hash_t[10];
	char buff[MAX_BUFF_SIZE];
	default_out=stdout;
  int arg_count;
  char* token; 
  char str_xrewsi[10];
  char call_1[20];
  char call_2[20];
  char str[7];
  char str_1[7];
  char temp_token[5][10];
  char final_time[7];
  char final_date[8];
  date* d_1;
  date* d_2;
  time* t_1;
  time* t_2;
  int rec_date_day_1;
	int rec_date_month_1;
	int rec_date_year_1;
	int rec_date_day_2;
	int rec_date_month_2;
	int rec_date_year_2;
  int l;
  strcpy(str,"");
  strcpy(str_1,"");
    for(i=0;i<5;i++){
    	strcpy(temp_token[i]," ");
    }
  
     for(i=1;i<argc;i++){
        if(strcmp(argv[i],"-h1")==0){
            if(i+1==argc){
                fprintf(stderr,"Failure: Wrong parameters.\n");
                exit(1);
            }
            hash_flag_1=1;
            mhash_size_1=atoi(argv[i+1]);
            pinakas_1=create_hash_table(mhash_size_1);
        }
        else if(strcmp(argv[i],"-h2")==0){
            if(i+1==argc){
                fprintf(stderr,"Failure: Wrong parameters.\n");
                exit(1);
            }
            hash_flag_2=1;
            mhash_size_2=atoi(argv[i+1]);
            pinakas_2=create_hash_table_2(mhash_size_2);
        }
        else if(strcmp(argv[i],"-s")==0){
            if(i+1==argc){
                fprintf(stderr,"Failure: Wrong parameters.\n");
                exit(1);
            }        
            bucket_size=atoi(argv[i+1]);
        }
        else if(strcmp(argv[i],"-o")==0){
            if(i+1==argc){
                fprintf(stderr,"Failure: Wrong parameters.\n");
                exit(1);
            }
            file_flag=1;
            nm=i+1;
            stream=fopen(argv[i+1],"r");
            if(stream==NULL){
                fprintf(stderr,"Failure: file %s does not exist.\n",argv[i+1]);
                exit(1);
            }
        }
    }
    binary_heap=create_heap();
    if(hash_flag_1!=1){
        printf("Failure: Missing hash table 1 size.");
        exit(1);
    }
    if(hash_flag_2!=1){
        printf("Failure: Missing hash table 2 size.");
        exit(1);
    }

  while(1){

  	i=0;
  	char* st;
  	printf("> ");

  	st=fgets(buff,MAX_BUFF_SIZE,stream);

  	 if(st==NULL && file_flag==0){
            break;
        }
     else if(st==NULL && file_flag==1){
            fclose(stream);
            file_flag=0;
            stream=stdin;
            printf("File: %s closed.\n",argv[nm]);
            continue;
       }
     rmn(buff);
     if(count_spaces(buff)==strlen(buff)){
            continue;
        }
           
     if(strlen(buff)<1){
         continue;
        }    
    token=strtok(buff," ");
    arg_count=0;
   // printf("%s",token);
   if(strcmp(token,"insert")==0){
   	 while(token!=NULL){
   		token=strtok(NULL,";");
   		if(token!=NULL){
   		  switch(i){
   		  	
   		  	case 0:
   		  	    strcpy(rec_.cdr_uniq_id,token);
   		  	    break;
   		  	case 1:
   		  	    strcpy(rec_.originator_number,token);
   		  	    break;
   		  	case 2:
   		  	    strcpy(rec_.destination_number,token);
   		  	    break;
   		  	case 3:
   		  	    strcpy(rec_.date,token);
   		  	    break;
   		  	case 4:
   		  	    strcpy(rec_.init_time,token);
   		  	    break;
   		  	case 5:
   		  	    a=atoi(token);
   		  	    //printf("a: %d",a);
   		  	    rec_.duration=a;
   		  	    break;
   		  	case 6:
   		  	   a=atoi(token);
   		  	   rec_.type=a;
   		  	   break;
   		  	case 7:    
   		  	   a=atoi(token);
   		  	   rec_.tarrif=a;
   		  	   break;
   		  	case 8: 
   		  	   strcpy(rec_.fault_condition,token);
   		  	   break;
   		  	default:
   		  	   break;  
   		  	       
   		  }
   		}
   		else{
   	
   			break;
   		}
   		i++;
   	  }
   	  //printf("%s\n %s\n %s\n %s\n %s\n %d\n %d\n %d\n %s\n",rec_.cdr_uniq_id,rec_.originator_number,rec_.destination_number,rec_.date,rec_.init_time,rec_.duration,rec_.type,rec_.tarrif,rec_. fault_condition);
   	  insert_records(pinakas_1, mhash_size_1,&rec_,bucket_size);
   	  insert_records_2(pinakas_2, mhash_size_2,&rec_,bucket_size);

      if(rec_.type==0){

        if(rec_.tarrif==0)
          xrewsi=0.1;
      }else if(rec_.type==1){
        if(rec_.tarrif==1)
          xrewsi=0.5*rec_.duration;
        else if(rec_.tarrif==2)
          xrewsi=1*rec_.duration;
      }else if(rec_.type==2){
        if(rec_.tarrif==1)
          xrewsi=0.2*rec_.duration;
        else if(rec_.tarrif==2)
          xrewsi=0.5*rec_.duration;
      }

      sprintf(str_xrewsi,"%f",xrewsi);

      komvos_heap=create_node();
      strcpy(komvos_heap->phone,rec_.originator_number);
      strcpy(komvos_heap->poso,str_xrewsi);
      
      insert_heap(binary_heap,komvos_heap);


   }else if(strcmp(token,"delete")==0){
   	 while(token!=NULL){
   	   token=strtok(NULL," ");
   	   if(token!=NULL){
   	   	   switch(i){
   	   	   	case 0:
   	   	   	    strcpy(rec_.cdr_uniq_id,token);
   		  	    break;
   		  	case 1: 
   		  	    strcpy(rec_.originator_number,token);
   		  	    break;   
   	   	   }
   	   }else{
   	   	  break;
   	   }

   	  i++;
   	 } 
   	 //printf("%s\n %s\n ",rec_.cdr_uniq_id,rec_.originator_number);
   	   delete_record(pinakas_1, mhash_size_1,rec_.originator_number,rec_.cdr_uniq_id);

   }else if(strcmp(token,"print")==0){
   	 while(token!=NULL){
   	   token=strtok(NULL," ");
   	   if(token!=NULL){
   	   	   switch(i){
   	   	   	case 0:
   	   	   	    strcpy(hash_t,token);
   		  	    break;
   	   	   }
   	   }else{
   	   	  break;
   	   }
   	  i++;
   	 } 
   	  if(!strcmp(hash_t,"hashtable1"))
   	     print_the_hash_table(pinakas_1, mhash_size_1);
   	  else
   	  	print_the_hash_table_2(pinakas_2, mhash_size_2);

   }else if(strcmp(token,"bye")==0){
   	 //printf("token: %s\n",token);
   	 puts("Success: Cleaned memory.");
   	 clean_werhauz(pinakas_1, mhash_size_1);
   	 clean_werhauz_2(pinakas_2, mhash_size_2);

     pinakas_1=create_hash_table(mhash_size_1);
     pinakas_2=create_hash_table_2(mhash_size_2);

   }else if(strcmp(token,"find")==0){
   	 while(token!=NULL){
   	   token=strtok(NULL," ");
   	   if(token!=NULL){
   	   	  if(arg_count==1){  	
   	   	  	while(token!=NULL){	   	
   	   	  		if(token!=NULL){   	  		
   	   	  			strcpy(temp_token[i],token);
   	   	  		//	printf("To orisma: %s\n",temp_token[i]);
   	   	  			i++;
   	   	  		}
   	   	  	 token=strtok(NULL," ");
   	   	    }
   	   	  }else{
   	   	  	strcpy(rec_.originator_number,token);
   	   	  	//printf("O caller:%s \n ",rec_.originator_number);
   	   	  }  
   	   }
   	  arg_count++;
   	 } 
   	 	if(!strcmp(temp_token[0]," ")){
   	 		find_cdrs_1(pinakas_1,mhash_size_1,rec_.originator_number);
   	 	}
   	 	else {
   	 		i=0;
   	 		while(strcmp(temp_token[i]," ")){
   	 			i++;
   	 		}
   	 		if(i==2){
   	 			strcpy(rec_.init_time,temp_token[0]);
   	 			strcpy(final_time,temp_token[1]);
   	 			find_cdrs_2(pinakas_1,mhash_size_1,rec_.originator_number,rec_.init_time,final_time);

   	 		}
   	 		if(i==4){
   	 			d_1=malloc(sizeof(date));
   	            d_2=malloc(sizeof(date));
   	            t_1=malloc(sizeof(time));
   	            t_2=malloc(sizeof(time));
   	 			strcpy(rec_.init_time,temp_token[0]);
   	 			strcpy(rec_.date,temp_token[1]);
   	 			strcpy(final_time,temp_token[2]);
   	 			strcpy(final_date,temp_token[3]);

   	 			printf("start_time:%s\n",rec_.init_time);

	            strncpy(str,rec_.init_time,2);
                t_1->hours=atoi(str);
	            printf("hours_t_1: %d\n",t_1->hours);
	            reverse_string_1(rec_.init_time);
	            strncpy(str,rec_.init_time,2);
	            reverse_string_1(str);

	            t_1->minutes=atoi(str);
	            printf("minutes_t_1: %d\n",t_1->minutes);

                printf("end_time:%s\n",final_time);
 
	            strncpy(str,final_time,2);
	            printf("str:%s\n",str);
	            t_2->hours=atoi(str);
	            printf("hours_t_2: %d\n",t_2->hours);
	            reverse_string_1(final_time);
	            strncpy(str,final_time,2);
	            reverse_string_1(str);
	            t_2->minutes=atoi(str);
	            printf("minutes_t_2: %d\n", t_2->minutes);


   	 			/*strncpy(str_1,rec_.date,4);	
	            strncpy(str,str_1,2);
	            rec_date_day_1=atoi(str);
	            reverse_string_1(str_1);	            
	            strncpy(str,str_1,2);           
	            reverse_string_1(str);           
	            rec_date_month_1=atoi(str);

	            reverse_string_1(rec_.date);
	            strncpy(str_1,rec_.date,4);
	            reverse_string_1(str_1);
	            rec_date_year_1=atoi(str_1);
	        
	            d_1->day=rec_date_day_1;
	            d_1->month= rec_date_month_1;
	            d_1->year=rec_date_year_1;
	            printf("Date_1: day:%d month:%d year:%d\n",d_1->day, d_1->month, d_1->year);

                strncpy(str_1,final_date,4);	
	            strncpy(str,str_1,2);
	            rec_date_day_2=atoi(str);
	    
	            reverse_string_1(str_1);	            
	            strncpy(str,str_1,2);           
	            reverse_string_1(str);           
	            rec_date_month_2=atoi(str);
	         
	            reverse_string_1(final_date);
	            strncpy(str_1,rec_.date,4);
	            reverse_string_1(str_1);
	            rec_date_year_2=atoi(str_1);
	         
	            d_2->day=rec_date_day_2;
	            d_2->month= rec_date_month_2;
	            d_2->year=rec_date_year_2;*/
	            //printf("Date_2: day:%d month:%d year:%d\n",d_2->day, d_2->month, d_2->year);

   	 			find_cdrs_3(pinakas_1,mhash_size_1,rec_.originator_number,t_1,t_2,d_1,d_2);
   	 		}
   	 	}
   }else if(strcmp(token,"topdest")==0){
   	 while(token!=NULL){
   	   token=strtok(NULL," ");
   	   if(token!=NULL){
   	   	   switch(i){
   	   	   	case 0:
   	   	   	    strcpy(rec_.originator_number,token);
   		  	    break;
   	   	   }
   	   }else{
   	   	  break;
   	   }
   	  i++;
   	 } 
   	  top_dest(pinakas_1, mhash_size_1,rec_.originator_number);
   	}else if(strcmp(token,"lookup")==0){
   	 while(token!=NULL){
   	   token=strtok(NULL," ");
   	   if(token!=NULL){
   	   	  if(arg_count==1){  	
   	   	  	while(token!=NULL){	   	
   	   	  		if(token!=NULL){   	  		
   	   	  			strcpy(temp_token[i],token);
   	   	  		//	printf("To orisma: %s\n",temp_token[i]);
   	   	  			i++;
   	   	  		}
   	   	  	 token=strtok(NULL," ");
   	   	    }
   	   	  }else{
   	   	  	strcpy(rec_.destination_number,token);
   	   	  	//printf("O caller:%s \n ",rec_.originator_number);
   	   	  }  
   	   }
   	  arg_count++;
   	 } 
   	 	if(!strcmp(temp_token[0]," ")){
   	 		find_cdrs_1_2(pinakas_2,mhash_size_2,rec_.destination_number);
   	 	}
   	 	else {
   	 		i=0;
   	 		while(strcmp(temp_token[i]," ")){
   	 			i++;
   	 		}
   	 		if(i==2){
   	 			strcpy(rec_.init_time,temp_token[0]);
   	 			strcpy(final_time,temp_token[1]);
   	 			find_cdrs_2_2(pinakas_2,mhash_size_2,rec_.destination_number,rec_.init_time,final_time);

   	 		}
   	 		if(i==4){
   	 			d_1=malloc(sizeof(date));
   	            d_2=malloc(sizeof(date));
   	            t_1=malloc(sizeof(time));
   	            t_2=malloc(sizeof(time));
   	 			strcpy(rec_.init_time,temp_token[0]);
   	 			strcpy(rec_.date,temp_token[1]);
   	 			strcpy(final_time,temp_token[2]);
   	 			strcpy(final_date,temp_token[3]);

   	 			printf("start_time:%s\n",rec_.init_time);

	            strncpy(str,rec_.init_time,2);
                t_1->hours=atoi(str);
	            printf("hours_t_1: %d\n",t_1->hours);
	            reverse_string_1(rec_.init_time);
	            strncpy(str,rec_.init_time,2);
	            reverse_string_1(str);

	            t_1->minutes=atoi(str);
	            printf("minutes_t_1: %d\n",t_1->minutes);

                printf("end_time:%s\n",final_time);
 
	            strncpy(str,final_time,2);
	            printf("str:%s\n",str);
	            t_2->hours=atoi(str);
	            printf("hours_t_2: %d\n",t_2->hours);
	            reverse_string_1(final_time);
	            strncpy(str,final_time,2);
	            reverse_string_1(str);
	            t_2->minutes=atoi(str);
	            printf("minutes_t_2: %d\n", t_2->minutes);


   	 			/*strncpy(str_1,rec_.date,4);	
	            strncpy(str,str_1,2);
	            rec_date_day_1=atoi(str);
	            reverse_string_1(str_1);	            
	            strncpy(str,str_1,2);           
	            reverse_string_1(str);           
	            rec_date_month_1=atoi(str);

	            reverse_string_1(rec_.date);
	            strncpy(str_1,rec_.date,4);
	            reverse_string_1(str_1);
	            rec_date_year_1=atoi(str_1);
	        
	            d_1->day=rec_date_day_1;
	            d_1->month= rec_date_month_1;
	            d_1->year=rec_date_year_1;
	            printf("Date_1: day:%d month:%d year:%d\n",d_1->day, d_1->month, d_1->year);

                strncpy(str_1,final_date,4);	
	            strncpy(str,str_1,2);
	            rec_date_day_2=atoi(str);
	    
	            reverse_string_1(str_1);	            
	            strncpy(str,str_1,2);           
	            reverse_string_1(str);           
	            rec_date_month_2=atoi(str);
	         
	            reverse_string_1(final_date);
	            strncpy(str_1,rec_.date,4);
	            reverse_string_1(str_1);
	            rec_date_year_2=atoi(str_1);
	         
	            d_2->day=rec_date_day_2;
	            d_2->month= rec_date_month_2;
	            d_2->year=rec_date_year_2;*/
	            //printf("Date_2: day:%d month:%d year:%d\n",d_2->day, d_2->month, d_2->year);

   	 			find_cdrs_3_2(pinakas_2,mhash_size_2,rec_.destination_number,t_1,t_2,d_1,d_2);
   	 		}
   	 	}

   	 }else if(strcmp(token,"indist")==0){
     while(token!=NULL){
       token=strtok(NULL," ");
       if(token!=NULL){
           switch(i){
            case 0:
                strcpy(call_1,token);
              break;
          case 1: 
              strcpy(call_2,token);
              break;   
           }
       }else{
          break;
       }

      i++;
     } 
      indist(pinakas_1,pinakas_2,call_1,call_2,mhash_size_1,mhash_size_2);
     }else if(strcmp(token,"dump")==0){
      char* name;
      name=malloc(MAX_BUFF_SIZE);
     while(token!=NULL){
       token=strtok(NULL," ");
       if(token!=NULL){
           switch(i){
            case 0:
                strcpy(hash_t,token);
              break;
          case 1: 
              strcpy(name,token);
              break;   
           }
       }else{
          break;
       }

      i++;
     } 
     if(!strcmp(hash_t,"hashtable1")){
            FILE* out = fopen(name,"w");
            default_out=out;
            dump_1(pinakas_1,mhash_size_1,out);
            default_out=stdout;
            fclose(out);
      }else{
        FILE* out = fopen(name,"w");
        default_out=out;
        dump_2(pinakas_2,mhash_size_2,out); 
        default_out=stdout;
        fclose(out);
      }
     
     }else{
   	  puts("Wrong command\n");
   }

  }
}