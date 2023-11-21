#include <bits/stdc++.h>
using namespace std;

class process
{
public:
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int id;
    int priority;
    process()
    {
        at = 0;
        bt = 0;
        ct = 0;
        tat = 0;
        wt = 0;
        id = 0;
        priority = 0;
    }
};

bool comp_at(const process &p1, const process &p2)
{
    return p1.at < p2.at;
}

bool comp_pt(const process &p1, const process &p2)
{
    if (p1.at == p2.at)
    {
        return p1.priority < p2.priority;
    }
    else
    {
        return p1.at < p2.at;
    }
}

class Algorithms
{

    int size;

public:
    Algorithms(int n)
    {

        size = n;
    }

    void avg_tat_n_wt(vector<process> &processes)
    {
        float avgtat = 0;
        float avgwt = 0;
        for (int i = 0; i < size; i++)
        {
            avgtat += processes[i].tat;
            avgwt += processes[i].wt;
        }
        cout << "\nAverage turn around time : " << avgtat / size << endl;
        cout << "\nAverage waiting time : " << avgwt / size << endl;
    }
    void input(vector<process> &processes)
    {

        for (int i = 0; i < size; i++)
        {
            process p;
            cout << "Enter id : ";
            cin >> p.id;
            cout << "Enter arrival time : ";
            cin >> p.at;
            cout << "Enter burst time : ";
            cin >> p.bt;
            processes.push_back(p);
        }
    }

    void input1(vector<process> &processes)
    {

        for (int i = 0; i < size; i++)
        {
            process p;
            cout << "Enter id : ";

            cin >> p.id;
            cout << "Enter priority : ";
            cin >> p.priority;
            cout << "Enter arrival time : ";
            cin >> p.at;
            cout << "Enter burst time : ";
            cin >> p.bt;

            processes.push_back(p);
        }
    }

    void FCFS()
    {
        vector<process> processes;
        input(processes);
        sort(processes.begin(), processes.end(), comp_at);

        // completion time
        processes[0].ct = processes[0].at + processes[0].bt;
        // turn around time
        processes[0].tat = processes[0].ct - processes[0].at;
        // waiting time
        processes[0].wt = processes[0].tat - processes[0].bt;
        cout << "ID\tAT\tBT\tCT\tTAT\tWT" << endl;
        cout << processes[0].id << "\t" << processes[0].at << "\t" << processes[0].bt << "\t"
             << processes[0].ct << "\t" << processes[0].tat << "\t" << processes[0].wt << endl;
        for (int i = 1; i < size; i++)
        {
            if (processes[i].at < processes[i - 1].ct)
            {
                processes[i].ct = processes[i - 1].ct + processes[i].bt;
            }
            else
            {
                processes[i].ct = processes[i].at + processes[i].bt;
            }

            // turn around time
            processes[i].tat = processes[i].ct - processes[i].at;
            // waiting time
            processes[i].wt = processes[i].tat - processes[i].bt;

            cout << processes[i].id << "\t" << processes[i].at << "\t" << processes[i].bt << "\t"
                 << processes[i].ct << "\t" << processes[i].tat << "\t" << processes[i].wt << endl;
        }

        avg_tat_n_wt(processes);
    }

    void SJFp()
    {
        vector<process> processes;
        input(processes);
        vector<int> btcpy(size, 0);
        for (int i = 0; i < size; i++)
        {
            btcpy[i] = processes[i].bt;
        }

        int complete = 0;
        int t = 0;
        int mini = INT_MAX;
        int shortest = 0;
        int finish_time;
        bool check = false;

        while (complete != size)
        {
            for (int j = 0; j < size; j++)
            {
                // process before the arrival time and having minimum burst time
                if (processes[j].at <= t && btcpy[j] < mini && btcpy[j] > 0)
                {
                    mini = btcpy[j];
                    shortest = j;
                    check = true;
                }
            }
            if (check == false)
            {
                t++;
                continue;
            }

            btcpy[shortest]--;
            mini = btcpy[shortest];
            if (mini == 0)
            {
                mini = INT_MAX;
            }

            if (btcpy[shortest] == 0)
            {
                complete++;
                check = false;
                finish_time = t + 1;
                processes[shortest].ct = finish_time;
            }
            t++;
        }

        for (int i = 0; i < size; i++)
        {
            // turn around time
            processes[i].tat = processes[i].ct - processes[i].at;
            // waiting time
            processes[i].wt = processes[i].tat - processes[i].bt;
            if (processes[shortest].wt < 0)
            {
                processes[shortest].wt = 0;
            }
            cout << processes[i].id << "\t" << processes[i].at << "\t" << processes[i].bt << "\t"
                 << processes[i].ct << "\t" << processes[i].tat << "\t" << processes[i].wt << endl;
        }

        avg_tat_n_wt(processes);
    }

