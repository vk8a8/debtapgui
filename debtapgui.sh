#!/bin/bash

FILE=$1
FILENAME=$(echo $1 | awk -F "/" '{print $NF}')
FILEDIR=$(echo $1 | rev | sed 's:/: :' | rev | awk '{print $1}')

debtap -Q $FILE
cd $FILEDIR
echo $FILEDIR
mkdir pkgtarzstgetname

CONTROLBALL=$(ar t $FILENAME | grep control)

ar x $FILENAME $CONTROLBALL --output pkgtarzstgetname
cd pkgtarzstgetname

tar -xf control.tar.xz

TARZSTPRE=$(grep Package control | cut -b 10-)-\
$(grep Version control | cut -b 10-)

cd ..

TARZSTNAME=$(ls | grep $TARZSTPRE)

rm -r pkgtarzstgetname

pkexec pacman --noconfirm -U $FILEDIR/$TARZSTNAME

echo "Installation complete"
