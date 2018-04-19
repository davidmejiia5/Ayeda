#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>

class clave;

using namespace std;
typedef clave DNI;

//Impresion del vector
template<class DNI>
void imprimir(vector<DNI> V){
    
    for(int i=0; i<V.size(); i++){
        cout << V[i];
        if(i<V.size()-1)
            cout << ",";
    }
    cout << endl;
}

template<class DNI>
void insercion(vector<DNI> V, int sz, int modo) {
    
    for(int i=1; i<sz; i++) {
        vector<int> aux;
        DNI a = V[i];
        int j = i-1;
        if(modo==1){
            cout << "Iteracion " << i-1 << endl;
            imprimir(V);
        }
        while((V[j]>a)&&(j>=0)){
            aux.resize(aux.size()+2);
            aux[0] = j;
            aux[1] = j+1;
            if(modo==1){
                cout << "Cambio " << V[j+1] << " en la posicion " << j+1 << " por " << V[j] << " en la posicion " << j << endl;
            }
            V[j+1] = V[j];
            j--;
            V[j+1] =a ;
            /*
            if(modo==1){
                llamar al metodo imprimir pero imprimiendo el vector ordenado
            }
            */
            aux.clear();
        }
        if(modo==1){
            cout << "\t************************************" << endl;
        }
        aux.clear();
    }
    if(modo==1){
        cout << endl;
        cout << "Vector ordenado : ";
        imprimir(V);
        cout << endl;
    }
}

template<class DNI>
void burbuja(vector<DNI> V, int sz, int modo) {
 
    for(int i=1; i<sz; i++){
        vector<int> aux;
        if(modo==1){
            cout << "Iteracion " << i-1 << endl;
            imprimir(V);
        }
        for(int j=sz-1; j>=i; j--){
            if(V[j]<V[j-1]){
                aux.resize(aux.size()+2);
                aux[0] = j;
                aux[1] = j-1;
                if(modo==1){
                    cout << "Cambio " << V[j-1] << " en la posicion " << j-1 << " por " << V[j] << " en la posicion " << j << endl;
                }
                DNI a = V[j-1];
                V[j-1] = V[j];
                V[j] = a;
                /*
                if(modo==1){
                    llamar al metodo imprimir pero imprimiendo el vector ordenado
                }
                */
                aux.clear();
            }
        }
        if(modo==1){
            cout << "\t*************************************" << endl;
        }
    } 
    if(modo==1){
        cout << endl;
        cout << "Vector ordenado : ";
        imprimir(V);
        cout << endl;
    }
}

template<class DNI>
void baja(int i,vector<DNI> &v,int n){
    int h1,h2,h;
    DNI x=v[i];
    while(2*i<n){
        h1=2*i+1;
        h2=h1+1;
        if(h1==n){
            h=h1;
        }else if(v[h1]>v[h2]){
            h=h1;
            }else{
                h=h2;
            }
        if(v[h]<=x){
            break;
        }else{
            v[i]=v[h];
            v[h]=x;
            i=h;
        }
    }
}

template<class DNI>
void casi_ordeno(int sz,vector<DNI> &v){
    for(int i=sz/2;i>0;i--)
        baja(i-1,v,sz);
}

template<class DNI>
void heapsort(vector<DNI> &v,int sz,int modo){
    clave aux;
    casi_ordeno(sz,v);
    for(int i=sz;i>1;i--){
        aux=v[0];
        v[0]=v[i-1];
        v[i-1]=aux;
        casi_ordeno(i-2,v);
    }
    if(v[0]>v[1]){
        aux=v[0];
        v[0]=v[1];
        v[1]=aux;
    }
}  

template<class DNI>
void quicksort(vector<DNI> V, int sz, int inicio, int final, int modo) {
    int i = inicio;
    int f = final;
    DNI p = V[(i+f)/2];
    while(i <= f){
        if(modo==1){
            cout << "Vector : ";
            imprimir(V);
            cout << endl;
        }
        while(V[i]<p){ i++; }
        while(V[f]>p){ f--; }
        if(i <= f){
            vector<int> aux;
            aux.resize(2);
            aux[0] = i;
            aux[1] = f;
            if(modo==1){
                cout << "Cambio " << V[i] << " en la posicion " << i << " por " << V[f] << " en la posicion " << f << endl;
            }
            DNI x = V[i];
            V[i] = V[f];
            V[f] = x;
            i++;
            f--;
            aux.clear();
        }
        if(modo==1){
            cout << "\t************************************"  << endl;
        }
    }
    if(inicio < f){ quicksort(V,sz,inicio,f,modo); }
    if(i < final){ quicksort(V,sz,i,final,modo); }
    if(modo==1){
        cout << endl;
        cout << "Vector ordenado : ";
        imprimir(V);
        cout << endl;
    }
}

template<class DNI>
void deltasort(int d, vector<DNI> V, int sz, int modo){
    for(int i=d; i<sz; i++){
        vector<int> aux;
        DNI x = V[i];
        int j=i;
        while((j>=d) && (x < V[j-d])){
            V[j] = V[j-d];
            j = j-d;
        }
        V[j] = x;
        if(modo==1){
        cout << "Vector -> ";
        imprimir(V);
        cout << endl;
        cout << "\t**************************************" << endl;
        }
    }
}
template<class DNI>
void shellsort(vector<DNI> V, int sz, double alfa, int modo) {
    
    int del = sz;
    while(del > 1){
        del = del*alfa;
        deltasort(del,V,sz,modo);
    }
}

