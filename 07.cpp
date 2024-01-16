#include "main.h"


#define BUF_SIZE 30
#define _WINSOCK_DEPRECATED_NO_WARNINGS
/*
int main(int argc, char* argv[])
{
	WSADATA wsadata;
	SOCKET hservsock, hclntsock;
	FILE* fp;
	char buf[BUF_SIZE];
	int readcnt;

	SOCKADDR_IN servAdr, clntAdr;
	int clntAdrsz;

	if (argc != 2)
	{
		cout << "usage : " << argv[0] << "\n";
		exit(1);
	}
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		cerr << "WSAStartup() error! \n";

	fopen_s(&fp,"file_server_win.c", "rb");
	hservsock = socket(PF_INET, SOCK_STREAM, 0);
	
	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAdr.sin_port = htons(atoi(argv[1]));

	bind(hservsock, (SOCKADDR*)&servAdr, sizeof(servAdr));
	listen(hservsock, 5);

	clntAdrsz = sizeof(clntAdr);
	hclntsock = accept(hservsock, (SOCKADDR*)&clntAdr, &clntAdrsz);

	while (1)
	{
		readcnt = fread((void*)buf, 1, BUF_SIZE, fp);
		if (readcnt < BUF_SIZE)
		{
			send(hclntsock, (char*)&buf, readcnt, 0);
			break;
		}
		send(hclntsock, (char*)&buf, readcnt, 0);
	}

	shutdown(hclntsock, 1); //1 = SD_SEND
	recv(hclntsock, (char*)buf, BUF_SIZE, 0);
	cout << "message from clinent : " << buf << "\n";

	fclose(fp);
	closesocket(hservsock), closesocket(hclntsock);
	WSACleanup();
	return 0;
}*/

/*
int main(int argc, char* argv[])
{
	WSADATA wsadata;
	SOCKET hsocket;
	FILE* fp;

	char buf[BUF_SIZE];
	int readcnt;

	SOCKADDR_IN servAdr;
	int clntAdrsz;

	if (argc != 3)
	{
		cout << "usage : " << argv[0] << "\n";
		exit(1);
	}
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		cerr << "WSAStartup() error! \n";

	fopen_s(&fp, "receive.dat", "wb");
	hsocket = socket(PF_INET, SOCK_STREAM, 0);

	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = inet_pton(AF_INET, argv[1], &servAdr.sin_addr);
	servAdr.sin_port = htonl(atoi(argv[2]));
	connect(hsocket, (SOCKADDR*)&servAdr, sizeof(servAdr));

	while ((readcnt = recv(hsocket, buf, BUF_SIZE, 0)) != 0)
		fwrite((void*)buf, 1, readcnt, fp);

	puts("Received file data");
	send(hsocket, "Thank you", 10, 0);
	fclose(fp);
	closesocket(hsocket);
	WSACleanup();
	return 0;
}*/