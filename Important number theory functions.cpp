//modular inverse
int inv(int a) 
{
  return a <= 1 ? a : m - (int)(m/a) * inv(m % a) % m;
}

//gcd
int gcd (int a, int b)
{
  if(a>b)
  {
    int temp=a;
    a=b;
    b=temp;
  }
  if(b%a==0) return a;
  else return gcd(b%a, a);
}
