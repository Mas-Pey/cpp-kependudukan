#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstring>

void input();
void output();
void searching();
void sorting();
void trx();
using namespace std;
FILE *pdd,*pdd2,*pdd3;
struct data_kependudukan{
	long int ktp;
	char nama[50],status[50],gol[5];
	};
data_kependudukan data[100],temp;
void tampilan(int i);
void saving(int i);
string garis(25,'=');
string garis2(80,'=');
int menu,jmlh,i,pilih;
char menuawal;
char namafile[50];
main(){
	do{
	system("cls");
	cout<<garis<<"\nDATA KEPENDUDUKAN\n"<<garis<<endl;
	cout<<"\t1. INPUT DATA\n\t2. TAMPILKAN DATA\n\t3. SEARCHING DATA\n\t4. SORTING DATA\n\t5. TRANSAKSI\n\t6. KELUAR\n";
	cout<<garis<<endl<<garis<<"\nMasukkan Pilihan\t= ";cin>>menu;system("cls");
	if(menu==1){input();
	}else if(menu==2){output();
	}else if(menu==3){searching();
	}else if(menu==4){sorting();		
	}else if(menu==5){trx();		
	}else if(menu==6){exit(0);
	}else{
		cout<<"\n\tMenu tidak tersedia\n";
	}
	cout<<"\nKembali ke Menu Utama?\nY = Kembali\nN = Keluar\nMasukkan Pilihan\t= ";cin>>menuawal;
	}while(menuawal=='y'||menuawal=='Y');
	
}

void input(){
	cin.ignore();
	cout<<garis<<"\n INPUT DATA KEPENDUDUKAN\n"<<garis<<"\nMasukkan nama file\t= ";cin.getline(namafile,50);
	pdd=fopen(namafile,"a");
	cout<<"\nBanyaknya Data = ";cin>>jmlh;
	for(i=0;i<jmlh;i++){
		cout<<"\tNomer KTP\t= ";cin>>data[i].ktp;cin.ignore();
		cout<<"\tNama\t\t= ";cin.getline(data[i].nama,50);
		cout<<"\tStatus\t\t= ";cin.getline(data[i].status,50);
		cout<<"\tGolongan darah\t= ";cin.getline(data[i].gol,5);
		for(int x=0;x<data[i].gol[x];x++)data[i].gol[x]=toupper(data[i].gol[x]);
		fwrite(&data[i],sizeof(data[i]),1,pdd);
		cout<<endl;
	}
	fclose(pdd);
}

void output(){
	cin.ignore();
	cout<<garis<<"=\n OUTPUT DATA KEPENDUDUKAN\n"<<garis<<"=\nMasukkan nama file\t= ";cin.getline(namafile,50);
	if((pdd=fopen(namafile,"r"))==NULL){
		cout<<"\tTidak dapat membuka File\n";
	}else{
		i=0;
		while(fread(&data[i],sizeof(data[i]),1,pdd) != 0){
			i++;
		}
		tampilan(i);
	}
		fclose(pdd);
}

