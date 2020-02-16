#include <iostream>
#include <string>

#include <algorithm>
#include <functional>


//////////////////////////////////////////////////
void print(std::vector<int>* values)
{
    for (int val : *values) {
        std::cout << val << std::endl;
    }
}

//////////////////////////////////////////////////
void sort_increasing(std::vector<int>* values) 
{
    std::sort(values->begin(), values->end(), [](int a, int b) {
        return a < b;
    });
}
//////////////////////////////////////////////////
void sort_decreasing(std::vector<int>* values) 
{
    std::sort(values->begin(), values->end(), [](int a, int b) {
        return a > b;
    });
}

//////////////////////////////////////////////////
//////////////////////////////////////////////////
int main()
{
    std::cout << "AppStart..............." << std::endl;

    std::vector<int> values = {3, 5, 2, 6, 4, 0, 1};


    sort_increasing(&values);
    print(&values);

    std::cout << std::endl;

    sort_decreasing(&values);
    print(&values);


    std::cout << "AppEnd................." << std::endl;
    return 0;
}
//////////////////////////////////////////////////
