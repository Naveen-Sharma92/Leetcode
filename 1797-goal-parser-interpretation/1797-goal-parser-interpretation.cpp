class Solution {
public:
    string interpret(string command) {
        int c=0;
        string s;
        int n=command.size();
        while(c<n){
            if(command[c] == 'G'){
                s.push_back('G');
                c++;
            }
            else if((command[c] == '(') && (command[c+1] == ')')){
                s.push_back('o');
                c+=2;
            }
            else{
                s.push_back('a');
                s.push_back('l');
                c+=4;
            }
        }
        return s;
        
    }
};