const long long MOD=1000000007;
struct Matrix{

    long long mat[52][52];
    int size;

    Matrix(int m){
        size=m;

        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                mat[i][j]=0;
            }
        }}

        Matrix operator*(const Matrix& other) const {
            Matrix result(size);
            
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                    for(int k=0; k<size; k++){
                        result.mat[i][j]=(result.mat[i][j]+(mat[i][k]*other.mat[k][j])%MOD)%MOD;
                    }
                }
            }
            return result;


         }

    
};

int getIndex(char c){
    if(c>='a' && c<='z') return c-'a';
    if(c>='A' && c<='Z') return c-'A'+26;
    return -1;
}

Matrix power(Matrix a, long long b){
    
    Matrix result(a.size);
    for(int i=0; i<result.size; i++){
        result.mat[i][i]=1;
    }

    while(b>0){
        if(b&1) result=result*a;
        a=a*a;
        b>>=1;
    }
    return result;
}

#include<iostream>
using namespace std;

int main(){

    long long n,m,k;
    cin>>n>>m>>k;

    Matrix transition(m);

    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            transition.mat[i][j]=1;
        }
    }

    for(int i=0; i<k; i++){
        string s;
        cin>>s;
        int u=getIndex(s[0]);
        int v=getIndex(s[1]);
        transition.mat[u][v]=0;
    }

    transition=power(transition,n-1);

    long long total=0;
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            total=(total+transition.mat[i][j])%MOD;
        }
    }

    cout<<total<<endl;
}