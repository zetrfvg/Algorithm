/*
能种就种，贪
*/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int res=0;
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]) continue;
            if(i&&flowerbed[i-1]) continue;
            if(i<flowerbed.size()-1&&flowerbed[i+1]) continue;
            res++;
            flowerbed[i]=1;
        }
        return res>=n;
    }
};
