반복문 돌 때 마다 초기화 해줘야하는 값은 없는지?
이번 경우 differentCount를 0으로 해줬어야함

log를 남기는거 대신 후보지(vector)에서 뺀 후 다음 DFS로 넘어가는것도 좋은 방법
왜 좋냐? 체크할 필요가 없다.

vector 추가 제거를 할 시 index가 복잡하게 변하기 때문에 넘길 값같은 경우에는 vector index로 하지말고 temp에 저장한 다음에 그걸 쓰는게 나을듯
