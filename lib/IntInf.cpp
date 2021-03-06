#include <stdio.h>
#include "IntInf.h"

namespace ece309{
  
bool IntInf::getPosInf() const{
  return posInf;
}
bool IntInf::getNegInf() const{
  return negInf;
}
int IntInf::getNum() const{
  return num;
}
IntInf& IntInf::operator=(const int& rhs){
  posInf = false;
  negInf = false;
  num = rhs;
  return *this;
}
IntInf& IntInf::operator=(const IntInf& rhs){
  num = rhs.num;
  posInf = rhs.posInf;
  negInf = rhs.negInf;
  return *this;
}
bool IntInf::operator>(const IntInf& rhs) const{
  bool rValue = false;
  //lhs is posInf and rhs is not
  if(posInf && !rhs.posInf){
    rValue = true;
  }
  //both lhs and rhs are real numbers
  if(!posInf && !rhs.posInf && !negInf && !rhs.negInf){
    rValue = num > rhs.num;
  }
  //lhs is a number and rhs is negInf
  if(!posInf && !rhs.posInf && rhs.negInf){
    rValue = true;
  }
  return rValue;
}
bool IntInf::operator<(const IntInf& rhs) const{
  bool rValue = true;
  //lhs is posInf and rhs is not
  if(posInf && !rhs.posInf){
    rValue = false;
  }
  //both lhs and rhs are real numbers
  if(!posInf && !rhs.posInf && !negInf && !rhs.negInf){
    rValue = num < rhs.num;
  }
  //lhs is a number and rhs is negInf
  if(!posInf && !rhs.posInf && rhs.negInf){
    rValue = false;
  }
  return rValue;
}
bool IntInf::operator==(const IntInf& rhs) const{
  bool rValue = false;
  if(!posInf && !negInf && !rhs.negInf && !rhs.posInf){
    rValue = num == rhs.num;
  }
  return rValue;
}
IntInf IntInf::operator/(const IntInf& rhs)const{
  IntInf ret(0,false,false);
  ret = *this;
  if(posInf && rhs.negInf){
    ret.posInf = false;
    ret.negInf = true;
  }
  else if(negInf && rhs.negInf){
    ret.posInf = true;
    ret.negInf = false;
  }
  else if(!posInf && !negInf && (rhs.negInf || rhs.posInf)){//number divide by inf
    ret.num = 0;
  }
  else if(!posInf && !negInf && !rhs.negInf && !rhs.posInf){
    ret.num = num/rhs.num;
  }
  return ret;
}
IntInf IntInf::operator*(const IntInf& rhs)const{
  IntInf ret(0,false,false);
  ret = *this;
  if(posInf && rhs.negInf){
    ret.posInf = false;
    ret.negInf = true;
    ret.num = 0;
  }
  else if(negInf && rhs.negInf){
    ret.posInf = true;
    ret.negInf = false;
    ret.num = 0;
  }
  else if(!posInf && !negInf && rhs.negInf){
    ret.posInf = false;
    ret.negInf = true;
    ret.num = 0;
  }
  else if(!posInf && !negInf && rhs.posInf){
    ret.posInf = true;
    ret.negInf = false;
    ret.num = 0;
  }
  else if(!posInf && !negInf && !rhs.negInf && !rhs.posInf){
    ret.num = num * rhs.num;
    ret.posInf = false;
    ret.negInf = false;
  }
  return ret;
}
IntInf IntInf::operator+(const IntInf& rhs)const{
  IntInf ret(0,false,false);
  ret = *this;
  if(!negInf && !posInf){
    if(rhs.negInf){
      ret.negInf = true;
      ret.posInf = false;
      ret.num = 0;
    }
    else if(rhs.posInf){
      ret.negInf = false;
      ret.posInf = true;
      ret.num = 0;
    }
    else{
      ret.negInf = false;
      ret.posInf = false;
      ret.num = num + rhs.num;
    }
  }
  return ret;
}
IntInf IntInf::operator-(const IntInf& rhs)const{
  IntInf ret(0,false,false);
  ret = *this;
  if(!negInf && !posInf){
    if(rhs.negInf){
      ret.negInf = true;
      ret.posInf = false;
      ret.num = 0;
    }
    else if(rhs.posInf){
      ret.negInf = false;
      ret.posInf = true;
      ret.num = 0;
    }
    else{
      ret.negInf = false;
      ret.posInf = false;
      ret.num = num - rhs.num;
    }
  }
  return ret;
}
void IntInf::print(){
  if(posInf){
    printf("Positive Infinity");
  }
  else if(negInf){
    printf("Negative Infinity");
  }
  else{
    printf("%d", num);
  }
  printf("\n");
}
}
