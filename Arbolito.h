#include<iostream>
#include "Nodo.h"
#include <windows.h>
using namespace std;
class Arbol{
private:
	Nodo* raiz=NULL;
	void recorrerBuscando(Nodo *raiz,Nodo *aux,int altura){
		if(aux==NULL){
				return;
		}else{
			if(altura==getLongitudProfundidad(raiz,aux->getIdentificador(),0)){
				cout<<aux->getIdentificador()<<endl;
			}
			recorrerBuscando(raiz,aux->getIzq(),altura);
			recorrerBuscando(raiz,aux->getDer(),altura);			
		}
	}
	void gotoxy(int x,int y){  
		HANDLE hcon;  
		hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
		COORD dwPos;  
		dwPos.X = x;  
		dwPos.Y= y;  
		SetConsoleCursorPosition(hcon,dwPos);  
	}  
	public: 
	void init() {
		raiz = NULL;
	}

	Nodo* getRaiz() {
		return raiz;
	}

	void newNodo(int n) {
		Nodo* nuevo = new Nodo();
		nuevo = nuevo->crear(n);

		if (raiz == NULL) { //EL �RBOL ES VACIO
			raiz = nuevo;
		}
		else 
			nextNodo(raiz, nuevo); //RECORRIDO RECURSIVO
	}

	void nextNodo(Nodo* aux, Nodo* nuevo) {
		if (aux == NULL)
			return;
		else {
			if (nuevo->getIdentificador() < aux->getIdentificador()) { //RECORRIDO A LA IZQUIERDA
				if (aux->getIzq() != NULL){
					nextNodo(aux->getIzq(), nuevo);
				}else{
					nuevo->setPadre(aux);
					aux->setIzq(nuevo);
				}
			}
			else if (nuevo->getIdentificador() > aux->getIdentificador()) { //RECORRIDO A LA DERECHA
				if (aux->getDer() != NULL){
					nextNodo(aux->getDer(), nuevo);
				}else{
					nuevo->setPadre(aux);
					aux->setDer(nuevo);
				}
					
			}
		}
	}

	int getLongitudProfundidad(Nodo *aux, int n, int contador) {
		if (aux != NULL) {
			if (n != aux->getIdentificador()) {
				if (n < aux->getIdentificador() && aux->getIzq() != NULL) {
					aux = aux->getIzq();
					getLongitudProfundidad(aux, n, contador + 1);
				}
				else {
					if (aux->getDer() != NULL) {
						aux = aux->getDer();
						getLongitudProfundidad(aux, n, contador + 1);
					}
					else
						return -1;
				}
			}
			else if (n == aux->getIdentificador())
				return contador;
			else
				return -1;
		}
		else
			return contador;
	}
	Nodo *buscarNodo(Nodo *aux,int buscar){
		if(aux==NULL){
			return NULL;
		}else{
			if(buscar==aux->getIdentificador()){
				return aux;
			}else{
				if(buscar<aux->getIdentificador()){
					aux=aux->getIzq();
					buscarNodo(aux,buscar);
				}else if(buscar>aux->getIdentificador()){
					aux=aux->getDer();
					buscarNodo(aux,buscar);
				}
			}
		}
	}
	int getAlturaNodo(Nodo* rama,Nodo *buscar){
		if(rama->getIzq()==NULL && rama->getDer()==NULL){
			int altura=0;
			Nodo *aux=rama;
				do{
				altura++;
				aux=aux->getPadre();
				}while(aux!=buscar);
				return altura;
		}else{
			return -1;
		}
	}
	void getArbol(Nodo* raiz, int cont) {
		if (raiz == NULL) {
			return;
		}
		else {
			
			getArbol(raiz->getDer(), cont + 1);
			for (int i = 0; i < cont; i++) {
				cout << "	";
			}
			cout << raiz->getIdentificador() << endl;
			getArbol(raiz->getIzq(), cont + 1);
		}
	}
	void preOrden(Nodo* aux) {
		if (aux == NULL)
			return;
		else {
			cout << aux->getIdentificador() << endl; //paso 1
			preOrden(aux->getIzq()); //paso 2
			preOrden(aux->getDer()); //paso 3
		}
	}
	void borrar(Nodo *aux){
		borrarSubarbol(aux);
		if(aux->getPadre()!=NULL){
			if(aux->getPadre()->getIzq()==aux){
				aux->getPadre()->setIzq(NULL);
			}else{
				aux->getPadre()->setDer(NULL);
			}
		}
		delete aux;
	}
	void borrarSubarbol(Nodo* aux) {
		if (aux == NULL){
			return;
		}else {
			borrarSubarbol(aux->getIzq()); //paso 2
			borrarSubarbol(aux->getDer()); //paso 3
			if(aux->getIzq()!=NULL) delete aux->getIzq();
			aux->setIzq(NULL);
			if(aux->getDer()!=NULL) delete aux->getDer();
			aux->setDer(NULL);
		}
	}
	void orden(Nodo* aux) {
		if (aux == NULL)
			return;
		else {
			orden(aux->getIzq()); //paso 1
			cout << aux->getIdentificador(); //paso 2
			orden(aux->getDer()); //paso 3
		}
	}
	void hermanosDe(Nodo *aux){
		Nodo *raiz=getRaiz();
		int altura=getLongitudProfundidad(raiz,aux->getIdentificador(),0);
		recorrerBuscando(raiz,raiz,altura);
	}

	void postOrden(Nodo* aux) {
		if (aux == NULL)
			return;
		else {
			postOrden(aux->getIzq());
			postOrden(aux->getDer());
			cout << aux->getIdentificador();
		}
	}
	void getArbolVertical(Nodo* raiz, int x,int y ,int isIzq) {
		if (raiz == NULL) {
			return;
		}
		else {
			y++;
			gotoxy(x,y);
			if(isIzq==1){
				cout <<"/";
			}else if(isIzq==2){
				cout<<((char)92);
			}else if(isIzq==0){
				cout<<"o";
			}
			y++;
			gotoxy(x,y);
			cout << raiz->getIdentificador();
			getArbolVertical(raiz->getDer(), x+2,y,2);
			getArbolVertical(raiz->getIzq(), x-2,y,1);
		}
		cout<<endl;
	}
};

