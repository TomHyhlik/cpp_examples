#include <iostream>
#include <string>

#define DEBUG_MODE 1


#if DEBUG_MODE
    #define LOG(x) std::cout << "Log: " << x << std::endl;
#else 
    #define LOG(x)
#endif



int main()
{
    std::cout << "AppStart..............." << std::endl;

    /* The macro is replaced withthe defined code 
     * during compilation.
     * Macro definition must be on one line, othervise
     * on the end of every line must be backslash '\'.  
     * 
     */
    LOG("Hello");


    std::cout << "AppEnd..............." << std::endl;
    return 0;
}

