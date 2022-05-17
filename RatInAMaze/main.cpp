// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    
    private :
    
     bool isSafe(int row, int col, int n, vector<vector<int>> &m){
         
         
         if (row < 0 || col < 0 || row >= n || col >= n || m[row][col] == 0 ){
         
             return false;
         
             
         }
         
         return true;
         
     }
     
     void ratInaMaze(int row, int col , vector<vector<int>> &m ,int n,
     vector<string> &s, string &currStr)
     {
         
         // check if the source or teh target is 0 ie blocked : 
         
         
         
         
         if (row == n-1 && col == n-1){
             s.push_back(currStr);
             return; 
         }
         
         
                         //  U ,D,L, R
         int  rowChange[] = {-1 , 1 , 0 , 0 };
         int  colChange[] = { 0 , 0 ,1 , -1 };
         char direction[] = {'U','D','R','L'};
         
         for (int i = 0;i<4;i++)
         {
             if (isSafe (row,col,n,m)){
                 
             if (isSafe (row + rowChange[i] , col + colChange[i] , n , m)){
                 
                 // add the direction to the string :
                 currStr.push_back(direction[i]);
                 
                 m[row][col] = 0;
                 
                 ratInaMaze(row + rowChange[i] , col + colChange[i] , m , n , s , currStr );
                        
                 m[row][col] = 1;
                 
                 currStr.pop_back();
             }
            }
            else return;
         }
     }
     
    public:
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<string> s;
        string currStr;
        
        ratInaMaze(0,0,m,n,s,currStr);
        
        return s;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends