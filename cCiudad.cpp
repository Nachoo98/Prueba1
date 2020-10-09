#include "cCiudad.h"
cCiudad::cCiudad()
{
	nombre = "";
	x = 0;
	y = 0;
	poblacion = 0;
}

cCiudad::cCiudad(string nom, float X, float Y, int pob)
{
	nombre = nom;
	x = X;
	y = Y;
	poblacion = pob;
}

void cCiudad::Imprimir_Pantalla()
{
	string texto = to_string();
	cout << texto << endl;
}

string cCiudad::to_string()
{
	std::string X = std::to_string(x);
	std::string Y = std::to_string(y);
	std::string POB = std::to_string(poblacion);
	string texto = "Nombre: " + nombre + ", Latitud: " + X + ", Longitud: " + Y + ", Poblacion: " + POB;
	return texto;
}

cCiudad::~cCiudad()
{
}