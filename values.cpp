/**
 * @file values.cpp
 * @author Eliot Hall
 * @brief Lvalues vs Rvalues vs pointers
 * @version 0.1
 * @date 2023-07-24
 *
 * @copyright Copyright (c) 2023
 *
 * @details Lvalues are what we call "references", Rvalues are what we call objects that only exist
 * on the RHS (right hand side) of the equals sign, and pointers are the memory address where a variable
 * is stored
 */

#include <iostream>
#include <string>
using namespace std;

// these are incorrect
// even though they might seem to modify their
// parameters, these changes are only local in scope
// This is because, in cpp, the default way to pass parameters
// is to copy the passed parameter.
namespace incorrect
{
    // makes a copy of the original string,
    // so changes are only reflected on the copy
    // the process of making a copy looks something like
    // int a = originalNumber
    void modifyInt(int a)
    {
        a += 3;
    }

    // makes a copy of the original string,
    // so changes are only reflected on the copy
    // the process of making a copy looks something like
    // string str = originalString
    void modifyStr(string str)
    {
        str += "hi";
    }
};

// lvalues are "references" to an object
// basically, instead of copying the object
// into a new variable that gets passed to the function,
// lvalues pass a reference to the variable, meaning
// that when the function modifies the parameter,
// those modifications affect the actual object (and not just a copy)
namespace lvalues
{
    void modifyInt(int &a)
    {
        a += 3;
    }
    void modifyStr(string &str)
    {
        str += "hi";
    }
}

// rvalues refer to constants that are only found
// on the right hand side of the equals side.
// for example, in `int a = 33`, 33 is an rvalue
// also, in `string cool = "cool"` "cool" is an rvalue
// In other words, if something is a variable, it is
// most likely an lvalue. If it isn't, then it's most
// likely an rvalue
// When taking an rvalue as a parameter, it saves
// operations and memory since instead of copying the value
// and passing that copy to the function, the compiler
// just passes the value itself
namespace rvalues
{
    // instead of doing int a = (some constant value)
    // this really just takes that constant value as a
    int modifyInt(int &&a)
    {
        return a + 3;
    }
    // instead of doing string str = (some constant value)
    // this just takes that rvalue string as the parameter
    string modifyStr(string &&str)
    {
        str += "hi";
        return str;
    }
}

// Pointers are the memory address where a variable is stored. Thus, pointers
// should always point to variables
//
// in terms of parameters, pointers have several different uses including:
// * acting as a way of passing references (by actually passing their memory address)
// * acting as a way of passing arrays of variable length
namespace pointers
{
    // in this case, the pointer acts as a way to pass arrays of
    // variable length
    int sumIntArray(int *array, size_t length)
    {
        int sum = 0;
        for (size_t i = 0; i < length; ++i)
        {
            sum += array[i];
        }
        return sum;
    }

    // in this case, the pointer acts as a way to pass a "reference"
    void modifyInt(int *a)
    {
        // dereference the pointer to get the variable, and add 3 to the int variable
        *a += 3;
    }
}

int main()
{
    // ========== lvalues demonstration ==========
    string greeting = "hello!";
    int number = 42;

    cout << "number is initially " << number << endl;
    incorrect::modifyInt(number);
    cout << "number is now " << number << endl;

    cout << "greeting is initially " << greeting << endl;
    incorrect::modifyStr(greeting);
    cout << "greeting is now " << greeting << endl;

    cout << "number is initially " << number << endl;
    lvalues::modifyInt(number);
    cout << "number is now " << number << endl;

    cout << "greeting is initially " << greeting << endl;
    lvalues::modifyStr(greeting);
    cout << "greeting is now " << greeting << endl;

    // while the above demonstrate the power of lvalues to modify
    // parameters, there's an important thing to note about lvalues:
    // they cannot take constants

    // this would be a compiler error since there is no variable here to pass a reference to
    // lvalues::modifyInt(22);

    // ========== rvalues demonstration ==========
    string betterGreeting = rvalues::modifyStr("hi there");
    cout << "betterGreeting is " << betterGreeting << endl;
    int rvalueInt = rvalues::modifyInt(22);
    cout << "rvalueInt is " << rvalueInt << endl;

    // just like how lvalue-parameter-functions can't take rvalues (non-variables) as their
    // lvalue parameters, functions with rvalues as parameters can't take variables (lvalues)
    // as their rvalue parameters. The below results in a compiler error
    // rvalues::modifyInt(rvalueInt);

    // ========== pointers demonstration ==========
    // pointer variables are declared with `(datatype)*`; the asterisk
    // tells the compiler that this holds a memory address that points
    // to a variable of type (datatype)
    // the & means to take the address of a variable
    int *myPointer = &rvalueInt;

    // to get the value stored in a pointer, we dereference it
    // to dereference it means that we go to the memory location
    // that it points to and take the datatype found there
    cout << "initially, pointer dereferenced is " << *myPointer << ", rvalueInt is " << rvalueInt << endl;
    cout << "the pointer points to address " << myPointer << endl;
    pointers::modifyInt(myPointer);
    cout << "now, pointer dereferenced is " << *myPointer << ", rvalueInt is " << rvalueInt << endl;

    // as we can see, arrays are really just pointers to data,
    // which is why we can use pointers to take in arrays as
    // arguments
    int intArray1[3] = {1, 2, 3};
    int intArray2[5] = {3, 4, 6, 7, 9};
    cout << "sum of intArray1 is " << pointers::sumIntArray(intArray1, 3) << endl;
    cout << "sum of intArray2 is " << pointers::sumIntArray(intArray2, 5) << endl;

    return 0;
}