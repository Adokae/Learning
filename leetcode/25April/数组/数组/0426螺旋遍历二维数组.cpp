#include <iostream>
using namespace std;
#include <vector>
/*
˼·1�����жϾ����Ƿ�Ϊ�գ���Ϊ�գ���ȷ�������ϡ��¡����ұ߽磬
��������-�����ϵ���-�����ҵ���-�����µ���˳�������ÿһ�α�����С�߽磬
���ж��Ƿ񳬳��߽磬����ѭ����ֱ�������߽硢����ѭ��

˼·2��ģ���ά�����·����ʹ���������ά����ͬ����С�ĸ��������ʾÿ��Ԫ���Ƿ񱻷���
���ն�ά�����·���������飬��·���������޻����֮ǰ���ʹ���λ�ã���˳ʱ����ת��������һ����
��·�����ȵ��ڶ�ά����������Ԫ�صĸ���ʱ������ѭ��

˼·3������ģ�⣬���ȴ�ӡ���������Ԫ�أ�Ȼ���ӡ�����Ԫ�أ�ֱ����ӡ���ڴ�Ԫ��
��ȷ���ϡ��¡����ұ߽磬���ϲ�Ԫ�ر�����(top,left)-��(top,right)
(top+1, right)->(bottom,right)��(bottom,right-1)->(bottom,left)��
(bottom-1, left)->(top-1,left)�������굱ǰ���left��top��1��right��bottom��1��
������һ�������ֱ������������Ԫ��

*/

// ˼·1
//vector<int> spiralArray(vector<vector<int>>& array) {
//	if (array.size() == 0 || array[0].size() == 0) {
//		return {};
//	}
//	int left = 0, right = array[0].size() - 1, top = 0, bottom = array.size()-1;
//	vector<int> m;
//	while (true) {
//		for (int i = left; i <= right; i++) {
//			m.push_back(array[top][i]);
//		}
//		top++;
//		if (top > bottom) { break; }
//
//		for (int i = top; i <= bottom; i++) {
//			m.push_back(array[i][right]);
//		}
//		right--;
//		if (left > right) { break; }
//
//		for (int i = right; i >= left; i--) {
//			m.push_back(array[bottom][i]);
//		}
//		bottom--;
//		if (top > bottom) { break; }
//
//		for (int i = bottom; i >= top; i--) {
//			m.push_back(array[i][left]);
//		}
//		left++;
//		if (left > right) { break; }
//	}
//	return m;
//}


//// ˼·2
//vector<int> spiralArray(vector<vector<int>>& array) {
//	if (array.size() == 0 || array[0].size() == 0) {
//		return {};
//	}
//	int directions[4][2] = { {0,1}, {1, 0}, {0, -1}, {-1, 0} };
//	int rows = array.size(), cols = array[0].size();
//	int total = rows * cols;
//	vector<vector<bool>> visited(rows, vector<bool>(cols, false));
//	vector<int> m(total);// ������СΪtotal��һά���� Ĭ�����ֵΪ0
//	int i = 0, row = 0, col = 0;// i��ʾ�����ҵ���Ԫ�ظ��� row-col��ʾ���ҵ���Ԫ�غ�������
//	int directionIndex = 0; // ��������
//	for (; i < total; i++) {
//		m[i] = array[row][col];
//		visited[row][col] = true;
//		int nextRow = row + directions[directionIndex][0];
//		int nextCol = col + directions[directionIndex][1];
//		if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols || visited[nextRow][nextCol] == true) {
//			directionIndex = (directionIndex + 1) % 4;
//		}
//		row = row + directions[directionIndex][0];
//		col = col + directions[directionIndex][1];
//	}
//	return m;
//}

// ˼·3
// ����ʹ��Ԫ�ظ�����Ϊ���� �������������ұ߽���Ϊ���� ��Ȼ��ʹ����Ԫ�ظ������� �߽�Ҳ�����
vector<int> spiralArray(vector<vector<int>>& array) {
	if (array.size() == 0 || array[0].size() == 0) {
		return {};
	}
	int rows = array.size(), cols = array[0].size();
	int total = rows * cols;
	int left = 0, top = 0, right = cols - 1, bottom = rows - 1;
	vector<int> m;// ������СΪtotal��һά���� Ĭ�����ֵΪ0
	/*int elems = 0 ; */
	while (left<= right && top <= bottom ) {
		for (int i = left; i <= right; i++) {
			m.push_back(array[top][i]);
			/*elems++;*/
		}

		for (int i = top+1; i <= bottom; i++) {
			m.push_back(array[i][right]);
			//elems++;
		}
		//����if���� �������һ�л�1�е����
		if (left < right && top < bottom) {
			for (int i = right-1; i >= left; i--) {
				m.push_back(array[bottom][i]);
				//elems++;
			}

			for (int i = bottom-1; i > top; i--) {
				m.push_back(array[i][left]);
				//elems++;
			}
		}
		top++;
		left++;
		right--;
		bottom--;
	}
	return m;
}

int main() {
	vector<vector<int>> array = {
		{1, 2, 3},
		{8, 9, 4},
		{7, 6, 5}
	};
	vector<int> matrix = spiralArray(array);
	for (vector<int>::const_iterator it = matrix.begin(); it != matrix.end(); it++) {
			cout << *it << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
