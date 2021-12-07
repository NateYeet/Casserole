#include <iostream>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")
using namespace std;

#define PORT 10000
bool initWSA(){
    WSADATA wsadata;
    int error = WSAStartup(0x0202, &wsadata);
    if (error) return false;
    if (wsadata.wVersion != 0x0202){
        WSACleanup();
        return false;
    }
    return true;
}
void closeConnection(SOCKET s)
{
    //Close the socket if it exists
    if (s)
        closesocket(s);

    WSACleanup(); //Clean up Winsock
}
int main(){
    initWSA();
    SOCKET s;
    SOCKADDR_IN addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (s == INVALID_SOCKET) cout << "INVALID SOCKET" << endl;
    if (bind(s, (LPSOCKADDR)&addr, sizeof(addr)) == SOCKET_ERROR){
    cout << "SOCKET ERROR" << endl;
    }
    listen(s, SOMAXCONN);
    //cout << "CAUGHT ONE" << endl;
    //closeConnection(s);
    return 0;
}
