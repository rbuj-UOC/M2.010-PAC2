# Enunciado
Desarrollar una aplicación, que se llamará “g_compropietarios2”, que gestiona información relativa a una pequeña comunidad de propietarios.

Esta comunidad gestiona diversas fincas, donde cada finca puede tener diversos propietarios de forma indivisa (es decir, la propiedad es compartida y no se puede dividir en fincas más pequeñas) y cada finca, además, tiene un grado de participación en los ingresos y gastos generales de la comunidad.

La información de la comunidad se describe en dos ficheros:

* el fichero de propiedades, “(año)-propiedades.txt”, que contiene:
  - la lista de propietarios (con id, nombre y email)
  - la lista de propiedades (con numfinca, nombre finca, grado de participación general en la comunidad, y lista de propietarios con su grado de participación en la finca).
* el fichero de transmisiones, “(año)-transmisiones.txt” donde se recoge la información de las transmisiones patrimoniales (por herencia, compraventa, donación, ...) que ha sufrido la comunidad durante el año en curso. Contiene:
  - una lista de propietarios que no estan en el año anterior.
  - la lista de transmisiones del año

El detalle de ambos ficheros es, por tanto:

detalle fichero (año)-propiedades:
```
.Comentario: Fichero de propiedades y propietarios del año 2010
#propietarios
idPropietario; nombre y apellidos; email
...
#propiedades
numfinca; nombre finca;participación general; propietario: participación & propietario: participación ...
```

detalle fichero (año)-transmisiones
```
.Comentario: Fichero de transmisiones del año 2011
#nuevos propietarios
idNuevoPropietario; nombre y apellidos; email
idNuevoPropietario; nombre y apellidos; email
...
#transmisiones
>idPropietarioAnterior; fecha; motivo
+datos específicos de la transmisión
numFinca; idNuevoPropietario: participación & idNuevoPropietario: participación numFinca; idNuevoPropietario: participación & idNuevoPropietario: participación >idPropietarioAnterior; fecha; motivo
+datos específicos de la transmisión
numFinca; idNuevoPropietario: participación & idNuevoPropietario: participación >idPropietarioAnterior; fecha; motivo
+datos específicos de la transmisión
numFinca; idNuevoPropietario: participación & idNuevoPropietario: participación
```

En estos ficheros, hay una serie de caracteres con significado propio:

a) el carácter “;” (punto y coma). Se utilitza como separador de campos.

b) el carácter # en el inicio de línea sirve para identificar una sección

c) el carácter . (punto) en inicio de línea indica que la línea es un comentario (la línea se ignora)

d) las líneas en blanco también se deben ignorar

e) el carácter > (mayor) en el fichero de transmisiones indica que comienza una nueva transmisión.

Esta transmisión puede afectar a una o a varias fincas (son las líneas siguientes).

Por otro lado, también hay que precisar que:
- el grado de participación se expresa en forma de fracción (“1” o “1/2” o “1/3”).
Este detalle es importante, pues las operaciones se deben implementar de la misma forma (en este caso redondear no es adecuado, pues un 0,01% de un valor de millones de euros, puede ser una cantidad significativa).
- la lista de propietarios con su participación se expresa de la forma
```
propietario: participación & propietario: participación & propietario: participación
```

Es decir, Las diversas participaciones se separan por un símbolo de ampersand ( & ) y el símbolo dos puntos (:) separa el propietario del grado de participación.
- la fecha se encuentra en formato aaaa-mm-dd, y
- los motivos habituales de transmisiones son herencia, compraventa o donación.
- si numFinca = 0, implica que la operación se aplica a TODAS sus fincas.
- la lista de Nuevos Propietarios solo se refiere a propietarios que no pertenecían a la comunidad. Si ya lo eran, se debe utilizar su código correspondiente.

Los datos específicos de la transmisión (las líneas que comienzan por +) dependerá del
motivo de ésta:

- en caso de herencia, los datos específicos son el parentesco (hijo, nieto, sobrino, hermano,
extraño, ...) y la fecha de aceptación de la herencia

El formato será:

```
+parentesco;fecha aceptación
```

- en caso de compraventa, los datos específicos son el precio pagado, y los medios de pago
(transferencia, cheque, efectivo, ...)

El formato será:

```
+precio;medio de pago
```

- en caso de donaciones, los datos específicos son el tipo de donación (puede ser simple o
con obligaciones) y en el segundo caso, la descripción de la obligación (...)

El formato será:

```
+con obligaciones;ocupante podrá quedarse mientras viva
```

## Llamar a la aplicación

