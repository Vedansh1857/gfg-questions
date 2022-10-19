// C++ program to find number of operations
// to make an array palindrome
#include <bits/stdc++.h>
using namespace std;

// Returns minimum number of count operations
// required to make arr[] palindrome
int findMinOps(int arr[], int n)
{
	int ans = 0; // Initialize result

	// Start from two corners
	int i=0;
  int j=n-1;
  while(i<j)
	{
		// If corner elements are same,
		// problem reduces arr[i+1..j-1]
		if (arr[i] == arr[j])
		{
			i++;
			j--;
		}

		else
		{
			arr[i+1] += arr[i];
      i++;
			ans++;
		}
	}

	return ans;
}

// Driver program to test above
int main()
{
	int arr[] = {11, 14, 15, 99};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Count of minimum operations is "
		<< findMinOps(arr, n) << endl;
	return 0;
}
