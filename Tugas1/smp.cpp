// Nama     : Arif Rhizky Gilang Purnama
// NPM      : 140810170030

#include <iostream>

using namespace std;

int main() { 
    int n;
    cout<<"Input jumlah orang : ";cin>>n;

    // mans[indexman][indexpreference]
    string strMans[n+1] = {"","Victor", "Wyatt", "Xavier", "Yancey", "Zeus"};
    string strWomans[n+1] = {"","Amy", "Bertha", "Clare", "Diane", "Erika"};

    int mans[n+1][n+1];
    int womans[n+1][n+1];
    int manMatch[n+1];
    int womanMatch[n+1];
    int manNextProposal[n+1];
    //input woman
    for (int i = 1; i <= n; i++) {
        womanMatch[i] = 0;
        cout<<"Input preference woman "<<i<<endl;
        for(int j = 1; j <= n; j++) {
            cin>>womans[i][j];
        }
    }
    cout<<endl;
    //input man
    for (int i = 1; i <= n; i++) {
        manMatch[i] = 0;
        manNextProposal[i] = 1;
        cout<<"Input preference man "<<i<<endl;
        for(int j = 1; j <= n; j++) {
            cin>>mans[i][j];
        }
    }
    
    bool freeManAvailable = true;
    int m = 1;
    while(freeManAvailable) {
        freeManAvailable = false;
        int w = mans[m][manNextProposal[m]++];
        if(womanMatch[w] == 0) {
            womanMatch[w] = m;
            manMatch[m] = w;
        } else {
            bool itsABetterProposal = false;
            
            for(int y = 1; y <= n; y++) {
                if(womans[w][y] == womanMatch[w]) {
                    itsABetterProposal = false; break;
                }

                if(womans[w][y] == m){ 
                    itsABetterProposal = true; break;
                }
            }
            if(itsABetterProposal) {
                manMatch[womanMatch[w]] = 0;
                womanMatch[w] = m;
                manMatch[m] = w;
            }
        }
        
        
        for(int x = 1; x <= n; x++) {
            if(manMatch[x] == 0) {
                m = x;
                freeManAvailable = true;
                break;
            }
        }
    }
    
    cout<<endl;
    cout<<"Result : "<<endl;
    for(int i = 1; i <= n;  i++){
        cout<<strMans[i]<<" match with "<<strWomans[manMatch[i]]<<endl;
    }
        // cout<<i<<" match with "<<manMatch[i]<<endl;

    return 0;
}
