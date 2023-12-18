#include "TcpListener.h"
using namespace std;


int TcpListener::init()
{
    // Initialze winsock
    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2);

    int wsOk = WSAStartup(ver, &wsData);
    if (wsOk != 0)
    {
        return wsOk;
    }

    // Create a socket
    m_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (m_socket == INVALID_SOCKET)
    {
        return WSAGetLastError();
    }

        // Bind the ip address and port to a socket
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(m_port);
    inet_pton(AF_INET, m_ip_address, &hint.sin_addr);

    if(bind(m_socket, (sockaddr *)&hint, sizeof(hint)) == SOCKET_ERROR)
    {
        return WSAGetLastError();
    };
}

int TcpListener::run()
{
}