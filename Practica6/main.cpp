#include <iostream>
#include <stdlib.h>

#include "clave.hpp"
#include "nodo.hpp"
#include "ABB.hpp"

using namespace std;

int main () {
    
    ABB<DNI> a;

    int opcion = 0;
    int contador = 0;
    DNI nuevo_dato;
    DNI eliminar_dato;
    DNI buscar_dato;
    
    cout << "-----ARBOLES BINARIOS DE BUSQUEDA.-----" << endl;
    cout << "MODO DEMOSTRACION" << endl;
    
    do {
        cout << "1.- Insertar." << endl;
        cout << "2.- Eliminar." << endl;
        cout << "3.- Buscar." << endl;
        cout << "4.- Salir" << endl;
        cout << "Opcion:";
        cin >> opcion;
        switch(opcion){
            
            case 1:
                cout << "Nuevo nodo que quiere insertar insertar:";
                cin >> nuevo_dato;
                a.insertar(nuevo_dato);
                a.imprimir();
                break;
            
            case 2:
                cout << "Dato que desea eliminar:";
                cin >> eliminar_dato;
                a.eliminar(eliminar_dato);
                a.imprimir();
                break;
                
            case 3:
                cout << "Dato que desea buscar:";
                cin >> buscar_dato;
                if(a.buscar(buscar_dato) != NULL){
                    cout << "Dato encontrado" << endl;   
                    cout << endl;
                }
                else{
                    cout << "Dato no encontrado" << endl;
                    cout << endl;
                }
                a.imprimir();
                break;
            
            case 4:
                cout << "Saliendo del programa.." << endl;
                break;
            
            default:
                cerr << "Opcion introducida no valida." << endl;
                opcion = 4;                
        }
        cout << "------------------------------------" << endl;
        cout << endl;
    } while(opcion != 4);
    
    cout << endl;

}