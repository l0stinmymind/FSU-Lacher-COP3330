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
  size_t i = 0;
  std::string temp1;
  strcpy(&temp1[0], after.GetName());
  while (i != strlen(&temp1[0]))
  {
    os << temp1[i];
    i++;
  }
  os <<std::setw(40)<<std::left<<temp1[i]<<std::setw(10)<<std::right<<after.GetAge();  
  return os;
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
