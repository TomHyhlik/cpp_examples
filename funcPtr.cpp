#include <iostream>
#include <string>


typedef void (* fun2)();
typedef fun2 (* StateFunc)(int *, bool *);

//////////////////////////////////////////////////////
class StateMachine 
{
    StateFunc fp;

public:
    StateMachine()
    {
        fp = (StateFunc) state_01;   // starting state
    }

    void start()
    {
        for (int i = 0; i < 10; i++) {
            if (!rxHandler(&i)) break;
        }
    }
    bool rxHandler(int *val) 
    {
        if (fp != nullptr) {
            bool success = false;
            fp = (StateFunc) fp(val, &success);
            if (!success) {
                std::cout << "Failed to handle received command: " 
                            <<  *val << "\n";
                fp = nullptr;
                return false;
            } 
        } else {
            std::cout << "Null state, exitting...\n";
            return false;
        }
        return true;
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


