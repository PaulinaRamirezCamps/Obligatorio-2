#include <cstdint>
#include <iostream>
#include <string>

int64_t contarRE(int64_t* dorsales, int ini, int medio, int fin){
    int64_t remontadas = 0;
    int j = medio;
    for(int i= ini; i < medio; i++)
    {
        while(j < fin && dorsales[i] > 2 * dorsales[j]){ 
            j++;
        }
        remontadas += j-medio;
    }
    return remontadas;
}

void merge(int64_t* dorsales, int64_t* aux, int ini, int medio, int fin){
    int i = ini;
    int j = medio;
    int k = ini;
    while (i < medio && j < fin)
    {
        if (dorsales[i] <= dorsales[j])
        {
            aux[k] = dorsales[i];
            i++;
        }
        else
        {
            aux[k] = dorsales[j];
            j++;
        }
        k++;
    }
    while (i < medio)
    {
        aux[k] = dorsales[i];
        i++;
        k++;
    }

    while (j < fin)
    {
        aux[k] = dorsales[j];
        j++;
        k++;
    }
    for (int p = ini; p < fin; p++)
    {
        dorsales[p] = aux[p];
    }
}


int64_t divideAndConquer(int64_t* dorsales, int64_t* aux, int ini, int fin)
{
    if (fin - ini <= 1)
    {
        return 0;
    }

    int m = (ini + fin) / 2;

    int64_t si = divideAndConquer(dorsales, aux, ini, m);
    int64_t sd = divideAndConquer(dorsales, aux, m, fin);
    int64_t cruzadas = contarRE(dorsales, ini, m, fin);
    merge(dorsales, aux, ini, m, fin);
    
   return si + sd + cruzadas;
}
