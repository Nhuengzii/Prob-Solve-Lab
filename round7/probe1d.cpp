#include <iostream>
#include "probelib.h"

using namespace std;

int main (int argc, char *argv[])
{
	int n = probe_init();
	int l = 0, r = n - 1;
	int mid = (l + r) / 2;
	while(l != r){
		if(probe_check(l, mid))	{
			r = mid;
			mid = (l + r) / 2;
		}else{
			l = mid + 1;
			mid = (l + r) / 2;
		}
	}
	probe_answer(l);

	return 0;
}
