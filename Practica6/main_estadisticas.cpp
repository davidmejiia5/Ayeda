#include <iostream>
#include <vector>

#include "clave.hpp"
#include "nodo.hpp"
#include "ABB.hpp"

using namespace std;

template <class DNI>
bool comprobar_aleatorios_dni(vector<DNI> v_aleatorios, int valor)
{
  int contador = 0;
  bool encontrado = false;
  while(contador < v_aleatorios.size() && encontrado != true)
  {
    if(v_aleatorios[contador].get_dni() == valor)
    {
      encontrado = true;
    }
    contador++;
  }
  return encontrado;
}

template <class DNI>
void inicializar_vector(vector<DNI> &v, ABB<DNI> &arbol_, int tamanio)
{
    v.resize(tamanio);
    for(int i=0;i<tamanio;i++)
    {
        srand(clock());
        int aux = 10000000 + rand()%(99999999-10000000);
        
        while(comprobar_aleatorios_dni(v,aux))
        {
            aux = 10000000 + rand()%(99999999-10000000);
        }
    
        DNI d(aux);
        v[i] = d;
        arbol_.insertar(d);
    }
}

bool comprobar_aleatorios_pruebas(vector<int> v_aleatorios, int valor)
{
  int contador = 0;
  bool encontrado = false;
  while(contador < v_aleatorios.size() && encontrado != true)
  {
    if(v_aleatorios[contador] == valor)
    {
      encontrado = true;
    }
    contador++;
  }
  return encontrado;
}

void generar_aleatorios(vector<int> &v, int limite_inferior, int limite_superior)
{
  for(int i=0;i<v.size();i++)
  {
      srand(clock());
      int aux_p = limite_inferior+rand()%(((limite_superior + 1 ) -1) -limite_inferior);
      while(comprobar_aleatorios_pruebas(v,aux_p))
      {
         aux_p = limite_inferior+rand()%(((limite_superior + 1 ) -1) -limite_inferior);
      }
      v[i] = aux_p;
  }
}

int main () {
    
    int num_nodos,num_pruebas;
    vector<DNI> muestra;
    vector<int> pruebas_busqueda;
    vector<int> pruebas_insercion;
    
    ABB<DNI> a;
    
    cout << "-----ARBOLES BINARIOS DE BUSQUEDA.-----" << endl;
    cout << "MODO ESTADISTICO" << endl;
    cout << "Introduzca el número de nodos: ";
    cin >> num_nodos;
    cout << "Introduzca el número de pruebas a realizar: ";
    cin >> num_pruebas;
    inicializar_vector(muestra, a, num_nodos*2);
    cout << "-------------------------" << endl;
    
    pruebas_busqueda.resize(num_pruebas);
    
    generar_aleatorios(pruebas_busqueda,0,num_nodos);
    
    cout << endl;
    int maximo_busqueda = 0;
    int minimo_busqueda = 214748364;
    double suma_busqueda = 0;
    double media_busqueda = 0;
    
    DNI::cont_ = 0;
    for(int i=0; i<num_pruebas;i++) {
        a.buscar(muestra[pruebas_busqueda[i]]);
        if(maximo_busqueda<DNI::cont_)
            maximo_busqueda = DNI::cont_;
        if(minimo_busqueda>DNI::cont_)
            minimo_busqueda = DNI::cont_;
        suma_busqueda += DNI::cont_;
        DNI::cont_ = 0;   
    }
    media_busqueda = suma_busqueda / num_pruebas;
    
    cout << endl;
    
    pruebas_insercion.resize(num_pruebas);
    
    generar_aleatorios(pruebas_insercion,num_nodos,2*num_nodos);
    
    int maximo_insercion = 0;
    int minimo_insercion = 214748364;
    double suma_insercion = 0;
    double media_insercion = 0;
    
    DNI::cont_ = 0;
    for(int i=0; i<num_pruebas; i++){
        a.buscar(muestra[pruebas_insercion[i]]);
        if(maximo_insercion < DNI::cont_)
            maximo_insercion = DNI::cont_;
        if(minimo_insercion > DNI::cont_)
            minimo_insercion = DNI::cont_;
        suma_insercion += DNI::cont_;
        DNI::cont_ = 0;
    }
    media_insercion = suma_insercion / num_pruebas;
    cout << endl;
    cout << "-----------------------------" << endl;
        
    cout << "ESTADISTICAS" << endl;
    cout << "\t\tN\tP\tMinimo\tMedio\tMaximo"<<endl;
    cout << "Busqueda\t"<<num_nodos<<"\t"<<num_pruebas<<"\t"<<minimo_busqueda<<"\t"<<media_busqueda<<"\t"<<maximo_busqueda<<endl;
    cout << "Insercion\t"<<num_nodos<<"\t"<<num_pruebas<<"\t"<<minimo_insercion<<"\t"<<media_insercion<<"\t"<<maximo_insercion<<endl;

}