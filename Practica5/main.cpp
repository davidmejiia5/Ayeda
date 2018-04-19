#include <iostream>
#include <stdlib.h>
#include <vector>
#include "clave.hpp"
#include "m_ordenacion.hpp"

using namespace std;
typedef clave DNI;

int main (void) {

    int modo=1, metodo=0;
    int sz;
    cout << "Práctica 5, ordenación dentro de un vector" << endl;
    cout << "MODO DEMOSTRACION" << endl;
    
    cout << "Introduzca el tamaño del vector de claves : ";
    cin >> sz;
    vector<DNI> V;
    V.clear();
    V.resize(sz);
    
    //insertar claves en el vector de claves
    char cadena[] = "TRWAGMYFPDXBNJZSQVHLCKE";
    for(int i=0;i<sz;i++){
        int auxi =  30000000 + rand()%(80000001-30000000);
        int a= rand()%22;
        DNI A(auxi,cadena[a]);
        V[i] = A;
    }

    cout <<"¿Qué método desea probar?" << endl;
    cout << "1. Inserción " << endl;
    cout << "2. Por intercambio (Burbuja)" << endl;
    cout << "3. Heapsort" << endl;
    cout << "4. Quicksort" << endl;
    cout << "5. Shellshort" << endl;
    cout << "Introduzca una opcion : ";
    cin >> metodo;
    cout << endl;
    
    switch(metodo){
        case 1:     
                    cout << "***** Metodo de inserción ***** " << endl;
                    cout << "Vector desordenado ->  "; 
                    imprimir(V);
                    cout << endl;
                    insercion(V,sz,modo);
                    break;
        case 2:     
                    cout << "***** Metodo de la burbuja ***** " << endl;
                    cout << "Vector desordenado ->  ";
                    imprimir(V);
                    cout << endl;
                    burbuja(V,sz,modo);
                    break;
        case 3:     
                    cout << "***** Metodo Heapsort ***** " << endl;
                    cout << "Vector desordenado ->  ";
                    imprimir(V);
                    cout << endl;
                    heapsort(V,sz,modo);
                    cout << "Vector ordenado ->  ";
                    imprimir(V);
                    break;
        case 4:    
                    cout << "***** Metodo Quicksort ***** " << endl;
                    cout << "Vector desordenado ->  ";
                    imprimir(V);
                    cout << endl;
                    quicksort(V,sz,0,V.size()-1,modo);
                    break;
        case 5:     
                    cout << "***** Metodo Shellsort ***** " << endl;
                    cout << "Vector desordenado ->  ";
                    imprimir(V);
                    cout << endl;
                    cout << "Introduzca valor de alfa[entre 0 y 1] : "; 
                    double alfa;
                    cin >> alfa;
                    shellsort(V,sz,alfa,modo);
                    break;
        default:    
                    cout << "Metodo mal escogido";
                    break;
    }
        
}