#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    bool checkSubstring(string &s, string &w)
    {
        int i{},j{};
   
        int start=0;
        while(start+s.size() <= w.size())
        {           int i = 0;
                    int j = start;
                   
                    while(i<s.size() && j<w.size() && s[i] == w[j])
                    {
                        
                        i++;
                        j++;

                    }
                    if(i==s.size())
                        return true;
                                 
                    start++;
        
        }
        return false;
    }
public:
    int numOfStrings(vector<string>& patterns, string word) {

            int num=0;
            for(string &s: patterns)
            {
                if(checkSubstring(s, word)){
                   // cout<<"True for "<<s<<endl;
                    num++;
                }
              //  else
                    //cout<<"False for "<<s<<endl;
            }
            return num;
    }
};
class Solution2{
    public:
    int numOfStrings(vector<string>& patterns, string word){
        int num=0;
        for(string& s: patterns)
        {   //npos is the value returned by member functions when they fail
            if(word.find(s) != string::npos)
                num++;
        }
        return num;
    }
};
int main()
{
        Solution2 sol;
        vector<pair<vector<string>, string>> testCases ={          
            {{"a","abc","bc","d"}, "abc"},
            {{"a","b","c"}, "aaaaabbbbb"},
            {{"a","a","a"}, "ab"},
            {{"hvzoo","r","hyjcrgzr","yvqahvz","org","yvqahvz","org","oor","gxe","zo","ahvzoo","ahvzo","r","o","caviikty","pkxlcaams"},"tyvqahvzoorg"},
            {{"e","ulhjriiikuwwi","odtbmiyiv","iiku","o","nao","ilrbdhfvndjaxohexcynpgocoqorifjngaurokumcqqkirqp","zmt","tuxulhjriiikuwwibjpodtbmiyiv","lhjriiikuwwibjpodtbmiyi","qjnwwkfqhztiyqayiabjjzyqhumh","lhjriiikuwwibjpodtbmiyiv","oyaloibpkqpyubftinknjraptsuqgejucpfigc","fdqvajkfornietcdvxltbktlkg","bcxslqwrjaabvywpynzfojetmnnwrurimjgwl","ncvvyhbznxrxoonfrzfmecfdnrvikffpvrc","gxvzmtuxulhjriiikuwwibjpodtbmiyi","ozuwzgetoddakvjwiwzocpwpiavcyclxhlguhfqtpbk","ktwqukguxobakxvbitkkdemvlmqypd","gxvzmtuxulhjri","xulhjriiiku","sjemhhtbqastmbtbvsfnuygqfypmmi","gqfmyqbjcvuxsjdaeffwthlelb","kuwwibjpodtbmiyivse","ydwiabsimbkdwmsvgp","ixrzoktohtadgblem","uicfykignmptxodjd","kecqujgjynq","sruqpwjevngokrbyi","rijyzrhrygxvzmtuxulhjriii","gsljxjrmkzbwaqdgmwysnblp","arkmbbafkziemddeqripnyjoavmoaxtn","gxhijktottj","ibjpodtbmiyivse","j","qzvmjstehwibuqcqlzdam","ikuwwibjpodt","mnrp","pduagikyudhcvdnqoaadqvvmhluywfsstqnawfmq","vse","iyiv","miyivs","qdfrbkhffkksgtjpnbgvqtrnigbnoacmqkepllouhqpgskpupy","wxbqfmzvmmffwtwjhjpuitcfmknnuwdtamtutiukmpsxzu","odtbmiyi","hrygxvzmtuxulhjriiiku","yzrhrygxvzmtuxu","se","gixgfjtunbltzcwgkrheavilcvektnsizvrrabmysx","hjriiikuwwibj","ahaeorlnaqkk","gvnyr","tynqzmrvdjaznuji","jbwybcttaspwsbieawybfqxsiwxulwkouezkhbauadatb","uwwibjpodt","gxv","zrhrygxvzmtuxulhjriiikuwwib","wivvuywmwchszzctw","lijcroypqr","mrx","m","ygngqghhza","riiikuwwibjpodtbmiyivs","tymtjqykindweexrfztizyagijnxntrcrcy","vse","kntxszudqpmtlrxzspcfivbrwonejzywv","ygxvzmtuxulh","wsnnrijyzrhrygxvzmtuxulhjriiik","zpymedyxskwqddvxlycxvq","qdkm","gxvzmtuxu","snnrijyzrhrygxvzmtuxulhjriiikuwwibjpo","iyivserr","yzrhrygxvzmt","rygxvzmtuxulhjrii","snnrijyzrhrygxvzmtuxul","gxvzmtuxulhjriiikuwwibjpodtbmiyivserr","kuwwibjpodt","ibjpodtbmiy","mtuxulhjriii","zrhrygxvzmtu","qxjvgdyuqt","rygxv","gnwmvzqhrodzqdvdexgupqbzogcpmtfq","oleibiotmojkqexnnlx","dtb","jjividhfhdixcvyduyunoiiipyvi","podtb","jpodtbmiyi","iiku","od","kuwwibjpodtb","b","irugjrzvsfp","wsnnrijyzrhrygxvzmtuxulhjrii","jriiikuwwibjpodtbmi"}, "wsnnrijyzrhrygxvzmtuxulhjriiikuwwibjpodtbmiyivserr"}
        };
        for(auto& [pattern, word]: testCases)
        {
            cout<<sol.numOfStrings(pattern, word)<<endl;
        }
}