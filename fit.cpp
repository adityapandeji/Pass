#include <bits/stdc++.h>
using namespace std;

void firstFit(vector<int> blocksize, int bsize, vector<int> processsize, int psize)
{
    vector<int> allocation(psize, -1);
    for (int i = 0; i < psize; i++)
    {
        for (int j = 0; j < bsize; j++)
        {
            if (blocksize[j] >= processsize[i])
            {
                allocation[i] = j;
                blocksize[j] -= processsize[i];
                break;
            }
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < psize; i++)
    {
        cout << " " << i + 1 << "\t\t" << processsize[i] << "\t\t";
        if (allocation[i] != -1)
        {
            cout << allocation[i] + 1;
        }
        else
        {
            cout << "Not Allocated";
        }
        cout << endl;
    }
}

void nextFit(vector<int> blocksize, int bsize, vector<int> processsize, int psize)
{
    vector<int> allocation(psize, -1);
    int t = bsize - 1;
    int j = 0;
    for (int i = 0; i < psize; i++)
    {
        while (j < bsize)
        {
            if (blocksize[j] >= processsize[i])
            {
                allocation[i] = j;
                blocksize[j] -= processsize[i];
                t = (j - 1) % bsize;
                break;
            }
            if (t == j)
            {
                t = (j - 1) % bsize;
                break;
            }
            j = (j + 1) % bsize;
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < psize; i++)
    {
        cout << " " << i + 1 << "\t\t" << processsize[i] << "\t\t";
        if (allocation[i] != -1)
        {
            cout << allocation[i] + 1;
        }
        else
        {
            cout << "Not Allocated";
        }
        cout << endl;
    }
}

void bestFit(vector<int> blocksize, int bsize, vector<int> processsize, int psize)
{
    vector<int> allocation(psize, -1);

    for (int i = 0; i < psize; i++)
    {
        int bestIndex = -1;
        for (int j = 0; j < bsize; j++)
        {
            if (blocksize[j] >= processsize[i])
            {
                if (bestIndex == -1)
                {
                    bestIndex = j;
                }
                else if (blocksize[bestIndex] > blocksize[j])
                {
                    bestIndex = j;
                }
            }
        }

        if (bestIndex != -1)
        {
            allocation[i] = bestIndex;
            blocksize[bestIndex] -= processsize[i];
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < psize; i++)
    {
        cout << " " << i + 1 << "\t\t" << processsize[i] << "\t\t";
        if (allocation[i] != -1)
        {
            cout << allocation[i] + 1;
        }
        else
        {
            cout << "Not Allocated";
        }
        cout << endl;
    }
}

void worstFit(vector<int> blocksize, int bsize, vector<int> processsize, int psize)
{
    vector<int> allocation(psize, -1);

    for (int i = 0; i < psize; i++)
    {
        int bestIndex = -1;
        for (int j = 0; j < bsize; j++)
        {
            if (blocksize[j] >= processsize[i])
            {
                if (bestIndex == -1)
                {
                    bestIndex = j;
                }
                else if (blocksize[bestIndex] < blocksize[j])
                {
                    bestIndex = j;
                }
            }
        }
        if (bestIndex != -1)
        {
            allocation[i] = bestIndex;
            blocksize[bestIndex] -= processsize[i];
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < psize; i++)
    {
        cout << " " << i + 1 << "\t\t" << processsize[i] << "\t\t";
        if (allocation[i] != -1)
        {
            cout << allocation[i] + 1;
        }
        else
        {
            cout << "Not Allocated";
        }
        cout << endl;
    }
}
int main()
{
    int bsize, psize;
    cout << "Enter the number of processes : ";
    cin >> psize;
    cout << "Enter the number of blocks : ";
    cin >> bsize;
    vector<int> processsize(psize);
    for (int i = 0; i < psize; i++)
    {
        cout << "Enter the size of process no." << i + 1 << " : ";
        cin >> processsize[i];
    }
    vector<int> blocksize(bsize);
    for (int i = 0; i < bsize; i++)
    {
        cout << "Enter the size of block no." << i + 1 << " : ";
        cin >> blocksize[i];
    }

    int ch = -1;
    int nh;
    while (ch)
    {
        cout << " * * * M E N U * * * " << endl;
        cout << "1. BEST FIT" << endl;
        cout << "2. NEXT FIT" << endl;
        cout << "3. WORST FIT" << endl;
        cout << "4.FIRST FIT" << endl;
        cout << "Enter your choice : " << endl;
        cin >> nh;
        if (nh == 1)
        {
            bestFit(blocksize, bsize, processsize, psize);
        }
        else if (nh == 2)
        {
            nextFit(blocksize, bsize, processsize, psize);
        }
        else if (nh == 3)
        {
            worstFit(blocksize, bsize, processsize, psize);
        }
        else if (nh == 4)
        {
            firstFit(blocksize, bsize, processsize, psize);
        }
        else
        {
            exit(0);
        }
    }

    return 0;
}

// 212 417 112 426
// 100 500 200 300 600
// 212 417 112 426
// 100 500 200 300 600