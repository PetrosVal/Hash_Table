#ifndef _REST_CALLER_RECORD_
#define _REST_CALLER_RECORD_

 typedef  struct rest_of_caller_record{
	char cdr_uniq_id_1[15];
    char destination_number_1[20];
    char date_1[10];
    char init_time_1[10];
    int duration_1;
    int type_1;
    int tarrif_1;
    char fault_condition_1[30];

}rest_record_1;


typedef struct rest_of_calle_record{
	char cdr_uniq_id_2[15];
	char originator_number_2[20];
	char date_2[10];
	char init_time_2[10];
	int duration_2;
	int type_2;
	int tarrif_2;
	char fault_condition_2[30];

}rest_record_2;


#endif