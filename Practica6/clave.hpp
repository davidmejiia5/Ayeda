#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>


using namespace std;

class clave { 
    
    private:
        
        int q_;
    
    public:
    
        static long int cont_;
        
        clave();
        clave(int q);
        ~clave();
        void set_dni(int q);
        int get_dni() const;
        
        bool operator==(clave &q_);
        bool operator<(clave &q_);
        bool operator>(clave &q_);
        bool operator<=(clave &q_);
        bool operator>=(clave &q_);
        
        friend ostream& operator<<(ostream &salida, clave clave);
        friend istream& operator >>(istream& sin, clave& n);
};