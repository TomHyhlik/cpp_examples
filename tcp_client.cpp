#include <iostream>
#include <string>
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 

#define SERVER_PORT     11999
#define SERVER_ADDR     "192.168.200.51"

/////////////////////////////////////////////////////////
class TcpClient
{    
    int sock; 

    std::string lastIpAddr;
    int lastPort;

public:
    bool connectToServer(std::string ipAddr, int port) 
    { 
        lastIpAddr = ipAddr;
        lastPort = port;

        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
        { 
            std::cout << "ERROR: Socket creation error \n"; 
            return false; 
        } 

        struct sockaddr_in serv_addr; 
        serv_addr.sin_family = AF_INET; 
        serv_addr.sin_port = htons(port); 
        
        // Convert IPv4 and IPv6 addresses from text to binary form 
        if(inet_pton(AF_INET, ipAddr.c_str(), &serv_addr.sin_addr)<=0)  
        { 
            std::cout << "ERROR: Invalid Network IP Address " << 
                ipAddr << "\n"; 
            return false; 
        } 
    
        return (connect(sock, (struct sockaddr *)&serv_addr, 
            sizeof(serv_addr)) != -1);
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

    bool isConnectedToServer()
    {
        return (recv(sock, nullptr, 0, MSG_PEEK | MSG_DONTWAIT) > 0);
    }
};

/////////////////////////////////////////////////////////
int main(int argc, char const *argv[]) 
{ 

    TcpClient client;
    while (!client.connectToServer(SERVER_ADDR, SERVER_PORT)) {
        std::cout << "ERROR: Failed to connect to server\n";
        sleep(2);
    }
    std::cout << "Connected to server: " << 
        SERVER_ADDR << " : " << SERVER_PORT << "\n";

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
