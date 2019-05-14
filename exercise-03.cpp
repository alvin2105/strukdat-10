/*nama	: Alvin
NPM		: 140810180013
kelas	: A
program : TREE MENU
*/
#include<iostream>
using namespace std;

struct simpul{
	int info;
	simpul* left;
	simpul* right;
};

typedef simpul* pointer;
typedef pointer tree;

void createBinaryTree(tree& root){
	root=NULL;
}

void createSimpul(pointer& pBaru){
	pBaru=new simpul;
	cout<<"Info	: ";
	cin>>pBaru->info;
	pBaru->left=pBaru->right=NULL;
}

void insertBST(tree& root, pointer pBaru){
	if(root==NULL){
		root=pBaru;
		
		cout<<root->info<<" ";
	}
	else if(pBaru->info < root->info){
		insertBST(root->left,pBaru);
	
		cout<<root->info<<" ";
	}
	else if(pBaru->info > root->info){
		insertBST(root->right,pBaru);
		
		cout<<root->info<<" ";
	}
	else{
		cout<<"Data Sudah ada."<<endl;

	}
}

void preOrder(tree root){
	if(root!=NULL){
		cout<<root->info<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(tree root){
	if(root!=NULL){
		inOrder(root->left);
		cout<<root->info<<" ";
		inOrder(root->right);
	}
}

void postOrder(tree root){
	if(root!=NULL){
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->info<<" ";
	}
}

int depth(tree root){
	if(root == NULL){
		return 0;
	}
	int a = depth(root->left);
	int b = depth(root->right);

	if(a>b) return a+1;
	else return b+1;
}

void tingkat(tree root, int level){
	if(root==NULL){
		return;
	}
	if(level==1){
		cout<<root->info<<" ";
	}else if(level > 1){
		tingkat(root->left, level-1);
		tingkat(root->right, level-1);
	}
}

void levelOrder(tree root){
    int h = depth(root);
    for(int i=1; i<=h; i++){
    	tingkat(root, i);
    }
}


int main(){
	cout<<"   BINARY SEARCH TREE    "<<endl;
	cout<<"-------------------------"<<endl;

	tree root;
	pointer pBaru;

	createBinaryTree(root);
	int pilih;
	do{
		cout<<"       Pilihan Menu      "<<endl;
		cout<<"-------------------------"<<endl;
		cout<<"1. Tambah Data"<<endl;
		cout<<"2. Traversal PreOrder"<<endl;
		cout<<"3. Traversal InOrder"<<endl;
		cout<<"4. Traversal PostOrder"<<endl;
		cout<<"5. Traversal Level Order"<<endl;
		cout<<"6. Kedalaman Pohon"<<endl;
		cout<<"0. Keluar"<<endl;
		cout<<"-------------------------"<<endl;

		cout<<endl<<"Masukkan pilihan: ";
		cin>>pilih;

		switch(pilih){
		case 1:
			createSimpul(pBaru);
			insertBST(root,pBaru);
			cout<<endl<<"Data baru berhasil ditambah."<<endl;
			break;
		case 2:
			preOrder(root);
			cout<<endl;
			break;
		case 3:
			inOrder(root);
			cout<<endl;
			break;
		case 4:
			postOrder(root);
			cout<<endl;
			break;
		case 5:
			levelOrder(root);
			cout<<endl;
			break;
		case 6:
			cout<<"Kedalaman pohon: "<<depth(root)<<endl;
			break;
		}
		cout<<endl;
	}
	while(pilih!=0);
}
