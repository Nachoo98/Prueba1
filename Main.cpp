#include <string>
#include <iostream>
#include <math.h>
#include "cCiudad.h"
#include "cVehiculo.h"
#include "cPersona.h"
#include "cPeaje.h"
#include "cLista.h"
//#include "globals.h"

using namespace std;
enum tito { conducir = 1, Imprimir, Vender };
int main()
{

	//creo objetos

	cCiudad* ciudad[5];
	//Poblacionar_Ciudades(); //Lo de globals preguntar bien,tira error
	ciudad[0] = new cCiudad("CABA", -58.472230, -34.598854, 3000000);
	ciudad[1] = new cCiudad("Mar del Plata", -57.548142, -38.004848, 1000000);
	ciudad[2] = new cCiudad("La Plata", 57.571631, 34.551722, 2000000);
	ciudad[3] = new cCiudad("Tandil", 59.0805, 37.1908, 350000);
	ciudad[4] = new cCiudad("Bariloche", 71.180, 41.900, 400000);

	cVehiculo* vehiculo[3];

	vehiculo[0] = new cVehiculo("Ford", "KA", 2018, "rojo", "AFH124", 1600, 45, 0, ciudad[0]);
	vehiculo[1] = new cVehiculo("Renault", "Logan", 2014, "negro", "QIU265", 1750, 50, 10000, ciudad[2]);
	vehiculo[2] = new cVehiculo("Peugeot", "308", 2015, "gris", "GJT145", 2000, 55, 15000, ciudad[4]);

	cPersona* persona[4];

	persona[0] = new cPersona("Carla", "Gomez", "51236985", vehiculo[1]);
	persona[1] = new cPersona("Ramiro", "Bouzat", "42365124", NULL);
	persona[2] = new cPersona("Fabian", "Estevez", "27102458", vehiculo[2]);
	persona[3] = new cPersona("Maria", "Garcia", "25698478", vehiculo[0]);

	cPeaje* peaje = new cPeaje();



	///////////////////////////////////interactuo//////////////////////////////////////////////////////////

	cLista<cPersona> listapersonas(4);
	cLista<cVehiculo> listavehiculos(3);

	listapersonas.AgregarItem(persona[0]);
	listapersonas.AgregarItem(persona[1]);
	listapersonas.AgregarItem(persona[2]);
	listapersonas.AgregarItem(persona[3]);

	listavehiculos.AgregarItem(vehiculo[0]);
	listavehiculos.AgregarItem(vehiculo[1]);
	listavehiculos.AgregarItem(vehiculo[2]);


	listapersonas.BuscarItem("42365124");
	listavehiculos.BuscarItem("GJT145");


	int op = 0;

	while (op != 4)
	{
		cout << "Conducir" << endl;
		cout << "Imprimir" << endl;
		cout << "Vender" << endl;
		cout << "SALIR" << endl;
		cout << "Digite una opcion" << endl;
		//cin >> op;
		op = rand() % 5;


		switch (op)
		{
		case conducir:
			system("cls");
			int v, l;

			cout << "Seleccione un vehiculo (1->vehiculo1, 2->vehiculo2, 3->vehiculo3)" << endl;
			//cin >> v;
			v = 1 + rand() % 3;
			cout << "Seleccione la ciudad de llegada(1->CABA, 2-> Mar del Plata, 3->La Plata, 4->Tandil, 5->Bariloche)" << endl;
			//cin >> l;
			l = 1 + rand() % 5;

			peaje->Cabina(persona[v - 1]);//esto hay que cambiar porque cabina reciba a una persona en vez de vehiculo, no me acuerdo como estaba organizado
			//vehiculo[v - 1]->conducir(ciudad[l - 1]); cambiar!

			system("pause ");
			system("cls");
			break;

		case Imprimir:
			system("cls");
			int a;

			cout << "¿Que desea imprimir? (1-> vehiculo, 2-> persona, 3->ciudad)" << endl;
			//cin >> a;
			a = 1 + rand() % 3;

			if (a == 1)
			{
				int v;
				cout << "Seleccione un vehiculo (1->vehiculo1, 2->vehiculo2, 3->vehiculo3)" << endl;
				//cin >> v;
				v = 1 + rand() % 3;
				vehiculo[v - 1]->ImprimirEnPantalla();
			}

			if (a == 2)
			{
				int p;
				cout << "Seleccione una persona (1->persona1, 2->persona2, 3->persona3, 4->persona4)" << endl;
				//cin >> p;
				p = 1 + rand() % 4;
				persona[p - 1]->Imprimir_Pantalla();

			}

			if (a == 3)
			{
				int c;
				cout << "Seleccione una ciudad (1->CABA, 2-> Mar del Plata, 3->La Plata, 4->Tandil, 5->Bariloche)" << endl;
				//cin >> c;
				c = 1 + rand() % 5;
				ciudad[c - 1]->Imprimir_Pantalla();

			}

			system("pause ");
			system("cls");
			break;

		case Vender:
			system("cls");
			int comprador, vendedor;
			for (int i = 0; i < 4; i++)
			{
				cout << "Persona " << i << ":" << endl;
				persona[i]->Imprimir_Pantalla();
			}
			cout << "Seleccione la persona que vendera su vehiculo(1->persona1, 2->persona2, 3->persona3, 4->persona4)" << endl;
			//cin >> vendedor;
			vendedor = 1 + rand() % 4;

			cout << "Seleccione la persona que comprara un vehiculo(1->persona1, 2->persona2, 3->persona3, 4->persona4)" << endl;
			//cin >> comprador;
			comprador = 1 + rand() % 4;

			persona[vendedor - 1]->VenderVehiculo(persona[comprador - 1]);

			system("pause ");
			system("cls");
			break;

		default:

			if (op < 1 || op>5)
			{
				system("cls");
				cout << "Este numero no es valido..." << endl;
				system("pause ");
				system("cls");
			}
			break;
		}
	}


	system("pause");

	///////////////////////////////////////////////////////////////////////////////////////////////////////////elimino objetos

	delete vehiculo[0]; vehiculo[0] = nullptr;
	delete vehiculo[1]; vehiculo[1] = nullptr;
	delete vehiculo[2]; vehiculo[2] = nullptr;

	delete persona[0]; persona[0] = nullptr;
	delete persona[1]; persona[1] = nullptr;
	delete persona[2]; persona[2] = nullptr;
	delete persona[3]; persona[3] = nullptr;

	delete ciudad[0]; ciudad[0] = nullptr;
	delete ciudad[1]; ciudad[1] = nullptr;
	delete ciudad[2]; ciudad[2] = nullptr;
	delete ciudad[3]; ciudad[3] = nullptr;
	delete ciudad[4]; ciudad[4] = nullptr;

	delete peaje; peaje = nullptr;

	return 0;
}