#include <iostream>
#include <string>
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 

#define SERVER_PORT     11994
#define SERVER_ADDR     "192.168.200.51"
// #define SERVER_ADDR     "127.0.0.1"

/////////////////////////////////////////////////////////
class TcpClient
{    
    int sock; 

    std::string lastIpAddr;
    int lastPort;
    struct sockaddr_in serv_addr; 

    bool status_connected;

public:
    TcpClient()
    {
    }

    bool connectToServer(std::string ipAddr, int port) 
    { 
        lastIpAddr = ipAddr;
        lastPort = port;

        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
        { 
            std::cout << "ERROR: Socket creation error \n"; 
            return false; 
        } 

        serv_addr.sin_family = AF_INET; 
        serv_addr.sin_port = htons(port); 
        
        // Convert IPv4 and IPv6 addresses from text to binary form 
        if(inet_pton(AF_INET, ipAddr.c_str(), &serv_addr.sin_addr)<=0)  
        { 
            std::cout << "ERROR: Invalid Network IP Address " << 
                ipAddr << "\n"; 
            return false; 
        }
    
        if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) != -1) {
            std::cout << "Connected to server: " << 
                SERVER_ADDR << " : " << SERVER_PORT << "\n";
            status_connected = true;
            return true;
        } else {
            std::cout << "Failed to connect to server: " << 
                SERVER_ADDR << " : " << SERVER_PORT << "\n";
            return false;
        }
    }

    bool connectToServer()
    {
        return connectToServer(lastIpAddr, lastPort);
    }

    bool transmit(const std::string data)
    {
        if (!isConnectedToServer()) 
            if (!connectToServer())
                return false;
        send(sock, data.c_str() , data.size(), 0);  
        return true;
    } 

    bool isConnectedToServer() // MSG_DONTWAIT
    {
        if (status_connected) {
            int val = recv(sock, nullptr, 0, MSG_DONTWAIT);
            if (val != 0) {
                return true;
            } else {
                close(sock);
                status_connected = false;
            }
        }
        return false;
    }
};

/////////////////////////////////////////////////////////
int main(int argc, char const *argv[]) 
{ 
    std::cout << "AppStart...................................\n";

    TcpClient client;

    while (!client.connectToServer(SERVER_ADDR, SERVER_PORT)) sleep(1);

    for (int i = 0; ; i++)
    {
        std::string message = "Message_" + std::to_string(i);
        if (client.transmit(message)) {
            std::cout << "Network transmit: " << message << "\n";
        } else {
            std::cout << "Can't transmit, server not connected\n";
        }
        sleep(1);
    }

    /* transmit keyboard input to server */
    // while (1)
    // {
    //     std::string inputData;
    //     std::cin >> inputData;

    //     int error_code;
    //     int error_code_size = sizeof(error_code);

    //     char buf[256];
    //     client.transmit(inputData); 
    // }

    // /* wait for reply from server */
    // char buffer[1024] = {0}; 
    // int valread = read( sock , buffer, 1024); 
    // std::cout << buffer << "\n"; 

    return 0; 
} 

/////////////////////////////////////////////////////////
