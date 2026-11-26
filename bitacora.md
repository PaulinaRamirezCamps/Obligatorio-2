# Bitácora — Obligatorio 2

## 2026-11-10 - En conjunto
- Leimos el ejercicio 6, resumimos para comprender y tener bien claro que hacer. Arrancamos con su implementación que nos resulto bastante sencilla, por lo que la terminamos hoy mismo y ya resumimos el ejercicio7

## 2026-11-12 - En conjunto
- Empezamos el ejercico 7 y lo terminamos aunque nos costo un poco mas que el anterior, al principio algunas pruebas nos fallaron pero con ayuda de chat GPT pudimos entender que cosas de nuestro codigo estaban fallando, era un pequeño detalle en el calculo de las remontadas. Ya aprovechamos e hicimos la justificacion de ordenes de ambos ejercicios

## 2026-11-17 - En conjunto 
- Leímos el enunciado del ejercicio 8 y analizamos qué decisiones y restricciones debía representar la solución.
- La principal dificultad fue definir el estado de la programación dinámica. Además de los productos y el peso máximo, debíamos controlar cuántos llevábamos de cada categoría; por eso usamos una tabla de seis dimensiones.

## 2026-11-19 - En conjunto 
- Avanzamos con la implementación del ejercicio 8 usando programación dinámica con tabulación y revisamos los estados y transiciones.
- Para no repetir productos, al evaluar si agregamos uno consultamos la capa de productos anteriores. La transición solo lo permite si respeta el peso máximo y el límite de su categoría; en cada estado comparamos incluirlo con no hacerlo.

## 2026-11-20 - En conjunto (fecha aproximada)
- Probamos la solución del ejercicio 8 con los test y corregimos detalles. En particular, revisamos que la respuesta considerara los máximos por categoría y que el peso usado funcionara como un límite, no como una obligación de llenar la heladera. Después leímos el enunciado del ejercicio 9 y empezamos a identificar la información necesaria para cada estado.

## 2026-11-23 - En conjunto (fecha aproximada)
- Implementamos y probamos el ejercicio 9 con programación dinámica y memoización. Revisamos los resultados y ajustamos detalles de la solución

## 2026-11-24 - En conjunto (fecha aproximada)
- Leímos el ejercicio 10 y analizamos las restricciones. La dificultad no era solo encontrar una asignación válida: podía haber varias y había que elegir la de menor resultado, aplicando luego los desempates por sumandos. Empezamos a plantear la búsqueda por backtracking y cómo asignar dígitos distintos a las letras.
- En vez de probar asignaciones completas y verificar la suma al final, organizamos la búsqueda por columnas, desde las unidades, llevando el acarreo. Así podemos descartar una rama apenas la cifra calculada no coincide con la letra correspondiente del resultado. También tuvimos en cuenta que las letras iniciales de palabras de más de una cifra no pueden valer cero.

## 2026-11-25 - En conjunto
- Continuamos la implementación del ejercicio 10. Como no alcanza con detenerse en la primera solución, comparamos las soluciones completas según el resultado y, si empatan, según los sumandos en orden. Agregamos además una poda: si los valores mínimos posibles con las letras ya asignadas no pueden mejorar la mejor solución encontrada, dejamos de explorar esa rama.
- Usamos una herramienta de IA como apoyo para revisar el enfoque por columnas y las podas, y contrastamos las sugerencias con las restricciones y nuestra implementación.
- Ejecutamos los test y completamos las justificaciones de órdenes y las declaraciones de autoría de los ejercicios 8, 9 y 10.
