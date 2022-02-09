#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int yellowRow, yellowCol;
    int sumY = brown/2-2;
    
    for(int yellowRow = sumY-1; yellowRow > 0; yellowRow--){
        int yellowCol = sumY - yellowRow;
        if(yellowRow * yellowCol == yellow){
            answer.push_back(yellowRow+2);
            answer.push_back(yellowCol+2);
            break;
        }
    }
    
    return answer;
}
