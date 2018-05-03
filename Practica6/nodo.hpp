#pragma once
#include <iostream>
#include <cctype>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class clave; 
typedef clave DNI;

template<class DNI>
class nodo {
    
    public:
    
        nodo<DNI>* izq_;
        nodo<DNI>* der_;
        DNI x_;
    
    
        nodo();
        ~nodo();
        nodo(DNI x);
        DNI get_dato(void);
        void set_dato(DNI x);
        
        void set_izquierda(nodo<DNI>* izquierda);
        nodo<DNI>* get_izquierda(void);
        void set_derecha(nodo<DNI>* derecha);
        nodo<DNI>* get_derecha(void);
        
};

template<class DNI>
nodo<DNI>::nodo(): izq_(NULL), der_(NULL) {}

template<class DNI>
nodo<DNI>::nodo(DNI x): x_(x), izq_(NULL), der_(NULL) {}

template<class DNI>
nodo<DNI>::~nodo() {
    if(izq_ != NULL) {
        delete izq_;
        izq_ = NULL;
    }
    if(der_ != NULL) {
        delete der_;
        der_ = NULL;
    }
}

template<class DNI>
DNI nodo<DNI>::get_dato() {
    return x_;
}

template<class DNI>
void nodo<DNI>::set_dato(DNI x){
    x_ = x;
}

template<class DNI>
void nodo<DNI>::set_izquierda(nodo<DNI>* izquierda) {
    izq_ = izquierda;
}

template<class DNI>
nodo<DNI>* nodo<DNI>::get_izquierda() {
    return izq_;
}

template<class DNI>
void nodo<DNI>::set_derecha(nodo<DNI>* derecha) {
    der_ = derecha;
}

template<class DNI>
nodo<DNI>* nodo<DNI>::get_derecha() {
    return der_;
}