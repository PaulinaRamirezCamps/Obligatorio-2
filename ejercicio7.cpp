#include <cstdint>
#include <iostream>
#include <string>
#include "funciones/divideAndConquer.cpp"

int main()
{
    std::int64_t N;
    std::cin >> N;
    int64_t *dorsales = new int64_t[N + 1];
    int64_t *aux = new int64_t[N + 1];
    for (int i = 0; i < N; i++)
    {
        std::cin >> dorsales[i];
    }
    std::cout << divideAndConquer(dorsales, aux, 0, N);
}