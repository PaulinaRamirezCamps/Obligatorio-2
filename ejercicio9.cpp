#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "funciones/arquero.cpp"

using namespace std;

int main()
{
    int K;
    std::cin >> K;
    int *a = new int[K];
    int *likes = new int[K];

    for (int i = 0; i < K; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 0; i < K; i++)
    {
        std::cin >> likes[i];
    }

    std::cout << maxLikes(K, a, likes) << std::endl;
    return 0;
}