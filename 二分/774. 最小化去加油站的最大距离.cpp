/*
二分答案
*/
class Solution {
public:
    const double eps=1e-8;
    double minmaxGasDist(vector<int>& stations, int k) {
        double l=0,r=1e8;
        auto check=[&](double m){
            int cnt=0;
            for(int i=1;i<stations.size();i++){
                cnt+=(int)((stations[i]-stations[i-1])/m);
            }
            return cnt<=k;
        };
        while(r-l>eps){
            double m=(l+r)/2.0;
            if(check(m)) r=m;
            else l=m;
        }
        return l;
    }
};
