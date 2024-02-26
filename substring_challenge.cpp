#include <iostream>
#include <vector>
using namespace std;
int main()
{
    bool char1 = false , char2 = false ,  char3 = false;
    int n;
    cin >> n;
    vector<char> gamal(n);
    vector<char> sobhey(3);
    for(int i =0 ; i < n ; i++)
    {
        cin >> gamal[i];
    }
    for(int i =0 ; i < 3 ; i++)
    {
        cin >> sobhey[i];
    }
    for(int i =0 ; i < n ; i++)
    {
            if(sobhey[0]==gamal[i])
            {
                char1= true;
                break;
            }
    }
    for(int i =0 ; i < n ; i++)
    {
        if(sobhey[1]==gamal[i])
        {
            char2= true;
            break;
        }
    } for(int i =0 ; i < n ; i++)
    {
        if(sobhey[2]==gamal[i])
        {
            char3= true;
            break;
        }
    }

    (char1&&char2&&char3)?cout << "YES" : cout << "NO";


    return 0;
}