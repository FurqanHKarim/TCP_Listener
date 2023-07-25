#ifndef _Data_container
#define _Data_container


#include<iostream>
#include"TCP_client.h"

struct Data_head {
	uint64_t head;
	uint32_t miss;
	uint32_t lenght_txt;

};
struct Data_recieved {
	Data_head head;
	char array[(buffer_size) - 16];
	
	bool verifyData();
	void empty_buffer();
	void print_all();
};

#endif // !_Data_container