#include <iostream>

using namespace std;

template<typename T> class Heap {
    public:
        T *H;
        int currentDim, maxDim;

        Heap(int maxDim) {
            this->maxDim = maxDim;
            H = new T[this->maxDim];
            currentDim = -1;
        }

        void insertElement(T x) {
            if (currentDim == maxDim-1) {
                cout<< "Error!"<<endl;
                return;
            }
            currentDim++;
            H[currentDim] = x;
            filterUp(currentDim);
       }
       
	T peek() {
            if (currentDim == -1) {
                cout<< "Error!"<<endl;
                T x;
                return x;
            }

            return H[0];
        }

 T deleteElement() {
            if (currentDim == -1) {
                cout<< "Error!"<<endl;
                T x;
                return x;
            }

            T minValue = H[0];
            H[0] = H[currentDim];
            currentDim--;
     if (currentDim > 0)
                filterDown();

            return minValue;
        }

        void filterUp(int i) {
            int parent;
            T vaux;

            parent = (i-1) / 2;
           while (i > 0 && H[parent] > H[i]) {
                vaux = H[parent];
                H[parent] = H[i];
                H[i] = vaux;

                i = parent;
                parent = (i-1) / 2;
            }
        }
        
 void filterDown() {
           int i = 0;
            T vaux;

            while (1) {
                if (2 * (i + 1) > currentDim) {
                    if (2 * i + 1 > currentDim)
                        break;
                     else
                         if (H[2 * i + 1] < H[i]) {
                        vaux = H[2 * i+1];
                        H[2 * i+1] = H[i];
                        H[i] = vaux;
                        i = 2 * i+1;
                         }
                    else
                        break;
                }
                else {
               
                    if (H[2 * (i+1) ] <= H[2 * i + 1] && H[2 * (i+1) ] < H[i]) {
                        vaux = H[2 * (i+1)];
                        H[2 * (i+1)] = H[i];
						H[i] = vaux;
                        i = 2 * (i+1);
                    }
                    else
                    if (H[2 * i + 1] <= H[2 * (i+1)] && H[2 * i + 1] < H[i]) {
                        vaux = H[2 * i + 1];
                        H[2 * i + 1] = H[i];
                        H[i] = vaux;
                        i = 2 * i + 1;
                    }
                    else
                        break;
                }
            }
        }
};



       