void searching(){
	cin.ignore();
	char menusearching;
	string name,stat,golongan;
	int noktp;
	do{system("cls");
	cout<<garis<<"\n CARI DATA KEPENDUDUKAN\n"<<garis<<"\nMasukkan nama file\t= ";cin.getline(namafile,50);
	if((pdd=fopen(namafile,"r"))==NULL){
		cout<<"\tTidak dapat membuka File\n";
	}else{system("cls");
		i=0;
		while(fread(&data[i],sizeof(data[i]),1,pdd) != 0){
			i++;
		}
		cout<<garis<<"\n CARI DATA KEPENDUDUKAN\n"<<garis<<"\n\t1. Sequential\n\t2. Binary\n"<<garis;
		cout<<"\nMasukkan Pilihan\t= ";cin>>menu;
		if(menu==1){
			do{system("cls");
			bool found=0;
			int x=0;
			cout<<garis<<"====\n PENCARIAN DENGAN SEQUENTIAL\n===="<<garis<<"\n\t1. NIK\n\t2. Nama\n\t3. Status\n\t4. Golongan Darah\n===="<<garis;
			cout<<"\nMasukkan Pilihan\t= ";cin>>pilih;
			if(pilih==1){
				cout<<"Masukkan Nomor KTP\t= ";cin>>noktp;
				cout<<endl;
				while(x<i){
					if(noktp==data[x].ktp){
						found=1;
						cout<<"\tNomor KTP\t= "<<data[x].ktp;
						cout<<"\n\tNama\t\t= "<<data[x].nama;
						cout<<"\n\tStatus\t\t= "<<data[x].status;
						cout<<"\n\tGolongan Darah\t= "<<data[x].gol<<endl<<endl;
					}
					x+=1;
				}
				if(!found) cout<<"\tData yang anda cari tidak ditemukan\n";
			}else if(pilih==2){cin.ignore();
				cout<<"Masukkan Nama Penduduk\t= ";getline(cin,name);
				cout<<endl;
				while(x<i){
					if(name==data[x].nama){
						found=1;
						cout<<"\tNomor KTP\t= "<<data[x].ktp;
						cout<<"\n\tNama\t\t= "<<data[x].nama;
						cout<<"\n\tStatus\t\t= "<<data[x].status;
						cout<<"\n\tGolongan Darah\t= "<<data[x].gol<<endl<<endl;
					}
					x+=1;
				}
				if(!found) cout<<"\tData yang anda cari tidak ditemukan\n";
			}else if(pilih==3){cin.ignore();
				cout<<"Masukkan Status Penduduk= ";getline(cin,stat);
				cout<<endl;
				while(x<i){
					if(stat==data[x].status){
						found=1;
						cout<<"\tNomor KTP\t= "<<data[x].ktp;
						cout<<"\n\tNama\t\t= "<<data[x].nama;
						cout<<"\n\tStatus\t\t= "<<data[x].status;
						cout<<"\n\tGolongan Darah\t= "<<data[x].gol<<endl<<endl;
					}
					x+=1;
				}
				if(!found) cout<<"\tData yang anda cari tidak ditemukan\n";
			}else if(pilih==4){cin.ignore();
				cout<<"Masukkan Golongan Darah\t= ";getline(cin,golongan);
				cout<<endl;
				while(x<i){
					if(golongan==data[x].gol){
						found=1;
						cout<<"\tNomor KTP\t= "<<data[x].ktp;
						cout<<"\n\tNama\t\t= "<<data[x].nama;
						cout<<"\n\tStatus\t\t= "<<data[x].status;
						cout<<"\n\tGolongan Darah\t= "<<data[x].gol<<endl<<endl;
					}
					x+=1;
				}
				if(!found) cout<<"\tData yang anda cari tidak ditemukan\n";
			}else{
				cout<<"\n\tMenu tidak tersedia\n";
			}
			cout<<"\nKembali ke menu Sequential Search?\nY = Kembali\nN = Keluar\nMasukkan Pilihan\t= ";cin>>menusearching;
			}while(menusearching=='y'||menusearching=='Y');
		}else if(menu==2){
			do{system("cls");
			bool found=0;
			int x=0,j=0,vs=0;
			int bawah=0,tengah=0,atas=0;
			atas=i;//nilai atas adalah nilai i alias jumlah data
			cout<<garis<<"\n PENCARIAN DENGAN BINARY\n"<<garis<<"\n\t1. NIK\n\t2. Nama\n\t3. Status\n\t4. Golongan Darah\n"<<garis;
			cout<<"\nMasukkan Pilihan\t= ";cin>>pilih;
			//karena metode binary search harus urut, maka disorting terlebih dahulu
			if(pilih==1){
				for(x=0;x<i-1;x++){//SORTING METODE BUBBLESORT
					for(j=0;j<i-1-x;j++){
						if(data[j].ktp>data[j+1].ktp){
							temp=data[j];
							data[j]=data[j+1];
							data[j+1]=temp;
						}
					}
				}
				cout<<"Masukkan Nomor KTP\t= ";cin>>noktp;
				cout<<endl;
				while(bawah<=atas && !found){
					tengah=(bawah+atas)/2;
					if(noktp==data[tengah].ktp){
						found=1;
						cout<<"\tNomor KTP\t= "<<data[tengah].ktp;
						cout<<"\n\tNama\t\t= "<<data[tengah].nama;
						cout<<"\n\tStatus\t\t= "<<data[tengah].status;
						cout<<"\n\tGolongan Darah\t= "<<data[tengah].gol<<endl<<endl;
					}
					else{
						if(noktp<data[tengah].ktp){atas=tengah-1;}
						else{bawah=tengah+1;}
					}
				}
				if(!found) cout<<"\tData yang anda cari tidak ditemukan\n";
			}else if(pilih==2){cin.ignore();
				for(x=0;x<i-1;x++){//SORTING METODE BUBBLESORT
					for(j=0;j<i-1-x;j++){
						vs=strcmp(data[j].nama,data[j+1].nama);
						if(vs>0){
							temp=data[j];
							data[j]=data[j+1];
							data[j+1]=temp;
						}
					}
				}
				cout<<"Masukkan Nama Penduduk\t= ";getline(cin,name);
				cout<<endl;
				while(bawah<=atas && !found){
					tengah=(bawah+atas)/2;
					if(name==data[tengah].nama){
						found=1;
						cout<<"\tNomor KTP\t= "<<data[tengah].ktp;
						cout<<"\n\tNama\t\t= "<<data[tengah].nama;
						cout<<"\n\tStatus\t\t= "<<data[tengah].status;
						cout<<"\n\tGolongan Darah\t= "<<data[tengah].gol<<endl<<endl;
					}
					else{
						if(name<data[tengah].nama){atas=tengah-1;}
						else{bawah=tengah+1;}
					}
				}
				if(!found) cout<<"\tData yang anda cari tidak ditemukan\n";
			}else if(pilih==3){cin.ignore();
				for(x=0;x<i-1;x++){//SORTING METODE BUBBLESORT
					for(j=0;j<i-1-x;j++){
						vs=strcmp(data[j].status,data[j+1].status);
						if(vs>0){
							temp=data[j];
							data[j]=data[j+1];
							data[j+1]=temp;
						}
					}
				}
				cout<<"Masukkan Status Penduduk= ";getline(cin,stat);
				cout<<endl;
				while(bawah<=atas && !found){
					tengah=(bawah+atas)/2;
					if(stat==data[tengah].status){
						found=1;
						cout<<"\tNomor KTP\t= "<<data[tengah].ktp;
						cout<<"\n\tNama\t\t= "<<data[tengah].nama;
						cout<<"\n\tStatus\t\t= "<<data[tengah].status;
						cout<<"\n\tGolongan Darah\t= "<<data[tengah].gol<<endl<<endl;
					}
					else{
						if(stat<data[tengah].status){atas=tengah-1;}
						else{bawah=tengah+1;}
					}
				}
				if(!found) cout<<"\tData yang anda cari tidak ditemukan\n";
			}else if(pilih==4){cin.ignore();
				for(x=0;x<i-1;x++){//SORTING METODE BUBBLESORT
					for(j=0;j<i-1-x;j++){
						vs=strcmp(data[j].gol,data[j+1].gol);
						if(vs>0){
							temp=data[j];
							data[j]=data[j+1];
							data[j+1]=temp;
						}
					}
				}
				cout<<"Masukkan Golongan Darah\t= ";getline(cin,golongan);
				cout<<endl;
				while(bawah<=atas && !found){
					tengah=(bawah+atas)/2;
					if(golongan==data[tengah].gol){
						found=1;
						cout<<"\tNomor KTP\t= "<<data[tengah].ktp;
						cout<<"\n\tNama\t\t= "<<data[tengah].nama;
						cout<<"\n\tStatus\t\t= "<<data[tengah].status;
						cout<<"\n\tGolongan Darah\t= "<<data[tengah].gol<<endl<<endl;
					}
					else{
						if(golongan<data[tengah].gol){atas=tengah-1;}
						else{bawah=tengah+1;}
					}
				}
				if(!found) cout<<"\tData yang anda cari tidak ditemukan\n";
			}else{
				cout<<"\n\tMenu tidak tersedia\n";
			}
			cout<<"\nKembali ke menu Binary Search?\nY = Kembali\nN = Keluar\nMasukkan Pilihan\t= ";cin>>menusearching;
			}while(menusearching=='y'||menusearching=='Y');
		}else{
			cout<<"\n\tMenu tidak tersedia\n";
		}
	}
	fclose(pdd);
	cout<<"\nKembali ke menu searching?\nY = Kembali\nN = Keluar\nMasukkan Pilihan\t= ";cin>>menuawal;cin.ignore();
	}while(menuawal=='y'||menuawal=='Y');
}

