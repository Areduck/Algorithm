// �ּ� - https://programmers.co.kr/learn/courses/30/lessons/64061?language=cpp
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    // Move ������ Ž��
    for (int i = 0; i < moves.size(); i++) {
        int boardIndex = moves.at(i) - 1;
        for (int j = 0; j < board.size(); j++) {
            int item = board[j][boardIndex];
            // item�� ������ ���
            if (item != 0) {
                // stack�� �Ⱥ��, top�� item�̶� ���� ���
                if (!s.empty() && s.top() == item) {
                    s.pop();
                    answer += 2;
                }
                // stack�� ����ְų�, top�� item�̶� ���� ���� ���
                else {
                    s.push(item);
                }
                // �׸��� ������ ���� �������� �ʱ�ȭ
                board[j][boardIndex] = 0;
                break;
            }
        }
    }
    return answer;
}