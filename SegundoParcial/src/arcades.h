/*
 * arcades.h
 *
 *  Created on: 21 nov. 2021
 *      Author: caroo
 */

#ifndef ARCADES_H_
#define ARCADES_H_


#define NACIONALIDAD_LEN 100
#define TIPO_MONO	1
#define TIPO_ESTEREO 2
#define JUEGO_LEN 63

typedef struct {
	char nacionalidad[NACIONALIDAD_LEN];
	int tipoDeSonido;
	int cantidadDeJugadores;
	int capacidadMaximaFichas;
	int idSalon;
	char nombreJuego[JUEGO_LEN];
	int idArcade;
	int isEmpty;
}eArcades;

int inicializarArcades(eArcades* listaArcades,int tamArcades);
int buscarLugarVacioArcades(eArcades* listaArcades,int tamArcades);
int generadorDeIDArcade(void);
int altaArcade(eArcades* listaArcades,int tamArcades, int indiceVacio, int idDeSalonACargar);
int forzarArcade(eArcades* listaArcades,int tamArcades, int indiceF, char nacionalidadF[], int tipoDeSonidoF,int cantidadDeJugadoresF,int capacidadMaximaFichasF,int idSalonF,char nombreJuegoF[],int idArcadeF,int isEmptyF);

int buscarIdArcade(eArcades* listaArcades,int tamArcades, int idBuscado);
int modificarArcade(eArcades* listaArcades,int tamArcades, int indiceAModificar, int opcionElegida);

int imprimirArcades(eArcades* listaArcades,int tamArcades);
int imprimirUnArcade(eArcades* listaArcades,int indiceArcadeAImprimir);
int bajaArcade(eArcades* listaArcades,int tamArcades, int indiceBuscadoArcade);
int bajaArcadePorSalon(eArcades* listaArcades,int tamArcades, int idSalonAEliminar);


#endif /* ARCADES_H_ */
