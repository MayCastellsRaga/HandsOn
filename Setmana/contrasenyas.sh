#!/bin/bash

IFS=":"
cat << EOF > users.txt
jordi:1234:ok
May:HEY:nok
EOF
while read -r usuari contrasenya estat
do
    echo "Usuari: $usuari"
    echo "Pass: $contrasenya"
    echo "Estat $estat"
done < users.txt