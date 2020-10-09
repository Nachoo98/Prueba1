#include "cVehiculo.h"
#include "cPersona.h"
#define PI 3.14159265
int cVehiculo::CONTADOR = 0;
cVehiculo::cVehiculo()
{
	Marca = "";
	tanqueLLENO = 50;
	consumo = 8;
	Modelo = "";
	anio = 0;
	color = "";
	patente = "";
	peso = rand() % 2000;
	tanqueACTUAL = 0;
	kilometraje = 0;
	distancia = 0;
	contTALLER = 0;
	encamino = false;
	lojack = 0;
}

cVehiculo::cVehiculo(string MARK, string MOD, int AN, string COL, string PAT, int PES, const float TL, float km, cCiudad* c)
{
	Marca = MARK;
	Modelo = MOD;
	tanqueLLENO = TL;
	consumo = 8;
	anio = AN;
	color = COL;
	patente = PAT;
	peso = PES;
	tanqueACTUAL = float(TL);//arranca lleno
	kilometraje = km;
	distancia = 0;
	contTALLER = 0;
	encamino = false;
	lojack = 0;
	ubicacion = c;

}

void cVehiculo::settanqueact(float TACT)
{
	if (TACT >= 0) tanqueACTUAL = TACT;
	else cout << "Fijate que le pussiste un - !!, ahora nos quedamos sin nafta en la ruta y al ACA lo llamas vos";
}

void cVehiculo::mantenimiento()
{
	float K = getKM();
	int x = getcontTAL() + 1;
	int r = rand() % 5;
	if (K >= 1000 && x == 1)
	{
		if (r == 0) { cout << "Bateria cambiada" << endl; }
		if (r == 1) { cout << "Bugia cambiada" << endl; }
		if (r == 2) { cout << "Frenos cambiados" << endl; }
		if (r == 3) { cout << "Luces cambiadas" << endl; }
		if (r == 4) { cout << "Aceite cambiado" << endl; }
		contTALLER++;
	}
	if (x != 0)
	{
		if (K >= (1000 * x))
		{
			if (r == 0) { cout << "Bateria cambiada" << endl; }
			if (r == 1) { cout << "Bugia cambiada" << endl; }
			if (r == 2) { cout << "Frenos cambiados" << endl; }
			if (r == 3) { cout << "Luces cambiadas" << endl; }
			if (r == 4) { cout << "Aceite cambiado" << endl; }
			contTALLER++;
		}

	}


}
void cVehiculo::ImprimirEnPantalla()
{
	string Texto = to_strinG();
	cout << Texto << "Marca: " << getMARCA() << "Modelo: " << getMODELO() << "Color: " << getcolor() << "patente: " << getCodigo() << endl;
}
string cVehiculo::to_strinG()
{
	std::string TACT = std::to_string(tanqueACTUAL);
	std::string TL = std::to_string(tanqueLLENO);
	std::string AN = std::to_string(anio);
	std::string KM = std::to_string(kilometraje);
	std::string C = std::to_string(consumo);
	string texto = "Tanque actual: " + TACT + "Tamanio de tanque: " + TL + "Anio de Fabricacion: " + AN + "kilometraje: " + KM + "Consumo: " + C;
	return texto;
}

void cVehiculo::consumirtanque()
{
	for (int i = 1; i < 100; i++)
	{
		float a = getTACT();
		if (getTACT() == float(i) * 100)
		{
			a = a - 8;
			settanqueact(a);
		}
		if (getTACT() < 10) { CONTADOR++; }
	}
}

void cVehiculo::cargarNAFTA()
{
	int a;
	float preciolitro = 60;
	float b = getTLLENO();
	float T = getTACT();
	T = T / b;

	cout << "Tiene" << T << "% del tanque lleno" << endl;

	cout << "Le lleno el tanque maestro?" << endl;
	cout << "ingrese 0 para que le llene el tanque:" << endl;
	//cin >> a;
	a = rand() % 2;
	if (a == 0)
	{
		float b = getTLLENO();
		float litros = b - T;
		settanqueact(b);
		cout << "su tanque se lleno completamente" << endl;
		setDIST(0);
	}
	else if (a != 0)
	{
		float e;
		cout << "cuanto le lleno? (en %) (ej: 90)" << endl;
		//cin >> e;
		e = 1 + rand() % 100;
		float d = (e / 100);
		d = d * b;
		settanqueact(d);
		setDIST(0);
	}

}
//calcula distancia
float cVehiculo::GPSDIST(cCiudad* c2)
{
	float D;
	float R = 6731000;//en metros
	float latinicial = ubicacion->getx();
	latinicial = latinicial * PI / 180;
	float longinicial = ubicacion->gety();
	float latfinal = c2->getx();
	latfinal = latfinal * PI / 180;
	float longfinal = c2->gety();
	float DLAT = (float(latfinal) - float(latinicial)) * PI / 180;
	float DLONG = (float(longfinal) - float(longinicial)) * PI / 180;
	float a = sin(DLAT / 2) * sin(DLAT / 2) + cos(latinicial) * cos(latfinal) * sin(DLONG / 2) * sin(DLONG / 2);
	float c = 2 * atan2(sqrt(a), sqrt(1 - a));
	D = R * c;

	return D;
}

/*void cVehiculo::conducir(cCiudad* c2)// lo hace persona
{

	lojack = 0;
	float N = Chequearnafta();
	float d = GPSDIST(c2);
	//float a=
	//cLista<cPeaje>peajes((rand() %(ceil(d / 50) + 1))); //creo una cantidad de peajes de entre 0 y d/50

	int PROBLEMA = 0;
	if (N < 25)
	{
		cargarnafta();
	}

	for (int i = 0; i < d; i++) //i es 1km
	{


		encamino = true;
		consumirtanque();
		mantenimiento();
		kilometraje++;
		distancia++;
		lojack++;
		int a = rand() % 100;
		string N = ubicacion->getNOM();
		if (a == 75)
		{
			cout << "CHOQUE!" << "mi ubicacion es: " << lojack << "km desde la ruta saliendo de" << N << endl;
			PROBLEMA++;
			break;
		}

	}

	if (PROBLEMA == 0)
	{
		ubicacion = c2;
		encamino = false;
	}
	if (PROBLEMA == 1)
	{
		encamino = true;//porque quedo en el camino, no llego a destino
	}
}*/

void cVehiculo::UbicacionACT()
{
	if (getBOOL() == false)
	{
		cout << "el auto esta en" << getubicacion().getNOM()<<endl;
	}
	else
	{
		cout << "el auto esta en ruta" << endl;
		cout << "el auto esta a" << getlojack() << " km de " << getubicacion().getNOM()<< endl;
	}

}

float cVehiculo::Chequearnafta()
{
	cout << "Tenes" << getTACT() << " de nafta en el tanque" << endl;

	return getTACT();
}

cVehiculo::~cVehiculo()
{
}
