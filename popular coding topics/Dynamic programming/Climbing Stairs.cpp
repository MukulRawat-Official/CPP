/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

class Solution {
public:
    unordered_map<int,int>m;
    
    int climbStairs(int n) {
        if(n<0) return 0;
        if(n==0) return 1;
        if(m[n]==0)
            m[n] = climbStairs(n-1)+climbStairs(n-2);
        return m[n];
    }
};
