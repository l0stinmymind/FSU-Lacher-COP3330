#include <iostream>

class ID
{
 public:
  ID();
  ID(const char* x, int y);
  ~ID();
  ID (const ID&);
  const ID &operator=( const ID& );
  friend std::ostream& operator << (std::ostream& os, ID& after);
  void SetName (const char*);
  void SetAge (int);
  const char* GetName () const;
  int GetAge() const;
  
 private:
  char* name_;
  int age_; 
};
