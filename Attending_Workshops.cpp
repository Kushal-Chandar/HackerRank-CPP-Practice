#include <bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
struct WorkShop
{
    int startTime;
    int duration;
    int endTime;
};
struct Available_Workshops
{
    int n;
    WorkShop *arr;
};

//Implement the functions initialize and CalculateMaxWorkshops
Available_Workshops *initialize(int startTime[], int duration[], int n)
{
    Available_Workshops *ptr = new Available_Workshops();
    ptr->n = n;
    ptr->arr = new WorkShop[n];
    for (int i = 0; i < n; i++)
    {
        ptr->arr[i].startTime = startTime[i];
        ptr->arr[i].duration = duration[i];
        ptr->arr[i].endTime = (startTime[i] + duration[i]);
    }
    return ptr;
}

int CalculateMaxWorkshops(Available_Workshops *ptr)
{
    //* Interval Scheduling maximisation problem:
    //? greedy algorithm
    WorkShop *workshops = ptr->arr;
    int size = ptr->n;
    sort(workshops, workshops + size, //? mistake i didn't sort the last element
         [](WorkShop &a1, WorkShop &a2)
         {
             return a1.endTime < a2.endTime;
         });
    int max = 1;
    WorkShop &previous = workshops[0];
    for (int i = 1; i < size; i++)
    {
        if (workshops[i].startTime >= previous.endTime)
        {
            max++;
            previous = workshops[i];
        }
    }

    delete[] workshops; //contains an array pointing to the int
    delete ptr;         //can be delete contains pointer to pointer and an int
    return max;
}

int main(int argc, char *argv[])
{
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int *start_time = new int[n];
    int *duration = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> duration[i];
    }

    Available_Workshops *ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;

    return 0;
}
