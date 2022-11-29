#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<int>> arr;
queue<int> q;
stack<int> s;
vector<int> answer;

void DFS(int n, bool taken[]){
    
    int standardNumber;
    int nextP;
    standardNumber = s.top();
    
    if(s.empty())
        return;
    else{
        s.pop();
        if(taken[standardNumber-1] == false){
            answer.push_back(standardNumber);
            taken[standardNumber-1] = true;
            for(int i = 0 ; i < arr[standardNumber-1].size() ; i++){
                s.push(arr[n-1][i]);
            }
        }
        
        if(!s.empty())
            nextP = s.top();
        else
            return;
        
    }
    
    DFS(nextP, taken);
    
}
void BFS(int n, bool taken[]){
    int standardNumber;
    standardNumber = q.front();
    int nextP;
    
    if(q.empty())
        return;
    else{
        q.pop();
        if(taken[standardNumber-1] == false){
            answer.push_back(standardNumber);
            taken[standardNumber-1] = true;
            for(int i = 0 ; i < arr[standardNumber-1].size() ; i++){
                q.push(arr[n-1][i]);
            }
        }
        
        if(!q.empty())
            nextP = q.front();
        else
            return;
    }
    BFS(q.front(), taken);
    
}
int main(void){
    
    int N;
    int V;
    int M;
    
    cin >> N;
        cin >> M;
        cin >> V;
        
        int a,b;
        bool taken[N];
        
        for(int i = 0 ; i < N ; i++){
            taken[i] = false;
        }
    arr.resize(N);
    
        while(M--){
            
            cin >> a >> b;
            
            if(a != b){
                arr[a-1].push_back(b);
                arr[b-1].push_back(a);
            }
            else{
                arr[a-1].push_back(b);
            }
            
            
        }

    
    for(int i = 0 ; i < arr.size() ; i++){
        sort(arr[i].rbegin() , arr[i].rend());
    }
    
    
    s.push(V);
    
    q.push(V);
    for(int i = 0 ; i < N ; i++){
        taken[i] = false;
    }
    DFS(V, taken);
    for(auto i : answer)
        cout << i << " ";
    
    cout << '\n';
    answer.resize(0);
    for(int i = 0 ; i < N ; i++){
        taken[i] = false;
    }
    for(int i = 0 ; i < arr.size() ; i++){
        sort(arr[i].begin() , arr[i].end());
    }
    
    BFS(V, taken);
    for(auto i : answer)
        cout << i << " ";
}