#include <iostream>
using namespace std;
#include <vector>
/*
思路1：先判断矩阵是否为空，不为空：先确定矩阵上、下、左、右边界，
按从左到右-》从上到下-》从右到左-》从下到上顺序遍历，每一次遍历缩小边界，
并判断是否超出边界，反复循环，直到超出边界、跳出循环

思路2：模拟二维数组的路径，使用与输入二维数组同样大小的辅助数组表示每个元素是否被访问
按照二维数组的路径访问数组，当路径超出界限或进入之前访问过的位置，就顺时针旋转，进行下一方向
但路径长度等于二维数组中所有元素的个数时，跳出循环

思路3：按层模拟，首先打印数组最外层元素，然后打印次外层元素，直到打印最内存元素
先确定上、下、左、右边界，最上层元素遍历从(top,left)-》(top,right)
(top+1, right)->(bottom,right)，(bottom,right-1)->(bottom,left)，
(bottom-1, left)->(top-1,left)。遍历完当前层后，left和top加1，right和bottom减1，
进入下一层遍历，直到遍历完所有元素

*/

// 思路1
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


//// 思路2
//vector<int> spiralArray(vector<vector<int>>& array) {
//	if (array.size() == 0 || array[0].size() == 0) {
//		return {};
//	}
//	int directions[4][2] = { {0,1}, {1, 0}, {0, -1}, {-1, 0} };
//	int rows = array.size(), cols = array[0].size();
//	int total = rows * cols;
//	vector<vector<bool>> visited(rows, vector<bool>(cols, false));
//	vector<int> m(total);// 创建大小为total的一维矩阵 默认填充值为0
//	int i = 0, row = 0, col = 0;// i表示遍历找到的元素个数 row-col表示查找到的元素横纵坐标
//	int directionIndex = 0; // 方向索引
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

// 思路3
// 不能使用元素个数作为条件 必须用上下左右边界作为条件 不然即使满足元素个数条件 边界也会出错
vector<int> spiralArray(vector<vector<int>>& array) {
	if (array.size() == 0 || array[0].size() == 0) {
		return {};
	}
	int rows = array.size(), cols = array[0].size();
	int total = rows * cols;
	int left = 0, top = 0, right = cols - 1, bottom = rows - 1;
	vector<int> m;// 创建大小为total的一维矩阵 默认填充值为0
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
		//加上if条件 避免出现一行或1列的情况
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
