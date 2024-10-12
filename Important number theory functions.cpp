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

//sieve of eratorthenos
vector<int> factors (int n)
{
    vector<bool> prime(n + 1, true);
    vector<int> v;
    for (int p = 2; p * p <= n; p++) 
    {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])
            v.push_back(p);
    return v;//contains all primes <=n
}
