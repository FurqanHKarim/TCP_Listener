#include "TCP_client.h"


TCP_client::TCP_client( const int socket_type, const int PORT_NO, const char* IP) {
	int Connection_type = AF_INET;
	WSAStartup(MAKEWORD(2, 2), &(this->wsaData));
	IP_address = (PCSTR)IP;//defining IP address and initializing server_address.sin_addr.s_addr doesnt work
	//	this is initialized while validating


	//Creating a Socket
	client_socket = socket(Connection_type, socket_type, 0);
	if (client_socket == INVALID_SOCKET) {
		cout << "Error: Failed to create socket" << endl;
		WSACleanup();
		//return 1;
	}
	//validate_SOCKET();
	//defining server initials
	server_address.sin_family = Connection_type; // defining the connection type as TCP or UDP (AF_INET)
	server_address.sin_port = htons(PORT_NO);    // defining my port
	inet_pton(Connection_type, IP_address, &server_address.sin_addr);


}
TCP_client:: ~TCP_client() {
	//Closing socket
	closesocket(client_socket);

	// Cleanup winsock
	WSACleanup();
}

int  TCP_client::validate_WINSOCK() {

	if (WSAStartup(MAKEWORD(2, 2), &(this->wsaData)) != 0) {
		cout << "Error: Failed to initialze Winsock" << endl;
		return 1;
	}
}

int TCP_client::validate_SOCKET() {

	if (client_socket == INVALID_SOCKET) {
		cout << "Error: Failed to create socket" << endl;
		WSACleanup();
		return 1;
	}
}

int TCP_client::validate_address() {
	//needs to be checked
	if (inet_pton(AF_INET, IP_address, &server_address.sin_addr) <= 0) {
		std::cerr << "Error: Invalid address specified" << std::endl;
		return 1;
	}
}


int TCP_client::est_connection() {
	if (connect(client_socket, (sockaddr*)&server_address, sizeof(server_address))) {
		cout << "Error: Connection failed" << endl;
		closesocket(client_socket);
		WSACleanup();
		return 1;
	}
}

int TCP_client::recieve_message(char* buffer,int size) {

	return recv(client_socket, buffer, sizeof(buffer), 0);

}