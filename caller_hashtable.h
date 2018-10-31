#include "caller_bucket.h"
#include <stdio.h>

 typedef Buckets* hash_table;

 hash_table create_hash_table(int size);
 void clean_hash_table(hash_table table,int size);
 int hash_function(char* key,int size);
 void print_all_hash_table(hash_table table,int size);
 void dump_print_all_hash_table(hash_table table,int size,FILE* out);
 bucket_record_1* search_hash_table(hash_table table,char* caller,int size);
 void delete_record_hash_table(hash_table table,int size,char* caller,char* id);
 int insert_hash_table(hash_table table,int size,record* rec,int bucket_size_);

