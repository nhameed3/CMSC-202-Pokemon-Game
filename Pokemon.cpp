// File: Pokemon.cpp
// Implementation of Pokemon class.
#include "Pokemon.h"
Pokemon::Pokemon(int num, string name, int cpMin, int cpMax, int rarity)
{
  m_Num = num;
  m_Name = name;
  m_MinCP = cpMin;
  m_MaxCP = cpMax;
  m_Rarity = rarity;
}
// ------------------------- Accessors --------------------------
int Pokemon::GetCPMin(){
  return m_MinCP;
}

int Pokemon::GetCPMax(){
  return m_MaxCP;
}

int Pokemon::GetRarity(){
  return m_Rarity;
}

string Pokemon::GetName(){
  return m_Name;
}

int Pokemon::GetNum(){
  return m_Num;
}

//---------------------------Mutators---------------------
void Pokemon::SetRarity(int newRarity){
  m_Rarity = newRarity;
}

void Pokemon::SetName(string newName){
  m_Name = newName;
}

void Pokemon::SetCP(int newCP){
  m_MaxCP = newCP;
  m_MinCP = newCP;
}
