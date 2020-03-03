#include <iostream>
#include <string>


typedef void (* funcPtr)();
typedef funcPtr (* StateFunc)(int *, bool *);

//////////////////////////////////////////////////////
class StateMachine 
{
    StateFunc currentState;

public:
    StateMachine()
    {
        currentState = (StateFunc) state_01;   // starting state
    }

    void start()
    {
        for (int i = 0; i < 10; i++) rxHandler(&i);
    }

    void rxHandler(int *val) 
    {
        if (currentState != nullptr) {
            bool success = false;
            currentState = (StateFunc) currentState(val, &success);
            if (!success) {
                std::cout << "Failed to handle received command: " 
                            <<  *val << "\n";
                currentState = nullptr;
            } 
        } else {
            std::cout << "Null state\n";
        }
    }

    //////////////////////////// DEFINED STATES
    static funcPtr state_04(int *cmd, bool *ok) 
    {
            std::cout << "State \t04\tcmd: " << *cmd << "\n"; 
            *ok = true;
            return (funcPtr)nullptr; 
    }

    static funcPtr state_03(int *cmd, bool *ok) 
    {
            std::cout << "State \t03\tcmd: " << *cmd << "\n"; 
            *ok = true;
            return (funcPtr)state_04; 
    }

    static funcPtr state_02(int *cmd, bool *ok) 
    {
            std::cout << "State \t02\tcmd: " << *cmd << "\n"; 
            *ok = true;
            return (funcPtr)state_03; 
    }

    static funcPtr state_01(int *cmd, bool *ok) 
    {
            std::cout << "State \t01\tcmd: " << *cmd << "\n"; 
            *ok = true;
            return (funcPtr)state_02; 
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


