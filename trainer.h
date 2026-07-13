#ifndef TRAINER_H
#define TRAINER_H
#include <iostream>
#include <string>
#include <vector>
#include "pokemon.h"
#include "grasstype.h"
#include "firetype.h"
#include "watertype.h"

using namespace std;

class trainer
{
    private:
    string tr_name; // the attributes of the trainer
    int badge_count;
    vector<pokemon*> team; // the team of pokemons of the trainer
    public:
    //overloaded constructor
    trainer(const string &_tr_name,unsigned int _badge_count);
    //copy constructor
    trainer(const trainer & person);
    //copy assignment operator
    trainer & operator = (const trainer & RHS);
    //destructor
    ~trainer();
    
    //getters for name and badge count
    string getTrainerName() const;
    unsigned int getBadgeCount() const;
    // a setter for the bedge count since I will be changind the value of it for the trainer
    void setBadgeCount(int _badge);
    void addPokemon(const pokemon &p);// my add function gotta include the pokemon that is going to be added
    void removePokemon(const string & name); //need to know which pokemon to exclude
    void viewPokemon(const string & name);//I suppose it should show the attributes of that specific pokemon "p"
    int countPokemons();// it will count how many pokemons are in the current team
    bool wasDefeated();// check if the trainer was defeated in a battle
    pokemon*selectedPokemon();// the trainer will choose one pokemon to go to the battle
    void viewStats();//I suppose the stats include the name the badge count and the whole team of pokemons of the trainer
    void LoadingandSaving();//file load system for the trainer's team of pokemons and saved progress file load system for the trainer's team of pokemons and current progress (how many pokemons he defeated and how many pokemons he still has left) and data
    
    
};
#endif