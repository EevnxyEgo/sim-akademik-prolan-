#include <iostream>
#include <vector>

#include "include/person.hpp"
#include "include/mahasiswa.hpp"
#include "include/dosen.hpp"
#include "include/tendik.hpp"

using namespace std;

class LoginSystem
{
     public:
         string userNameAttempt;
         string passWordAttempt;

         LoginSystem(){

            access= 0;
         }
         void login(){
             cout <<"\n.LOGIN." << endl << "Masukkan Username dan Password Anda" << endl;
			 cout <<"\nUsername:";
             cin >> userNameAttempt;
             if(userNameAttempt==userName){
                cout << "Password:";
                cin >> passWordAttempt;

                if(passWordAttempt==passWord){

                    cout << "Selamat datang di Universitas HahaHihi";
                }else { 
					cout << "password yang anda masukkan salah" << endl;
					login();
				}
            } else{
				cout<<"Username yang anda masukkan tidak terdaftar, mohon gunakan username lain"<<endl;
				login();
			}
        }
    private:
        string passWord = "admin";
        string userName = "admin";
        bool access;
};



int main()
{
	LoginSystem loginlog;
    loginlog.login();

	vector<mahasiswa> recMhs;
	vector<dosen> recDosen;
	vector<tendik> recTendik;

	int menu_terpilih, d=0, e=0, f=0;

	while(1) {
		cout << endl;
		cout << "Data statistik:" << endl;
		cout << "  1. Jumlah Mahasiswa             : " << recMhs.size() << " mahasiswa" << endl;
		cout << "  2. Jumlah Dosen                 : " << recDosen.size() << " dosen" << endl;
		cout << "  3. Jumlah Tenaga Kependidikan   : " << recTendik.size() << " tenaga kependidikan" << endl;
		cout << endl;
		cout << "Menu: " << endl;
		cout << "  1. Tambah Mahasiswa" << endl;
		cout << "  2. Tambah Dosen" << endl;
		cout << "  3. Tambah Tenaga Kependidikan" << endl;
		cout << "  4. Tampilkan semua Mahasiswa" << endl;
		cout << "  5. Tampilkan semua Dosen" << endl;
		cout << "  6. Tampilkan semua Tenaga Kependidikan" << endl;
		cout << "-> Silahkan memilih salah satu: ";
		cin >> menu_terpilih;

		switch (menu_terpilih) {
			case 1:
				{
					d++;
					string nama, id, nrp, departemen;
					int dd, mm, yy, tahunmasuk, semesterke, skslulus;
					cout<<"Input ID: ";
					cin>>id;
					cout<<"Input Nama Lengkap: ";
					cin.ignore();
					getline(cin,nama);
					cout<<"Input Tanggal Lahir (dalam angka): ";
					cin>>dd;
					cout<<"Input Bulan Lahir (dalam angka): ";
					cin>>mm;
					cout<<"Input Tahun Lahir (dalam angka): ";
					cin>>yy;
					cout<<"Input NRP: ";
					cin>>nrp;
					cout<<"Input Departemen: ";
					cin.ignore();
					getline(cin,departemen);
					cout<<"Input Tahun Masuk/Angkatan: ";
					cin>>tahunmasuk;
					cout<<"Input Semester Saat Ini: ";
					cin>>semesterke;
					cout<<"Input SKS Lulus: ";
					cin>>skslulus;

					mahasiswa MAHASISWA( id,nama, dd, mm, yy, nrp, departemen, tahunmasuk, semesterke, skslulus);
					recMhs.push_back(MAHASISWA);
				}
				break;

			case 2:
				{
					e++;
					string nama, id, npp, departemen;
					int dd, mm, yy, pendidikan;
					cout<<"Input ID: ";
					cin>>id;
					cout<<"Input Nama Lengkap: ";
					cin.ignore();
					getline(cin,nama);
					cout<<"Input Tanggal Lahir (dalam angka): ";
					cin>>dd;
					cout<<"Input Bulan Lahir (dalam angka): ";
					cin>>mm;
					cout<<"Input Tahun Lahir (dalam angka): ";
					cin>>yy;
					cout<<"Input NPP: ";
					cin>>npp;
					cout<<"Input Departemen: ";
					cin.ignore();
					getline(cin,departemen);
					cout<<"Input Pendidikan: ";
					cin>>pendidikan;

					dosen DOSEN(id, nama, dd, mm, yy, npp, departemen, pendidikan);
					recDosen.push_back(DOSEN);

				}
				break;

			case 3:
				{
					f++;
					string nama, id, npp, unit;
					int dd, mm, yy;
					cout<<"Input ID: ";
					cin>>id;
					cout<<"Input Nama Lengkap: ";
					cin.ignore();
					getline(cin,nama);
					cout<<"Input Tanggal Lahir (dalam angka): ";
					cin>>dd;
					cout<<"Input Bulan Lahir (dalam angka): ";
					cin>>mm;
					cout<<"Input Tahun Lahir (dalam angka): ";
					cin>>yy;
					cout<<"Input NPP: ";
					cin>>npp;
					cout<<"Input Unit: ";
					cin>>unit;

					tendik TENDIK(id, nama, dd, mm, yy, npp, unit);
					recTendik.push_back(TENDIK);
				}
				break;

			case 4:
				{
					int i=0;
					while(i<d)
					{
						cout<<"Nama Lengkap :"<<recMhs[i].getNama()<<endl;
						cout<<"ID :"<<recMhs[i].getId()<<endl;
						cout<<"Semester :"<<recMhs[i].getSemester()<<endl;
						cout<<"SKS Lulus :"<<recMhs[i].getSKSLulus()<<endl;
						cout<<"Tanggal Lahir :"<<recMhs[i].getTglLahir()<<"-"<< recMhs[i].getBulanLahir() <<"-"<<recMhs[i].getTahunLahir()<<endl;
						cout<<endl;
						i++;
					}	
				}
				break;

			case 5:
				{
					int i=0;
					while(i<e)
					{
						cout<<"Nama Lengkap :"<<recDosen[i].getNama()<<endl;
						cout<<"ID :"<<recDosen[i].getId()<<endl;
						cout<<"Pendidikan :"<<recDosen[i].getPendidikan()<<endl;
						cout<<"Tanggal Lahir :"<<recDosen[i].getTglLahir()<<"-"<< recDosen[i].getBulanLahir() <<"-"<<recDosen[i].getTahunLahir()<<endl;
						cout<<endl;
						i++;
					}
				}
				break;

			case 6:
				{
					int i=0;
					while(i<f)
					{
						cout<<"Nama Lengkap :"<<recTendik[i].getNama()<<endl;
						cout<<"ID :"<<recTendik[i].getId()<<endl;
						cout<<"UNIT :"<<recTendik[i].getUnit()<<endl;
						cout<<"Tanggal Lahir :"<<recTendik[i].getTglLahir()<<"-"<< recTendik[i].getBulanLahir() <<"-"<<recTendik[i].getTahunLahir()<<endl;
						cout<<endl;
						i++;
					}
				break;
				
				}
		}
	}
}

