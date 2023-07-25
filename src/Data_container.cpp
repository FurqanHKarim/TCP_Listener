
#include "Data_container.h"
#include <iostream>
using namespace std;

void Data_recieved::print_all() {
	cout << endl;
	char* buffer;
	buffer = (char*)this;
	for (int i = 0; i < this->lenght_txt+16; i++)
	{
		cout << buffer[i];
	}
	cout << endl;
}

bool Data_recieved::verifyData() {
	char stop = 'h';
	int lenght = 0;
	for (int i = 0; stop != '\0'; i++) {
		stop = TXT[i];
		if (i > lenght_txt) {
			//cout << "Message not recieved Properly: Disregarded" << endl;
			return 1;
		}
		lenght = i;

	}
	return 0;



}

void Data_recieved::empty_buffer() {
	fill(this, this + 1, Data_recieved{ 0 });
}

