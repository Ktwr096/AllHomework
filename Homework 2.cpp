#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void max1D(int arr[], int size, int& max)
{
    max = arr[0];

    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
}


void max2D(int arr[][10], int rows, int cols, int& max)
{
    max = arr[0][0];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (arr[i][j] > max)
                max = arr[i][j];
}


int findElement(int arr[], int size, int x, int i = 0)
{
    if (i == size)   // кінець масиву
        return -1;

    if (arr[i] == x)
        return i;

    return findElement(arr, size, x, i + 1);
}

int main()
{
    srand(time(0));

  //1  
    int a[5];

    for (int i = 0; i < 5; i++)
        a[i] = rand() % 100;

    int max1;

    max1D(a, 5, max1);

    cout << "Max 1D = " << max1 << endl;

    

    int b[3][10];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 10; j++)
            b[i][j] = rand() % 100;

    int max2;

    max2D(b, 3, 10, max2);

    cout << "Max 2D = " << max2 << endl;




    //2

    const int SIZE = 12;
    int arr[SIZE] = { 5, 2, 9, 1, 7, 3, 8, 6, 4, 10, 11, 12 };

    int x;
    cin >> x;

    int pos = findElement(arr, SIZE, x);

    if (pos == -1)
        cout << "Not found" << endl;
    else
        cout << "Position: " << pos << endl;


    return 0;
}
