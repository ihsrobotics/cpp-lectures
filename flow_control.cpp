#include <iostream>
#include <cstdlib>
using namespace std;




int main(){
    // if, else if, else
    bool rainy = true;
    bool cloudy = true;
    bool bringUmbrella;
    if(rainy){
        bringUmbrella = true;
        cout << "it's rainy today" << endl;
    }
    else if(cloudy){
        bringUmbrella = false;
        cout << "it's cloudy but not raining" << endl; 
    }
    else{
        bringUmbrella = false;
        cout << "it's sunny today" << endl;
    }

    // ternary operator
    /*
    output = (condition) ? case true : case false
    */
    bringUmbrella = (rainy) ? true : false;
    // ternary can also be used to execute line(s) of code
    int a = 5;
    int b = 6;
    (a > b) ? cout << "a is greater than b" << endl : cout << "b is greater than a" << endl; 
    // nested ternary can be used to achieve if/else if/else
    (a == b) ? cout << "a is equal to b" << endl : 
        (a > b) ? cout << "a is greater than b" << endl : cout << "a is less than b" << endl;

    // for loops 
    for(int i = 0; i < 50; i++){
        // code to iterate 
    }
    // you can write a for loop without some or all of the statements
    for(;;){
        cout << "just be careful because it could create an infinite loop" << endl;
        break;
    }

    // while loops
    int x = 0;
    while(x < 10){
        cout << "running while condition is true" << endl;
        cout << "make sure that the condition of the loop can actually be met" << endl << 
        "ie if it's a variable being incremented make sure that it does get incremented in the loop" << endl;

        break;
    }

    // you can also nest loops
    int j;
    for(int i = 0; i < 5; i++){
        while(j < 5){
            cout << "i: " << i << " j: " << j << endl;
            j++;
        }
    }

    // switch cases
    int month = 7;
    // the switch variable must be a primitive 
    switch(month){
        case 1:
            cout << "it is January" << endl;
            break;
        case 2:
            cout << "it's February" << endl;
            break;
        case 3:
            cout << "it's March" << endl;
            break;
        case 4: 
            cout << "it's April" << endl;
            break;
        case 5:
            cout << "it's May" << endl;
            break;
        case 6:
            cout << "it's June" << endl;
            break;
        case 7:
            cout << "it's July" << endl;
            break;
        case 8:
            cout << "it's August" << endl;
            break;
        case 9: 
            cout << "it's September" << endl;
            break;
        case 10:
            cout << "it's October" << endl;
            break;
        case 11:
            cout << "it's November" << endl;
            break;
        case 12:
            cout << "it's December" << endl;
            break;

        default:
            cout << "it's not one of the 12 months" << endl;
            break;
    }
}