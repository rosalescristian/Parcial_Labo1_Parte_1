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
int initLugarLibreRaza(struct sRazas *aRaza, int cantidad)
{
	int retorno;
	int i;
	if(aRaza != NULL && cantidad >0)
	{
		retorno = -1;
		for(i=0;i<cantidad;i++)
		{
			aRaza[i].isEmpty=1;
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
int altaForzadaRaza(struct sRazas *aArray, int cantidad)
{
	int i;
	int idRaza[] ={0,1,2,3,4,5};
	char nombre[][QTY_CARACTERES] = {"Siames","Doberman","Persa","Pastor Belga","Dogo Argentino","Pastor Aleman"};
	int idTamanio[] = {0,2,1,2,2,2};
	char tamanio[][QTY_CARACTERES] = {"Chico","Grande","Mediano","Grande","Grande","Grande"};
	int idPais[] = {0,1,2,3,4,1};
	//char pais[][QTY_CARACTERES] = {"Tailandia","Alemania","Persia","Belgica","Argentina","Alemania"};

	int retorno;

    retorno = -1;
	for(i=0;i<cantidad;i++)
	{
		aArray[i].id = idRaza[i];
		strncpy(aArray[i].descripcion,nombre[i],QTY_CARACTERES);
		aArray[i].idTamanio= idTamanio[i];
		strncpy(aArray[i].tamanio,tamanio[i],QTY_CARACTERES);
		aArray[i].idPaisOrigen = idPais[i];
//		strncpy(aArray[i].paisOrigen,pais[i],QTY_CARACTERES);
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
int imprimirRaza(struct sRazas *aArray, int indexTipo, struct sPaises *bArray)
{
	int i;
	int retorno = -1;
	int lenRaza;
    char paisOrigen[QTY_CARACTERES];
	if(aArray != NULL && indexTipo >=0)
	{
		retorno = 0;
        lenRaza = QTY_RAZAS;
		for(i=0;i<lenRaza;i++)
		{
            if(aArray[i].isEmpty == 0 && aArray[i].id == indexTipo)
            {
                getDescripcionPais(bArray,aArray[i].idPaisOrigen,paisOrigen);
                printf("\nID: %02d - Raza: %-20s - ID Tamanio: %02d - Tamanio: %-20s - Pais Origen: %-20s\n",aArray[i].id, aArray[i].descripcion,aArray[i].idTamanio,aArray[i].tamanio,paisOrigen);
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
/*int calculaLenRaza(struct sRazas *aArray, int *lenRaza)
 {
     int retorno;
     int len;
     int i;
     retorno = -1;
     len = 0;
     i = 0;
     if(aArray != NULL && lenRaza != NULL)
     {
         while(aArray[i].isEmpty == 0 && aArray[i].id >=0)
         {
            len++;
            i++;
         }
         if(len > 0)
         {
            *lenRaza = len;
            retorno = 0;
         }
     }
     return retorno;
 }
*/
 /** \brief Imprimo la estructura Tipo de Mascotas
 *
 * \param aArray recibe la direccion de memoria donde se almaceno la estructura a imprimir
  * \return Devuelve 0 si pudo mostrar los elementos por pantalla, -1 si hubo algun error
 *
 */
int imprimirArrayRaza(struct sRazas *aArray, struct sPaises *bArray)
{
	int i;
	int retorno = -1;
	int lenRaza;
	if(aArray != NULL && bArray != NULL)
	{
		retorno = 0;
		lenRaza = QTY_RAZAS;
		for(i=0;i<lenRaza+1;i++)
		{
            if(aArray[i].isEmpty == 0)
            {
                imprimirRaza(aArray,aArray[i].id, bArray);
            }
        }
	}
	return retorno;
}

 /** \brief Recupero la descripcion de Raza
 *
 * \param aArray recibe la direccion de memoria donde se almaceno la estructura a recorrer
 * \param indexTipo recibe el indice a buscar
 * \param nombreTipo recibe el puntero a donde se almacenara el nombre del tipo de Raza
* \return Devuelve 0 si pudo mostrar los elementos por pantalla, -1 si hubo algun error
 *
 */
int getDescripcionRaza(struct sRazas *aArray, int indexRaza, char nombreRaza[])
{
    int retorno;
    int lenRaza;
    retorno = -1;

    if(aArray != NULL && indexRaza >=0)
    {
        lenRaza = QTY_RAZAS;
        for(int i = 0; i<lenRaza+1;i++)
        {
            if(aArray[i].isEmpty == 0 && aArray[i].id == indexRaza)
            {
                strcpy(nombreRaza,aArray[i].descripcion);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

 /** \brief Recupero la descripcion de tamaño de la Raza
 *
 * \param aArray recibe la direccion de memoria donde se almaceno la estructura a recorrer
 * \param indexTipo recibe el indice a buscar
 * \param nombreTipo recibe el puntero a donde se almacenara el nombre del tipo de Raza
* \return Devuelve 0 si pudo mostrar los elementos por pantalla, -1 si hubo algun error
 *
 */
int getTamanioRaza(struct sRazas *aArray, int indexRaza, char tamanioRaza[])
{
    int retorno;
    int lenRaza;
    retorno = -1;

    if(aArray != NULL && indexRaza >=0)
    {
        lenRaza = QTY_RAZAS;
        for(int i = 0; i<lenRaza+1;i++)
        {
            if(aArray[i].isEmpty == 0 && aArray[i].id == indexRaza)
            {
                strcpy(tamanioRaza,aArray[i].tamanio);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

 /** \brief Recupero la descripcion de tamaño de la Raza
 *
 * \param aArray recibe la direccion de memoria donde se almaceno la estructura a recorrer
 * \param indexTipo recibe el indice a buscar
 * \param nombreTipo recibe el puntero a donde se almacenara el nombre del tipo de Raza
* \return Devuelve 0 si pudo mostrar los elementos por pantalla, -1 si hubo algun error
 *
 */
int getPaisRaza(struct sRazas *aArray, int indexRaza, char paisRaza[], struct sPaises *bArray)
{
    int retorno;
    int lenRaza;
    char nombrePais[QTY_CARACTERES];
    retorno = -1;

    if(aArray != NULL && indexRaza >=0)
    {
        lenRaza = QTY_RAZAS;
        for(int i = 0; i<lenRaza+1;i++)
        {
            if(aArray[i].isEmpty == 0 && aArray[i].id == indexRaza)
            {
                getDescripcionPais(bArray, aArray[i].idPaisOrigen,nombrePais);
                strcpy(paisRaza,nombrePais);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

 /** \brief Imprimo la estructura Tipo de Mascotas por Raza
 *
 * \param aArray recibe la direccion de memoria donde se almaceno la estructura a imprimir
  * \return Devuelve 0 si pudo mostrar los elementos por pantalla, -1 si hubo algun error
 *
 */
int imprimirArrayMascotasPorRaza(struct sMascotas *aArray, struct sTipos *bArray, struct sRazas *cArray)
{
	int i;
	int retorno = -1;
	int lenRaza;
	int lenMascota;
	if(aArray != NULL && bArray != NULL && cArray != NULL)
	{
		retorno = 0;
		lenRaza = QTY_RAZAS;
        lenMascota = QTY_MASCOTAS;
        printf("\t***** LISTADO DE MASCOTAS *****\n\n");
		for(i=0;i<lenRaza;i++)
		{
            if(cArray[i].isEmpty == 0)
            {
                for(int j = 0;j<lenMascota;j++)
                {
                    if(aArray[j].isEmpty == 0 && aArray[j].idRaza == i)
                    {
                        imprimirMascota(aArray,aArray[j].id,bArray,cArray);
                    }
                }
            }

        }
	}
	return retorno;
}

/** \brief Da de alta un nuevo elemento en el array de estructura
 *
 * \param aArray recibe el array de estructura donde se ingresara el valor nuevo
 * \param cantidad recibe el valor de elementos del array
 * \param mascota recibe el nuevo elemento a ingresar en el array
 * \return Devuelve 0 si pudo ingresar el nuevo elemento, -1 si hubo algun error
 *
 */
int altaRazaPorId(struct sRazas *aArray, int cantidad, struct sRazas raza)
{
	int retorno;
	int bLugarLibre;

	if(aArray != NULL && cantidad > 0)
	{
		retorno = -1;
		bLugarLibre = buscarLugarLibreRaza(aArray, QTY_RAZAS);
		if(bLugarLibre != -1)
			{
				aArray[bLugarLibre]=raza;
				retorno = 0;
			}
	}
	return retorno;
}

/** \brief Recorre el array de estructura y recupera el lugar libre
 *
 * \param aArray recibe el array de estructura a recorrer
 * \param cantidad recibe la cantidad de elementos maximos en el array
 * \return Devuelve la posicion libre en el array o -1 si hubo algun error
 *
 */
int buscarLugarLibreRaza(struct sRazas *aArray, int cantidad)
{
	int index;
	int i;
	int retorno;

	if(aArray != NULL && cantidad > 0)
	{
		index = -1;
		retorno=-1;
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].isEmpty == 1)
			{
				index=i;
				break;
			}
		}
		retorno = index;
	}
	return retorno;
}

/** \brief Recupero los valores de cadena de caracteres para almacenar en la estructura
 *
 * \param aMascota recibe la direccion de memoria donde se encuentra almacenada la estructura
 * \param bEmpledao recibe un item dentro de la estructura
 * \param limite recibe el valor maximo de elementos de la estructura
 * \param reintentos es la cantidad de intentos que tendra el usuario en caso de cometer algun errot
 * \param id es la posicion de la estructura donde ingresaremos los valores que recuperemos
 * \return Devuelve 0 si pudo tomar un valor o -1 si hubo algun error
 *
 */

int getRazaStr(	struct sRazas *aRaza,
                struct sRazas bRaza,
                struct sPaises *aPais,
					int limite,
					int reintentos,
					int id)
{
	int retorno;
	int bIdTamanio;
	int bIdPaisOrigen;
	int cRaza;
	char bDescripcion[QTY_CARACTERES];
	char bPaisOrigen[QTY_CARACTERES];

	if(		aRaza != NULL &&
            limite > 0 &&
			reintentos > 0 &&
			id != -1)
	{
		do
		{
		    retorno = -1;
		    cRaza = -1;

		    if(getNameMascota(bDescripcion, "\nIngrese el nombre de la raza: ", "\nHa ingresado un nombre invalido, reintente.", 2, sizeof(bDescripcion),3)==0)
            {
                strncpy(bRaza.descripcion,bDescripcion,QTY_CARACTERES);
            }
            if(getInt(&bIdTamanio, "\nIngrese el Id Tamanio: \n\n0-Chico\n1-Mediano\n2-Grande\n", "\nHa ingresado una edad invalida, reintente.",0,2,3)==0)
            {
                bRaza.idTamanio=bIdTamanio;
            }
            switch(bIdTamanio)
            {
                case 0:
                    strcpy(bRaza.tamanio,"Chico");
                    break;
                case 1:
                    strcpy(bRaza.tamanio,"Mediano");
                    break;
                case 2:
                    strcpy(bRaza.tamanio,"Grande");
                    break;
            }
            imprimirArrayPais(aPais);
            if(getInt(&bIdPaisOrigen, "\n Ingrese el ID del Pais de origen: ", "\nHa ingresado un valor invalido, reintente.",0,5,3)==0)
            {
                bRaza.idPaisOrigen = bIdPaisOrigen;
            }
            bRaza.id=id;
            bRaza.isEmpty=0;
            cRaza = 0;
        }while(cRaza != 0);

        altaRazaPorId(aRaza,QTY_RAZAS,bRaza);

		retorno = 0;
	}
	return retorno;
}
