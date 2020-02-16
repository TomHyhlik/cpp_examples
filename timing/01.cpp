#include <iostream>
#include <chrono>
#include <thread>

#include <unistd.h>


int main()
{
    std::cout << "AppStart..............." << std::endl;



    auto start = std::chrono::high_resolution_clock::now();

    /* The std::this_thread::sleep_for() supports seconds only. 
     *  Therefore alternative is the usleep() from <unistd.h>
     */
    
    usleep(1000000);

    auto end = std::chrono::high_resolution_clock::now();
    

    std::chrono::duration<float> duration = end - start;

    std::cout << "Duration (s): " << duration.count() << std::endl;


    int duration_ms = duration.count() * 1000;

    std::cout << "Duration (ms): " << duration_ms << std::endl;



    std::cout << "AppEnd..............." << std::endl;
    return 0;
}

