#include <iostream>
#include <string>

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

void printVal(Entity *e) 
{
    std::cout << "Entity value: " << e->val << std::endl;
}

//////////////////////////////////////////////////////
int main()
{
    std::cout << "AppStart..............." << std::endl;

    // std::unique_ptr <Entity> e = std::unique_ptr <Entity> (new Entity());
    // std::shared_ptr <Entity> e(new Entity());
    // std::shared_ptr <Entity> e;
    // e = std::make_shared <Entity> ();

    {   
        auto eShared = std::shared_ptr <Entity> (new Entity());
        eShared->val = 10;
        printVal(eShared.get());
    }
    

    std::cout << "AppEnd................." << std::endl;
    return 0;
}
//////////////////////////////////////////////////////


