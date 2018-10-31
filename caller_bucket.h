#include "record.h"
#include "rest_of_caller_record.h"
#include <stdio.h>


struct bucket_record_1{
	char* originator_number_1;
	struct second_buckets_of_nodes* deiktis;
	struct bucket_record_1* next_rec;

};
 
 struct bucket_node_1{
 	int number_of_records;
 	struct bucket_record_1* First_rec;
 	struct bucket_node_1* next_buc;

 };

 struct buckets_of_nodes_1{
 	int number_of_buckets;
 	struct bucket_node_1* First_buc;
 
 };

 struct second_record_1{
 	rest_record_1* rec;
 	struct second_record_1* next_rec_2;

 };

 struct second_node_1{
 	int number_of_records_2;
 	struct second_record_1* First_rec_2;
 	struct second_node_1* next_buc_2;
 	
 };

 struct second_buckets_of_nodes{
 	int number_of_buckets_2;
 	struct second_node_1* First_buc_2;

 };

/*TYPEDEFS*/

 typedef struct bucket_record_1 bucket_record_1;
 typedef struct bucket_node_1 bucket_node_1;
 typedef struct buckets_of_nodes_1* Buckets;
 typedef struct second_record_1 second_record_1;
 typedef struct second_node_1 second_node_1;
 typedef struct second_buckets_of_nodes* second_Buckets;

/*SYNARTHSEIS*/
 bucket_record_1* create_record_1_new(record* r);
 bucket_record_1* create_record_1();
 bucket_node_1* create_node_1(void);
 Buckets create_buckets(void);
 void print_all_from_bucket(Buckets b);
 void dump_print_all_from_bucket(Buckets b,FILE* out );
 void clean_buckets(Buckets b);
 int size_of_buckets(Buckets b);
 void insert_to_end_of_bucket_node(Buckets b,bucket_record_1* r,int bucket_size_);
 bucket_record_1* search_bucket(Buckets b,char* x);


 second_record_1* create_second_record_1();
 second_record_1* create_second_record_1_new(rest_record_1* rec_);
 second_node_1* create_second_node_1(void);
 second_Buckets create_second_buckets(void);
 void print_all_from_first_second(second_Buckets b);
 void dump_print_all_from_first_second(second_Buckets b,FILE* out);
 void clean_second_buckets(second_Buckets b);
 int size_of_second_buckets(second_Buckets b);
 void insert_to_end_second(second_Buckets b,second_record_1* r);
 second_record_1* second_search_bucket(second_Buckets b,char* x);
 void print_recs_from_first_second_1(second_Buckets b,char* start_time,char* end_time);
 void print_recs_from_first_second_2(second_Buckets b,time* start_time,time* end_time,date* date_1,date* date_2);
 void top_dest_bucket(second_Buckets b);




 


