/*
哈希表，模拟，阅读理解题
*/
class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_map<int,int> p;
        unordered_set<string> pf(positive_feedback.begin(),positive_feedback.end());
        unordered_set<string> nf(negative_feedback.begin(),negative_feedback.end());
        for(int i=0;i<report.size();i++){
            string s;
            report[i]+=' ';
            if(!p.count(student_id[i])) p[student_id[i]]=0;
            for(auto c:report[i]){
                if(c==' '){
                    if(pf.count(s)) p[student_id[i]]+=3;
                    if(nf.count(s)) p[student_id[i]]--;
                    s.clear();
                }
                else s+=c;
            }
        }
        set<pair<int,int>> st;
        for(auto &[a,b]:p){
            st.insert({-b,a});
        }
        vector<int> ans;
        while(k--){
            ans.push_back((*st.begin()).second);
            st.erase(st.begin());
        }
        return ans;
    }
};
