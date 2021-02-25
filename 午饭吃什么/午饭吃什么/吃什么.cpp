#include <iostream>
#include <cstdlib>
#include <ctime>
#define maxsize 100
using namespace std;
class menu
{
private:
	
	int size=0;
	string fan[maxsize];

public:
	void addmenu(string a) {
		
	}
};

int main() 
{
	srand((int)time(0));
	int t = 1;
	while (t)
	{
		int r = rand() % 10;
		cout << f[r]<<endl;
		cout << "是否重新选择(输入1表示不重新选择，0表示重新"<<endl;
			int y;
			cin >> y;

			if (y == 1)
				t = 0;
	}
	
	system("pause");
}