
#include <string>

std::string greedy(int* frecuencia){

    std::string izquierda = "";
    std::string derecha = "";
    int centro = -1;
    for(int i = 1000 ; i>=0; i--)
    {
        int parejas = frecuencia[i]/2;

        for(int j=0; j<parejas; j++)
        {
            izquierda += std::to_string(i) + " ";
        }

        if(frecuencia[i] % 2 == 1 && centro == -1 ){
            centro = i;
        }
    }
    if (centro != -1)
    {
        izquierda += std::to_string(centro) + " ";
    }
     for(int i = 0 ; i<=1000; i++)
    {
        int parejas = frecuencia[i]/2;

        for(int j=0; j<parejas; j++)
        {
            derecha += std::to_string(i) + " ";
        }

    }
    return izquierda + derecha;
}