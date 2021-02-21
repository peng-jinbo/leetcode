class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;

        //Hash map to store all fizzbuzz mappings.
        map<int, string> fizzBuzzDict = {
            {3, "Fizz"},
            {5, "Buzz"} 
        };
    
        for (int num = 1; num <= n; ++num)
        {
            string numAnsStr = "";

            for (auto key : fizzBuzzDict)
            {
                //If the num is divisible by key,
                //then add the corressponding string mapping to current numAnsStr
                if (num % key.first == 0)
                    numAnsStr += key.second;
            }
            //Not divisible by 3 or 5, add the number
            if (numAnsStr == "")
                numAnsStr += to_string(num);
            // Append the current answer str to the ans list
            ans.push_back(numAnsStr);
        }
        return ans;
    }
};