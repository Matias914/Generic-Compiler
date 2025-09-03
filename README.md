# Descripción
Este es un trabajo realizado por estudiantes de la Universidad del Centro de la Provincia de Buenos Aires. Se trata de un compilador para un lenguaje genérico y simple, definido por una cátedra.    
<br><br />
# Build
Para ejecutar el trabajo, se necesita instalar docker, una herramienta para crear y ejecutar contenedores. Su instalación depende del sistema operativo subyacente. En distribuciones de Linux como Arch, se puede ejecutar el siguiente comando:    
```    
sudo pacman -S docker docker-buildx docker-compose    
```
Una vez instalada la dependencia, en la terminal, se debe elegir un directorio para alojar este repositorio y clonar el proyecto:      
```    
git clone https://github.com/Matias914/Generic-Compiler.git    
```
En terminal también, se debe acceder al directorio del repositorio con:        
```    
cd Generic-Compiler    
```
Para construir la imagen del contenedor docker, se escribe el comando:    
```    
sudo docker build -t <nombre_imagen> .    
```
Finalmente, para ejecutar el proyecto:         
```    
sudo docker run --rm -v "$(pwd)":/generic_compiler -w /generic_compiler <nombre_imagen> bash -c "cmake . && make && ./TPE"
``` 
