#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;


// A templated function of type T.  As long as type "T" supports the + operator,
// it can be used with this function.
template<typename T>
T combine_two_things(const T& _1st, const T& _2nd){
    return _1st + _2nd;
}

// A pointer to a function that takes two integers and returns an integer.
// typedef int(*Fn)(int,int);
using Fn = int(*)(int,int);

// A simple binomial function.
int add_two_numbers(int a, int b){
    return a + b;
}

// A function template.  The type "F" is termined by the parameter passed in and 
// can be anything that supports "int operator()(int,int)"
template<typename F>
int binomial_operator(const F& binomial, int a, int b){
    return binomial(a,b);
}


// A c++20 template.  The parameter "binomial" is templated and can be any type
// that supports "operator()(int,int)".  This is equivalent to the above template.
// int binomial_operator(const auto& binomial, int a, int b){
//     return binomial(a,b);
// }


// This is a class that implements "int operator()(int,int)" and therefore can 
// be used as a parameter to ""binomial_operator".
struct Subtract{
    int startingPoint;
    Subtract(int aNumber):startingPoint(aNumber){}
    int operator()(int a, int b) const{
        // Subtract two numbers from a starting point.
        return startingPoint - a - b;
    }
 
};

// Some templated class, dependent on type T, whatever that may be.
template<typename T>
struct A{
    T myT;
    A(const T& t):myT(t){}
};


int main(){
    // Templated classes:
    A<int> a1_int(1);
    A<int> a2_int(2);
    A<float> a_float(3.0);
    a1_int = a2_int;
    // a1_int = a_float; // Error! The types are different

    int aNumber =4;
    auto multiply = [&](auto a, auto b){return a*b*aNumber;};
    auto add = add_two_numbers;
    Subtract mySubtractFunction(100);
    // Notice: binomial operator can take a function pointer, a lambda, or a function object.
    cout << binomial_operator(add,3,4)<<"\n";
    cout << binomial_operator(multiply,5,6)<<"\n";
    cout << binomial_operator(mySubtractFunction,5,6)<<"\n";


    // Any type that supports the "+" operator can be used to call
    // the template "combine_two_things."
    string hello = "hello";
    string world = " world";
    cout<<combine_two_things(hello,world)<<"\n";
    auto [a, b] = tuple(3,4);
    cout<<combine_two_things(a,b)<<"\n\n";


    //Using lambdas in method calls:
    vector<int> v = {5,3,1,2,12};
    // The parameters a and b can be anything, but in this case they are integers.
    sort(v.begin(),v.end(),[&](auto a, auto b){
        // Ascending.
        return a<b;
    });
    for (auto n:v){
        cout << n<<"\n";
    }

    return binomial_operator(mySubtractFunction,2,1);
     
}
