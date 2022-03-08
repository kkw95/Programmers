#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string level1 = "";
    string level2 = "";
    string level3 = "";
    string level4 = "";
    string level5 = "";
    string level6 = "";
    string level7 = "";
    int orig_size = new_id.size();
    
    for(int i=0; i<new_id.size(); i++){
        level1 += tolower(new_id[i]);
    }
    for(int i=0; i<level1.size(); i++){
        if(level1[i] >= 'a' && level1[i] <= 'z' || level1[i] == '-' || level1[i] == '_' || level1[i] =='.' || level1[i] >= '0' && level1[i] <= '9'){
            level2 += level1[i];
        }
    }
    for(int i=0; i<level2.size(); i++){
        level3 += level2[i];
        if(level2[i] == '.'){
            for(int j=i; j<level2.size(); j++){
                if(level2[j] == '.'){
                    i++;
                }else{
                    i--;
                    break;
                }
            }
        }

    }
    level4 = level3;
    if(level4[0] == '.') level4 = level4.substr(1,level4.size()-1);
    if(level4[level4.size()-1] == '.') level4 = level4.substr(0, level4.size()-1);
    
    if(level4.size() == 0){
        level5+='a';
    }else{
        level5 = level4;
    }
    
    if(level5.size() > 15){
        level6 = level5.substr(0,15);
        if(level6[level6.size()-1] == '.'){
            level6 = level6.substr(0,14);
        }
    }else{
        level6 = level5;
    }

