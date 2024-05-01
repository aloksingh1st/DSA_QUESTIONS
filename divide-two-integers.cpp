class Solution {
public:
  string remainder(string &s1,int num, int divisor)
{
  if(num<divisor)
  {
  s1.push_back('0');
  return to_string(num);
  }
  int diff=num;
  if(num>=divisor)
  {
    int count=0;
      while(diff>=divisor)
      {
          count++;diff=diff-divisor;
      }
      s1.insert(s1.size(),to_string(count));
  }
  return to_string(diff);
}
int divide(int dividend, int divisor) {
   int sign=0;
  if(divisor==INT_MIN){
  if(dividend==INT_MIN){
  return 1;
  }
  return 0;
  }
  if(dividend<0||divisor<0)
  {
    if(dividend<0&&divisor<0)
    {}
    else
    sign=1;
  }
  int check=0;
  if(dividend==INT_MIN)
  {
    check=1;
    dividend=abs(dividend+1);}
  else
  dividend=abs(dividend);
  divisor=abs(divisor);
  if(divisor==1)
  {
    if(sign==0)
    return dividend;
    else if(sign==1&&check==1)
    return -dividend-1;
    else
      return -dividend;
  }
  if(dividend<divisor)
  {
    return 0;
  }
   string s=to_string(dividend);
  string s1="";
  int size=to_string(divisor).size();
  string remain=s.substr(0,size-1);
  int i=size-1;
  while(i<s.size())
    {
      string s2=remain+s.substr(i,1);
      remain=remainder(s1,stoi(s2),divisor);
      i++;
    }
  if(check==1)
  {
    if(stoi(remain)+1==divisor)
    {
      if(sign==1)
        {
          return -stoi(s1)-1;
        }
        return stoi(s1)+1;
    }
  }
    if(sign==1)
  {
    return -stoi(s1);
  }
  return stoi(s1);
}
};