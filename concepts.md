# C

## References
* [C Reference](https://cppreference.com/w/c.html)
* [C Reference Language](https://cppreference.com/w/c/language.html)

## Basic Concepts
### C Program
Un programa en C es una secuencia de archivos de texto, típicamente archivos header y source. Estos programas pasan por una *translation* para convertirse en un programa ejecutable, y este se ejecuta cuando el Sistema Operativo llama a su *main function*, a menos que el programa sea el propio SO o algún otro programa "independiente", en cuyo caso, el punto de entrada está definido en la implementación (implementaion-defined).

Hay palabras en un programa C que tienen un significado y utlidad especial, y son llamadas *keywords*. Otras, pueden ser usadas como especificadores de varios tipos. Cada identificador (aparte de las macros) es válido únicamente dentro de una parte del programa, a esto se le llama *scope* y puede pertenecer a uno de cuatro tipos de *name spaces*.

Las definiciones de funciones incluyen secuencias de *statements* y *declarations*, que a su vez, pueden incluir *expressions* que especifican las operaciones computacionales a realizar por el programa. Por lo que las *declarations* y *expressions* pueden Crear, Destruir, Acceder y Manipular *objects*. Donde cada *object*, *function* y *expression* están asociados con un *type*.

### ASCII Chart
[ASCII Chart](https://cppreference.com/w/c/language/ascii.html)

### Character Sets
[Character Sets and Encodings](https://cppreference.com/w/c/language/charset.html)

### Translation
Un programa en C pasa por un total de ocho fases distintas para poder ser convertido en un programa ejecutable, este proceso es conocido coomo *translation* o *proceso de traducción*. Sin embargo, cabe aclarar que la implementación real puede combinar estas fases o procesarlas de distintas maneras, pero el resultado es básicamente el mismo siempre.
#### Phase 1
En esta primera fase, los bytes individuales del archivo source, que generalmente están codificados en UTF-8, son mapeados de acuerdo a la forma de implementación definida, a los caracteres del *source character set*. Es decir, el compilador trasforma todos los caracteres del archivo a su forma normal, o a la forma en que el compilador puede entender y trabajar con esos caracteres.

El *source character set* o *conjunto de caracteres básico* es un conjunto de caracteres de múltiples bytes, que contiene un total de 96 caracteres:
* 5 caracteres de espacio en blanco (space, horizontal tab, vertical tab, form feed, new-line)
* 10 carateres de dígitos (0 - 9)
* 52 letras, incluyendo mayúsculas y minúsculas (a - z)
* 29 caracteres especiales o de puntuación (_ { } [ ] # ( ) < > % : ; . ? * + - / ^ & | ~ ! = , \ " ')

#### Phase 2
Esta segunda fase detecta la presencia de backslashes (\) al final de las líneas, pues generalmente son usadas para definir una sola línea en varias líneas físicas. Por lo tanto, el compilador las elimina y une todas esas líneas en una única línea lógica. Si un archivo source que no está vacío no termina con el caracter new-line en esta fase, se dice que el comportamiento es indefinido.

#### Phase 3
En esta tercera fase, el compilador convierte el código en *preprocessing tokens* válidos que puede entender, y por lo tanto identificar qué es cada parte del código, como headers, identifiers, integer constants, float constants, character constants, string literals, operators, etc. Además, los comentarios son reemplazados por un caracter de espacio.

Para la generación de los *preprocessing tokens*, se sigue la regla de *maximal munch*, que básicamente busca tomar la secuecia más larga de caracteres (mayor cantidad de caracteres) que puedan formar un token válido.

#### Phase 4
En la cuarta fase el *proprocessor* es ejecutado, el cual, se encarga de ejecutar todas aquellas partes del código que inician con el caracter "#", como #include o #define. Entonces, cada archivo que es introducido al archivo source, pasa por todas las fases anteriores (Phase 1 - 4) recursivamente, lo que asegura que todos los archivos a usar tengan el formato correcto y el compilador puede trabajar con ellos. Al final de esta fase, todo el código ejectutado por el *preprocessor* es eliminado del archivo source, pues es reemplazado por el resultado correspondiente.

#### Phase 5
En esta fase, todos los caracteres de escape se encuentran representados por caracteres del *source character set*, por lo que son convertidos a caracteres de *execution character set*. Es decir, que todos aquellos caracteres de escape como \n, son convertidos a caracteres que el compilador realmente puede interpretar por lo que son.

#### Phase 6
Esta fase es sencilla, y básicamente se encarga de contatenar *string literals* para convertir múltiples strings en un solo string.

#### Phase 7
Esta es la fase de compilación, donde los tokens son analizados en cuanto a su sintaxis (¿está bien escrito?), y a su semántica (¿tiene sentido?) como una unidad de traducción o *tranlation unit*. Se revisa que las variables estén declaradas antes de ser usadas, que los tipos de datos existan, se realizan optimizaciones, etc. Todo esto para que el compilador pueda convertir todo el código en código máquina o en código objeto, que la computadora puede entender pero todavía no lo puede ejecutar.

#### Phase 8
En esta última fase, se da el proceso de *linking*, donde las *translation units*, obtenidas de la fase anterior, y las librerías necesitadas son colectadas en una imagen de programa que contiene la información necesitada para su ejecución. Es decir, que se arma el programa ejecutable final que contine toda la información necesaria para que funcione y finalmente la computadora pueda ejecutar dicho programa.

### Punctuation
Hay un total de 47 símbolos de puntuación en C, y algunos pueden tener múltiples funcionalidades:
#### Delimitation and Grouping
* {} - Delimitan bloques de código, listas de inicializadores, y definiciones de estructuras, uniones y enumeraciones.
* [] - Actúan como operador de subscripción para arrays, forman parte de declaradores de arrays, y se usan para designadores en inicialización.
* () - Agrupan expresiones, delimitan llamadas a funciones, encierran operandos, rodean listas de parámetros, y aparecen en estructuras de control.
#### Preprocessing
* #- Introduce directivas del preprocesador. También funciona como operador de "stringificación" que convierte argumentos de macro en cadenas de texto.
* ##- Es el operador de concatenación de tokens del preprocesador, que une elementos adyacentes para formar un solo token.
#### Control and Separation
* ; - Termina sentencias y declaraciones.
* : - Aparece en el operador condicional, en etiquetas, en campos de bits.
* , - Funciona como operador secuencial y como separador en listas de declaradores, argumentos de función, inicializadores, y parámetros de macro.
#### Access and Navegation
* . - Operador de acceso a miembros de estructuras y uniones, y designadores para miembros específicos en inicialización.
* -> - Operador de acceso a miembros a través de punteros, equivalente a (*ptr).member.
* ... - Indica funciones variádicas (que aceptan número variable de argumentos) y macros variádicas.
* ? - Forma parte del operador condicional ternario.
* :: - Indica alcance de atributos y parámetros prefijados del preprocesador. 
#### Arithmetic and Logical
* +, -, *, /, % - Funcionan como operadores aritméticos básicos, donde * también actúa como operador de indirección para punteros y como indicador de puntero en declaraciones.
* ~ - Operador de complemento bit a bit (NOT).
* ! - Operador de negación lógica (NOT lógico).
#### Bit-to-Bit and Logical
* ^ - Operador XOR bit a bit.
* & - Operador AND bit a bit y operador de dirección (para obtener la dirección de una variable).
* | - Operador OR bit a bit.
* && - Operador AND lógico.
* || - Operador OR lógico.
* <<, >> - Operadores de desplazamiento de bits a la izquierda y derecha.
#### Assignation
* = - Operador de asignación simple, también usado en inicialización y definición de constantes de enumeración.
* +=, -=, *=, /=, %=, ^=, &=, |=, <<=, >>= combinan una operación aritmética o bit a bit con asignación.
#### Comparation
* <, >, <=, >= - Operadores relacionales para comparaciones numéricas. Los símbolos <, > también delimitan nombres de cabecera en directivas del preprocesador.
* ==, != - Operadores de igualdad y desigualdad.
#### Increment-Decrement
* ++, -- - Operadores de incremento y decremento, que pueden usarse como prefijo o sufijo.

### Identifier
Un *identifier* es una secuencia arbitraria larga de dígitos, guiones bajos, letras, etc. Para que sea válido debe empezar con un caracter que no sea numérico o que no sea Unicode. Además, los identificadores son *case-sensitive*.

Cada identificador, aparte de los usados en macros, tienen un *scope*, pertenecen a un *name space* y pueden tener *linkage*. Incluso, el mismo identificador puede ser usado para denotar diferentes entidades en distintos puntos del programa, o en el mismo punto pero en name spaces distintos.

Cabe mencionar que existen identificadores reservados y no deben ser declarados en el programa, pues de hacerlo surgiría comportamiento inesperado. Los siguientes son los *reserved identifiers*:
* Identificadores que son *keywords*.
* Identificadores externos que empiezan con guion bajo.
* Identificadores que empiezan con guion bajo y son seguidos por una letra mayúscula u otro guion bajo.
* Identificadores definidos por la *standard library* o por el propio lenguaje.

En cuanto a los límites de longitud de un identificador, con la tecnología actual no existe un límite especificado. Sin embargo, los compiladores y linkers iniciales tenían límites bien definidos.

### Scope
Cada identificador que aparece en un programa de C es visible solamente en alguna porción discontigua del código, a lo que se le llama *scope*. Entonces, C tiene cuatro diferentes tipos de *scope*, excluyendo sus combinaciones:
* Block Scope: Este es el tipo de scope más común y restrictivo. Cualquier identificador declarado dentro de una sentencia compuesta (entre llaves), incluyendo cuerpos de funciones, o en expresiones dentro de sentencias if, switch, for, while, o do-while, tiene alcance de bloque. Su vida útil comienza exactamente en el punto donde lo declaras y termina cuando se cierra el bloque correspondiente.
* File Scope: Este representa el alcance más amplio para variables regulares. El alcance de cualquier identificador declarado fuera de cualquier bloque o lista de parámetros comienza en el punto de declaración y termina al final de la unidad de traducción. También, es conocido como variales globales.
* Function Scope: Este es un tipo muy específico que se aplica exclusivamente a las etiquetas (labels) usadas con goto. Una etiqueta declarada dentro de una función está en alcance en todas partes dentro de esa función, en todos los bloques anidados, antes y después de su propia declaración.
* Function Prototype Scope: Este es el más limitado de todos los scopes. El alcance de un nombre introducido en la lista de parámetros de una declaración de función que no es una definición termina al final del declarador de función.

### Lifetime
Cada objeto en C existe, tiene una dirección constante, retiene su último valor almacenado (excepto cuando el valor es indeterminado), y para VLA, retiene su tamaño durante una porción de la ejecución del programa conocida como el tiempo de vida de este objeto.

Para la mayoría de objetos, el lifetime está directamente relacionado con su *storage duration*. Para los objetos que se declaran con duración de almacenamiento automática, estática y de hilo, el tiempo de vida es igual a su duración de almacenamiento. Esto significa que:
* **Variables automáticas (locales)**: Viven desde que se declaran hasta que termina su bloque.
* **Variables estáticas**: Viven durante toda la ejecución del programa.
* **Variables de hilo**: Viven durante la vida del hilo que las creó.

Los objetos creados dinámicamente tienen reglas especiales. Para los objetos con duración de almacenamiento asignada, el tiempo de vida comienza cuando la función de asignación retorna (incluyendo el retorno de realloc) y termina cuando se llama a la función realloc o de desasignación. Estos objetos nacen con malloc(), calloc(), o realloc(), y mueren con free() o realloc(). Su lifetime está completamente bajo control propio, lo que da poder pero también responsabilidad.

C también tiene un concepto más sutil llamado "temporary lifetime" para objetos temporales. Los objetos de struct y union con miembros de array que son designados por expresiones que no son lvalue, tienen tiempo de vida temporal. Entonces, en el siguiente ejemplo, el tiempo de vida temporal comienza cuando se evalúa la expresión que se refiere a tal objeto y termina cuando termina la expresión completa contenedora o el declarador completo.
    ```C
    struct T { double a[4]; };
    struct T f(void) { return (struct T){3.15}; }
    double g1(double* x) { return *x; }

    int main(void) {
        double d = g1(f().a);  // ¿Es esto seguro?
    }
    ```

### Main Function
Cualquier programa de C hecho para ser ejecutado en un entorno hosteado (con un Sistema Operativo), debe contener la definición de una función llamada *main*, la cual, es designada como el punto de entrada para el programa. Hay dos tipos principales para su implementación:
* Cuando la función no recibe argumentos en su ejecución:
    ```C
    int main(void) { /*body*/ }
    ```
* Cuando la función sí recibe argumentos en su ejecución:
    ```C
    int main(int argc, char *argv[]) { /*body*/ }
    /* Donde:
        - "argc (argument count)" es un valor no negativo que representa el número total de argumentos pasados al programa en su ejecución.
        - "argv (argument vector)" es un puntero al primer elemento de un arreglo de punteros de tamaño argc + 1, donde el primer elemento argv[0] apunta al nombre del programa, los demás elementos apuntan a los strings que repesentan a los argumentos, y el último elemento argv[arc] es null.
    */
    ```
En cuanto al *return* de la función main, si es explícitamente usado, llama implícitamente a *exit()*, y el valor 0 o EXIT_SUCCESS indican terminación exitosa, mientras que 1 o EXIT_FAILURE indican terminación fallida. Por otro lado, *main* es llamada en el setup del programa, después de que todos los objetos con duración de almacenamiento estática hayan sido inicializados. Además, un prototipo de esta función no puede ser proporcionado por el mismo programa.
* Ejemplo de uso:
    ```C
    int main(int argc, char *argv[])
    {
        printf("argc = %d\n", argc);
        for (int ndx = 0; ndx != argc; ++ndx)
            printf("argv[%d] --> %s\n", ndx, argv[ndx]);
        printf("argv[argc] = %p\n", (void*)argv[argc]);
    }
    ```

### Declarations
Una *declaration* es un *construct* que introduce uno o más identificadores al programa, y especifica su significado y propiedades. Estas pueden aparecer en cualquier *scope*, y consisten de dos partes obligatorias:
* *specifiers-and-qualifiers* - Especifican el tipo del declarador, por ejemplo: void, int, struct, enum, typeof etc. Se separan mediante espacios en blanco.
* *declarators-and-initializers* - Indican el nombre de la declaración, y pueden ser acompañados por inicializadores, es decir, los valores asignados al declarador, por ejemplo: number = 5;. Se separan mediante comas.
* Ejemplo:
    ```C
    int a, *b = NULL;
    /* Donde:
        - "int" es el "type specifier"
        - "a" y "*b" son los "declarator"
        - "NULL" es el "initializer" para ambos declarators.
    */
    ```

### Definitions
Una *definition* es una declaración que provee toda la información sobre los identificadores que declara. Por ejemplo, una declaración de una función que incluye en cuerpo de dicha función, es una definición; una declaración de un objeto que aloja memoria, es una definición, similar con structs y unions.
* Ejemplo:
    * int foo(double x) { return x; }
    * int n = 10;
    * struct X { int m; }

