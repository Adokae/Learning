#include <iostream>
using namespace std;
#include <vector>
/*
˼·1 ���ǰ������� (0,1)->(1,0)->(0,-1)->(-1,0)->(0,1)...ѭ���� ֱ������������Ԫ��
����˼·��������˼·2��һ����

˼·2����������ҿ��������Ԫ�� �����ܹ�����Ȧ�� 
�ڿ��Ǳ���Ȧ���д����� ���ϵ��� ���ҵ��� ���µ���һ�α���
����ж�n�Ƿ�Ϊ���� ��Ϊ���� ��ʾ�м仹��һ��Ԫ��λ��δ������
Ҫ���⴦��

˼·3���ȶ���һ��n*n��С�ľ���ȷ���������ұ߽磬ȷ����ʼ����ֵ1��������ֵֹn*n
����ʼ����ֵС�ڵ�����ֵֹʱ�����Ͻ�������ѭ����
�����ҡ����ϵ��¡����ҵ��󡢴��µ��ϣ�ÿһ��˳��ѭ��������������߽�

*/


vector<vector<int>> generateMatrix(int n) {
	int startx = 0, starty = 0;//��ʼ����Ԫ������λ��
	vector<vector<int>> matrix(n, vector<int>(n, 0));
	int circle = 0; // Ȧ��
	int offset = 1, i, j;
	int count = 1;// ��ʼԪ��ֵ
	while (circle < n/2){
		// �ʼ������
		for (j = starty; j < n - offset; j++) {
			matrix[startx][j] = count++;
		}
		// ���ϵ���
		for (i = startx; i < n - offset; i++) {
			matrix[i][j] = count++;
		}
		// ���ҵ���
		for (; j > starty; j--) {
			matrix[i][j] = count++;
		}
		//���µ���
		for (; i > startx; i--) {
			matrix[i][j] = count++;
		}
		startx++, starty++, offset++, circle++;
	}
	while (n % 2 == 1) {
		matrix[startx][starty] = count++;
		break;
	}
	return matrix;
}

int main() {
	int n = 4;
	vector<vector<int>> matrix = generateMatrix(n);
	for (vector<vector<int>>::const_iterator it = matrix.begin(); it != matrix.end(); it++) {
		for (vector<int>::const_iterator itt = (*it).begin(); itt != (*it).end(); itt++) {
			cout << *itt << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

