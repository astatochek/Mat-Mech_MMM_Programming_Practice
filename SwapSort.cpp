#include <iostream>
using namespace std;

// сортировка вставками массива из n заданных элементов
void swap(int& x, int& y){
  int temp = x;
  x = y;
  y = temp;
}

int main() {
  int n;
  cin >> n;
  int* A = new int[n];
  for (int i = 0; i < n; i++)
    cin >> A[i];

  for(int i=1; i<n; i++)     
	  for(int j=i; j>0 && A[j-1] > A[j]; j--)
			swap(A[j-1], A[j]);

  for (int i = 0; i < n; i++)
    cout << A[i] << " ";

  delete [] A;
}
