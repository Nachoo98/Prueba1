#pragma once
#include<iostream>
#include <string>

using namespace std;

class cCiudad
{
private:
	string nombre;
	float x;//latitud
	float y;//longitud
	int poblacion;


public:
	cCiudad();
	cCiudad(string nom, float X, float Y, int pob);
	float getx() { return x; };
	float gety() { return y; };
	string getNOM() { return nombre; };

	void Imprimir_Pantalla();
	string  to_string();

	~cCiudad();
};