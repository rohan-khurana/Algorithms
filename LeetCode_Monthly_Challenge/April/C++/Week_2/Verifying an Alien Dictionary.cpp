/*
In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.
Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.
Example 1:
Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

Example 2:
Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

Example 3:
Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
 

Constraints:
1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are English lowercase letters.
*/

class Solution {
public:
    int charMap[26];
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<order.length();i++){
            charMap[order[i]-'a']=i;
        }
        for(int i=1;i<words.size();i++){
            if(compare(words[i-1],words[i])>0){
                return false;
            }
        }
        return true;
    }
    int compare(string word1, string word2){
        int i=0,j=0, compareVal=0;
        while(i<word1.length() && j<word2.length() && compareVal==0){
            compareVal=charMap[word1[i]-'a']-charMap[word2[j]-'a'];
            i++;
            j++;
        }
        if(compareVal==0){
            return word1.length()-word2.length();
        }
        else{
            return compareVal;
        }
    }
};
