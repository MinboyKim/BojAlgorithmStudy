
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    int Choko[2000];
    cin >> N >> K;

    for(int i=0; i<N; i++){
        int C;
        cin >> C;
        Choko[i] = C;
    }

    int Min = 0;                     //what bucket has min choko
    int eat = 0;                     // eat choko num
    int date = 0;                    // elapsed date
    while (Min + K <= N-1) {         // N-1 cause end idx is less then num of choko
        sort(Choko, Choko + N);
        if (Choko[Min] == Choko[Min + K]) {
            Min++;
            continue;
        }
        while (Choko[Min] < Choko[Min + K]) {
            eat++;
            Choko[Min + K]--;
        }       
        date++;
    }

    cout << eat << " " << date;

    return 0;
}

