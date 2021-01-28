#include "clase.h"

int main(int argc, char** argv) {
	int n;
	cout<<"Dati nr. de elem. din vector:";
	cin>>n;
	Generic**vec=new Generic*[n];
	for(int i=0;i<n;i++){
		int t;
		cout<<"Pentru tipuri piese apasati 0, pentru ansamblu apasati 1."<<endl;
		cin>>t;
		if(t==0){
			int x;
			cout<<"Pentru piesa cu gauri apasati 1, pentru piesa colorata apasati 2."<<endl;
			cin>>x;
				if(x==1){
					char cod[4];
					int pret,ng;
					cout<<"Dati 3 caractere pentru cod: ";
					cin>>cod;
					cout<<"Dati pretul: ";
					cin>>pret;
					cout<<"Dati nr. de gauri: ";
					cin>>ng;
					vec[i]=new Piesa_G(cod,pret,ng);
				}else{
					if(x==2){
						char cod[4];
						int pret;
						char *c=new char[25];
						cout<<"Dati 3 caractere pentru cod: ";
						cin>>cod;
						cout<<"Dati pretul: ";
						cin>>pret;
						cout<<"Dati culoarea: ";
						fflush(stdin);
						cin>>c;
						fflush(stdin);
						vec[i]=new Piesa_C(cod,pret,c);
					}else{
						i--;
					}
				}
			}
		