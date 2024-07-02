// If the numbers to are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 
// If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
 
 
// NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

#include <bits/stdc++.h>
using namespace std;

int main()
{
     map<int, string> mp = {{1 , "one"}, {2,"two"}, {3,"three"}, {4,"four"}, {5,"five"}, {6,"six"}, {7,"seven"}, {8,"eight"},{9,"nine"}, {10,"ten"}, {11,"eleven"}, {12,"twelve"}, {13,"thirteen"}, {14,"fourteen"}, {15,"fifteen"}, {16,"sixteen"}, {17,"seventeen"}, {18,"eighteen"}, {19,"nineteen"}, {20,"twenty"}, {30,"thirty"}, {40,"fourty"}, {50,"fifty"}, {60,"sixty"}, {70,"seventy"}, {80,"eighty"},{ 90,"ninty"}};
    
    int n;
    cin>>n;
    if(n == 1000){
        cout<<11<<endl;
        return 0;
    }
    
    int letters_used = 0, cnt = 0;
    if(mp.find(n) != mp.end()){
        letters_used += mp[n].size();
        cout<<letters_used;
        return 0;
    }
    int last_two = n % 100;
    if(mp.find(last_two) != mp.end()){
        letters_used += mp[last_two].size();
    }else{
        int t = last_two;
        int unitPlace = t % 10;
        t = t / 10;
        int tenPlace = t % 10;
        tenPlace = tenPlace * 10;
        letters_used += mp[unitPlace].size();
        letters_used += mp[tenPlace].size();
    }
    
    n = n / 100;
    if(n > 0){
        cnt++;
        letters_used += mp[n].size();
        letters_used += 7;  // hundred
    }
    
    if(cnt > 0)  // 3 digit number
        letters_used += 3;  // handling case when "and" is used
    cout<<letters_used<<endl;
    return 0;
}