#include <iostream>

#ifdef _WIN32
#include <WinSock2.h>
#include <io.h> //���� ����� �� I/O �۾� (open,read . . .) 
#include <fcntl.h> //���� ���� �÷��� ����
#include <Ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib") // Link with the Winsock library
#define _CRT_SECURE_NO_WARNINGS
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#endif


using namespace std; 