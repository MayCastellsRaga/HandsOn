#!/bin/bash
mkdir -p test
touch test/fitxer1.txt
touch test/fitxer2.txt
touch test/fitxer3.c
touch test/fitxer4.txt

ls test/  | grep "*.old"
for file in test/*.txt;
do
   # mv $file ${file%.txt}.old

done
echo "Fitxers amb extensió .txt modificats a .old:"
#rm -rf test
exit 0
# Sortida:
# Fitxers amb extensió .txt modificats a .old:
# fitxer1.old fitxer2.old fitxer4.ol