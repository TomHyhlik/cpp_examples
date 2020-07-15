#include <iostream>
#include <thread>     
#include <chrono>


//////////////////////////////////////////////////////
void t1_routine() 
{
    for (int i = 0; i < 5; i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "thread running: " << i << std::endl;
    }
}

//////////////////////////////////////////////////////
int main(void) 
{
    std::cout << "AppEnd...........................\n";

    std::thread first (t1_routine);   
    

    first.join();          // wait till thread finishes
    

    std::cout << "AppStart.........................\n";
    return 0;
}
//////////////////////////////////////////////////////