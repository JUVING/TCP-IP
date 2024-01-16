#include <iostream>

#ifdef _WIN32
#include <WinSock2.h>
#include <io.h> //파일 입출력 및 I/O 작업 (open,read . . .) 
#include <fcntl.h> //파일 제어 플래그 지원
#include <Ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib") // Link with the Winsock library
#define _CRT_SECURE_NO_WARNINGS
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#endif


using namespace std; 