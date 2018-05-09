/* Dynamic Programming solution to find length of the 
longest common substring */
#include<iostream>
#include<string.h>
using namespace std;

int LCSubStr(char *X, char *Y, int m, int n)
{
   if(m == 0 || n == 0) return 0;
   int dp[m][n];
   dp[0][0] = X[0] == Y[0] ? 1 : 0;
   for(int col = 1; col < n; col++) {
       dp[0][col] = 0;
       if(X[0] == Y[col])
            dp[0][col] = 1;
   }
   for(int row = 1; row < m; row++) {
       dp[row][0] = 0;
       if(X[row] == Y[0])
            dp[row][0] = 1;
   }
   int ans = 0;
   for(int row = 1; row < m; row++) {
       for(int col = 1; col < n; col++) {
           if(X[row] == Y[col])
                dp[row][col] = 1 + dp[row-1][col-1];
            else
                dp[row][col] = 0;
            ans = max(ans, dp[row][col]);
       }
   }
   return ans;
}

/* Driver program to test above function */
int main()
{
	char X[] = "OldSite:GeeksforGeeks.org";
	char Y[] = "NewSite:GeeksQuiz.com";

	int m = strlen(X);
	int n = strlen(Y);

	cout << "Length of Longest Common Substring is "
		<< LCSubStr(X, Y, m, n);
	return 0;
}
