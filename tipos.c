#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mascotas.h"
#include "razas.h"
#include "utn.h"
#include "tipos.h"

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
int initLugarLibreTipo(struct sTipos *aTipo, int cantidad)
{
	int retorno;
	int i;
	if(aTipo != NULL && cantidad >0)
	{
		retorno = -1;
		for(i=0;i<cantidad;i++)
		{
			aTipo[i].isEmpty=1;
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
int altaForzadaTipos(struct sTipos *aArray, int cantidad)
{
	int i;
	int idTipo[] = {0,1,2};
	char tipo[][QTY_CARACTERES] = {"Gato","Perro","Raro"};

	int retorno;

    retorno = -1;
	for(i=0;i<cantidad;i++)
	{
		aArray[i].id = idTipo[i];
		strncpy(aArray[i].descripcion,tipo[i],QTY_CARACTERES);
		aArray[i].isEmpty = 0;
	}
	retorno = 0;
	return retorno;
}

/** \brief Imprimo Tipo de Mascotas
 *
 * \param aMascotas recibe la direccion de memoria donde se almaceno la estructura a imprimir
 * \param cantidad recibe la cantidad de elementos en la estructura a imprimir
 * \return Devuelve 0 si pudo mostrar los elementos por pantalla, -1 si hubo algun error
 *
 */
int imprimirTipo(struct sTipos *aArray, int indexTipo)
{
	int i;
	int retorno = -1;
	int lenTipo;

	if(aArray != NULL && indexTipo >=0)
	{
		retorno = 0;
		calculaLenTipo(aArray,&lenTipo);
		for(i=0;i<lenTipo;i++)
		{
            if(aArray[i].isEmpty== 0 && aArray[i].id == indexTipo)
            {
                printf("ID: %d  -   Tipo:    %s  \n",aArray[i].id, aArray[i].descripcion);
            }
        }
	}
	return retorno;
}

/** \brief Calcula la cantidad de elementos de la esructura
 *
 * \param aTipos recibe la direccion de memoria donde se almaceno la estructura a recorrer
 * \param cantidad recibe el puntero a donde se almacenara la cantidad de elementos
 * \return Devuelve 0 si pudo mostrar los elementos por pantalla, -1 si hubo algun error
 *
 */
int calculaLenTipo(struct sTipos *aArray, int *lenTipo)
 {
     int retorno;
     int len;
     int i;
     retorno = -1;
     len = 0;
     i = 0;
     if(aArray != NULL && lenTipo != NULL)
     {
         while(aArray[i].isEmpty == 0 && aArray[i].id >=0)
         {
            len++;
            i++;
         }
         if(len > 0)
         {
            *lenTipo = len;
            retorno = 0;
         }
     }
     return retorno;
 }

 /** \brief Imprimo la estructura Tipo de Mascotas
 *
 * \param aArray recibe la direccion de memoria donde se almaceno la estructura a imprimir
  * \return Devuelve 0 si pudo mostrar los elementos por pantalla, -1 si hubo algun error
 *
 */
int imprimirArrayTipo(struct sTipos *aArray)
{
	int i;
	int retorno = -1;
	int lenTipo;
	if(aArray != NULL)
	{
		retorno = 0;
		calculaLenTipo(aArray,&lenTipo);
		for(i=0;i<lenTipo+1;i++)
		{
		    if(aArray[i].isEmpty == 0)
            {
                imprimirTipo(aArray,aArray[i].id);
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
int getDescripcionTipo(struct sTipos *aArray, int indexTipo, char nombreTipo[])
{
    int retorno;
    int lenTipo;
    retorno = -1;

    if(aArray != NULL && indexTipo >=0)
    {
        calculaLenTipo(aArray,&lenTipo);
        for(int i = 0; i<lenTipo+1;i++)
        {
            if(aArray[i].isEmpty == 0 && aArray[i].id == indexTipo)
            {
                strcpy(nombreTipo,aArray[i].descripcion);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
