class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int a=max(0,accumulate(energy.begin(),energy.end(),0)-initialEnergy+1);
        int b=0;
        for(int i=0;i<experience.size();i++){
            if(initialExperience<=experience[i]){
                b+=experience[i]-initialExperience+1;
                initialExperience=experience[i]+1;
            }
            initialExperience+=experience[i];
        }
        return a+b;
    }
};
