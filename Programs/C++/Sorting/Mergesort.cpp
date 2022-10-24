#include <iostream>
using namespace std;


void merge(int A[], int l, int r){
    int temp[r+1];
    int cur;
    for(int i = l;i <= r; i++){
        temp[i] = A[i];
    }
    int m = (l+r)/2;
    int i1 = l;
    int i2 = m+1;
    for(cur = l; cur <= r; cur++){
        if(i1 == m+1){
            A[cur] = temp[i2];
            i2++;
        }else if(i2 > r){
            A[cur] = temp[i1]; 
            i1++;
        }else if(temp[i1] <= temp[i2]){
            A[cur] = temp[i1];
            i1++;
        }else{
            A[cur] = temp[i2];
            i2++;
        }
    }
}


void mergesort(int A[], int l, int r){
    if (l < r){
        int m = (l+r)/2;
        mergesort(A, l, m);
        mergesort(A, m+1, r);
        merge(A, l, r);
    }
}

int main(){
    int len;

    cout << "Enter the array size: ";
    cin >> len;
    int Array[len];
    cout << "Chosen numbers: ";
    for(int j = 0; j < len; j++){
        cin >> Array[j];
    }
    cout << "\n";
    mergesort(Array, 0, len-1);
    cout << "Sorted array: ";
    for(int m = 0; m < len; m++){
        cout << Array[m] << " ";
    }
    cout << ("\n");     
}
