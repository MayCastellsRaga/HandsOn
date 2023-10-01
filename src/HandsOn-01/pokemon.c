#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strdup(),
#include "pokemon.h"



Pokemon create_pokemon(int pokemon_id,char *name, double heigth, double weight) //no hi ha version de array perque pokemons form string ja crea pokemons desde una array
 {
    Pokemon pokemon;
    pokemon.pokemon_id= pokemon_id;
    pokemon.name = malloc((strlen(name)+1)*sizeof(char));
    strcpy(pokemon.name,name);
    pokemon.height = heigth;
    pokemon.weight = weight;
    return pokemon;
 }

 void print_pokemon(Pokemon pokemon, FILE *stream)
{
    if(stream == NULL)
    {
        stream = stdout;
    }
    fprintf(stream, "Pokemon: %s \n",pokemon.name);
    fprintf(stream, "Pokemon ID: %d \n",pokemon.pokemon_id);
    fprintf(stream, "Pokemon Height: %f \n",pokemon.height);
    fprintf(stream, "Pokemon Weight: %f \n",pokemon.weight);
}

void print_pokemon_array(char *pokestring[],int typeid, FILE *stream)
{
    Pokemon pokemon = pokemon_from_string(pokestring,typeid);
    if(stream == NULL)
    {
        stream = stdout;
    }
    fprintf(stream, "Pokemon: %s \n",pokemon.name);
    fprintf(stream, "Pokemon ID: %d \n",pokemon.pokemon_id);
    fprintf(stream, "Pokemon Height: %f \n",pokemon.height);
    fprintf(stream, "Pokemon Weight: %f \n",pokemon.weight);
}

Pokemon pokemon_from_string(char *pokestring[],int typeid)
{
    printf("just tu be sure 2 %s\n",pokestring[typeid]);
    int id;
    char * name;
    double height;
    double weight;
    char* temp = strdup(pokestring[typeid]); //idea de chatgpt
    char* cmd = strtok(temp," ");
    id = atoi(cmd);
    cmd = strtok(NULL, " ");
    name = cmd;
    cmd = strtok(NULL, " ");
    weight = atof(cmd);
    cmd = strtok(NULL, " ");
    height = atof(cmd);
    Pokemon pokemon = create_pokemon(id,name,weight,height);
    print_pokemon(pokemon,stderr);
    return pokemon;
}
void destroy_pokemon(Pokemon pokemon)
{
    free(pokemon.name);
}

void destroy_pokemon_array(char *pokestring[],int typeid)
{
      Pokemon pokemon = pokemon_from_string(pokestring,typeid);
    free(pokemon.name);
}

int get_pokemon_id(Pokemon pokemon) {
    return pokemon.pokemon_id;
}

int get_pokemon_id_array(char *pokestring[],int typeid) 
{
    Pokemon pokemon = pokemon_from_string(pokestring,typeid);
    return pokemon.pokemon_id;
}


void set_pokemon_id(Pokemon pokemon, int pokemon_id)
{
    pokemon.pokemon_id = pokemon_id;
}

void set_pokemon_id_array(char *pokestring[],int typeid, int pokemon_id)
{
    Pokemon pokemon = pokemon_from_string(pokestring,typeid);
    pokemon.pokemon_id = pokemon_id;
}
char  get_pokemon_name(Pokemon pokemon)
{
    return pokemon.name;
}

char  get_pokemon_name_array(char *pokestring[],int typeid)
{
    Pokemon pokemon = pokemon_from_string(pokestring,typeid);
    return pokemon.name;
}

void set_pokemon_name(Pokemon pokemon, char *name)
{

    pokemon.name = name;
}
void set_pokemon_name_array(char *pokestring[],int typeid, char *name)
{
    Pokemon pokemon = pokemon_from_string(pokestring,typeid);
    pokemon.name = name;
}

double get_pokemon_weight(Pokemon pokemon)
{
    return pokemon.weight;
}

double get_pokemon_weight_array(char *pokestring[],int typeid)
{
    Pokemon pokemon = pokemon_from_string(pokestring,typeid);
    return pokemon.weight;
}
void set_pokemon_weight(Pokemon pokemon, double weight)
{
    pokemon.weight = weight;
}
void set_pokemon_weight_array(char *pokestring[],int typeid, double weight)
{
    Pokemon pokemon = pokemon_from_string(pokestring,typeid);
    pokemon.weight = weight;
}

double get_pokemon_height(Pokemon pokemon)
{
    return pokemon.height;
}
double get_pokemon_height_array(char *pokestring[],int typeid)
{
    Pokemon pokemon = pokemon_from_string(pokestring,typeid);
    return pokemon.height;
}

void set_pokemon_height(Pokemon pokemon, double height)
{
    pokemon.height = height;
}

void set_pokemon_height_array(char *pokestring[],int typeid, double height)
{
    Pokemon pokemon = pokemon_from_string(pokestring,typeid);
    pokemon.height = height;
}