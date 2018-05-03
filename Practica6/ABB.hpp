#pragma once
#include <queue>
#include <iostream>
#include "nodo.hpp"
#include "clave.hpp"

typedef struct {
    nodo<DNI>* nd;
    int nivel;
} nodo_t;

template<class DNI>
class ABB {
    
    private:
    
        nodo<DNI>* raiz_;
        int num_niveles,num_nodos;
        
    public:
    
        ABB();
        ~ABB();
        void podar(nodo<DNI>* &nodo);
        void insertarRama(nodo<DNI>* &nd, DNI x);
        nodo<DNI>* get_raiz(void);
        nodo<DNI>* buscarRama(nodo<DNI>* nodo, DNI x);
        void eliminarRama(nodo<DNI>* &nodo, DNI x);
        void sustituye(nodo<DNI>* &eliminado, nodo<DNI>* &sust);
        void imprimirArbol(nodo<DNI>* nodo);
        bool eshoja(nodo<DNI>* nodo);
        bool si_vacio(void);
        
        nodo<DNI>* buscar(DNI x);
        void insertar(DNI x);
        void eliminar(DNI x);
        void imprimir();
};

template<class DNI>
ABB<DNI>::ABB(): num_niveles(0), num_nodos(0), raiz_(NULL) {}

template<class DNI>
ABB<DNI>::~ABB() {
    podar(raiz_);
}

template<class DNI>
void ABB<DNI>::podar(nodo<DNI>* &nodo) {
    if(nodo==NULL) return;
    podar(nodo->izq_);
    podar(nodo->der_);
    delete nodo;
    nodo = NULL;
}

template<class DNI>
void ABB<DNI>::insertarRama(nodo<DNI>* &nd, DNI x) {
    if(nd==NULL){
        nd = new nodo<DNI>(x);
        num_nodos++;
    }   
    else
    {
        if(x < nd->x_)
            insertarRama(nd->izq_,x);
        else
            insertarRama(nd->der_, x);
    }
}

template<class DNI>
nodo<DNI>* ABB<DNI>::get_raiz() {
    return raiz_;
}

template<class DNI>
nodo<DNI>* ABB<DNI>::buscarRama(nodo<DNI>* nodo, DNI x) {
    if(nodo==NULL)
        return NULL;
    if(x == nodo->x_)
        return nodo;
    if(x < nodo->x_)
        return buscarRama(nodo->izq_, x);
    return buscarRama(nodo->der_, x);
}

template<class DNI>
void ABB<DNI>::sustituye(nodo<DNI>* &eliminado, nodo<DNI>* &sust) {
    if(sust->der_ != NULL)
        sustituye(eliminado, sust->der_);
    else
    {
        eliminado->x_ = sust->x_;
        eliminado = sust;
        sust = sust->izq_;
    }
}

template<class DNI>
void ABB<DNI>::eliminarRama(nodo<DNI>* &nd, DNI x) {
    if(nd==NULL)
        return;
    if(x < nd->x_)
        eliminarRama(nd->izq_,x);
    else
    {
        if(x > nd->x_)
            eliminarRama(nd->der_,x);
        else
        {
            nodo<DNI>* elimina = nd;
            if(nd->der_ == NULL)
                nd = nd->izq_;
            else
            {
                if(nd->izq_ == NULL)
                    nd = nd->der_;
                else sustituye(elimina, nd->izq_);
            }
        delete(elimina);
        }
    }
}

template<class DNI>
bool ABB<DNI>::eshoja(nodo<DNI>* nodo) {
    return !nodo->der_ && !nodo->izq_;
}

template<class DNI>
bool ABB<DNI>::si_vacio() {
    return raiz_ == NULL;
}


template<class DNI>
void ABB<DNI>::imprimirArbol(nodo<DNI>* nd) {
    
    cout << "Numero de nodos del arbol:" << num_nodos << endl;
    queue<nodo_t> Q;
    
    
    nodo_t raiz;

    int nivel = 0;
    int nivel_actual = 0;
    bool final = false;
    nodo_t nodo_actual;
    
    raiz.nd = raiz_;
    raiz.nivel = 0;
    Q.push(raiz);
    cout << "Nivel " << nivel_actual << ":\t";
    while(!Q.empty())
    {
        nodo_actual = Q.front();
        Q.pop();
        if(nodo_actual.nivel > nivel_actual)
        {
            nivel_actual = nodo_actual.nivel;   
            cout << endl;
            cout << "Nivel " << nivel_actual << ":\t"; 
        }
        if(nodo_actual.nd != NULL)
        {
            cout << (nodo_actual.nd)->x_ << "\t";
            
            nodo_t hijo_izquierdo;
            nodo_t hijo_derecho;
            
            if((nodo_actual.nd)->izq_ != NULL)
            {
                hijo_izquierdo.nd = (nodo_actual.nd)->izq_;
            }
            else
            {
                hijo_izquierdo.nd = NULL;
            }
            if((nodo_actual.nd)->der_ != NULL)
            {
                hijo_derecho.nd = (nodo_actual.nd)->der_;
            }
            else
            {
                hijo_derecho.nd = NULL;
            }   
            
            hijo_izquierdo.nivel = nivel_actual+1;
            hijo_derecho.nivel = nivel_actual+1;
            Q.push(hijo_izquierdo);
            Q.push(hijo_derecho);
        }
        else
        {
            //Subárbol vacío
            cout << "[.]" << "\t";
        }
    }
}


template<class DNI>
nodo<DNI>* ABB<DNI>::buscar(DNI x) {
    return buscarRama(raiz_,x);
}

template<class DNI>
void ABB<DNI>::insertar(DNI x) {
    insertarRama(raiz_,x);
}

template<class DNI>
void ABB<DNI>::eliminar(DNI x) {
    eliminarRama(raiz_,x);
}

template<class DNI>
void ABB<DNI>::imprimir() {
    cout << "Imprimiendo árbol" << endl;
    if(si_vacio())
        cout << "El árbol está vacío" << endl;
    else 
        imprimirArbol(raiz_);
    
    cout << endl;
}