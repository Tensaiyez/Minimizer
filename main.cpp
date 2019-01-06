#include <set>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int find_in_vec(const vector<pair<string,int> > & vec, const string &str)
{
    for(int i=0; i<vec.size(); ++i)
    {
        if(vec[i].first==str)
            return vec[i].second;
    }
    return -1;
}

int main()
{
    string str;
    getline(cin, str);

    vector<pair<string,int> > words;

    bool isString=false;
    string curr = "";
    int ind=0;
    for(int i=0; i<str.size(); ++i)
    {
        if((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z'))
        {
            if(isString==true)
            {
                //Add curr to words
                int temp=find_in_vec(words, curr);

                if(temp==-1)
                {
                    pair<string, int> temp1;
                    temp1.first=curr;
                    temp1.second=ind;
                    words.push_back(temp1);
                    cout << curr;
                }
                else
                {
                    cout << "$" << temp;
                }

                ++ind;
                curr="";
                isString=false;
            }
            cout << str[i];
        }
        else
        {
            curr+=str[i];
            if(isString==false)
                isString=true;
        }
    }
    if(isString==true)
    {
        //Add curr to words
        int temp=find_in_vec(words, curr);

        if(temp==-1)
        {
            pair<string, int> temp1;
            temp1.first=curr;
            temp1.second=ind;
            words.push_back(temp1);
            cout << curr;
        }
        else
        {
            cout << "$" << temp;
        }

        ++ind;
        curr="";
        isString=false;
    }
    return 0;
}
