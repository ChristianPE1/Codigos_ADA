#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int Media(vector<int> vec){
    sort(vec.begin(),vec.end());
    if(vec.size()%2==1){
        return vec[(vec.size()/2)];
    }
    else{
        int mid =  vec.size()/2;
        return (vec[mid-1]+vec[mid])/2;
    }
}

int main(){
    
    vector<int> test;
    int n;
    while(n!=-1){
        cin>>n;
        test.push_back(n);
        cout<<Media(test)<<endl;
    }
    
    return 0;
}
