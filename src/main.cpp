//Author Furqan Hameed Karim


#include <string>
#include <WinSock2.h>
#include <iostream>
#include <WS2tcpip.h>
#include <vector>
#include "TCP_client.h"
#include "Data_container.h"
#include <fstream>
#include "file_handler.h"

using namespace std;


#define PORT 9000
#define IP_ad   "127.0.0.1"

 int main() {


	TCP_client TCP_1(SOCK_STREAM, PORT, IP_ad); //2 ==AF_INET
	file_handler obj;
	Data_recieved *TCP_data;
	int bytes_recieved;
	int counter = 0;//just testing collect data till certain loops then exist the loop below


	TCP_data = (Data_recieved*)TCP_1.buffer;

	
	TCP_1.validate_WINSOCK();
	TCP_1.validate_SOCKET();
	TCP_1.validate_address();
	TCP_1.est_connection();

	//recieveing messages for the server
	obj.open_file("txt.json");
	obj.confirm_file_open();





	while (bytes_recieved = TCP_1.recieve_message((char*)TCP_data, buffer_size)) {
		
		TCP_data->verifyData();
		TCP_data->print_all();
		obj.write_file(*TCP_data);


		TCP_data->empty_buffer();
		counter++;
		if (counter > 5) {
			break;
		}
	}
	obj.file_close();




	return 0;


}
