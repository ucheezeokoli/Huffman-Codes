#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <bitset>
#include <string>
#include <algorithm>
// #include <char>

using namespace std;

int ExtractMin(vector<int>& Q, vector<string>& L, vector<int>& freq, vector<string>& Letters)
{
    int i;
    int index = 0;
    int min = Q.at(0);

    if (Q.size() == 1){
        freq.push_back(Q.at(index));
        Letters.push_back(L.at(index));
        return index;
    }

    else
    {
        for (i = 0; i < Q.size(); i++)
        {
            if (min > Q.at(i))
            {
                min = Q.at(i);
                index = i;
            }
        }

        freq.push_back(Q.at(index));
        Letters.push_back(L.at(index));
    }

    
    return index;
}

int Hoffman(vector<int>& C, vector<int>& Q, vector<string>& L, vector<int>& freq, vector<string>& Letters)
{
    int n = C.size();

    int i,l_index,r_index,z,temp_i,left,right;
    string temp_s, l_let,r_let;
    
    for (i = 1; i < n; i++)
    {
        //LEFT
        l_index = ExtractMin(Q,L,freq,Letters);
        left = Q.at(l_index);
        l_let = L.at(l_index);

        //moves the min value to the back
        temp_i = Q.at(Q.size() - 1); //set temp equal to the last element
        Q.at(Q.size() - 1) = Q.at(l_index);
        Q.at(l_index) = temp_i;

        temp_s = L.at(L.size() - 1); //set temp equal to the last element
        L.at(L.size() - 1) = L.at(l_index);
        L.at(l_index) = temp_s;

        Q.pop_back();
        L.pop_back();
    
        //RIGHT
        r_index = ExtractMin(Q,L,freq,Letters);
        right = Q.at(r_index);
        r_let = L.at(r_index);

        //moves the min value to the back
        temp_i = Q.at(Q.size() - 1); //set temp equal to the last element
        Q.at(Q.size() - 1) = Q.at(r_index);
        Q.at(r_index) = temp_i;

        temp_s = L.at(L.size() - 1); //set temp equal to the last element
        L.at(L.size() - 1) = L.at(r_index);
        L.at(r_index) = temp_s;

        Q.pop_back();
        L.pop_back();

        z = left + right;
        Q.push_back(z);

        string str (l_let + r_let);
        L.push_back(str);
        
    }
    return ExtractMin(Q,L,freq,Letters);
}

int SearchLetters(vector<string>& Letters, char let, string encode)
{
    int i,j;
    for (i = 1; i < Letters.size(); i++)
    {
        string x(Letters.at(i));
        for (j = 0; j < x.length(); j++)
        {
            if (let == x[j])
            {
                
                encode += to_string(i%2);
            }
        }
    }
    cout << let << ":" << encode<< endl;
}

int PrintEncode(vector<int>& freq, vector<string>& Letters, vector<int>& C)
{
    string encode;
    char let;
    int i;
    for (i = 0; i < C.size(); i++)
    {
        let = 'A' + i;
        SearchLetters(Letters,let,encode);
    }
}

int main()
{
    vector<int> C(6);
    vector<int> freq;
    vector<int> Q(C.size());
    vector<string> Letters;
    vector<string> L(C.size());

    int i;
    int j = 0;
    for (i = 0; i < C.size(); i++)
    {
        cin >> C.at(i);
        Q.at(i) = C.at(i);
        L.at(i) = 'A' + i;
    }

    Hoffman(C,Q,L,freq,Letters);

    reverse(freq.begin(),freq.end());
    reverse(Letters.begin(),Letters.end());

    PrintEncode(freq,Letters,C);

}