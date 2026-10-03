#ifndef NOMBRES_H
#define NOMBRES_H
#include <iostream>
#include <string>
using namespace std;

class Complex2D{
    private:
     double re;
     double img;
    public:
     Complex2D();
     Complex2D(double re,double img);
     Complex2D(double complex);
     Complex2D(Complex2D &complex);
     Complex2D set_re(double r);
     Complex2D set_img(double i);
     double get_re();
     double get_img();
     Complex2D operator+(Complex2D &complex);
     Complex2D operator-(Complex2D &complex);
     Complex2D operator*(Complex2D &complex);
     Complex2D operator/(Complex2D &complex);
     bool operator<(Complex2D &complex);
     bool operator>(Complex2D &complex);
    
};
void Affichage();
#endif