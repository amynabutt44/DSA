//{ Driver Code Starts
#include <iostream>
#include <queue>

using namespace std;


// } Driver Code Ends
class Solution
{
public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long >, greater<long long>> qp;
        for (int i = 0; i < n; i++)
        {
            qp.push(arr[i]);
        }
        long long  cost = 0;

        while (qp.size() > 1)
        {
            long long a = qp.top();
            qp.pop();
            long long b = qp.top();
            qp.pop();
            long long  sum = a + b;
            cost += sum;
            qp.push(sum);


        }
        return cost;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends