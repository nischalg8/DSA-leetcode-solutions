#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string processStr(string s) {
        string result;
        
        for(char x:  s)
        {
            if(x == '*'){
              if(!result.empty())
                result.pop_back();
            }
            else if(x=='#')
                result.append(result);
            else if(x=='%')
                reverse(result.begin(), result.end());
            else 
                result+=x;

        }
        return result;
    }
};

int main()
{
    Solution sol;

    cout<<sol.processStr("z*#")<<endl;
    cout<<sol.processStr("a#b%*")<<endl;
    cout<<sol.processStr("abcde")<<endl;
    cout<<sol.processStr("abcd%##")<<endl;
    return 0;
}