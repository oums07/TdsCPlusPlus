#include <iostream>
#include "Nombres.h"
using namespace std;

int main(int argc,char* argv[]){
  Complex2D c1(2,3);
  Complex2D c2(4,5);
  Complex2D c3=c1+c2;    
  Affichage(c3);
  Complex2D c4=c1-c2; 
  Affichage(c4);
  Complex2D c5=c1*c2;
  Affichage(c5);
  Complex2D c6=c1/c2;
  Affichage(c6);
 
  cout<<endl<<"c2>c1 : "<<(c2>c1)<<endl;
  cout<<endl<<"c2<c1 : "<<(c2<c1)<<endl;
}