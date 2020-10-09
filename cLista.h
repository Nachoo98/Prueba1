#pragma once

#include <string>
#include <iostream>
#define NMAX 250
using namespace std;
template<class T>
class cLista
{
	T** vector;
	unsigned int CA;
	unsigned int TAM;
public:
	cLista(unsigned int TAM = NMAX);
	bool AgregarItem(T* item);
	T* Quitar(string codigo);
	T* Quitar(T* item);
	T* QuitarenPos(unsigned int pos);
	void Eliminar(string codigo);
	void Eliminar(const T* item);
	void Listar();
	T* BuscarItem(string codigo);
	T* getItem(unsigned int pos);
	int getCA() { return CA; }
	T* operator[](int pos);
	unsigned int getItemPos(string codigo);
	~cLista();

};

template<class T>
cLista<T>::cLista(unsigned int TAM)
{
	vector = new T * [TAM];
	for (unsigned int i = 0; i < TAM; i++)
	{
		vector[i] = NULL;
	}

	this->TAM = TAM;
	CA = 0;
}
template<class T>
cLista<T>::~cLista()
{
	if (vector != NULL)
	{
		for (unsigned int i = 0; i < CA; i++)
		{
			if (vector[i] != NULL)
				delete vector[i];
		}
		delete[] vector;
	}
}
template<class T>
void cLista<T>::Listar()
{

	for (unsigned int i = 0; i < CA; i++)
	{
		vector[i]->Imprimir();// imprimir
	}
}
template<class T>
T* cLista<T>::getItem(unsigned int pos)
{
	if (pos < CA)
		return vector[pos];
	else return NULL;
}
template<class T>
bool cLista<T>::AgregarItem(T* item)//REVISAR
{

	/*T *i_f = BuscarItem(item->getCodigo());
	if (i_f != NULL)throw new exception("Ya se encuentra en la lista");*/

	if (CA < TAM)
		vector[CA++] = item;
	else throw new exception("No hay tamaño suficiente para agregar el item");
	return true;
}
template<class T>
T* cLista<T>::Quitar(string codigo) {

	unsigned int pos = getItemPos(codigo);
	if (pos >= CA)return NULL;
	return QuitarenPos(pos);

}

template<class T>
T* cLista<T>::Quitar(T* item) {
	unsigned int pos = getItemPos(item->getCodigo());
	if (pos >= CA)return NULL;
	return QuitarenPos(pos);
}

template<class T>
T* cLista<T>::QuitarenPos(unsigned int pos) {

	if (pos >= CA)throw new exception("Posicion invalida");

	T* aux = vector[pos];

	for (unsigned int i = pos; i < CA - 1; i++)
	{
		vector[i] = vector[i + 1];
	}

	vector[CA - 1] = NULL;
	CA--;
	return aux;
}
template<class T>
void cLista<T>::Eliminar(string codigo)
{

	unsigned int pos = getItemPos(codigo);

	if (pos < CA)
		Eliminar(pos);
	//sino...

}
template<class T>
void cLista<T>::Eliminar(const T* item)
{

	Eliminar(item->getCodigo());
}
template<class T>
T* cLista<T>::BuscarItem(string codigo)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if ((*vector[i]).getCodigo() == codigo)
			return vector[i];
	}
	return NULL;
}
template<class T>
inline T* cLista<T>::operator[](int pos)//REVISAR
{
	if (pos < CA)
		return vector[pos];
	return NULL;
}
template<class T>
unsigned int cLista<T>::getItemPos(string codigo)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i]->getCodigo() == codigo)
			return i;
	}

	return INT_MAX;
}