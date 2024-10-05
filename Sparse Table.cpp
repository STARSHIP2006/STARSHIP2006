# define N 1000
int lookup[N][N];
void buildSparseTable(int arr[], a,b, int n) 
{ 
    // Initialize M for the intervals with length 1 
    for(int i=1; i<=n; i++)
          lookup[i][i]=arr[i][i];
    for(int j=1; (1<<j)<=n; j++)
        continue;
    j--;
    for(int i=2; i<=(1<<j); i*=2)
    {
        int w=(i-1)/2;
        lookup[a][a+i-1]=min(lookup[a][a+w-1],lookup[a+w][a+i-1]);
    }
} 

