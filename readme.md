# Proyecto: Steal a Brainrot!
Steal a Brainrot! es un juego de Roblox que consiste en coleccionar y robar diferentes personajes catalogados como "Brainrot", este juego tiene un sistema de rarezas (Común, Raro, Épico, Legendario, BrainrotGOD y Secreto) y costos en cuestión a los personajes que existen, por lo que es más valioso un Brainrot Secreto a un Brainrot BrainrotGod. Usando los diferentes temas que hemos aprendido durante el semestre, este proyecto se designa a facilitar la busqueda y catalogo de los Brainrots que el usuario tiene en el juego, mejorando el ordenamiento en su base dependiendo si quiere ordenarlos por nombre, costo o rareza.

# Link de problemas:
https://drive.google.com/drive/folders/1fBlEFJQTMsG1tIqIwnGjqTxsechl54-m?usp=sharing

## Descripción del avance 1
En este avance se entrega un primer prototipo de consola que:
+ Pide al usuario diferentes brainrots que añadir a vectores como Nombre, Rareza y Costo.
+ Permite consultar arreglos con datos ya ingresados por el usuario.
+ Implementa un algoritmo de ordenamiento: Bubble Sort.

Permite elegir criterios de orden:
+ (Bubble Sort) Costo (Menor a Mayor).
+ (Insertion Sort) Rareza (Menor a Mayor) PENDIENTE.
+ (Merge Sort) Nombre (Alfabético) PENDIENTE.

## Descripción del avance 2
En este avance se entrega un segundo prototipo de consola que (a diferencia del primero):
+ El usuario decide si añade sus propios brainrots o toma un banco de personajes ya establecido (mediante un csv).
+ Permite consultar arreglos con datos ya ingresados por el usuario.
+ Implementa un mejor algoritmo de ordenamiento (basados en el analisis de complejidad) que Bubble Sort: Merge Sort.
+ Implementa una estructura de datos Stack para poder eliminar/consultar el ultimo personaje añadido (el que se queda en top).

### Cambios sobre el primer avance
1. Cambié mi algoritmo de ordenamiento de Bubble Sort (el único que había programado) porque su análisis de complejidad no lo hacia eficiente al hacer tanto recorrimientos, proponiendo a Merge Sort por su complejidad final en el peor, promedio y mejor caso en los ordenamientos de Costo, Rareza y Nombre.
2. Ahora ya se puede elegir una lista de personajes/brainrots ya existentes para no tener que estar metiendo personaje por personaje cuando se quiera probar una función del programa mediante un CSV implementando el uso de archivos externos.

## Descripción del avance 3
En este avance, se implementó un mecanismo de persistencia de datos mediante la escritura en archivos, permitiendo que el inventario de personajes Brainrot pueda conservarse entre sesiones. Este mecanismo fue desarrollado a través del archivo header "CsvLoader.h", la cual aparte de cargar los datos en la sesión del programa, permite sobreescribirlos con los cambios hechos en este mismo, se puede ingresar cualquier archivo de tipo .CSV que siga las bases del que se proporciona como "PersonajesBrainrot.csv".

El sistema está diseñado de manera que los cambios en el inventario (como agregar y ordenar personajes) no se reflejan de inmediato, solo cuando el usuario explicitamente selecciona la opción de sobrescritura en el menú principal, permitiendo un mayor control y eficiencia en la gestión de datos.

Además, en este avance se realizó un análisis de complejidad de todas las funciones restantes del proyecto, este análisis nos permite identificar y evaluar la eficiencia de cada componente, determinando así la complejidad temporal final del proyecto, este estudio asegura que el sistema es escalable y tiene un rendimiento óptimo incluso si se llegan a tener muchos personajes en el inventario.

El avance también incluye el manejo de errores para asegurar que el archivo se abra correctamente antes de intentar escribir en él, evitando problemas como perdida de datos o que incluso el archivo al que vamos a sobrescribir/cargar datos existe.

### Cambios sobre el segundo avance
1. Cambie "Stack.h" por "DList.h" para tener una función de mejor uso a solo eliminar y consultar último personaje.
2. Ahora "CsvLoader.h" puede cargar y sobrescribir archivos de tipo CSV y no solo cargarlos como lo hacia en el anterior avance (y a medias, porque no dejaba seguir usando el sistema).
3. Todos los componentes ahora tienen un análisis de complejidad.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -std=c++11 -o tercer_avance` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./tercer_avance` 

