# -----------------------------------------------
# PD: Se parte de la base del anterior
# -----------------------------------------------

FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# Se agrega nodejs, npm, wabt
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    rsync \
    nodejs \
    npm \
    wabt \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app