    void priority()
    {
        vector<process> processes;
        input1(processes);
        sort(processes.begin(), processes.end(), comp_pt);
        vector<bool> chk(size, false);
        int complete = 1;
        processes[0].ct = processes[0].bt + processes[0].at;
        int t = processes[0].bt + processes[0].at;
        int pr = INT_MAX;
        int shortest = 0;
        chk[0] = true;
        cout << processes[0].id << endl;
        while (complete != size)
        {
            for (int i = 1; i < size; i++)
            {

                if (chk[i] != true && processes[i].at <= t && processes[i].priority < pr)
                {
                    pr = processes[i].priority;
                    shortest = i;
                }
            }
            chk[shortest] = true;
            complete++;
            t += processes[shortest].bt;
            processes[shortest].ct = t;
            pr = INT_MAX;
        }

        cout << "ID\tAT\tBT\tCT\tTAT\tWT" << endl;
        for (int i = 0; i < size; i++)
        {
            // turn around time
            processes[i].tat = processes[i].ct - processes[i].at;
            // waiting time
            processes[i].wt = processes[i].tat - processes[i].bt;
            if (processes[shortest].wt < 0)
            {
                processes[shortest].wt = 0;
            }
            cout << processes[i].id << "\t" << processes[i].at << "\t" << processes[i].bt << "\t"
                 << processes[i].ct << "\t" << processes[i].tat << "\t" << processes[i].wt << endl;
        }

        avg_tat_n_wt(processes);
    }

    void Round_Robin()
    {
        vector<process> processes;
        input(processes);
        sort(processes.begin(), processes.end(), comp_at);
        queue<process> q;
        q.push(processes[0]);
        int t = processes[0].at;
        int prev = 0;
        int qtime = 2;
        vector<int> v;
        vector<int> rt(size, 0);
        for (int i = 0; i < size; i++)
        {
            rt[i] = processes[i].bt;
        }
        while (!q.empty())
        {
            prev = t;
            process temp = q.front();
            q.pop();
            v.push_back(temp.id);
            int ind = 0;
            for (int i = 0; i < size; i++)
            {
                if (processes[i].id == temp.id)
                {
                    ind = i;
                    break;
                }
            }
            cout << "ind : " << ind << endl;
            if (rt[ind] <= qtime)
            {
                t += rt[ind];
                rt[ind] = 0;
                processes[ind].ct = t;
            }
            else
            {
                t += qtime;
                rt[ind] -= qtime;
            }

            for (int i = 0; i < size; i++)
            {
                if (i != ind)
                {
                    if (prev < processes[i].at && processes[i].at <= t && rt[i] > 0)
                    {
                        q.push(processes[i]);
                    }
                }
            }

            if (rt[ind] > 0)
            {
                q.push(processes[ind]);
            }
        }

        cout << "ID\tAT\tBT\tCT\tTAT\tWT" << endl;
        for (int i = 0; i < size; i++)
        {
            // turn around time
            processes[i].tat = processes[i].ct - processes[i].at;
            // waiting time
            processes[i].wt = processes[i].tat - processes[i].bt;
            if (processes[i].wt < 0)
            {
                processes[i].wt = 0;
            }
            cout << processes[i].id << "\t" << processes[i].at << "\t" << processes[i].bt << "\t"
                 << processes[i].ct << "\t" << processes[i].tat << "\t" << processes[i].wt << endl;
        }

        avg_tat_n_wt(processes);
        cout << endl;

        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
    }
};

int main()
{
    Algorithms a(4);

    a.FCFS();
    // a.SJFp();
    // a.priority();
    // a.Round_Robin();
    return 0;
}

// 1 2 0 11 2 0 5 28 3 3 12 2 4 1 2 10 5 4 9 16

// 1 3 0 3 2 4 1 6 3 9 3 1 4 7 2 2 5 8 4 4

// 1 0 5 2 1 4 3 2 2 4 3 1
// 1 2 0 11
// 2 0 5 28
// 3 3 12 2
// 4 1 2 10
// 5 4 9 16