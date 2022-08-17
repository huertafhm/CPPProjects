#include <iostream>

using namespace std;

int A[] = {1,2,3,4,5};
int sizeA = sizeof(A)/sizeof(int);      //'sizeof' returns the size of the array in bytes, not the number of elements of the array
                                        // that's why we divide between the value of an int

/*
The 'multiplyOtherPositions' method will return an array where the element in a given position is the result of the multiplication
of the other positions of another array, in this case array 'A' previously declared where:
A[0] = 1;
A[1] = 2;
A[2] = 3;
A[3] = 4;
A[4] = 5;

The desired result is:
R[0] = A[1] * A[2] * A[3] * A[4] = 2 * 3 * 4 * 5 = 120
R[1] = A[0] * A[2] * A[3] * A[4] = 1 * 3 * 4 * 5 = 60
R[2] = A[0] * A[1] * A[3] * A[4] = 1 * 2 * 4 * 5 = 40
R[3] = A[0] * A[1] * A[2] * A[4] = 1 * 2 * 3 * 5 = 30
R[4] = A[0] * A[1] * A[2] * A[3] = 1 * 2 * 3 * 4 = 24

*/

int * multiplyOtherPositions(){         // The return type is a pointer since C++ doesn't allow for array return type in functions.
    static int R[5];                    // Has to be static since c++ doesn't return the address of a local variable to outside the function
    int sizeR = sizeof(R)/sizeof(int);
    std::fill_n(R, sizeR, 1);           // The R vector is initialized to 1 in all its variables so the multiplication is made correctly
    cout<<"size of R = "<<sizeR<<endl;
    
    for (int i = 0; i < sizeR; i++){
        cout << "----------In i = " <<i<< endl;
        for (int j = 0; j < sizeR; j++){
            if (i != j){
                //cout << "In j = " <<j<< "; " << A[j] << endl;
                R[i] *= A[j];
                //cout << "R[" <<i<< "] = "<<R[i]<<endl<<endl;
            }
        }
    }
    
    return R;
}

int main()
{
    int *P = multiplyOtherPositions();
    //int sizeP = sizeof(P)/sizeof(int);        // Size of pointer is 8 or 4, depending on processor
    //cout<<"size of P = "<<sizeP<<endl;
    
    for (int i = 0; i < sizeA; i++){
        cout<<"P["<<i<<"] = "<<P[i]<<endl;
    }
    
    return 0;
}