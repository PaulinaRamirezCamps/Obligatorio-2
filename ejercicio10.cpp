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
        cantidadLetras = 0;
        for (int i = 0; i <= K; i++)
        {
            for (int j = 0; j < palabras[i].size(); j++)
            {
                int letra = palabras[i][j] - 'A';

                if (letras[letra] == -1)
                {
                    letras[letra] = -2;
                    cantidadLetras++;
                }
            }
        }

        for (int i = 0; i < 26; i++)
        {
            if (letras[i] == -2)
            {
                letras[i] = -1;
            }
        }

        haySolucion = false;
        resolver(0);
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
