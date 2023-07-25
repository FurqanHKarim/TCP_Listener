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
	int recieve_message(char*,int);

	

};


