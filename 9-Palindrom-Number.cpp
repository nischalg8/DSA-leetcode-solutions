#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0) 
            return false;

        long num = 0;      
        int temp = x;     
        while (x != 0) {
            num = num * 10 + x % 10;
            x /= 10;
        }

        return num == temp;  
    }
};

int main() {
    Solution solution;
    int testCases[] = {121, -121, 12321, 10, 0};
    
    for (int x : testCases) {
        if (solution.isPalindrome(x))
            cout << x << " is a palindrome." << endl;
        else
            cout << x << " is NOT a palindrome." << endl;
    }
    
    return 0;
}
