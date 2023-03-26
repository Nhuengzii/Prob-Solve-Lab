#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;





int main (int argc, char *argv[])
{
	int n = 0;
	vector<int> data;
	while(true){
		cin >> n;
		if ( n == 0 ){
			break;
		}
		data.clear();
		data = vector<int>(n);
		for (int a = 0; a < n; a++) {
			cin >> data[a];
		}
		sort(data.begin(), data.end());
		for (auto x : data) {
			cout << x << " ";
		
		}
		cout << endl;
	}
	
	return 0;
}
