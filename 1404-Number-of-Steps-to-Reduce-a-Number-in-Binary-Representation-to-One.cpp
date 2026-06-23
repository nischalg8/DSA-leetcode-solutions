#include <iostream>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int stepCount = 0;
        while(s!="1")
        {
            char last = s.back();
            
            if(last=='1'){
                int i = s.length() -1;
                while(s != "" && s.back()!='0'){
                    stepCount++;
                    s.pop_back();
                    i--;
                }
                s[s.length()-1]=1;
            }
            else{
                stepCount++;
                s.pop_back();
            }
        }
        return stepCount;
    }
};

int main(){
    
    string s1="10";
    string s2="1101";
    Solution sol;
    cout<<sol.numSteps(s1)<<endl;
    cout<<sol.numSteps(s2)<<endl;
}