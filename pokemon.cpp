#include "pokemon.h"
#include <vector>
pokemon::pokemon()
{
    poke_name="";
    type="";
    HP=0;
    ID=0;

}
pokemon::pokemon(const string &_poke_name, const string &_type, int _HP, int _ID, vector<Attack*> _attackSet)//overloading constructor to determine the attributes of the pokemon
{
    poke_name=_poke_name;
    type=_type;
    HP = _HP;
    ID=_ID;
    for(int i=0;i<_attackSet.size();i++)
    {
        Attack*new_attack = new Attack;
        new_attack = _attackSet.at(i);
        attackSet.push_back(new_attack);
    }
}
//copy constructor
pokemon::pokemon(const pokemon & member)
{
    poke_name=member.poke_name;
    type=member.type;
    HP = member.HP;
    ID=member.ID;
    for(int i=0;i< member.attackSet.size();i++)
    {
        Attack*new_attack = new Attack;
        new_attack = member.attackSet.at(i);
        attackSet.push_back(new_attack);
    }
}
//copy assignment operator
pokemon & pokemon::operator =(const pokemon & RHS)
{
    if(this!=&RHS){
        poke_name = RHS.poke_name;
        type = RHS.type;
        HP = RHS.HP;
        ID = RHS.ID;
        if(attackSet.empty()==false)
        {
            while(attackSet.size()>0)
            {
                delete attackSet.at(attackSet.size()-1);
                attackSet.pop_back();
            }
        }
        for(int i=0;i< RHS.attackSet.size();i++)
    {
        Attack*new_attack = new Attack;
        new_attack = RHS.attackSet.at(i);
        attackSet.push_back(new_attack);
    }
    }
    return *this;
}
//destructor
pokemon::~pokemon()
{
    while(attackSet.size()>0)
    {
        delete attackSet.at(attackSet.size()-1);
        attackSet.pop_back();
    }
}

//setters for each attribute
void pokemon::setName(const string &_poke_name)
{
    poke_name=_poke_name;
}
void pokemon::setType(const string &_type)
{
    type=_type;
}
void pokemon::setHP(int _HP)
{
    HP = _HP;
}
void pokemon::setID(int _ID)
{
    ID=_ID;
}
void pokemon::setAttack(const string &_attackName, int _damage)
{
    Attack* new_attack = new Attack;
    new_attack->attackName=_attackName;
    new_attack->damage=_damage;
    attackSet.push_back(new_attack);
}

//getters for each attribute
string pokemon::getName() const
{
    return poke_name;
}
string pokemon::getType() const
{
    return type;
}
int pokemon::getHP() const
{
    return HP;
}

int pokemon::getID() const
{
    return ID;
}
string pokemon::getAttackName(unsigned int pos) const
{
    return attackSet.at(pos)->attackName;
}
int pokemon::getAttackDamage(unsigned int pos) const
{
    return attackSet.at(pos)->damage;
}
unsigned int pokemon::getNumberofAttacks() const
{
    return attackSet.size();
}

/*polymorphism for update HP. It will comapare the types of each of the opponents, and update the damages of their attacks accordingly to
advantages
and diadvantages. When a pokemon is in advantage, the level of damage of each of its attacks is increased by 5
when a pokemon is in disadvantage, the level of damage of each of its attacks is decreased by 5*/
void pokemon::updateDamages(const string &_enemy_type,const string &_previous_enemy_type)
{

//This function will only be relevant in the derived classes. It will not be used from the base class


}


// In this function, the Announcer will invite me to choose an attack for my pokemon and it will subtract from the enemy's HP 
// Then it will have it's HP updated by the setter
int pokemon::attack(const string & trainer_name,const string & _pokemon_name,int  _enemy_HP)
{
     //announcer invites me to choose an attack
     cout << "Announcer: "<< trainer_name << ", choose an attack!" << endl << endl;
    
     string choice;
     int _chosen_attack_damage;// the amount of damage of the chosen attack
     _chosen_attack_damage=-1;//this "-1" is a flag for an invalid choice
     while(_chosen_attack_damage==-1){
     //I choose one of the possible attacks. It keeps looping until I choose a valid attack.
     
     getline(cin,choice);
     for(int i=0;i<attackSet.size();i++)
     {
         if(attackSet.at(i)->attackName==choice)
         {
             _chosen_attack_damage=attackSet.at(i)->damage;
             break;
         }
     }
     if(_chosen_attack_damage==-1)// I am assuming that the for loop did not find any name corresponding to the chosen attack
     {
         cout << "Your Pokemon do not have that attack. Please choose a valid name!"<< endl;
     }
     }
     //Simulating the trainer yelling:
     cout << trainer_name << ": " << _pokemon_name << ", use " << choice << "!" << endl << endl;
 
     //my pokemon does the attack that will reduce the health points of my opponent
   
     _enemy_HP= _enemy_HP - _chosen_attack_damage;
     
     if(_enemy_HP < 0)//HP cannot be negetive
     {
         _enemy_HP = 0;
     }
    //return the new value of the HP of the affected pokemon
     return _enemy_HP;
}