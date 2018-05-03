#include <iostream>
#include "clave.hpp"

using namespace std;

clave::clave(){
    cont_=0;
    q_=0;
}

clave::clave(int q){
    cont_=0;
    q_=q;
}

clave::~clave(){}

void clave::set_dni(int q){
    q_ = q;    
}

int clave::get_dni() const{
    return q_;
}


bool clave::operator==(clave &clave)
{
    cont_++;
    if(q_ == clave.get_dni())
        return true;
    else
        return false;
}

bool clave::operator<(clave &clave)
{
    cont_++;
    if(q_ < clave.get_dni())
        return true;
    else
        return false;
}

bool clave::operator>(clave &clave)
{
    cont_++;
    if(q_ > clave.get_dni())
        return true;
    else
        return false;
}

bool clave::operator<=(clave &clave)
{
    cont_++;
    if(q_ <= clave.get_dni())
        return true;
    else
        return false;
}

bool clave::operator>=(clave &clave)
{
    cont_++;
    if(q_ >= clave.get_dni())
        return true;
    else
        return false;
}

ostream& operator<<(ostream &salida,const clave clave)
{
    salida << clave.get_dni();
    return salida;
}

istream& operator >>(istream& sin, clave& clave)
{
     int auxiliar = 0;
     sin >> auxiliar;
     clave.set_dni(auxiliar);
     return sin;
}

long int clave::cont_ = 0;