void sorting(){
	cin.ignore();
	char menusorting;
	int urut,x,j,vs,k;
	do{system("cls");
	cout<<garis<<"==\n PENGURUTUAN DATA PENDUDUK\n"<<garis<<"==\nMasukkan nama file\t= ";cin.getline(namafile,50);
	if((pdd=fopen(namafile,"r"))==NULL){
		cout<<"\tTidak dapat membuka File\n";
	}else{system("cls");
		i=0;
		while(fread(&data[i],sizeof(data[i]),1,pdd) != 0){
			i++;
		}
		do{system("cls");
		cout<<garis<<"==\n PENGURUTUAN DATA PENDUDUK\n"<<garis<<"==\n1. Nomor KTP(bubble sort)\n2. Nama(selection Sort)\n3. Status(insertion Sort)\n4. Gol. Darah(quick Sort)\n"<<garis;
		cout<<"==\nMasukkan Pilihan\t= ";cin>>pilih;
		if(pilih==1){system("cls");
			cout<<garis<<"\n PENGURUTUAN DATA BUBBLE\n"<<garis<<"\n\t1. Ascending\n\t2. Descending\n"<<garis<<"\nMasukkan Pilihan\t= ";cin>>urut;
			if(urut==1){
				cout<<"\t\t\tPengurutan Nomor KTP Ascending";
				for(x=0;x<i-1;x++){
					for(j=0;j<i-1-x;j++){
						if(data[j].ktp>data[j+1].ktp){
							temp=data[j];
							data[j]=data[j+1];
							data[j+1]=temp;
						}
					}
				}
				tampilan(i);saving(i);
			}else if(urut==2){
				cout<<"\t\t\tPengurutan Nomor KTP Descending";
				for(x=0;x<i-1;x++){
					for(j=0;j<i-1-x;j++){
						if(data[j].ktp<data[j+1].ktp){
							temp=data[j];
							data[j]=data[j+1];
							data[j+1]=temp;
						}
					}
				}
				tampilan(i);saving(i);
			}else{
				cout<<"\n\tMenu tidak tersedia\n";
			}
		}else if(pilih==2){system("cls");
			cout<<garis<<"===\n PENGURUTUAN DATA SELECTION\n"<<garis<<"===\n\t1. Ascending\n\t2. Descending\n"<<garis<<"===\nMasukkan Pilihan\t= ";cin>>urut;
			if(urut==1){
				cout<<"\t\t\tPengurutan Nama Ascending";
				for(x=0;x<i;x++){
					for(j=x+1;j<i;j++){
						vs=strcmp(data[x].nama,data[j].nama);
						if(vs==1){
							temp=data[x];
							data[x]=data[j];
							data[j]=temp;
						}
					}
				}
				tampilan(i);saving(i);
			}else if(urut==2){
				cout<<"\t\t\tPengurutan Nama Descending";
				for(x=0;x<i;x++){
					for(j=x+1;j<i;j++){
						vs=strcmp(data[x].nama,data[j].nama);
						if(vs==-1){
							temp=data[x];
							data[x]=data[j];
							data[j]=temp;
						}
					}
				}
				tampilan(i);saving(i);
			}else{
				cout<<"\n\tMenu tidak tersedia\n";
			}
		}else if(pilih==3){system("cls");
			cout<<garis<<"===\n PENGURUTUAN DATA INSERTION\n"<<garis<<"===\n\t1. Ascending\n\t2. Descending\n"<<garis<<"===\nMasukkan Pilihan\t= ";cin>>urut;
			if(urut==1){
				cout<<"\t\t\tPengurutan Status Ascending";
				for(x=1;x<i;x++){
					temp=data[x];
					j=x-1;
					vs=strcmp(temp.status,data[j].status);
					while(vs==-1 && j>=0){
						data[j+1]=data[j];
						j--;
						vs=strcmp(temp.status,data[j].status);
					}
					data[j+1]=temp;
				}
				tampilan(i);saving(i);
			}else if(urut==2){
				cout<<"\t\t\tPengurutan Status Descending";
				for(x=1;x<i;x++){
					temp=data[x];
					j=x-1;
					vs=strcmp(temp.status,data[j].status);
					while(vs==1 && j>=0){
						data[j+1]=data[j];
						j--;
						vs=strcmp(temp.status,data[j].status);
					}
					data[j+1]=temp;
				}
				tampilan(i);saving(i);
			}else{
				cout<<"\n\tMenu tidak tersedia\n";
			}
		}else if(pilih==4){system("cls");
			cout<<garis<<"\n PENGURUTUAN DATA SHELL\n"<<garis<<"\n\t1. Ascending\n\t2. Descending\n"<<garis<<"\nMasukkan Pilihan\t= ";cin>>urut;
			if(urut==1){
				cout<<"\t\t\tPengurutan Gol. Darah Ascending";
				for(k=i/2;k>0;k/=2){
					for(x=k;x<i;x++){
						for(j=x-k;j>=0;j-=k){
							vs=strcmp(data[j+k].gol,data[j].gol);
							if(vs==1 || vs==0){
								break;
							}else{
								temp=data[j];
								data[j]=data[j+k];
								data[j+k]=temp;
							}
						}
					}
				}
				tampilan(i);saving(i);
			}else if(urut==2){
				cout<<"\t\t\tPengurutan Gol. Darah Descending";
				for(k=i/2;k>0;k/=2){
					for(x=k;x<i;x++){
						for(j=x-k;j>=0;j-=k){
							vs=strcmp(data[j+k].gol,data[j].gol);
							if(vs==-1 || vs==0){
								break;
							}else{
								temp=data[j];
								data[j]=data[j+k];
								data[j+k]=temp;
							}
						}
					}
				}
				tampilan(i);saving(i);
			}else{
				cout<<"\n\tMenu tidak tersedia\n";
			}
		}else{
			cout<<"\n\tMenu tidak tersedia\n";
		}
		cout<<"\nKembali ke menu jenis sorting?\nY = Kembali\nN = Keluar\nMasukkan Pilihan\t= ";cin>>menusorting;
		}while(menusorting=='y'||menusorting=='Y');
	}
	fclose(pdd);
	cout<<"\nKembali ke menu sorting?\nY = Kembali\nN = Keluar\nMasukkan Pilihan\t= ";cin>>menuawal;cin.ignore();
	}while(menuawal=='y'||menuawal=='Y');
}

