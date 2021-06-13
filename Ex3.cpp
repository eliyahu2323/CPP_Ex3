

#include <iostream>
#include <stdbool.h>
using namespace std;
int neastprime(int n);
bool isPrime(int n);
void sort(int arr[], int len);
bool isDiff(int a[], int size);
double large_of_average(double a[], int size);
int sub_seq_of_zeros(int arr[], int size);
double arrayStdev(double arr[], int size);
double mean(double arr[], int size);

int main()
{
	int menu;
	bool flag = true; //boolean variable for loop

	while (flag) {
		cout << "Menu:" << endl;
		cout << "Press:" << endl;
		cout << "0 for exit" << endl;
		cout << "1 for  display neastprime" << endl;
		cout << "2 all numbers in array are different?" << endl;
		cout << "3 display a percent of elements bigger of average" << endl;
		cout << "4 longest subsequence of zero" << endl;
		cout << "5 standard deviation" << endl;
		cout << "Enter your choice:";
		cin >> menu; //get your choice from user

		switch (menu) {

		case 0: {//if menu == 0 you want exit
			cout << "Thank you for using the program" << endl;
			flag = false;
			break;
		}
		case 1: {
			int n;
			cout << "please enter n: ";
			cin >> n;
			cout << neastprime(n) << endl;
			break;
		}
		case 2: {
			int size = 0;
			cout << "Please enter the size of your array: ";
			cin >> size;
			cout << "Please enter your array numbers:\n";
			int arr[100];
			for (int i = 0; i < size; i++) {
				cin >> arr[i];
			}
			bool ans = isDiff(arr, size);
			if (ans == true) {
				cout << "True" << endl << "all the numbers in the array are different" << endl;
			}
			else {
				cout << "False" << endl << "There are similar numbers in the array" << endl;
			}
			break;
		}

		case 3: {

			int size = 0;
			cout << "Please enter the size of your array: ";
			cin >> size;
			cout << "Please enter your array numbers:\n";
			double arr[100];
			for (int i = 0; i < size; i++) {
				cin >> arr[i];
			}
			cout << "The percentage of organs larger than average is: " << large_of_average(arr, size) << "%" << endl;
			break;
		}
		case 4: {
			int size = 0;
			cout << "Please enter the size of your array: ";
			cin >> size;
			cout << "Please enter your array numbers:\n";
			int arr[100];
			for (int i = 0; i < size; i++) {
				cin >> arr[i];
			}
			cout << "The largest length consisting of zeros is: " << sub_seq_of_zeros(arr, size) << endl;
			break;
		}

		case 5: {

			int size = 0;
			cout << "Please enter the size of your array: ";
			cin >> size;
			cout << "Please enter your array numbers:\n";
			double arr[100];
			for (int i = 0; i < size; i++) {
				cin >> arr[i];
			}
			cout <<"The standard deviation of the array members is: "<< arrayStdev(arr, size)<<endl;
		}

		}
	}
}

//Finds the prime number closest to the given number
int neastprime(int n) {
	//If the given number is prime, it is the number returned
	if (isPrime(n) == true) {
		return n;
	}
	for (int i = 1; i < n; i++) {
		//Checks the small number first and then if it is not small checks the larger number
		if (isPrime(n - i) == true) {
			return n - i;
		}
		if (isPrime(n + i) == true) {
			return n + i;
		}
	}
	
}
//Checks if a number is prime
bool isPrime(int n) {
	for (int i = 2; i < n ; i++) {
		if (n%i== 0) {
			return false;
		}
	}
	return true;
}
//sort array of integer
void sort(int arr[], int len) {
	for (int i = 0; i < len-1; i++) {
		for (int j = 0; j < len-i-1; j++) {
			if (arr[j] > arr[j + 1]) {
				//swap
				int x = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = x;
			}
		}
	}
}
//A function that checks if all the numbers are different from each other
bool isDiff(int a[], int size) {
	sort(a, size);
	for (int i = 0; i < size-1; i++){
		if (a[i] == a[i + 1]) { 
			return false;
		}
	}

	return true;
}
//A function that returns the percentage of large organs just above the average
double large_of_average(double a[], int size) {
	
	double ave = mean(a, size);//Keeps the average
	double sizeBig = 0;
	//Count the numbers larger than average
	for (int i = 0; i <size; i++){
		if (a[i] > ave) {
			sizeBig++;
		}
	}
	
	return (sizeBig / size) * 100;
}

//A function that returns the largest number of consecutive long zeros out of the array
int sub_seq_of_zeros(int arr[], int size) {
	int lenBig = 0;//Maintains the longest sequence the longest time
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		
		if (arr[i] == 0) {
			count++;
			if (count > lenBig) {//Updates the largest number of zeros
				lenBig = count;
			}
		}
		if (arr[i] == 1) {
				count = 0;	
		}

	}
	return lenBig;
}

//A function that returns the standard deviation of the array members
double arrayStdev(double arr[], int size) {
	double sum = 0;
	double ave = mean(arr, size);//average of array
	for (int i = 0; i < size; i++){
		sum += pow((arr[i] - ave),2);//sum all (arr[i]-average)^2
	}
	return sqrt((double)((sum /size)));
}

//A function that returns an array average
double mean(double arr[],int size) {
	double sum = 0;
	for (int i = 0; i < size; i++){
		sum += arr[i];
	}
	return sum / size;
}
