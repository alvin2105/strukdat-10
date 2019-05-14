/*nama	: Alvin
NPM		: 140810180013
kelas	: A
program : QUEUE ARRAY
*/
#include<iostream>
using namespace std;

const int maxElemen = 255;

struct elemen{
	char data[10];

};

struct queue{
	elemen isi[maxElemen];
	int head;
	int tail;
};
queue q;

void createQueue(queue& q){
	q.head = 0;
	q.tail = -1;
}

void createElement(elemen& baru){
	cout<<"Masukkan data: ";
	cin>>baru.data;

}

void insertQueue(queue& q, elemen baru){
	if(q.tail==maxElemen-1){
		cout<<"Antrian penuh"<<endl;
	}
	else {
		q.tail = q.tail+1;
		q.isi[q.tail] = baru;
	}
}

void deleteQueue(queue& q, elemen& hapus){
	if(q.head > q.tail){
		cout<<"Antrian kosong, tidak ada yang dihapus."<<endl;
	}
	else {
		hapus = q.isi[q.head];
		for(int i=0;i<q.tail;i++){
			q.isi[q.tail] = q.isi[q.tail+1];
		}
		q.tail = q.tail-1;
	}
}

void cetakQueue(queue q){
	int i=0;
	cout<<"DATA"<<endl;
	while(i!=q.tail+1){
		cout<<q.isi[i].data<<endl;
		i++;
	}
}

int main(){
	queue q;
	elemen baru,hapus;
	createQueue(q);
	int pilih;
	do{
		cout<<"     QUEUE ARRAY      "<<endl;
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
				createElement(baru);
				insertQueue(q,baru);
				cout<<"Data berhasil ditambah"<<endl<<endl;
				}
				break;
			case 2: {
				deleteQueue(q,hapus);
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