## Descripción de las entradas del avance de proyecto
Para el avance de proyecto 3, se necesita ingresar nombres de personajes brainrot (ejemplo: Tralalero Tralala, Orcalero Orcala, Lirili Larila, Cappuchino Assasino, etc.), su rareza (ejemplo: Common, Rare, Epic, Ñegendary, BrainrotGod, Secret) y costo (varía, puedes poner cualquier numero que NO sea negativo), O en su defecto, elegir una lista de personajes brainrot por default para facilitar la prueba de este mismo programa. Si no se hace esto al inicio del programa, no te dejará hacer Merge Sort ni utilizar la Double Linked List ni consultar los arreglos (los datos permitidos se los hará saber el programa). Al ser personajes creados con IA, en un futuro pueden existir muchisimos más personajes que en el proyecto no se agregan (debido a la gran cantidad, por lo que dejamos al usuario agregar los que el tiene). SE RECOMIENDA AGREGAR MÁS DE 2 PERSONAJES, SI SON 2 PERSONAJES NO SE PODRÁ OBSERVAR EL DESEMPEÑO TOTAL DE LOS ALGORITMOS DE ORDENAMIENTO NI ESTRUCTURAS DE DATOS.

## Descripción de las salidas del avance de proyecto
Al terminar de ejecutar el avance, se puede obtener:
+ Los arreglos sin ordenar.
+ Los arreglos ordenados por su costo (menor a mayor) con Merge Sort.
+ Los arreglos ordenados por su rareza (menor a mayor) con Merge Sort.
+ Los arreglos ordenados por su nombre (alfábetico) con Merge Sort.
+ Un arreglo de personajes favoritos dependiendo del uso del usuario con Double Linked List.
+ El archivo CSV original o sobrescrito (según lo decida el usuario).

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
En mi proyecto, he implementado el algoritmo de ordenamiento Merge Sort en la función mergeSort. El análisis de complejidad del algoritmo es el siguiente:

Complejidad:
Tiempo: O(n log n) en mejor/promedio/peor caso (divide y combina de manera lineal con las 3 propuestas (nombre, rareza y costo)).
Espacio extra: O(n) por los arreglos temporales de merge + O(log n) de pila (domina O(n)).
Estabilidad: Sí. En empates, el orden previo se respeta. Además:
+ Costo: desempato por nombre para determinismo.
+ Rareza: uso de rarityRank + desempate por nombre.
+ Nombre: comparación alfabética (case-insensitive si activas la versión con keys minúscula).

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
1. Vector: En mi proyecto, utilicé vectores para almacenar y gestionar el inventario de personajes. A continuación explicaré donde se reflejan las diferentes operaciones del vector junto con su complejidad en los distintos casos.
a. mostrarArreglos()
Complejidad en el mejor y peor caso: O(n), el acceso a los elementos del vector implica recorrer todos los personajes e imprimirlos en consola.

b. mergeSort()
Complejidad en el mejor, promedio y peor caso: O(n log n), ordena de manera paralela los 3 vectores, dependiendo de la opción escogida, tomará "nombres", "costos" o "rarezas" como principal. Merge Sort siempre hace dos mitades recursivamente y las combina, dejando la complejidad de O(n log n).

e. capturarPersonajes()
Inserción al final con push_back, cuando el usuario ingresa nuevos personajes, insertar al final es O(1), pero la función completa es O(n) por la cantidad de personajes ingresados.

2. Double Linked List: La lista doblemente ligada es una estructura de datos lineal en la que cada nodo almacena un elemento (en mi caso, un personaje favorito con nombre, rareza y costo) y dos apuntadores, uno al nodo anterior y otro al nodo siguiente. Esto permite recorrer la lista en los dos sentidos (inicio - fin y fin - inicio) y realizar inserciones y eliminaciones una vez que se tiene la referencia del nodo. En mi proyecto la usé para manejar la lista de brainrots favoritos del usuario.

a. addFavorite()
Complejidad en el mejor, promedio y peor caso: O(1), inserta un personaje (nombre, rareza y costo) al final de la lista usando el apuntador tail, como solo ajusta los punteros prev y next del ultimo y nuevo nodo, no necesita recorrer toda la lista. Por ello la inserción siempre será O(1).

b. removeFavorite()
Complejidad en el mejor caso: O(1), en el peor caso: O(n), si el favorito a eliminar está en la cabeza, se hace un O(1) ya que se elimina en la primera comparación, sin embargo, en el caso peor y promedio es O(n) debido a la necesidad de recorrer la lista hasta encontrar el nodo a eliminar.

