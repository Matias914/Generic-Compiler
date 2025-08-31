FROM ubuntu:22.04

# ------- apt-get update
# Actualiza la lista de paquetes disponibles
# Es como "refrescar" el catálogo de software disponible
# Siempre hazlo antes de instalar paquetes
#
# ------- && apt-get install -y \
# && = "y si el comando anterior fue exitoso, entonces..."
# install -y = instalar paquetes sin preguntar (parametro "yes")
# \ = continúa el comando en la siguiente línea
#
# Los paquetes:
#
# ------- build-essential:
# Meta-paquete que incluye gcc, g++, make y otras herramientas básicas de compilación
# ------- cmake:
# Sistema de build que CLion necesita
# ------- gdb:
# Debugger que CLion usa para depurar código
# ------- rsync:
# CLion lo usa para sincronizar archivos entre tu máquina y el contenedor
# ------- tar:
# Para comprimir/descomprimir archivos (CLion también lo necesita)
#
# ------- && rm -rf /var/lib/apt/lists/*
# Limpia la caché de apt-get para hacer la imagen más pequeña
# /var/lib/apt/lists/* contiene los metadatos de paquetes que ya no necesitas
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    gdb \
    rsync \
    tar \
    zsh \
    && rm -rf /var/lib/apt/lists/*

# Se define un nombre para el directorio
WORKDIR /generic_compiler

# Usuario no-root (para que CLion no corra como root)
RUN useradd -m -s /bin/zsh appuser

# Se cambian los permisos a los de usuario
RUN chown -R appuser:appuser /generic_compiler

# Se cambia al usuario appuser
USER appuser
