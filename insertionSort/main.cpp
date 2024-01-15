#include <iostream>

using namespace std;

template <class Type>
void insertionSort(Type list[], int length)
{
    for (int firstIndexOutOfOrder = 1; firstIndexOutOfOrder<length; firstIndexOutOfOrder++) // number of iterations
        {
            if (list[firstIndexOutOfOrder] < list[firstIndexOutOfOrder-1])
                {
                    Type temp = list[firstIndexOutOfOrder];
                    int location = firstIndexOutOfOrder;


                    do
                        {
                            list[location] = list[location-1];
                            location--;
                        }
                    while (location > 0 && list[location - 1] > temp);

                    list[location] = temp;
                }
        }

    for (int i = 0;i<length;i++)
        {
            cout << list[i] << " ";
        }
}

int main()
{
    int unsortedArr[] = {10,17,24,30,23,16,45,35};

    insertionSort(unsortedArr,8);

    return 0;
}
