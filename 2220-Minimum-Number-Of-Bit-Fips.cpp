
#include <iostream>

using namespace std;


class Solution1{
    public:
    int minBitFlips(int start, int goal)
    {
        int xorResult = start ^ goal;

        // Brian Kernighan’s Algorithm to count number of set bits..
        // only O(number of set bits) not mexbits
        // after every iteration the least significant set bit is reset by and-ing x with x-1 ;
        int x = xorResult;
        int y = x-1, count =0;
        

        while( x& y)
        {
            x = x&y;
            y= x-1;
            count++;
        }
        return count;
    }

};
// O(number of bits)
class Solution2 {
public:
    int minBitFlips(int start, int goal) {
            int xorResult = start ^ goal;
            int count;
            while(xorResult)
            {
                count+= xorResult &1;
                xorResult >> 1;
            }
            return count;
            
    }
};

//recursive approach  O(maxbits)
class Solution3{

    public: 

    int minBitFlips(int start, int goal){
     if (start == 0 && goal == 0) return 0;

     int flip = (start & 1) != (goal & 1);

     return flip + minBitFlips(start>>1, goal>>1);
    }
};


int main(){
    
}