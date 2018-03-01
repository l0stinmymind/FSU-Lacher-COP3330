#include <iostream>
#include <cstringdiff.h>
class ID
{
 public:
  ID();
  ID(const char* x, int y);
  ~ID();
  ID (const ID&);
  const ID &operator=( const ID& );
  void SetName (const char*);
  void SetAge (int);
  const char* GetName () const;
  int GetAge() const;

 private:
  char* name_;
  int age_; 
};
std::ostream& operator << (std::ostream& os, ID& after);
std::istream& operator>> ( std::istream& is , ID& id );
bool          operator<  ( const ID& id1 , const ID& id2 );
