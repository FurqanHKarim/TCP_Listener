#pragma once

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <string>
#include <iostream>

using namespace std;

class TCP_client {
	WSAData wsaData;
	SOCKET client_socket;
	sockaddr_in server_address;
	PCSTR IP_address;
	

public:
	TCP_client(int,int, const char*);
	~TCP_client();
	int validate_WINSOCK();
	int validate_SOCKET();
	int validate_address();
	int est_connection();
	int recieve_message(char* , int);

	

};


///@brief for self understanding
//WSADATA wsa_date;//done
//if (WSAStartup(MAKEWORD(2, 2), &wsa_date) != 0) {
//	cout << "Error: Failed to initialze Winsock" << endl;
//	return 1;
//}


////Creating a Socket
//SOCKET client_socket = socket(AF_INET, SOCK_STREAM, 0);//done

//if (client_socket == INVALID_SOCKET) {
//	cout << "Error: Failed to create socket" << endl;
//	WSACleanup();
//	return 1;
//}

//// defining server initials
//sockaddr_in server_address;//done
//server_address.sin_family = AF_INET;// defining the connection type as TCP or UDP
//server_address.sin_port = htons(PORT); // defining my port
//
//if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
//	std::cerr << "Error: Invalid address specified" << std::endl;
//	return 1;
//}

////checking if the connection is valid
//if (connect(client_socket, (sockaddr*)&server_address, sizeof(server_address))) {
//	cout<<"Error: Connection failed"<<endl;
//		closesocket(client_socket);
//		WSACleanup();
//		return 1;
//}

////	//Closing socket
//closesocket(client_socket);
//
//// Cleanup winsock
//WSACleanup();