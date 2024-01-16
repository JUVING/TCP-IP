#include "main.h"


#define BUF 1024

/*
int main(int argc, char *argv[])
{
	WSADATA wsadata;
	SOCKET hservsock, hclntsock;
	char message[BUF];
	int strlen, i;

	SOCKADDR_IN servaddr, clntaddr;
	int clntadrsize;

	if (argc != 2)
	{
		cout << "usage : " << argv[0] << "\n";
		exit(1);
	}

	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		cout << "WSAstartup() error !\n";

	hservsock = socket(PF_INET, SOCK_STREAM, 0);
	if (hservsock == INVALID_SOCKET)
		cout << "socket() error !\n";

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(atoi(argv[1]));

	if (bind(hservsock, (SOCKADDR*)&servaddr, sizeof(servaddr)) == SOCKET_ERROR)
		cout << "bind() error ! \n";

	clntadrsize = sizeof(clntaddr);

	for (i = 0; i < 5; i++)
	{
		hclntsock = accept(hservsock, (SOCKADDR*)&clntaddr, &clntadrsize);
		if (hclntsock == -1)
			cout << "accept error! \n";
		else
			cout << "connected error! \n";
		while ((strlen = recv(hservsock, message, BUF, 0)) != 0)
			send(hclntsock, message, strlen, 0);

		closesocket(hservsock);
	}
	closesocket(hservsock);
	WSACleanup();
	return 0;
}*/


/*
int main(int argc, char* argv[])
{
	WSADATA wsadata;
	SOCKET hservsock;
	char message[BUF];
	int strLen;
	SOCKADDR_IN servaddr;

	if (argc != 3)
	{
		cout << "usage : " << argv[0] << "\n";
		exit(1);
	}
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		cout << "WSAstartup() error !\n";

	hservsock = socket(PF_INET, SOCK_STREAM, 0);
	if (hservsock == INVALID_SOCKET)
		cout << "socket() error !\n";

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	servaddr.sin_port = htons(atoi(argv[2]));

	if (connect(hservsock, (SOCKADDR*)&servaddr, sizeof(servaddr)) == SOCKET_ERROR)
		cout << "connected error! \n";
	else
		puts("connected......");

	while (1)
	{
		fputs("Input message(Q to quit): ", stdout);
		fgets(message, BUF, stdin);

		if (!strcmp(message, "q\n") || !strcmp(message, "Q\n"))
			break;

		send(hservsock, message, strlen(message), 0);
		strLen = recv(hservsock, message, BUF - 1, 0);
		message[strLen] = 0;
		cout << "message from server: " << message << "\n";
	}
	closesocket(hservsock);
	WSACleanup();
	return 0;
}*/