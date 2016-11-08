#pragma comment(lib, "Ws2_32.lib")
 
#include <stdio.h>
#include <stdlib.h>
//#include <WinSock2.h>
#include <Windows.h>
#include <conio.h>
 
#define PORT 9000
#define IP "127.0.0.1"
 
int isEnd = 0;
CRITICAL_SECTION hCS;
 
DWORD WINAPI rcvMessage(LPVOID arg) {
    int sock = (int)arg;
    char rcvBuffer[BUFSIZ];
 
    while (1) {
        if (recv(sock, rcvBuffer, sizeof(rcvBuffer), 0) > 0) {
            printf("%s\n", rcvBuffer);
        }
 
        EnterCriticalSection(&hCS);
        if (isEnd == 1) break;
        LeaveCriticalSection(&hCS);
    }
}
 
DWORD WINAPI sendMessage(LPVOID arg){
    int sock = (int)arg;
    char sendBuffer[BUFSIZ];
    char tmp[380];
    char name[128];
 
    printf("Name : ");
    fgets(name, 127, stdin);
    name[strlen(name) - 1] = '\0';
    sprintf(sendBuffer, "%s log in", name);
    send(sock, sendBuffer, sizeof(sendBuffer), 0);
 
    while (1) {
        fgets(tmp, 380, stdin);
        tmp[strlen(tmp) - 1] = '\0';
        if (!strcmp(tmp, "quit")) {
            sprintf(sendBuffer, "quit / %s log out", name);
            send(sock, sendBuffer, sizeof(sendBuffer), 0);
 
            EnterCriticalSection(&hCS);
            isEnd = 1;
            LeaveCriticalSection(&hCS);
 
            break;
        }
        else {
            sprintf(sendBuffer, "%s : %s", name, tmp);
            send(sock, sendBuffer, sizeof(sendBuffer), 0);
        }
    }
}
 
void main() {
    WSADATA wsadata;
    struct sockaddr_in conn_addr;
    int connSock;
 
    HANDLE hSendThread;
    HANDLE hRecvThread;
    DWORD hSendId;
    DWORD hRecvId;
 
    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) {
        printf("WSAStartup error");
        return;
    }
 
    connSock = socket(PF_INET, SOCK_STREAM, 0);
 
    memset(&conn_addr, 0, sizeof(conn_addr));
    conn_addr.sin_addr.s_addr = inet_addr(IP);
    conn_addr.sin_family = AF_INET;
    conn_addr.sin_port = htons(PORT);
 
    if (connect(connSock, (struct sockaddr *)&conn_addr, sizeof(conn_addr)) == -1) {
        printf("connect error");
        return;
    }
 
    InitializeCriticalSection(&hCS);
 
    hSendThread = _beginthreadex(NULL, 0, sendMessage, (LPVOID)connSock, 0, &hSendId);
    hRecvThread = _beginthreadex(NULL, 0, rcvMessage, (LPVOID)connSock, 0, &hRecvId);
    WaitForSingleObject(hSendThread, INFINITE);
    WaitForSingleObject(hRecvThread, INFINITE);
 
    DeleteCriticalSection(&hCS);
 
    closesocket(connSock);
    WSACleanup();
}
[출처] C언어 - 멀티 채팅 클라이언트|작성자 revsic

