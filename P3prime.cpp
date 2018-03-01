#include <cstddef>
#include <iostream>
#include <stdio.h>     
#include <math.h>
#include <prime.h>

Prime::Prime(size_t ub) : bv_(ub+1)
{
  Sieve();
}

Prime::Prime(const Prime& p) : bv_(p.bv_)
{
} 

Prime& Prime::operator = (const Prime& p)
{
  if (this != &p)
  {
    bv_ = p.bv_;
  }
  return *this;
}

Prime::~Prime()
{

}

size_t Prime:: Largest(size_t ub) const
{
  size_t largest = 0;
  if (ub > bv_.Size())
  {
    ub = bv_.Size();
  }

  for (size_t i = 0; i <= ub; i++)
  {
    if (bv_.Test(i))
    {
      largest = i;
    }
  }
  return  largest;
}

void Prime::All(size_t ub, std::ostream& os) const
{
  if (ub > bv_.Size())
  {
    ub = bv_.Size();
  }

  for (size_t i = 0; i <= ub; i++)
  {
    if (bv_.Test(i))
    {
      os << bv_.Test(i) << " ";
    }
  }
}

void Prime::All(std::ostream& os) const
{
  for (size_t i = 0; i <= bv_.Size(); i++)
  {
    if (bv_.Test(i))
    {
      os << bv_.Test(i) << " ";
    }
  }
}

size_t Prime::UpperBound() const
{
  return bv_.Size();
}

void Prime::ResetUpperBound(size_t ub)
{
  bv_.Expand(ub);
}

void Prime::Dump(std::ostream& os) const
{
  bv_.Dump(os);
}

void Prime::Sieve()
{
  bv_.Set();
  bv_.Unset(0);
  bv_.Unset(1);

  for (size_t i = 2; i < sqrt(bv_.Size()); i++)
  {
    bv_.Set(i);

    for (size_t j = i + i; j < bv_.Size(); j++)
    {
      bv_.Unset(j);
    }
  }
}
