#include "trainer.h"
#include <iostream>
#include <fstream>

//overloaded constructor
trainer::trainer(const string & _tr_name,unsigned int _badge_count)
{
    tr_name=_tr_name;
    badge_count=_badge_count;
    // I do not want to decare the team right at the declaration of the new trainer. The addPokemon function should be adding
    //the pokemons of the team for me. I thought I should put the team member the way I would in a default constructor

}
//copy constructor
trainer::trainer(const trainer & person)
{
    tr_name=person.tr_name;
    badge_count=person.badge_count;
    for(int i=0;i<person.team.size();i++)
    {
        pokemon*new_pokemon = nullptr;
        if (person.team.at(i)->getType() == "fire type"){
        new_pokemon = new firetype ((firetype &)*person.team.at(i));
        new_pokemon =person.team.at(i);
        team.push_back(new_pokemon);
        }
        else if (person.team.at(i)->getType() == "grass type"){
            new_pokemon = new grasstype ((grasstype &)*person.team.at(i));
            new_pokemon =person.team.at(i);
            team.push_back(new_pokemon);
        }
        else if (person.team.at(i)->getType() == "water type"){
            new_pokemon = new watertype ((watertype &)*person.team.at(i));
            new_pokemon =person.team.at(i);
            team.push_back(new_pokemon);
        }
    }
}
//copy assignment operator
trainer & trainer::operator = (const trainer & RHS)
{
    if(this!=&RHS){
        tr_name=RHS.tr_name;
    badge_count=RHS.badge_count;
        if(team.empty()==false)
        {
            while(team.size()>0)
            {
                delete team.at(team.size()-1);
                team.pop_back();
            }
        }
        for(int i=0;i< RHS.team.size();i++)
    {
        pokemon*new_pokemon = nullptr;
        if (RHS.team.at(i)->getType() == "fire type"){
        new_pokemon = new firetype ((firetype &)*RHS.team.at(i));
        new_pokemon =RHS.team.at(i);
        team.push_back(new_pokemon);
        }
        else if (RHS.team.at(i)->getType() == "grass type"){
            new_pokemon = new grasstype ((grasstype &)*RHS.team.at(i));
            new_pokemon =RHS.team.at(i);
            team.push_back(new_pokemon);
        }
        else if (RHS.team.at(i)->getType() == "water type"){
            new_pokemon = new watertype ((watertype &)*RHS.team.at(i));
            new_pokemon =RHS.team.at(i);
            team.push_back(new_pokemon);
        }
    }
    }
    return *this;
}
//destructor
trainer::~trainer()
{
    while(team.size()>0)
    {
        delete team.at(team.size()-1);
        team.pop_back();
    }
}
    
void trainer::addPokemon(const pokemon &p)// my add function gotta include the pokemon that is going to be added
{
pokemon *temp = nullptr;
if(p.getType() == "fire type")
{
    temp = new firetype ((firetype &)p);
}
else if (p.getType()== "grass type")
{
    temp = new grasstype ((grasstype &)p);
}
else if (p.getType()== "water type")
{
    temp = new watertype ((watertype & )p);
}
team.push_back(temp);
}

