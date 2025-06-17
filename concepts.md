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
Un archivo source en C es procesado por el compilador en un total de ocho (8) fases. Sin embargo, cabe aclarar que la implementación real puede combinar estas fases o procesarlas de distintas maneras, pero el comportamiento es básicamente siempre el mismo. Estas fases son:
### Phase 1
