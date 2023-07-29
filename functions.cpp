/**
 * @file functions.cpp
 * @author Eliot Hall
 * @brief Short Description of functions
 * @version 0.1
 * @date 2023-07-28
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <functional>

// general syntax:
// returnType functionName(parameterType parameterName, ...) {
//      function contents
// }

// function "signature" is the return type and parameter types

int addTwo(int, int); // declarations normally go in header files

// implementation normally in cpp files
int addTwo(int a, int b)
{
    return a + b;
}
int multiplyTwo(int a, int b)
{
    return a * b;
}
int subtractTwo(int a, int b)
{
    return a - b;
}

// functions can have any return type
// so long as that type is defined
std::string sayHello(std::string name)
{
    return "hi there " + name;
}

// variables created inside a function only exist
// as long as the function is on the stack
// (unless otherwise allocated)
int haveAVariable()
{
    int temp = 33;
    int otherTemp = 22;
    return temp + otherTemp;
}

// functions can have default parameters
int add(int a, int b = 33)
{
    return a + b;
}

// template return types can be used to allow multiple
// return types with the same types of parameters
// this particular one cannot be deduced by the compiler and
// must be specificed at the call site
template <typename T>
T coolThing(void *data)
{
    return *reinterpret_cast<T *>(data);
}

// this can return only the type that it was given
template <typename T>
T addThings(T a, T b)
{
    return a + b;
}

// a function;
int main()
{
    // functions can be stored as pointers
    int (*f)(int, int) = subtractTwo;
    std::cout << f(1, 2) << std::endl; // -1

    // but the best way to store them is with std::function
    // this allows easier-to-read passing of functions
    std::function<int(int, int)> easyFunction = addTwo;
    std::cout << easyFunction(1, 2) << std::endl; // 3
    easyFunction = multiplyTwo;                   // can be reassigned since the signature of the functions match

    // example of multiple return types from the same function
    int temp = 22;
    void *data = &temp;
    std::cout << coolThing<int>(data) << std::endl;
    std::string secondVar = "hi";
    data = &secondVar;
    std::cout << coolThing<std::string>(data) << std::endl;

    return 0;
}