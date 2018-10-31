#include "record.h"
#include "rest_of_caller_record.h"
#include <stdio.h>

struct bucket_record_2{
	char*  destination_number_2;
	struct second_buckets_of_nodes_2* deiktis;
	struct bucket_record_2* next_rec;

};
struct bucket_node_2{
 	int number_of_records;
 	struct bucket_record_2* First_rec;
 	struct bucket_node_2* next_buc;

 };

 struct buckets_of_nodes_2{
 	int number_of_buckets;
 	struct bucket_node_2* First_buc;
 
 };

 struct second_record_2{
 	rest_record_2* rec;
 	struct second_record_2* next_rec_2;

 };

 struct second_node_2{
 	int number_of_records_2;
 	struct second_record_2* First_rec_2;
 	struct second_node_2* next_buc_2;
 	
 };

 struct second_buckets_of_nodes_2{
 	int number_of_buckets_2;
 	struct second_node_2* First_buc_2;

 };

 /*TYPEDEFS*/

 typedef struct bucket_record_2 bucket_record_2;
 typedef struct bucket_node_2 bucket_node_2;
 typedef struct buckets_of_nodes_2* Buckets_2;
 typedef struct second_record_2 second_record_2;
 typedef struct second_node_2 second_node_2;
 typedef struct second_buckets_of_nodes_2* second_Buckets_2;


 /*SYNARTHSEIS*/

 bucket_record_2* create_record_2_new(record* r);
 bucket_record_2* create_record_2();
 bucket_node_2* create_node_2(void);
 Buckets_2 create_buckets_2(void);
 void print_all_from_bucket_2(Buckets_2 b);
 void dump_print_all_from_bucket_2(Buckets_2 b,FILE* out);
 void clean_buckets_2(Buckets_2 b);
 int size_of_buckets_2(Buckets_2 b);
 void insert_to_end_of_bucket_node_2(Buckets_2 b,bucket_record_2* r,int bucket_size_);
 bucket_record_2* search_bucket_2(Buckets_2 b,char* x);


 second_record_2* create_second_record_2();
 second_record_2* create_second_record_2_new(rest_record_2* rec_);
 second_node_2* create_second_node_2(void);
 second_Buckets_2 create_second_buckets_2(void);
 void print_all_from_first_second_2(second_Buckets_2 b);
 void dump_print_all_from_first_second_2(second_Buckets_2 b,FILE* out);
 void clean_second_buckets_2(second_Buckets_2 b);
 int size_of_second_buckets_2(second_Buckets_2 b);
 void insert_to_end_second_2(second_Buckets_2 b,second_record_2* r);
 second_record_2* second_search_bucket_2(second_Buckets_2 b,char* x);
 void print_recs_from_first_second_1_2(second_Buckets_2 b,char* start_time,char* end_time);
 void print_recs_from_first_second_2_2(second_Buckets_2 b,time* start_time,time* end_time,date* date_1,date* date_2);
 void top_dest_bucket_2(second_Buckets_2 b);
