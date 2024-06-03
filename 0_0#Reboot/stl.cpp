#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void explainpair()
{

    // pair<int, int> p = {1, 2};
    // cout << p.first << endl
    //      << p.second;

    // pair<int, char> q = {2, 'y'};

    // pair<int, pair<int, int>> r = {1, {2, 3}};
    // cout << r.first << endl
    //      << r.second.first << endl
    //      << r.second.second;

    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
    // cout << arr[2].first;
    for (int i = 0; i < 3; i++)
    {

        cout << arr[i].first << endl
             << arr[i].second << endl;
    }
}

void explainVector()
{

    // vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.emplace_back(4);
    // cout << v.at(3); // same as push_back

    // vector<pair<int, int>> p;
    // p.push_back({1, 2});
    // p.emplace_back(2, 3);
    // cout << p.at(0).first;

    // declare vector with elements
    // vector<int> q(5, 2); // here 5 time 2 is stored {2,2,2,2,2}
    // vector<int> q{5, 2}; // here 5,2 is stored at time of creation
    // cout << q.at(0) << endl
    //      << q.at(1);

    // vector with size
    // vector<int> r(5); // 5 garbage value stored at diclearition
    // copy vector

    // vector<int> s(r);
    // cout << s.at(1);

    // vector itterate

    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // vector<int>::iterator it = v.begin();

    // cout << *(it);

    // cout << *(v.begin()); //these returns address
    // cout << *(v.end() - 1);

    // cout << v.front(); //these return actual values
    // cout << v.back();

    // for (auto it = v.begin(); it != v.end(); it++)
    // {
    //     cout << *(it) << endl;
    // }

    // for each loop
    //  for (auto it:v)
    //  {
    //      cout<<it<<endl;
    //  }

    // erase

    // v.erase(v.begin());
    // cout << v.back();

    // erase multiple

    // v.erase(v.begin(), v.begin() + 3);
    // cout<<v[0];

    // insert
    // v.insert(v.begin(), 0);
    // v.insert(v.begin(), 2, 80); //insert 2 times 80
    // cout << v[0];

    // copy vector

    vector<int> p{11, 12, 13};
    // v.insert(v.begin(), p.begin(), p.end());

    // cout << v[0];

    // cout << v.size();

    // v.swap(p);
    // cout<<p[0];

    // v.clear();
    // v.empty(); //return true false
} 

void explainList(){
    list<int>l;
    l.push_back(1);
    

}
int main()
{
    // explainpair();
    explainVector();

    return 0;
}