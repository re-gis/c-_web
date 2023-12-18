#pragma once

#include <iostream>
#include <WS2tcpip.h>
#include <string>
#include <sstream>

#pragma comment(lib, "ws2_32.lib")

class TcpListener
{
public:
    // constructor
    TcpListener(const char *mIpAddress, int port) : m_ip_address(mIpAddress), m_port(port) {}
    int init();
    int run();

protected:
private:
    const char *m_ip_address;
    int m_port;
    int m_socket;
};