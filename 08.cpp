#include "main.h"


/*
int main(int argc, char* argv[])
{
	WSADATA wsadata;
	int i;
	struct  hostent* host;
	if (argc != 2)
	{
		cout << "usage : " << argv[0] << "\n";
		exit(1);
	}
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		cerr << "WSAStarup() error! \n";

	host = gethostbyname(argv[1]);
	if (!host)
		cerr << "hostname.....error!\n";

	cout << "official name : " << host->h_name << "\n";
	for (i = 0; host->h_aliases[i]; i++)
		cout << "Aliases" << i + 1 << " " << host->h_aliases[i] << "\n";
	cout << "address type : " << ((host->h_addrtype == AF_INET)?"AF_INET":"AF_INET6") << "\n";
	for (i = 0; host->h_addr_list[i]; i++)
		cout << "IP addr : " << i + 1 << " " << inet_ntoa(*(struct in_addr*)host->h_addr_list[i]);
	WSACleanup();
	return 0;
}*/

/*
int main(int argc, char* argv[])
{
	WSADATA wsadata;
	int i;
	struct  hostent* host;
	SOCKADDR_IN addr;
	if (argc != 2)
	{
		cout << "usage : " << argv[0] << "\n";
		exit(1);
	}
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		cerr << "WSAStarup() error! \n";

	memset(&addr, 0, sizeof(addr));
	addr.sin_addr.s_addr = inet_addr(argv[1]);
	host = gethostbyaddr((char*)&addr.sin_addr, 4, AF_INET);
	if (!host)
		cerr << "gethost...error!\n";

	cout << "official name : " << host->h_name<<"\n";
	for (i = 0; host->h_aliases[i]; i++)
		cout << "Aliases" << i + 1 << " " << host->h_aliases[i] << "\n";
	cout << "address type : " << ((host->h_addrtype == AF_INET) ? "AF_INET" : "AF_INET6") << "\n";
	for (i = 0; host->h_addr_list[i]; i++)
		cout << "IP addr : " << i + 1 << " " << inet_ntoa(*(struct in_addr*)host->h_addr_list[i]);
	WSACleanup();
	return 0;
}*/