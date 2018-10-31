#include "calle_bucket.h"
#include <stdio.h>

typedef Buckets_2* hash_table_2;

 hash_table_2 create_hash_table_2(int size);
 void clean_hash_table_2(hash_table_2 table,int size);
 int hash_function_2(char* key,int size);
 void print_all_hash_table_2(hash_table_2 table,int size);
 void dump_print_all_hash_table_2(hash_table_2 table,int size,FILE* out);
 bucket_record_2* search_hash_table_2(hash_table_2 table,char* caller,int size);
 void delete_record_hash_table_2(hash_table_2 table,int size,char* caller,char* id);
 int insert_hash_table_2(hash_table_2 table,int size,record* rec,int bucket_size_);
