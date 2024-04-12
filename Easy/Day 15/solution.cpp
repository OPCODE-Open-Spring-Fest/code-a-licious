// Write your code here.
#include<bits/stdc++.h>
using namespace std;

bool check_line(vector<vector<int> > &visited){
	for (int i = 0; i < 3; ++i) {
        if ((visited[i][0] && visited[i][1] && visited[i][2] ) ||
            (visited[0][i] && visited[1][i] && visited[2][i] )) {
            return true;
        }
    }

    // Check diagonals
    if ((visited[0][0] && visited[1][1] && visited[2][2] ) ||
        (visited[0][2] && visited[1][1] && visited[2][0] )) {
        return true;
    }

    return false;
}

int main(){
	vector<vector<int> > store;
	for(int i=0;i<3;i++){
		int a,b,c;
		cin>>a>>b>>c;
        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);
        temp.push_back(c);
		store.push_back(temp);
	}
	
	vector<vector<int> >visited(3,vector<int>(3,0));

	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;

		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(store[i][j]==temp){
					visited[i][j]=1;
					break;
				}
			}
		}

		if(check_line(visited)){
			cout<<"YES";
			exit(0);
		}
	}
	cout<<"NO";
    return 0;	
}