#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mascotas.h"
#include "razas.h"
#include "utn.h"
#include "tipos.h"
#include "pais.h"

#define QTY_MASCOTAS 10
#define QTY_CARACTERES 20
#define QTY_HARDCODEO 5
#define QTY_RAZAS 10
#define QTY_TIPOS 10
#define QTY_PAISES 5

/** \brief Inicializa la estructura, setea todos los elementos como Empty
 *
 * \param aMascota recibe la direccion de memoria donde se encuentra la estructura a inicializar
 * \param cantidad recibe la cantidad de elementos de la estructura
 * \return Devuelve 0 si pudo iniciarlizarse, -1 si hubo algun error
 *
 */
int initLugarLibrePais(struct sPaises *aPais, int cantidad)
{
	int retorno;
	int i;
	if(aPais != NULL && cantidad >0)
	{
		retorno = -1;
		for(i=0;i<cantidad;i++)
		{
			aPais[i].isEmpty=1;
		}
		retorno = 0;
	}

	return retorno;

}

/** \brief Cargo datos en una estructura de manera masiva
 *
 * \param aArray recibo la estructura a cargar
 * \param cantidad recibe la cantidad de datos a cargar
 * \return Devuelve 0 si la carga fue exitosa, -1 si hubo algun error.
 *
 */
int altaForzadaPaises(struct sPaises *aArray, int cantidad)
{
    /*
    int id;
    char nombrePais[20];
    int idContinte;
    char continente[20];
    int codigoTelefonico;
    int isEmpty;
    */
	int i;
	int idPais[] = {0,1,2,3,4};
	char nombrePais[][QTY_CARACTERES] = {"Tailandia","Alemania","Persia","Belgica","Argentina"};
	int idContinente[] = {0,1,0,1,2};
	char continente[][QTY_CARACTERES] = {"Asia", "Europa", "Asia","Europa","America del Sur"};
    int codigoTelefonico[] = {66,49,98,32,54};
	int retorno;

    retorno = -1;
	for(i=0;i<cantidad;i++)
	{
		aArray[i].id = idPais[i];
		strncpy(aArray[i].nombrePais,nombrePais[i],QTY_CARACTERES);
		aArray[i].idContinente = idContinente[i];
		strncpy(aArray[i].continente,continente[i],QTY_CARACTERES);
		aArray[i].codigoTelefonico = codigoTelefonico[i];
		aArray[i].isEmpty = 0;
	}
	retorno = 0;
	return retorno;
}

/** \brief Imprimo Paises
 *
 * \param aMascotas recibe la direccion de memoria donde se almaceno la estructura a imprimir
 * \param cantidad recibe la cantidad de elementos en la estructura a imprimir
 * \return Devuelve 0 si pudo mostrar los elementos por pantalla, -1 si hubo algun error
 *
 */
int imprimirPais(struct sPaises *aArray, int indexPais)
{
	int i;
	int retorno = -1;
	int lenPais;

	if(aArray != NULL && indexPais >=0)
	{
		retorno = 0;
        lenPais = QTY_PAISES;
		for(i=0;i<lenPais;i++)
		{
            if(aArray[i].isEmpty == 0 && aArray[i].id == indexPais)
            {
                printf("\nID: %02d - Pais: %-20s - ID Continente: %02d - Continente: %-20s - Cod. Telefonico: %d\n",aArray[i].id, aArray[i].nombrePais,aArray[i].idContinente,aArray[i].continente,aArray[i].codigoTelefonico);
            }
        }
	}
	return retorno;
}

 /** \brief Imprimo la estructura Tipo de Paises
 *
 * \param aArray recibe la direccion de memoria donde se almaceno la estructura a imprimir
  * \return Devuelve 0 si pudo mostrar los elementos por pantalla, -1 si hubo algun error
 *
 */
int imprimirArrayPais(struct sPaises *aArray)
{
	int i;
	int retorno = -1;
	int lenPais;
	if(aArray != NULL)
	{
		retorno = 0;
		lenPais = QTY_PAISES;
		for(i=0;i<lenPais+1;i++)
		{
		    if(aArray[i].isEmpty == 0)
            {
                imprimirPais(aArray,aArray[i].id);
            }

        }
	}
	return retorno;
}

 /** \brief Recupero la descripcion de Tipo de Raza
 *
 * \param aArray recibe la direccion de memoria donde se almaceno la estructura a recorrer
 * \param indexTipo recibe el indice a buscar
 * \param nombreTipo recibe el puntero a donde se almacenara el nombre del tipo de Raza
* \return Devuelve 0 si pudo mostrar los elementos por pantalla, -1 si hubo algun error
 *
 */
int getDescripcionPais(struct sPaises *aArray, int indexPais, char nombrePais[])
{
    int retorno;
    int lenPais;
    retorno = -1;

    if(aArray != NULL && indexPais >=0)
    {
        lenPais = QTY_PAISES;
        for(int i = 0; i<lenPais+1;i++)
        {
            if(aArray[i].isEmpty == 0 && aArray[i].id == indexPais)
            {
                strcpy(nombrePais,aArray[i].nombrePais);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

 /** \brief Recupero el codigo Telefonico del Pais
 *
 * \param aArray recibe la direccion de memoria donde se almaceno la estructura a recorrer
 * \param indexTipo recibe el indice a buscar
 * \param nombreTipo recibe el puntero a donde se almacenara el nombre del tipo de Raza
* \return Devuelve 0 si pudo mostrar los elementos por pantalla, -1 si hubo algun error
 *
 */
int getCodigoTelefonico(struct sPaises *aArray, int indexPais, int *codigoTelefonico)
{
    int retorno;
    int lenPais;
    retorno = -1;

    if(aArray != NULL && indexPais >=0)
    {
        lenPais = QTY_PAISES;
        for(int i = 0; i<lenPais+1;i++)
        {
            if(aArray[i].isEmpty == 0 && aArray[i].id == indexPais)
            {
                *codigoTelefonico = aArray[i].codigoTelefonico;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