void trx(){
	data_kependudukan data2[100];
	char filebaru[50],filesplit[50],filesplit2[50];
	char ulang;
	int size,x,j;
	do{system("cls");
	cout<<garis<<"\n      MENU TRANSAKSI\n"<<garis<<"\n1. Merging Sambung\n2. Merging Urut\n3. Updating\n4. Splitting\n"<<garis;
	cout<<"\nMasukkan Pilihan\t= ";cin>>menu;
	if(menu==1){
		do{
		cin.ignore();
		size=0;
		system("cls");
		cout<<garis<<"\n     MERGING SAMBUNG\n"<<garis;
		cout<<"\nNama File Pertama\t= ";cin.getline(namafile,50);
		if((pdd=fopen(namafile,"r"))==NULL){
			cout<<"\tTidak dapat membuka File\n";
			goto back;
		}else{
			i=0;
			while(fread(&data[i],sizeof(data[i]),1,pdd) != 0){
				data2[size]=data[i];
				i++;
				size++;
			}
			tampilan(i);
		}
		fclose(pdd);
		cout<<"\nNama File Kedua\t\t= ";cin.getline(namafile,50);
		if((pdd=fopen(namafile,"r"))==NULL){
			cout<<"\tTidak dapat membuka File\n";
			goto back;
		}else{
			i=0;
			while(fread(&data[i],sizeof(data[i]),1,pdd) != 0){
				data2[size]=data[i];
				i++;
				size++;
			}
			tampilan(i);
		}
		fclose(pdd);
		cout<<"\nMasukkan nama file baru\t= ";cin.getline(filebaru,50);
		pdd=fopen(filebaru,"w");
		for(x=0;x<size;x++){
			fwrite(&data2[x],sizeof(data2[x]),1,pdd);
		}
		fclose(pdd);
		cout<<"File baru berhasil dibuat!\n";
		back:
		cout<<"\nUlangi?\nY = Kembali\nN = Keluar\nMasukkan Pilihan\t= ";cin>>ulang;
		}while(ulang=='y'||ulang=='Y');
	}else if(menu==2){
		do{
		cin.ignore();
		size=0;
		system("cls");
		cout<<garis<<"\n       MERGING URUT\n"<<garis;
		cout<<"\nNama File Pertama\t= ";cin.getline(namafile,50);
		if((pdd=fopen(namafile,"r"))==NULL){
			cout<<"\tTidak dapat membuka File\n";
			goto back2;
		}else{
			i=0;
			while(fread(&data[i],sizeof(data[i]),1,pdd) != 0){
				data2[size]=data[i];
				i++;
				size++;
			}
			tampilan(i);
		}
		fclose(pdd);
		cout<<"\nNama File Kedua\t\t= ";cin.getline(namafile,50);
		if((pdd=fopen(namafile,"r"))==NULL){
			cout<<"\tTidak dapat membuka File\n";
			goto back2;
		}else{
			i=0;
			while(fread(&data[i],sizeof(data[i]),1,pdd) != 0){
				data2[size]=data[i];
				i++;
				size++;
			}
			tampilan(i);
		}
		fclose(pdd);
		for(x=1;x<size;x++){
			temp=data2[x];
			j=x-1;
			while(temp.ktp<data2[j].ktp && j>=0){
				data2[j+1]=data2[j];
				j--;
			}
			data2[j+1]=temp;
		}
		cout<<"\nMasukkan nama file baru\t= ";cin.getline(filebaru,50);
		pdd=fopen(filebaru,"w");
		for(int x=0;x<size;x++){
			fwrite(&data2[x],sizeof(data2[x]),1,pdd);
		}
		fclose(pdd);
		cout<<"File baru berhasil dibuat!\n";
		back2:
		cout<<"\nUlangi?\nY = Kembali\nN = Keluar\nMasukkan Pilihan\t= ";cin>>ulang;
		}while(ulang=='y'||ulang=='Y');
	}else if(menu==3){
		int noktp;
		do{
		int x=0;
		bool found=0;
		cin.ignore();
		system("cls");
		cout<<garis<<"\n\tUPDATING\n"<<garis;
		cout<<"\nMasukkan nama file\t= ";cin.getline(namafile,50);
		if((pdd=fopen(namafile,"r"))==NULL){
			cout<<"\tTidak dapat membuka File\n";
			goto back3;
		}else{
			i=0;
			while(fread(&data[i],sizeof(data[i]),1,pdd) != 0){
				i++;
			}
			tampilan(i);
		}
		fclose(pdd);
		cout<<"Masukkan Nomor KTP\t= ";cin>>noktp;
		cout<<endl;
		while(x<i){
			if(noktp==data[x].ktp){
				found=1;
				cout<<"\tNomor KTP\t= "<<data[x].ktp;
				cout<<"\n\tNama\t\t= "<<data[x].nama;
				cout<<"\n\tStatus\t\t= "<<data[x].status;
				cout<<"\n\tGolongan Darah\t= "<<data[x].gol;
				cout<<"\n\nData Update Baru\t= ";
				cout<<"\n\n\tNomer KTP\t= ";cin>>data[x].ktp;cin.ignore();
				cout<<"\tNama\t\t= ";cin.getline(data[x].nama,50);
				cout<<"\tStatus\t\t= ";cin.getline(data[x].status,50);
				cout<<"\tGolongan darah\t= ";cin.getline(data[x].gol,5);
				for(int z=0;z<data[x].gol[z];z++)data[x].gol[z]=toupper(data[x].gol[z]);
				cout<<garis2<<endl<<endl;
			}
			x+=1;
		}
		if(!found){cout<<"\tData yang anda cari tidak ditemukan\n";
		}else{
			cout<<"Masukkan nama file baru\t= ";cin.getline(filebaru,50);
			pdd2=fopen(filebaru,"w");
			for(int x=0;x<i;x++){
				fwrite(&data[x],sizeof(data[x]),1,pdd2);
			}
			cout<<"File baru berhasil dibuat!\n";
			fclose(pdd2);
		}
		back3:
		cout<<"\nUlangi?\nY = Kembali\nN = Keluar\nMasukkan Pilihan\t= ";cin>>ulang;
		}while(ulang=='y'||ulang=='Y');
	}else if(menu==4){
		int k;
		do{
		cin.ignore();
		system("cls");
		cout<<garis<<"\n\tSPLITTING\n"<<garis;
		cout<<"\nMasukkan nama file\t= ";cin.getline(namafile,50);
		if((pdd=fopen(namafile,"r"))==NULL){
			cout<<"\tTidak dapat membuka File\n";
		}else{
			i=0;
			while(fread(&data[i],sizeof(data[i]),1,pdd) != 0){
				i++;
			}
			tampilan(i);
			fclose(pdd);
			cout<<"\nMasukkan nilai tengah No. KTP untuk dibagi menjadi 2 = ";cin>>k;
			cin.ignore();
			cout<<"\nNama File Split Pertama\t= ";cin.getline(filesplit,50);
			cout<<"Nama File Split Kedua\t= ";cin.getline(filesplit2,50);
			pdd=fopen(namafile,"r");
			pdd2=fopen(filesplit,"w");
			pdd3=fopen(filesplit2,"w");
			i=0;
			while(fread(&data[i],sizeof(data[i]),1,pdd) != 0){
				if(data[i].ktp<k) fwrite(&data[i],sizeof(data[i]),1,pdd2);
				else fwrite(&data[i],sizeof(data[i]),1,pdd3);
				i++;
			}fclose(pdd);fclose(pdd2);fclose(pdd3);
			cout<<"\nFile Split berhasil dibuat!\n";
		}
		cout<<"\nUlangi?\nY = Kembali\nN = Keluar\nMasukkan Pilihan\t= ";cin>>ulang;
		}while(ulang=='y'||ulang=='Y');
	}else{
		cout<<"\n\tMenu tidak tersedia\n";
	}
	cout<<"\nKembali ke menu transaksi?\nY = Kembali\nN = Keluar\nMasukkan Pilihan\t= ";cin>>menuawal;
	}while(menuawal=='y'||menuawal=='Y');
}

