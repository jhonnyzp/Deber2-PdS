#!/bin/bash

# Verificar la cantidad de argumentos
if [ "$#" -ne 5 ]; then
    echo "Uso: $0 <ubicacion_origen> <ubicacion_nueva> <usuario> <grupo> <permisos>"
    exit 1
fi

# Obtener los argumentos
ubicacion_origen=$1
ubicacion_nueva=$2
usuario=$3
grupo=$4
permisos=$5

# Verificar que la ubicación origen exista
if [ ! -d "$ubicacion_origen" ]; then
    echo "La ubicación origen no existe."
    exit 1
fi

# Verificar que la ubicación nueva no exista previamente
if [ -d "$ubicacion_nueva" ]; then
    echo "La ubicación nueva ya existe. Por favor, elija una ubicación diferente."
    exit 1
fi

# Crear la ubicación nueva
mkdir "$ubicacion_nueva"

# Copiar los archivos de la ubicación origen a la ubicación nueva
cp -r "$ubicacion_origen"/* "$ubicacion_nueva"

# Cambiar el propietario y grupo de los archivos en la ubicación nueva
chown -R "$usuario:$grupo" "$ubicacion_nueva"

# Cambiar los permisos de los archivos en la ubicación nueva
chmod -R "$permisos" "$ubicacion_nueva"

echo "El proceso de copia y cambio de permisos ha finalizado correctamente."
