#include <iostream>
#include <deque>
using namespace std;

//? Random access in a deque is O(n)
//? brute force exceedes tle

void printKMax(int arr[], int n, int k)
{
    //use deque to store index rather than elements
    //we will store useful elements(is max of this window or (will be max of next windows))
    //keep checking and popping the last element of the deque, if it is less than element being added from the array

    //maximum element of the current window will always be the first element in deque
    //and the following elements will have the potential to be the maximum elements in the following window

    deque<int> window;
    int i = 0;
    //we will have maximum of first k elements and other useful elements in the window
    for (; i < k; i++)
    {
        while (!window.empty() && arr[window.back()] <= arr[i])
        {
            window.pop_back();
        }
        window.push_back(i);
    }

    //continuing the process for rest of the elements
    for (; i < n; i++)
    {
        cout << arr[window.front()] << ' ';

        //remove index which are out of window
        while (!window.empty() && window.front() <= i - k)
        {
            window.pop_front();
        }

        while (!window.empty() && arr[window.back()] <= arr[i])
        {
            window.pop_back();
        }
        window.push_back(i);
    }
    cout << arr[window.front()] << '\n';
}

int main()
{

    int t;
    cin >> t;
    while (t > 0)
    {
        int n, k;
        cin >> n >> k;
        int i;
        int arr[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}