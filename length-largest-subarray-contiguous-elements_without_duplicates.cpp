#include <iostream>
#include <climits>

using namespace std;

int findLength(int arr[], int n)
{
    int maxlen = -1;
    for(int s = 0; s < n; s++) {
        int minelem = INT_MAX, maxelem = INT_MIN;
        for(int e = s; e < n; e++) {
            maxelem = max(maxelem, arr[e]);
            minelem = min(minelem, arr[e]);
            if(maxelem - minelem == e - s)
                maxlen = max(maxlen, e - s + 1);
        }
        
    }
    return maxlen;
}

int main()
{
	int arr[] = {1, 56, 58, 57, 90, 92, 94, 93, 91, 45};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Length of the longest contiguous subarray is "
		<< findLength(arr, n);
	return 0;
}
