#include <iostream>
using namespace std;

int main(){
    // c++ is a statically typed language and requires explicit typing in most situations
    // variables are only a name given to a memory location, and operations done on the variable affects that memory location

    // primitive types in c++:
    int a = 10;

    // floats are 32 bits (like int)
    float b = 10.0;

    // doubles are also used to store decimals but are 64 bits (more precise than floats)
    double c = 10.0;

    // there are also type modifiers: signed, unsigned, short, long 
    // signed and unsigned are pretty self explanatory, signed can contain both positive and negative values, while unsigned can only contain positive values

    // short is 16 bits 
    short d = 32767;
    // this means that its range is -32767 to +32767
    short int e = -32767;
    // short int is equivalent to short

    // long is used for longer integers and are used for storing larger values
    long int f = 10;
    long g = 10;
    // these are equivalent 
    // long is 32 bits, which are the same as normal integers, which means theres practically no difference

    // for larger values
    long long h = 9223372036854775807;
    // it's pretty long

    // for more precise decimals there's 
    long double i = 10.0;
    // it's usually 80 bits

    // sign and size modifiers can be used together
    unsigned short int j = 5;

    // there is also the const modifier
    const int k = 15;
    // this makes a variable immutable and any operations that attempts to modify it will result in a error during compilation


    // the last primitive type is char
    // it stores an ASCII character 
    char l = 'E';
    // you cannot use double quotes "" to assign char 


    // string is another commonly used datatype in c++
    // however it is not a primitive but rather an object (recall OOP from Python)
    string m = "abcdefg";
    // you must use double quotes to assign strings 

    // because strings are objects, this means they have methods
    // a commonly used one is substring

    string n = m.substr(3);
    // take the portion of m from index 3 to the end of the string 
    cout << n << endl;
    // defg

    string o = m.substr(3, 2);
    // there is a second optional argument, length, that specifies how long the substring is 
    cout << o << endl;
    
    // another commonly used string method is find()
    // this searches if a substring is in a string
    // if it is successful, the beginning index is returned
    // else it doesn't return a position, and we detect this using string.npos

    int index = m.find("abc");
    cout << index << endl; // this will print 0 

    index = m.find("opq");
    cout << index << endl; // this will print out some nonsense
    if(index == m.npos){
        cout << "not found" << endl; // this will be printed 
    }


}
