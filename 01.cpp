#include "main.h"


/*
//30pg
int main() {
    int fd;
    char buf[] = "Let`s go!\n";

    if (_sopen_s(&fd, "data.txt", _O_CREAT | _O_WRONLY | _O_TRUNC, _SH_DENYNO, _S_IWRITE) != 0)
        std::cerr << "_sopen_s() error\n";
    else {
        std::cout << "file descriptor: " << fd << "\n";

        if (_write(fd, buf, sizeof(buf)) == -1)
            std::cerr << "write() error\n";

        _close(fd);
    }

    return 0;
}*/


/*
//32pg
#define BUF_SIZE 100
int main(void)
{
    int fd;
    char buf[BUF_SIZE];

    if (_sopen_s(&fd, "data.txt", _O_RDONLY, _SH_DENYNO, _S_IREAD) == 0)
    {
        std::cout << "file descriptor: " << fd << "\n";

        int bytesRead = _read(fd, buf, sizeof(buf) - 1);

        if (bytesRead == -1)
            std::cerr << "read() error\n";
        else
        {
            buf[bytesRead] = '\0';
            std::cout << "file data : " << buf << "\n";
        }

        _close(fd);
    }
    else
    {
        std::cerr << "_sopen_s() error\n";
    }

    return 0;
}*/


/*
//41pg
int main(int argc, char* argv[])
{
    WSADATA wsadata;
    SOCKET hservsock, hclntsock;
    SOCKADDR_IN servAddr, clntAddr;

    int szclntAddr;
    char message[] = "Hello word!";
    if (argc != 2)
    {
        cout << "Usage : " << argv[0] << "port\n";
        exit(1);
    }

    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
        cerr << "WSAstartup() error!\n";

    hservsock = socket(PF_INET, SOCK_STREAM, 0);
    if (hservsock == INVALID_SOCKET)
        cerr << "socket() error!\n";

    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY); //IP주소를 설정하는 부분으로 htol은 호스트 바이트 순서를 
                                                  //네트워크 바이트 순서로 변환한다. INADDR_ANY는모든 IP주소를 수락한다.

    servAddr.sin_port = htons(atoi(argv[1])); //PORT번호를 구성하고 htons는 호스트 바이트 순서를 네트워크 순서로 변환

    if (bind(hservsock, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
        cerr << "bind() error!\n";

    if (listen(hservsock, 5) == SOCKET_ERROR)
        cerr << "listen() error!\n";

    szclntAddr = sizeof(clntAddr);
    hclntsock = accept(hservsock, (SOCKADDR*)&clntAddr, &szclntAddr);

    if (hclntsock == INVALID_SOCKET)
        cerr << "accept() error!\n";

    send(hclntsock, message, sizeof(message), 0);
    closesocket(hclntsock);
    closesocket(hservsock);
    WSACleanup();
    return 0;
}


int main(int argc, char* argv[])
{
    WSADATA wsadata;
    SOCKET hsocket;
    SOCKADDR_IN servAddr;

    int szclntAddr;
    char message[30];
    int strLen;
    if (argc != 2)
    {
        cout << "Usage : " << argv[0] << "port\n";
        exit(1);
    }

    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
        cerr << "WSAstartup() error!\n";

    hsocket = socket(PF_INET, SOCK_STREAM, 0);
    if (hsocket == INVALID_SOCKET)
        cerr << "socket() error!\n";

    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY); //IP주소를 설정하는 부분으로 htol은 호스트 바이트 순서를 
                                                  //네트워크 바이트 순서로 변환한다. INADDR_ANY는모든 IP주소를 수락한다.

    servAddr.sin_port = htons(atoi(argv[1])); //PORT번호를 구성하고 htons는 호스트 바이트 순서를 네트워크 순서로 변환

    if (connect(hsocket, (SOCKADDR*)&hsocket, sizeof(hsocket) == SOCKET_ERROR))
        cerr << "connect error!\n";

    strLen = recv(hsocket, message, sizeof(message) - 1, 0);
    closesocket(hsocket);
    WSACleanup();
    return 0;
}*/
