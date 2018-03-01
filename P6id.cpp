
#include <id.h>
#include <iomanip>
#include <string.h>
#include <stdio.h> 
#include <iostream>
#include <string>

ID::ID(): name_ (new char ('#')), age_(-1) 
{
}

ID::ID(const char* x , int y)
{
  name_ = new char(strlen(x));
  SetName(x);
  SetAge(y);
}

ID::~ID()
{
  delete name_;
}

ID::ID (const ID& origin)
{
  name_ = new char();
  SetName(origin.GetName());
  SetAge (origin.GetAge());
}

const ID &ID::operator=(const ID& copy)
{
  if (this != &copy)
  {
    this -> SetName (copy.GetName());
    this -> SetAge (copy.GetAge());
  }
  return *this;
}

std::ostream& operator << (std::ostream& os, ID& after)
{
  os  << std::setw(9) << std::left;
  os << after.GetName();
  os << std::setw(8) << std::left;
  os << after.GetAge();  
  return os;
}

std::istream& operator >> ( std::istream& is , ID& id )
{
  size_t i = 121;
  int number;
  char *buffer = new char[i];
  is >> std::setw(i) >>buffer >>  number;
  buffer[120] = '\0';
  id.SetName(buffer);
  id.SetAge(number);
  delete [] buffer;
  return is;
}

bool operator < (const ID& id1, const ID& id2)
{
  int d = DictionaryDiff( id1.GetName() , id2.GetName() );
  if (d < 0)
  {
    return true;
  }
  if (d > 0)
  {
    return false;
  }
  if (d == 0)
  {
    return (id1.GetAge() < id2.GetAge());
  }
  return d;
}

void ID::SetName ( const char* setNamePtr)
{
  strcpy ( name_,setNamePtr);
}

void ID::SetAge (int ager)
{
  age_ = ager;
}

const char* ID:: GetName() const
{
  return name_;
}

int ID::GetAge() const
{
  return age_;
}
