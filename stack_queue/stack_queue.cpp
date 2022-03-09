#include <string>
#include <vector>
#include<iostream>
#include<list>
#include<queue>

using namespace std;

/*프로그래머스 고득점 kit - 기능개발 */
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int leftday[100];
    for (int i = 0; i < progresses.size(); i++) {
        int result = (100 - progresses[i]) % speeds[i];
        if (result == 0)
            leftday[i] = (100 - progresses[i]) / speeds[i];
        else
            leftday[i] = (100 - progresses[i]) / speeds[i] + 1;
    }
    int j = 0;
    for (int i = 0; i < progresses.size(); i++) {
        int count = 0;
        for (j = i + 1; j < progresses.size(); j++) {
            if (leftday[i] < leftday[j]) {
                i = j - 1;
                break;
            }
            count++;
        }
        answer.push_back(count + 1);
        if (j == progresses.size())
            break;
    }

    return answer;
}


/* 프로그래머스 고득점 kit - 프린터 */
int solution(vector<int> priorities, int location) {
    list<int> ps(priorities.begin(), priorities.end());
    int max;
    int answer = 0;

    max = *max_element(ps.begin(), ps.end());
    while (true) {
        int front = ps.front();
        if (max != front) {
            ps.pop_front();
            ps.push_back(front);
        }
        else {
            ps.pop_front();
            answer++;
            if (location == 0) break;
            max = *max_element(ps.begin(), ps.end());
        }
        if (--location < 0) location = ps.size() - 1;
    }
    return answer;
}


/* 프로그래머스 고득점 kit - 다리를 지나가는 트럭 */
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    //시간을 체크
    int time = 0;

    //현재까지 건넌 트럭의 index
    int truck_index = 0;

    //현재 다리위의 트럭무게
    int bridge_weight = 0;

    //현재 다리위의 트럭개수
    int truck_count = 0;

    //현재 트럭들의 다리위에서의 위치가 필요
    vector<int> truck_loc(bridge_length);

    //현재 다리의 시작점 index
    int bridge_begin = 0;

    //트럭의 개수
    int orgin_size = truck_weights.size();
    int size = orgin_size;

    do{
        time++;

        //다리 맨앞의 정보
        int begin = truck_loc[bridge_begin];
        //맨 앞에 나갈 트럭이 있는지 체크
        if (begin != 0){
            //트럭이 빠져나갔으므로 중량 감소, 트럭 개수 감소
            bridge_weight -= begin;
            truck_count--;
        }

        if (truck_index < orgin_size){
            int next_truck = truck_weights[truck_index];

            //현재 들어올 트럭이 다리의 무게와 트럭 개수를 넘지 않는지 체크
            if (bridge_weight + next_truck <= weight && truck_count < bridge_length){
                truck_loc.push_back(next_truck);
                //새 트럭이 들어왔으므로 다리 중량 증가, 트럭 개수 증가
                bridge_weight += next_truck;
                truck_count++;
                //새 트럭이 다리로 진입했으므로 다음 대기트럭으로 이동
                truck_index++;
                //새 트럭이 들어왔으므로 대기중인 트럭 개수 감소
                size--;
            }
            else{
                truck_loc.push_back(0);
            }
        }

        bridge_begin++;
    } while (size != 0 || truck_count != 0);

    answer = time;
    return answer;
}


/* 프로그래머스 고득점 kit - 주식가격 */
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int size = prices.size();
    int count = 0;
    for (int i = 0; i < size; i++) {
        count = 0;
        for (int j = i + 1; j < size; j++) {
            if (prices[i] <= prices[j])
                count++;
            else {
                count++;
                break;
            }
        }
        if (i == size)
            count = 0;
        answer.push_back(count);
    }
    return answer;
}