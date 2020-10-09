#include "cPersona.h"
#include "cPeaje.h"
#include "Math.h"
cPersona::cPersona(string nom, string ape, string DNI, cVehiculo* v1)
{
	nombre = nom;
	apellido = ape;
	dni = DNI;
	billetera = 1000 + rand() % 15001;
	this->vehiculo[0] = v1;
	this->vehiculo[1] = NULL;
	this->vehiculo[2] = NULL;
}

void cPersona::Comprarvehiculo(cPersona* ven)//al cliente(el que llama la funcion) se le pasa el vendedor
{
	int a;
	for (int i = 0; i < 3; i++)
	{
		if (vehiculo[i] != NULL)
		{

			ven->vehiculo[i]->ImprimirEnPantalla();
			cout << "Auto nro: " << i << endl;

		}
	}
	cout << "elija su auto: " << endl;
	//cin >> a;
	a = rand() % 3;
	if (a != 0 && a != 1 && a != 2)
	{
		cout << "no existe, mira bien!!" << endl;
	}
	else {
		for (int i = 0; i < 3; i++)
		{
			if (vehiculo[i] == NULL)
			{
				setV(i, ven->vehiculo[a]);
				ven->vendido(a);

			}
			if (vehiculo[0] != NULL && vehiculo[1] != NULL && vehiculo[2] != NULL)
			{
				cout << " No tenes lugar para otro auto" << endl;
			}
		}
	}

}

void cPersona::VenderVehiculo(cPersona* cliente)
{
	int contador = 0;
	int a;
	for (int i = 0; i < 3; i++)
	{
		if (vehiculo[i] != NULL)
		{

			vehiculo[i]->ImprimirEnPantalla();
			cout << "Auto nro: " << i << endl;
			contador++;
		}
	}
	cout << "Esto es lo que tengo" << endl;
	a = rand() % contador - 1;
	if (a != 0 && a != 1 && a != 2)
	{
		cout << "Bueno, vuelva cuando quiera!" << endl;
		return;
	}
	else {
		for (int i = 0; i < 3; i++)
		{
			if (cliente->vehiculo[i] == NULL)
			{
				setV(i, vehiculo[a]);
				vendido(a);

			}
			if (cliente->vehiculo[0] != NULL && cliente->vehiculo[1] != NULL && cliente->vehiculo[2] != NULL)
			{
				cout << " No tenes lugar para otro auto" << endl;
			}
		}
	}

}

void cPersona::vendido(int pos)
{
	vehiculo[pos] = NULL;
}

void cPersona::setV(int i, cVehiculo* v)
{
	vehiculo[i] = v; 
}

void cPersona::Imprimir_Pantalla()
{
	string texto = to_string();
	cout << texto << endl;
}

string cPersona::to_string()
{

	string texto = "Nombre: " + nombre + ", Apellido: " + apellido + ", DNI: " + dni;
	return texto;
}



void cPersona::cargarnafta(int i)
{
	int a;
	float preciolitro = 60;
	float b = vehiculo[i]->getTLLENO();
	float T = vehiculo[i]->getTACT();
	float litros1 = b - T;
	T = T / b;
	float ACTUAL= vehiculo[i]->getTACT();
	cout << "Tiene" << T << "% del tanque lleno" << endl;

	cout << "Le lleno el tanque maestro?" << endl;
	cout << "ingrese 0 para que le llene el tanque:" << endl;
	//cin >> a;
	a = rand() % 2;
	if (a == 0)
	{
		
		vehiculo[i]->settanqueact(b);
		cout << "su tanque se lleno completamente" << endl;
		vehiculo[i]->setDIST(0);
		pagaralgo(preciolitro * litros1);
	}
	else if (a != 0)
	{
		float e;
		cout << "cuanto le lleno? (en %) (ej: 90)" << endl;
		//cin >> e;
		e = 1 + rand() % 100;
		float d = (e / 100);//porcentaje
		d = d * b;//nuevo tanque actual
		float litros = d-ACTUAL;//cantidad de litros que se le carga
		vehiculo[i]->settanqueact(d);
		vehiculo[i]->setDIST(0);
		pagaralgo(preciolitro * litros);
	}
}

void cPersona::conducir(cCiudad* c2,int i)
{
	vehiculo[i]->setlojack(0);
	float N = vehiculo[i]->getTACT();//guardo el tanque actual en N
	float d = vehiculo[i]->GPSDIST(c2);

	
	float a=rand() %((int) ceil(d / 50) + 1);

    cLista<cPeaje>peajes(a); //creo una cantidad de peajes de entre 0 y d/50 TIRA ERROR DSP VER

	for (int i = 0; i < a; i++)
	{
		cPeaje* peaje[i]= new cPeaje;
		peajes.AgregarItem(peaje[i]);
	}
	

	int PROBLEMA = 0;
	if (N < 25)
	{
		cargarnafta(0);//default dsp vemos el resto
	}

	for (int i = 0; i < d; i++) //i es 1km
	{


		vehiculo[i]->setencamino(true);
		int a = vehiculo[i]->getcontTAL();
		vehiculo[i]->consumirtanque();
		while(vehiculo[i]->getCONTADOR()!=0)
		{
			pagaralgo((vehiculo[i]->getTLLENO() - 1) * 60);//paga un tanque lleno
			int a = vehiculo[i]->getCONTADOR();//cuenta las veces que el amigo lo cubrio durante el viaje
			vehiculo[i]->setCONTADOR(a - 1);//le devuelve la plata que el amigo le presto durante el viaje			
		}
		vehiculo[i]->mantenimiento();
		if (vehiculo[i]->getcontTAL() > a) { pagaralgo(3000); }//si tuvo que ir al taller en el camino paga
		
		float k=vehiculo[i]->getKM();
		vehiculo[i]->setKM(k + 1);
		float D=vehiculo[i]->getDIST();
		vehiculo[i]->setDIST(D + 1);
		float l=vehiculo[i]->getlojack();
		vehiculo[i]->setlojack(l + 1);
		int C = rand() % 100;
		string N = vehiculo[i]->getubicacion().getNOM();
		if (C > 95)
		{
			cout << "CHOQUE!" << "mi ubicacion es: " << vehiculo[i]->getlojack() << "km desde la ruta saliendo de" << N << endl;
			PROBLEMA++;
			break;
		}

	}

	if (PROBLEMA == 0)
	{
		vehiculo[i]->setUBICACION(c2);
		vehiculo[i]->setencamino(false);
	}
	if (PROBLEMA == 1)
	{

		vehiculo[i]->setencamino(true);//porque quedo en el camino, no llego a destino
	}
}



void cPersona::Trabajar(float minimo)//o se calcula en el main o hacemos un metodo que calcule costos que cubran nafta+peajes.
{
	int a = getbilletera();
	int contT = 0;

	while (a < minimo)
	{
		setbilletera(a + 100);
		contT++;
	}
	cout << "Trabajo" << contT << "dias" << endl;
	
}

cPersona::~cPersona()
{
}