#include <iostream>
using namespace std;
int m;//ɫ��
int point;//����
int edge;//����
int total = 0;//����
int Graph[100][100] = { 0 };//�����������
int x[100] = { 0 };//��ɫ��������ʾ

bool IsOk(int i){
	for (int j = 1; j < i; ++j) {
		if (Graph[i][j] == 1 && x[j] == x[i]) {
			return false;
		}
	}
	return true;
}

void BackTrack(int i){
	int j;
	if (i > point){
		cout << "����" << ++total << ":";
		for (j = 1; j <= point; ++j){
			cout << x[j];
		}
		cout << endl;
		return;
	}
	else{
		for (j = 1; j <= m; ++j){
			x[i] = j;
			if (IsOk(i)) {
				BackTrack(i + 1);
			}
			x[i] = 0;
		}
	}
}

int main(){
	int p1, p2;
	cout << "���������ɫ��������:";
	cin >> point >> m >> edge;
	cout << "����ÿ����������յ�:\n";
	for (int i = 1; i <= edge; ++i){
		cin >> p1 >> p2;
		Graph[p1][p2] = 1;
		Graph[p2][p1] = 1;
	}
	BackTrack(1);
	if (total > 0) {
		cout << "һ����" << total << "�ַ���\n";
	}
	else {
		cout << "NO\n";
	}
}

/*4 3 5
1 2
1 3
1 4
2 3
2 4*/