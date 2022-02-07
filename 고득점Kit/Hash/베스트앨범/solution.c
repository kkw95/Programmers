#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

struct Data{
    int index;
    string genre;
    int play;
};

bool cmp(Data a, Data b){
    if(a.genre == b.genre){
        if(a.play == b.play){
            return a.index < b.index;
        }
        return a.play > b.play;
    }
    return a.genre < b.genre;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<Data> db;
    map<int, vector<Data>, greater<int>> topGenreMap;
    
    for(int i=0; i<plays.size(); i++){
        Data tempDb = {i, genres[i], plays[i]};
        db.push_back(tempDb);   
    }
    sort(db.begin(), db.end(), cmp);
    
    int value = 0;
    vector<Data> temp;
    
    for(int i=0; i<db.size(); i++){
        value += db[i].play;
        temp.push_back(db[i]);
        for(int j=i+1; j<db.size(); j++){
            if(db[i].genre == db[j].genre){
                value += db[j].play;
                temp.push_back(db[j]);
                i++;
            }
        }
        topGenreMap.insert(make_pair(value,temp));
        temp.clear();
        value = 0;
    }
    for(auto iter : topGenreMap){
        if(iter.second.size() > 1){
            answer.push_back(iter.second[0].index);
            answer.push_back(iter.second[1].index);
        }else{
            answer.push_back(iter.second[0].index);
        }
    }
    return answer;
}
