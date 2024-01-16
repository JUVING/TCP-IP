#include "main.h"

#define BUF_SIZE 30
/*
int main(int argc, char* argv[])
{
	WSADATA wsadata;
	SOCKET servsock;
	char message[BUF_SIZE];
	int strLen, clntAdrsz;

	SOCKADDR_IN servAdr, clntAdr;
	if (argc != 2)
	{
		cout << "usage : " << argv[0] << "\n";
		exit(1);
	}
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		cerr << "WSAStartup() error!\n";

	servsock = socket(PF_INET, SOCK_DGRAM, 0);
	if (servsock == INVALID_SOCKET)
		cerr << "socket() error!\n";

	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAdr.sin_port = htonl(atoi(argv[1]));

	if (bind(servsock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
		cerr << "bind() error! \n";

	while (1)
	{
		clntAdrsz = sizeof(clntAdr);
		strLen = recvfrom(servsock, message, BUF_SIZE, 0, (SOCKADDR*)&clntAdr, &clntAdrsz);
		sendto(servsock, message, strLen, 0, (SOCKADDR*)&clntAdr, sizeof(clntAdr);
	}
	closesocket(servsock);
	WSACleanup();
	return 0;
}*/

/*
#define _WINSOCK_DEPRECATED_NO_WARNINGS

int main(int argc, char* argv[])
{
	WSADATA wsadata;
	SOCKET sock;
	char message[BUF_SIZE];
	int strLen;

	SOCKADDR_IN servAdr;
	if (argc != 3)
	{
		cout << "usage : " << argv[0] << "\n";
		exit(1);
	}
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		cerr << "WSAStartup() error!\n";

	sock = socket(PF_INET, SOCK_DGRAM, 0);
	if (sock == INVALID_SOCKET)
		cerr << "socket() error!\n";

	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = inet_pton(AF_INET, argv[1], &servAdr.sin_addr);
	servAdr.sin_port = htonl(atoi(argv[2]));
	connect(sock, (SOCKADDR*)&servAdr, sizeof(servAdr));

	while(1)
	{
		fputs("insert message(q to quit : ", stdout);
		fgets(message, sizeof(message), stdin);
		if (!strcmp(message, "q/n") || !strcmp(message, "Q/n"))
			break;

		send(sock, message, strlen(message), 0);
		strLen = recv(sock, message, sizeof(message) - 1, 0);
		message[strLen] = 0;
		cout << "message from server : " << message << "\n";
	}
	closesocket(sock);
	WSACleanup();
	return 0;
}*/
