#ifndef RAZAS_H_INCLUDED
#define RAZAS_H_INCLUDED

struct sRazas
{
    int id;
    char descripcion[20];
    int idTamanio;
    char  tamanio[20];
    int idPaisOrigen;
    char paisOrigen[20];
    int isEmpty;
};

#endif // RAZAS_H_INCLUDED

int initLugarLibreRaza(struct sRazas *aRaza, int cantidad);
int altaForzadaRaza(struct sRazas *aArray, int cantidad);
int imprimirRaza(struct sRazas *aArray, int indexTipo);
int calculaLenRaza(struct sRazas *aArray, int *lenRaza);
int imprimirArrayRaza(struct sRazas *aArray);
int getDescripcionRaza(struct sRazas *aArray, int indexRaza, char nombreRaza[]);
int getTamanioRaza(struct sRazas *aArray, int indexRaza, char tamanioRaza[]);
int getPaisRaza(struct sRazas *aArray, int indexRaza, char paisRaza[]);
//int imprimirArrayMascotasPorRaza(struct sMascotas *aArray, struct sTipos *bArray, struct sRazas *cArray, int idRaza);
//int imprimirArrayMascotasPorRaza(struct sMascotas *aArray, struct sTipos *bArray, struct sRazas *cArray);
/*int getRazaStr(	struct sRazas *aRaza,
                struct sRazas bRaza,
                struct sPaises *aPais,
					int limite,
					int reintentos,
					int id);*/