La aplicación g_compropietarios es llamada con los siguientes parámetros:
```
g_compropietarios2 año_referencia
```
Ejemplo:
```
g_compropietarios 2011
```
donde el año de referencia es el año que se desea generar (se genera el fichero de propiedades antes de la reunión anual de la comunidad).

Por tanto, si el año de referencia es 2011, entonces:

```
2010-propiedades.txt + 2011-transmisiones.txt ---> 2011-propiedades.txt
```

La aplicación debe hacer los siguientes procesos de forma consecutiva:
1. Leer datos (año-propietarios.txt y año-transmisiones.txt)
2. Verificar datos participaciones, si las fracciones suman 1.
3. Generar fichero de propietarios del año en curso (año)-propietarios
> [!NOTE]  
> A partir de (año-1)-propietarios.txt y (año)-transmisiones.txt
4. Generar listado de propietarios con sus participaciones globales en la comunidad (año)-participaciones.txt
5. Generar informe de transmisiones (ordenadas por número de finca y fecha) en (año)-informe.txt

## Punto 1 (Leer datos)
Debe leer los ficheros de texto de entrada (año-1)-propietarios.txt y (año)-transmisiones.txt y cargar la información en estructuras de memoria de forma organizada (como no se sabe el número de elementos, se deberá utilizar listas dinámicas o de otras formas).

Al finalizar, debe mostrar un mensaje final en pantalla que dé un resumen de los elementos leídos:

```
Procesando año 2011...
Registros leídos:
propietarios 2010   : xxx
propiedades         : xxx
propietarios nuevos : xxx
transmisiones       : xxx
```

## Punto 2 (Verificar datos participaciones)
Corresponde a recorrer las listas de memoria creadas anteriormente, y verificar que los datos de las participaciones son correctos. Hay dos controles:

a) A nivel de comunidad: La suma de participaciones generales de cada finca debe dar 1.

b) A nivel de finca: La suma de participaciones de cada finca para todos los propietarios de ésta también debe dar 1.

Si alguno de los resultados es incorrecto, hay que mostrar en pantalla un mensaje de aviso indicando el error detectado. No obstante, esta situación no impedirá los listados posteriores.

Hay que recordar que las operaciones se deben hacer con fracciones.

## Punto 3 (Generar fichero de propietarios del año en curso)
Tiene el mismo formato que el fichero de propietarios original.

Paso previo: En el paso 1 se ha leído el fichero de propiedades, creando las listas de propietarios y de propiedades, y el fichero de transmisiones, creando dos listas nuevas: nuevos propietarios y transmisiones.

**Proceso:**

El primer paso que se deberá hacer es añadir la lista de nuevos propietarios a la lista ya existente (se añadirán al final).

El segundo paso es aplicar la lista de transmisiones. Por tanto, se debe recorrer la lista de transmisiones que se mantiene en memoria, y para cada una de las fincas de este propietario que se encuentre se debe hacer la substitución por el nuevo propietario.

Ejemplo:

La finca 5 (“Cal Pep”) , con una participación general de una 1/10 parte de la comunidad, pertenece a Juan (id=16) y a Pedro (id=17) a partes iguales (es decir, participación 1/2 ).

En la lista de propiedades, tenemos:

```
5;Cal Pep;1/10;16:1/2 & 17:1/2
```

Si Juan muere y le deja en herencia (el 10 de mayo) a sus hijas María (id=27), Marta
(id=28) y Montserrat (id=29) la finca 5 a partes iguales.

La transmisión correspondería a las siguientes líneas:

```
>16;10-05-2009;Herencia
   5; 27:1/3 & 28:1/3 & 29:1/3
```

Por tanto, la información de la finca queda:

```
5;Cal Pep;1/10;27:1/6 & 28:1/6 & 29:1/6 & 17:1/2
```

Si un mes más tarde, María vende a Marta su parte, la transmisión quedaría:

```
>27;10-06-2009;Herencia
   5; 28:1
```

y la información final de la finca queda:

```
5;Cal Pep;1/10;28:1/3 & 29:1/6 & 17:1/2
```

## Punto 4 (Generar listado de propietarios con las participaciones globales en la comunidad)
El listado generado recibirá el nombre de “(año)-participaciones.txt” y será de la forma:

```
idProp Nombre            Email                 NumFincas Part(fracc)   Part(%)
-----------------------------------------------------------------------------
 1     Juan Pi Port      jpiport@mail.com        1        1/25         4,00%
 2     Marta Pi Port     mpiport@mail.com        1        2/25         8,00%
 3     Francisco Pi Port fpiport@mail.com        1        2/25         8,00%
 4     Narcíso Mont Prim nmontprim@mail.com      1        1/9          11,11%
 5     Sandra Mont Prim  smontprim@mail.com      1        2/9          22,22%
 6     Roberto Mont Prim rmontprim@mail.com      2        4/9          44,44%
 7     Ricardo Pi Mont   rpimont@mail.com        1        1/45          2,22%
-----------------------------------------------------------------------------
 7 propietarios                           TOTAL            1           99,99%
```

