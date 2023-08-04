#include <iostream>
#include <vector>

// example class to demonstrate
// lvalue and rvalues
class X
{
public:
    // constructor; 0 parameter constructor
    X() : val(0) { std::cout << "X obj created" << std::endl; };
    X &operator+=(int o)
    {
        val += o;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &o, const X &x)
    {
        o << x.val;
        return o;
    }

private:
    int val;
};

// the X() statement gets evaluated every time,
void defaultExample(int val, X obj = X())
{
    obj += val;
    std::cout << "obj is now" << obj << std::endl;
}

// const lvalues can be bound to newly created objects
void defaultExample2(const X &obj = X())
{
    // can't increment it bc it is const
    // obj += val
    std::cout << "obj is" << obj << std::endl;
}

// this would'nt work; anyone know why?
// void incorrectDefaultExample(int val, X &obj = X())
// {
//     obj += val;
//     std::cout << "obj is" << obj << std::endl;
// }

int main()
{
    // default parameter lifetime
    defaultExample(1);
    defaultExample(3);

    // const lvalue binding
    defaultExample2();
    defaultExample2();

    return 0;
}