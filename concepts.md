# C

## C Conceptos Básicos
### Programa C
Un programa en C es una secuencia de archivos de texto, típicamente archivos header y source, los cuales contienen *declarations*.

Estos programas pasan por una *translation* para convertirse en un programa ejecutable. Este se ejecuta cuando el Sistema Operativo llama a su *main function*, a menos que el programa sea el propio SO o algún otro programa "independiente", en cuyo caso, el punto de entrada está definido en la implementación (implementaion-defined).

Hay palabras en un programa C que tienen un significado y utlidad especial, y son llamadas *keywords*. Otras, pueden ser usadas como identificadores.
Cada identificador (aparte de las macros) es válido únicamente dentro de una parte del programa, llamada *scope* que pertenece a uno de cuatro tipo de *name spaces*

Las definitions de functions incluyen secuencias de *statements* y *declarations*, que a su vez, pueden incluir *expressions* que especifican las operaciones computacionales a realizar por el programa.

Las *declarations* y *expressions* pueden Crear, Destruir, Acceder y Manipular *objects*. Donde cada *object*, *function* y *expression* están asociados con un *type*.

### Declarations
Una *declaration* es un *construct* que introduce uno o más identificadores al programa, y especifica su significado y propiedades. Estas pueden aparecer en cualquier *scope*, y consisten de dos partes obligatorias:
* *specifiers-and-qualifiers* - Especifican el tipo del declarador, por ejemplo: void, int, struct, enum, typeof etc. Se separan mediante espacios en blanco.
* *declarators-and-initializers* - Indican básicamente el nombre de la declaración, y pueden ser acompañados por inicializadores, es decir, los valores asignados al declarador, por ejemplo: number = 5; .Se separan mediante comas.
* Ejemplo:
    * int a, *b = NULL;
    * Donde "int" es el "type specifier", "a" y "*b" son los "declarator", y "NULL" es el "initializer" para ambos declarators.

### Definitions
Una *definition* es una declaración que provee toda la información sobre los identificadores que declara. Por ejemplo, una declaración de una función que incluye en cuerpo de dicha función, es una definición; una declaración de un objeto que utiliza aloja memoria, es una definición, similar con structs y unions.
* Ejemplo:
    * int foo(double x) { return x; }
    * int n = 10;
    * struct X { int m; }

## Translation
Un programa en C pasa por un total de ocho fases distintas para poder ser convertido en un programa ejecutable, este proceso es conocido coomo *translation* o *proceso de traducción*. Sin embargo, cabe aclarar que la implementación real puede combinar estas fases o procesarlas de distintas maneras, pero el comportamiento es básicamente siempre el mismo.
### Phase 1
En esta primera fase, los bytes individuales del archivo source, que generalmente están codificados en UTF-8, son mapeados de acuerdo a la forma de implementación definida, a los caracteres del *source character set*. Es decir, el compilador trasforma todos los caracteres del archivo a su forma normal, o a la forma en que el compilador puede entender y trabajar con esos caracteres.
El *source character set* o *conjunto de caracteres básico* es un conjunto de caracteres de múltiples bytes, que contiene un total de 96 caracteres:
* 5 caracteres de espacio en blanco (space, horizontal tab, vertical tab, form feed, new-line)
* 10 carateres de dígitos (0 - 9)
* 52 letras, incluyendo mayúsculas y minúsculas (a - z)
* 29 caracteres especiales o de puntuación (_ { } [ ] # ( ) < > % : ; . ? * + - / ^ & | ~ ! = , \ " ')

### Phase 2
Esta segunda fase detecta la presencia de backslashes (\) al final de las líneas, pues generalmente son usadas para definir una sola línea en varias líneas físicas. Por lo tanto, el compilador las elimina y une todas esas líneas en una única línea lógica.
Si un archivo source que no está vacío no termina con el caracter new-line en esta fase, se dice que el comportamiento es indefinido.

### Phase 3
En esta tercera fase, el compilador convierte el código en *preprocessing tokens* válidos que puede entender, y por lo tanto identificar qué es cada parte del código, como headers, identifiers, integer constants, float constants, character constants, string literals, operators, etc. Además, los comentarios son reemplazados por un caracter de espacio.
Para la generación de los *preprocessing tokens*, se sigue la regla de *maximal munch*, que básicamente busca tomar la secuecia más larga de caracteres (mayor cantidad de caracteres) que puedan formar un token válido.

### Phase 4
En la cuarta fase el *proprocessor* es ejecutado, el cual, se encarga de ejecutar todas aquellas partes del código que inician con el caracter "#", como #include o #define. Entonces, cada archivo que es introducido al archivo source, pasa por todas las fases anteriores (Phase 1 - 4) recursivamente, lo que asegura que todos los archivos a usar tengan el formato correcto y el compilador puede trabajar con ellos.
Al final de esta fase, todo el código ejectutado por el *preprocessor* es eliminado el archivo source, pues es reemplazado por el resultado correspondiente.

### Phase 5
En esta fase, todos los caracteres de escape se encuentran representados por caracteres del *source character set*, por lo que son convertidos a caracteres de *execution character set*. Es decir, que son todos aquellos caracteres de escape como (\n), son convertidos a caracteres que el compilador realmente puede interpretar por lo que son.

### Phase 6
Esta fase es sencilla, y básicamente se encarga de contatenar *string literals* para convertir múltiples strings en un solo string.

### Phase 7
Esta es la fase de compilación, donde los tokens son analizados en cuanto a su sintaxis (¿está bien escrito?), y a su semántica (¿tiene sentido?) como una unidad de traducción o *tranlation unit*.
Se revisa que las variables estén declaradas antes de ser usadas, que los tipos de datos existan, se realizan optimizaciones, etc. Todo esto para que el compilador pueda convertir todo el código en código máquina o en código objeto, que la computadora puede entender pero todavía no lo puede ejecutar.

### Phase 8
En esta última fase, se da el proceso de *linking*, donde las *translation units*, obtenidas de la fase anterior, y las librerías necesitadas son colectadas en una imagen de programa que contiene la información necesitada para su ejecución. Es decir, que se arma el programa ejecutable final que contine toda la información necesaria para que funcione y finalmente la computadora pueda ejecutar dicho programa.
