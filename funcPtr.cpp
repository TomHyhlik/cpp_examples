#include <iostream>
#include <string>


typedef void (*fun2)();
typedef fun2 (*fun1)(int *, bool *);

//////////////////////////////////////////////////////
class StateMachine 
{
    fun1 fp;

public:
    StateMachine()
    {
        fp = (fun1) state_01;   // starting state
    }

    void start()
    {
        for (int i = 0; i < 6; i++) {
            rxHandler(&i);
        }
    }
    void rxHandler(int *val) 
    {
        bool success = false;

        if (fp != nullptr) {
            fp = (fun1) fp(val, &success);
            if (!success) {
                std::cout << "Failed to handle received command: " 
                    <<  *val << "\n";
                fp = nullptr;
            }
        }
    }

    //////////////////////////// DEFINED STATES
    static fun2 state_04(int *cmd, bool *ok) 
    {
            std::cout << "State \t04\tcmd: " << *cmd << "\n"; 
            *ok = true;
            return (fun2)nullptr; 
    }

    static fun2 state_03(int *cmd, bool *ok) 
    {
            std::cout << "State \t03\tcmd: " << *cmd << "\n"; 
            *ok = true;
            return (fun2)state_04; 
    }

    static fun2 state_02(int *cmd, bool *ok) 
    {
            std::cout << "State \t02\tcmd: " << *cmd << "\n"; 
            *ok = true;
            return (fun2)state_03; 
    }

    static fun2 state_01(int *cmd, bool *ok) 
    {
            std::cout << "State \t01\tcmd: " << *cmd << "\n"; 
            *ok = true;
            return (fun2)state_02; 
    }
};

////////////////////////////////////////////////////// MAIN
int main()
{
    std::cout << "AppStart..............." << std::endl;

    StateMachine sm;
    sm.start();

    std::cout << "AppEnd................." << std::endl;
    return 0;
}
//////////////////////////////////////////////////////


