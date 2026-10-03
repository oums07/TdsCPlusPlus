#ifndef CLASS_H
#define CLASS_H
#include <iostream>
#include <string>
using namespace std;

 class my_class{
    private: 
     string variable;
    public: 
    void print_my_element();
    my_class();
    my_class(string var);
};
#endif