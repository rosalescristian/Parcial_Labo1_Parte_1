#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

struct sTipos
{
    int id;
    char descripcion[20];
    int isEmpty;

};

#endif // TIPOS_H_INCLUDED
int initLugarLibreTipo(struct sTipos *aTipo, int cantidad);
int altaForzadaTipos(struct sTipos *aArray, int cantidad);
int imprimirTipo(struct sTipos *aArray, int indexTipo);
int calculaLenTipo(struct sTipos *aArray, int *lenTipo);
int imprimirArrayTipo(struct sTipos *aArray);
int getDescripcionTipo(struct sTipos *aArray, int indexTipo, char nombreTipo[]);
