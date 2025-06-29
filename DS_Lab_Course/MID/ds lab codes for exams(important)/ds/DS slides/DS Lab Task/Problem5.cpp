#include <iostream>

using namespace std;

const int MAX_SIZE=100;
int arr[MAX_SIZE];
int sz=0;

void array_input();
void array_output();
void print_reverse();
void insert_end();
void insert_position();
void delete_end();
void delete_x();
void delete_position();
void highest_lowest();
void count_data();
void search_x();

int main()
{
    int choice;
    int data,pos;

    cout<<"Enter the number of elements: ";
    cin>>sz;

    if (sz>MAX_SIZE||sz<=0)
        {
        cout << "Invalid array size! Size should be between 1 and " << MAX_SIZE << "."<<endl;
        return 1;
    }

    cout << "Enter " << sz << " elements:"<<endl;
    for (int i = 0; i < sz; ++i)
        {
        cin>>arr[i];
    }

   while(choice!=12)
    {
        cout << "Menu: "<<endl;
        cout << "1. Input data into array"<<endl;
        cout << "2. Traverse array and display"<<endl;
        cout << "3. Print array in reverse order"<<endl;
        cout << "4. Insert a new item at the end of array"<<endl;
        cout << "5. Insert a new item at a specific position"<<endl;
        cout << "6. Delete the last item"<<endl;
        cout << "7. Delete an item by value"<<endl;
        cout << "8. Delete an item by position"<<endl;
        cout << "9. Find highest and lowest items"<<endl;
        cout << "10. Count occurrences of a particular item"<<endl;
        cout << "11. Search for an item (linear search)"<<endl;
        cout << "12. Exit ";
        cout << "Enter your choice: ";
        cin>>choice;

        switch (choice)
        {
            case 1:
                array_input();
                break;
            case 2:
                array_output();
                break;
            case 3:
                print_reverse();
                break;
            case 4:
                insert_end();
                break;
            case 5:
                insert_position();
                break;
            case 6:
                delete_end();
                break;
            case 7:
                delete_x();
                break;
            case 8:
                delete_position();
                break;
            case 9:
                highest_lowest();
                break;
            case 10:
                count_data();
                break;
            case 11:
                search_x();
                break;
            case 12:
                cout << "Exiting program..."<<endl;
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 12."<<endl;
                break;
        }}

    return 0;
}

void array_input()
{
    cout<<"Enter the number of elements: ";
    cin>>sz;

    if(sz>MAX_SIZE||sz <= 0)
        {
        cout<<"Invalid array size! Size should be between 1 and " <<MAX_SIZE << " "<<endl;
        return;
    }

    cout<<"Enter "<<sz<<"elements: "<<endl;
    for (int i=0;i<sz; ++i)
        {
        cin >>arr[i];
    }
}

void array_output()
{
    if (sz>0)
        {
        cout << "Array elements: ";
        for (int i=0; i<sz;++i)
        {
            cout<<arr[i]<< " ";
        }
        cout << endl;
    } else
    {
        cout << "Array is empty."<<endl;
    }
}

void print_reverse()
{
    if(sz>0)
        {
        cout<<"Array elements in reverse order: ";
        for(int i = sz - 1; i >= 0; --i) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    } else
    {
        cout<<"Array is empty.\n";
    }
}

void insert_end()
{
    if (sz < MAX_SIZE)
        {
        int data;
        cout << "Enter the data to insert at the end: ";
        cin >> data;
        arr[sz++] = data;
        cout << "Element inserted successfully."<<endl;
    } else {
        cout << "Array is full. Cannot insert more elements."<<endl;
    }
}

void insert_position()
{
    if (sz < MAX_SIZE)
        {
        int pos, data;
        cout << "Enter the position to insert (0-" << sz << "): ";
        cin >> pos;
        if (pos < 0 || pos > sz) {
            cout << "Invalid position! "<<endl;
            return;
        }
        cout << "Enter the data to insert: ";
        cin >> data;

        // Shift elements to the right
        for (int i = sz; i > pos; --i) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = data;
        ++sz;
        cout << "Element inserted successfully."<<endl;
    } else
    {
        cout << "Array is full. Cannot insert more elements."<<endl;
    }
}

void delete_end()
{
    if (sz > 0)
        {
        --sz;
        cout << "Last element deleted successfully."<<endl;
    } else {
        cout << "Array is empty. No elements to delete."<<endl;
    }
}

void delete_x()
{
    if (sz > 0)
        {
        int data, found_index = -1;
        cout << "Enter the data to delete: ";
        cin >> data;

        for (int i =0;i < sz; ++i)
            {
            if (arr[i]==data)
            {
                found_index =i;
                break;
            }
        }

        if (found_index != -1)
            {
            for (int i = found_index; i < sz - 1; ++i)
                {
                arr[i] = arr[i + 1];
            }
        --sz;
            cout << "Element deleted successfully."<<endl;
        } else {
            cout << "Element not found in array."<<endl;
        }
    } else {
        cout << "Array is empty. No elements to delete."<<endl;
    }
}

void delete_position()
{
    if (sz > 0) {
        int pos;
        cout << "Enter the position to delete (0-" << sz - 1<< "): ";
        cin >> pos;
        if (pos < 0 || pos >= sz)
            {
            cout << "Invalid position!"<<endl;
            return;
        }
        for (int i = pos;i<sz - 1;++i)
            {
            arr[i]=arr[i + 1];
        }
        --sz;
        cout <<"Element deleted successfully."<<endl;
    } else {
        cout << "Array is empty. No elements to delete."<<endl;
    }
}

void highest_lowest()
{
    if (sz > 0)
        {
        int highest = arr[0];
        int lowest = arr[0];

        for (int i=1;i<sz;++i)
            {
            if (arr[i]>highest)
            {
                highest=arr[i];
            }
            if (arr[i]<lowest)
            {
                lowest=arr[i];
            }
        }

        cout<<"Highest element: " << highest << endl;
        cout<<"Lowest element: " << lowest << endl;
    } else
    {
        cout << "Array is empty. No elements to find highest and lowest."<<endl;
    }
}

void count_data()
{
    if (sz > 0)
        {
        int data, count = 0;
        cout<<"Enter the data to count: ";
        cin>>data;

        for (int i =0;i<sz;++i)
            {
            if (arr[i]==data)
            {
                ++count;
            }
        }

        cout << "Count of " << data << " in array: " << count << endl;
    } else
    {
        cout << "Array is empty. No elements to count."<<endl;
    }
}

void search_x()
{
    if (sz>0)
        {
        int data;
        cout<<"Enter the data to search: ";
        cin>>data;

        for (int i=0;i<sz;++i)
            {
            if (arr[i]==data)
            {
                cout<<"Element found at position " <<i<< endl;
                return;
            }
        }

        cout<<"Element not found in array."<<endl;
    } else
    {
        cout<<"Array is empty. No elements to search."<<endl;
    }
}
