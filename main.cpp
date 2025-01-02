#include<iostream>
#include <vector>
#include <stack>
using namespace std;

void instructiuni(){
    system("cls");
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
bool castiga(const vector<stack<int>>& towers, int n){
    return towers[2].size()==n;
}

void meniu(){
    system("cls");
    cout<<"====================="<<endl;
    cout<<"Turnutile din Hanoi"<<endl;
    cout<<"====================="<<endl;
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
            case 1:
                break;
            case 2:
                instructiuni();
                break;
            case 3:
                cout<<"La revedere!"<<endl;
                break;
            default:
                cout<<"Optiune invalida!"<<endl;
        }
    }while (optiune!=3);
    return 0;
}