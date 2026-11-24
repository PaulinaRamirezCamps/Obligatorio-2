#include <iostream>
#include "funciones/asado.cpp"

int main()
{
    int N, W;
    std::cin >> N >> W;

    int L[4];
    for (int i = 0; i < 4; i++)
    {
        std::cin >> L[i];
    }

    int *p = new int[N + 1];
    int *s = new int[N + 1];
    int *cat = new int[N + 1];

    for (int i = 1; i <= N; i++)
    {
        std::cin >> p[i] >> s[i] >> cat[i];
    }

    std::cout << asado(N, W, L, p, s, cat);

    return 0;
}
