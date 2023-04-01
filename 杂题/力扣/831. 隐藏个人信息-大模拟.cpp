class Solution {
public:
    string maskPII(string s){
        auto email=[](string s){
            for(auto &c:s) if(c>='A'&&c<='Z') c^=32;
            string res;
            int pos=0,n=s.size();
            while(s[pos]!='@') pos++;
            res+=s[0];
            res+="*****";
            res+=s[pos-1];
            while(pos<n) res+=s[pos++];
            return res;
        };
        auto phone=[](string s){
            string res,num;
            for(auto c:s) if(isdigit(c)) num+=c;
            int n=num.size();
            if(n==11) res="+*-";
            if(n==12) res="+**-";
            if(n==13) res="+***-";
            for(int i=n-10,j=1;i<n;i++,j++){
                if(j<=6) res+='*';
                else res+=num[i];
                if(j<=6&&j%3==0) res+='-';
            }
            return res;
        };
        int type=1;
        for(auto c:s) if(c=='@') type=2;
        if(type==1) return phone(s);
        else return email(s);
    }
};
