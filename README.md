# Compilador [gc]

Este repositorio contiene el código fuente de un compilador simple, single-threaded desarrollado en C++. El proyecto utiliza Docker para garantizar un entorno de compilación y ejecución consistente.

---

## Requisitos Previos 📋

Para compilar y ejecutar este proyecto, el único requisito es tener **Docker** instalado y funcionando en tu sistema.

---

## Crear la Imagen de Docker

El proyecto está configurado para ser compilado usando una imagen de Docker. Podés usar una imagen personalizada basada en el `Dockerfile` del proyecto y construirla vos mismo.

Parado en el directorio raíz del proyecto (donde está el `Dockerfile`), ejecutá:
```bash
docker build -t <nombre-imagen> .
````

-----

## Compilación 🛠️

Todo el proceso de compilación se maneja a través de Docker para evitar problemas de dependencias y asegurar la portabilidad.

Para compilar el proyecto, clona este repositorio, abre una terminal en el directorio raíz del proyecto y ejecuta el siguiente comando (usando el nombre de la imagen que corresponda):

```bash
sudo docker run --rm \
  -v "$(pwd)":/generic_compiler \
  -w /generic_compiler <nombre-imagen> \
  bash -c "
    mkdir -p /tmp/build &&
    cd /tmp/build &&
    cmake /generic_compiler &&
    make &&
    mkdir -p /generic_compiler/bin &&
    cp gc /generic_compiler/bin/ &&
    cp gc_tests /generic_compiler/bin/
  "
```

Este comando compilará el proyecto completo y dejará los ejecutables `gc` y `gc_tests` en una nueva carpeta llamada `bin/` en la raíz del proyecto.

-----

## Uso ▶️

Una vez compilado, puedes usar el compilador o ejecutar la suite de pruebas desde la carpeta `./bin`.

### Ejecutar el Compilador

Para compilar un archivo de código fuente, utiliza el ejecutable `gc`.

**Sintaxis:**

```bash
./bin/gc <ruta_al_archivo_fuente> [-v <ruta_al_archivo_log>]
```

  * `<ruta_al_archivo_fuente>`: la ruta al archivo de código que deseas compilar.
  * `-v <ruta_al_archivo_log>`: activa el modo detallado y guarda un log del proceso de compilación en la ruta especificada. El mismo, muestra información de las tablas de símbolos y literales, además de, tokens y estructuras sintácticas.

**Ejemplos:**

```bash
# Compilar un archivo
./bin/gc examples/program001.txt

# Compilar un archivo y generar un log
mkdir outputs
./bin/gc examples/program001.txt -v outputs/compilation.log
```

### Ejecutar los Tests

Para verificar la integridad y el correcto funcionamiento de los componentes del compilador, puedes ejecutar la suite de pruebas automatizadas.

**Sintaxis:**

```bash
./bin/gc_tests --input=<ruta_proyecto> [--verbose=<directorio_logs>]
```

  * `--input=<ruta_proyecto>`: especifica el directorio raíz del proyecto. Es necesario para que los tests puedan encontrar sus archivos de datos. Generalmente se usa `.` para indicar el directorio actual.
  * `--verbose=<directorio_logs>`: activa la generación de reportes en archivos de texto con los resultados de los tests. Los reportes se guardarán en el directorio especificado. **Se recomienda usar `--verbose=outputs`** para mantener los resultados organizados.

**Ejemplo:**

```bash
# Ejecutar todos los tests y generar los logs de salida en la carpeta 'outputs'
./bin/gc_tests --input=. --verbose=outputs
```
