#!/bin/bash

# --------------------------------------------------
# Script ejecutado dentro de Docker
# --------------------------------------------------

# $1 = Ruta relativa del archivo .txt
SOURCE_REL_PATH="$1"

# --- DEBUGGING ---
if [ -z "$SOURCE_REL_PATH" ]; then
    echo "[[ ERROR ]]: El script recibió un argumento vacío." >&2
    exit 1
fi

# --- DEBUGGING ---
# Se manda esto a stderr para verlo en consola pero no ensuciar el archivo de salida
echo "DEBUG: Docker recibió el archivo: '$SOURCE_SOURCE_REL_PATH'" >&2

# Se crea compilador dentro del entorno de Docker
mkdir -p build
# shellcheck disable=SC2164
cd build

# Se ejecuta cmake una vez gracias al if
# Se silencian las salidas para evitar ruido
if [ ! -f "Makefile" ]; then
    cmake .. > /dev/null 2>&1
fi
make gc > /dev/null 2>&1

# shellcheck disable=SC2103
cd ..

# Rutas de archivos generados
BASENAME=$(basename "$SOURCE_REL_PATH" .txt)
DIRNAME=$(dirname "$SOURCE_REL_PATH")

OUTPUT_WAT="${DIRNAME}/${BASENAME}.wat"
OUTPUT_WASM="${DIRNAME}/${BASENAME}.wasm"

# Usando el compilador se genera el WAT
./build/gc "$SOURCE_REL_PATH" --output "$OUTPUT_WAT" >&2

# Se captura la salida del compilador
GC_EXIT_CODE=$?

# shellcheck disable=SC2181
if [ $GC_EXIT_CODE -ne 0 ]; then
    echo "SCRIPT_DETECTED_COMILATION_ERROR"
    exit 1
fi

# Se dan permisos publicos para que puedan ser borrados
if [ -f "$OUTPUT_WAT" ]; then chmod 666 "$OUTPUT_WAT"; fi

# Conversión a WASM
wat2wasm "$OUTPUT_WAT" -o "$OUTPUT_WASM" >&2

WABT_EXIT_CODE=$?

if [ $WABT_EXIT_CODE -ne 0 ]; then
    # Si el WAT generado está mal formado
    echo "SCRIPT_DETECTED_WABT_ERROR"
    exit 1
fi

# Se dan permisos publicos para que puedan ser borrados
if [ -f "$OUTPUT_WASM" ]; then chmod 666 "$OUTPUT_WASM"; fi

# Ejecutar el WASM con Node
node tests/environment/utilities.js "$OUTPUT_WASM"