#include <iostream>
using namespace std;
#include <vector>
/*
思路1 考虑按步长走 (0,1)->(1,0)->(0,-1)->(-1,0)->(0,1)...循环走 直到遍历完所有元素
但该思路本质上与思路2是一样的

思路2：考虑左闭右开区间遍历元素 考虑总共遍历圈数 
在考虑遍历圈数中从左到右 从上到下 从右到左 从下到上一次遍历
最后判断n是否为奇数 若为奇数 表示中间还有一个元素位置未遍历到
要额外处理

思路3：先定义一个n*n大小的矩阵，确定上下左右边界，确定初始迭代值1，迭代终止值n*n
但初始迭代值小于迭代终止值时，不断进行下列循环：
从左到右、从上到下、从右到左、从下到上，每一次顺序循环迭代完后，收缩边界

*/


vector<vector<int>> generateMatrix(int n) {
	int startx = 0, starty = 0;//初始行列元素索引位置
	vector<vector<int>> matrix(n, vector<int>(n, 0));
	int circle = 0; // 圈数
	int offset = 1, i, j;
	int count = 1;// 初始元素值
	while (circle < n/2){
		// 最开始从左到右
		for (j = starty; j < n - offset; j++) {
			matrix[startx][j] = count++;
		}
		// 从上到下
		for (i = startx; i < n - offset; i++) {
			matrix[i][j] = count++;
		}
		// 从右到左
		for (; j > starty; j--) {
			matrix[i][j] = count++;
		}
		//从下到上
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

