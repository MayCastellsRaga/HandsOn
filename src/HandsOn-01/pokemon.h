/*
    pokemon.h
*/
#ifndef _POKEMON_H_
#define _POKEMON_H_

typedef struct pokemon
{
    int pokemon_id;
    char * name;
    double height;
    double weight;
}Pokemon;


Pokemon create_pokemon (int pokemon_id, char *name, double height, double weight);
void print_pokemon(Pokemon pokemon, FILE *stream);
void destroy_pokemon(Pokemon pokemon);
int get_pokemon_id(Pokemon pokemon);
void  set_pokemon_id(Pokemon pokemon, int pokemon_id);
char get_pokemon_name(Pokemon pokemon);
void set_pokemon_name(Pokemon pokemon, char *name);
double get_pokemon_weight(Pokemon pokemon);
void set_pokemon_weight(Pokemon pokemon, double weight);
double get_pokemon_height(Pokemon pokemon);
void set_pokemon_height(Pokemon pokemon, double height);

Pokemon pokemon_from_string(char *pokestring[],int typeid);
void print_pokemon_array(char *pokestring[],int typeid, FILE *stream);
void destroy_pokemon_array(char *pokestring[],int typeid);
void set_pokemon_height_array(char *pokestring[],int typeid, double height);
double get_pokemon_height_array(char *pokestring[],int typeid);
void set_pokemon_weight_array(char *pokestring[],int typeid, double weight);
double get_pokemon_weight_array(char *pokestring[],int typeid);
void set_pokemon_name_array(char *pokestring[],int typeid, char *name);
char  get_pokemon_name_array(char *pokestring[],int typeid);
void set_pokemon_id_array(char *pokestring[],int typeid, int pokemon_id);
int get_pokemon_id_array(char *pokestring[],int typeid) ;
#endif 