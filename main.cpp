#include <iostream>
#include <vector>
#include "battle.h"
#include "trainer.h"
#include "pokemon.h"
#include "grasstype.h"
#include "firetype.h"
#include "watertype.h"

using namespace std;


int main(){

string attack1_name="Hot Iron";
unsigned int attack1_damage = 16;
string attack2_name="Falling Star";
unsigned int attack2_damage = 10;
string attack3_name="Ignation";
unsigned int attack3_damage = 25;
string attack4_name="Draco Meteor";
unsigned int attack4_damage = 21;
Attack attack1;
Attack attack2;
Attack attack3;
Attack attack4;
vector<Attack*> Charmander_attacks;
attack1.attackName=attack1_name;
attack1.damage=attack1_damage;
attack2.attackName=attack2_name;
attack2.damage=attack2_damage;
attack3.attackName=attack3_name;
attack3.damage=attack3_damage;
attack4.attackName=attack4_name;
attack4.damage=attack4_damage;
Charmander_attacks.push_back(&attack1);
Charmander_attacks.push_back(&attack2);
Charmander_attacks.push_back(&attack3);
Charmander_attacks.push_back(&attack4);// define an array of structures for the attacks of each pokemon
firetype Charmander("Charmander", "fire type", 100,  1245128, Charmander_attacks);
firetype Cyndaquill("Cyndaquill", "fire type", 100, 2347892, Charmander_attacks);//In the new pokmon I define its name, type,HP, ID and collecction of attacks
firetype Torchich("Torchic", "fire type", 100, 2347892, Charmander_attacks);
firetype Cinderace("Cinderace", "fire type", 100, 2347892, Charmander_attacks);
firetype Tepig("Tepig", "fire type", 100, 2347892, Charmander_attacks);// introdue the pokemons
trainer Victor("Victor",3);// The trainer's parameters contain their name and numer of badges
trainer Rick("Rick",2);
Rick.addPokemon(Charmander);
Rick.addPokemon(Cinderace);

Victor.addPokemon(Charmander);
Victor.addPokemon(Cyndaquill);
Victor.addPokemon(Torchich);
Victor.addPokemon(Tepig);// add pokemons in parenthesis to VIctor's current team
Victor.addPokemon(Cinderace);
Victor.addPokemon(Cinderace);
Victor.addPokemon(Cinderace);
Victor.addPokemon(Cinderace);
Victor.viewPokemon("Cyndaquill");// Show the features of the pokemon with the name of Cyndaquill
Battle battle1;
battle1.dispute(Victor,Rick);
Victor.removePokemon("Cyndaquill");
Victor.removePokemon("Cinderace");
Victor.removePokemon("Cinderace");
Victor.removePokemon("Cinderace");
Victor.removePokemon("Cinderace");
Victor.removePokemon("Tepig");
Victor.removePokemon("Torchic");// should have only Charmander left to be saved in the current team before I load a new team
Victor.LoadingandSaving();
Victor.viewPokemon("Snivy");


Rick.LoadingandSaving();
Battle battle2;
battle2.dispute(Victor,Rick);// it will increase the number of badges of the winner by one

cout << "Victor's current number of badges: " << Victor.getBadgeCount() << endl;
cout << "Ricky's current number of badges: " << Rick.getBadgeCount() << endl;
Victor.viewStats();// Shows the number of badges of the trainer and its current team
}