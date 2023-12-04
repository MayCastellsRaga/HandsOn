#!/bin/bash
function maximum 
{
 maxim=$(($1+0));
   max=$i
   for i in $@; # returna una string separada en espais en blanc //IFS='algo' indicara el separador, de normal es el espai
   do
        if(($i > max));
        then
            max=$i
        fi
    done
    return $max
 
}
function maximum2
{
   max=0
   limit=$#
   for ((i=0;i<limit;i++)); 
   do
   echo $1
        if [ "$1" -gt "$max" ]; then
            max=$1
        fi
    shift
    done
    return $max
 
}
maximum2 4 8 15 16 23 42
echo "Maximum [4 8 15 16 23 42] is: $?"
exit 0
# Sortida: Maximum [4 8 15 16 23 42] is: 