#include <iostream>
#include <string>
#include <cstdint>
using namespace std;

int letras[26];
bool usado[10];
bool letraInicial[26];

string palabras[6];
int K;
int cantidadColumnas;
int64_t mejorResultado;
int64_t mejorSumandos[5];
bool haySolucion;

int64_t convertir(string palabra)
{
    int64_t numero = 0;
    for (size_t i = 0; i < palabra.size(); i++)
    {
        numero = numero * 10 + letras[palabra[i] - 'A'];
    }
    return numero;
}

int64_t limiteInferior(string palabra)
{
    int64_t numero = 0;

    for (size_t i = 0; i < palabra.size(); i++)
    {
        int digito = letras[palabra[i] - 'A'];
        if (digito < 0)
        {
            digito = 0;
        }
        numero = numero * 10 + digito;
    }

    return numero;
}

bool puedeMejorar()
{
    if (!haySolucion)
    {
        return true;
    }
    int64_t resultadoMinimo = limiteInferior(palabras[K]);
    if (resultadoMinimo < mejorResultado)
    {
        return true;
    }
    if (resultadoMinimo > mejorResultado)
    {
        return false;
    }

    for (int i = 0; i < K; i++)
    {
        int64_t sumandoMinimo = limiteInferior(palabras[i]);
        if (sumandoMinimo < mejorSumandos[i])
        {
            return true;
        }
        if (sumandoMinimo > mejorSumandos[i])
        {
            return false;
        }
    }

    return false;
}

bool esMejor()
{
    int64_t resultado = convertir(palabras[K]);

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
        int64_t actual = convertir(palabras[i]);

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

void resolverColumna(int columna, int64_t acarreo);

void asignarLetrasColumna(int indice, int cantidad, int letrasColumna[6], int columna, int64_t acarreo)
{
    if (!puedeMejorar())
    {
        return;
    }
    if (indice == cantidad)
    {
        int64_t total = acarreo;
        for (int i = 0; i < K; i++)
        {
            int posicion = (int)palabras[i].size() - 1 - columna;
            if (posicion >= 0)
            {
                total += letras[palabras[i][posicion] - 'A'];
            }
        }
        int digitoResultado = (int)(total % 10);
        int posicionResultado = (int)palabras[K].size() - 1 - columna;
        if (posicionResultado >= 0)
        {
            int letraResultado = palabras[K][posicionResultado] - 'A';
            if (letras[letraResultado] != digitoResultado)
            {
                return;
            }
        }
        else if (digitoResultado != 0)
        {
            return;
        }

        resolverColumna(columna + 1, total / 10);
        return;
    }

    int letra = letrasColumna[indice];
    for (int digito = 0; digito <= 9; digito++)
    {
        if (!usado[digito] && !(digito == 0 && letraInicial[letra]))
        {
            letras[letra] = digito;
            usado[digito] = true;
            asignarLetrasColumna(indice + 1, cantidad, letrasColumna, columna, acarreo);
            letras[letra] = -1;
            usado[digito] = false;
        }
    }
}

void resolverColumna(int columna, int64_t acarreo)
{
    if (!puedeMejorar())
    {
        return;
    }

    if (columna == cantidadColumnas)
    {
        if (acarreo == 0 && esMejor())
        {
            guardarSolucion();
        }
        return;
    }

    int letrasColumna[6];
    int cantidad = 0;

    for (int i = 0; i <= K; i++)
    {
        int posicion = (int)palabras[i].size() - 1 - columna;
        if (posicion >= 0)
        {
            int letra = palabras[i][posicion] - 'A';
            if (letras[letra] == -1)
            {
                bool repetida = false;
                for (int j = 0; j < cantidad && !repetida; j++)
                {
                    if (letrasColumna[j] == letra)
                    {
                        repetida = true;
                    }
                }
                if (!repetida)
                {
                    letrasColumna[cantidad++] = letra;
                }
            }
        }
    }
    asignarLetrasColumna(0, cantidad, letrasColumna, columna, acarreo);
}
