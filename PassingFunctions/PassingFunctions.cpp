// PassingFunctions.cpp : Defines the entry point for the application.
//

#include <functional>
#include "PassingFunctions.h"

#include <iostream>

/**
 * A function that is passed as a parameter
 * @param v a value to which we add 2
 */
void add1(int &v)
{
    v += 1;
}

/**
 * A function that is passed as a parameter
 * @param v a value to which we add 2
 */
void add2(int &v)
{
    v += 2;
}

/**
 * Function parameters as template parameters
 * @tparam F some function type
 * @param f the function to invoke
 */
template<typename F>
void doOperation(F f)
{
    int temp = 0;
    f(temp);
    std::cout << "Result: " << temp << std::endl;
}

/**
 * Class to serve as factory for function objects
 * @tparam T
 */
template<typename T>
class add3
{
public:
    /**
     * Overloaded function operator; function objects will add 1 to its argument
     * @param v the parameter for the function
     */
    void operator()(T &v) { v += 3; }
};

/**
 * A function that takes a function as a parameter
 * @tparam T type parameter
 * @param v value to pass to incoming function
 * @param visit a function to invoke
 */
template<typename T>
void doBar(T& v, void visit(T&))
{
    visit(v);
    std::cout << "Result: " << v << std::endl;
}

int main()
{
    doOperation(add1);
    doOperation(add2);
    doOperation(add3<int>());
    int v{5};
    doBar(v, add1);
    return 0;
}