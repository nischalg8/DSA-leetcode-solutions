#include <iostream> 
using namespace std;


class Solution1 {
public:
    int sum(int num1, int num2) {
        return num1+ num2;
    }
};
class Solution2 {
public:
    int sum(int num1, int num2) {
        if(num2==0)
            return num1;
        
        else 
            // xor represents the bit (if opposite then sum will be 1 if same then sum will be 0 (for 1 and 1 the sum is 0 with borrow 1 ))
            // and represents the borrow if both 1 then it creates the borrow else 0 
            return sum(num1^num2, (num1 & num2) << 1);
    }
};

int main()
{
    Solution1 sol1;
    cout<<sol1.sum(4, 5)<<endl;

    Solution2 sol2;
    cout<<sol2.sum(10, 11)<<endl;
}