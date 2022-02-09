#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> giveUp1 = {1,2,3,4,5};
    vector<int> giveUp2 = {2,1,2,3,2,4,2,5};
    vector<int> giveUp3 = {3,3,1,1,2,2,4,4,5,5};
    vector<int> count = {0,0,0};
    
    for(int i=0; i<answers.size(); i++){
        if(answers[i] == giveUp1[i%giveUp1.size()]){
            count[0]++;
        }
        if(answers[i] == giveUp2[i%giveUp2.size()]){
            count[1]++;
        }
        if(answers[i] == giveUp3[i%giveUp3.size()]){
            count[2]++;
        }
    }
    
    int max = 0;
    for(int i=0; i<count.size(); i++){

