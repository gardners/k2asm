#include "Number.h"

inline int Number::charValue(char c) const {
  switch(c) {
    
  case '0' : return 0;
  case '1' : return 1;
  case '2' : return 2;
  case '3' : return 3;
  case '4' : return 4;
  case '5' : return 5;
  case '6' : return 6;
  case '7' : return 7;
  case '8' : return 8;
  case '9' : return 9;
  case 'a' : return 10;
  case 'b' : return 11;
  case 'c' : return 12;
  case 'd' : return 13;
  case 'e' : return 14;
  case 'f' : return 15;
  case 'A' : return 10;
  case 'B' : return 11;
  case 'C' : return 12;
  case 'D' : return 13;
  case 'E' : return 14;
  case 'F' : return 15;
  case '.': return 0;
  case '#': return 1;
  case '?' : return 1; //ZY: to suppress random zeropage addressing

  default : return -1;
  }
}


bool Number::isDNC(char c) const {
  return c == '?';
}


Number::Number(int value, int mask): value(value), dncMask(mask) {};

Number::Number(const char* str, int base) {
  value = 0;
  dncMask = 0;
  int start=(base==10)?0:1;

  for (int i=start; str[i]; i++) {
    value *= base;
    dncMask *= base;
    
    value += charValue(str[i]);
    if (isDNC(str[i])) dncMask += base -1;
  }
}

Number::operator int() const {
  return value;
}


unsigned int Number::getDNCMask() const {
  return dncMask;
}

//ZY calculating with dnc
Number Number::operator|(const Number& n) const {
  return Number(value|n.value, dncMask|n.dncMask);
}

Number Number::operator+(const Number& n) const {
  int mask = 0;
  //if (dncMask || n.dncMask) mask = (unsigned int) -1;
  mask=dncMask|n.dncMask;   // ZY we get more ambitious!
  return Number(value+n.value, mask);
}

//ZY the following are for lowbyte,highbyte..
Number Number::operator&(const Number& n) const {
  return Number(value&n.value,dncMask&n.value); //ZY erase dnc-bits
}

Number Number::operator>>(const int& n) const {
  return Number(value>>n,dncMask>>n); //ZY shr dnc-bits
}

Number Number::operator<<(const int& n) const {
  return Number(value<<n,dncMask<<n); //ZY shl dnc-bits
}

Number Number::operator-(const Number& n) const {
  int mask = 0;
  //if (dncMask || n.dncMask) mask = (unsigned int) -1;
  return Number(value-n.value, mask);
}


Number Number::operator*(const Number& n) const {
  int mask = 0;
  //if (dncMask || n.dncMask) mask = (unsigned int) -1;
  return Number(value*n.value, mask);
}


Number Number::operator/(const Number& n) const {
  int mask = 0;
  //if (dncMask || n.dncMask) mask = (unsigned int) -1;
  return Number(value/n.value, mask);
}

char *bin(int v, char* buf) {
  int i;
  int len=16;
  
  int exp = 1;
  for (i=1; i<len; i++) exp*=2;
  for (i=0; i<len; i++) {
    buf[i] = (v & exp) ? '1':'0';
    exp/=2;
  }
  buf[i]=0;
  return buf;
}

