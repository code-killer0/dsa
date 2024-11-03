// rotaating by one step and then check

class Solution {
private:
    void rotate(string &s){
        char temp = s[0];
        for(int i = 0;i<s.size()-1;i++){
            s[i] = s[i+1];
        }
        s[s.size()-1] = temp;
    }
public:
    bool rotateString(string s, string goal) {
        for(int i = 0;i<s.size();i++){
            if(s == goal){
                return true;
            }
            else{
                rotate(s);
            }
        }
        return false;
    }
};