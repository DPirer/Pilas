#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

// Prototipo de función
void agregarPila(Nodo *&,int);
void sacarPila(Nodo *&, int &);


int main()
{
    // Inicializamos la pila a NULL
    Nodo *pila = NULL;
    int dato;
    char respuesta;

    // Pedimos al usuario que ponga los elementos a introducir y llamamos a la función agregarPila
    while(true){
        cout<<"Introduzca un numero: "; cin>>dato;
        agregarPila(pila, dato);

        cout<<"Quiere introducir otro elemento? (y/n): "; cin>>respuesta;
        if (respuesta == 'n' || respuesta == 'N'){
            break;
        }
    }

    // Una vez tenemos todos los elementos, vamos sacándolos y mostrándolos por pantalla
    cout<<"\nSacando los elementos de la pila: ";
    while(pila != NULL){
        sacarPila(pila, dato);
        if (pila != NULL){
            cout<<dato<<", ";
        }
        else {
            cout<<dato<<".";
        }

    }
    cout<<endl<<endl;

    return 0;
}


void agregarPila(Nodo *&pila,int n){
    Nodo *nuevo_nodo = new Nodo();      // Rerservamos espacio en memoria de tipo Nodo
    nuevo_nodo -> dato = n;             // Metemos el dato en el nodo
    nuevo_nodo -> siguiente = pila;     // Hacemos que el siguiente apunte a pila, que era NULL
    pila = nuevo_nodo;                  // Y actualizamos la pila, que ahora es el nuevo nodo

    // Cuando haya más de un elemento, el proceso se repitirá indefinidamente. Pila no apuntará
    // a NULL, pero sí al siguiente nodo, creando así la cadena necesaria
    cout<<"Elemento agregado correctamente"<<endl;
}

void sacarPila(Nodo *&pila, int &n){ // El n hay que pasarlo por referencia porque dependerá del valor en la posición de la pila
    Nodo *aux = pila;                   // Creamos un nodo auxiliar que sea igual a la pila
    n = aux -> dato;                    // Le decimos a aux el dato al que apunta
    pila = aux -> siguiente;            // Avanzamos la pila a la siguiente posición
    delete aux;                         // Y eliminamos aux

    // Al igual que antes, el proceso se repite en bucle hasta que se llega al final de la pila
}
