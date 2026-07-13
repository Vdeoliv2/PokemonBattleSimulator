#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Attack
{
    string attackName;
    int damage;
};
class pokemon
{
    protected:
        string poke_name;
        string type;
        int HP;
        int ID;//attributes of the pokemon
        vector<Attack*> attackSet;
    public:
        //default constructor
        pokemon();
        //overloading constructor
        pokemon(const string &_poke_name, const string &_type, int _HP,  int _ID, vector<Attack*> _attackSet);
        //copy constructor
        pokemon(const pokemon & member);
        //copy assignment operator
        pokemon & operator =(const pokemon & RHS);
        //destructor
        virtual ~pokemon();
        
        
        //setters
        void setName(const string &_poke_name);
        void setType(const string &_type);
        void setHP(int _HP);
        void setID(int _ID);
        void setAttack(const string &_attackName,int _damage);
       
        //getters
        string getName() const;
        string getType() const;
        int getHP() const;
        int getID() const;
        string getAttackName(unsigned int pos) const;
        int getAttackDamage(unsigned int pos) const;
        unsigned int getNumberofAttacks() const;// retrun the number of attacks of my pokemon
        

        /*polymorphism for update Damage. It will comapare the types of each of the opponents, and update the damages of their attacks accordingly to
        advantages
        and diadvantages. When a pokemon is in advantage, the level of damage of each of its attacks is increased by 5
        when a pokemon is in disadvantage, the level of damage of each of its attacks is decreased by 5*/
        virtual void updateDamages(const string &_enemy_type,const string &_previous_enemy_type);

        // In this function, the Announcer will invite me to choose an attack for my pokemon and it will subtract from the enemy's HP 
        // Then it will have it's HP updated by the setter
        int attack(const string & trainer_name,const string & _pokemon_name,int _enemy_HP);
};
#endif