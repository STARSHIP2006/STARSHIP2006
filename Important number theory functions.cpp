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

//modular exponentiation
int modularExponentiation(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;  // In case base is larger than mod

    while (exp > 0) {
        // If exp is odd, multiply base with result
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        
        // exp must be even now
        exp = exp / 2;
        base = (base * base) % mod;  // Square the base
    }

    return result;
}



// it doesn't actually have to be infinity or a big number
//Gauss Jordan method for solving Linear equations
int gauss (vector < vector<double> > a, vector<double> & ans) {
    double EPS = 1e-9;
    int INF = 2; 
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m]] / a[where[i]][i]];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}
