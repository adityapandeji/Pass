#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
class EleAlgorithms
{
public:
    vector<pair<int, bool>> nodeArray;
    int coordinator;
    int size;

    EleAlgorithms(int n)
    {
        size = n;
        nodeArray.resize(size, {0, true});
    }

    void input()
    {
        int n;
        cout << "Enter the no. of nodes : ";
        cin >> n;
        vector<pair<int, bool>> nodePr(n, {0, true});
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter the id for node" << i + 1 << " : ";
            cin >> nodeArray[i].first;
            if (nodeArray[i].first > maxi)
            {
                maxi = nodeArray[i].first;
                coordinator = i;
            }
        }
    }

    int failCor(vector<pair<int, bool>> &v)
    {
        v[coordinator].second = false;
        return coordinator;
    }

    int failNod(vector<pair<int, bool>> &v, int i)
    {
        v[i].second = false;
        return i;
    }

    void Ring()
    {
        vector<pair<int, bool>> ring = nodeArray;

        int failed;
        failed = failCor(ring);
        cout << "Node " << ring[failed].first << " failed !" << endl;
        // srand(time(0));
        // int i = rand()%(ring.size());
        // failed=failNod(ring,i);
        int st;
        while (ring[st].second == false)
            st = rand() % ring.size();
        cout << "Detected by : " << ring[st].first << endl;
        

        int ini = st;
        vector<int> res;
        do
        {
            int nxt = (st + 1) % size;

            if (ring[nxt].second == true && ring[st].second == true)
            {
                cout << ring[st].first << " elects " << ring[nxt].first << endl;
                sleep(1);
                res.push_back(ring[st].first);
            }
            else if (ring[nxt].second == false && ring[st].second == true)
            {
                nxt = (nxt + 1) % size;
                cout << ring[st].first << " elects " << ring[nxt].first << endl;
                sleep(1);
                res.push_back(ring[st].first);
            }

            st = nxt;

        } while (st != ini);

        cout << "Result" << endl;
        for (auto i : res)
        {
            cout << i << " ";
        }
        cout << endl;
        int newcordinator = *max_element(res.begin(), res.end());
        cout << "New coordinator will be " << newcordinator << endl;
    }

    void Bully()
    {
        vector<pair<int, bool>> bull = nodeArray;

        int failed;
        // failed = failCor(bull);
        srand(time(0));
        int i = rand()%(bull.size());
        failed=failNod(bull,i);
        cout << "Node " << bull[failed].first << " failed !" << endl;
        int st;
        while (bull[st].second == false)
            st = rand() % bull.size();
        cout << "Detected by : " << bull[st].first << endl;
        

        for (int i = st; i < size; i++)
        {
            int ackcnt = 0;
            for (int j = 0; j < size; j++)
            {
                if (bull[j].first > bull[i].first)
                {
                    cout << "Election from " << bull[i].first << " to " << bull[j].first <<"  ->";
                    if (bull[j].second == true)
                    {
                        ackcnt++;
                        cout << "Ack OK " << endl;
                        sleep(1);
                    }
                    else{
                        cout<<"Ack lost  "<<endl;
                        sleep(1);
                    }
                }
            }

            if(ackcnt==0){
                cout<<"New Co-ordinate elected : "<<bull[i].first<<endl;
                sleep(1);
                break;
            }
        }
    }
};

int main()
{
    EleAlgorithms e(8);
    e.input();
    e.Ring();
    // e.Bully();

    return 0;
}