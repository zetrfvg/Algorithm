/*
排序后贪心，每次选取最小的行星碰撞
*/
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            if(mass>=asteroids[i]) mass=min(1LL*mass+asteroids[i],1LL*INT_MAX);
            else return false;
        }
        return true;
    }
};
