FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    gdb \
    rsync \
    tar \
    zsh \
    mingw-w64 \
    && \
    # Le dice al sistema que use la versión POSIX (con soporte para hilos) \
    # de los compiladores de MinGW como la opción por defecto \
    update-alternatives --set x86_64-w64-mingw32-g++ /usr/bin/x86_64-w64-mingw32-g++-posix && \
    update-alternatives --set x86_64-w64-mingw32-gcc /usr/bin/x86_64-w64-mingw32-gcc-posix && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /generic_compiler

RUN useradd -m -s /bin/zsh appuser

RUN chown -R appuser:appuser /generic_compiler

USER appuser
