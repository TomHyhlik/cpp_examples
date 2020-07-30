#include <iostream>
#include <string>
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 


#define SERVER_PORT     11999 
#define SERVER_ADDR     "192.168.200.51"

   
int main(int argc, char const *argv[]) 
{ 
    int sock = 0; 
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        std::cout << "ERROR: Socket creation error \n"; 
        return -1; 
    } 

    struct sockaddr_in serv_addr; 
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(SERVER_PORT); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, SERVER_ADDR, &serv_addr.sin_addr)<=0)  
    { 
        std::cout << "ERROR: Invalid address\n"; 
        return -1; 
    } 
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        std::cout << "Connection Failed \n"; 
        return -1; 
    }

    while (1)
    {
        std::string inputData;
        std::cin >> inputData;

        send(sock, inputData.c_str() , inputData.size() , 0); 
    }

    /* wait for reply from server */
    char buffer[1024] = {0}; 
    int valread = read( sock , buffer, 1024); 
    std::cout << buffer << "\n"; 

    return 0; 
} 