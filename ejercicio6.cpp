#include <cstdint>
#include <iostream>
#include <limits>
#include "funciones/greedy.cpp"

using namespace std;
int main()
{
    std::int64_t N;
    std::cin >> N;
    int frecuencia[1001];
    for (int i = 0; i < 1001; i++)
    {
        frecuencia[i] = 0;
    }
    for (int i = 0; i < N; i++)
    {
        int numero;
        std::cin >> numero;
        frecuencia[numero]++;
    }
    std::cout << greedy(frecuencia);
    return 0;
}
