
#include <vector>
#include <algorithm>

int asado(int N, int W, int *L, int *p, int *s, int *cat)
{
    int A = L[0] + 1;
    int B = L[1] + 1;
    int C = L[2] + 1;
    int D = L[3] + 1;

    std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>> tabla(
        N + 1,
        std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>(
            W + 1,
            std::vector<std::vector<std::vector<std::vector<int>>>>(
                A,
                std::vector<std::vector<std::vector<int>>>(
                    B,
                    std::vector<std::vector<int>>(
                        C,
                        std::vector<int>(D, 0))))));

    for (int i = 1; i <= N; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            for (int a = 0; a < A; a++)
            {
                for (int b = 0; b < B; b++)
                {
                    for (int c = 0; c < C; c++)
                    {
                        for (int d = 0; d < D; d++)
                        {
                            int mejor = tabla[i - 1][w][a][b][c][d];

                            int a2 = a;
                            int b2 = b;
                            int c2 = c;
                            int d2 = d;

                            if (cat[i] == 0)
                            {
                                a2--;
                            }
                            if (cat[i] == 1)
                            {
                                b2--;
                            }
                            if (cat[i] == 2)
                            {
                                c2--;
                            }
                            if (cat[i] == 3)
                            {
                                d2--;
                            }
                            if (p[i] <= w && a2 >= 0 && b2 >= 0 && c2 >= 0 && d2 >= 0)
                            {
                                int candidato = tabla[i - 1][w - p[i]][a2][b2][c2][d2] + s[i];
                                mejor = std::max(mejor, candidato);
                            }
                            tabla[i][w][a][b][c][d] = mejor;
                        }
                    }
                }
            }
        }
    }

    return tabla[N][W][L[0]][L[1]][L[2]][L[3]];
}
