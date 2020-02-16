#include <iostream>
#include <vector>
#include <algorithm>

#define NEWLINE     std::cout << std::endl;


void ForEach(const std::vector<int>& values, void (*func)(int))
{
    for (int value : values) {
        func(value);
    }
}



int main()
{
    std::cout << "AppStart..............." << std::endl;


    std::vector <int> values = {1, 2, 3, 4, 5};

    /* option 1 
     * define the lambda straight 
     */
    ForEach(values, [](int value) {
        std::cout << "Lambda 01 Value: " << value << std::endl;
    });

    NEWLINE;

    /* option 2
     *  make a pointer to the lambda function
     */
    auto lambda = [] (int value) {
        std::cout << "Lambda 02 Value: " << value << std::endl;
    };
    /* and call it like this */
   ForEach(values, lambda);


    std::cout << "AppEnd..............." << std::endl;
    return 0;
}

