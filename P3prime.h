#include <bitvect.h>

class Prime
{
public:
  Prime (size_t);
  Prime(const Prime& p);
  ~Prime();
  Prime& operator = (const Prime& p);
  size_t     Largest           ( size_t ub ) const;
  void       All               ( size_t ub , std::ostream& os = std::cout ) const;
  void All(std::ostream& os = std::cout) const;
  size_t UpperBound() const;
  void ResetUpperBound(size_t ub);
  void Dump(std::ostream& os = std::cout) const;
private:
  fsu::BitVector bv_;
  void Sieve();
};
