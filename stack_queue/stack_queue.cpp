#include <string>
#include <vector>
#include<iostream>
#include<list>
#include<queue>

using namespace std;

/*���α׷��ӽ� ����� kit - ��ɰ��� */
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


/* ���α׷��ӽ� ����� kit - ������ */
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


/* ���α׷��ӽ� ����� kit - �ٸ��� �������� Ʈ�� */
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    //�ð��� üũ
    int time = 0;

    //������� �ǳ� Ʈ���� index
    int truck_index = 0;

    //���� �ٸ����� Ʈ������
    int bridge_weight = 0;

    //���� �ٸ����� Ʈ������
    int truck_count = 0;

    //���� Ʈ������ �ٸ��������� ��ġ�� �ʿ�
    vector<int> truck_loc(bridge_length);

    //���� �ٸ��� ������ index
    int bridge_begin = 0;

    //Ʈ���� ����
    int orgin_size = truck_weights.size();
    int size = orgin_size;

    do{
        time++;

        //�ٸ� �Ǿ��� ����
        int begin = truck_loc[bridge_begin];
        //�� �տ� ���� Ʈ���� �ִ��� üũ
        if (begin != 0){
            //Ʈ���� �����������Ƿ� �߷� ����, Ʈ�� ���� ����
            bridge_weight -= begin;
            truck_count--;
        }

        if (truck_index < orgin_size){
            int next_truck = truck_weights[truck_index];

            //���� ���� Ʈ���� �ٸ��� ���Կ� Ʈ�� ������ ���� �ʴ��� üũ
            if (bridge_weight + next_truck <= weight && truck_count < bridge_length){
                truck_loc.push_back(next_truck);
                //�� Ʈ���� �������Ƿ� �ٸ� �߷� ����, Ʈ�� ���� ����
                bridge_weight += next_truck;
                truck_count++;
                //�� Ʈ���� �ٸ��� ���������Ƿ� ���� ���Ʈ������ �̵�
                truck_index++;
                //�� Ʈ���� �������Ƿ� ������� Ʈ�� ���� ����
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


/* ���α׷��ӽ� ����� kit - �ֽİ��� */
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