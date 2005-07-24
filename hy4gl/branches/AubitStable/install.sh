#!/bin/sh
#
#------ Script de instalacion de hy4GL
#
#
#
# Compruebe que los directorios que se indican a continuacion son correctos
# Y modifique el valor de la variable COMPROBADO a "SI"
export COMPROBADO="NO"
export VERSION=0.7.6

# Directorio donde se quiere instalar hy4gl
export INSTDIR=/usr/local/hy4gl

# Directorio donde se tienen las librerias de PostgreSQL
export PG_INC=/usr/local/pgsql/include
export PG_LIB=/usr/local/pgsql/lib

#
#
#------------------ De aqui en adelante no necesita modificar nada!!
#
export FILES="hy4gl.e hy4gl.h lib4gl.$VERSION.a lib4gl.so.$VERSION"

if [ $COMPROBADO = NO ]
then
   echo "Debe editar el archivo install.sh"
   exit 1
fi

clear


echo -n "Directorio de destino [$INSTDIR]: "
read donde
if [ ! -z "$donde" ]
then
   INSTDIR=$donde
fi

if [ ! -f $PG_INC/postgres.h ]
then
  echo -n "Directorio de 'include' de PostgreSQL [$PG_INC]:"
  read donde
  if [ ! -z "$donde" ]
  then
     PG_INC=$donde 
  fi
fi

if [ ! -f $PG_LIB/libpq.a ]
then
  echo -n "Directorio de librerias de PostgreSQL [$PG_LIB]:"
  read donde
  if [ ! -z "$donde" ]
  then
     PG_LIB=$donde
  fi
fi


echo
echo "Instalando en $INSTDIR ..."
echo

# Compruebo si ya existe y no es un directorio
if [ -e $INSTDIR -a \! -d $INSTDIR ]
then
   echo "$INSTDIR existe y no es un directorio"
   echo
   exit 1
fi

# Compruebo si no existe
if [ ! -e $INSTDIR ]
then
   echo -n "Creando el directorio $INSTDIR..."
   if mkdir -p $INSTDIR 2> /dev/null
   then
      echo " hecho"
   else
      echo " ERROR."
      exit 1
   fi
fi


# Ya debe existir. Veo si puedo escribir en el
if [ ! -w $INSTDIR ]
then
   echo "No se puede escribir en $INSTDIR"
   exit 1
fi

# Ahora debo poder copiar los archivos...
for i in $FILES
do
   echo -n "Copiando $i..."
   if cp $i $INSTDIR 2> /dev/null
   then
      echo "hecho"
   else
      echo "ERROR"
      exit 1
   fi
done
ln -sf $INSTDIR/lib4gl.so.$VERSION $INSTDIR/lib4gl.so || \
   { echo "Error al copiar la libreria lib4gl.so.$VERSION" ; exit 1; }

# Y genero un 'hy4gl' personalizado
echo "#!/bin/sh" > $INSTDIR/hy4gl || { echo "ERROR"; exit 1; }
echo "#" >> $INSTDIR/hy4gl || { echo "ERROR"; exit 1; }
echo "# ---------- Script que llama al programa que haga falta" >> $INSTDIR/hy4gl || { echo "ERROR"; exit 1; }
echo "# -          para compilar cada modulo." >> $INSTDIR/hy4gl || { echo "ERROR"; exit 1; }
echo "#" >> $INSTDIR/hy4gl || { echo "ERROR"; exit 1; }
echo "PGRESLIB=$PG_LIB" >> $INSTDIR/hy4gl || { echo "ERROR"; exit 1; }
echo "PGRESINC=$PG_INC" >> $INSTDIR/hy4gl || { echo "ERROR"; exit 1; }
echo "HY4GLDIR=$INSTDIR" >> $INSTDIR/hy4gl || { echo "ERROR"; exit 1; }
echo  >> $INSTDIR/hy4gl || { echo "ERROR"; exit 1; }
cat hy4gl.dist >> $INSTDIR/hy4gl || { echo "ERROR"; exit 1; }
chmod +x $INSTDIR/hy4gl || { echo "ERROR"; exit 1; }

echo
echo
echo "                      Instalacion finalizada."
echo "                      -----------------------"
echo
echo "   Compruebe que los directorios indicados en el archivo"
echo "$INSTDIR/hy4gl son los correctos"
echo
echo "   Puede compilar sus programas escribiendo:"
echo
echo "   hy4gl <nombre.4gl>"
echo
echo "   En el directorio $PWD/demo/ tiene algunos ejemplos"
echo
echo "   Si enlaza sus programas con la libreria dinamica (por defecto)"
echo "debera incluir el directorio $INSTDIR en su variable"
echo "de entorno LD_LIBRARY_PATH o en /etc/ld.so.conf para que el"
echo "enlazador encuentre las librerias compartidas."
echo 
echo "   No olvide vitaminarse y super-mineralizarse."
echo 
echo "Saludos."
echo "   David Prieto."
echo "   davidp@huelvayork.com"
echo
echo
sleep 10
