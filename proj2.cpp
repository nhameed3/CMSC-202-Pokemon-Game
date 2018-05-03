/*Title: proj2.cpp
Author: Nauman Hameed
Date: 10/18/16
Section: 17
Description: Simple implementation of the famous Pokemon Franchise.
*/
#include "proj2.h"

int main () {
  srand(10);
  vector<Pokemon> pokeDex;
  vector<MyPokemon> myCollection;
  getPokeDex(pokeDex);
  getMyCollection(myCollection);
  mainMenu(pokeDex, myCollection);
  return 0;
}
//Fills the Pokemon vector
void getPokeDex(vector<Pokemon> & pokeDex){
  int num, cpMin, cpMax, rarity;
  string name;
  ifstream inStream;
  inStream.open(POKEDEX);
  for(int i = 0; i < POKECOUNT; i++)
    {
      inStream >> num  >> name >> cpMin >> cpMax >> rarity;
      Pokemon Pokemon( num, name, cpMin, cpMax, rarity);
      pokeDex.push_back(Pokemon);
    }
}
//Fills the MyPokemon vector
void getMyCollection(vector<MyPokemon> & myCollection){
  int num, CP, HP, rarity;
  string name;
  ifstream inStream;
  inStream.open(MYCOLLECTION);
  while(inStream >> num  >> name >> CP >> HP >> rarity)
    {
      MyPokemon MyPokemon(num, name, CP, HP, rarity);
      myCollection.push_back(MyPokemon);
    }
}
//Prints the Pokemon vector
void printPokeDex(vector<Pokemon> & pokeDex){
  for(unsigned int i =0; i < pokeDex.size(); i++)
    {
      cout << pokeDex[i].GetNum() << " ";
      cout << pokeDex[i].GetName() << endl;
    }
}
//Prints the MyPokemon vector
void printMyCollection(vector <MyPokemon> & myCollection){
  for(unsigned int i =0; i < myCollection.size(); i++)
    {
      cout << i << "."<< setw(10);
      cout << myCollection[i].GetNum() << setw(15);
      cout << myCollection[i].GetName() << setw(10);
      cout << myCollection[i].GetCP() << setw(10);
      cout << myCollection[i].GetHP() << setw(10);
      cout << myCollection[i].GetRarity() << endl;
    }
}
//Allows user to select the rarity of the pokemon and gives them a chance to catch them
void catchPokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
  int option, probability;
  cout << "What type of Pokemon would you like to try and catch?:" << endl;
  cout << "1. Very Common (Very High Probability)" << endl;
  cout << "2. Common (High Probability)" << endl;
  cout << "3. Uncommon (Normal Probability)" << endl;
  cout << "4. Rare (Low Probability)" << endl;
  cout << "5. Ultra-Rare (Extremely Low Probability)" << endl;
  cin >> option;
  cout << "You start to search." << endl;
  probability = rand()%100+1;
  switch(option){
  case 1:
    if(probability>=1 && probability<=65)
      {foundPokemon(option,pokeDex,myCollection);}
    else
      {cout << "Didnt find a Pokemon, better luck next time!" << endl;}
    break;
  case 2:
    if(probability>=1 && probability<=45)
      {foundPokemon(option,pokeDex,myCollection);}
    else
      {cout << "Didnt find a Pokemon, better luck next time!" << endl;}
    break;
  case 3:
    if(probability>=1 && probability<=25)
      {foundPokemon(option,pokeDex,myCollection);}
    else
      {cout << "Didnt find a Pokemon, better luck next time!" << endl;}
    break;
  case 4:
    if(probability>=1 && probability<=10)
      {foundPokemon(option,pokeDex,myCollection);}
    else
      {cout << "Didnt find a Pokemon, better luck next time!" << endl;}
    break;
  case 5:
    if(probability==1)
      {foundPokemon(option,pokeDex,myCollection);}
    else
      {cout << "Didnt find a Pokemon, better luck next time!" << endl;}
    break;
  }
}
//Once user has found a Pokemon, this function adds it to their collection
void foundPokemon(int rarity, vector<Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
 int i; 
 do{
     i = rand()%POKECOUNT;
   }while(pokeDex[i].GetRarity() != rarity);

 if(pokeDex[i].GetRarity() == rarity)
   {cout << "Congrats! You found a " << pokeDex[i].GetName() << endl;}

 int num = pokeDex[i].GetNum();
 string name = pokeDex[i].GetName();
 int CP = rand()%(pokeDex[i].GetCPMax()+pokeDex[i].GetCPMin());
 int HP = (CP/10);
 MyPokemon MyPokemon(num,name,CP,HP,rarity);
 myCollection.push_back(MyPokemon);
}

void mainMenu(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
  int option = 0;
  bool isExit = 0;
  do {
    do {
      cout << "What would you like to do?: " << endl;
      cout << "1. See the PokeDex" << endl;
      cout << "2. See your collection" << endl;
      cout << "3. Search for a new Pokemon" << endl;
      cout << "4. Battle Your Pokemon" << endl;
      cout << "5. Train your Pokemon" << endl;
      cout << "6. Exit" << endl;
      cin >> option;
    }while(option < 1 || option > 6);
  
    switch(option){
    case 1:
      printPokeDex(pokeDex);
      break;
    case 2:
      printMyCollection(myCollection);
      break;
    case 3:
      catchPokemon(pokeDex,  myCollection);
      break;
    case 4:
      battlePokemon(pokeDex, myCollection);    
      break;
    case 5:
      trainPokemon(pokeDex, myCollection);
      break;
    case 6:
      exitPokemon(myCollection);
      isExit = 1;
    }
  }while(isExit == 0);
}
//Allows user to battle their pokemon against a random pokemon
 void battlePokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
   int i = rand()%POKECOUNT+1, choice;
   int enemyCP = rand()%(pokeDex[i].GetCPMax()+pokeDex[i].GetCPMin());
   printMyCollection(myCollection);
   cout << "You are going to fight a " << pokeDex[i].GetName() << endl;
   cout << "The enemy has a CP of " << enemyCP << endl;
   cout << "Which of your Pokemon would you like to use?:" << endl;
   cin >> choice; 
   if(myCollection[choice].GetCP() > enemyCP)
     {cout << "You Won!!" << endl;}
   else
     {cout << "You Lost." << endl;}
}
//Add 10 CP to Pokemon selected
 void trainPokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
   int choice;
   cout << "Which of your Pokemon would you like to use?:" << endl;
   printMyCollection(myCollection);
   cin >> choice;
   myCollection[choice].Train();
   cout << "Your " << myCollection[choice].GetName() << " trained." << endl;
   cout << "Your CP is now " << myCollection[choice].GetCP() << "." << endl;
}

 void exitPokemon(vector<MyPokemon> & myCollection){
   saveMyCollection(myCollection);
   cout << "File Saved" << endl;
   cout << "Thank you for playing Pokemon UMBC" << endl;
}
//Writes the vector to myCollection.txt
void saveMyCollection(vector<MyPokemon> & myCollection){
  ofstream outStream;
  outStream.open(MYCOLLECTION);
  for(unsigned int i = 0; i<myCollection.size(); i++)
    { 
      outStream << setw(10) << myCollection[i].GetNum()<< setw(10) << myCollection[i].GetName()<< setw(10);
      outStream << myCollection[i].GetCP()<< setw(10) << myCollection[i].GetHP()<< setw(10);
      outStream << myCollection[i].GetRarity()<< setw(10) << endl;
    }
  outStream.close();
}
