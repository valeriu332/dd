#include <iostream>
#include <string.h>
using namespace std;
class Generic{
	public:
		virtual void afis()=0;
		virtual int get_pret()=0;
		virtual ~Generic(){
		}
};

class Piesa:public Generic{
	protected:
		char cod[4];
		int pret;
	public:
		Piesa(){
			strcpy(cod,"000");
			pret=0;
		}
		Piesa(char c[],int p):pret(p){
			strcpy(cod,c);
		}
		int get_pret(){
			return pret;
		}
		void afis(){
			cout<<"Cod: "<<cod<<endl<<"Pret: "<<pret<<endl;
		}
};

class Piesa_G:public Piesa{
	int nr_gauri;
	public:
		Piesa_G(){
			nr_gauri=0;
		}
		Piesa_G(char c[],int p=0,int ng=0):Piesa(c,p),nr_gauri(ng){}
		void afis(){
			cout<<"Piesa gauri: "<<endl;
			Piesa::afis();
			cout<<"Nr. gauri: "<<nr_gauri<<endl;
		}
		int get_gauri(){
			return nr_gauri;
		}
};

class Piesa_C:public Piesa{
	char *culoare;
	public:
		Piesa_C(){
			culoare=NULL;
		}
		Piesa_C(char c[],int p=0,char* cul=NULL):Piesa(c,p){
			if(cul==NULL) culoare=NULL;
			else{
				culoare=new char[strlen(cul)+1];
				strcpy(culoare,cul);
			}
		}
		Piesa_C& operator=(const Piesa_C& c){
			(Piesa&)(*this)=c;
			if(c.culoare==NULL) culoare=NULL;
			else{
				culoare=new char[strlen(c.culoare)+1];
				strcpy(culoare,c.culoare);
			}
			return *this;
		}
		Piesa_C(const Piesa_C& c){
			*this=c;
		}
		void afis(){
			Piesa::afis();
			if(culoare!=NULL)
				cout<<"Culoare: "<<culoare<<endl;
			else
				cout<<"Nu are culoare!"<<endl;
		}
		~Piesa_C(){
			if(culoare!=NULL) delete[] culoare;
		}
};

class Ansamblu:public Generic{
	Piesa_G pg;
	Piesa_C *buf;
	public:
		Ansamblu(char c[],int p,int ng,Piesa_C *b):pg(c,p,ng){
			if(pg.get_gauri()!=0)
			{
				buf=new Piesa_C[pg.get_gauri()];
				for(int i=0;i<pg.get_gauri();i++)
					buf[i]=b[i];
			}
		}
		Ansamblu(Piesa_G p,Piesa_C *b):pg(p){
			if(pg.get_gauri()!=0)
			{
				buf=new Piesa_C[pg.get_gauri()];
				for(int i=0;i<pg.get_gauri();i++)
					buf[i]=b[i];
			}
		}
		Ansamblu& operator=(const Ansamblu& a){
			(Piesa_G&)(*this)=a.pg;
			buf=new Piesa_C[pg.get_gauri()];
			for(int i=0;i<pg.get_gauri();i++)
				buf[i]=a.buf[i];
		}
		Ansamblu(const Ansamblu& a){
			*this=a;
		}
		void afis(){
			cout<<"Ansamblu: "<<endl;
			pg.afis();
			for(int i=0;i<pg.get_gauri();i++){
				cout<<"Piesa colorata nr."<<i<<":"<<endl;
				buf[i].afis();
			}
		}
		int get_pret(){
			int sum=pg.get_pret();
			for(int i=0;i<pg.get_gauri();i++)
				sum+=buf[i].get_pret();
			return sum;
		}
};

