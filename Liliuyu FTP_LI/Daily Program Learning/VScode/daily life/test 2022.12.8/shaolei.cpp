#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>
using namespace std;

int main() {

	int n, m;//n代表行，m代表列
	cin >> n >> m;
	char str[100][100];//存放炸弹数据的数组
	int ans[100][100];//计算炸弹的数组
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans[i][j]=0;//初始化二维数组
		}
    }
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> str[i][j];//i代表行，j代表列
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (str[i][j] == '*') {//若该位置为炸弹
				if (j > 0 && j < m - 1) {//位置不在第一列，并且不住最后一列
					ans[i][j + 1] += 1;
					ans[i][j - 1] += 1;//左右各加一
					if (i > 0 && i < n - 1) {//并且位置不在第一行
						ans[i - 1][j] += 1;
						ans[i + 1][j] += 1;//上下加一
						ans[i - 1][j - 1] += 1;
						ans[i - 1][j + 1] += 1;//左侧上下加一
						ans[i + 1][j - 1] += 1;
						ans[i + 1][j + 1] += 1;//右侧上下加一
					}
					else if (i == 0) {//但在第一行
						ans[i + 1][j] += 1;//下侧加一
						ans[i + 1][j - 1] += 1;
						ans[i + 1][j + 1] += 1;//下侧左右加一
					}
					else if (i == n - 1) {//但在最后一行
						ans[i - 1][j] += 1;//上侧加一
						ans[i - 1][j - 1] += 1;
						ans[i - 1][j + 1] += 1;//上侧左右加一
					}
				}//位置不在第一列，并且不在最后一列的所有情况
				else if (j == 0)//第一列
				{
					ans[i][j + 1] += 1;//右侧加一
					if (i > 0 && i < n - 1) {//位置不在第一行，并且不住最后一行
						ans[i - 1][j] += 1;
						ans[i + 1][j] += 1;//上下加一
						ans[i - 1][j + 1] += 1;
						ans[i + 1][j + 1] += 1;//右侧上下加一
					}
					else if (i == 0) {//第一行（左上角）
						ans[i + 1][j] += 1;//下侧加一
						ans[i + 1][j + 1] += 1;//下侧右边加一
					}
					else if (i == n - 1) {//最后一行（左下角）
						ans[i - 1][j] += 1;//上侧加一
						ans[i - 1][j + 1] += 1;//上侧右边加一
					}
				}
				else if (j == m - 1)//最后一列 
                {
					ans[i][j - 1] += 1;//左侧加一
					if (i > 0 && i < n - 1) {//位置不在第一行，并且不住最后一行
						ans[i - 1][j] += 1;
						ans[i + 1][j] += 1;//上下侧加一
						ans[i - 1][j - 1] += 1;
						ans[i + 1][j - 1] += 1;//左上下侧加一
					}
					else if (i == 0) {//第一行（右上角）
						ans[i + 1][j] += 1;//下侧加一
						ans[i + 1][j - 1] += 1;//左下侧加一
					}
					else if (i == n - 1) {//最后一行（右下角）
						ans[i - 1][j] += 1;//上侧加一
						ans[i - 1][j - 1] += 1;//左上侧加一
					}
				}//位置在第一列，和位置在最后一列的所有情况
			}//以上为所有类型的判断

		}
	}

	for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(str[i][j]=='*')
                cout<<'*';
            else{
                cout<<ans[i][j];
            }
        }
        cout<<endl;
	}


	return 0;
}