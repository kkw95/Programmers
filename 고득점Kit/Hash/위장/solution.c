#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> category;
    
    for(int i=0; i<clothes.size(); i++){
        if(category.find(clothes[i][1]) == category.end()){
            //not found
            category.insert(make_pair(clothes[i][1],2));
        }else{
            category[clothes[i][1]]++;
        }
    }
    
    for(auto &cat : category){
        answer *= cat.second;
    }
    
    return answer-1;
}
