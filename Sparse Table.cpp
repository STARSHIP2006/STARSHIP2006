//query to find the minimum of in a range
#define N 1000
int lookup[N][10]; // Assuming log(N) = 10 (you might need to adjust this for larger N)

// Function to build the sparse table
void buildSparseTable(int arr[], int n) 
{ 
    // Initialize the table for the intervals with length 1
    for (int i = 0; i < n; i++) 
        lookup[i][0] = arr[i];
    
    // Compute values from smaller to larger intervals
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; (i + (1 << j) - 1) < n; i++) {
            lookup[i][j] = min(lookup[i][j-1], lookup[i + (1 << (j-1))][j-1]);
        }
    }
}

// Function to perform a range minimum query using the sparse table
int query(int L, int R) 
{
    int j = log2(R - L + 1);
    return min(lookup[L][j], lookup[R - (1 << j) + 1][j]);
}
