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
    cout << "Enter the number of children: ";
    cin>> sizeOfG;
    vector<int>g(sizeOfG);

    cout << "Enter the greed factors of the children: ";
    for (int i = 0; i < sizeOfG; i++) {
        cin >> g[i];
    }

    cout << "Enter the number of cookies: ";
    cin >> sizeOfS;
    vector<int>s(sizeOfS);

    cout << "Enter the sizes of the cookies: ";
    for (int i = 0; i < sizeOfS; i++) {
        cin >> s[i];
    }

    int solution = maxNumberOfContentChildren(g,s);
    cout << "The maximum number of content children is: " << solution << endl;

    return 0;
}
