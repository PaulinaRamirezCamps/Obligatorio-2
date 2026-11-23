# Justificación de órdenes — Obligatorio 2

## Ejercicio 6

- Justificación: Usamos un arreglo de frecuencias para contar las placas y una estrategia greedy para formar el palíndromo óptimo, priorizando los números más grandes. El orden temporal es O(N), ya que recorremos las N placas y los recorridos del arreglo de frecuencias son constantes porque su tamaño es fijo. El orden espacial es O(N), por las cadenas utilizadas para construir el resultado

## Ejercicio 7

-Justificacion: El orden temporal es O(N log N), ya que utilizamos dividir y conquistar, separando el array en dos mitades en cada llamada recursiva. En cada llamada contamos las remontadas entre ambas mitades y realizamos el merge (recorriendo como máximo N elementos). Como hay O(log N) niveles de recursión, el orden temporal total es O(N log N). El orden espacial es O(N), porque utilizamos un arreglo auxiliar de tamaño N para realizar el merge y la pila de recursión tiene O(log N), por lo que el espacio total sigue siendo O(N)



