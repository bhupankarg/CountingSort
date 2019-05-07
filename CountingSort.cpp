#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& arr, int size)
{
    vector<int> countVec(size, 0);
    
    for(int i = 0; i < arr.size(); i++)
        ++countVec[arr[i]];
    int totalSorted = 0;
    for(int i = 0; i < countVec.size(); i++)
    {
        if(countVec[i] != 0)
        {
            for(int j = totalSorted; j < totalSorted+countVec[i]; j++)
                arr[j] = i;
            totalSorted += countVec[i];
        }
    }
}

int main()
{
    int total, maxVal, val;
    cout << "How many numbers you want to sort?" << endl;
    cin >> total;
    vector<int> arr;
    cout << "Enter the " << total << " numbers" << endl;
    cin >> val;
    arr.push_back(val);
    maxVal = val;
    for(int i = 1; i < total; i++)
    {
        cin >> val;
        arr.push_back(val);
        if(maxVal < val)
        	maxVal = val;
    }
    cout << "Before sorting" << endl;
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
    countingSort(arr, maxVal+1);
    cout << "After sorting" << endl;
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}

