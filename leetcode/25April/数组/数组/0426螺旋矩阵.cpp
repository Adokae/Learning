#include <iostream>
using namespace std;
#include <vector>
/*
思路1：首先确定左右上下的边界，按照从左到右、从上到下、从右到左、从下到上的顺序打印
每遍历完一条边，就把边界收缩，判断是否超出边界限制，若超出边界限制，直接跳出循环
*/


vector<int> spiralOrder(vector<vector<int>> matrix) {
	if (matrix.size() == 0 || matrix[0].size() == 0) {
		return {};
	}
	vector<int> m;
	int rows = matrix.size(), cols = matrix[0].size();// 矩阵的行数和列数
	int left = 0, right = cols - 1, top = 0, bottom = rows - 1;
	while (true) {
		for (int i = left; i <= right; i++) {
			m.push_back(matrix[top][i]);
		}
		top++;
		if (top > bottom) { break; }
		for (int j = top; j <= bottom; j++) {
			m.push_back(matrix[j][right]);
		}
		right--;
		if (left > right) { break; }
		for (int i = right; i >= left; i--) {
			m.push_back(matrix[bottom][i]);
		}
		bottom--;
		if (top > bottom) { break; }
		for (int j = bottom; j >= top; j--) {
			m.push_back(matrix[j][left]);
		}
		left++;
		if (left > right) { break; }
	}
	return m;
}

int main() {
	vector<vector<int>> matrix = { {1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16},
		{17, 18, 19, 20},
		{21, 22, 23, 24}
	};
	/*
	{1, 2,3},
		{4, 5, 6},
		{7, 8, 9}

		{1, 2, 3, 4},
	{5, 6, 7, 8},
	{9, 10, 11, 12}
	*/
	vector<int> m = spiralOrder(matrix);

	for (vector<int>::const_iterator it = m.begin(); it != m.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

