#include "main.h"

#define TTL 64
#define BUF_SIZE 30
/*
int main(int argc, char* argv[])
{
	WSADATA wsadata;
	SOCKET hsendsock;
	SOCKADDR_IN mulAdr;
	int timeLive = TTL;
	FILE* fp;
	char buf[BUF_SIZE];

	if (argc != 3)
	{
		cout << "usage : " << argv[0] << "\n";
		exit(1);
	}
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		cerr << "WSAStartup() error! \n";

	hsendsock = socket(PF_INET, SOCK_DGRAM, 0);
	memset(&mulAdr, 0, sizeof(mulAdr));
	mulAdr.sin_family = AF_INET;
	mulAdr.sin_addr.s_addr = inet_addr(argv[1]);
	mulAdr.sin_port = htons(atoi(argv[2]));

	setsockopt(hsendsock, IPPROTO_IP,IP_MULTICAST_TTL,(void*)&timeLive,sizeof(timeLive));
	if ((fp = fopen("news.txt", "r")) == NULL)
		cerr << "fopen() error! \n";
	while (!feof(fp))
	{
		fgets(buf, BUF_SIZE, fp);
		sendto(hsendsock, buf, strlen(buf), 0, (SOCKADDR*)&mulAdr, sizeof(mulAdr));
		sleep(2000);
	}
	closesocket(hsendsock);
	WSACleanup();
	return 0;
}*/


int main(int argc, char* argv[])
{
	WSADATA wsadata;
	SOCKET hrecvsock;
	SOCKADDR_IN adr;
	struct ip_mreq joinAdr;
	char buf[BUF_SIZE];
	int strLen;

	if (argc != 3)
	{
		cout << "usage : " << argv[0] << "\n";
		exit(1);
	}
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		cerr << "WSAStartup() error! \n";

	hrecvsock = socket(PF_INET, SOCK_DGRAM, 0);
	memset(&adr, 0, sizeof(adr));
	adr.sin_family = AF_INET;
	adr.sin_addr.s_addr = inet_addr(argv[1]);
	adr.sin_port = htonl(INADDR_ANY);
	if (bind(hrecvsock, (SOCKADDR*)&adr, sizeof(adr)) == SOCKET_ERROR)
		cerr << "bind() error! \n";

	joinAdr.imr_multiaddr.s_addr = inet_addr(argv[1]);
	joinAdr.imr_interface.s_addr = htonl(INADDR_ANY);
	if(setsockopt(hrecvsock,IPPROTO_IP,IP_ADD_MEMBERSHIP,(void*)&joinAdr,sizeof(joinAdr))==SOCKET_ERROR)
		cerr<<"setsockopt() error! \n";
	
	while (1)
	{
		strLen = recvfrom(hrecvsock, buf, BUF_SIZE - 1, 0, NULL, 0);
		if (strLen < 0)
			break;
		buf[strLen] = 0;
		fputs(buf, stdout);
	}
	closesocket(hrecvsock);
	WSACleanup();
	return 0;
}