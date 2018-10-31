#ifndef _RECORD_
#define _RECORD_

typedef struct record{

	char cdr_uniq_id[15];
	char originator_number[20];
	char destination_number[20];
	char date[10];
	char init_time[10];
	int duration;
	int type;
	int tarrif;
	char fault_condition[30];

}record;

typedef struct date{
	int day;
	int month;
	int year;

}date;

typedef struct time{
	int hours;
	int minutes;

}time;


#endif