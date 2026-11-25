#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "funciones/backTracking.cpp"

int main()
{
    int T;
    cin >> T;

    while (T > 0)
    {
        cin >> K;
        for (int i = 0; i <= K; i++)
        {
            cin >> palabras[i];
        }
        for (int i = 0; i < 26; i++)
        {
            letras[i] = -1;
        }
        for (int i = 0; i < 10; i++)
        {
            usado[i] = false;
        }
        for (int i = 0; i < 26; i++)
        {
            letraInicial[i] = false;
        }
        cantidadColumnas = 0;
        for (int i = 0; i <= K; i++)
        {
            if (palabras[i].size() > 1)
            {
                letraInicial[palabras[i][0] - 'A'] = true;
            }
            if ((int)palabras[i].size() > cantidadColumnas)
            {
                cantidadColumnas = (int)palabras[i].size();
            }
        }

        haySolucion = false;
        resolverColumna(0, 0);
        if (!haySolucion)
        {
            cout << "imposible" << endl;
        }
        else
        {
            for (int i = 0; i < K; i++)
            {
                if (i > 0)
                {
                    cout << " + ";
                }

                cout << mejorSumandos[i];
            }
            cout << " = " << mejorResultado << endl;
        }
        T--;
    }

    return 0;
}
