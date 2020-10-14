#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "razas.h"
#include "mascotas.h"
#include "utn.h"
#include "tipos.h"

#define QTY_MASCOTAS 10
#define QTY_CARACTERES 20
#define QTY_HARDCODEO 5
#define QTY_RAZAS 10
#define QTY_TIPOS 10
#define QTY_PAISES 5

/** \brief Imprimo Mascota
 *
 * \param aArray recibe la direccion de memoria donde se almaceno la estructura a imprimir
 * \param indexMascota recibe el id de la mascota a imprimir
* \param bArray recibe la direccion de memoria donde se almaceno la estructura a imprimir
* \param cArray recibe la direccion de memoria donde se almaceno la estructura a imprimir
 * \return Devuelve 0 si pudo mostrar los elementos por pantalla, -1 si hubo algun error
 *
 */
int imprimirMascota(struct sMascotas *aArray, int indexMascota, struct sTipos *bArray, struct sRazas *cArray, struct sPaises *dArray)
{
	int retorno = -1;
	int lenMascota;
	int codigoTelefonico;
	char tipo[QTY_CARACTERES];
	char raza[QTY_CARACTERES];
	char pais[QTY_CARACTERES];

	if(aArray != NULL && indexMascota>=0 && bArray != NULL && cArray != NULL)
	{
		retorno = 0;
		lenMascota = QTY_MASCOTAS;
		for(int i=0;i<lenMascota;i++)
		{
            if(aArray[i].isEmpty== 0 && aArray[i].id == indexMascota)
            {
                getDescripcionTipo(bArray,aArray[i].idTipo,tipo);
                getDescripcionRaza(cArray,aArray[i].idRaza,raza);
                getPaisRaza(cArray,aArray[i].idPaisOrigen,pais,dArray);
                getCodigoTelefonico(dArray,aArray[i].idPaisOrigen,&codigoTelefonico);
                printf("ID: %02d - Nombre: %-20s - Edad: %02d - Peso: %02d - Sexo: %c - Raza: %-20s - Tipo: %-10s - Pais Origen: %-20s - Cod. Telefonico: %d\n",aArray[i].id, aArray[i].nombre,aArray[i].edad,aArray[i].peso,aArray[i].sexo,raza,tipo,pais,codigoTelefonico);
            }
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
int imprimirArrayMascotas(struct sMascotas *aArray, struct sTipos *bArray, struct sRazas *cArray, int cantidadMascotas, int cantidadTipos, int cantidadRazas, struct sPaises *dArray, int cantidadPaises)
{
	int retorno = -1;
	int lenMascota;
	if(aArray != NULL && bArray != NULL && cArray != NULL)
	{
		retorno = 0;
		lenMascota = cantidadMascotas;
		printf("\t***** LISTADO DE MASCOTAS *****\n\n");
		for(int i=0;i<lenMascota;i++)
		{
            if(aArray[i].isEmpty == 0)
            {
                imprimirMascota(aArray,aArray[i].id,bArray,cArray, dArray);
            }

        }
	}
	return retorno;
}
/** \brief Inicializa la estructura, setea todos los elementos como Empty
 *
 * \param aMascota recibe la direccion de memoria donde se encuentra la estructura a inicializar
 * \param cantidad recibe la cantidad de elementos de la estructura
 * \return Devuelve 0 si pudo iniciarlizarse, -1 si hubo algun error
 *
 */
int initLugarLibreMascota(struct sMascotas *aMascota, int cantidad)
{
	int retorno;
	int i;
	if(aMascota != NULL && cantidad >0)
	{
		retorno = -1;
		for(i=0;i<cantidad;i++)
		{
			aMascota[i].isEmpty=1;
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
 int altaForzadaMascotas(struct sMascotas *aArray, int cantidad)
{
	int i;
	int idMascota[] ={0,1,2,3,4,5,6};
	char nombre[][QTY_CARACTERES] = {"Bobby","Firulais","Negra","Nieve","Otto","Harry","Lonzo"};
	int edad[] = {1,2,5,7,3,4,2};
	int peso[] = {5,40,10,7,25,15,25};
	char sexo[] = {'M','M','F','F','M','M','F'};
	int idTipo[] = {0,1,0,0,1,1,1};
    int idPaisOrigen[] = {0,1,2,0,3,4,1};
    int idRaza[] = {0,1,2,0,3,4,5};

	int retorno;

    retorno = -1;
	for(i=0;i<cantidad;i++)
	{
		aArray[i].id = idMascota[i];
		strncpy(aArray[i].nombre,nombre[i],QTY_CARACTERES);
		aArray[i].edad = edad[i];
		aArray[i].peso = peso[i];
		aArray[i].sexo = sexo[i];
		aArray[i].idTipo = idTipo[i];
		aArray[i].idPaisOrigen = idPaisOrigen[i];
		aArray[i].idRaza = idRaza[i];
		aArray[i].isEmpty = 0;
	}
	retorno = 0;
	return retorno;
}

/** \brief Recorre el array de estructura y recupera el lugar libre
 *
 * \param aArray recibe el array de estructura a recorrer
 * \param cantidad recibe la cantidad de elementos maximos en el array
 * \return Devuelve la posicion libre en el array o -1 si hubo algun error
 *
 */
int buscarLugarLibreMascota(struct sMascotas *aArray, int cantidad)
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

/** \brief Da de alta un nuevo elemento en el array de estructura
 *
 * \param aArray recibe el array de estructura donde se ingresara el valor nuevo
 * \param cantidad recibe el valor de elementos del array
 * \param mascota recibe el nuevo elemento a ingresar en el array
 * \return Devuelve 0 si pudo ingresar el nuevo elemento, -1 si hubo algun error
 *
 */
int altaMascotasPorId(struct sMascotas *aArray, int cantidad, struct sMascotas mascota)
{
	int retorno;
	int bLugarLibre;

	if(aArray != NULL && cantidad > 0)
	{
		retorno = -1;
		bLugarLibre = buscarLugarLibreMascota(aArray, QTY_MASCOTAS);
		if(bLugarLibre != -1)
			{
				aArray[bLugarLibre]=mascota;
				retorno = 0;
			}
	}
	return retorno;
}

/** \brief Recorre el array de estructura y devuelve el valor de determinada posicion
 *
 * \param aArray recibe la direccion de memoria del array a recorrer
 * \param cantidad recibe el tamaño del array a recorrer
 * \param id recibe el id a buscar en el array
 * \return Devuelve el id buscado si lo pudo encontrar o -1 si hubo algun error
 *
 */
int buscarMascotasPorId(struct sMascotas *aArray, int cantidad, int id)
{
	int i;
	int retorno;
	if(aArray != NULL && cantidad>0 && id > 0)
	{
		retorno  = -1;
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].id == id)
			{
				retorno = id;
				break;
			}

		}
	}
	return retorno;
}

/** \brief Da de beja un elemento en el array de estructura
 *
 * \param aArray recibe la direccion de memoria donde se encuentra el array de estructura
 * \param cantidad recibe el tamaño del array a recorrer
 * \return Devuelve 0 si se pudo procesar la baja o -1 si hubo algun error.
 *
 */
int bajaMascotasPorId(struct sMascotas *aArray, int cantidadMascotas, struct sRazas *bArray, int cantidadRazas, struct sTipos *cArray, int cantidadTipos,struct sPaises *dArray, int cantidadPaises)
{
	int retorno;
	int idEditable;
	char seguir;

	if(aArray != NULL && cantidadMascotas>0 && bArray != NULL && cantidadRazas > 0 && cArray != NULL)
	{
	    system("cls");
        imprimirArrayMascotas(aArray, cArray,bArray,cantidadMascotas,cantidadTipos,cantidadRazas,dArray,cantidadPaises);
        retorno = -1;
        seguir = 'N';
		if(getInt(&idEditable,"\nSeleccione el id a dar de baja: \n","Ha seleccionado un id no valido. Reintente\n",0,cantidadMascotas-1,3)==0)
        {
            system("cls");
            printf("Va a eliminar la siguiente mascota: \n\n");
            imprimirMascota(aArray, idEditable, cArray, bArray, dArray);
            getCharBinario(&seguir, "Desea proceder(S/N): \n", "La respuesta es invalida, reintente.\n",'N','S',3);
            if(seguir == 'S')
            {
                aArray[idEditable].isEmpty=1;
                retorno = 0;
            }
        }
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
int getMascotaStr(	struct sMascotas *aMascota,
                    struct sMascotas bMascota,
                    struct sRazas *aRaza,
                    struct sTipos *aTipo,
                    struct sPaises *aPais,
					int limite,
					int reintentos,
					int id)
{
	int retorno;
	char bNombre[QTY_CARACTERES];
	char bSexo;
	int bEdad;
	int bPeso;
	int cMascota;
	int bIdRaza;
	int bTipo;
	int bIdPais;

	if(		aMascota != NULL &&
            limite > 0 &&
			reintentos > 0 &&
			id != -1)
	{
		do
		{
		    retorno = -1;
		    cMascota = -1;

		    if(getNameMascota(bNombre, "\nIngrese el nombre del mascota: ", "\nHa ingresado un nombre invalido, reintente.", 2, sizeof(bNombre),3)==0)
            {
                strncpy(bMascota.nombre,bNombre,QTY_CARACTERES);
            }
            if(getInt(&bEdad, "\nIngrese la edad de la mascota: ", "\nHa ingresado una edad invalida, reintente.", 0, 500,3)==0)
            {
                bMascota.edad=bEdad;
            }
            if(getInt(&bPeso, "\n Ingrese el peso de la mascota: ", "\nHa ingresado un valor invalido, reintente.",0,500,3)==0)
            {
                bMascota.peso = bPeso;
            }
            if(getCharBinario(&bSexo,"\nIngrese el sexo de la mascota (F-M): ", "\nHa ingresado un sexo invalido\n", 'F','M',3)==0)
            {
                bMascota.sexo=bSexo;
            }
            imprimirArrayTipo(aTipo);
            if(getInt(&bTipo, "\nSeleccione el ID del Tipo de Mascota: ", "Ha ingresado un tipo invalido\n",0,2,3)==0)
            {
                bMascota.idTipo=bTipo;
            }
            imprimirArrayRaza(aRaza, aPais);
            if(getInt(&bIdRaza, "\nSelecccione el Id de la raza para la Mascota: ", "\nHa ingresado un id invalido, reintente.",0,QTY_RAZAS,3)==0)
            {
                bMascota.idRaza=bIdRaza;
            }
            imprimirArrayPais(aPais);
            if(getInt(&bIdPais,"\nSeleccione el Id del pais de Origen: ","\nHa ingresado una opcion invalida, reintente",0,QTY_PAISES,3)==0)
            {
                bMascota.idPaisOrigen=bIdPais;
            }
            bMascota.id=id;
            bMascota.isEmpty=0;
            cMascota = 0;
        }while(cMascota != 0);

        altaMascotasPorId(aMascota,QTY_MASCOTAS,bMascota);

		retorno = 0;
	}
	return retorno;
}

/** \brief Capturo del usuario el campo nombre del elemento Mascota dentro de la estructura
 *
 * \param bName es la direccion de memoria donde almacenaremos el resultado de la consulta
 * \param pMensaje es la consigna que le brindaremos al usuario
 * \param pMensajeError es el mensaje de error que se le dara al usuario en caso de un ingreso erroneo
 * \param minimo es el valor minimo aceptado por la funcion
 * \param maximo es el valor maximo aceptado por la funcion
 * \param reintentos es la cantidad de reintentos que tendra el usuario en caso de un ingreso erroneo
 * \return Devuelve 0 si pudo capturar el dato o -1 si hubo algun error
 *
 */

int getNameMascota(    char *bName,
                        char *pMensaje,
                        char *pMensajeError,
                        int minimo,
                        int maximo,
                        int reintentos)
{
	int retorno = -1;
	char buffer[255];

	if(		bName != NULL &&
			pMensaje != NULL &&
			pMensajeError != NULL &&
			minimo < maximo &&
			reintentos > 0)
	{
		do
		{
			printf("%s",pMensaje);
			fflush(stdin);
			fgets(buffer,sizeof(buffer),stdin);
			buffer[strlen(buffer)-1]='\0';
			if(strlen(buffer)<=maximo && strlen(buffer)>=minimo)
			{
                if(isCharOrSpace(buffer)==0)
                {
                    strncpy(bName,buffer,maximo+1);
                    retorno = 0;
                    break;
                }
            }
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

/** \brief Capturo del usuario el campo sector del elemento Mascota dentro de la estructura
 *
 * \param pResultado es la direccion de memoria donde almacenaremos el resultado de la consulta
 * \param pMensaje es la consigna que le brindaremos al usuario
 * \param pMensajeError es el mensaje de error que se le dara al usuario en caso de un ingreso erroneo
 * \param minimo es el valor minimo aceptado por la funcion
 * \param maximo es el valor maximo aceptado por la funcion
 * \param reintentos es la cantidad de reintentos que tendra el usuario en caso de un ingreso erroneo
 * \return Devuelve 0 si pudo capturar el dato o -1 si hubo algun error
 *
 */

int getEdad(  int *pResultado,
                char *pMensaje,
                char *pMensajeError,
                int minimo,
                int maximo,
                int reintentos)
{
    int errorCarga;
	int retorno = -1;
	char buffer[255];
	int bufferDos;
	do
		{
			printf("%s",pMensaje);
			fflush(stdin);
			fgets(buffer,sizeof(buffer),stdin);
			buffer[strlen(buffer)-1]='\0'; // con esto contamos el largo del string, y en la ultima posicion ponemos el "\0"
            for(int i=0;i<strlen(buffer);i++)
            {
                if(buffer[i]>='0' && buffer[i]<='9')
                {
                    errorCarga = 0;
                }
                else
                {
                    errorCarga = -1;
                    break;
                }
            }
			if(errorCarga==0)
            {
                bufferDos=atoi(buffer);
                if(bufferDos >= minimo && bufferDos <= maximo)
                {
                    //retorno = bufferDos;
                    *pResultado = bufferDos;
                    retorno = 0;
                    break;
                }
            }
			printf("%s\n",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
    return retorno;
}




 /** \brief Recupero una mascota de acuerdo a un ID de raza
 *
 * \param aArray recibe la direccion de memoria donde se almaceno la estructura a recorrer
 * \param idRaza recibe el Id de raza a recuperar
 * \param aMascota es la direccion de memoria donde almacena la mascota
  * \return Devuelve 0 si pudo mostrar los elementos por pantalla, -1 si hubo algun error
 *
 */
int getMascotaPorRaza(struct sMascotas *aArray, int idRaza, struct sMascotas aMascota)
{
    int retorno;
    int lenMascotas;
    if(aArray != NULL && idRaza >= 0)
    {
        lenMascotas = QTY_MASCOTAS;
        for(int i =0;i<lenMascotas;i++)
        {
            if(aArray[i].idRaza == idRaza)
            {
                aMascota = aArray[i];
                retorno = 0;
            }
        }
    }
    return retorno;
}

/** \brief Ordena los elementos de la estructura por Nombre o Apellido
 *
 * \param aEmpleado recibe la estructura a ordenar
 * \param cantidad recibe la cantidad de elementos en la estructura
 * \return Devuelve 0 si pudo ordenar la estructura o -1 si hubo algun error
 *
 */
int ordenarStructMascotasPorPeso(struct sMascotas *aArray, struct sRazas *bArray, struct sTipos *cArray, int cantidadMascotas, int cantidadRazas, int cantidadTipos, struct sPaises *dArray, int cantidadPaises)
{
	int i;
	int j;
	int retorno = -1;
	struct sMascotas bMascota;
	int fSwap;
	if(aArray != NULL && cantidadMascotas>0 && bArray != NULL && cantidadRazas >0 && cArray != NULL && cantidadTipos > 0)
	{
		do
		{
			fSwap = 0;
			for(i=0;i<cantidadMascotas-1;i++)
			{
				j = i+1;
				if(aArray[i].isEmpty == 0 && aArray[j].isEmpty == 0 && aArray[i].peso > aArray[j].peso)
                {
                    fSwap = 1;
                    bMascota = aArray[i];
                    aArray[i]=aArray[j];
                    aArray[j]=bMascota;
                }
			}
			retorno = 0;
		}while(fSwap==1);
		imprimirArrayMascotas(aArray,cArray, bArray,cantidadMascotas,cantidadTipos,cantidadRazas, dArray, cantidadPaises);
	}
	return retorno;
}

/** \brief Modifica los datos de un elemento del array de estructura
 *
 * \param aArray recibe la direccion de memoria donde se encuentra almacenado el elemento a modificar
 * \param cantidadMascotas recibe el tamaño del array
 * \param bArray recibe la direccion de memoria donde se encuentra almacenado el elemento a modificar
 * \param cantidadRazas recibe el tamaño del array
 * \param cArray recibe la direccion de memoria donde se encuentra almacenado el elemento a modificar
 * \param cantidadTipos recibe el tamaño del array
 * \param recibe los datos a ingresar
 * \return Devuelve 0 si pudo hacer la modificacion o -1 si hubo algun error
 *
 */
int modificarMascotasPorId(struct sMascotas *aArray, int cantidadMascotas, struct sMascotas mascota, struct sRazas *bArray, int cantidadRazas, struct sTipos *cArray, int cantidadTipos, struct sPaises *dArray, int cantidadPaises)
{
    int retorno;
	char bNombre[QTY_CARACTERES];
	char bSexo;
	int bEdad;
	int bPeso;
	int bIdRaza;
    int idEditable;
    int campoEditable;
    int bTipo;
    int bIdPaisOrigen;
    char seguir;
do{
    system("cls");
    imprimirArrayMascotas(aArray,cArray, bArray,cantidadMascotas,cantidadTipos,cantidadRazas, dArray,cantidadPaises);
    retorno = -1;
    seguir = 'N';
    printf("1");
    if(getInt(&idEditable,"\nIngrese el id a editar: \n\n","Ha seleccionado una opcion no valida. Reintente\n\n",0,cantidadMascotas-1,3)==0)

    {
        for(int i=0;i<cantidadMascotas;i++)
        {
            if(aArray[i].id == idEditable && aArray[i].isEmpty == 0)
            {
                mascota=aArray[i];
            }
        }
        imprimirMascota(aArray, mascota.id, cArray, bArray,dArray);
        if(getInt(&campoEditable,"Ingrese el campo a editar (1/7)\n\n","Ha elegido un campo invalido, reintente.\n",1,7,3)==0)
        {
            switch(campoEditable)
            {
                case 1:
                    printf("Va a editar el Nombre: %s\n", mascota.nombre);
                    if(getNameMascota(bNombre,"Ingrese el nuevo Nombre: \n", "Ha ingresado un nombre Invalido. Reintente\n",2,sizeof(bNombre),3)==0)
                    {
                        strncpy(mascota.nombre,bNombre,QTY_CARACTERES);
                        printf("El nuevo Nombre es: %s\n", mascota.nombre);
                        getChar(&seguir, "Desea modificar alguna otra Mascota?(S/N)", "La respuesta es invalida, reintente.",'N','S',3);

                    }
                    break;
                case 2:
                    printf("Va a editar la edad: %d\n", mascota.edad);
                    if(getInt(&bEdad,"Ingrese la nueva edad: \n", "Ha ingresado una edad Invalida. Reintente\n",0,500,3)==0)
                    {
                        mascota.edad= bEdad;
                        printf("La nueva edad es: %d\n", mascota.edad);
                        getChar(&seguir, "Desea modificar alguna otra Mascota?(S/N)", "La respuesta es invalida, reintente.",'N','S',3);

                    }
                    break;
                case 3:
                    printf("Va a editar el peso: %d\n", mascota.peso);
                    if(getInt(&bPeso,"Ingrese el nuevo Peso: \n", "Ha ingresado un valor Invalido. Reintente\n",0,500,3)==0)
                    {
                        mascota.peso= bPeso;
                        printf("el Nuevo peso es: %d\n", mascota.peso);
                        getChar(&seguir, "Desea modificar alguna otra Mascota?(S/N)", "La respuesta es invalida, reintente.",'N','S',3);

                    }
                    break;
                case 4:
                    printf("Va a editar el sexo: %c\n", mascota.sexo);
                    if(getCharBinario(&bSexo,"Ingrese el nuevo Sexo: \n", "Ha ingresado un caracter Invalido. Reintente\n",'F','M',3)==0)
                    {
                        mascota.sexo=bSexo;
                        printf("El nuevo Sexo es: %c\n", mascota.sexo);
                        getChar(&seguir, "Desea modificar alguna otra Mascota?(S/N)", "La respuesta es invalida, reintente.",'N','S',3);

                    }
                    break;
                case 5:
                    printf("Va a editar el ID de Tipo: %d\n Recuerde actualizar el ID de raza\n", mascota.idTipo);
                    imprimirArrayTipo(cArray);
                    if(getInt(&bTipo, "Seleccione el nuevo ID de Tipo: ", "Ha ingresado un valor invalido, reintente. ", 0, QTY_TIPOS-1,3)==0)
                    {
                        mascota.idTipo=bTipo;
                        printf("El nuevo ID de tipo es: %d\n Recuerde Actualizar el ID de Raza",mascota.idTipo);
                        getChar(&seguir, "Desea modificar alguna otra Mascota?(S/N)", "La respuesta es invalida, reintente.",'N','S',3);
                    }
                    break;
                case 6:
                    system("cls");
                    printf("Va a editar el ID Pais Origen: ID %d  Recuerde actualizar el ID de raza\n", mascota.idPaisOrigen);
                    imprimirArrayRaza(bArray, dArray);
                    if(getInt(&bIdPaisOrigen, "Seleccione el nuevo ID de Pais Origen: ", "Ha seleccionado un valor invalido, reintente",0,3,3)==0)
                    {
                        mascota.idPaisOrigen=bIdPaisOrigen;
                        printf("El nuevo ID de Pais Origen: %d\n",mascota.idPaisOrigen);
                        getChar(&seguir, "Desea modificar alguna otra Mascota?(S/N)", "La respuesta es invalida, reintente.",'N','S',3);
                    }
                    break;
                case 7:
                    system("cls");
                    printf("Va a editar el ID de Raza: ID %d", mascota.idRaza);
                    imprimirArrayRaza(bArray, dArray);
                    if(getInt(&bIdRaza, "Seleccione el nuevo ID de Raza: ", "Ha seleccionado un valor invalido, reintente",0,QTY_RAZAS,3)==0)
                    {
                        mascota.idRaza=bIdRaza;
                        printf("El nuevo ID de Raza es: %d\n",mascota.idRaza);
                        getChar(&seguir, "Desea modificar alguna otra Mascota?(S/N)", "La respuesta es invalida, reintente.",'N','S',3);
                    }
                    switch(bIdRaza)
                    {
                        case 1:
                                mascota.idTipo=1;
                                mascota.idPaisOrigen=1;
                                break;
                        case 2:
                                mascota.idTipo=2;
                                mascota.idPaisOrigen=2;
                                break;
                        case 3:
                                mascota.idTipo=1;
                                mascota.idPaisOrigen=3;
                                break;
                        case 4:
                                mascota.idTipo=2;
                                mascota.idPaisOrigen=4;
                                break;
                    }
                    break;
                }
            }

        }
        aArray[idEditable]=mascota;
    }while(seguir == 'S');

    retorno = 0;
    return retorno;
}

int contarMascotasPorPais(struct sMascotas *aArray, int cantidadMascotas, int idPais, int *contadorMascotas)
{
    int retorno;
    int mascotas;
    if(aArray != NULL && idPais > -1)
    {
        mascotas = 0;
        for(int i=0; i<cantidadMascotas; i++)
        {
            if(aArray[i].isEmpty == 0 && aArray[i].idPaisOrigen == idPais)
            {
                mascotas++;
            }
        }
    *contadorMascotas = mascotas;
    retorno = 0;
    }
    return retorno;
}

/** \brief Imprime por pantalla el pais que tiene mayor cantidad de mascotas y de cuantos animales se trata
 *
 * \param aArray recibe la direccion de memoria de la estructura Mascotas
 * \param cantidadMascotas
 * \param bArray recibe la direccion de memoria de la estructura Razas
 * \param cantidadRazas
 * \param dArray recibe la direccion de memoria de la estructura Paies
 * \param cantidadPases
 * \return 0 si fue exitoso, -1 si hubo algun error
 *
 */
int paisConMayorCantidadMascotas(struct sMascotas *aArray, struct sRazas *bArray, int cantidadMascotas, int cantidadRazas, struct sPaises *dArray, int cantidadPaises)
{
    int retorno;
    int contadorMascotas;
    int maxContador;
    int idPais;
    char nombrePais[QTY_CARACTERES];

    retorno = -1;
    if(aArray != NULL && bArray != NULL && cantidadMascotas > 0 && cantidadRazas > 0)
    {
        contadorMascotas = 0;
        maxContador = 0;
        for(int i=0;i<cantidadRazas;i++)
        {
            if(bArray[i].isEmpty == 0)
            {
                idPais = bArray[i].idPaisOrigen;
                if(i==0 || idPais != bArray[i].idPaisOrigen)
                {
                    contarMascotasPorPais(aArray,cantidadMascotas,idPais,&contadorMascotas);
                }
                if(i == 0 || contadorMascotas > maxContador)
                {
                    maxContador = contadorMascotas;
                    idPais = idPais;
                    getDescripcionPais(dArray, idPais,nombrePais);
                }
            }
        }
    retorno = 0;
    printf("El pais con mayor cantidad de mascotas es: %-20s con %d mascotas.\n",nombrePais,maxContador);
    }

    return retorno;
}

/** \brief Ordena los elementos de la estructura por Codigo Telefonico
 *
 * \param aEmpleado recibe la estructura a ordenar
 * \param cantidad recibe la cantidad de elementos en la estructura
 * \return Devuelve 0 si pudo ordenar la estructura o -1 si hubo algun error
 *
 */
int ordenarStructMascotasPorCodigoTelefonico(struct sMascotas *aArray, struct sRazas *bArray, struct sTipos *cArray, int cantidadMascotas, int cantidadRazas, int cantidadTipos, struct sPaises *dArray, int cantidadPaises)
{
	int i;
	int j;
	int retorno = -1;
	int codigoTelefonicoI;
	int codigoTelefonicoJ;
	struct sMascotas bMascota;
	int fSwap;
	if(aArray != NULL && cantidadMascotas>0 && bArray != NULL && cantidadRazas >0 && cArray != NULL && cantidadTipos > 0 && dArray != NULL && cantidadPaises > 0)
	{
		do
		{
			fSwap = 0;
			for(i=0;i<cantidadMascotas-1;i++)
			{
				j = i+1;
				if(aArray[i].isEmpty == 0 && aArray[j].isEmpty == 0)
                {
                    getCodigoTelefonico(dArray,aArray[i].idPaisOrigen,&codigoTelefonicoI);
                    getCodigoTelefonico(dArray,aArray[j].idPaisOrigen,&codigoTelefonicoJ);
                    if(codigoTelefonicoI<codigoTelefonicoJ)
                    {
                        fSwap = 1;
                        bMascota = aArray[i];
                        aArray[i]=aArray[j];
                        aArray[j]=bMascota;
                    }

                }
			}
			retorno = 0;
		}while(fSwap==1);
		imprimirArrayMascotas(aArray,cArray, bArray,cantidadMascotas,cantidadTipos,cantidadRazas, dArray, cantidadPaises);
	}
	return retorno;
}



/** \brief Da de beja un elemento en el array de estructura
 *
 * \param aArray recibe la direccion de memoria donde se encuentra el array de estructura
 * \param cantidad recibe el tamaño del array a recorrer
 * \return Devuelve 0 si se pudo procesar la baja o -1 si hubo algun error.
 *
 */
int bajaMascotasPorIdAutomatica(struct sMascotas *aArray, int cantidadMascotas, struct sRazas *bArray, int cantidadRazas, struct sTipos *cArray, int cantidadTipos,struct sPaises *dArray, int cantidadPaises, int idRaza)
{
	int retorno;
	int idEditable;
	char seguir;

	if(aArray != NULL && cantidadMascotas>0 && bArray != NULL && cantidadRazas > 0 && cArray != NULL)
	{
        for(int i=0; i<cantidadMascotas;i++)
        {
            if(aArray[i].idRaza==idRaza)
            {
                aArray[i].isEmpty = 1;
            }
        }
        retorno = 0;
    }
	return retorno;
}

/** \brief Imprime por pantalla el cantidad de mascotas por pais, total de pesa de todas las mascotas y el promedio de peso por tipo de mascota
 *
 * \param aArray recibe la direccion de memoria de la estructura Mascotas
 * \param cantidadMascotas
 * \param bArray recibe la direccion de memoria de la estructura Razas
 * \param cantidadRazas
 * \param dArray recibe la direccion de memoria de la estructura Paies
 * \param cantidadPases
 * \return 0 si fue exitoso, -1 si hubo algun error
 *
 */
int listarPorPesoTipo(struct sMascotas *aArray, int cantidadMascotas, struct sRazas *bArray, int cantidadRazas, struct sTipos *cArray, int cantidadTipos, struct sPaises *dArray, int cantidadPaises)
{
    int retorno;
    float contadorMascotasTipoCero;
    float contadorMascotasTipoUno;
    float contadorMascotasTipoDos;
    float sumaPesoMascotasTipoCero;
    float sumaPesoMascotasTipoUno;
    float sumaPesoMascotasTipoDos;
    float promedioPesoMascotasTipoCero;
    float promedioPesoMascotasTipoUno;
    float promedioPesoMascotasTipoDos;
    int idTipo;
    char nombreTipoCero[QTY_CARACTERES];
    char nombreTipoUno[QTY_CARACTERES];
    char nombreTipoDos[QTY_CARACTERES];

    retorno = -1;

    if(aArray != NULL && bArray != NULL && cArray != NULL && dArray != NULL && cantidadMascotas > 0 && cantidadRazas > 0 && cantidadTipos > 0 && cantidadRazas > 0)
    {
        sumarPesosMascotas(aArray, cantidadMascotas, 0,&sumaPesoMascotasTipoCero);
        contadorMascotasPorTipo(aArray,cantidadMascotas,0,&contadorMascotasTipoCero);
        getDescripcionTipo(cArray,0,nombreTipoCero);

        sumarPesosMascotas(aArray, cantidadMascotas, 1,&sumaPesoMascotasTipoUno);
        contadorMascotasPorTipo(aArray,cantidadMascotas,1,&contadorMascotasTipoUno);
        getDescripcionTipo(cArray,1,nombreTipoUno);

        sumarPesosMascotas(aArray, cantidadMascotas, 2,&sumaPesoMascotasTipoDos);
        contadorMascotasPorTipo(aArray,cantidadMascotas,2,&contadorMascotasTipoDos);
        getDescripcionTipo(cArray,2,nombreTipoDos);
    }
    if(sumaPesoMascotasTipoCero > 0 )
    {
        promedioPesoMascotasTipoCero= sumaPesoMascotasTipoCero/contadorMascotasTipoCero;
    }
    if(sumaPesoMascotasTipoUno > 0 )
    {
        promedioPesoMascotasTipoUno= sumaPesoMascotasTipoUno/contadorMascotasTipoUno;
    }
    if(sumaPesoMascotasTipoDos > 0 )
    {
        promedioPesoMascotasTipoDos= sumaPesoMascotasTipoDos/contadorMascotasTipoDos;
    }
    retorno = 0;

    printf("***************************************************************************************\n");
    printf("***** CANT MASCOTAS POR TIPO - PESO ACUMULADO POR TIPO - PROMEDIO DE PESO POR TIPO *****\n");
    printf("***************************************************************************************\n");
    printf("Mascotas Tipo: %-10s - Cantidad: %-.2f - Peso Acumulado: %-.2f - Peso Promedio: %-.2f\n",nombreTipoCero,contadorMascotasTipoCero,sumaPesoMascotasTipoCero,promedioPesoMascotasTipoCero);
    printf("Mascotas Tipo: %-10s - Cantidad: %-.2f - Peso Acumulado: %-.2f - Peso Promedio: %-.2f\n",nombreTipoUno,contadorMascotasTipoUno,sumaPesoMascotasTipoUno,promedioPesoMascotasTipoUno);
    printf("Mascotas Tipo: %-10s - Cantidad: %-.2f - Peso Acumulado: %-.2f - Peso Promedio: %-.2f\n",nombreTipoDos,contadorMascotasTipoDos,sumaPesoMascotasTipoDos,promedioPesoMascotasTipoDos);

    return retorno;
}

int sumarPesosMascotas(struct sMascotas *aArray, int cantidadMascotas, int idTipo, float *sumaPesoMascotas)
{
    int retorno;
    float pesoMascotas;
    retorno = -1;
    *sumaPesoMascotas = 0;
    if(aArray != NULL && idTipo > -1)
    {
        pesoMascotas = 0;
        for(int i=0; i<cantidadMascotas; i++)
        {
            if(aArray[i].isEmpty == 0 && aArray[i].idTipo == idTipo)
            {
                pesoMascotas = pesoMascotas + aArray[i].peso;
            }
        }
    *sumaPesoMascotas = pesoMascotas;
    retorno = 0;
    }
    return retorno;
}

int contadorMascotasPorTipo(struct sMascotas *aArray, int cantidadMascotas, int idTipo, float *sumaPesoMascotas)
{
    int retorno;
    float pesoMascotas;
    *sumaPesoMascotas = 0;
    if(aArray != NULL && idTipo > -1)
    {
        pesoMascotas = 0;
        for(int i=0; i<cantidadMascotas; i++)
        {
            if(aArray[i].isEmpty == 0 && aArray[i].idTipo == idTipo)
            {
                pesoMascotas++;
            }
        }
    *sumaPesoMascotas = pesoMascotas;
    retorno = 0;
    }
    return retorno;
}

