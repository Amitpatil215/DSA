class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0;
        int e=s.size()-1;
        int wordCount=0;
        // discard if there is any trailing spaces
        while(s[e]==' ' && e>0){
            e--;
        }
        // count the length of the word
        while(e>=0 && s[e]!=' '){
            len++;
            e--;
        }
        return len;
    }
};