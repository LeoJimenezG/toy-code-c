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
Un programa en C pasa por un total de ocho fases distintas para poder ser convertido en un programa ejecutable, este proceso es conocido como `translation` o *proceso de traducción*. Sin embargo, cabe aclarar que la implementación real puede combinar estas fases o procesarlas de distintas maneras, pero el resultado es básicamente el mismo siempre.
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
En la cuarta fase el *proprocessor* es ejecutado, el cual, se encarga de ejecutar todas aquellas partes del código que inician con el caracter `#`, como `#include` o `#define`. Entonces, cada archivo que es introducido al archivo source, pasa por todas las fases anteriores (Phase 1 - 4) recursivamente, lo que asegura que todos los archivos a usar tengan el formato correcto y el compilador puede trabajar con ellos. Al final de esta fase, todo el código ejectutado por el *preprocessor* es eliminado del archivo source, pues es reemplazado por el resultado correspondiente.

#### Phase 5
En esta fase, todos los caracteres de escape se encuentran representados por caracteres del *source character set*, por lo que son convertidos a caracteres de *execution character set*. Es decir, que todos aquellos caracteres de escape como `\n`, son convertidos a caracteres que el compilador realmente puede interpretar por lo que son.

#### Phase 6
Esta fase es sencilla, y básicamente se encarga de contatenar *string literals* para convertir múltiples strings en un solo string.

#### Phase 7
Esta es la fase de compilación, donde los tokens son analizados en cuanto a su sintaxis (¿está bien escrito?), y a su semántica (¿tiene sentido?) como una unidad de traducción o *tranlation unit*. Se revisa que las variables estén declaradas antes de ser usadas, que los tipos de datos existan, se realizan optimizaciones, etc. Todo esto para que el compilador pueda convertir todo el código en código máquina o en código objeto, que la computadora puede entender pero todavía no lo puede ejecutar.

#### Phase 8
En esta última fase, se da el proceso de *linking*, donde las *translation units*, obtenidas de la fase anterior, y las librerías necesitadas son colectadas en una imagen de programa que contiene la información necesitada para su ejecución. Es decir, que se arma el programa ejecutable final que contine toda la información necesaria para que funcione y finalmente la computadora pueda ejecutar dicho programa.

### Punctuation
Hay un total de 47 símbolos de puntuación en C, y algunos pueden tener múltiples funcionalidades:
#### Delimitation and Grouping
* `{}` - Delimitan bloques de código, listas de inicializadores, y definiciones de estructuras, uniones y enumeraciones.
* `[]` - Actúan como operador de subscripción para arrays, forman parte de declaradores de arrays, y se usan para designadores en inicialización.
* `()` - Agrupan expresiones, delimitan llamadas a funciones, encierran operandos, rodean listas de parámetros, y aparecen en estructuras de control.
#### Preprocessing
* `#` - Introduce directivas del preprocesador. También funciona como operador de "stringificación" que convierte argumentos de macro en cadenas de texto.
* `##` - Es el operador de concatenación de tokens del preprocesador, que une elementos adyacentes para formar un solo token.
#### Control and Separation
* `;` - Termina sentencias y declaraciones.
* `:` - Aparece en el operador condicional, en etiquetas, en campos de bits.
* `,` - Funciona como operador secuencial y como separador en listas de declaradores, argumentos de función, inicializadores, y parámetros de macro.
#### Access and Navegation
* `.` - Operador de acceso a miembros de estructuras y uniones, y designadores para miembros específicos en inicialización.
* `->` - Operador de acceso a miembros a través de punteros, equivalente a (*ptr).member.
* `...` - Indica funciones variádicas (que aceptan número variable de argumentos) y macros variádicas.
* `?` - Forma parte del operador condicional ternario.
* `::` - Indica alcance de atributos y parámetros prefijados del preprocesador. 
#### Arithmetic and Logical
* `+`, `-`, `*`, `/`, `%` - Funcionan como operadores aritméticos básicos, donde * también actúa como operador de indirección para punteros y como indicador de puntero en declaraciones.
* `~` - Operador de complemento bit a bit (NOT).
* `!` - Operador de negación lógica (NOT lógico).
#### Bit-to-Bit and Logical
* `^` - Operador XOR bit a bit.
* `&` - Operador AND bit a bit y operador de dirección (para obtener la dirección de una variable).
* `|` - Operador OR bit a bit.
* `&&` - Operador AND lógico.
* `||` - Operador OR lógico.
* `<<`, `>>` - Operadores de desplazamiento de bits a la izquierda y derecha.
#### Assignation
* `=` - Operador de asignación simple, también usado en inicialización y definición de constantes de enumeración.
* `+=`, `-=`, `*=`, `/=`, `%=`, `^=`, `&=`, `|=`, `<<=`, `>>=` combinan una operación aritmética o bit a bit con asignación.
#### Comparation
* `<, >`, `<=`, `>=` - Operadores relacionales para comparaciones numéricas. Los símbolos <, > también delimitan nombres de cabecera en directivas del preprocesador.
* `==`, `!=` - Operadores de igualdad y desigualdad.
#### Increment-Decrement
* `++`, `--` - Operadores de incremento y decremento, que pueden usarse como prefijo o sufijo.

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
* `Block Scope`: Este es el tipo de scope más común y restrictivo. Cualquier identificador declarado dentro de una sentencia compuesta (entre llaves), incluyendo cuerpos de funciones, o en expresiones dentro de sentencias if, switch, for, while, o do-while, tiene alcance de bloque. Su vida útil comienza exactamente en el punto donde lo declaras y termina cuando se cierra el bloque correspondiente.
* `File Scope`: Este representa el alcance más amplio para variables regulares. El alcance de cualquier identificador declarado fuera de cualquier bloque o lista de parámetros comienza en el punto de declaración y termina al final de la unidad de traducción. También, es conocido como variales globales.
* `Function Scope`: Este es un tipo muy específico que se aplica exclusivamente a las etiquetas (labels) usadas con goto. Una etiqueta declarada dentro de una función está en alcance en todas partes dentro de esa función, en todos los bloques anidados, antes y después de su propia declaración.
* `Function Prototype Scope`: Este es el más limitado de todos los scopes. El alcance de un nombre introducido en la lista de parámetros de una declaración de función que no es una definición termina al final del declarador de función.

