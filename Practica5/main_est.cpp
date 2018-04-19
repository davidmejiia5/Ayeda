#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include "clave.hpp"
#include "m_ordenacion.hpp"

using namespace std;
typedef clave DNI;

struct estadistica {
    string nombre;
    int maximo;
    long int minimo;
    double media;
};

void imprimir_estadisticas(vector<estadistica> est) {
    cout << "Tabla de estadisticas:" << endl;
    cout << "\t\t"<<"Mayor"<<"\t"<<"Media"<<"\t"<<"Menor"<<endl;
    cout<<est[0].nombre<<"\t\t"<<est[0].maximo<<"\t"<<est[0].media<<"\t"<<est[0].minimo<<endl;
    for(int i=1;i<est.size();i++) {
        cout<<est[i].nombre<<"\t"<<est[i].maximo<<"\t"<<est[i].media<<"\t"<<est[i].minimo<<endl;
    }
}

int main (void) {
  
    int modo=2;
    int sz;
    int npruebas;
    vector<estadistica> estadisticas;
    vector< vector<DNI> > P;
    cout << "***********MODO ESTADISTICO*************" << endl;
    cout << "Introduzca el tamaño del vector de claves : ";
    cin >> sz;
    cout << endl;
    cout << "Introduzca el numero de vectores sobre los que ejecutar las pruebas => ";
    cin >> npruebas;
    cout << endl;
    
    for(int i=0;i<npruebas;i++) {
      vector<DNI> aux;
      
      aux.resize(sz);
      for(int j=0; j<sz; j++){
          int pepe = 30000000 + rand() %(80000001-30000000);
          DNI w(pepe);
          aux[j] = w;
      }
      
      P.resize(P.size()+1);
      P[i] = aux;
    }
    
   /*
    for(int i=0;i<P.size();i++){
    cout << "Vector " << i << " =>\t" ;
    for(int j = 0;j<sz;j++)
    {
      cout << P[i][j];
      if(j < sz-1)
        cout << ",";
    }
    cout << endl;
    }
    */
    /*
        METODO DE LA BURBUJA
    */
    struct estadistica bur;
    bur.nombre = "Burbuja";
    bur.maximo = 0;
    bur.minimo = 2147483647;
    vector<int> comparaciones_burbuja;
    double suma = 0;
    comparaciones_burbuja.resize(sz);
    
    for(int i=0;i<npruebas;i++)
    {
    vector<DNI> copia = P[i];
    burbuja(copia,sz,modo);
    comparaciones_burbuja[i] = DNI::cont_;
    if(bur.maximo < DNI::cont_)
    {
      bur.maximo = DNI::cont_;
    }
    if(bur.minimo > DNI::cont_)
    {
      bur.minimo = DNI::cont_;
    }
    suma += comparaciones_burbuja[i];
    DNI::cont_ = 0;
    }
    bur.media = (suma / npruebas);
    estadisticas.resize(estadisticas.size()+1);
    estadisticas[0] = bur;
    DNI::cont_ = 0;
    
    
    /*
        METODO DE INSERCION
    */
    struct estadistica ins;
    ins.nombre = "Insercion";
    ins.maximo = 0;
    ins.minimo = 2147483647;
    vector<int> comparaciones_insercion;
    double suma1 = 0;
    comparaciones_insercion.resize(sz);
    for(int i=0;i<npruebas;i++) {
        vector<DNI> copia = P[i];
        insercion(copia,sz,modo);
        comparaciones_insercion.resize(comparaciones_insercion.size()+1);
        comparaciones_insercion[i] = DNI::cont_;
        if(ins.maximo < DNI::cont_)
        {
          ins.maximo = DNI::cont_;
        }
        if(ins.minimo > DNI::cont_)
        {
          ins.minimo = DNI::cont_;
        }
        
        DNI::cont_ = 0;
        suma1 += comparaciones_insercion[i];
    }
    ins.media = (suma1 / npruebas);
    estadisticas.resize(estadisticas.size()+1);
    estadisticas[1] = ins;
    
    /*
        METODO QUICKSORT
    */
    struct estadistica qck;
    qck.nombre = "Quicksort";
    qck.maximo = 0;
    qck.minimo = 2147483647;
    vector<int> comparaciones_quicksort;
    double suma2 = 0;
    comparaciones_quicksort.resize(sz);
    for(int i=0;i<npruebas;i++) {
        vector<DNI> copia = P[i];
        quicksort(copia,sz,0,sz-1,modo);
        comparaciones_quicksort.resize(comparaciones_quicksort.size()+1);
        comparaciones_quicksort[i] = DNI::cont_;
        if(qck.maximo < DNI::cont_)
        {
          qck.maximo = DNI::cont_;
        }
        
        if(qck.minimo > DNI::cont_)
        {
          qck.minimo = DNI::cont_;
        }
        suma2 += comparaciones_quicksort[i];
        DNI::cont_ = 0;
    }
    qck.media = (suma2 / npruebas);
    estadisticas.resize(estadisticas.size()+1);
    estadisticas[2] = qck;
    
    cout << endl;
    
    /*
        METODO SHELLSORT
    */
    struct estadistica shll;
    shll.nombre = "Shellsort";
    shll.maximo = 0;
    shll.minimo = 2147483647;
    vector<int> comparaciones_shellsort;
    double suma4 = 0;
    comparaciones_shellsort.resize(sz);
    double alfa = 0;
    cout << "Introduzca alfa:[entre 0 y 1] => ";
    cin >> alfa;
    cout << endl;
    for(int i=0;i<npruebas;i++) {
        vector<DNI> copia = P[i];
        shellsort(copia,sz,alfa, modo);
        comparaciones_shellsort.resize(comparaciones_shellsort.size()+1);
        comparaciones_shellsort[i] = DNI::cont_;
        if(shll.maximo < DNI::cont_) {
          shll.maximo = DNI::cont_;
        }
        if(shll.minimo > DNI::cont_){
          shll.minimo = DNI::cont_;
        }
        DNI::cont_ = 0;
        suma4 += comparaciones_shellsort[i];
    }
    shll.media = (suma4 / npruebas);
    estadisticas.resize(estadisticas.size()+1);
    estadisticas[3] = shll;
  
   /*
        METODO HEAPSORT
    */
    struct estadistica heap;
    heap.nombre = "Heapsort";
    heap.maximo = 0;
    heap.minimo = 2147483647;
    vector<int> comparaciones_heapsort;
    double suma5 = 0;
    comparaciones_heapsort.resize(sz);
    for(int i=0;i<npruebas;i++) {
        vector<DNI> copia = P[i];
        heapsort(copia,sz,modo);
        comparaciones_heapsort.resize(comparaciones_heapsort.size()+1);
        comparaciones_heapsort[i] = DNI::cont_;
        if(heap.maximo < DNI::cont_)
        {
          heap.maximo = DNI::cont_;
        }
        
        if(heap.minimo > DNI::cont_)
        {
          heap.minimo = DNI::cont_;
        }
        suma5 += comparaciones_heapsort[i];
        DNI::cont_ = 0;
    }
    heap.media = (suma5 / npruebas);
    estadisticas.resize(estadisticas.size()+1);
    estadisticas[4] = heap;
    
    cout << endl;
    imprimir_estadisticas(estadisticas);
}

