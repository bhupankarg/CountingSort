#include <iostream>
#include <vector>
using namespace std;

void counting_sort(vector<int>& arr)
{
	int max = arr[0];
	for(int i = 1; i < arr.size(); i++)
	{
		if(arr[i] > max) max = arr[i];
	}
	int count[max + 1] = { 0 };
	for(int i = 0; i < arr.size(); i++)
	{
		count[arr[i]]++;
	}
	int i = 0, j = 0;
	while(i < max + 1)
	{
		if(count[i] != 0)
		{
			arr[j] = i;
			count[i]--;
			j++;
		}
		else
		{
			i++;
		}
	}
}

int main()
{
    int total;
    cout << "How many numbers you want to sort?" << endl;
    cin >> total;
    vector<int> arr(total);
    cout << "Enter the " << total << " numbers" << endl;
    for(int i = 0; i < total; i++)
    {
    	int val;
        cin >> val;
        arr[i] = val;
    }
    cout << "Before sorting..." << endl;
    for(int i = 0; i < total; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "Applying counting sort..." << endl;
    counting_sort(arr);
    cout << "After sorting..." << endl;
    for(int i = 0; i < total; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}