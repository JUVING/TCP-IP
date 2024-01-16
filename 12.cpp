#include "main.h"
/*
#define BUF_SIZE 1024

int main(int argc, char* argv[])
{
	WSADATA wsadata;
	SOCKET hservsock, hclntsock;
	SOCKADDR_IN servAdr, clntAdr;
	TIMEVAL timeout;
	fd_set reads, cpyReads;

	int adrsz;
	int strLen, fdNum, i;
	char buf[BUF_SIZE];

	if (argc != 2)
	{
		cout << "usage : " << argv[0] << "\n";
		exit(1);
	}
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		cerr << "WSAStartup() error! \n";

	hservsock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAdr.sin_port = htons(atoi(argv[1]));

	if (bind(hservsock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
		cerr << "bind() error! \n";
	if (listen(hservsock, 5) == SOCKET_ERROR)
		cerr << "listen() error! \n";

	FD_ZERO(&reads);
	FD_SET(hservsock, &reads);

	while (1)
	{
		cpyReads = reads;
		timeout.tv_sec = 5;
		timeout.tv_usec = 5000;

		if ((fdNum = select(0, &cpyReads, 0, 0, &timeout)) == SOCKET_ERROR)
			break;

		if (fdNum == 0)
			continue;

		for (i = 0; i < reads.fd_count; i++)
		{
			if (FD_ISSET(reads.fd_array[i], &cpyReads))
			{
				if (reads.fd_array[i] == hservsock)
				{
					adrsz = sizeof(clntAdr);
					hclntsock = accept(hservsock, (SOCKADDR*)&clntAdr, &adrsz);
					FD_SET(hservsock, &reads);
					cout << "connected client : " << hservsock << "\n";
				}
				else
				{
					strLen = recv(reads.fd_array[i], buf, BUF_SIZE - 1, 0);
					if (strLen == 0)
					{
						FD_CLR(reads.fd_array[i], &reads);
						closesocket(cpyReads.fd_array[i]);
						cout << "close client : " << cpyReads.fd_array[i] << "\n";
					}
					else
					{
						send(reads.fd_array[i], buf, strLen, 0);
					}
				}
			}
		}
	}
	closesocket(hservsock);
	WSACleanup();
	return 0;
}*/