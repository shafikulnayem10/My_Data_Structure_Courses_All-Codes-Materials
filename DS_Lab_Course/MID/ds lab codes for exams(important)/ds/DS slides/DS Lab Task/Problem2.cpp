#include <iostream>
using namespace std;

int main() {
    int mat[100][100],r,c;

    cout<<"Enter Row Size: ";
    cin>>r;
    cout<<"Enter Column Size: ";
    cin>>c;


    cout<<"Enter Matrix Elements: " << endl;
    for(int i=0;i<r;i++)
        {
        for (int j=0;j<c;j++)
        {
            cin>>mat[i][j];
        }
    }

    cout<<"Upper right triangle elements of the matrix:" <<endl;
    for(int i=0;i<r;i++)
        {
        for (int j=0;j<c;j++)
        {
            if(j>=i)
                {
                cout<<mat[i][j]<<" ";
                }
    else
            {
                cout<< "  ";
            }
        }
cout<<endl;
    }

    return 0;
}
