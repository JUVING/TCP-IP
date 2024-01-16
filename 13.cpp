#include "main.h"

#define BUF_SIZE 30
/*
int main(int argc, char* argv[])
{
	WSADATA wsadata;
	SOCKET hsocket;
	SOCKADDR_IN sendadr;
	if (argc != 3)
	{
		cout << "usage : " << argv[0] << "\n";
		exit(1);
	}
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		cerr << "WSAStartup() error! \n";

	hsocket = socket(PF_INET, SOCK_STREAM, 0);
	memset(&sendadr, 0, sizeof(sendadr));
	sendadr.sin_family = AF_INET;
	sendadr.sin_addr.s_addr = inet_addr(argv[1]);
	sendadr.sin_port = htons(atoi(argv[2]));

	if (connect(hsocket, (SOCKADDR*)&sendadr, sizeof(sendadr)) == SOCKET_ERROR)
		cerr << "connect() error\n";

	send(hsocket, "123", 3, 0);
	send(hsocket, "4", 1, MSG_OOB);
	send(hsocket, "567", 3, 0);
	send(hsocket, "890", 3, MSG_OOB);

	closesocket(hsocket);
	WSACleanup();
	return 0;
}

int main(int argc, char* argv[])
{
	WSADATA wsadata;
	SOCKET hacpsock,hrecvsock;
	SOCKADDR_IN sendadr,recvadr;
	int sendadrsize, strLen;
	char buf[BUF_SIZE];
	int result;

	fd_set read, except, readcopy, exceptcopy;
	struct timeval timeout;

	if (argc != 2)
	{
		cout << "usage : " << argv[0] << "\n";
		exit(1);
	}
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		cerr << "WSAStartup() error! \n";

	hacpsock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&recvadr, 0, sizeof(recvadr));
	sendadr.sin_family = AF_INET;
	sendadr.sin_addr.s_addr = htonl(INADDR_ANY);
	sendadr.sin_port = htons(atoi(argv[2]));

	if (bind(hacpsock, (SOCKADDR*)&recvadr, sizeof(recvadr)) == SOCKET_ERROR)
		cerr << "bind() error\n";
	if (listen(hacpsock, 5) == SOCKET_ERROR)
		cerr << "listen() error\n";
	sendadrsize = sizeof(sendadr);
	hrecvsock = accept(hacpsock, (SOCKADDR*)&sendadr, &sendadrsize);
	FD_ZERO(&read);
	FD_ZERO(&except);
	FD_SET(hrecvsock,&read);
	FD_SET(hrecvsock,&except);

	while (1)
	{
		readcopy = read;
		exceptcopy = except;
		timeout.tv_sec = 5;
		timeout.tv_usec = 0;

		result = select(0, &readcopy, 0, &exceptcopy, &timeout);

		if (result > 0)
		{
			if (FD_ISSET(hrecvsock, &exceptcopy))
			{
				strLen = recv(hrecvsock, buf, BUF_SIZE - 1, MSG_OOB);
				buf[strLen] = 0;
				cout << "Urgent message : " << buf << "\n";
			}
			if (FD_ISSET(hrecvsock, &readcopy))
			{
				strLen = recv(hrecvsock, buf, BUF_SIZE - 1, MSG_OOB);
				if (strLen == 0)
				{
					break;
					closesocket(hrecvsock);
				}
				else
				{
					buf[strLen] = 0;
					puts(buf);
				}
				
			}
		}
	}
	closesocket(hacpsock);
	WSACleanup();
	return 0;
}*/