La participación (en fracción) se calcula a partir de la suma de la participación de cada propietario en todas les fincas que posea (aplicando la participación general de la finca en la comunidad).

La participación en % es una representación del cálculo anterior en fracción, redondeado a 2 decimales. Como se ha comentado anteriormente, es a efectos de comprensibilidad pero sin valor legal.

> [!IMPORTANT]  
> Se ha añadido una columna adicional NumFincas respecto a la PEC1.

**Proceso**

Como paso previo, se puede recorrer la lista de propietarios, y para cada propietario, hacer una búsqueda en la lista de fincas sumando sus participaciones (en fracción). Para cada propietario, esta suma se puede guardar en memoria dentro de la lista de propietarios. Finalizados los cálculos, se puede generar el listado pasándole sólo la lista dinámica de propietarios, que ya contiene toda la información.

## Punto 5 (Generar informe de transmisiones)
El listado generado recibirá el nombre de “(año)-informe.txt” y será de la forma:

```
NF Fecha Tr.   Prop.Anterior      Prop.Nuevo        Motivo      Datos adicionales
----------------------------------------------------------------------------------------------------
 1  20.02.2011 Juan Pi Port       Ricardo Pi Mont   Herencia    Parentesco: Hijo (F.Ac: 20.05.2011)
 1  20.05.2011 Ricardo Pi Mont    Roberto Mont Prim Compraventa Precio: 100.000 EUR (Transferencia)
 1  30.12.2011 Roberto Mont Prim  Juan Mont Prim    Donación    Tipo: Simple
----------------------------------------------------------------------------------------------------
 3 transmisiones
```

Este informe contiene las siguientes columnas:

a) NF: Número de finca

b) Fecha Transmisión: La fecha efectiva de la transmisión (el segundo campo introducido en la línea de cabecera de transmisión, es decir, la que comienza por “>” ).

c) El nombre del propietario anterior (no su código)

d) El nombre del propietario nuevo (no su código)

e) El motivo de la transmisión (herencia, compraventa o donación)

f) Datos adicionales: Según el motivo de transmisión que se haya producido, esta columna contendrá:

- Si es herencia, la relación de parentesco y la fecha de aceptación de la herencia

El formato será: parentesco: xxxx ( dd.mm.aaaa )

donde xxxx corresponde al parentesco (hijo, hermano, tío, sobrino, nieto, extraño, ...) y ( dd.mm.aaaa ) la fecha de aceptación de la herencia.

- Si es compraventa, el precio pagado y los medios de pago

El formato será: precio: xxxx ( yyyy )

donde xxxx corresponde al precio, indicando también la moneda y ( yyyy ) el medio de pago (efectivo, transferencia, .... ).

- Si es donación, el tipo de donación y, si tuviera, las obligaciones pactadas El formato será: tipo: xxxx ( yyyy )

donde xxxx corresponde al tipo (simple, con carga)

y ( yyyy ) la obligación a la donación .

> [!NOTE]  
> En la columna “Datos adicionales” de este listado es donde se puede observar más fácilmente la aplicación del polimorfismo.

> [!CAUTION]
> Para simplificar se puede considerar que las entradas de datos son sintácticamente correctos.

## Observaciones finales
1. Como podéis observar, la realización de esta PEC esta concebida como evolución de la PEC anterior por lo que bastante código base puede ser común.

> [!CAUTION]
> Se puede tomar como base la solución de la PEC1 aportada por el consultor, aunque si lo preferís, se puede iniciar a partir de vuestra propia solución.

2. Como se ha indicado, se desea valorar el uso de la orientación a objetos y la aplicación de sus propiedades. En concreto, SE DEBE aplicar herencia en la definición de las transmisiones, y posteriormente polimorfismo en el listado informe.txt.

También se deben definir objetos para los diferentes elementos de la PEC (finca, propiedad, propietario, ...). También se debe crear una clase Fraccion donde se encapsulan las operaciones con fracciones. Por otro lado, se sugiere la creación de las clases (ListaPropiedades, listaPropietarios, ...)..

3. Aunque en los apuntes sólo esté ligeramente comentado, es posible (y, por poco que podáis, recomendado) utilizar las librerías STL. Para ayudar al conocimiento de dichas librerías, os animo a que comentéis en el foro su uso y su posible aplicación (por favor, sólo a nivel de conceptos y sin utilizar código fuente del ejercicio) y evidentemente las dudas. Especialmente sencillos y útiles os pueden ser list y vector.

