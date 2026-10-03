#include <iostream>
#include "class.h"
using namespace std;


    void  my_class::print_my_element(){
        cout<<endl<<variable<<endl;
    }
    my_class::my_class(){
        variable="default";
    };
    my_class::my_class(string var){
        variable=var;
    }
