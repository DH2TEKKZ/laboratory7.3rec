#include <iomanip>
#include <iostream>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int low, const int high, int i, int j);
void Input(int** a, const int rowCount, const int colCount, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
bool CheckColumnForZero(int** a, int rowCount, int col, int row = 0);
void CountColumnsWithZero(int** a, const int rowCount, const int colCount, int& count, bool& result, int col = 0);
bool Part1_CountColsWithZero(int** a, const int rowCount, const int colCount, int& count, bool& result);
void CheckRowForLongestSeries(int** a, int colCount, int& longestRow, int& maxLength, int currentLength, int currentValue, int row, int col);
void FindLongestRow(int** a, const int rowCount, const int colCount, int& longestRow, int& maxLength, int row = 0);
void rowSeria(int** a, const int rowCount, const int colCount, int& longestRow, int& maxLength);

int main()
{
    srand((unsigned)time(NULL));

    int low = -45;
    int high = 24;

    int rowCount, colCount;

    cout << "rowCount= "; cin >> rowCount;
    cout << "colCount= "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, low, high, 0, 0);
    Input(a, rowCount, colCount, 0, 0);
    Print(a, rowCount, colCount, 0, 0);

    int count = 0;
    bool result = false;

    Part1_CountColsWithZero(a, rowCount, colCount, count, result);

    if (result)
        cout << "count = " << count << endl;
    else
        cout << "there are no zero elements" << endl;

    cout << endl;

    int longestRow = -1;
    int maxLength = 0;

    rowSeria(a, rowCount, colCount, longestRow, maxLength);

    cout << "count= " <<  longestRow << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int low, const int high, int i, int j)
{
    a[i][j] = low + rand() % (high - low + 1);
    if (j < colCount - 1) {
        Create(a, rowCount, colCount, low, high, i, j + 1);
    }
    else if (i < rowCount - 1) {
        Create(a, rowCount, colCount, low, high, i + 1, 0);
    }
}

void Input(int** a, const int rowCount, const int colCount, int i, int j)
{
    cout << "a[" << i << "][" << j << "] = "; cin >> a[i][j];
    if (j < colCount - 1) {
        Input(a, rowCount, colCount, i, j + 1);
    }
    else if (i < rowCount - 1) {
        Input(a, rowCount, colCount, i + 1, 0);
    }
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
    cout << setw(4) << a[i][j];
    if (j < colCount - 1) {
        Print(a, rowCount, colCount, i, j + 1);
    }
    else if (i < rowCount - 1) {
        cout << endl;
        Print(a, rowCount, colCount, i + 1, 0);
    }
    else {
        cout << endl;
    }
}

bool CheckColumnForZero(int** a, int rowCount, int col, int row)
{
    if (row >= rowCount) {
        return false;
    }
    if (a[row][col] == 0) {
        return true;
    }
    return CheckColumnForZero(a, rowCount, col, row + 1);
}

void CountColumnsWithZero(int** a, const int rowCount, const int colCount, int& count, bool& result, int col)
{
    if (col >= colCount) {
        return;
    }
    if (CheckColumnForZero(a, rowCount, col)) {
        result = true;
        count++;
    }
    CountColumnsWithZero(a, rowCount, colCount, count, result, col + 1);
}

bool Part1_CountColsWithZero(int** a, const int rowCount, const int colCount, int& count, bool& result)
{
    CountColumnsWithZero(a, rowCount, colCount, count, result);
    return result;
}

void CheckRowForLongestSeries(int** a, int colCount, int& longestRow, int& maxLength, int currentLength, int currentValue, int row, int col)
{
    if (col >= colCount) {
        if (currentLength > maxLength) {
            maxLength = currentLength;
            longestRow = row;
        }
        return;
    }
    if (a[row][col] == currentValue) {
        CheckRowForLongestSeries(a, colCount, longestRow, maxLength, currentLength + 1, currentValue, row, col + 1);
    }
    else {
        CheckRowForLongestSeries(a, colCount, longestRow, maxLength, 1, a[row][col], row, col + 1);
    }
}

void FindLongestRow(int** a, const int rowCount, const int colCount, int& longestRow, int& maxLength, int row)
{
    if (row >= rowCount) {
        return;
    }

    CheckRowForLongestSeries(a, colCount, longestRow, maxLength, 1, a[row][0], row, 1);
    FindLongestRow(a, rowCount, colCount, longestRow, maxLength, row + 1);
}

void rowSeria(int** a, const int rowCount, const int colCount, int& longestRow, int& maxLength)
{
    FindLongestRow(a, rowCount, colCount, longestRow, maxLength);
}