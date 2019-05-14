/*nama	: Alvin
NPM		: 140810180013
kelas	: A
program : QUEUE LIST
*/
#include<iostream>
using namespace std;

struct elemen{
	char data[10];
	elemen* next;
};

typedef elemen* pointer;
typedef pointer list;

struct queue{
	list head;
	list tail;
};
queue q;

void createQueue(queue& q){
	q.head = NULL;
	q.tail = NULL;
}

void createElement(pointer& pBaru){
	pBaru = new elemen;
	cout<<"Data: ";
	cin>>pBaru->data;
	pBaru->next=NULL;
}

void insertQueue(queue& q,pointer pBaru){
	if(q.head==NULL && q.tail==NULL){
		q.head = pBaru;
		q.tail = pBaru;
	}
	else {
		q.tail->next=pBaru;
		q.tail = pBaru;
	}
}

void deleteQueue(queue& q, pointer& pHapus){
	if(q.head==NULL && q.tail==NULL){
		pHapus=NULL;
		cout<<"Queue kosong, tidak ada yang dihapus."<<endl;
	}
	else if(q.head->next==NULL){
		pHapus=q.head;
		q.head=NULL;
		q.tail=NULL;
	}
	else {
		pHapus=q.head;
		q.head=q.head->next;
		pHapus->next=NULL;
	}
}

void cetakQueue(queue q){
	pointer pBantu;
	if(q.head==NULL){
		cout<<"Queue kosong."<<endl;
	}
	else {
		pBantu=q.head;
		cout<<"data"<<endl;
		do{
			cout<<pBantu->data<<endl;
			pBantu=pBantu->next;
		}
		while(pBantu!=q.tail->next);
	}
}

int main(){
	queue q;
	pointer pBaru, pHapus;

	createQueue(q);
	int pilih;
	do{
        cout<<"      QUEUE LIST      "<<endl;
		cout<<"         Menu         "<<endl;
		cout<<"----------------------"<<endl;
		cout<<"1. Insert Data"<<endl;
		cout<<"2. Delete Data"<<endl;
		cout<<"3. Cetak Data"<<endl;
		cout<<"0. Keluar"<<endl;

		cout<<endl<<"Masukkan pilihan: ";
		cin>>pilih;

		switch(pilih){
			case 1: {
				createElement(pBaru);
				insertQueue(q,pBaru);
				cout<<"Data berhasil ditambah"<<endl<<endl;
				}
				break;
			case 2: {
				deleteQueue(q,pHapus);
				cout<<"Data berhasil dihapus"<<endl<<endl;
				}
				break;
			case 3: {
				cetakQueue(q);
				cout<<endl;
				}
				break;
		}
	}
	while(pilih!=0);
}
