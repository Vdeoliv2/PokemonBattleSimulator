#ifndef BATTLE_H
#define BATTLE_H
#include "pokemon.h"
#include "trainer.h"
#include <vector>

class Battle
{
    private:
    
    public:
    //function to start the battle, it will annouce the start and assemble the two trainers into the battle field.
    int dispute(trainer &T1,trainer &T2);
    
};

//function to start the battle, it will annouce the start and assemble the two trainers into the battle field.
int Battle::dispute(trainer & trainer1,trainer & trainer2)
{

int badge; //This will be used to increase the number of badges of the winner by 1
//check the size of team of pokemons of each trainer. Cannot excede six pokemons. If that happens, the battle is cancelled
if(trainer1.countPokemons()>6||trainer2.countPokemons()>6)
{
    cout << "Announcer: Excess of pokemons. We cannot start this battle!" << endl;
    return 0;
}
int last_loss=0;// This is a flag to determine which trainer had their last pokemon defeated and asked to choose another one
//I chose to start it with the value of zero for the beggining of the battle
//If the last pokemon defeated was from trainer 1, last loss ==1. If it beblonged to trainer 2 last loss==2
//in a while loop will ask each trainer which pokemon they want to select and output the pokemon selected.
pokemon* pokemon1=nullptr;
pokemon* pokemon2=nullptr;
int pokemon1_HP;
int pokemon2_HP;// the attack functions will return the health points of the respective attacked pokemons and assigned in their setters

string _former_enemy_type="none";// this will store the type of the previous pokemon defeated and be used in the virtual updateHP function
//to set the damages of the pokemon of the other trainer back to their original values
//when there are no previous pokemons defeated by the pokemon currently in battle, the string is set to none as the attacks
//do not need to be set back to their original value

while(!(trainer1.wasDefeated()||trainer2.wasDefeated()))// It will stop when one of the trainers is defeated
{
 if(last_loss==0||last_loss==1)
 {
    if(last_loss==1)
    {
        _former_enemy_type=pokemon1->getType();
        
    }
    pokemon1 = trainer1.selectedPokemon();//trainer 1 brings one pokemon to the battle
    cin.ignore(256,'\n');//careful so the getline function does not read the new line character as my choice of attack
    if(last_loss==1)
    {
    cout<< endl << endl << pokemon1->getName() << "'s HP: " << pokemon1->getHP() << endl;//shows the current Hp of each of the pokemons currently in battle
    cout << pokemon2->getName() << "'s HP: " << pokemon2->getHP() << endl << endl;
    pokemon1->updateDamages(pokemon2->getType(),"none");// the new pokemon do not have any previous enemies so its attacks do not have ot be set back to the original
    pokemon2->updateDamages(pokemon1->getType(),_former_enemy_type);
    }
 }
 if(last_loss==0||last_loss==2)
 {
    if(last_loss==2)
    {
        _former_enemy_type=pokemon2->getType();
        
    }
    pokemon2 = trainer2.selectedPokemon();//trainer 2 brings one pokemon to the battle
    cin.ignore(256,'\n');//careful so the getline function does not read the new line character as my choice of attack
    cout<< endl << endl << pokemon1->getName() << "'s HP: " << pokemon1->getHP() << endl;//shows the current Hp of each of the pokemons currently in battle
    cout << pokemon2->getName() << "'s HP: " << pokemon2->getHP() << endl << endl;
    if(last_loss==2)
    {
    pokemon1->updateDamages(pokemon2->getType(),_former_enemy_type);
    pokemon2->updateDamages(pokemon1->getType(),"none");// the new pokemon do not have any previous enemies so its attacks do not have ot be set back to the original
    }
    else//last_loss==0
    {
    pokemon1->updateDamages(pokemon2->getType(),_former_enemy_type);//_former_enemy_type=="none" as it is the beginning of the battle and no one had
    pokemon2->updateDamages(pokemon1->getType(),_former_enemy_type);//any previous enemies
    }
 }
    //nested while loop
    while(!(pokemon1->getHP()==0||pokemon2->getHP()==0))
    {
    //in a while loop it will call the attack function from pokemon class for trainer 1 and then for trainer 2. It will stop when one of the HPs is zero
    //then it will announce which pokemon cannot compete anymore. It pops back from the outer loop
     pokemon2_HP = pokemon1->attack(trainer1.getTrainerName(),pokemon1->getName(),pokemon2->getHP());
     pokemon2->setHP(pokemon2_HP);
     cout<< endl << endl << pokemon1->getName() << "'s HP: " << pokemon1->getHP() << endl;
     cout<< pokemon2->getName() << "'s HP: " << pokemon2->getHP() << endl << endl;
     if(pokemon2->getHP()==0)// trainer 2 cannot choose an attack anymore if their pokemon was already defeated
     {
        break;
     }
     pokemon1_HP = pokemon2->attack(trainer2.getTrainerName(),pokemon2->getName(),pokemon1->getHP());
     pokemon1->setHP(pokemon1_HP);
     cout<< endl << endl << pokemon1->getName() << "'s HP: " << pokemon1->getHP() << endl;
     cout<< pokemon2->getName() << "'s HP: " << pokemon2->getHP() << endl << endl;
    }
    if(pokemon1->getHP()==0)
    {
        cout << endl << endl << "Announcer: " << pokemon1->getName() << " cannot battle anymore!" << endl;
        last_loss=1;
    }
    else
    {
        cout << endl << endl << "Announcer: " << pokemon2->getName() << " cannot battle anymore!" << endl;
        last_loss=2;
    }
//it announces the winner
}
if(trainer1.wasDefeated())
{
    cout << endl << endl << "Announcer: This means that the winner is " << trainer2.getTrainerName() << "!" << endl;
    badge = trainer2.getBadgeCount();
    badge += 1; //one new badge for the winner
    trainer2.setBadgeCount(badge);
    return 0;
}
else
{
    cout << endl << endl << "Announcer: This means that the winner is " << trainer1.getTrainerName() << " !" << endl;
    badge = trainer1.getBadgeCount();
    badge += 1; //one new badge for the winner
    trainer1.setBadgeCount(badge);
    return 0;
}
}


#endif