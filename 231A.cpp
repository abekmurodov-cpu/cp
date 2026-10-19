#include <iostream>
#include <vector>
using namespace std;

vector<int> applyPermutation(vector<int> sequence, vector<int> permutation){
    vector<int> newSequence(sequence.size());
    for(int i=0; i<sequence.size(); i++){
        newSequence[i]=sequence[permutation[i]];
    }
    return newSequence;
}

vector<int> permutate(vector<int> sequence, vector<int> permutation, long long k){
    
    while(k>0){
        if(k&1) sequence=applyPermutation(sequence,permutation);
        permutation=applyPermutation(permutation,permutation);
        k>>=1;
    }
    return sequence;
}

long long modpow(long long a, long long b, long long p){
    a=a%p;
    long long res=1;
    while(b>0){
        if(b&1) res=(res*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return res;
}


long long combineCounter(vector<string> a){
    long long res=0;
    for(int i=0; i<a.size(); i++){
        for(int j=i+1; j<a.size(); j++){
            if(a[i][0]==a[j][1]) res++;
            if(a[i][1]==a[j][0]) res++;
        }
    }
    return res;
}

int main() {
    
   long long n,m,k;
   cin>>n>>m>>k;

   vector<string> a(k);

   for(int i=0; i<k; i++){
       cin>>a[i];
   }

   long long totalCombinations=modpow(m,n,1000000007);
   long long invalidCombinations=combineCounter(a)*modpow(m,n-3,1000000007);
   long long forbiddenCombinations=n-2!=0? modpow(m,n-2,1000000007)*a.size()*2: a.size();
   forbiddenCombinations-=invalidCombinations;
   long long validCombinations=(totalCombinations-forbiddenCombinations+1000000007)%1000000007;
   cout<<validCombinations<<endl;
//    cout<<totalCombinations<<" "<<invalidCombinations<<" "<<forbiddenCombinations<<" "<<a.size()<<endl;
	

}
