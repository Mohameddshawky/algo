#include "bits/stdc++.h"
using namespace std;

int maxNumberOfContentChildren(vector<int>& g, vector<int>& s){
    int contentChildrin=0;
    int i=0 , j=0;

    sort(g.begin(),g.end());
    sort(s.begin(),s.end());

    while(i<g.size() && j<s.size()){
        if(s[j] >= g[j]){
            contentChildrin++;
            i++;
        }
        j++;
    }

    return contentChildrin;

}
int main(){
    int sizeOfG, sizeOfS;
    cin>> sizeOfG;
    vector<int>g(sizeOfG);

    for (int i = 0; i < sizeOfG; i++) {
        cin >> g[i];
    }
    
    cin >> sizeOfS;
    vector<int>s(sizeOfS);

    for (int i = 0; i < sizeOfS; i++) {
        cin >> s[i];
    }

    int solution = maxNumberOfContentChildren(g,s);
    cout<< solution << endl;

    return 0;
}
