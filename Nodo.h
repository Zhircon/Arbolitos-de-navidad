#include <iostream>
class Nodo{
    private:
    int identificador;
    Nodo *izq;
    Nodo *der;
    Nodo *padre;
    public:
    Nodo *crear(int dato){
        Nodo *nuevo=new Nodo();
        nuevo->setIdentificador(dato);
        nuevo->setIzq(NULL);
        nuevo->setDer(NULL);
        nuevo->padre=(NULL);
        return nuevo;
    }
    int getIdentificador(){
        return identificador;
    }
    Nodo *getIzq(){
        return izq;
    }
    Nodo *getDer(){
        return der;
    }
    Nodo *getPadre(){
        return padre;
    }
    void setPadre(Nodo *p){
        padre=p;
    }
    void setIdentificador(int n){
        identificador=n;
    }
    void setIzq(Nodo *n){
        izq=n;
    }
     void setDer(Nodo *n){
        der=n;
    }
};