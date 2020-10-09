#define _CRT_SECURE_NO_WARNINGS
#include "cPeaje.h"
int cPeaje::contPARO = 0;

cPeaje::cPeaje()
{
	nombre = "Autopistas Argentinas, guarda con el pozo";
}

cPeaje::cPeaje(string NOM, int BOX)//, bool TELE)
{
	nombre = NOM;
	caja = BOX;
	//telepeaje = rand() % 2; No hace nada por ahora?
}

void cPeaje::Cabina(cPersona*P)
{
	
	int paro = rand() % 10;

	if (paro>7)
	{
		cout << "Bienvenido al Peaje de Autopistas Argentinas, lamentablemente estamos de paro, espere media hora y pase \n";
		contPARO++;
	}
	else
	{
		cout << "Gracias por utilizar nuestros servicios,¡Hasta la proxima! ";
	}
	cobrar(P);
}

void cPeaje::cobrar(cPersona* p)
{
	
	float normal = 20;
	int P = p->getVehiculo(0).getPeso();
	time_t ttime = time(0);
	tm* local_time = localtime(&ttime);
	int Hora = local_time->tm_hour;
	
	if (1000 < P < 1500)
	{
		float precio = normal;
		
		if (11 < Hora < 15)
		{
			precio = 2 * precio;//hora pico
		}
		if (17 < Hora < 21)
		{
			precio = 2 * precio;//hora pico
		}
		
		caja = caja + precio;
		p->pagaralgo(precio);
	}
	if (1501 < P < 1800)
	{
		float precio = normal * float(1.2);
		if (11 < Hora < 15)
		{
			precio = 2 * precio;//hora pico
		}
		if (17 < Hora < 21)
		{
			precio = 2 * precio;//hora pico
		}
		caja = caja + precio;
		p->pagaralgo(precio);

	}
	if (P > 1800)
	{
		float precio = normal * float(1.5);
		if (11 < Hora < 15)
		{
			precio = 2 * precio;//hora pico
		}
		if (17 < Hora < 21)
		{
			precio = 2 * precio;//hora pico
		}

		caja = caja + precio;
		p->pagaralgo(precio);

	}

}

cPeaje::~cPeaje()
{
}
