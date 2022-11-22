#include <iostream>
#include "a.h"
#include "b.h"

void test(char p, char t)
{
    std::cout << "Function test() from main file works!\n";
}

int main()
{
    test(5);
    test('c');
    test('c', 4);
    test('a', 'b');
}

//The functions test() can be called not at the same time with the help of their unique parameters
//The functions will be analysed and the best match for the parameters given will be found and called
//Calling all three at the same time is impossbile, as the difference in parameters will not exist and it will be deemed an ambigous call
