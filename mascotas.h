#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

struct sMascotas
{
    int id;
    char nombre[20];
    int edad;
    int peso;
    char sexo;
    int idTipo;
    int idPaisOrigen;
    int idRaza;
    int isEmpty;

};

#endif // MASCOTAS_H_INCLUDED


int initLugarLibreMascota(struct sMascotas *aMascota, int cantidad);
int altaForzadaMascotas(struct sMascotas *aArray, int cantidad);
int buscarLugarLibreMascota(struct sMascotas *aArray, int cantidad);
int altaMascotasPorId(struct sMascotas *aArray, int cantidad, struct sMascotas mascota);
int buscarMascotasPorId(struct sMascotas *aArray, int cantidad, int id);
//int bajaMascotasPorId(struct sMascotas *aArray, int cantidadMascotas, struct sRazas *bArray, int cantidadRazas, struct sTipos *cArray, int cantidadTipos);
/*int getMascotaStr(	struct sMascotas *aMascota,
                    struct sMascotas bMascota,
                    struct sRazas *aRaza,
                    struct sTipos *aTipo,
                    struct sPaises *aPais,
					int limite,
					int reintentos,
					int id);*/
int getNameMascota(    char *bName,
                        char *pMensaje,
                        char *pMensajeError,
                        int minimo,
                        int maximo,
                        int reintentos);
int getEdad(  int *pResultado,
                char *pMensaje,
                char *pMensajeError,
                int minimo,
                int maximo,
                int reintentos);
//int imprimirMascota(struct sMascotas *aArray, int indexMascota, struct sTipos *bArray, struct sRazas *cArray, struct sPaises *dArray);
//int imprimirArrayMascotas(struct sMascotas *aArray, struct sTipos *bArray, struct sRazas *cArray, int cantidadMascotas, int cantidadTipos, int cantidadRazas, struct sPaises *dArray, int cantidadPaises);
int getMascotaPorRaza(struct sMascotas *aArray, int idRaza, struct sMascotas aMascota);
//int ordenarStructMascotasPorPeso(struct sMascotas *aArray, struct sRazas *bArray, struct sTipos *cArray, int cantidadMascotas, int cantidadRazas, int cantidadTipos, struct sPaises *dArray, int cantidadPaises);
//int modificarMascotasPorId(struct sMascotas *aArray, int cantidadMascotas, struct sMascotas mascota, struct sRazas *bArray, int cantidadRazas, struct sTipos *cArray, int cantidadTipos, struct sPaises *dArray, int cantidadPaises);
int contarMascotasPorPais(struct sMascotas *aArray, int cantidadMascotas, int idPais, int *contadorMascotas);
//int paisConMayorCantidadMascotas(struct sMascotas *aArray, struct sRazas *bArray, int cantidadMascotas, int cantidadRazas, struct sPaises *dArray, int cantidadPaises);
//int ordenarStructMascotasPorCodigoTelefonico(struct sMascotas *aArray, struct sRazas *bArray, struct sTipos *cArray, int cantidadMascotas, int cantidadRazas, int cantidadTipos, struct sPaises *dArray, int cantidadPaises);
