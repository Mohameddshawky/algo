#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;

int cpuTasks(vector<char>& tasks, int n) {
    priority_queue<int> pq;
    vector<int>mp(26, 0);

    for(char character: tasks){
        mp[character - 'A']++;
    }

    for(int i = 0; i < 26; i++){
        if(mp[i] > 0){
            pq.push(mp[i]);
        }
    }

    int time = 0;
    while(!pq.empty()){
        vector<int> remain;
        int cycle = n+1;

        while(cycle && !pq.empty()){
            int maxChar = pq.top();
            pq.pop();
            if(maxChar > 1){
                remain.push_back(maxChar-1);
            }
            time++;
            cycle--;
        }
        for(int e: remain){
            pq.push(e);
        }
        if(pq.empty()){
            break;   // No need to add idle time
        }
        time += cycle;  // idle time
    }
    return time;
}

int main() {
    int n;
    string input;
    cin >> input;
    vector<char> tasks(input.begin(), input.end());
    cin >> n;

    int result = cpuTasks(tasks, n);
    cout << result << endl;
    return 0;
}