Su uso os puede facilitar crear las listas de propietarios, de propiedades y de transmisiones.

# Resposta

# Entorn de desenvolupament

- IDE: NetBeans 7.0.1 (C/C++)
- SO: Mac OS X 10.6.8 + Xcode 3.2.6 + JRE 1.6 10M3425 
- SO: Ubuntu 11.10 + gcc 4.6.1 + JRE 1.6.0-23

## Per afegir o modificar els arguments del programa:

En propietats del projecte, en la secció "Execució" establir:

```
"${OUTPUT_PATH}" 2010
```

on 2010 és l'any que es passa com paràmetre

## Gestió de tasques amb l'IDE afegint patrons ToDo:

per activar-ho: >>Eines-> Opcions C/C++<< Opcions del projecte: Suport per a la indexació de fitxers que no siguin ...
```C
// @todo: explicació
```

# Implementació de les llistes

Llistes doblement enllaçades amb iteradors al següent node, amb inserció ordenada
segons el valor clau de l'element a afegir, utilitzant un iterador per trobar la seva
posició en la llista abans de ser afegit en la llista.

La llista hereda control sobre el nombre d'elements de la classe ed (estructura de dades).

La classe IteradorLlista implementa els mètodes virtuals de la classe Iterador.

Llistes principals:

- Llista de propietaris   = Llista<Propietari> llista_propietaris;
- Llista de propietats    = Llista<Propietat> llista_propietats;
- Llista nous propietaris = Llista<Propietari> llista_nous_propietaris;
- Llista de transmissions = Llista<Transmissio_node> llista_transmissions;

## Llista de propietaris / Llista de nous propietaris

Cada node de la llista conté un Propietari amb les següents dades:

- Identificador del propietari = unsigned long id;
- Nom del propietari           = string nom;
- Correu electrònic            = string email;

### Llista de propietats

Cada node de la llista conté una Propietat amb les següents dades:

- Identificador de propietat  = unsigned long id;
- nom de la propietat         = string nom;
- participació general        = Fraccio participacio;
- Llistat de participacions   = Llista<Participacio> llista_participacions;

### Llistat de participacions 

Cada node de la llista conté una participació amb les següents dades:

- Identificador del propietari = unsigned long id;
- Participació del propietari  = Fraccio f_participacio;

## Llista de transmissions

Cada node de la llista conté una transmissió (Transmissio_node) amb les  següents dades:

- Identificador de l'antic propietari       = unsigned long id;
- Data de la transmissió                    = Data data;
- Motiu de la transmissió                   = string motiu;
- Llistat amb els detalls de la transmissió = LlistaTransmissions dades_transmissio;

### Llistat amb els detalls de la transmissió

Cada node de la llista conté un tipus de transmissió (NodeTransmissio) amb les següents dades: 

Tots els subtipus de transmissió contenen un llistat de finques Llista<Finca> llista_finques

Si el tipus de transmissió és HERENCIA el node a demès emmagatzema les dades següents dades:

- Parentesc amb l'antic propietari   = string parentesc;
- Data de l'acceptació de l'herència = Data data_acceptacio;

Si el tipus de transmissió és DONACIO el node emmagatzema les dades següents:

- Si té o no obligacions       = bool amb_obligacions;
- en cas afirmatiu els detalls = string descripcio;

Si el tipus de transmissió és COMPRAVENTA el node emmagatzema les dades següents:

- El preu de la compraventa = float preu;
- El mode de pagament       = string mode_pagament;

## Llistat de finques

Cada node de la llista conté les següents dades:

- Identificador de la finca = unsigned long id;
- Llistat de participacions = Llista<Participacio> llista_participacions;

### Llistat de participacions 

Cada node de la llista conté una participació amb les següents dades:

- Identificador del propietari = unsigned long id;
- Participació del propietari  = Fraccio f_participacio;

## ALTRES ...

Flux d'execució:

 - Fitxers g_compropietarios2.cpp, compropietaris.h, compropietaris.cpp

Operacions sobre fitxers:

 - Classe gestió bàsica de fitxers, Fitxer: fitxer.h i fitxer.cpp
 - Classe gestió fitxer any-propiedades: fitxer_propietats.h, fitxer_propietats.cpp
 - Classe gestió fitxer any-transmisiones: fitxer_transmissions.h, fitxer_transmissions.cpp

Classe Fraccio: Representació i operacions bàsiques sobre fraccions

 - Fitxers fraccio.h, fraccio.cpp

Classe Data: Representació i operacions bàsiques sobre dates

 - Fitxers data.h, data.cpp

Utilitats:

 - Fitxers: util.h, util_excepcio.h, split.h

Constants:

 - Fitxers: constants.h
