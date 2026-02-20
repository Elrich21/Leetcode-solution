#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {

        int a=0,b=0,c=0;
        int ans=0;

        // maps for different balance types
        unordered_map<int,int> ab;     // a-b
        unordered_map<int,int> bc;     // b-c
        unordered_map<int,int> ac;     // a-c
        unordered_map<long long,int> abc; // (a-b , a-c)

        ab[0] = bc[0] = ac[0] = -1;
        abc[0] = -1;

        for(int i=0;i<s.size();i++) {

            if(s[i]=='a') a++;
            else if(s[i]=='b') b++;
            else c++;

            int d_ab = a-b;
            int d_bc = b-c;
            int d_ac = a-c;

            long long key = ((long long)d_ab<<32) ^ (d_ac & 0xffffffff);

            // a==b
            if(ab.count(d_ab)) ans=max(ans,i-ab[d_ab]);
            else ab[d_ab]=i;

            // b==c
            if(bc.count(d_bc)) ans=max(ans,i-bc[d_bc]);
            else bc[d_bc]=i;

            // a==c
            if(ac.count(d_ac)) ans=max(ans,i-ac[d_ac]);
            else ac[d_ac]=i;

            // a==b==c
            if(abc.count(key)) ans=max(ans,i-abc[key]);
            else abc[key]=i;
        }

        return ans;
    }
};
