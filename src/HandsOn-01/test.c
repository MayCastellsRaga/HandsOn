/*
    test.c

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokemon.h"

void test_crear_pokemon()
{

    Pokemon p = create_pokemon(25,"pikachu",0.4,6.0);
    if(p.pokemon_id != 25 ||
       strcmp(p.name,"pikachu")!= 0 ||
       p.height != 0.4 || p.weight != 6.0)
    {
        printf("ERROR: TEST CREAR POKEMON NO SUPERAT, DADES INCORRECTES. \n");
    } else
    {
        printf("test de crear pokemon passat amb exit\n");
    }
    destroy_pokemon(p);
}

void test_print_pokemon()
{
    Pokemon p = create_pokemon(25,"pikachu",0.4,6.0);
    FILE *file =fopen("pikachu.txt","w");
    char newline[100];//Treu
    print_pokemon(p, file);   
    fclose(file);
    FILE *fread =fopen("pikachu.txt","r");
    char myString[100];
    fgets(myString, 18, fread);
    printf("my string 1 %s\n",myString);
    if( strcmp("Pokemon: pikachu ",myString)== 0)
    {
        printf("Print pokemon name correcte\n");
    }else
    {
        printf("print pokemon name incorrecte\n");
    }
    strtok(myString, "\n");
    fgets(newline, 17, fread); //
    fgets(myString, 15, fread);
    if( strcmp("Pokemon ID: 25",myString)== 0)
    {
        printf("Print pokemon Id correcte\n");
    }else
    {
        printf("print pokemon Id incorrecte\n");
    }
    strtok(myString, "\n");
    fgets(newline, 17, fread);
    fgets(myString, 25, fread);
    if( strcmp("Pokemon Height: 0.400000",myString)== 0)
    {
        printf("Print pokemon Height correcte\n");
    }else
    {
        printf("print pokemon height incorrecte\n");
    }
    strtok(myString, "\n");
    fgets(newline, 17, fread);
    fgets(myString, 25, fread);
    if( strcmp("Pokemon Weight: 6.000000",myString)== 0)
    {
        printf("Print pokemon weight correcte\n");
    }else
    {
        printf("print pokemon weight incorrecte\n");
    }
    fclose(fread);  
}

int main()
{
   // char* pokestring = "34 name";
   char *types[2] = {"25 pikachu 0.4 6","542 Leavanny 20.5 1.2"};
   int typesId =0;
    Pokemon p = pokemon_from_string(types,typesId);
    test_crear_pokemon();
    test_print_pokemon();
    return 0;
}