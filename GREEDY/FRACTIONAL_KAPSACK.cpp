//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
         sort(arr, arr + n, [](Item a, Item b) {
            double r1 = (double)a.value / a.weight;
            double r2 = (double)b.value / b.weight;
            return r1 > r2;
        });
        // Your code here
        double total_till_now_profit=0.0;
        int curr_wt=0;
        for(int i=0;i<n;i++)
        {
            if(w>=arr[i].weight+curr_wt)
            {
                total_till_now_profit+=arr[i].value;
                curr_wt+=arr[i].weight;
            }
            else
            {
                double weight_i_can_use=w-curr_wt;
                total_till_now_profit+=((double)arr[i].value/arr[i].weight)*weight_i_can_use;
                break;
            }
        }
        return total_till_now_profit;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
