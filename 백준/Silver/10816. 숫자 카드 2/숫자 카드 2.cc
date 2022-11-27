#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> input;
vector<int> findArray;
int a,b;

int upperNumber(int target){
    
    int first = 0;
    int last = input.size()-1;
    int mid;
    
    while(first < last){
        mid = (first + last) / 2;
        if(input[mid] > target){
            last = mid;
        }
        else{
            first = mid + 1;
        }
    }
    
    return last;
}
int lowerNumber(int target){
    int first = 0;
    int last = input.size()-1;
    int mid;
    
    while(first < last){
        mid = (first + last) / 2;
        if(input[mid] >= target){
            last = mid;
        }
        else{
            first = mid + 1;
        }
    }
    
    return last;
}
int main(void) {
   
    
    cin >> a;
    while(a--){
        int i;
        cin >> i;
        input.push_back(i);
    }
    cin >> b;
    while(b--){
        int i;
        cin >> i;
        findArray.push_back(i);
    }
  
    sort(input.begin(), input.end());
    vector<int> answer;
    for(auto i : findArray){
        int size = input.size() - 1;
        int up = upperNumber(i);
        int down = lowerNumber(i);
        if(up == size && input[size] == i){
            up += 1;
        }
        answer.push_back(up - down);
    }
    
    for(auto i: answer){
        cout << i << " ";
    }
    
}

