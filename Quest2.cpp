// There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
 
// In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
 
// Your score is the sum of the points of the cards you have taken.
 
// Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
 
// Example 1:
// Input: cardPoints = [1,2,3,4,5,6,1], k = 3
// Output: 12
 
// Example 2:
// Input: cardPoints = [2,2,2], k = 2
// Output: 4
 
// Example 3:
// Input: cardPoints = [9,7,7,9,7,7,9], k = 7
// Output: 55

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;  // size of card array
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    int k;
    cin>>k;

    int st = 0, en = n-1, cnt = 0, maxPts = 0;
    while(cnt != k && st < n && en > 0){
        if(cnt == k)
            break;
        if(v[st] > v[en]){
            maxPts += v[st++];
            cnt++;
        }else{
            maxPts += v[en--];
            cnt++;
        }
    }

    cout<<maxPts;

    return 0;
}