#include <iostream>
#include "clave.hpp"

using namespace std;

clave::clave(){
    cont_=0;
    q_=0;
}

clave::clave(int q,char letra){
    cont_=0;
    q_=q;
}

clave::~clave(){}

void clave::set_contador(long int cont){
    
    cont_ = cont;
    
}

int clave::get_contador() {
    
    return cont_;
    
}


int clave::get_dni() const{
    return q_;
}

char clave::get_letra(){
    return letra;
}


bool clave::operator==(clave &clave)
{
    cont_++;
    // cout << "Comparaciones: " << comparaciones << endl;

    if(q_ == clave.get_dni())
        return true;
    else
        return false;
}

bool clave::operator<(clave &clave)
{
    cont_++;
    // cout << "Comparaciones: " << comparaciones << endl;
    if(q_ == clave.get_dni()){
        if(letra<clave.get_letra()){
            return true;
        }else{
            return false;
        }
            
    }else{
        if(q_ < clave.get_dni())
        return true;
    else
        return false;
    }
}

bool clave::operator>(clave &clave)
{
    cont_++;
    // cout << "Comparaciones: " << comparaciones << endl;

    if(q_ == clave.get_dni()){
        if(letra>clave.get_letra()){
            return true;
        }else{
            return false;
        }
            
    }else{
        if(q_ > clave.get_dni())
        return true;
    else
        return false;
    }
}

bool clave::operator<=(clave &clave)
{
    cont_++;
    // cout << "Comparaciones: " << comparaciones << endl;
    
    if(q_ == clave.get_dni()){
        if(letra<=clave.get_letra()){
            return true;
        }else{
            return false;
        }
            
    }else{
        if(q_ <= clave.get_dni())
        return true;
    else
        return false;
    }
}

bool clave::operator>=(clave &clave)
{
    cont_++;
    // cout << "Comparaciones: " << comparaciones << endl;

if(q_ == clave.get_dni()){
        if(letra>=clave.get_letra()){
            return true;
        }else{
            return false;
        }
            
    }else{
        if(q_ >= clave.get_dni())
        return true;
    else
        return false;
    }
}

ostream& operator<<(ostream &salida,const clave clave)
{
    salida << clave.get_dni();
    return salida;
}

long int clave::cont_ = 0;