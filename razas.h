#ifndef RAZAS_H_INCLUDED
#define RAZAS_H_INCLUDED

struct sRazas
{
    int id;
    char descripcion[20];
    int idTamanio;
    char  tamanio[20];
    int idPaisOrigen;
    int isEmpty;
};

#endif // RAZAS_H_INCLUDED

int initLugarLibreRaza(struct sRazas *aRaza, int cantidad);
int altaForzadaRaza(struct sRazas *aArray, int cantidad);
//int imprimirRaza(struct sRazas *aArray, int indexTipo, struct sPaises *bArray);
int calculaLenRaza(struct sRazas *aArray, int *lenRaza);
//int imprimirArrayRaza(struct sRazas *aArray, struct sPaises *bArray);
int getDescripcionRaza(struct sRazas *aArray, int indexRaza, char nombreRaza[]);
int getTamanioRaza(struct sRazas *aArray, int indexRaza, char tamanioRaza[]);
//int getPaisRaza(struct sRazas *aArray, int indexRaza, char paisRaza[], struct sPaises *bArray);
//int imprimirArrayMascotasPorRaza(struct sMascotas *aArray, struct sTipos *bArray, struct sRazas *cArray, int idRaza);
//int imprimirArrayMascotasPorRaza(struct sMascotas *aArray, struct sTipos *bArray, struct sRazas *cArray);
/*int getRazaStr(	struct sRazas *aRaza,
                struct sRazas bRaza,
                struct sPaises *aPais,
					int limite,
					int reintentos,
					int id);*/
//int bajaRazasPorId(struct sMascotas *aArray, int cantidadMascotas, struct sRazas *bArray, int cantidadRazas, struct sTipos *cArray, int cantidadTipos,struct sPaises *dArray, int cantidadPaises);
