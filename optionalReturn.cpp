#include <iostream>
#include <string>
#include <fstream>

#include <fstream>
#include <sstream> //std::stringstream
#include <optional>

std::optional<std::string> ReadFile(const std::string& fileName)
{
    std::ifstream stream(fileName);

    if (stream)
    {
        std::stringstream strStream;
        strStream << stream.rdbuf(); //read the file
        std::string result = strStream.str(); //str holds the content of the file
        stream.close();
        return result;
    }

    return {};
}


int main()
{
    std::cout << "AppStart..............." << std::endl;

    std::optional<std::string> data = ReadFile("README.md");

    if (data.has_value()) {
        std::cout << "File data: " << data.value() << std::endl;
    } else {
        std::cout << "Failed to read file" << std::endl;
    }

    std::cout << "AppEnd..............." << std::endl;
    return 0;
}