c. Navegación
Complejidad en el mejor, promedio y peor caso: O(1), se usan las funciones de moveToFirst, moveToLast, moveNext, movePrev, getCurrent que trabajan con el apuntador Current, todas estas funciones son sencillamente asignaciones de punteros por lo que siempre son O(1), haciendo facil de mover los favoritos de delante a atrás.

d. Recorridos
Complejidad en el mejor y peor caso: O(n), las funciones recorren la lista desde head to tail o viceversa, teniendo que pasar por cada nodo por nodo, cumpliendo con la complejidad O(n).

3. Stack: Un Stack es una estructura de datos lineal en la que el último elemento en entrar es el primero en salir (Last in, First Out).

En mi proyecto, utilicé un Stack dinámico para almacenar el inventario completo que posteriormente será sobrescrito en el archivo CSV. Esta estructura permite una manipulación eficiente cuando se necesita insertar o eliminar elementos desde el tope, además de servir como puente entre los arreglos principales y el proceso de escritura en archivo, usando una complejidad obligatoria de O(n) al tener que recorrer todos los elementos, me funciona para generarlo temporalmente y a la vez de ir ingresando personajes los voy sacando.

a. push()
Complejidad en mejor, promedio y peor caso: O(1)
La función crea un nuevo nodo que apunta al nodo anterior (topNode) y luego actualiza dicho puntero al nuevo nodo.
No importa el tamaño del Stack, la operación siempre es constante.

b. pop()
Complejidad en mejor, promedio y peor caso: O(1)
Se verifica si el Stack está vacío, y si no lo está, se elimina el nodo superior y se regresa su contenido.
La operación nunca recorre la estructura, por eso siempre es O(1).

c. toVectors()
Complejidad en el mejor y peor caso: O(n)
Con esta función recorro nodo por nodo desde el tope hasta el final del Stack para reconstruir los vectores nombres, rarezas y costos.
La complejidad es O(n) porque se debe visitar cada nodo exactamente una vez.

d. fromVectors()
Complejidad en el mejor y peor caso: O(n)
Antes de insertar, primero vacía el Stack eliminando nodo por nodo (O(n)).
Después, recorre los vectores desde el final hacia el principio para insertar con push() y conservar el orden.
Ambas operaciones son lineales, así que la complejidad total es O(n).

Esta función es fundamental para sobrescribir el CSV con el orden correcto después de aplicar Merge Sort en los vectores.

e. guardarCSV()
Complejidad en el mejor, promedio y peor caso: O(n)
La función abre el archivo CSV y recorre cada nodo del Stack escribiendo:
nombre, rareza, costo
La complejidad depende del número de registros, por lo que es lineal.

f. cargarCSV()
Complejidad en el mejor, promedio y peor caso: O(n)
Se lee el archivo línea por línea, se separan los campos, se valida la rareza y cada personaje se inserta usando push().
Cada inserción es O(1), pero el proceso debe recorrer todas las líneas del archivo, por lo que termina siendo O(n).

g. empty()
Complejidad: O(1)
Solo compara si topNode == NULL.

He desarrollado esta competencia al implementar estructuras de datos, de las cuales reconozco sus puntos fuertes y el como me pueden apoyar para resolver diferentes puntos o problemas que se pueden generar en mi programa, los vectores son ideales para operaciones de recorridos secuenciales, el stack me sirve para poder ir cargando y guardando personajes en un arreglo temporal, las listas doblemente ligadas son fundamentales para generar un sub-inventario que no necesite ser recorrido de manera total en todas sus ejecuciones. 

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
En mi proyecto he realizado un análisis de complejidad para todos los componentes principales del sistema, considerando las estructuras de datos y las operaciones que se realizan sobre ellas.

En primer lugar, analicé las operaciones sobre los vectores (nombres, rarezas, costos): accesos por índice en O(1), recorridos completos en O(n), inserciones al final en O(1) y el uso de estos vectores como base para el algoritmo de ordenamiento Merge Sort. Después, implementé la Double Linked List (DListFavoritos<Row>), identificando sus operaciones de inserción al final en O(1), eliminación por nombre en O(n), navegación (moveNext, movePrev, moveToFirst, moveToLast, getCurrent) en O(1) y recorridos completos en O(n), donde n es el número de favoritos, a la par, desarrollé un Stack (StackInventario inventario) donde cada inserción en el arreglo temporal es de O(1) pero al ser una estructura usada para sobrescribir y cargar un CSV, termina en O(n) ya que se tiene que recorrer de manera completa.

Analizando las funciones de entrada/salida de archivos:
cargarDesdeCSV(...) recorre línea por línea el archivo y agrega los personajes a los vectores, con complejidad O(n), donde n es el número de líneas válidas.
guardarEnCSV(...) recorre los vectores una sola vez para sobrescribir el CSV con el inventario actual, con complejidad O(n).

