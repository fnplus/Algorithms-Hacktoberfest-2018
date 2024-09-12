#include <iostream>



void bubblesort (int n, int a[]) {
    int i, j, t;
    for(i = 0; i < n-1; ++i) {
        for(j = 0; j < n-i-1; ++j) {
            if(a[j+1] < a[j]) {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}

void print_array(int a_size, int *a) {
	for(int i=0; i<a_size; i++) {
		std::cout << a[i] << " ";
	}
}

int main() {

	int size = 10;
	int arr[10] = {4, 2, 7, 3, 0, 9, 1, 5, 6, 8};
	bubblesort(size, arr);
	print_array(size, arr);

	return 0;
}
