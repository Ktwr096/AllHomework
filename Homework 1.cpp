#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void minMax(int a, int b, int c)
{
    int min = a;
    int max = a;

    if (b < min) min = b;
    if (c < min) min = c;

    if (b > max) max = b;
    if (c > max) max = c;

    cout << "Min = " << min << endl;
    cout << "Max = " << max << endl;

}

void countElements(int arr[], int size, int& pos, int& neg, int& zero)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0) pos++;
        else if (arr[i] < 0) neg++;
        else zero++;
    }
}

void sortArray(int arr[], int size, int mode = 1)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if ((mode == 1 && arr[j] < arr[j + 1]) ||
                (mode == 0 && arr[j] > arr[j + 1]))
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    //1
    int a, b, c;

    cin >> a >> b >> c;

    minMax(a, b, c);

    //2
    srand(time(0));

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 21 - 10;

    int pos = 0, neg = 0, zero = 0;

    countElements(arr, n, pos, neg, zero);

    cout << "Positive: " << pos << endl;
    cout << "Negative: " << neg << endl;
    cout << "Zero: " << zero << endl;


    //3
    srand(time(0));

    const int SIZE = 10;
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }

    cout << "\n\n";

    sortArray(arr, SIZE, 0);

    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }
}
