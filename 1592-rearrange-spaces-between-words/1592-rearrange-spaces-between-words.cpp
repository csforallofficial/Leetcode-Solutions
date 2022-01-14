class Solution {
public:
    string reorderSpaces(string text) {
        vector<string>ans;
        int total_spaces = 0;
        string answer_string = "";
        
        for(int i = 0; i<text.size();){
            if(text[i] == ' '){
                total_spaces++;
                i++;
            }
            
            else{
                string str;
                while(i<text.size() and text[i]!=' '){
                    str.push_back(text[i]);
                    i++;
                }
                
                ans.push_back(str);
            }
        }
        
        int no_of_words = ans.size();
        string space_between_words = "";
        int spaces_between_words = no_of_words>1? total_spaces/(no_of_words-1) : 0;
        int spaces_at_end = no_of_words>1? total_spaces%(no_of_words-1):total_spaces;

        for(int i = 0; i<spaces_between_words; i++){
            space_between_words.push_back(' ');
        }
        
        for(int i = 0; i<ans.size(); i++){
            answer_string+=ans[i];
            if(i!=ans.size()-1){
                answer_string+=space_between_words;
            }
        }
        
        
        for(int i = 0; i<spaces_at_end; i++){
            answer_string.push_back(' ');
        }
        
        return answer_string;
    }
};