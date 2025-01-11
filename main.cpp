#include<iostream>
#include <vector>
#include <stack>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

using namespace std;

void system(){
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}


void tije(const vector<stack<int>>& tower, int n){
    cout<<endl<<"Tijele:"<<endl;
    for(int i=0;i<3;++i){
        cout<<char('A'+i)<<": ";
        stack<int> temp=tower[i];
        vector<int> discuri;
        while(!temp.empty()){
            discuri.push_back(temp.top());
            temp.pop();
        }
        for(auto it=discuri.rbegin();it!=discuri.rend();++it){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    cout<<"====================="<<endl;
}

void determinare(int n, char from, char to, char aux,vector<stack<int>>& towers){
    if(n==1){
        cout<<"Mutare disc "<<n<<" de la "<<from<<" la "<<to<<endl;

        int from_tija=from-'A';
        int to_tija=to-'A';
        towers[to_tija].push(towers[from_tija].top());
        towers[from_tija].pop();
        tije(towers,n);
        cin.get();
        return;
    }
    determinare(n-1,from,aux,to, towers);
    
    cout<<"Mutare disc "<<n<<" de la "<<from<<" la "<<to<<endl;

    int from_tija=from-'A';
    int to_tija=to-'A';
    towers[to_tija].push(towers[from_tija].top());
    towers[from_tija].pop();
    tije(towers,n);
    cin.get();

    determinare(n-1,aux,to,from, towers);
}

void testare(){
    system();
    cout<<"=== Secventa de testare ==="<<endl;
    int n;
    cout<<"Introduceti numarul de discuri(minim 3): ";
    while(true){
        cin>>n;
        if(n>=3){
            break;
        }
        cout<<"Numarul de discuri trebuie sa fie minim 3. Reintroduceti: ";
    }

    vector<stack<int>> towers(3);
    for(int i=n;i>=1;--i){
        towers[0].push(i);
    }

    cout<<endl<<"Tijele la inceput:"<<endl;
    tije(towers,n);
    cout<<"Apasa orice tasta pentru a continua...";
    cin.get();
    cin.get();

    determinare(n,'A','C','B',towers);

    cout<<endl<<"Acesta a fost rezultatul final"<<endl;
    cout<<endl<<"Apasa orice tasta pentru a reveni la meniu...";
    cin.get();
    cin.get();
}
void instructiuni(){
    system();
    cout<<"\n=== Instructiuni ===\n";
    cout<<"Scopul jocului este de a muta toate discurile de pe unul dintre turnuri pe celalalt, folosind un al treilea turn ca suport.\n";
    cout<<"Regulile jocului sunt simple:\n";
    cout<<"1. Se poate muta cate un disc la un moment dat.\n";
    cout<<"2. Un disc mai mare nu poate fi plasat peste un disc mai mic.\n";
    cout<<"3. Se poate muta un disc doar de pe varful unui turn.\n";
    cout<<"4. Se poate muta un disc doar pe varful unui turn.\n";
    cout<<"5. Scopul jocului este de a muta toate discurile de pe un turn pe celalalt, folosind un al treilea turn ca suport.\n";
    cout<<"6. Numarul de mutari este minim daca se respecta regulile de mai sus.\n";
    cout<<"7. Jocul se termina atunci cand toate discurile sunt pe un alt turn decat cel initial.\n";
    cout<<"8. Numarul minim de mutari este 2^n - 1, unde n este numarul de discuri.\n";
    cout<<"9. Jocul se poate juca cu orice numar de discuri.\n";
    cout<<"10. Succes!\n";
    cout<<"Apasa orice tasta pentru a reveni la meniu...";
    cin.get();
    cin.get();
}

bool castiga(const vector<stack<int>>& towers, int n){
    return (towers[0].size()==n||towers[1].size()==n || towers[2].size()==n);
}

void distributie(vector<stack<int>>& towers, int n){

    for(auto& tower : towers){
        while(!tower.empty()){
            tower.pop();
        }
    }

    for(int i=n;i>=1;--i){
        towers[0].push(i);
    }
}
void distributie1(vector<stack<int>>& towers, int n){
   srand(time(0));

   vector<int> discuri;
   vector<bool> used(n+1,false);

   while(discuri.size()<n){
    int disc=rand()%n+1;
    if(!used[disc]){
        discuri.push_back(disc);
        used[disc]=true;
    }
   }

   do{
    for (auto& tower : towers){
            while(!tower.empty()){
            tower.pop();
            }
        }

    
        int tijarandom=0;
        for(int i=n-1;i>=0;--i){
            towers[tijarandom].push(discuri[i]);
            tijarandom=(tijarandom+1)%3;
        }
   }while(castiga(towers,n));
}

void joc(){
    int n, dif;
    system();
    cout<<"Introduceti numarul de discuri(minim 3, maxim 10): ";
    while(true){
        cin>>n;
        if(n>=3 && n<=10){
            break;
        }
        cout<<"Numarul de discuri trebuie sa fie intre 3 si 10. Reintroduceti: ";
    }

    vector<stack<int>> towers(3);
    distributie1(towers,n);

    int from, to;
    while(!castiga(towers,n)){
        system();
        tije(towers,n);
        cout<<"Introdu tija sursa (1-3) si tija destinatie (1-3): ";
        cin>>from>>to;

        if(from<1 || from>3 || to<1 || to>3){
            cout<<"Tija invalida! Reintroduceti: ";
            continue;
        }

        --from;
        --to;

        if(towers[from].empty()){
            cout<<"Tija sursa goala! Reintroduceti: ";
            continue;
        }

        if(!towers[to].empty() && towers[from].top()>towers[to].top()){
            cout<<"Discul nu poate fi plasat pe disc mai mic! Reintroduceti: ";
            continue;
        }
        towers[to].push(towers[from].top());
        towers[from].pop();
    }

    system();
    cout<<"Felicitari! Ati castigat!"<<endl;
    cout<<endl<<"Apasa orice tasta pentru a reveni la meniu...";
    cin.get();
    cin.get();
}
void meniu(){
    system();
    cout<<"====================="<<endl;
    cout<<"Turnutile din Hanoi"<<endl;
    cout<<"====================="<<endl;
    cout<<"0. Secventa de testare"<<endl;
    cout<<"1. Start joc"<<endl;
    cout<<"2. Instructiuni"<<endl;
    cout<<"3. Iesire"<<endl;
    cout<<"Alegere: ";
}

int main(){
    int optiune;
    do{
        meniu();
        cin>>optiune;
        switch(optiune){
            case 0:
                testare();
                cout<<"Secventa de testare"<<endl;
                break;
            case 1:
                joc();
                break;
            case 2:
                instructiuni();
                break;
            case 3:
                system();
                cout<<"La revedere!"<<endl;
                break;
            default:
                cout<<"Optiune invalida!"<<endl;
        }
    }while (optiune!=3);
    return 0;
}