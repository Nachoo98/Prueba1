#include "globals.h"

void Poblacionar_Ciudades()
{
	Ciudades_global.AgregarItem(new cCiudad("CABA", -58.472230, -34.598854, 3000000));
	Ciudades_global.AgregarItem(new cCiudad("Mar del Plata", -57.548142, -38.004848, 1000000));
	Ciudades_global.AgregarItem(new cCiudad("La Plata", 57.571631, 34.551722, 2000000));
	Ciudades_global.AgregarItem(new cCiudad("Tandil", 59.0805, 37.1908, 350000));
	Ciudades_global.AgregarItem(new cCiudad("Bariloche", 71.180, 41.900, 400000));
	
}
