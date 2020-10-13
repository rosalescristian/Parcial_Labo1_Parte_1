#define QTY_MASCOTAS 10
#define QTY_CARACTERES 20
#define QTY_HARDCODEO 5
#define QTY_RAZAS 10
#define QTY_TIPOS 10


#ifndef UTN_H_
#define UTN_H_

#endif /* UTN_H_ */
int funcionMenu(void);
int initArrayInt(int array[],int limite,int valor);
int imprimeArrayInt(int array[],int limite);
int getArrayInt(	int array[],
					int limite,
					char *mensaje,
					char *mensajeError,
					int minimo,
					int maximo,
					int reintentos);
int maximoArrayInt(int array[],int limite,int *pResultado);
int getInt(	int *pResultado,
			char *pMensaje,
			char *pMensajeError,
			int minimo,
			int maximo,
			int reintentos);
int ordenarArrayInt(int array[],int limite);
int ordenarArraySwapIntAsc(int array[] ,int limite);
int ordenarArraySwapIntDes(int array[] ,int limite);
int insertionSortArrayInt(int array[], int limite);
int getString(char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos);
int initArrayStr(char array[][QTY_CARACTERES],int limite,int valor);
int imprimeArrayStr(char array[][QTY_CARACTERES], int limite);
int getArrayStr(	char array[][QTY_CARACTERES],
					int limite,
					char *mensaje,
					char *mensajeError,
					int minimo,
					int maximo,
					int reintentos);
int ordenarArraySwapStrAsc(char array[][QTY_CARACTERES],int limite);
int ordenarArraySwapStrDesc(char array[][QTY_CARACTERES],int limite);
int ordenarArraySwapStrIntAscByInt(char arrayChars[][QTY_CARACTERES],int arrayInt[],int limite);
int ordenarArraySwapStrIntDescByInt(char arrayChars[][QTY_CARACTERES],int arrayInt[],int limite);
char getChar(char *resultado,
			char *mensaje,
			char *mensajeError,
			char minimo,
			char maximo,
			int reintentos);
int isCharOrSpace(char buffer[]);
int isFloat(char buffer[]);
int isInt(char buffer[]);
int isChar(char buffer[]);
char getCharBinario( char *resultado,
                    char *mensaje,
                    char *mensajeError,
                    char minimo,
                    char maximo,
                    int reintentos);
