#pragma once
#include <string>
#include<iostream>
#include "cPersona.h"
#include <ctime>


using namespace std;

class cPeaje
{
	string nombre;
	int caja;
	//bool telepeaje;
	static int contPARO;

public:
	cPeaje();
	cPeaje(string NOM, int BOX);//, bool TELE); No sirve el telepeaje por ahora, no se que se te ocurre
	void Cabina(cPersona *P);//recibe y dependiendo de un rand hay paro o no, CABINA incluye COBRAR!!
	void cobrar(cPersona *p);
	float Ganancias() { return caja; };
	static int getcantParos() { return contPARO; };
	~cPeaje();


};