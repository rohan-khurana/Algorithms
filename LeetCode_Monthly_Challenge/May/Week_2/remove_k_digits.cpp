class Solution {
public:
    string removeKdigits(string num, int k) {
         if (num.length() == k) {
            return "0";
        }
        string result = "";
        int i=0;
        while (i < num.length()) 
        {
            int end = result.size() - 1;
            while (k > 0 && end >= 0 && result[end] > num[i])
            {
                    result.erase(result.begin() + end);
                    k--;
                    end--;
            }
                result=result+num[i];
                i++;
        }
        while (k > 0) 
        {
            int end = result.size() - 1;
            result.erase(result.begin() + end);
            k--;
        }
        while (result.size() > 1 && result[0] == '0') //removing starting zero
        {
            result.erase(result.begin());
        }
        return result;
    } 
};