void tampilan(int i){
	cout<<endl<<garis2<<endl;
	cout<<left<<setfill(' ')<<setw(15)<<" Nomor KTP"<<setfill(' ')<<setw(35)<<" Nama"<<setfill(' ')<<setw(12)<<" Gol. Darah"<<setfill(' ')<<setw(20)<<" Status";
	cout<<endl<<garis2<<endl;
	for(int x=0;x<i;x++){
		cout<<" "<<left<<setfill(' ')<<setw(14)<<data[x].ktp;
		if(strlen(data[x].nama)>34){
			cout<<" ";
			for(int j=0;j<34;j++)cout<<data[x].nama[j];
		}else cout<<" "<<setfill(' ')<<setw(34)<<data[x].nama;
		cout<<" "<<left<<setfill(' ')<<setw(11)<<data[x].gol;
		cout<<" "<<left<<setfill(' ')<<setw(19)<<data[x].status<<endl;
	}
	cout<<garis2<<endl;
}

void saving(int i){
	char baru;
	cout<<"\nSimpan menjadi file baru (y/n)? ";cin>>baru;cin.ignore();
	if(baru=='y'||baru=='Y'){
		char filebaru[50];
		cout<<"\nMasukkan nama file baru\t= ";cin.getline(filebaru,50);
		pdd=fopen(filebaru,"w");
		for(int x=0;x<i;x++){
			fwrite(&data[x],sizeof(data[x]),1,pdd);
		}
		cout<<"File baru berhasil dibuat!\n";
		fclose(pdd);
	}
}
