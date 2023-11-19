// C++ implementation of the above approach
#include <bits/stdc++.h>
using namespace std;
 
// Macro for vector of pair to store
// each node with edge
#define vp vector<pair<int, float> >
 
// Function to calculate the
// probability of reaching F
// at time T after starting
// from S
float findProbability(vector<vp>& G, int N,
                      int F, int S, int T)
{
    // Declaring the DP table
    vector<vector<float> > P(N + 1, vector<float>(T + 1, 0));
 
    // Probability of being at S
    // at t = 0 is 1.0
    P[S][0] = 1.0;
 
    // Filling the DP table
    // in bottom-up manner
    for (int i = 1; i <= T; ++i)
        for (int j = 1; j <= N; ++j)
            for (auto k : G[j])
                P[j][i] += k.second * P[k.first][i - 1];
 
    return P[F][T];
}
 
// Driver code
int main()
{
    // Adjacency list
    int N = 3;
    vector<vp> G(N+1);
 
    // Building the graph
    // The edges have been stored in the row
    // corresponding to their end-point
    G[1] = vp({ { 3, 0.5 } });
    G[2] = vp({{3,0.5},{1,0.5}});
    G[3] = vp({{2,1},{1,0.5}});
 
 
    int S = 1, F = 1, T = 100;
 
    cout << "The probability of reaching " << F
         << " at time " << T << " \nafter starting from "
         << S << " is " << findProbability(G, N, F, S, T);
 
    return 0;
}
