#pragma once

#include <string>
#include <iostream>
#include <math.h>
#include "cCiudad.h"
//#include"cPeaje.h"
#include "cLista.h"

using namespace std;
class cVehiculo
{
private:
	string Marca;
	string Modelo;
	int anio;
	string color;//se puede hacer enum
	string patente;
	int peso;
	float tanqueLLENO;//limite de carga
	float tanqueACTUAL;
	float consumo;//x100km (8l por 100km o 16% por 100km)
	float kilometraje;//aranca en 0 (NO SE RESETEA NUNCA)
	float distancia;//mide la dist entre cada ciudad (SE RESETEA DESPUES DE CARGAR NAFTA)
	float lojack;//acum durante el camino por si se pierde
	int contTALLER;
	bool encamino;//TRUE si esta manejando, false si no
	cCiudad* ubicacion;
	static int CONTADOR;//cuenta las veces que tuvo que cargar tanque de emergencia

public:
	cVehiculo();//NO SE USA
	cVehiculo(string MARK, string MOD, int AN, string COL, string PAT, int PES, const float TL, float km, cCiudad* c);

	//gets
	string getMARCA() { return Marca; };
	string getMODELO() { return Modelo; };
	int getanio() { return anio; };
	string getcolor() { return color; };
	string getCodigo() { return patente; };//getpatente
	int getPeso() { return peso; };
	float getTLLENO() { return tanqueLLENO; };// get del tanque lleno	
	float getTACT() { return tanqueACTUAL; };// Get tanque actual, para ver cuanta nafta tiene
	//void setconsumo(float CONS) { consumo = CONS; };
	float getCONS() { return consumo; };//get consumo del auto
	float getKM() { return kilometraje; };//get del kilometraje del auto
	float getDIST() { return distancia; };//get de la distancia recorrida del trayecto
	int getcontTAL() { return contTALLER; };//get del contador de las veces que fue al taller
	bool getBOOL() { return encamino; };//devuelve estado del auto, encamino(True) o en casa(false)
	float getlojack() { return lojack; };//distancia acumulada del auto por si se pierde
	cCiudad getubicacion() { return *ubicacion; };//ubicacion de la ciudad
	static int getCONTADOR() { return CONTADOR; };
	
	//sets
	void setDIST(float DIST) { distancia = DIST; };//set distancia
	void setKM(float k) { kilometraje = k; };
	void settanqueact(float TACT);// Set Tanque actual, para cargar nafta
	void setlojack(float LJ) { lojack=LJ; };
	void setencamino(bool algo) { encamino = algo; };
	static void setCONTADOR(int algo) { CONTADOR = algo; };
	void setUBICACION(cCiudad* U) { ubicacion = U; };
	
	
	void ImprimirEnPantalla();
	void mantenimiento();//cada 1000km
	string to_strinG();
	void consumirtanque();
	void cargarNAFTA();

	float GPSDIST(cCiudad* c2);//Distancia en kilometros
	//void conducir(cCiudad* c2);
	void UbicacionACT();//Ubicacion actual
	float Chequearnafta();

	~cVehiculo();

};