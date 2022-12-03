#include <iostream>
using namespace std;

// n is lucky if n * n = sum of n consecutive numbers
// 3 is lucky because 3 * 3 = 2 + 3 + 4

int main()
{
	int n;

	cin >> n;

	int pivotSum = 0;  // we will continuasly calculate pivotSum and compare it with n * n

	int  sumContor, arrayContor;

	sumContor = 1;  // it keeps track of the numbers in the current sum calculated
	arrayContor = 1;    //it keeps track of the numbers from 1 to n * n

	//we calculate 1 + 2 + ... + n
	//and then 2 + 3 + ... + (n + 1)
	//and then 3 + 4 + ... + (n + 2 )
	//and so on until we get the right sequence of numbers


	//sumContor goes only from 1 to n (to know when we end a sequence of n numbers) while arrayContor goes from 1 to n * n

	while (pivotSum < n * n) {
		int pivot = arrayContor;   //we use pivot to keep track of each begining of a sequence
		while (sumContor <= n)   //we take the sequences n by n
		{
			pivotSum += arrayContor;
			arrayContor++;
			sumContor++;
		}
		//at this point, after the while we have a sum of a sequence of n numbers (from 1 to n, or from 2 to (n+1) and so in)

		//if pivotSum it's still less than n * n than we have to  reinitiate sumContor, the pivotSum and the arrayContor

		if (pivotSum < n * n)
			sumContor = 1 , pivotSum = 0, arrayContor = pivot + 1;
		

	}

	//when we get out of while, it means that eather we found the right sequence, or the number n is not lucky

	if (pivotSum == n * n)
	{
		//this means we got the right sequence
		//the last arrayContor is the final number of the sequence + 1
		for (int i = arrayContor - n; i < arrayContor; i++)
			cout << i << " ";   //we print the sequence that demonstrates that n is lucky
	}
	else cout << "NU ESTE NOROCOS";  // n is in lucky (in romanian)
	
	return 0;
}

//After i finished the problem I realised it was an easier way to do it (with formulas only), but I'll leave like this, because I enjoyed making it this way :)