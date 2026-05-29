#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        while(left <right)
        {
            if(numbers[left] + numbers[right] == target)
            {
                return {left+1, right+1};
            }
            else if(numbers[left]+ numbers[right] > target){
                right --;
            }
            else {
                if(numbers[left+1] + numbers[right] <= target){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
    }
};

int main() {
    Solution solution;

    // Define test cases using a vector of structures for clean iteration
    struct TestCase {
        std::vector<int> numbers;
        int target;
    };

    std::vector<TestCase> testCases = {
        {{2, 7, 11, 15}, 9},
        {{2, 3, 4}, 6},
        {{-1, 0}, -1},
        {{1, 2, 3, 4, 4, 9, 56}, 8},
        {{-5, -3, -2, 1, 4},-1 }
    };

    // Iterate through each test case and execute the function
    for (size_t i = 0; i < testCases.size(); ++i) {
        // We make a local copy or pass by reference if appropriate; 
        // twoSum takes a reference so we pass the vector directly.
        std::vector<int> result = solution.twoSum(testCases[i].numbers, testCases[i].target);
        
        std::cout << "Test Case " << i + 1 << ":\n";
        std::cout << "  Input Array: [";
        for (size_t j = 0; j < testCases[i].numbers.size(); ++j) {
            std::cout << testCases[i].numbers[j] << (j == testCases[i].numbers.size() - 1 ? "" : ", ");
        }
        std::cout << "]\n";
        std::cout << "  Target: " << testCases[i].target << "\n";
        std::cout << "  Output Indices (1-indexed): [" << result[0] << ", " << result[1] << "]\n";
        std::cout << "-------------------------------------------\n";
    }

    return 0;
}