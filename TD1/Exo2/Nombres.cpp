#include<iostream>
using namespace std;

     Complex2D::Complex2D(){
        re=0;
        img=0;
     }
     Complex2D::Complex2D(double re,double img){
         this->re=re;
         this->img=img;
     }
     Complex2D::Complex2D(double complex){
        re=complex;
        img=complex;
     }
     Complex2D::Complex2D(Complex2D &complex){
        re=complex.get_re();
        img=complex.get_img();
     }
     Complex2D::Complex2D set_re(double r){
        re=r;
        return *this;
     }
     Complex2D::Complex2D set_img(double i){
        img=i;
        return *this;
     }
     double Complex2D::get_re(){
        return re;
     }
     
     double Complex2D::get_img(){
        return img;
     }
     Complex2D Complex2D::operator+(Complex2D &complex){
        Complex2D res;
        res.set_re(complex.get_re()+this.get_re());
        res.set_img(complex.get_img()+this.get_img());
        return res;

     }
     Complex2D Complex2D::operator-(Complex2D &complex){
         Complex2D res;
        res.set_re(complex.get_re()-this.get_re());
        res.set_img(complex.get_img()-this.get_img());
        return res;
     }
     Complex2D  Complex2D::operator*(Complex2D &complex){
        Complex2D res;
        res.set_re(complex.get_re()*this->get_re()-complex.get_img()*this->get_img());
        res.set_img(complex.get_re()*this->get_img()+complex.get_img()*this->get_re());
        return res;
     }
     Complex2D Complex2D::operator/(Complex2D &complex){
       Complex2D res;
        res.set_re((complex.get_re()*this->get_re()+complex.get_img()*this->get_img())/(complex.get_re()*complex.get_re()+complex.get_img()*complex.get_img()));
        res.set_img((complex.get_img()*this->get_re()-complex.get_re()*this->get_img())/(complex.get_re()*complex.get_re()+complex.get_img()*complex.get_img()));
        return res;

     }
     bool Complex2D::operator<(Complex2D &complex){
        double mod1=this->get_re()*this->get_re()+this->get_img()*this->get_img();
        double mod2=complex.get_re()*complex.get_re()+complex.get_img()*complex.get_img();
        return mod1<mod2;
     }
     bool Complex2D::operator>(Complex2D &complex){
        double mod1=this->get_re()*this->get_re()+this->get_img()*this->get_img();
        double mod2=complex.get_re()*complex.get_re()+complex.get_img()*complex.get_img();
        return mod1>mod2;
     }
     void Affichage(){
        cout<<endl<<this->get_re()<<"+"<<this->get_img()<<"i";
     }
