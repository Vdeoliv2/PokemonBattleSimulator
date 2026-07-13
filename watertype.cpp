#include "watertype.h"
watertype::watertype(const string &_poke_name, const string &_type, int _HP, int _ID,const vector<Attack*> & _attackSet):pokemon(_poke_name,_type,_HP,_ID,_attackSet)
{  
//It does not add any new member

}
//destructor
watertype::~watertype()
{
    while(attackSet.size()>0)
    {
        delete attackSet.at(attackSet.size()-1);
        attackSet.pop_back();
    }
}

void watertype::updateDamages(const string &_enemy_type,const string &_previous_enemy_type)
{
    // I need to set the damages of the attacks back to their original value since they were previously changed when the pokemon fought the preious enemy
    // with a new enemy of a different type it will have to be upadate from their original value not the last value from the setter
    if(_previous_enemy_type=="fire type")
    {
        // this will decrease the values of each of my attack damages by 5 as the original value was previously increased by 5 It cannot be negative.
        for(int i=0;i<attackSet.size();i++)
        {  
            attackSet.at(i)->damage-=5;
           
            if(attackSet.at(i)->damage<0)
            {
                attackSet.at(i)->damage=0;
            }
            
        }
    }
    if(_previous_enemy_type=="grass type")
    {
        // this will increase the values of each of my attacks damages by 5 as the original value was previously decreased by 5. It cannot be negative.
        for(int i=0;i<attackSet.size();i++)
        {
            attackSet.at(i)->damage+=5;
          
        }
    }


    //Now that the damages of the attacks are set back to their original values
    // we can update them again accordingly to the new pokemon we are facing
    //I am supposing water types have advantage with fire types and disadvantages with grass types


    if(_enemy_type=="fire type")
    {
        cout << getName()<< " is in advantage!" << endl;
        // this will increase the values of each of my attack damages by 5
        for(int i=0;i<attackSet.size();i++)
        {
            attackSet.at(i)->damage+=5;
           
        }
    }
    if(_enemy_type=="grass type")
    {
        cout << getName()<< " is in disadvantage!" << endl;
        // this will decrease the values of each of my attacks damages by 5. It cannot be negative.
        for(int i=0;i<attackSet.size();i++)
        {  
            attackSet.at(i)->damage-=5;
          
            if(attackSet.at(i)->damage<0)
            {
                attackSet.at(i)->damage=0;
            }
         
        }
    }
    cout<<endl<<getName()<<"'s Attacks:"<<endl;
    for(int i=0;i<attackSet.size();i++)
        {
            
            cout << "Attack " << i+1 << ": " << attackSet.at(i)->attackName << " -> " << attackSet.at(i)->damage << endl;
        }
    cout<<endl<<endl;
}
