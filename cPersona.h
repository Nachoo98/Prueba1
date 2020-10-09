#pragma once
#include<iostream>
#include <string>
#include "cVehiculo.h"

using namespace std;

class cPersona
{
	
	string nombre;
	string apellido;
	string dni;
	float billetera;
	cVehiculo *vehiculo[3];

public:
	cPersona(string nom, string ape, string DNI, cVehiculo* v1);
	void Comprarvehiculo(cPersona* ven);//al cliente(el que llama la funcion) se le pasa el vendedor
	void VenderVehiculo(cPersona* cliente);//vendedor llama la funcion
	void vendido(int pos);//Vende auto entonces el espacio de auto apunta a NULL
	void setV(int i, cVehiculo* v);//Set vehiculo
	void Imprimir_Pantalla();
	string getCodigo() {return dni;};//getDNI
	string to_string();
	
	cVehiculo getVehiculo(int a) { return *vehiculo[a]; }
	
	int getbilletera() { return billetera; };
	void setbilletera(int wallet) { billetera = wallet; };
	void pagaralgo(float precioo) { billetera = billetera - precioo; }
	void cargarnafta(int i);// el int i que se le pasa es para que elija dentro de sus autos, default seria 0
	void conducir(cCiudad* c2,int i);
	void Trabajar(float minimo);
	~cPersona();
};