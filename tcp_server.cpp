// Server side C/C++ program to demonstrate Socket programming 

#include <iostream>
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 

#define SERVER_PORT 11999

/////////////////////////////////////////////////////////
class TcpServer
{
    int sock_client;


    int server_fd; 
    struct sockaddr_in address; 

    int addrlen = sizeof(address); 

public:

    bool startListen()
    {
        int opt = 1; 
        
        // Creating socket file descriptor 
        if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
        { 
            perror("socket failed"); 
            exit(EXIT_FAILURE); 
        } 
        
        // Forcefully attaching socket to the port 8080 
        if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                    &opt, sizeof(opt))) 
        { 
            perror("setsockopt"); 
            exit(EXIT_FAILURE); 
        } 
        address.sin_family = AF_INET; 
        address.sin_addr.s_addr = INADDR_ANY; 
        address.sin_port = htons(SERVER_PORT); 
        
        // Forcefully attaching socket to the port 8080 
        if (bind(server_fd, (struct sockaddr *)&address,  
                                    sizeof(address))<0) 
        { 
            perror("bind failed"); 
            exit(EXIT_FAILURE); 
        } 

        if (listen(server_fd, 3) < 0) 
        { 
            perror("listen"); 
            exit(EXIT_FAILURE); 
        }
    }

    bool readfromClient(std::string* buff_out)
    {


        if ((sock_client = accept(server_fd, (struct sockaddr *)&address,  
                (socklen_t*)&addrlen)) < 0) 
        { 
            perror("ERROR: accept"); 
            // exit(EXIT_FAILURE); 
            return false;
        }

        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));
        
        int valread = read( sock_client , buffer, 1024); 
        if (valread > 0)
        {
            // std::cout << "val: " << valread << ", Buff: " << buffer << "\n"; 
            *buff_out = std::string(buffer);
            return true;
        }
        return false;
    }
};

/////////////////////////////////////////////////////////
int main(int argc, char const *argv[]) 
{ 
    TcpServer server;
    server.startListen();

    while (1)
    {
        std::string buffer;
        if (server.readfromClient(&buffer))
        {
            std::cout << "Received:" << buffer << "\n";
        }

    }

    // char buffer[1024] = {0}; 
    // send(sock , hello , strlen(hello) , 0 ); 
    // printf("Hello message sent\n"); 
    return 0; 
} 

/////////////////////////////////////////////////////////