#include <iostream>
#include <string>


///////////////////////////////
typedef void (*fun2)();
typedef fun2 (*fun1)(int *, bool *);

class StateMachine 
{

    bool success;
    fun1 fp;

public:
    StateMachine()
    {
        fp = (fun1) state_01;
        success = false;
    }

    //////////////////////////////////////////////////////
    static fun2 state_04(int *cmd, bool *ok) 
    {
            std::cout << "State \t04\tcmd: " << *cmd << "\n"; 
            return (fun2)nullptr; 
    }

    static fun2 state_03(int *cmd, bool *ok) 
    {
            std::cout << "State \t03\tcmd: " << *cmd << "\n"; 
            return (fun2)state_04; 
    }

    static fun2 state_02(int *cmd, bool *ok) 
    {
            std::cout << "State \t02\tcmd: " << *cmd << "\n"; 
            return (fun2)state_03; 
    }

    static fun2 state_01(int *cmd, bool *ok) 
    {
            std::cout << "State \t01\tcmd: " << *cmd << "\n"; 
            return (fun2)state_02; 
    }


    //////////////////////////////////////////////////////
    void rxHandler(int *val) 
    {
            if (fp != nullptr) {
                fp = (fun1) fp(val, &success);
            }
    }
    //////////////////////////////////////////////////////
    void start()
    {

        for (int i = 0; i < 6; i++) {
            rxHandler(&i);
        }
    }
};

//////////////////////////////////////////////////////
int main()
{
    std::cout << "AppStart..............." << std::endl;

    StateMachine sm;
    sm.start();

    std::cout << "AppEnd................." << std::endl;
    return 0;
}
//////////////////////////////////////////////////////


