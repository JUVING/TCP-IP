#include "main.h"


/*
//85pg
int main(int argc, char* argv[])
{
	WSADATA wsadata;
	unsigned short host_port = 0x1234;
	unsigned short net_port;
	unsigned long host_addr = 0x12345678;
	unsigned long net_addr;

	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		cerr << "WSAStartup() error\n";

	net_port = htons(host_port);
	net_addr = htonl(host_addr);

	cout << "호스트 포트 : " << host_port << "\n네트워크 포트 : " << net_port;
	cout<< "\n\n호스트 주소 : " << host_addr << "\n네트워크 주소 : " << net_addr;

	WSACleanup();
	return 0;
}*/


/*
//86pg
int main(int argc, char* argv[])
{
    WSADATA wsadata;
    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
        std::cerr << "WSAStartup() error\n";

    {
        const char* addr = "127.214.124.78";
        sockaddr_in sockaddr;
        InetPtonA(AF_INET, addr, &(sockaddr.sin_addr)); //#include <Ws2tcpip.h>
        std::cout << "addr : " << sockaddr.sin_addr.s_addr << "\n";
    }

    {
        struct sockaddr_in addr;
        char strarr[20];

        addr.sin_addr.s_addr = htonl(0x1020304);
        InetNtopA(AF_INET, &(addr.sin_addr), strarr, sizeof(strarr)); //#include <Ws2tcpip.h>
        std::cout << "DDn: " << strarr;
    }

    WSACleanup();
    return 0;
}*/


/*
* //89pg
int main(int argc, char* argv[])
{
    const char *straddr = "203.211.218.102:9190";
    char straddrBuf[50];

    SOCKADDR_IN servaddr;
    int size;

    WSADATA wsadata;
    WSAStartup(MAKEWORD(2, 2), &wsadata);

    size = sizeof(servaddr);
    WSAStringToAddress(straddr, AF_INET, NULL, (SOCKADDR*)&servaddr, &size);
    size = sizeof(straddrBuf);
    WSAAddressToString((SOCKADDR*)&servaddr, sizeof(servaddr), NULL, straddrBuf, &size);

    cout << "result : " << straddrBuf << "\n";
    WSACleanup();
    return 0;
}*/