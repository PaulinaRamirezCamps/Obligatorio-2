# Justificación de órdenes — Obligatorio 2

## Ejercicio 6

- Justificación: Usamos un arreglo de frecuencias para contar las placas y una estrategia greedy para formar el palíndromo óptimo, priorizando los números más grandes. El orden temporal es O(N), ya que recorremos las N placas y los recorridos del arreglo de frecuencias son constantes porque su tamaño es fijo. El orden espacial es O(N), por las cadenas utilizadas para construir el resultado

## Ejercicio 7

-Justificacion: El orden temporal es O(N log N), ya que utilizamos dividir y conquistar, separando el array en dos mitades en cada llamada recursiva. En cada llamada contamos las remontadas entre ambas mitades y realizamos el merge (recorriendo como máximo N elementos). Como hay O(log N) niveles de recursión, el orden temporal total es O(N log N). El orden espacial es O(N), porque utilizamos un arreglo auxiliar de tamaño N para realizar el merge y la pila de recursión tiene O(log N), por lo que el espacio total sigue siendo O(N)


## Ejercicio 8

- Justificación: Utilizamos programación dinámica con tabulación. tabla[i][w][a][b][c][d] representa la máxima satisfacción que puede obtenerse usando los primeros i productos, con peso total w y cantidades utilizadas de las cuatro categorías a, b, c y d . El orden temporal es O(N × W × L0 × L1 × L2 × L3), ya que se recorren todas las combinaciones de producto, peso y cantidades por categoría. El orden espacial es el mismo, O(N × W × L0 × L1 × L2 × L3), debido a la matriz de estados utilizada

## Ejercicio 9

- Justificación: Utilizamos programación dinámica con memoización. memo[indice][diferencia][anterior] representa la máxima cantidad de likes que puede obtenerse desde la ronda indice, considerando la diferencia actual entre los goles de A y B y si el Pato bailó en la ronda anterior. Para cada ronda se consideran las dos decisiones posibles: no bailar, actualizando la diferencia según si el pateador de A convierte, o bailar, sumando los likes correspondiente y verificando que A no quede abajo. Cada estado se calcula una sola vez y se reutiliza en las llamadas siguientes. Existen O(K) posibles rondas, O(K) diferencias posibles y además dos estados para el baile anterior, por lo que la tabla tiene O(K²) estados y el orden temporal es O(K²). El orden espacial es O(K²) debido a la tabla de memoización

## Ejercicio 10

- Justificación: Utilizamos backtracking asignando dígitos a las letras y procesando la suma columna por columna, desde las unidades. En cada columna calculamos el total con el acarreo y descartamos la rama si el dígito obtenido no coincide con la letra correspondiente del resultado, también descartamos si sobra un dígito cuando el resultado ya no tiene más columnas. Como hay a lo sumo 10 letras distintas, el conjunto de asignaciones está acotado por 10! combinaciones. Para cada rama procesamos como máximo 10 columnas y hasta 5 sumandos, por lo que el orden temporal en el peor caso es O(10! × 10 × 5), con poda de ramas inválidas antes de completar todas las asignaciones. El orden espacial es O(1), porque usamos arreglos de tamaño fijo y la profundidad de la recursión está acotada por la cantidad de letras y columnas (ambas como máximo 10)