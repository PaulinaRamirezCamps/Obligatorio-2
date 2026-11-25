#include <vector>
#include <algorithm>

int maxLikesMemo(int K, int *a, int *likes, int indice, int diferencia, int anterior, int ***memo)
{

    if (indice == K)
    {
        return 0;
    }
    if (memo[indice][diferencia][anterior] != -1)
    {
        return memo[indice][diferencia][anterior];
    }

    int op1 = maxLikesMemo(K, a, likes, indice + 1, diferencia + a[indice], 0, memo);
    int op2 = 0;
    if (diferencia + a[indice] - 1 >= 0)
    {
        int ganancia = likes[indice];
        if (anterior == 1)
            ganancia = likes[indice] / 2;
        op2 = ganancia + maxLikesMemo(K, a, likes, indice + 1, diferencia + a[indice] - 1, 1, memo);
    }

    memo[indice][diferencia][anterior] = std::max(op1, op2);
    return memo[indice][diferencia][anterior];
}

int maxLikes(int K, int *a, int *likes)
{
    int ***memo = new int **[K + 1];
    for (int i = 0; i <= K; i++)
    {
        memo[i] = new int *[K + 1];
        for (int j = 0; j <= K; j++)
        {
            memo[i][j] = new int[2];
            for (int h = 0; h < 2; h++)
            {
                memo[i][j][h] = -1;
            }
        }
    }
    int resultado = maxLikesMemo(K, a, likes, 0, 0, 0, memo);
    return resultado;
}
