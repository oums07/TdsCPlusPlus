#include<iostream>
#include "class.h"
using namespace std;
int main(int argc,char* argv[]){
    my_class obj1;
    my_class obj2("oumnia");
    obj1.print_my_element();
    obj2.print_my_element();
     return 0;
}