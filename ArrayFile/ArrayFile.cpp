#include <iostream>
using namespace std;

const int MAX = 200;

void task1()
{
    double A[MAX], B[MAX];
    int N, i, nB = 0;

    cout << "Enter size of array N: ";
    cin >> N;

    for (i = 0; i < N; i++)
    {
        cout << "A[" << i << "] = ";
        cin >> A[i];
    }

    for (i = 0; i < N; i++)
        if (A[i] < 0)
            B[nB++] = A[i];

    cout << "Array B :" << endl;

    for (i = 0; i < nB; i++)
        cout << B[i] << "\t";

    cout << endl;
}

void task2()
{
    int* A;
    int N, T;
    int i;
    int maxNeg;
    bool found = false;

    cout << "Enter size of array N: ";
    cin >> N;

    A = new int[N];

    cout << "Enter number T: ";
    cin >> T;

    for (i = 0; i < N; i++)
    {
        cout << "A[" << i << "] = ";
        cin >> A[i];
    }

    for (i = 0; i < N; i++)
    {
        if (A[i] == T)
            break;

        if (A[i] < 0)
        {
            if (!found || A[i] > maxNeg)
            {
                maxNeg = A[i];
                found = true;
            }
        }
    }

    if (found)
        cout << "Maximum negative element = " << maxNeg << endl;
    else
        cout << "No negative elements found before T" << endl;

    delete[] A;
}

void task3()
{
    int A[MAX], B[MAX];
    int N;
    int i, j, k;
    int nB = 0;
    bool repeated;

    cout << "Enter size of array N: ";
    cin >> N;

    for (i = 0; i < N; i++)
    {
        cout << "A[" << i << "] = ";
        cin >> A[i];
    }

    for (i = 0; i < N; i++)
    {
        repeated = false;

        for (j = 0; j < N; j++)
        {
            if (i != j && A[i] == A[j])
                repeated = true;
        }

        if (repeated)
        {
            bool exist = false;

            for (k = 0; k < nB; k++)
                if (B[k] == A[i])
                    exist = true;

            if (!exist)
                B[nB++] = A[i];
        }
    }

    cout << "Array B :" << endl;

    for (i = 0; i < nB; i++)
    {
        cout << B[i] << "\t";
        if ((i + 1) % 5 == 0)
            cout << endl;
    }

    cout << endl;
}

int main()
{
    int choice;

    do {
        cout << endl;
        cout << "MENU" << endl;
        cout << "1 - Task 1" << endl;
        cout << "2 - Task 2" << endl;
        cout << "3 - Task 3" << endl;
        cout << "0 - Exit" << endl;
        cout << "Choose: ";
        cin >> choice;

        switch (choice)
        {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 0: cout << "Exit program" << endl; break;
        default: cout << "Wrong choice" << endl;
        }

    } while (choice != 0);

    return 0;
}