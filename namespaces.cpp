/**
 * @file namespaces.cpp
 * @author Eliot Hall
 * @brief Introduction to namespaces
 * @version 0.1
 * @date 2023-07-21
 *
 * @copyright Copyright (c) 2023
 *
 * @details
 * Namespaces are collections of functions, classes, and variables
 * that have been grouped together. A good way to think of namespaces is to think
 * of them as scopes. There's the global namespace (or global scope), and there
 * can be custom namespaces in which variables, functions, etc exist.
 */

#include <iostream>
#include <unordered_map>

// here, we say that we want to use all the functions / classes / etc
// from the std namespace as if they were in the global namespace
using namespace std;
// (imaginary definition of cout and endl and iostream)

// this is would be what you'd do in a header file
// that way it doesn't bring the full namespace
// into any file that includes the header file
using std::cout;
using std::endl;

// inaccessible namespace
// since there's no name that you can use
// to access all the functions/variables w/i the namespace
namespace
{
    string secretSauce = "secret!!";
};
// namespaces are declared with the keyword `namespace`. Their contents
// goes in the following brackets (which should be ended with a semicolon)
// this namespace contains multiple fibonacci functions, each
// with a different implementation
namespace fibonacci
{
    // nested namespace
    namespace fibonacciprivate
    {
        // cache that stores fibonacci numbers;
        // this isn't actually a global variable, rather, it
        // is a variable that exists inside the `fibonacci` namespace
        unordered_map<int, int> fibonacciCache;
    }
    // basic recursive fibonacci
    int fibonacciRecursive(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }

    // fibonacci, but it
    // uses the cache to calculate fibonacci numbers
    int fibonacciCached(int n)
    {
        // if n already is within the cache, just
        // return that value
        if (fibonacciprivate::fibonacciCache.find(n) != fibonacciprivate::fibonacciCache.end())
        {
            return fibonacciprivate::fibonacciCache[n];
        }

        int ret = 0;
        if (n == 0)
        {
            ret = 0;
        }
        else if (n == 1)
        {
            ret = 1;
        }
        else
        {
            // calculate the value
            ret = fibonacciCached(n - 1) + fibonacciCached(n - 2);
        }

        // store the calculated value
        fibonacciprivate::fibonacciCache[n] = ret;
        return ret;
    }

}; // namespace fibonacci

int main()
{
    int times = 35;

    // :: is used to specify that we are referring to a member of the namespace
    // equivalent to doing numpy.array
    // namespace::variable / function
    cout << fibonacci::fibonacciRecursive(times) << endl;

    // using directives can go within functions too!!
    // here, we say we want to use fibonacci's fibonacciCached as if it was "in the global namespace"
    using fibonacci::fibonacciCached;
    cout << fibonacciCached(times) << endl;

    // std::cout and std::endl are what we are really
    // using above, but because we used the `using` directive,
    // we can use them as if they were in the global namespace

    // trying to access the members of a namespace without either specifying the namespace
    // or using a `using` directive would lead to the same type of error you would get
    // if it wasn't defined at all --- because, for the compiler, it is undefined since
    // the compiler doesn't know where that function comes from
    // try it:
    // cout << fibonacciRecursive(times) << endl; // compiler error

    return 0;
}