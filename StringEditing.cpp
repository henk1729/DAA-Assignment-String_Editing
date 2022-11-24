#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

#define ll long long
#define forn(i, n) for(int i=0; i<(n); ++i)

//to add a delay
void buffering(string a, int t){
    forn(i, a.length()){
        cout<<a[i];
        Sleep(t);
    }
}

//to calculate min. editing cost
int calculateEditingCost(vector<vector<int>>&dp, string s1, string s2, int ins, int del, int rep){
    forn(i, s1.length()+1){
        forn(j, s2.length()+1){
            if(i==0){ //if source is momentarily empty, delete remaining input string
                dp[i][j]=j*del;
            }
            else if(j==0){ //if input is momentarily empty, insert remaining source string
                dp[i][j]=i*ins;
            }
            else if(s1[i-1]==s2[j-1]){ //if characters matched, skip
                dp[i][j]=dp[i-1][j-1];
            }
            else{ //select min. of insert, delete, replace operations
                dp[i][j]=min(ins+dp[i-1][j], min(del+dp[i][j-1], rep+dp[i-1][j-1]));
            }
        }
    }

    return dp[s1.length()][s2.length()];
}

//to print analysis
void printOperations(vector<vector<int>> dp, string s1, string s2, int ins, int del, int rep){
    cout<<"\nEditing Analysis\n\n";
    //for reference
    cout<<"Source string-> ";
    forn(i, s1.length()) cout<<s1[i]<<" ";
    cout<<endl;
    cout<<"Input string -> ";
    forn(i, s2.length()) cout<<s2[i]<<" ";
    cout<<"\n\n";

    //index
    cout<<"Index\n";
    cout<<"N: do nothing\n";
    cout<<"R: replace\n";
    cout<<"I: insert\n";
    cout<<"D: delete\n\n";

    //v -> stores operation
    //v1-> stores affected character in source
    //v2-> stores affected character in input
    vector<char> v, v1, v2;
    for(ll i=s1.length(), j=s2.length(); i>0 || j>0; ){
        ll flag=0;
        if(i>0 && j>0 && rep+dp[i-1][j-1]==dp[i][j]){ //replace
            v.push_back('R');
            v1.push_back(s1[i-1]);
            v2.push_back(s2[j-1]);
            i--;
            j--;
            flag=-1;
        }
        else{
            if(i>0 && ins+dp[i-1][j]==dp[i][j]){ //insert
                v.push_back('I');
                v1.push_back(s1[i-1]);
                v2.push_back('.');
                flag=1;
            }
            else if(j>0 && del+dp[i][j-1]==dp[i][j]){ //delete
                v.push_back('D');
                v1.push_back('.');
                v2.push_back(s2[j-1]);
                flag=2;
            }
            if(flag==1) i--;
            if(flag==2) j--;
        }

        if(flag==0){ //do nothing
            v.push_back('N');
            v1.push_back(s1[i-1]);
            v2.push_back(s2[j-1]);
            i--;
            j--;
        } 
    }

    //printing
    forn(i, v.size()) cout<<v[v.size()-1-i]<<" ";
    cout<<"\n";
    forn(i, 2*v.size()-1) cout<<"-";
    cout<<"\n";
    forn(i, v1.size()) cout<<v1[v1.size()-1-i]<<" ";
    cout<<"\n";
    forn(i, v2.size()) cout<<v2[v2.size()-1-i]<<" ";
}

//input function
void inputParameters(){
    buffering("Welcome onboard!\n\n", 100);

    //input strings
    string s1, s2;
    cout<<"Enter source string: ";
    cin>>s1;
    cout<<"Enter input string : ";
    cin>>s2;

    //input operation costs
    int ins, del, rep;
    cout<<"\nEnter positive costs for operations:\n";
    cout<<"1. Insertion  : ";
    cin>>ins;
    cout<<"2. Deletion   : ";
    cin>>del;
    cout<<"3. Replacement: ";
    cin>>rep;
    cout<<"\n______________\n";

    cout<<"\nWait while we are processing your query";
    buffering(" ...\n", 1000);

    //2D array to store cost
    vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1));

    //function call
    cout<<"\nCost of conversion:\n"<<calculateEditingCost(dp, s1, s2, ins, del, rep)<<endl;
    cout<<"\n______________\n";

    //function call
    printOperations(dp, s1, s2, ins, del, rep);
}


int main(){
    //function call
    inputParameters();
    return 0;
}