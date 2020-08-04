#include <iostream>
#include <string>
#include <memory>

//////////////////////////////////////////////////////
class Entity 
{
public:
    Entity() {
        std::cout << "Constructed\n";
    }
    ~Entity() {
        std::cout << "Destructed\n";
    }
    int val;
};

class nevim
{
    // std::unique_ptr <Entity> e;
    Entity e;

public:
    nevim() 
    {
        // e = std::make_unique <Entity> ();
    
    };


};

//////////////////////////////////////////////////////
int main()
{
    std::cout << "AppStart..............." << std::endl;


    {
        nevim n;



    }




    std::cout << "AppEnd................." << std::endl;
    return 0;
}
//////////////////////////////////////////////////////


