#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

struct sPaises
{
    int id;
    char nombrePais[20];
    int idContinente;
    char continente[20];
    int codigoTelefonico;
    int isEmpty;

};

#endif // PAIS_H_INCLUDED

int initLugarLibrePais(struct sPaises *aPais, int cantidad);
int altaForzadaPaises(struct sPaises *aArray, int cantidad);
int imprimirPais(struct sPaises *aArray, int indexPais);
int imprimirArrayPais(struct sPaises *aArray);
int getDescripcionPais(struct sPaises *aArray, int indexPais, char nombrePais[]);
//int getCodigoTelefonico(struct aPaises *aArray, int indexPais, int *codigoTelefonico);
