/*
模拟
*/
class Solution {
public:
    string categorizeBox(int a, int b, int c, int d) {
        bool f=a>=1e4||b>=1e4||c>=1e4||1LL*a*b*c>=1e9;
        bool g=d>=100;
        if(f&&g) return "Both";
        else if(f) return "Bulky";
        else if(g) return "Heavy";
        else return "Neither";
    }
};