El componente más costoso del sistema es el algoritmo de ordenamiento Merge Sort (anteriormente eran 3 mergeSorts, ahora es 1 gracias al uso de los templates), utilizado en la función:
mergeSort()

Cada una de estas funciones divide recursivamente el arreglo y combina los subarreglos, obteniendo una complejidad:
Mejor caso: Θ(n log n)
Caso promedio: Θ(n log n)
Peor caso: Θ(n log n)

Al combinar todos estos resultados, la complejidad final del programa cuando se realiza una operación de ordenamiento sobre n personajes está dominada por Merge Sort, por lo que la complejidad global del sistema se resume en:
Complejidad total del programa: Θ(n log n)

Las demás operaciones (cargar/guardar CSV, mostrar inventario, gestionar favoritos) son O(n) y no superan al costo del ordenamiento.

Considero que he desarrollado esta competencia porque:

+ He identificado las operaciones clave de cada estructura (vector, stack y lista doblemente ligada) y he determinado su complejidad en mejor, peor y caso promedio cuando aplica.
+ He documentado la complejidad directamente en el código con comentarios (por ejemplo, en MergeSort.h, DList.h, StackInventario.h, CsvLoader.h y en las funciones del main.cpp), mostrando un análisis línea por línea.
+ Este desarrollo se observa tanto en la implementación del código como en la justificación escrita de la complejidad para cada módulo, concluyendo en la complejidad final del programa.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Comparando Merge Sort con otros algoritmos (como el que usé en mi avance 1, Bubble Sort, o Selection Sort, Insertion Sort y Quick Sort)  que en el peor de los casos tienen una complejidad de O(n^2). Merge Sort es más eficiente para grandes volumenes de datos (excelente en este caso, sin saber que tantos personajes tiene el usuario), también es estable lo que significa que mantiene el orden relativo de los elementos iguales después del proceso de ordenamiento (aparte de tener alineados los 3 valores de nombre, rareza y costo), cosa que comparado con un hipotetico Quick Sort, este ultimo no garantizaría ese proceso.

Esta estabilidad y orden es necesario en mi sistema por el mismo factor de utilizar valores alineados entre vectores, principalmente visible a la hora de ordenar, por ejemplo: sí se está ordenando por nombre, este mismo irá moviendose alineado con su rareza y costo.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Para este proyecto, seleccioné dos estructuras de datos fundamentales, vector y lista doblemente ligada. La decisión de utilizar ambas estructuras se tomó para abordar diferentes necesidades específicas del inventario de personajes brainrot y optimizar tanto la eficiencia como la funcionalidad.

Selección y uso del vector:
Utilicé un vector porque es una estructura dinámica y eficiente para almacenar colecciones de datos, en este caso, de manera paralela, nombres, rarezas y costos. Los vectores permiten realizar accesos directos a los elementos mediante índices en O(1), lo que es ideal para recorrer y mostrar todos los personajes del inventario de manera secuencial. El vector se utiliza principalmente en las funciones mostrarArreglos() y en capturarPersonajes() para almacenar los personajes que el usuario vaya añadiendo.
Permite recorrer los elementos rápidamente para visualizarlos en consola y es fácil de gestionarlos mediante el uso de índices.

Un problema con el uso de vectores es que no se puede mover uno libremente mediante ellos sin generar un recorrido (complejidad de O(n)), por lo que si el usuario tiene ya una selección de personajes favoritos no podrá irlos viendo uno por uno para decidir cual se va o cual se queda. Bajo este problema, decidí complementar el vector con un subarreglo de una lista doblemente ligada.

Selección y uso de la Lista Doblemente Ligada:
Incorporé una lista doblemente ligada para manejar las operaciones que no requieran de un recorrido total (O(n)) como es el caso de los vectores, por lo que el usuario tiene la opción de generar una lista doblemente ligada para ir ingresando sus personajes favoritos y ubicarlos rapidamente sin tener que recorrer necesariamente todo un arreglo (como en mostrarArreglos()), el uso de la lista doblemente ligada se puede observar en las funciones addFavorite() que es O(1) al ingresar un personaje al final de la lista, removeFavorite() que es O(1) por eliminar un nodo y modificar los punteros del anterior y siguiente.  

Las ventajas de esta estructura son:
+ La búsqueda personalizada: O(1) si solo quieres meter selectos personajes a la lista.
+ Inserción o eliminación selecta: O(1) al no tener que afectar toda la estructura con la eliminación o inserción de personaje.

