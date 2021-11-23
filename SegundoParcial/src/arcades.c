/*
 * arcades.c
 *
 *  Created on: 21 nov. 2021
 *      Author: caroo
 */

#include <stdio.h>
#include "arcades.h"


int inicializarArcades(eArcades* listaArcades,int tamArcades)
{
	int retorno = -1;
	int i;

	if(listaArcades != NULL && tamArcades > 0)
	{
		retorno = 0;
		for(i=0;i<tamArcades;i++)
		{
			listaArcades[i].isEmpty = 1;
		}
	}
	return retorno;
}

int buscarLugarVacioArcades(eArcades* listaArcades,int tamArcades)
{
	int retorno = -1;
	int i;

	if(listaArcades != NULL && tamArcades > 0)
	{
		for(i=0;i<tamArcades;i++)
		{
			if(listaArcades[i].isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int generadorDeIDArcade(void)
{
	static int contadorId=0;

	return contadorId++;
}

int altaArcade(eArcades* listaArcades,int tamArcades, int indiceVacio, int idDeSalonACargar)
{
	int retorno=-1;
	eArcades arc;

	if(listaArcades!=NULL && tamArcades>0 && indiceVacio< tamArcades && indiceVacio>=0 && idDeSalonACargar>=0)
	{
		if(utn_getChar(arc.nacionalidad,"\nIngrese la nacionalidad: ","\nError",NACIONALIDAD_LEN,3)==0 &&
		   utn_getNumeroInt(&arc.tipoDeSonido,"\nIngrese el tipo de sonido (MONO:1 STEREO:2)", "\nError",1,2,3)==0 &&
		   utn_getNumeroInt(&arc.cantidadDeJugadores,"\nIngrese la cantidad de jugadores(1 a 4)", "\nError",1,4,3)==0 &&
		   utn_getNumeroInt(&arc.capacidadMaximaFichas,"\nIngrese la capacidad máxima de fichas", "\nError",1,100000,3)==0 &&
		   utn_getDescripcion(arc.nombreJuego,"\nIngrese el nombre del juego: ","\nError",JUEGO_LEN,3)==0)
		{
			arc.idSalon=idDeSalonACargar;
			arc.idArcade=generadorDeIDArcade();
			arc.isEmpty=0;
			listaArcades[indiceVacio]=arc;
			retorno=0;
		}
	}
	return retorno;
}

int forzarArcade(eArcades* listaArcades,int tamArcades, int indiceF, char nacionalidadF[], int tipoDeSonidoF,int cantidadDeJugadoresF,int capacidadMaximaFichasF,int idSalonF,char nombreJuegoF[],int idArcadeF,int isEmptyF)
{
	int retorno=-1;
	eArcades arc;

	if(listaArcades!=NULL && tamArcades>0 && indiceF< tamArcades && indiceF>=0 && nacionalidadF!=NULL && (tipoDeSonidoF==1||tipoDeSonidoF==2) && idSalonF>=0 && nombreJuegoF!=NULL && idArcadeF>=0 && (isEmptyF==0||isEmptyF==1))
	{
		strncpy(listaArcades[indiceF].nacionalidad,nacionalidadF,NACIONALIDAD_LEN);
		arc.tipoDeSonido=tipoDeSonidoF;
		arc.cantidadDeJugadores=cantidadDeJugadoresF;
		arc.capacidadMaximaFichas=capacidadMaximaFichasF;
		arc.idSalon=idSalonF;
		strncpy(arc.nombreJuego,nombreJuegoF,JUEGO_LEN);
		arc.idArcade=idArcadeF;
		arc.isEmpty=isEmptyF;
		listaArcades[indiceF]=arc;
		retorno=0;
	}
	return retorno;
}

int buscarIdArcade(eArcades* listaArcades,int tamArcades, int idBuscado)
{
	int retorno = -1;
	int i;

	if(listaArcades != NULL && tamArcades > 0 && idBuscado >= 0)
	{
		retorno = -2;
		for(i=0;i<tamArcades;i++)
		{
			if(listaArcades[i].idArcade == idBuscado)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


int modificarArcade(eArcades* listaArcades,int tamArcades, int indiceAModificar, int opcionElegida)
{
	int retorno=-1;
	eArcades arc;

	if(listaArcades!= NULL && tamArcades >=0 && indiceAModificar >=0 && (opcionElegida==11 ||opcionElegida==12) && listaArcades[indiceAModificar].isEmpty==0)
	{
		switch(opcionElegida)
		{
			case 11:
				if(utn_getNumeroInt(&arc.cantidadDeJugadores,"\nIngrese la cantidad de jugadores", "\nCantidad inválida",1,4,3)==0)
				{
					listaArcades[indiceAModificar].cantidadDeJugadores=arc.cantidadDeJugadores;
					retorno=0;
				}
				break;
			case 12:
				if(utn_getDescripcion(arc.nombreJuego,"\nIngrese el nuevo nombre del juego","\nNombre inválido",JUEGO_LEN,3)==0)
				{
					strncpy(listaArcades[indiceAModificar].nombreJuego,arc.nombreJuego,sizeof(listaArcades[indiceAModificar].nombreJuego));
					retorno=0;
				}
				break;
		}
	}
	return retorno;
}


int bajaArcade(eArcades* listaArcades,int tamArcades, int indiceBuscadoArcade)
{
	int retorno = -1;

	if(listaArcades != NULL && tamArcades > 0 && indiceBuscadoArcade >= 0 && listaArcades[indiceBuscadoArcade].isEmpty == 0)
	{
		listaArcades[indiceBuscadoArcade].isEmpty = 1;
		retorno = 0;
	}
	return retorno;
}

int bajaArcadePorSalon(eArcades* listaArcades,int tamArcades, int idSalonAEliminar)
{
	int retorno = -1;
	int i;

	if(listaArcades != NULL && tamArcades > 0 && idSalonAEliminar >= 0)
	{
		for(i=0;i<tamArcades;i++)
		{
			if(listaArcades[i].idSalon == idSalonAEliminar && listaArcades[i].isEmpty==0)
			{
				listaArcades[i].isEmpty = 1;
				retorno = 0;
			}
		}
	}
	return retorno;
}


int imprimirArcades(eArcades* listaArcades,int tamArcades)
{
	int retorno = -1;
	int i;

	if(listaArcades != NULL && tamArcades >=0)
	{
		retorno = 0;
		for(i=0;i<tamArcades;i++)
		{
			if(listaArcades[i].isEmpty==0)
			{
				printf("\nID del arcade: %d - Tipo de sonido: %d - Cantidad de jugadores: %d - Capacidad máxima de fichas: %d - Nombre del juego: %s - Id del Salon: %d\n", listaArcades[i].idArcade,listaArcades[i].tipoDeSonido,listaArcades[i].cantidadDeJugadores,listaArcades[i].capacidadMaximaFichas,listaArcades[i].nombreJuego,listaArcades[i].idSalon);
			}
		}
	}
	return retorno;
}

int imprimirUnArcade(eArcades* listaArcades,int indiceArcadeAImprimir)
{
	int retorno = -1;

	if(listaArcades != NULL && indiceArcadeAImprimir>=0 && listaArcades[indiceArcadeAImprimir].isEmpty==0)
	{
		retorno = 0;
		printf("\nID del arcade: %d - Tipo de sonido: %d - Cantidad de jugadores: %d - Capacidad máxima de fichas: %d - Nombre del juego: %s - Id del Salon: %d\n", listaArcades[indiceArcadeAImprimir].idArcade,listaArcades[indiceArcadeAImprimir].tipoDeSonido,listaArcades[indiceArcadeAImprimir].cantidadDeJugadores,listaArcades[indiceArcadeAImprimir].capacidadMaximaFichas,listaArcades[indiceArcadeAImprimir].nombreJuego,listaArcades[indiceArcadeAImprimir].idSalon);
	}
	return retorno;
}
