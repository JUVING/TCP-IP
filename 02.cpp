#include "main.h"
/*
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <ws2tcpip.h>
int main(int argc, char *argv[])
{
	WSADATA wsadata;
	SOCKET hsocket;
	SOCKADDR_IN servAddr;

	char message[30];
	int strLen = 0;
	int idx = 0, readlen = 0;

	if (argc != 3)
	{
		cout << "USAGE : " << argv[0] << " <PORT>\n";
		exit(1);
	}
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		cerr << "WSAstartup() error!\n";

	hsocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hsocket == INVALID_SOCKET)
		cerr << "socket() error!\n";

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_pton(AF_INET, argv[1], &(servAddr.sin_addr));

	servAddr.sin_port = htons(atoi(argv[2])); //PORT번호를 구성하고 htons는 호스트 바이트 순서를 네트워크 순서로 변환

	if (connect(hsocket, (SOCKADDR*)&hsocket, sizeof(hsocket) == SOCKET_ERROR))
		cerr << "connect error!\n";

	while (readlen = recv(hsocket, &message[idx++], 1, 0))
	{
		if (readlen == -1)
			cerr << "read() error!";

		strLen += readlen;
	}

	cout << "Message from server : " << message << "\n";
	cout << "fungtion read callcount : " << strLen << "\n";

	closesocket(hsocket);
	WSACleanup();
	return 0;
}*/