간만에 코딩테스트 문제를 풀었더니 map 순회를 까먹어서 애먹음
for(const &temp : map) 이거 좀 익숙해져야할듯

그리고 map.first / map.second 잘 쓰자.

중복을 피하기 위해 map을 사용했는데 vector에서도 unique 사용해서 중복 처리한 다른 사람의 풀이가 인상 깊었음.

report.erase(unique(report.begin(), report.end()), report.end());
