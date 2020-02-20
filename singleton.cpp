#include <iostream>
#include <string>

//////////////////////////////////////////////////////
class Parameters_serial 
{
    Parameters_serial(){}
    static Parameters_serial s_Instance;

public:
    /*  disable to make aditional instance, must be only one */
    Parameters_serial(const Parameters_serial&) = delete;

    static Parameters_serial& get() 
    {
        return s_Instance;
    }
    std::string portName;
    uint32_t baudRate;

};

Parameters_serial Parameters_serial::s_Instance;

//////////////////////////////////////////////////////
void param_write()
{
    Parameters_serial::get().portName = "ttyS0";
    Parameters_serial::get().baudRate = 9600;
}


void param_print()
{
    std::cout << "Port name: " << Parameters_serial::get().portName
    << "\nBaud rate: " << Parameters_serial::get().baudRate 
    << std::endl;

}

//////////////////////////////////////////////////////
int main()
{
    std::cout << "AppStart..............." << std::endl;

    /* members can be accessed as bellow */

    // Parameters_serial& param = Parameters_serial::get();
    /* or */ 
    auto& param = Parameters_serial::get();

    param.baudRate = 115200;

    param_write();
    param_print();



    std::cout << "AppEnd................." << std::endl;
    return 0;
}



