// question link : https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include<iostream>
using namespace std;
#include<vector>



void solve(vector<vector<int>> &m, int n, int i, int j, string temp, vector<vector<bool>> &visited, vector<string> &ans){
    if(i == n-1 && j == n-1){
        ans.push_back(temp);
        return;
    }
    visited[i][j] = true;
        
    if(j-1>=0 && !visited[i][j-1] && m[i][j-1]==1){
        visited[i][j] = true;
        solve(m, n, i, j-1, temp+'L', visited, ans); //left
        visited[i][j] = false;
    }
        
    if(i-1>=0 && !visited[i-1][j] && m[i-1][j]==1){
        visited[i][j] = true;
        solve(m, n, i-1, j, temp+'U', visited, ans); //up
        visited[i][j] = false;
    }
    if(i+1<n && !visited[i+1][j] && m[i+1][j]==1){
        visited[i][j] = true;
        solve(m, n, i+1, j, temp+'D', visited, ans); //down
        visited[i][j] = false;
    }
        
    if(j+1<n && !visited[i][j+1] && m[i][j+1] == 1){
        visited[i][j] = true;
        solve(m, n, i, j+1, temp+'R', visited, ans); //right
        visited[i][j] = false;
    }
    visited[i][j] = false;
}
vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<string> ans;
    if(m[0][0] == 1)
        solve(m, n, 0, 0, "", visited, ans);
        return ans;
    }