### Lifetime
Cada objeto en C existe, tiene una dirección constante, retiene su último valor almacenado (excepto cuando el valor es indeterminado), y para VLA, retiene su tamaño durante una porción de la ejecución del programa conocida como el tiempo de vida de este objeto.

Para la mayoría de objetos, el lifetime está directamente relacionado con su *storage duration*. Para los objetos que se declaran con duración de almacenamiento automática, estática y de hilo, el tiempo de vida es igual a su duración de almacenamiento. Esto significa que:
* `Variables automáticas (locales)`: Viven desde que se declaran hasta que termina su bloque.
* `Variables estáticas`: Viven durante toda la ejecución del programa.
* `Variables de hilo`: Viven durante la vida del hilo que las creó.

Los objetos creados dinámicamente tienen reglas especiales. Para los objetos con duración de almacenamiento asignada, el tiempo de vida comienza cuando la función de asignación retorna (incluyendo el retorno de realloc) y termina cuando se llama a la función realloc o de desasignación. Estos objetos nacen con `malloc()`, `calloc()`, o `realloc()`, y mueren con `free()` o `realloc()`. Su lifetime está completamente bajo control propio, lo que da poder pero también responsabilidad.

C también tiene un concepto más sutil llamado *temporary lifetime* para objetos temporales. Los objetos de struct y union con miembros de array que son designados por expresiones que no son lvalue, tienen tiempo de vida temporal. Entonces, en el siguiente ejemplo, el tiempo de vida temporal comienza cuando se evalúa la expresión que se refiere a tal objeto y termina cuando termina la expresión completa contenedora o el declarador completo.
```C
struct T { double a[4]; };
struct T f(void) { return (struct T){3.15}; }
double g1(double* x) { return *x; }
int main(void)
{
    double d = g1(f().a);  // ¿Es esto seguro?
}
```

### Lookup and Name Spaces
Cuando un identificador es localizado, se realiza una búsqueda o *lookup*, para intentar localizar la declaración que introdujo dicho identificador y que está en el scope correspondiente. Por lo tanto, C permite más de una declaración del mismo identificador en el mism scope siempre y cuando pertenezcan a diferentes categorías llamadas *name spaces*. Los siguientes son los *name spaces* disponibles y siguen la jerarquía:
1. `Label name space`: Todos los identificadores declarados como *labels*.
2. `Tag names`: Todos los identificadores declarados como nombres de *structs*, *unions*, y *enumerated types*.
3. `Member names`: Todos los identificadores declarados como miembros de *struct* o *union*.
4. `Global attribute name space`: *attribute tokens* definidos por el estándar.
5. `Non-standard attribute names`: Nombres de atributos seguidos por prefijos de atributos.
6. `Ordinary identifiers`: Son todos los otros identificadores, como de nombres de funciones, nombres de objetos, nombres de typedefs, constantes de enumeración, etc.

Ejemplo:
```C
void foo (void) { return; } // ordinary name space, file scope
struct foo {      // tag name space, file scope
    int foo;      // member name space for this struct foo, file scope
    enum bar {    // tag name space, file scope
        RED       // ordinary name space, file scope
    } bar;        // member name space for this struct foo, file scope
    struct foo* p; // OK: uses tag/file scope name "foo"
};
enum bar x; // OK: uses tag/file-scope bar
// int foo; // Error: ordinary name space foo already in scope 
//union foo { int a, b; }; // Error: tag name space foo in scope
 
int main(void)
{
    goto foo; // OK uses "foo" from label name space/function scope
}
```

### Types
Los objetos, funciones y expresiones en C tienen una propiedad llamada *type*, que determina cómo se debe interpretar el valor binario almacenado en dicho objeto o evaluado por dicha expresión. El sistema tipos de C consiste en los siguientes *fudamental types*:
#### Void type
* `void`: Representa la ausencia de tipo, utilizado principalmente para funciones que no retornan un valor o para punteros genéricos.
#### Basic type
* `char`: Tipo de caracter básico, y puede ser *signed* o *unsigned* (8 bits).
* `signed char`: Tipo de caracter con signo.
* `short`: Entero corto con signo (16 bits).
* `int`: Entero estándar con signo (32 bits).
* `long`: Entero largo con signo (64 bits).
* `long long`: Entero extra largo con signo (128 bits).
* `_Bool`: Tipo booleano (0/1 o false/true).
* `unsigned char`: Tipo de caracter sin signo.
* `unsigned short`: Entero corto sin signo (16 bits).
* `unsigned int`: Entero estándar sin signo (16-32 bits).
* `unsigned long`: Entero largo sin signo (32-64 bits).
* `unsigned long long`: Entero extra largo sin signo (64 bits).
* `float`: Punto flotante de precisión simple.
* `double`: Punto flotante de precisión doble.
* `long double`: Punto flotante de precisión extendida.
#### Derived type
* `Array`: Arrays o arreglos de elementos de un solo tipo.
* `struct`: Estructura que agrupa diferentes tipos de datos.
* `union`: Uniones que permiten almacenar diferentes tipos en la misma ubicación de memoria.
* `Function`: Tipo que representa una función.
* `Pointer`: Tipo que almacena direcciones de memoria.
* `Atomic`: Tipo usado en la programación concurrente.

Cabe mencionar que para cada uno de estos tipos pueden existir diferentes versiones dependiendo de la palabra reservada que se use o no:
* Si no se usa alguna palabra reservada, su comportamiento es normal.
* Si se usa *const* hace que el objeto sea solo de lectura.
* Si se usa *volatile* indica que el valor puede cambiar de manera impredecible.
* Si se usa *restrict* para optimizar los punteros.

### Objects and Alignment requirement
Los programas en C pueden Crear, Destruir, Acceder y Manipular objetos, donde un *object* es una región de información almacenada en el entorno de ejecución cuyo contenido puede representar el valor o valores del objeto. Todo objeto puede tener las siguientes características básicas:
* `size`: Tamaño del objeto o la cantidad de bytes que ocupa en memoria (sizeof).
* `alignment requirement`: Es un valor entero de tipo `size_t` que representa la restricción de alineación que determina en qué direcciones de memoria puede comenzar un objeto de cierto tipo. Es decir, indica el múltiplo del que debe ser una dirección de memoria para poder iniciar el almacenamiento de un objeto de un tipo específico, con la intención hacer la lectura de memoria más eficiente. Llegando al punto en que el orden de declaración de variables importa.
* `storage duration`: Se refiere al período durante el cual un espacio de memoria está reservado y disponible para un objeto. Determina cuándo el sistema asigna memoria para un objeto y cuándo esa memoria es liberada y puede ser reutilizada por el sistema para otros propósitos. En C existen cuatro categorías: automatic
* `lifetime`: Se refiere al período durante el cual el contenido de un objeto existe y es válido en un espacio de memoria dado. Comienza cuando el objeto se inicializa con un valor y termina cuando el objeto es destruido o cuando su valor deja de ser válido.
* `effective type`: Se refiere al tipo de dato que C considera que está almacenado en un espacio de memoria específico en un momento dado. Esta "etiqueta" invisible determina cómo el compilador puede optimizar el código y qué tipos de accesos a memoria son válidos según las reglas de strict aliasing.
* `value`: Es el valor asignado al objeto y depende del tipo de dicho objeto. Puede ser indeterminado.
* `identifier`: Este es el nombre que denota o identifica al objeto, y es opcional pero muy útil.

### Main Function
Cualquier programa de C hecho para ser ejecutado en un entorno hosteado (con un Sistema Operativo), debe contener la definición de una función llamada `main`, la cual, es designada como el punto de entrada para el programa. Hay dos tipos principales para su implementación:
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
En cuanto al `return` de la función main, si es explícitamente usado, llama implícitamente a `exit()`, y el valor `0` o `EXIT_SUCCESS` indican terminación exitosa, mientras que `1` o `EXIT_FAILURE` indican terminación fallida. Por otro lado, `main` es llamada en el setup del programa, después de que todos los objetos con duración de almacenamiento estática hayan sido inicializados. Además, un prototipo de esta función no puede ser proporcionado por el mismo programa.
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

### As-if rule (Observable behaviour)
Esta regla permite al compilador hacer "trampa", o realizar cualquier tipo de transformación en el código con la intención de optimizarlo, siempre y cuando no modifique el comportamiento observable del programa. Esta regla se cumple siempre y cuando se protega lo siguiente:
1. Objetos volátiles:
    * Antes C11: En cada "sequence point", los valores de objetos `volatile` deben estar estables.
    * Desde C11: Los accesos a `volatile` ocurren exactamente según la semántica escrita, sin reordenamiento
2. Archivos:
    * Al terminar el programa, los datos escritos a archivos deben ser idénticos a ejecutar el código literalmente.
3. Entrada/aalida interactiva:
    * Los prompts deben mostrarse antes de esperar entrada del usuario.
4. Entorno de punto flotante:
    * Si `#pragma STDC FENV_ACCESS` está `ON`, los cambios al entorno de punto flotante se preservan (excepciones, modos de redondeo).

Esta regla es crucial cuando se trabaja con hardware, sistemas embebidos, o cuando las optimizaciones del compilador interfieren con el comportamiento esperado. 

### Undefined behaviour
El estándar de C precisamente especifica todo el `observable behaviour` (comportamiento definido) de progras hechos en C, sin embargo, dicho estándar no espeficica para las siguientes categorías de comportamiento:
* `undefined behaviour`: En este caso no existen restricciones en el comportamiento del programa, por lo que los compiladores no están obligados a diagnosticar este comportamiento, y el programa resultante tampoco está obligado a hacer algo significativo. Es decir, que no hay un comportamiento definido para todos los casos del programa y no se sabe lo que pasará exactamente.
* `unspecified behaviour`: En este caso dos o más comportamientos son permitidos, y la implementación no está obligada a detallar los efectos de cada comportamiento. Esto significa que el resultado de cada comportamiento no especificado puede ser completamente diferente y variar aunque sea el mismo porgrama.
* `implementation-denifed behaviour`: Este es un caso donde se da comportamiento no especificado pero donde el documento donde se encuentran las declaraciones es el que define las decisiones que se van a tomar, y por lo tanto, el resultado que se va a obtener.
* `locale-specific behaviour`: Este es un caso donde se da un comportamiento definido por la implementación donde el comportamiento depende en el `currently chosen locale` (locale es básicamente la forma de implementar y tomar decisiones).

### Memory model
El modelo de memoria define la semántica (significado) del uso de la memoria de la computadora, como herramienta para la máquina abstracta de C. En este contexto, el almacenamiento de memoria o memoria disponible para un programa de C es una o más secuencias de `bytes` contiguos, donde cada `byte` tiene una dirección de memoria única.

Por otro lado, un `byte` es la unidad de memoria más pequeña que puede tener una dirección, y son lo suficientemente largos para representar cualquier miembro del *basic character set*. C soporta bytes de 8 o más bits.

