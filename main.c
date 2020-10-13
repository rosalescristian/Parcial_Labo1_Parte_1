#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

int main()
{
    int retorno;
    retorno = -1;
    if(funcionMenu()==0)
    {
        retorno = 0;
    }
    return retorno;
}
