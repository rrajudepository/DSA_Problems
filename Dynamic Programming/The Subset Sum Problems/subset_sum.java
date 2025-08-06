import java.util.*;
// A Dynamic Programming solution for subset sum problem
class subset_sum
{
	// Returns true if there is a subset of set[] with sun equal to given sum
	static boolean isSubsetSum(int set[], int n, int sum)
	{
		// The value of subset[i][j] will be true if there 
			// is a subset of set[0..j-1] with sum equal to i
		boolean subset[][] = new boolean[sum+1][n+1];
	
		// If sum is 0, then answer is true
		for (int i = 0; i <= n; i++)
		subset[0][i] = true;
	
		// If sum is not 0 and set is empty, then answer is false
		for (int i = 1; i <= sum; i++)
		subset[i][0] = false;
	
		// Fill the subset table in botton up manner
		for (int i = 1; i <= sum; i++)
		{
		for (int j = 1; j <= n; j++)
		{
			subset[i][j] = subset[i][j-1];
			if (i >= set[j-1])
			subset[i][j] = subset[i][j] || 
										subset[i - set[j-1]][j-1];
		}
		}
	
		/* // uncomment this code to print table
		for (int i = 0; i <= sum; i++)
		{
		for (int j = 0; j <= n; j++)
			System.out.println (subset[i][j]);
		} */
	
		return subset[sum][n];
	}
	/* Driver program to test above function */
	public static void main (String args[])
	{
	    Scanner input = new Scanner(System.in);
	    int n = input.nextInt();
	    int sum  = input.nextInt();
	    int set[] = new int[n];
	    for(int i=0;i<n;i++)
	    {
	        set[i]=input.nextInt();
	    }
		/*int set[] = {3, 34, 4, 12, 5, 2};
		int sum = 9;
		int n = set.length;*/
		if (isSubsetSum(set, n, sum) == true)
			System.out.println("Yes");
		else
			System.out.println("No");
	}
}/* This code is contributed by Rajat Mishra */
