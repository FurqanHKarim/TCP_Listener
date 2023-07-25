#pragma once
#include<iostream>

struct Data_recieved {
	uint64_t head;
	uint32_t miss;
	uint32_t lenght_txt;
	char TXT[1984];
	

	bool verifyData();
	void empty_buffer();
	void print_all();
};
