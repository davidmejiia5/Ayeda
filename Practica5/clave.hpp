#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>


using namespace std;

class clave { 
    
    private:
        
        int q_;
        char letra;
    
    public:
    
        static long int cont_;
        
        clave();
        clave(int q,char letra);
        ~clave();
        void set_contador(long int cont);
        int get_contador();
        int get_dni() const;
        char get_letra();
        
        // sobrecarga de operadores
        bool operator==(clave &q_);
        bool operator<(clave &q_);
        bool operator>(clave &q_);
        bool operator<=(clave &q_);
        bool operator>=(clave &q_);
        
        friend ostream& operator<<(ostream &salida, clave clave);
        
};