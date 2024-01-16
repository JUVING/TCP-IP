#include "main.h"


#define BUF_SIZE 1024
#define RLT_SIZE 4
#define OPSZ 4

/*
int main(int argc, char* argv[])
{
	WSADATA wsadata;
	SOCKET hsocket;
	char opmsg[BUF_SIZE];
	int result, opndcnt, i;
	SOCKADDR_IN servAdr;

	if (argc != 3)
	{
		cout << "USAGE : " << argv[0] << "\n";
		exit(1);
	}

	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		cerr << "WSAStartup() error! \n";

	hsocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hsocket == INVALID_SOCKET)
		cerr << "socket() error! \n";

	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = PF_INET;
	servAdr.sin_addr = inet_addr(argv[1]);
	servAdr.sin_port = htons(atoi(argv[2]));

	if (connect(hsocket, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
		cerr << "connect() error!\n";
	else
		puts("connected.....");

	fputs("Operand count: ", stdout);
	cin >> opndcnt;
	opmsg[0] = (char)opndcnt;

	for (i = 0; i < opndcnt; i++)
	{
		cout << "operand count : " << i + 1<<"\n";
		cin >> opmsg[i * OPSZ + 1];
	}
	fgetc(stdin);
	fputs("operator: ", stdout);
	cin >> opmsg[opndcnt * OPSZ + 1];
	send(hsocket, opmsg, opndcnt * OPSZ + 2, 0);
	recv(hsocket, &result, RLT_SIZE, 0);

	cout << "operation result : " << result << "\n";
	closesocket(hsocket);
	WSACleanup();
	return 0;
}*/

/*
int calculate(int opnum, int opnds[], char oprator);
int main(int argc, char* argv[])
{
	WSADATA wsadata;
	SOCKET hservsock, hclntsock;
	char opinfo[BUF_SIZE];
	int result, opndcnt, i;
	int recvcnt, recvLen;
	SOCKADDR_IN servAdr,clntAdr;
	int clntAdrsize;

	if (argc != 2)
	{
		cout << "USAGE : " << argv[0] << "\n";
		exit(1);
	}

	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		cerr << "WSAStartup() error! \n";

	hservsock = socket(PF_INET, SOCK_STREAM, 0);
	if (hservsock == INVALID_SOCKET)
		cerr << "socket() error! \n";

	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = PF_INET;
	servAdr.sin_addr = htonl(INADDR_ANY);
	servAdr.sin_port = htons(atoi(argv[1]));

	if (bind(hservsock, (SOCKADDR*)&wsadata, sizeof(servAdr)) == SOCKET_ERROR)
		cerr << "bind() error! \n";

	if(listen(hservsock,5)==SOCKET_ERROR)
		cerr<<"listen() error! \n";

	clntAdrsize = sizeof(clntAdr);

	for (i = 0; i < 5; i++)
	{
		opndcnt = 0;
		hclntsock = accept(hservsock, (SOCKADDR*)&clntAdr, &clntAdrsize);
		recv(hclntsock, &opndcnt, 1, 0);
		while ((opndcnt * OPSZ + 1) > recvLen)
		{
			recvLen = recv(hclntsock, &opinfo[recvLen], BUF_SIZE - 1, 0);
			recvLen += recvcnt;
		}
		result = calculate(opndcnt, (int*)opinfo, opinfo[recvLen - 1]);
		send(hclntsock, (char*)&result, sizeof(result), 0);
		closesocket(hservsock);
	}
	closesocket(hservsock);
	WSACleanup();
	return 0;
}
int calculate(int opnum, int opnds[], char op)
{
	int result = opnds[0], i;

	switch (op)
	{
	case '+':
		for (i = 1; i < opnum; i++) result += opnds[i];
		break;
	case '-':
		for (i = 1; i < opnum; i++) result -= opnds[i];
		break;
	case '*':
		for (i = 1; i < opnum; i++) result *= opnds[i];
		break;
	}
	return result;
}*/