El uso de vector y lista doblemente ligada le sirve mucho a mi proyecto en dado caso de necesitar tener a la mano ciertos personajes de manera rápida en una lista, a diferencia de solo usar vectores y limitarse a hacer puros recorridos de O(n), en la lista se logra optimizar la parte de solo consultar personajes selectos que el usuario estará usando constantemente.

Este desarrollo de la competencia se observa en la forma que aplico y selecciono cada estructura de datos para aprovechar sus puntos fuertes y compensar sus limitaciones. El vector es ideal para operaciones de acceso y recorrido mientras que la lista doblemente ligada es fundamental para evitar ciertos recorridos totales innecesarios que se tendrían que hacer en los vectores sin la existencia de las listas.

Selección y uso del Stack:
Añadí un stack para manejar las operaciones que requieren obligatoriamente un recorrido total (O(n)), como lo es el cargar y sobrescribir un archivo CSV, haciendo una estructura temporal que solo será utilizada para esos mismos.

Las ventajas de esta estructura son:
+ El uso momentaneo de esta: O(1) al meter un personaje y sacarlo instantaneamente de la estructura, permite no usar espacio de más en la memoria.


### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructuras correctos.
En mi proyecto he incorporado mecanismos eficientes para consultar información de las estructuras de datos utilizadas, como los vectores de nombres, rarezas y costos y la lista doblemente ligada, a continuación explicaré como se aplican estos mecanismos y garantizan la precisión de las consultas:

1. Mecanismos de consulta en Vectores: Los vectores almacenan de manera separada los nombres, rarezas y costos de los personajes ingresados al inventario, la consulta del contenido de los inventarios se realiza mediante el acceso secuencial a sus elementos, es decir, se recorren uno a uno los datos de cada vector paralelamente para listar todos los datos en una salida clara para el usuario.
La complejidad del recorrido en mis vectores es de O(n), siendo n el número de personajes, mientras que la complejidad de acceso a mis datos es de O(1) tomando en cuenta los accesos por índice (nombres[i], rarezas[i], costos[i]), concluyendo en un recorrido eficiente aún cuando el inventario crece.

2. Mecanismos de consulta en Lista Doblemente Ligada
Además del inventario principal, el sistema cuenta con una lista doblemente ligada para manejar los brainrots favoritos del usuario, asegurando una complejidad de O(n) dependiendo del número de favoritos ingresados y O(1) en casos de movimiento y lectura de datos dentro de la lista, ya que puedes ir moviendo de siguiente y previo favorito sin necesidad de recorrer toda la lista en cada acción.

3. Validación de las consultas
En las consultas sobre la lista de favoritos también se manejan situaciones de error de forma clara:

Si el usuario intenta mostrar o navegar favoritos cuando la lista está vacía:

if (favoritos.empty()) {
    cout << "No hay favoritos.\n";
}

Si se intentan movimientos más allá del primer o último elemento (moveNext en el último, movePrev en el primero), se notifica al usuario:

cout << "Ya estás en el último favorito.\n";

o

cout << "Ya estás en el primer favorito.\n";

Esto asegura que las consultas sean seguras, manejando correctamente los límites de la estructura, teniendo una complejidad de O(1) al no permitir que el usuario tenga que hacer más acciones para notificar que hay un error.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
Creé un archivo CSV en excel para no crear una lista de personajes directa en el main.cpp y limpiar codigo que se puede mover externamente, de igual manera, se puede integrar un CSV externo que siga los estándares del que viene incluido en el proyecto para que el sistema sea escalable y no tenga que recurrir a un solo archivo CSV, esta funcionalidad se encuentra en la función cargarDesdeCSV.
Lectura de archivos:
+ Entrada desde CSV con encabezados (Nombre,Rareza,Costo).
+ Admite nombres con comillas y comas.
+ Validación de rarezas contra catálogo y sanitización de costo (no negativo).
+ Complejidad total: O(n) en el número de filas.
+ Integración directa al menú, con feedback de registros agregados.

### Implementa mecanismos de escritura de archivos para guardar los datos de las estructuras de manera correcta
En mi sistema existe una opción de sobrescribir un CSV nuevo o ya existente con los datos que existan o ya se hayan modificado en el programa, esta funcionalidad se encuentra en la función guardarEnCSV.
Guardar datos en archivos CSV mediante Stack:
+ Guarda en CSV con encabezados (Nombre, Rareza, Costo).
+ Complejidad total: O(n) por el uso del Stack y su recorrido completo final.
+ Integración directa, con feedback de acción completada.