void trainer::removePokemon(const string & name) //need to know the name of the pokemon to exclude from the team
{
for (int i=0;i<team.size();i++)
{
    if(team.at(i)->getName()== name)
    {
        team.erase(team.begin()+i);
        break;
    }
}

}
string trainer::getTrainerName() const
{
    return tr_name;
}
unsigned int trainer::getBadgeCount() const
{
    return badge_count;
}
void trainer::setBadgeCount (int badge){
    badge_count = badge;
}
void trainer::viewPokemon(const string & name)//I suppose it should show the attributes of that specific pokemon whose name is "name"
{
    int flag=0;// will determine wether a pokemon was found on the list or not. will be one if a pokemon was found
    for (int i=0;i<team.size();i++)
{
    if(team.at(i)->getName()== name)
    {
    flag=1;
    cout << "Pokemon name: " << team.at(i)->getName() << endl;
    cout << "Pokemon type: " << team.at(i)->getType() << endl;
    cout << "Pokemon ID: " << team.at(i)->getID() << endl;
    break;
    }
}
if(flag==0)
{
    cout << "You do not have a Pokemon called " << name << "." << endl;
}

}
int trainer::countPokemons()// it will count how many pokemons are in the current team
{
    return team.size();
}
bool trainer::wasDefeated()// check it the trainer was defeated in a battle
{
    int sum_of_HPs=0;// I will sum the HPs of all of my pokemons. 
    //Since HP must be a positive integer, if the sum is zero, I assume all HP of each of the pokemons equal zero 
    //and therefore the trainer was defeated 
    for(int i=0;i<team.size();i++)
    {
        sum_of_HPs = sum_of_HPs + team.at(i)->getHP();
    }
    if(sum_of_HPs==0)return true;
    else return false;
}
pokemon* trainer::selectedPokemon()// the trainer will choose one pokemon to go to the battle
{
    cout << "Announcer: " << getTrainerName() << ", select your pokemon!" << endl;
    string name;
    cin >> name;
    for (int i=0;i<team.size();i++)
    {
        if(team.at(i)->getName()== name && team.at(i)->getHP()!=0)// the selected pokemon cannot be one that was alaready defeated
        {
            cout << getTrainerName() << ": " << team.at(i)->getName() << ", I choose you!" << endl;
            return team.at(i);
        }
    }
    cout << "You do not have this pokemon, or it was defeated." << endl; // When loop is over and nothing was returned and try the function again
    return trainer::selectedPokemon();
}
void trainer::viewStats()//I suppose the stats include the name the badge count and the whole team of pokemons of the trainer
{
cout << "Badge Count: " << getBadgeCount() << endl;
cout << "Pokemons:" << endl;
for(int i=0;i<team.size();i++)
{
    cout << i+1 << " " << team.at(i)->getName() << endl;
}
}
void trainer::LoadingandSaving()//file load and save system for the trainer's team of pokemons
{
    cout << "Do you want to save your current team (if not it will be deleted)? yes or no: "; // If I am loading a new team it will geive me the potion to save my current team
    string response;
    cin >> response;
    if(response == "yes")
    {
        cout << endl << "Choose a name for you current team (ending with .txt)" << endl;
        string ofilename;
        cin >> ofilename;
        ofstream output_file;
        output_file.open(ofilename);
        if(output_file.is_open()==true)
        {
            for(long long unsigned int i=0; i < team.size();i++)
            {// it will save the attributes of each pokemon from the team in each line until ID
                output_file << "Pokemon ." << team.at(i)->getName() << "," << team.at(i)->getType() << "," << team.at(i)->getHP() << "," << team.at(i)->getID() << endl;
                // then, for the set of attacks of the pokemon there will be an attack and its corresponding level of damage per line
                for(int j=0;j<team.at(i)->getNumberofAttacks();j++){
                    output_file << "    Attack ." << team.at(i)->getAttackName(j) << "," << team.at(i)->getAttackDamage(j) << endl;
                }
            }
            output_file.close();
        }
    }
    else
    {
       team.clear();// it will make the team empty
    }
    cout << endl << "Choose a team from a file" << endl;
    string ifilename;
    cin >> ifilename;
    ifstream input_file;
    input_file.open(ifilename);
    if(input_file.is_open()==false)
    {
        cout << "The entered file does not exist!" << endl;
    }
    else
    {
        pokemon* new_pokemon = nullptr;//it saves the pokemon's features from each line of the input file
        string identifier;//it will identify whether this is either the identity of the pokemon (name, type, HP and ID) or its attacks
        string whitespace;// will hold the characters between the identifier and the names of pokemon and of the attacks
        string _poke_name;
        string _type;
        int _HP;
        int _ID;
        string _attackName;
        int _attackDamage;

        input_file>>identifier; 

        while(input_file.eof()==false)
        {
            if(identifier=="Pokemon"){//after the identifier I included a dot for a new getline command to hold the white space and the dot before 
            new_pokemon= new pokemon;
            getline(input_file,whitespace,'.');//reading the name so the value inside the name does not start with a whitespace
            getline(input_file,_poke_name,',');
            getline(input_file,_type,',');
            char comma;//will hold the comma character
            input_file >> _HP >> comma >> _ID;
            input_file.ignore(256,'\n');
            if(_type == "fire type")// update the new pokemon to its specific type
            {
                new_pokemon = new firetype ((firetype &)*new_pokemon);
            }
            else if (_type== "grass type")
            {
                new_pokemon= new grasstype ((grasstype &)*new_pokemon);
            }
            else if (_type== "water type")
            {
                new_pokemon = new watertype ((watertype &)*new_pokemon);
            }
            new_pokemon->setName(_poke_name);
            new_pokemon->setType(_type);
            new_pokemon->setHP(_HP);
            new_pokemon->setID(_ID);// input the name type and ID
            }
            
            
            while(input_file>>identifier){
                if(identifier!="Attack")
                {
                    break;
                }
                
                getline(input_file,whitespace,'.');
                getline(input_file,_attackName,',');// input the name of the attack and the damage
                
                input_file >> _attackDamage;
                input_file.ignore(256,'\n');
                new_pokemon->setAttack(_attackName,_attackDamage);
              
           //     input_file>>identifier;
            }
    
            team.push_back(new_pokemon);
        }
        cout << "The file was loaded Successfully"<<endl<<endl;
        cout << getTrainerName() <<"'s current team is:" << endl;

        for(int i=0;i<team.size();i++){
            cout<< "Pokemon " << i+1 << ": " << team.at(i)->getName() << endl;
        }
        input_file.close();
    }
}
