#include <iostream>
#include <string>

using namespace std;

//The two required parameters
void changepositions(char arr[],int lower,int upper);
void changechararray(char arr[]);

int main() {

	//Example 1
	char arr1[] = "Ahmed Sayed Mansour";
	changepositions(arr1, 6, 10);
	for (int i = 0; i <sizeof(arr1)/sizeof(arr1[0]); ++i) cout << arr1[i];
	cout << endl << endl;

	//Example 2
	char arr2[] = "Ahmed Sayed Mansour";
	changechararray(arr2);
	for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); ++i) cout << arr2[i];
	cout << endl << endl;

	system("pause");
}

//A function with three required parameters to reverse the array
void changepositions(char arr[], int lower, int upper) {
	if (upper - lower > 1) {
		swap(arr[lower], arr[upper]);
		changepositions(arr, ++lower, --upper);
	}
}

//A function with one parameter and then uses the kast function to reverse the array
void changechararray(char arr[]) {
	int lower = 0, upper = strlen(arr);
	changepositions(arr, lower, upper);
}