//Author Furqan Hameed Karim


#include <string>
#include <WinSock2.h>
#include <iostream>
#include <WS2tcpip.h>
#include <vector>
#include "TCP_client.h"
#include "Data_container.h"
using namespace std;

#define PORT 9000
#define IP_ad   "127.0.0.1"

int main() {

	
	TCP_client TCP_1(SOCK_STREAM,PORT,IP_ad); //2 ==AF_INET
	TCP_1.validate_WINSOCK();
	TCP_1.validate_SOCKET();
	TCP_1.validate_address();
	TCP_1.est_connection();

	
	//recieveing messages for the server
	char buffer[2000] = { 0 };
	char dumb[2000] = { 0 };

	int bytes_recieved;
	Data_recieved hello;
	
	while(bytes_recieved = TCP_1.recieve_message(buffer, sizeof(buffer))>0){




		copy(buffer, buffer + sizeof(hello), (char*) &hello);
		
		cout << "Start of message in norm head in norm: " << hello.head << endl;
		cout << "Start of message in norm head in hex : " << std::hex << hello.head<< endl;
		
		cout << "Start of message in norm: " << hello.lenght_txt << endl;
		cout << "Start of message in norm16: " << std:: dec<<hello.lenght_txt << endl;
		


		cout << "Recieved message: " << (uint64_t*)dumb << endl;
		cout << "ustad Rao ka kamal: " << buffer << endl;


		cout << endl;
		for (int i = 0; i < sizeof(buffer); i++)
		{
			cout << buffer[i];

		}
		cout << endl;
		//memset(buffer, 0, sizeof(buffer));
	}
	
	//memset(buffer, 0, sizeof(buffer));




	return 0;

}
