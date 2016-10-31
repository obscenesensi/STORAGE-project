#include<stdio.h>
#include<winsock2.h>
#include<conio.h>

#pragma comment(lib,"ws2_32.lib")

void main()
{
	WSADATA wsaData;
	SOCKET s, cs;
	struct sockaddr_in sin;
	struct sockaddr_in cli_addr;
	int size = sizeof(cli_addr);
	int nTimeOut = 200;
	char buff[1000], data[1000];
	char ID[100];
	int ret;

	if (WSAStartup(WINSOCK_VERSION, &wsaData) != 0)
	{
		printf("WSAStartup 실패, 에러코드 = %d \n", WSAGetLastError());
		return;
	}

	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);


	if (s == INVALID_SOCKET)
	{
		printf("소켓 생성 실패, 에러코드 = %d \n", WSAGetLastError());
		WSACleanup(); return;
	}



	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = htonl(ADDR_ANY);
	sin.sin_port = htons(10000);


	if (bind(s, (struct sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR)

	{
		printf("바인드 실패, 에러코드 = %d \n", WSAGetLastError());
		closesocket(s); WSACleanup(); return;
	}

	if (listen(s, SOMAXCONN) != 0)
	{
		printf("리슨모드 설정실패, 에러코드= %d \n", WSAGetLastError());
		closesocket(s); WSACleanup(); return;

	}

	puts("채팅서버를 시작합니다.");

	cs = accept(s, (struct sockaddr*)&cli_addr, &size);

	if (cs == INVALID_SOCKET)

	{
		printf("접속승인실패, 에러코드 = %d \n", WSAGetLastError());
		closesocket(s); WSACleanup(); return;
	}
	printf("채팅에 사용할 별명 : ");
	gets(ID);
	puts("메시지를 입력:");
	size = sizeof(int);
	setsockopt(cs, SOL_SOCKET, SO_RCVTIMEO, (char*)&nTimeOut, size);



	while (1)
	{
		if (kbhit())
		{
			gets(buff);
			if (strcmp(buff, "END") == 0)
			{
				send(s, "END", 3, 0);
				break;

			}

			sprintf(data, "%s: %s", ID, buff);

			if (send(cs, data, strlen(data), 0) < strlen(data))
			{
				printf("전송 실패, 에러코드 = %u \n", WSAGetLastError());
				closesocket(cs); closesocket(s); WSACleanup(); return;
			}
		}
		memset(data, 0, sizeof data);
		ret = recv(cs, data, 1000, 0);
		if (ret == 0 || WSAGetLastError() == WSAETIMEDOUT) continue;

		if (ret == SOCKET_ERROR)
		{
			printf("수신 실패, 에러 코드 = %u \n", WSAGetLastError());
			closesocket(cs); closesocket(s); WSACleanup(); return;

		}
		puts(data);

	}
	if (closesocket(cs) != 0 || closesocket(s) != 0)
	{
		printf("소켓 제거 실패, 에러코드 = %u \n", WSAGetLastError());
		WSACleanup(); return;
	}
	if (WSACleanup() != 0)
	{
		printf("WSACleanup 실패, 에러코드 = %u \n", WSAGetLastError());
		return;
	}
}
