
#include <iostream>
#include <string>
using namespace std;

int letras[26];
bool usado[10];

string palabras[6];
int K;
int cantidadLetras;
long long mejorResultado;
long long mejorSumandos[5];
bool haySolucion;

long long convertir(string palabra)
{
    long long numero = 0;

    for (int i = 0; i < palabra.size(); i++)
    {
        numero = numero * 10 + letras[palabra[i] - 'A'];
    }

    return numero;
}

bool sumaCorrecta()
{
    long long suma = 0;
    for (int i = 0; i < K; i++)
    {
        suma += convertir(palabras[i]);
    }
    return suma == convertir(palabras[K]);
}

bool esMejor()
{
    long long resultado = convertir(palabras[K]);

    if (!haySolucion || resultado < mejorResultado)
    {
        return true;
    }
    if (resultado > mejorResultado)
    {
        return false;
    }
    for (int i = 0; i < K; i++)
    {
        long long actual = convertir(palabras[i]);

        if (actual < mejorSumandos[i])
        {
            return true;
        }
        if (actual > mejorSumandos[i])
        {
            return false;
        }
    }

    return false;
}

void guardarSolucion()
{
    mejorResultado = convertir(palabras[K]);
    for (int i = 0; i < K; i++)
    {
        mejorSumandos[i] = convertir(palabras[i]);
    }
    haySolucion = true;
}

void resolver(int posicion)
{
    if (posicion == cantidadLetras)
    {
        if (sumaCorrecta() && esMejor())
        {
            guardarSolucion();
        }

        return;
    }

    int letra = -1;

    for (int i = 0; i < 26; i++)
    {
        if (letras[i] == -1)
        {
            letra = i;
            break;
        }
    }
    for (int digito = 0; digito <= 9; digito++)
    {
        if (!usado[digito])
        {

            bool ceroInicial = false;

            if (digito == 0)
            {
                for (int i = 0; i <= K; i++)
                {
                    if (palabras[i].size() > 1 &&
                        palabras[i][0] == letra + 'A')
                    {
                        ceroInicial = true;
                    }
                }
            }
            if (!ceroInicial)
            {
                letras[letra] = digito;
                usado[digito] = true;
                resolver(posicion + 1);
                letras[letra] = -1;
                usado[digito] = false;
            }
        }
    }
}
