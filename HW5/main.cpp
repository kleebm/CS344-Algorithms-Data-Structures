//You can add more functions to this file.

#include <iostream>

using namespace std;

void most_frequent(int arr[], int n);
void merge(int arr[], int p, int m, int q);
void mergeSort(int arr[], int low, int high);
void printArray(int arr[], int n);

int main(){
	int array1[] = {9, -2101, 1926, -2101, -101, 9, -4, 9};
	int arr1_length = sizeof(array1) / sizeof(*array1);			//using a variable so you can test with different length arrays
	cout << "In 1st array, the most frequent element is: ";
	mergeSort(array1, 0, arr1_length - 1);
	most_frequent(array1, arr1_length);						//output 9

	int array2[] = {104, 10, -10, 104, 9918, 10, 206, -1311, 289};
	int arr2_length = sizeof(array2) / sizeof(*array2);
	cout << endl << "In 2nd array, the most frequent element is: ";
	mergeSort(array2, 0 , arr2_length - 1);
	most_frequent(array2, arr2_length);						//output 10 or 104
}

void merge(int arr[], int p, int m, int q){
	int n1 = m - p +1;
	int n2 = q - m;

	int first[n1], second[n2];

	int i, j, k;
	for(i = 0; i < n1; i++){
		first[i] = arr[p + i];
	}

	for(j = 0; j<n2;j++){
		second[j] = arr[m + 1 + j];
	}


	i = j = 0;
	k = p;
	while(i < n1 && j < n2){
		if(first[i] <= second[j]){
			arr[k] = first[i];
			i++;
		}
		else{
			arr[k] = second[j];
			j++;
		}
		k++;
	}

	while( i< n1){
		arr[k] = first[i];
		k++;
		i++;
	}
	while( j<n2){
		arr[k] = second[j];
		k++;
		j++;
	}

}

void mergeSort(int arr[], int low, int high){
	if(low >= high)
		return;
	int m = (low + high ) /2;
	mergeSort(arr, low, m);
	mergeSort(arr, m+1, high);
	merge(arr, low, m, high);
}

void printArray(int arr[], int n){
	for(int i = 0; i < n; i++)
		cout<< arr[i]<<" ";
	cout<<""<<endl;
}

void most_frequent(int arr[], int n){
	int freq = arr[0]; //most frequent number
	int count = 1; // number of times freq appeared
	int temp_freq = arr[0]; //set as arr[0] so it will trigger the first time going through the loop to change
	int temp_count; // number checking against freq, to see if it is new freq
	for(int i = 1; i < n; i++){
		if(freq == arr[i]){
			count++;
		}
		else{
			if(temp_freq != arr[i]){
				temp_freq = arr[i];
				temp_count = 1;
			}
			else{
				temp_count++;
			}
		}

		if(count < temp_count){
			freq = temp_freq;
			count = temp_freq;
			temp_freq = 0;
		}
	}


	cout << freq<<endl;
}
