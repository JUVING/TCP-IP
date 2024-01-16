#include "main.h"

/*
void showsocketBufsize(SOCKET sock);

int main(int argc,char * argv[])
{
	WSADATA wsadata;
	SOCKET hsock;
	int sndBuf, rcvBuf, state;
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		cerr << "WSAStartup() error!\n";

	hsock = socket(PF_INET, SOCK_STREAM, 0);
	showsocketBufsize(hsock);
	sndBuf = 1024 * 3, rcvBuf = 1024 * 3;
	state = setsockopt(hsock, SOL_SOCKET, SO_SNDBUF, (char*)&sndBuf, sizeof(sndBuf));
	if (state == INVALID_SOCKET)
		cerr << "setsockopt() error!\n";

	state = setsockopt(hsock, SOL_SOCKET, SO_RCVBUF, (char*)&sndBuf, sizeof(rcvBuf));
	if (state == INVALID_SOCKET)
		cerr << "setsockopt() error!\n";

	showsocketBufsize(hsock);
	closesocket(hsock);
	return 0;
}

void showsocketBufsize(SOCKET sock)
{
	int sndBuf, rcvBuf, state, len;

	len = sizeof(sndBuf);
	state = getsockopt(sock, SOL_SOCKET, SO_SNDBUF, (char*)&sndBuf, &len);
	if (state == INVALID_SOCKET)
		cerr << "getsockopt() error!\n";

	len = sizeof(rcvBuf);
	state = getsockopt(sock, SOL_SOCKET, SO_RCVBUF, (char*)&rcvBuf, &len);
	if (state == INVALID_SOCKET)
		cerr << "setsockopt() error!\n";

	cout << "Input Buffer size : " << rcvBuf << "\n";
	cout << "Output Buffer size : " << sndBuf << "\n";
}*/