
#ifndef _NUMBER_HEADER
#define _NUMBER_HEADER

class Number {
  int value;
  int dncMask;

  inline int charValue(char c) const;
  inline bool isDNC(char c) const;

 public:  
  Number(int value=0, int mask=0);
  Number(const char* str, int base);

  operator int() const;

  unsigned int getDNCMask() const;

  Number operator|(const Number&) const; //ZY
  Number operator&(const Number&) const; //ZY
  Number operator>>(const int &)  const; //ZY
  Number operator<<(const int &) const; //ZY
  Number operator+(const Number&) const;
  Number operator-(const Number&) const;
  Number operator*(const Number&) const;
  Number operator/(const Number&) const;

};

#endif
