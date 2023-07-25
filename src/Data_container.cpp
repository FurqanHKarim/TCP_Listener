
#include "Data_container.h"
#include <iostream>
using namespace std;



void Data_recieved::print_all() {
	cout << endl;
	char* buffer;
	buffer = (char*)this;
	cout << "Start of the text: " << hex << head.head << dec << endl;
	for (int i = 0; i < this->head.lenght_txt+16; i++)
	{
		cout << buffer[i];
	}
	cout << endl;
}

bool Data_recieved::verifyData() {
	char stop = 'h';
	int lenght = 0;
	for (int i = 0; stop != '\0'; i++) {
		stop = array[i];
		if (i > head.lenght_txt) {
			//cout << "Message not recieved Properly: Disregarded" << endl;
			return 1;
		}
		lenght = i;

	}
	return 0;

}

void Data_recieved::empty_buffer() {
	fill(this, this + 1, Data_recieved{0});
}

