#ifndef FIRETYPE_H
#define FIRETYPE_H

#include "pokemon.h"
#include "trainer.h"
#include <vector>


class firetype : public pokemon
{
    private:

    public:
    firetype(const string &_poke_name, const string &_type,  int _HP, int _ID,const vector<Attack*> & _attackSet);
    //destructor
    virtual ~firetype();

 
/*polymorphism for update HP. It will comapare the types of each of the opponents, and update the damages of their attacks accordingly to
advantages
and diadvantages. When a pokemon is in advantage, the level of damage of each of its attacks is increased by 5
when a pokemon is in disadvantage, the level of damage of each of its attacks is decreased by 5*/
    virtual void updateDamages(const string &_enemy_type,const string &_previous_enemy_type);
    
};
#endif