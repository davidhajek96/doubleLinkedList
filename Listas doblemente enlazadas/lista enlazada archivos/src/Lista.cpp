#include "Lista.h"
//#include "assert.h"

Lista::Lista(): prim(NULL) {
    // Completar
}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;

}

Lista::~Lista() {
    destruirNodos();
}
void Lista::copiarNodos(const Lista& aCopiar){
    Nodo* actual = aCopiar.prim;
    while (actual!= nullptr){
        agregarAtras(actual->valor);
        actual = actual->sig;
    }
}
void Lista::destruirNodos() {

    Nodo* actual = prim;
    Nodo* sig;
    while(actual!= nullptr){
        sig = actual->sig;
        delete actual;
        actual = sig;
    }
    prim = nullptr;

}

Lista& Lista::operator=(const Lista& aCopiar) {
    // Completar
    destruirNodos();
    copiarNodos(aCopiar);
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    Nodo* nuevo = new Nodo(elem, nullptr, nullptr);
    if(prim == NULL){
        prim = nuevo;
    }else{
        Nodo* actual = prim;
        nuevo->sig = actual;
        actual->ant= nuevo;
        prim = nuevo;

    }

}

void Lista::agregarAtras(const int& elem) {
    // Completar
    if (prim== nullptr){
        agregarAdelante(elem);
    }
    else{
        Nodo*   actual = prim;
        Nodo* nuevo = new Nodo(elem, nullptr, nullptr);

        while(actual->sig!= nullptr ){
            actual = actual->sig;
        }

        actual->sig = nuevo;
        nuevo->ant = actual;
    }
}

void Lista::eliminar(Nat i) {
    Nodo* actual = prim;
    Nodo* anterior;
    Nodo* posterior;

    if (i==0 && longitud()==1){
        actual->ant = nullptr;
        actual->sig = nullptr;
        delete actual;
        prim = nullptr;

    }else{
        if (i == 0 && longitud()!= 1){
            prim = actual->sig;
            anterior = actual;
            actual = actual->sig;
            actual->ant = nullptr;
            delete anterior;
        }else{
            if (i == longitud()-1){
                for (int j = 0; j < i; ++j) {
                    anterior = actual;
                    actual = actual->sig;
                    //posterior = actual->sig;
                }
                delete actual;

                anterior->sig = nullptr;

            }else{
                for (int j = 0; j < i; ++j) {
                    anterior = actual;
                    actual = actual->sig;
                    posterior = actual->sig;
                }
                //anterior = actual->ant;
                //posterior = actual->sig;
                anterior->sig = actual->sig;
                posterior->ant = actual->ant;

                delete actual;
            }
        }
    }

}



/*
 Nodo* actual = prim;
    for (int j = 1; j < i; ++j) {
        actual = actual->sig;
    }

    delete actual;

void Lista::eliminar(Nat i) {
    Nodo* actual = prim;
    Nodo* anterior = actual->ant;
    Nodo* posterior = actual->sig;

    if (i != 1){
        for (int j = 1; j < i; ++j) {

            actual = actual->sig;
            anterior = actual->ant;
            posterior = actual->sig;
        }
        anterior->sig = posterior;
        posterior->ant = anterior;

        delete actual;
    }else{
        delete actual;

    }



}
 */
int Lista::longitud() const {
    // Completar
    Nodo* actual = prim;
    int c = 0;
    while(actual!= nullptr ){
        c++;
        actual= actual->sig;
    }
    return c;
}

const int& Lista::iesimo(Nat i) const {
    // Completar
    Nodo* actual = prim;
    for (int j = 0; j < i; ++j) {
        actual = actual->sig;
    }
    //assert(actual->valor);
    return actual->valor;
}

int& Lista::iesimo(Nat i) {
    // Completar (hint: es igual a la anterior...)
    Nodo* actual = prim;
    for (int j = 0; j < i; ++j) {
        actual = actual->sig;
    }
    return actual->valor;
}

void Lista::mostrar(ostream& o) {
    // Completar
}