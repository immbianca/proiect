#include<iostream>

using namespace std;

void meniu(){
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