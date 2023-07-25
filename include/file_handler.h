#pragma once
#include<fstream>
#include<string>
#include"Data_container.h"
using namespace std;


class file_handler
{
	fstream reservoir;

public:
	void write_file(Data_recieved&);
	void open_file(string);
	void confirm_file_open();
	void file_close();

};


