#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/* My solution but has higher space complexity
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> charMap1, charMap2;
        if (s.size()!= t.size() ) return false;
        
        for (size_t i = 0; i < s.size(); i++) {
            charMap1[s[i]]++;
             
    
        }
        for (size_t i = 0; i < s.size(); i++) {
            charMap2[t[i]]++;
             
    
        }
        for(size_t i =0; i<s.size(); i++)
        {
            if(charMap1[s[i]] != charMap2[s[i]]){
                return false;
            } 
          
        }
        
        return true;
       
    }
};
*/
class Solution{
public: 
bool isAnagram(string s, string t){
    int countArr[26]={0};

    if(s.length() != t.length()) return false;
    for(size_t i= 0; i<s.length(); i++)
    {
        countArr[s[i]-'a']++;
        countArr[t[i]-'a']--;
    }
    for(int i=0; i<26; i++)
    {
        if(countArr[i] !=0)
        {
            return false;
        }
    }
    return true;
}

};

int main() {
    Solution sol;
    string s1="cat";
    string t1="tac";
    string s2="silente";
    string t2="liseent";
    string s3="troop";
    string t3="prout";
    
    cout<<"For 1   "<<sol.isAnagram(s1, t1)<<endl;
    cout<<"For 2   "<<sol.isAnagram(s2, t2)<<endl;
    cout<<"For 3   "<<sol.isAnagram(s3, t3)<<endl;

  

    
}
