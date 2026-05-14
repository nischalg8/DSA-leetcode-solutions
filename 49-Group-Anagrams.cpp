#include <iostream>
#include <vector>
#include <unordered_map> 
#include <algorithm>

using namespace std;


//-----------First Approach (Brute Force).......This approach is O(n^2 k)  k=> avg leng of each string 
class Solution1
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> groupedAnagrams;
        vector<bool> processed(strs.size(), false);
        unsigned short x = 0;
      
        //nested loop is O(n^2) and isAnagram function is O(k) compmlexity 
        for (size_t i = 0; i < strs.size(); i++)
        {
            if (processed[i])
            {
                continue;
            }
            groupedAnagrams.push_back({});
            groupedAnagrams[x].push_back(strs[i]);
            
            for (size_t j = 0; j < strs.size(); j++)
            {

                if (i == j ) continue;
                if(processed[j]) continue;

                //isAnagram function is O(k) copmlexity  
                bool anagrams = isAnagram(strs[i], strs[j]);
                if (anagrams)
                {
                    groupedAnagrams[x].push_back(strs[j]);
                    processed[j] = true;
                }
            }
            x++;
            processed[i] = true;
        }
        return groupedAnagrams;
    }
    bool isAnagram(string s, string t)
    {

        unsigned short countArr[26] = {0};

        if (s.length() != t.length())
            return false;
        for (size_t i = 0; i < s.length(); i++)
        {
            countArr[s[i] - 'a']++;
            countArr[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (countArr[i] != 0)
                return false;
        }

        return true;
    }
};




//  Second Approach ------ Sorted String Hashing (O(klogk) * O(n)) klogk for sorting and n for no. of strings 
class Solution2
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for(string s: strs)
        {
            string key = s;
            sort(key.begin(), key.end());

            mp[key].push_back(s);
        }
        vector<vector<string>> result;
        for(auto& it: mp)
        {
            result.push_back(it.second);
        }
        return result;
    }

 
    
};


/*      
    NOTE:::: As there are short string in test cases of leetcode so second approach takes less time 
    even though theoretically third approach has lower time complexity O(nk) compared O(klogk . n)  
*/


/*... Third Approach Frequency Based Hashing  O(n.k)*/
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        // building the map with the frequency array as key
        for(string s: strs)
        {
            int freqArr[26] ={0};
            //building the count of each alphabets
            for(char c: s)
            {
                freqArr[c-'a']++;
            }
            // 
            string key;
            for(int i=0; i<26; i++)
            {
                key+='#'+to_string(freqArr[i]);
            }
            mp[key].push_back(s);

        }
            // putting the vectors of the map into result nested vector
        vector<vector<string>> result;
        for(auto& it: mp)
        {
            result.push_back(it.second);
        }
        return result;
    }

    
};

void printResult(vector<vector<string>> &result) {
    for (size_t i = 0; i < result.size(); i++) {
        cout << "[ ";
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "]\n";
    }
    cout << "----------------------\n";
}

int main() {

    Solution sol;

    // list of test cases
    vector<vector<string>> testCases = {

        {"eat", "tea", "tan", "ate", "nat", "bat", "tab", "silent", "listen", "enlist", "rat", "tar"},

        {"a"},

        {"abc", "def", "ghi"},

        {"eat", "tea", "eat"},

        {"", "", ""},

        {"", "a", "", "a"},

        {"a", "b", "a"},

        {"abc", "bca", "cab", "acb", "bac", "cba"},

        {"eat", "tan", "ate", "nat", "bat"}

    };

    // run all test cases
    for (size_t i = 0; i < testCases.size(); i++) {

        cout << "Test Case " << i + 1 << ":\n";

        vector<vector<string>> result = sol.groupAnagrams(testCases[i]);

        printResult(result);
        cout<<typeid(result).name()<<endl;
    }

    return 0;
}