## C Keywords
[C Keywords](https://cppreference.com/w/c/keyword.html)

## Preprocessor
El preprocesador es ejecutado en la fase 4 del proceso de traducción, por lo que sucede antes de la compilación. El resultado del preprocesador es un **único archivo**, el cual es pasado al compilador.

Las `preprocessor directives` o directivas del preprocesador controlan su comportamiento, y cada directiva ocupa una línea y deben seguir un cierto formato:
* Primero, va el caracter `#`.
* Luego, el instrucción del preprocesador (`define`, `include`, etc.).
* Argumentos de la instrucción.
* Salto de línea.

Por otro lado, el preprocesador tiene las siguientes `capabilities` o capacidades:
* Condicionalmente compilar partes del archivo base.
* Reemplazar macros en texto.
* Incluir otros archivos.
* Arrojar errores o advertencias.

### Conditional directives
El preprocesador soporta compilación condicional de partes del archivo principal. Este comportamiento es controlado por las siguientes directivas:
* `#if`
* `#else`
* `#elif`
* `#ifdef`
* `#ifndef`
* `#elifdef`
* `#elifndef`
* `#endif`

El bloque de preprocesamiento condicional se estructura de la siguiente manera:
1. Inicia con una directiva como: `#if`, `#ifdef`, or `#ifndef`.
2. Luego, incluye cualquier cantidad de directivas adicionales como: `#elif`, `#elifdef`, or `#elifndef`.
3. Después, opcionalmente incluye como máximo una directiva `#else`.
4. Finalmente, el bloque termina con la directiva `#endif`.

Cualquier bloque de preprocesamiento condicional, ya sean bloques internos o no, son procesados individualmente, y las directivas usadas controlan completamente el comportamiento. Funcionan básicamente como los *if* tradicionales pero para el preprocesador.

Además, es importante tener en cuenta que las directivas solo pueden y deben usar `constants` o `identifiers`. En el caso de las constantes no hay problema en cuanto a su declaración, pues son globales, pero para los identificadores, deben ser definidos usando `#define` para que las directivas condicionales las puedan usar.

### Replacement directives
El preprocesador puede realizar reemplazo de macros, ya sea reemplazo por texto simple o reemplazo en forma de función. Las siguientes directivas son usadas para esto:
* `define`
* `undef`

En este contexto, una macro es una definición de texto, básicamente un identificador, que el preprocesador sustituye por algún valor definido o por alguna función también definida. Ejemplos:
* Text macro: El preprocesador reemplaza el identificador por el valor asignado, por lo que no ocupa memoria.
    ```C
    #define PI 3.14159
    #define MAX_SIZE 100
    ```
* Function-like macro: Igualmente, el preprocesador únicamente reemplaza el identificador y sus parámetros por la evaluación que se realiza dentro de la macro. Para este tipo de macros, existen dos operadores muy útiles, `#` para convertir a string y `##` para concatenar.
    ```C
    #define MAX(a, b) ((a) > (b) ? (a) : (b))
    #define FUNCTION(name, a) int func_##name(int x) { return (a) * x; }
    ```

### Inclusion directives
En esta categoría solo existe la directiva `#include`, que básicamente incluye otro archivo con código dentro del archivo donde se está usando dicha directiva. Esta inclusión sucede inmediatamente en la siguiente línea de la directiva.

Existen dos formas de utilizar esta directiva, dependiendo completamente de la sintáxis:
* `""`: Esta sintáxis obliga al preprocesador a buscar los archivos en el directorio actual, y si no los encuentra, los busca en el sistema.
    ```C
    #include "my_header_file.h"
    ```
* `<>`: Esta sintáxis obliga al preprocesador a buscar los archivos en el sistema directamente, por lo que es el segundo paso si la búsqueda con la sintáxis anterior falla.
    ```C
    #include <stdio.h>
    ```

### Implementation-defined directives
El comportamiento definido por la implementación es controlado únicamente por la directiva `#pragma`. Esta directiva controla la implementación específica de un archivo que el compilador debe realizar, como deshabilitar advertencias del compilador, cambiar los requirimientos, etc., y cualquier uso de esta que no sea reconocido es ignorado.

### Informative directives
En esta categoría se tiene la directiva `#line` que sirve para cambiar la línea actual y el nombre del archivo en el preprocesador.

También, existen las directivas `#error` y `#warning`. Estas directivas muestran el error o advertencia, respectivamente, que se especifica y se renderiza el programa ignorando dicha información.

## Statements
Los *statements* o sentencias son fragmentos de cualquier programa de C que son ejecutados secuencialmente, es decir, uno tras otro siguiendo un orden. Existen cinco tipos de sentencias en C:
* `compound statements`: También conocidos como *blocks* o bloques, son secuencias de sentencias y declaraciones entre llaves `{}`, por lo que crean su propio scope y permiten agrupar múltiples sentencias. Ejemplo:
    ```C
    if (expr)
    {
        int n = 1;
        printf("%d\n", n);
    }
    ```
* `expression statements`: Estas sentencias son seguidas por `;`, incluyen asignaciones, declaraciones, definiciones y llamadas a funciones. Ejemplo:
    ```C
    printf("statement");
    ```
* `selection statements`: Las sentencias de selección eligen una única sentencia de varias basándose en el resultado de una expresión. Ejemplo:
    ```C
    if (expression) {
        // Hacer algo
    }
    else {
        // Hacer otro algo
    }
    switch (expression) {
        case 1:
            break;
        default:
            // Hacer algo
    }
    ```
* `iteration statements`: Las sentencias iterativas ejecutan repetidamente una sentencia. Ejemplo:
    ```C
    while (expression) {
        // Hacer algo
    }
    for (expression) {
        // Hacer algo
    }
    do {
        // Hacer algo
    } while (expression);
    ```
* `jump statements`: Las sentencias de salto transfieren el flujo de control incondicionalmente. Ejemplo:
    ```C
    break;
    continue;
    return;
    goto;
    ```

### If
La sentencia `if` ejecuta código condicionalmente, y se usa donde el código necesita ser ejecutado únicamente cuando alguna condición se cumpla. Ejemplo:
```C
int j = 1;
if (j > 2) {
    printf("%d > 2\n", j);
}
else {
    printf("%d < 2\n", j);
}
```

### Switch
La sentencia `switch` ejecuta código de acuerdo al valor de un argumento. Es importante notar que esta sentencia únicamente redirige el flujo de ejecución al `case` donde la expresión se cumple y continúa ejecutando secuencialmente, por lo que es importante tener el cuenta el concepto de `fall-through`. Ejemplo:
```C
int k = 2;
switch (k) {
    case 1:
        printf("Case 1\n");
        break;
    case 2:
        printf("Case 2 and");
    case 3:
        printf(" Case 3\n");
        break;
    default:
        printf("Case 0\n");
}
```

### For
La sentencia `for` ejecuta un bucle, y es un equivalente corto al bucle *while*. Cabe mencionar que se puede combinar con otras palabras clave como `break`, `continue`, `return`, etc. Ejemplo:
```C
for (int i = 0; i < 10; ++i) {
    // La primera parte se ejecuta antes de iniciar el bucle.
    // La segunda parte se ejecuta antes de cualquier iteración.
    // La tercera parte se ejecuta después de cualquier iteración.
}
```

### While
La sentencia `while` ejecuta código repetidamente hasta que el resultado de una expresión ya no secumpla o se convierta en 0, y dicho resultado se checa antes de cualquier iteración. De igual forma, se puede combinar con otras palabras clave. Ejemplo:
```C
int n = 0;
while (n < 10) {
    printf("Iteration: %d\n", n);
    ++n;
}
```

### Do-While
La sentencia `do-while` ejecuta código repetidamente hasta que el resultado de una expresión ya no se cumpla o se convierta en 0, y dicho resultado se checa después de cualquier iteración. Se puede combinar también con otras palabras clave. Ejemplo:
```C
int m = 0;
do {
    printf("Iteration: %d\n", m);
    ++m;
} while (m < 10);
```

### Continue
La sentencia `continue` provoca que el código restante después de dicha sentencia dentro de algún bucle sea ignorado, y por lo tanto, no sea ejecutado. Básicamente ignora lo que resta de una iteración sin terminar por completo el bucle.

### Break
La sentencia `break` hace que la sentencia donde es usado termine completamente, ignorando el código y/o las iteraciones restantes. Esta sentencia puede ser usada dentro de bucles o de switches.

### Goto
La sentencia `goto` transfiere el control incondicionalmente a la ubicación deseada, la cual es especificada por algún `label`. En este contexto, un label es un `identifier` seguido por `:` y tienen el mismo scope que una función. Ejemplo:
```C
int main(void)
{
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            printf("(%d;%d)\n",x,y);
            if (x + y >= 3) goto endloop;
        }
    }
endloop:; // identifier "endloop" + ":" = "endloop:";
// goto es muy útil para salir de bucles anidados.
}
```

### Return
La sentencia `return` finaliza la función donde se está utilizando y devuelve el valor especificado al lugar u objeto que llamó a dicha función.

## Expressions
Una expresión es una secuencia de operadores y operandos que especifican una tarea computacional. La evaluación de una expresión puede generar un resultado, efectos variados o designar objetos o funciones.

Los operandos de cualquier operador pueden ser otras expresiones o *primary expressions* (constantes y literales, identificadores o palabras clave y *generic selections*). Cualquier expresión que esté dentro de paréntesis también es clasificada como una primary expression, lo que garantiza que tendrá mayor precedencia que cualquier otro operador.

### Value categories
Cualquier expresión en C is caracterizada por dos propiedades independientes: un `type` y una `value category`. Por lo tanto, toda expresión pertenece a una de tres *value categories*:
* **`Lvalue expressions`**: Cualquier expresión donde su tipo de objeto es cualquiera diferente al tipo `void`, en otras palabras, aquellas que designan objetos (ubicaciones de memoria) de cualquier tip. A esta categoría también se le conoce como `left value`, pues refleja el uso de *lvalue expressions*. 
* **`Non-Lvalue expressions`**: También conocidas como `rvalues`, son aquellas expresiones que no designan objetos, es decir, que representan valores que no son almacenados en memoria, por lo que no se puede acceder o utilizar su dirección de memoria. 
* **`Function designator expressions`**: Son aquellas expresiones de tipo función que se refieren a funciones específicas. Este tipo de expresiones siempre son convertidas a punteros de categoría *non-lvalue* que apuntan a una función.

### Evaluation order
El orden de evaluación de los operandos de cualquier operador de C no está especificado (a excepción de ciertos casos). Por lo que el compilador evaluará a las expresiones en cualquier orden, y puede elegir un orden u otro incluso cuando sea la misma expresión. Además, en C no existe en concepto de evaluación *left-to-right* o *right-to-left*.

#### Evaluations
Existen dos tipos de evaluaciones realizadas por el compilador para cada una de las expresiones:
* `value computation`: Es el valor calculado que es regresado por la expresión. Puede ser un lvalue o un non-lvalue.
* `side effect`: Puede ser acceder a un objeto, modificar un objeto o archivo, o llamar a una función que realiza cualquiera de estas operaciones.
Cabe mencionar que, si no se producen efectos por la expresión o el compilador determina que el valor de la expresión no es utilizado, dicha expresión puede no ser evaluada.
#### Ordering
Las evaluaciones de expresiones que están secuenciadas (*sequenced-before*) dentro del mismo hilo, se caracterizan por ser asimétricas, transitivas y en pares. Por lo tanto, cuando se tienen expresiones secuenciadas, se sigue lo siguiente:
* Si existe un *sequence point* (garantiza que los efectos secuandarios son hechos antes) entre expresiones E1 y E2, entonces todo el procesamiento de E1 se da antes de procesar E2.
* Si la evaluación A está secuenciada antes que la evaluación B, la evaluación de A se completará antes de iniciar con la evaluación de B. Y viceversa.
* Si la evaluación A y la evaluación B no están secuenciadas y son independientes, se pueden dar dos casos:
    * La evaluación de A y de B suceden en cualquier orden y se pueden dar al mismo tiempo.
    * La evaluación A y B son secuenciadas en cualquier orden, pero una se evalúa antes que otra siempre.
#### Rules
[14 Rules](https://en.cppreference.com/w/c/language/eval_order.html#Rules)
#### Undefined behaviour
* Si el efecto secundario en un objeto está junto con otro efecto secundario del mismo objeto dentro de la misma expresión, se da un comportamiento indefinido. Ejemplo:
    ```C
    i = ++i + i++;
    i = ++i + 1;
    fnc(++i, ++i);
    ```
* Si el efecto secundario en un objeto está junto con el uso del valor del mismo objeto dentro de la misma expresión, se da un comportamiento indefinido. Ejemplo:
    ```C
    f(i, i++);
    a[i] = i++;
    ```

### Operators
[Expresssion operators](https://cppreference.com/w/c/language/operators.html#Operators)

### Operator precedence
[C Operator Precedence](https://cppreference.com/w/c/language/operator_precedence.html)

### Generic selection
La selección genérica provee una forma de elegir una de múltiples expresiones en tiempo de compilación, y se basa en un tipo de expresiones de control.

Se utiliza la sintáxis **_Generic(*controlling-expression*, *association-list*)**, donde:
* `_Generic()` es simplemente la palabra clave.
* `controlling-expression` es la expresión a controlar.
* `association-list` es la lista de asociaciones separadas por comas.

Ejemplo:
```C
// Possible implementation of the tgmath.h macro cbrt
#define cbrt(X) _Generic((X),     \
              long double: cbrtl, \
                  default: cbrt,  \
                    float: cbrtf  \
              )(X)
```

## Initialization
Una declaración de un objeto puede incluir su valor inicial mediante el proceso de `initialization`, pues el *initializer* o inicializador especifica el valor inicial almacenado en un objeto. Existen tres tipos de inicialización:
* scalar initialization
* array initialization
* struct/union initialization

Cuando un objeto no es explícitamente inicializado, **en algunos casos** se le asigna un valor automáticamente que preresenta en vacío del tipo de ese objeto. Por ejemplo, un objeto de tipo entero es inicializado con un cero unsigned, objetos de tipo flotante son inicializados con un cero positivo, etc.

### Scalar initialization
Se refiere a la inicialización de objetos de tipo escalar, es decir asignar valores iniciales a variables de tipos básicos, como enteros, flotantes, booleanos, caracteres y punteros. Existen tres tipos de sintáxis que se pueden usar:
```C
int x = 5;  // Inicialización directa.
int y = {10};  // Inicialización con llaves.
int z = {};  // Inicialización en 0 (depende del type).
```

Es importante notar que los valor correspondiente al inicializador es convertido al tipo correspondiente al objeto que se está inicializando, siempre y cuando la conversión se pueda dar. Por ejemplo:
```C
int i = 3.14;  // double se convierte en int.
float f = 5;  // int se convierte en float.
char c = 65;  // 65 se convierte en el caracter número 65 (A).
```

### Array initialization
La inicialización de arreglos se puede dar de dos formas: usando cadenas de caracteres, para el caso de un string `char s[]`; o usando listas entre llaves `{}`.

Es importante tener en cuenta que:
* Los elementos no inicializados se les da el valor de 0, dependiendo del tipo del arreglo.
* No se pueden proporcionar más inicializadores que el total de elementos de un arreglo.
* Que el tamaño de los arreglos de tamaño desconocido es determinado por el índice más alto inicializado.
* Y que los arrays estáticos (como cualquier otro valor global o estático) requiren expresiones constantes.

Ejemplos:
```C
int arr[] = {1, 2, 3};  // Tamaño automático.
int arr[5] = {1, 2, 3};  // Tamaño de 5, y los elementos restantes son igual a 0.
int arr[5] = {};  // Tamaño de 5 y todos los elementos son igual a 0.

char str[] = "hello";  // Arreglo de tamaño 5 + 1, donde el último es '\0'.
char str[5] = "hello";  // Arreglo de tamaño 5.

int arr[5] = {[0]=1, [4]=5};  // arr = {1, 0, 0, 0, 5}.

int matrix[3][2] = {
    {1, 2},
    {3, 4},
    {5, 6}
};
int matrix[3][2] = {1, 2, 3, 4, 5, 6};
```

### Struct/Union initialization
La inicialización de structses muy parecida a la inicialización de los arrays, con la diferencia de que el orden de declaración de los miembros de una struct sí influye en el momento de la inicialización. Las mismas consideraciones de los arrays aplican en las structs. Ejemplos:
```C
struct Point {int x, y;};
struct Point p = {10, 20};  // x=10, y=20
struct Point p = {.x=10, .y=20};  // x=10, y=20
struct Point p = {};  // x=0, y=0
```

En cuanto a las unions, solo es posible inicializar un miembro, y por defecto es el primer elemento a menos de que se utilicen designators.

## Declarations
Una declaración es un constructo que introduce uno o más identificadores al programa, y especifica su significado y propiedades. Estas pueden aparecer en cualquier scope, y consisten de dos partes obligatorias:
* `specifiers-and-qualifiers`: Especifican el tipo del declarador, por ejemplo: void, int, struct, enum, typeof etc. Se separan mediante espacios en blanco.
* `declarators-and-initializers`: Indican el nombre del identificador y/o información adicional sobre el tipo del objeto, y pueden ser acompañados por inicializadores. Se separan mediante comas.
* Ejemplo:
    ```C
    int a, *b = NULL;
    /* Donde:
        - "int" es el "type specifier".
        - "a" es el "identifier".
        - "*b" proporciona más información sobre el tipo.
        - "NULL" es el "initializer" para ambos declarators.
    */
    ```

### Definitions
Una definición es una declaración que provee toda la información sobre los identificadores que declara. Por ejemplo, una declaración de una función que incluye en cuerpo de dicha función, es una definición; una declaración de un objeto que aloja memoria, es una definición, similar con structs y unions.
* Ejemplo:
    ```C
    int foo(double x) { return x; } // Function definition
    int n = 10; // Variable definition
    struct X { int m; } // Struct definition
    ```

### Pointer declaration
Un puntero es un tipo de objeto que se refiere a una función o un objeto de otro tipo, incluso, puede referirse a nada mediante el uso de `NULL`. Para declarar un puntero se utilizan tres elementos fundamentales:
* El tipo al que apunta el puntero.
* El símbolo de puntero `*`.
* El identificador o nombre del puntero.

Es importante recalcar el uso del símbolo `*`, pues puede tener diferentes usos. En la declaración de un puntero, sirve para indicar que se está declarando un puntero; pero su uso fuera de una declaración sirve para indicar que se está trabajando con el valor del objeto al que el puntero hace referencia. Además, la sintáxis de la declaración de un puntero es crucial, pues la posición de los elementos influye directamente en el funcionamiento del puntero.

Ejemplos:
```C
/* ------------------------------------------------------------------------------------------------------------- */
void *pv = NULL;  // Puntero que hare referencia a nada.
/* ------------------------------------------------------------------------------------------------------------- */
int n;  // Objeto de tipo int.
int *pn = &n;  // Puntero que hace referencia a un objeto de tipo int.
*pn = 7;  // Trabaja con el valor del objeto al que el puntero hace referencia.
/* ------------------------------------------------------------------------------------------------------------- */
int a[2];  // Array de dos elementos.
int *pa = a;  // Puntero que hace referencia al primer elemento de un arreglo de tipo int.
/* ------------------------------------------------------------------------------------------------------------- */
int v() { return 37; }  // Función de tipo int que no recibe argumentos.
int (*pf1)() = v;  // Puntero que hace referencia a una función de tipo int que no recibe argumentos.
(*pf1)();  // Llamada a la función que hace referencia desreferenciando el puntero.
pf1();  // Llamada a la función que hace referencia directamente desde el propio puntero.
/* ------------------------------------------------------------------------------------------------------------- */
int f(int x) { return (x + 1) * 2; }  // Función de tipo int que recibe un int.
int (*pf2)(int) = f;  // Puntero que hace referencia a una función de tipo int que recibe un argumento de tipo int.
/* ------------------------------------------------------------------------------------------------------------- */
```

### Array declaration
Un array es un tipo de objeto que consiste de espacios de memoria alojados contiguamente que contienen objetos no vacíos de cierto tipo. Es decir, que un array es memoria contigua que almacena elementos de un tipo específico. Además, el tamaño del array nunca cambia en todo su tiempo de vida.

Existen tres tipos de arrays que se diferencían por su tamaño:
* `Arrays of constant known size`: Son aquellos arrays que su tamaño o la expresión que define su tamaño es constante y mayor que 0, y pueden ser inicializados como normalmente. Ejemplo:
    ```C
    int n[10];  // Array de 10 elementos de tipo int.
    int n[3] = {1, 2, 3};  // Array de 3 elementos de tipo int, con inicializadores.
    char s[] = "abc";  // Array de 4 elementos de tipo char, donde el último elemento es '\0'.
    ```
* `Variable-length arrays (VLA)`: Son aquellos arrays cuya expresión que define su tamaño es evaluada únicamente en tiempo de ejecución, por lo que deben tener una duración automática y no pueden ser `static`, `extern` o `global`. Además, no pueden ser usados en `struct` o en `unions` Ejemplo:
    ```C
    int x = 10;
    int a[x];  // El tamaño es determinado en tiempo de ejecución.
    ```
* `Arrays of unknown size`: Son aquellos arrays donde su tamaño o la expresión que define su tamaño es omitida, por lo que su tamaño es definido por otras características o simplemente no es definido. Ejemplo:
    ```C
    extern int x[];  // El tamaño del array es desconocido.
    int a[] = {1, 2, 3};  // Se infiere el tamaño del array por sus elementos (3).
    ```

Es importante saber que los arrays se convierten automáticamente a punteros en la mayoría de contextos (conversión array-a-puntero). En esta conversión, el nombre del array se convierte en un puntero al primer elemento, pero el array en sí mismo no es un puntero, sino un bloque contiguo de memoria.

Más ejemplos:
```C
void func1(int arr[static 10]) {
    // El uso de static garantiza que el array es de al menos 10 elementos pero no limitado a esa cantidad.
}

void func2(int a[restrict], int b[restrict]) {
    // El uso de restrict garantiza que a y b no se superponen, es decir, que no comparten los mismos espacios de memoria.
}

void func3(double a[static restrict 100], double b[static restrict 100]) {
    // El uso de static y restrict garantiza que los arreglos son de al menos 100 elementos y que no se superponen.
}

void func4(int rows, int cols, int matrix[rows][cols]) {
    // Uso de VLA (variable-length arrays) dentro de un function scope.
}

int* func5(int size) {
    int *arr = malloc(size * sizeof(int));
    return arr;  // Retorna un puntero que hace referencia al array creado dinámicamente.
}
```

### Enumerations
Un tipo enumerado es un tipo diferente cuyo valor es un valor de su tipo subyacente, que incluye los valores de constantes explícitamente nombradas, conocidas como **constantes de enumeración**. Son prácticamente parecidas a la directiva del preprocesador `#define`, pero con algunos cambios:
* Si no se especifican los valores de las constantes de enumeración, toman el valor anterior más uno (+1), donde el primer valor de cualquier constante de enumeración no especificado es 0.
* Cada constante de enumeración se convierte en una constante entera de tipo int, es decir, que se convierten en números.
* Un enum es compatible con tipos char, int y uint. Y, como son enteros, pueden usarse en conversiones implícitas y operadores aritméticos.
* Los enums son únicamente visibles en el scope donde son declarados.

Ejemplos:
```C
enum State { IDLE, RUNNING, STOPPED, ERROR };
enum State machine_state = IDLE;  // Equivale a 0.

switch (machine_state) {
    case IDLE: printf("Esperando...\n"); break;
    case RUNNING: printf("Ejecutando...\n"); break;
    case ERROR: printf("Error!\n"); break;
}

struct Machine {
    char version[5];
    enum State state;
}
```

### Storage duration
**Nota: Es importante entender que *storage duration* y *lifetime* son conceptos similares, sin embargo, el primero se refiere al tiempo en que un espacio de memoria se utiliza para cierto objeto; mientras que el segundo se refiere al valor almacenado en ese espacio de memoria reservado para dicho objeto.**
Todo objeto tiene una propiedad llamada *storage duration* o duración de almacenamiento, la cual limita el *lifetime* o tiempo de vida del valor de dicho objeto. Existen cuatro tipos de duración de almacenamiento:
* `automatic storage duration`: Este tipo hace que la duración de almacenamiento de los objetos dependan completamente del bloque donde son declarados, pues son asignados cuando se entra al bloque y desasignados cuando el bloque termina por cualquier razón. Cuando se usa recursividad para entrar a un bloque se hacen nuevas asignaciones que dependen del nuevo nivel de recursividad, y esto aplica para cualquier objeto no estático.
* `static storage duration`: Este tipo hace que la duración de almacenamiento de un objeto sea la duración de ejecución de todo el programa, es decir, que su asignación sucede una vez antes de llamar a la función main y se encuentran en la misma dirección de memoria durante todo el tiempo que el programa es ejecutado.
* `thread storage duration`: Este tipo hace que la duración de almacenamiento de los objetos dependan completamente del tiempo de ejecución del *thread* o hilo donde son usados, y su inicialización se realiza cuando el hilo empieza.
* `allocated storage duration`: Este tipo permite asignar y desasignar memoria a como sea necesario, mediante el uso de las funciones para la asignación de memoria dinámica. Es decir, que este tipo es completamente dependiente de cómo sea usado por el programador.

Ejemplo:
```C
int global_var;              // static storage duration
_Thread_local int tls_var;   // thread storage duration

void func() {
    int local_var;           // automatic storage duration
    static int static_var;   // static storage duration
    int *ptr = malloc(sizeof(int)); // allocated storage duration
}
```

### Linkage
Este concepto se refiere a la capacidad de un identificador para ser utilizado en otros scopes o niveles. En C, se reconocen los siguientes tipos de *linkages*:
* `no linkage`: En este tipo los identificadores pueden ser utilizados únicamente dentro del nivel donde se encuentran, por ejemplo, a nivel de bloque. Todos los identificadores que no especifiquen un comportamiento diferente, incluyendo parámetros de la función utilizan este tipo de linkage.
* `internal linkage`: En este tipo los identificadores pueden ser utilizados desde cualquier nivel que se encuentre en la misma unidad de traducción (archivo). Todas las variables y funciones declaradas a nivel de archivo usando `static` o `constexpr` utilizan este tipo de linkage.
* `external linkage`: En este tipo los identificadores pueden ser utiizados desde cualquier otra unidad de traducción (archivo) que pertenezca al propio programa. Todas las variables y funciones declaradas a nivel de archivo que no usan `static` o `constexpr` utilizan este tipo de linkage.

### Storage-class specifiers
Existen cuatro `storage-class specifiers`:
* `auto`: automatic storage duration.
    * Este especificador solo está permitido para objetos declarados dentro de un *block scope* sin incluir las listas de parámetros de funciones. Indica que *storage duration* es automático y no hay *linkage*.
* `register`: automatic storage duration.
    * Este especificador solo está permitido para objetos declarados dentro de un *block scope* incluyendo las listas de parámetros de funciones. Indica que *storage duration* es automático y no hay *linkage*, además, indica al optimizador que debe guardar el valor del objeto en un registro del CPU cuando sea posible, y por lo tanto, no se puede usar su dirección ni se puede convertir en puntero.
* `static`: static storage duration.
    * Este especificador está permitido para funciones y variables a nivel de bloque o archivo. Indica que *static storage duration* y hay puede haber *internal linkage* o no.
* `extern`: static storage duration.
     * Este especificador está permitido para declaraciones de funciones y objetos a nivel de bloque o archivo. Indica que *static storage duration* y hay *external linkage*.
* Extras:
    * `_Thread_local`: thread storage duration.
    * `malloc()`/`free()`: allocated storage duration.

Estos especificadores aparecen en declaraciones, y solo se puede usar uno de ellos. Usar un especificador determina dos propiedades independendientes del nombre que declaran: *storage duration* y *linkage*.

Por defecto, si no se utiliza alguno de los especificadores, se asignan automáticamente:
* `extern` para todas las funciones.
* `extern` para objetos a nivel de archivo.
* `auto` para objetos a nivel de bloque.

Ejemplo:
```C
// Nivel archivo.
int global_var;           // extern por defecto.
static int file_var;      // static + internal linkage.

// Nivel de bloque.
void func() {
    int local;            // auto por defecto.
    static int s_local;   // static + no linkage.
    register int r_var;   // register + no linkage.
}
```

### Const

### Volatile

### Restrict
