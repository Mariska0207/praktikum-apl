#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define MAX 20

bool login_admin = false;
bool login_user = false;

struct nama_pengguna{
    string username;
    string password;
};

struct data_barang{
    string nama;
    int harga;
    int stok;
    string status;
};

data_barang barang[MAX];
nama_pengguna pengguna[MAX];
string username, password, namabarang;
int pilihan, jmlhsewa, jumlahpengguna = 0, percobaan = 0, jmlhbarang = 0;

int main(){
    while(true){
        while(!login_admin && !login_user){
            system("cls");
            cout << "=============================" << endl;
            cout << "TOKO PENYEWAAN ALAT CAMPING" << endl;
            cout << "=============================" << endl;
            cout << "1. LOGIN SEBAGAI ADMIN " << endl;
            cout << "2. LOGIN SEBAGAI PENGGUNA BIASA" << endl;
            cout << "3. REGISTER" << endl;
            cout << "4. KELUAR" << endl;
            cout << "=============================" << endl;
            cout << "MASUKKAN PILIHAN ANDA : ";
            cin >> pilihan;
            system("cls");
            switch(pilihan){
                case 1:
                    cout << "=============================" << endl;
                    cout << "           ADMIN" << endl;
                    cout << "=============================" << endl;
                    cout << "MASUKKAN USERNAME : ";
                    cin >> username;
                    cout << "MASUKKAN PASSWORD : ";
                    cin >> password;
                    if(username == "mariska" && password == "052"){
                        cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
                        cout << "       LOGIN BERHASIL" << endl;
                        cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
                        system("pause");
                        login_admin = true;
                        login_user = false;
                        percobaan = 0;
                        break;
                    }else{
                        percobaan++;
                        if(percobaan == 3){
                            cout << "percobaan login anda habis, program keluar" << endl;
                            return 0;
                        }else{
                            cout << "!!! percobaan anda tersisa " << 3 - percobaan << " kali, coba lagi !!!" << endl;
                            system("pause");
                            continue;
                        }
                    }
                    break;

                case 2:
                {
                    cout << "=============================" << endl;
                    cout << "       PENGGUNA BIASA" << endl;
                    cout << "=============================" << endl;
                    cout << "MASUKKAN USERNAME : ";
                    cin >> username;
                    cout << "MASUKKAN PASSWORD : ";
                    cin >> password;
                    bool ketemu = false;    
                    for(int i = 0; i < jumlahpengguna; i++){
                        if(username == pengguna[i].username && password == pengguna[i].password){
                            cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
                            cout << "       LOGIN BERHASIL" << endl;
                            cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
                            system("pause");
                            login_admin = false;
                            login_user = true;
                            percobaan = 0;
                            ketemu = true;
                            break;
                        }
                    }
                    if(!ketemu){
                        percobaan++;
                        if(percobaan == 3){
                            cout << "percobaan login anda habis, program keluar" << endl;
                            return 0;
                        }else{
                            cout << "!!! percobaan anda tersisa " << 3 - percobaan << " kali, coba lagi !!!" << endl;
                            system("pause");
                            continue;
                        }
                    }
                }
                break;

                case 3:
                {
                    cout << "=============================" << endl;
                    cout << "           REGISTER" << endl;
                    cout << "=============================" << endl;
                    if (jumlahpengguna < MAX){
                        cout << "masukkan username : ";
                        cin >> username;
                        cout << "masukkan password : ";
                        cin >> password;
                        bool data_ada = false;
                        for(int i = 0; i < jumlahpengguna; i++){
                            if(username == pengguna[i].username){                           
                                cout << "!!! username sudah ada !!!" << endl;
                                system("pause");
                                data_ada = true;
                                break;
                            }
                        }
                        if(!data_ada){
                            cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
                            cout << "  REGISTRASI ANDA BERHASIL" << endl;
                            cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
                            pengguna[jumlahpengguna].username = username;
                            pengguna[jumlahpengguna].password = password;
                            jumlahpengguna++;
                            system("pause");
                            continue;
                        }
                    }else{
                        cout << "!!! daftar pengguna penuh !!!" << endl;
                    }
                }
                break;

                case 4:
                {
                    cout << "TERIMA KASIH TELAH  MENGGUNAKAN PROGRAM INI" << endl;
                    return 0;
                }
                break;

                default:
                {
                    cout << "!!! pilihan tidak valid !!!" << endl;
                }
                system("pause");
                continue;
            }
        }
    

        while(login_user){
            system("cls");
            cout << "=============================" << endl;
            cout << "     SILAHKAN PILIH MENU" << endl;
            cout << "=============================" << endl;
            cout << "1. lihat daftar barang" << endl;
            cout << "2. sewa barang" << endl;
            cout << "3. keluar" << endl;
            cout << "=============================" << endl;
            cout << "masukkan pilihan anda : ";
            cin >> pilihan;
            system("cls");
            switch(pilihan){
                case 1:
                    if (jmlhbarang == 0){
                        cout << "!!! daftar barang kosong !!!" << endl;
                        system("pause");
                        continue;
                    }else{
                        cout << "=========================================================" << endl;
                        cout << "                     DAFTAR BARANG" << endl;
                        cout << "=========================================================\n";
                        cout << left << setw(5) << "No"
                        << setw(20) << "Nama Barang"
                        << setw(10) << "Harga"
                        << setw(10) << "Stok"
                        << setw(10) << "Status" << endl;
                        cout << "=========================================================\n";

                        for(int i = 0; i < jmlhbarang; i++){
                            cout << left << setw(5) << i+1
                                << setw(20) << barang[i].nama
                                << setw(10) << barang[i].harga
                                << setw(10) << barang[i].stok
                                << setw(10) << barang[i].status << endl;
                        }
                        cout << "=========================================================\n";
                    }
                    system("pause");
                    continue;
                case 2:
                {
                    cout << "=========================================================" << endl;
                    cout << "                      SEWA BARANG" << endl;
                    if (jmlhbarang == 0){
                        cout << "!!! daftar barang kosong !!!" << endl;
                        system("pause");
                        continue;
                    }else{
                        cout << "=========================================================\n";
                        cout << left << setw(5) << "No"
                        << setw(20) << "Nama Barang"
                        << setw(10) << "Harga"
                        << setw(10) << "Stok"
                        << setw(10) << "Status" << endl;
                        cout << "=========================================================\n";

                        for(int i = 0; i < jmlhbarang; i++){
                            cout << left << setw(5) << i+1
                                << setw(20) << barang[i].nama
                                << setw(10) << barang[i].harga
                                << setw(10) << barang[i].stok
                                << setw(10) << barang[i].status << endl;
                        }
                        cout << "=========================================================\n";
                        int nobarang;
                        cout << "masukkan NOMOR barang yang ingin di sewa (1-" << jmlhbarang << "): ";
                        cin >> nobarang;
                        
                        if(nobarang >= 1 && nobarang <= jmlhbarang){
                            cout << "masukkan jumlah barang yang ingin di sewa : ";
                            cin >> jmlhsewa;
                            if (jmlhsewa > barang[nobarang - 1].stok){
                                cout << "!!! stok barang tidak mencukupi !!!" << endl;
                            }else{
                                barang[nobarang - 1].stok = barang[nobarang - 1].stok - jmlhsewa;
                                if(barang[nobarang - 1].stok == 0){
                                    barang[nobarang - 1].status = "habis";
                                }
                                cout << "total harga : " << jmlhsewa * barang[nobarang - 1].harga << endl;
                                cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
                                cout << "   barang berhasil di sewa" << endl;
                                cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
                            }
                        }else{
                            cout << "!!! barang tidak ditemukan !!!" << endl;
                        }
                    }
                    system("pause");
                    continue;
                }
                case 3:
                    login_user = false;
                    break;

                default:
                    cout << "!!! pilihan tidak valid !!!" << endl;
                    system("pause");
                    continue;
            }
        }
        while(login_admin){
            system("cls");
            cout << "=============================" << endl;
            cout << "    SILAHKAN PILIH MENU" << endl;
            cout << "=============================" << endl;
            cout << "1. tambah daftar barang" << endl;
            cout << "2. lihat daftar barang" << endl;
            cout << "3. update daftar barang" << endl;
            cout << "4. hapus daftar barang" << endl;
            cout << "5. keluar" << endl;
            cout << "=============================" << endl;
            cout << "masukkan pilihan anda : ";
            cin >> pilihan;
            system("cls");
            cin.ignore();
            switch(pilihan){
                case 1:
                    cout << "=============================" << endl;
                    cout << "       TAMBAH BARANG" << endl;
                    cout << "=============================" << endl;
                    if (jmlhbarang >= MAX){
                        cout << "!!! daftar barang penuh !!!" << endl;
                    }else{
                        bool ada;
                        do{
                            ada = false;
                            cout << "masukkan nama barang : ";
                            getline(cin, barang[jmlhbarang].nama);
                            for(int i = 0; i < jmlhbarang; i++){
                                if(barang[jmlhbarang].nama == barang[i].nama){
                                    cout << "nama barang sudah ada" << endl;
                                    ada = true;
                                    break;
                                }
                            }
                        }while(ada);
                        cout << "masukkan harga barang : ";
                        cin >> barang[jmlhbarang].harga;
                        cout << "masukkan stok barang : ";
                        cin >> barang[jmlhbarang].stok;
                        cout << "masukkan status barang : ";
                        cin >> barang[jmlhbarang].status;
                        jmlhbarang++;
                        cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
                        cout << "barang berhasil ditambahkan" << endl;
                        cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
                    }
                    system("pause");
                    continue;
                case 2:
                    system("cls");
                    if (jmlhbarang == 0){
                        cout << "!!! daftar barang kosong !!!" << endl;
                        system("pause");
                        continue;
                    }else{
                        cout << "=========================================================" << endl;
                        cout << "                     DAFTAR BARANG" << endl;
                        cout << "=========================================================\n";
                        cout << left << setw(5) << "No"
                        << setw(20) << "Nama Barang"
                        << setw(10) << "Harga"
                        << setw(10) << "Stok"
                        << setw(10) << "Status" << endl;
                        cout << "=========================================================\n";

                        for(int i = 0; i < jmlhbarang; i++){
                            cout << left << setw(5) << i+1
                                << setw(20) << barang[i].nama
                                << setw(10) << barang[i].harga
                                << setw(10) << barang[i].stok
                                << setw(10) << barang[i].status << endl;
                        }
                        cout << "=========================================================\n";
                    }
                    system("pause");
                    continue;
                case 3:
                    cout << "=========================================================" << endl;
                    cout << "                 update daftar barang" << endl;
                    if (jmlhbarang == 0){
                        cout << "!!! daftar barang kosong !!!" << endl;
                        system("pause");
                        continue;
                    }else{
                        cout << "=========================================================\n";
                        cout << left << setw(5) << "No"
                        << setw(20) << "Nama Barang"
                        << setw(10) << "Harga"
                        << setw(10) << "Stok"
                        << setw(10) << "Status" << endl;
                        cout << "=========================================================\n";

                        for(int i = 0; i < jmlhbarang; i++){
                            cout << left << setw(5) << i+1
                                << setw(20) << barang[i].nama
                                << setw(10) << barang[i].harga
                                << setw(10) << barang[i].stok
                                << setw(10) << barang[i].status << endl;
                        }
                        cout << "=========================================================\n";
                        int no_update;
                        cout << "masukkan NOMOR barang yang ingin di update (1-" << jmlhbarang << "): ";
                        cin >> no_update;
                        if(no_update >= 1 && no_update <= jmlhbarang){
                            cin.ignore();
                            bool ada;
                            do{
                                ada = false;
                                cout << "masukkan nama barang : ";
                                getline(cin, barang[no_update-1].nama);
                                for(int i = 0; i < jmlhbarang; i++){
                                    if(barang[no_update-1].nama == barang[i].nama && i != no_update-1){
                                        cout << "nama barang sudah ada" << endl;
                                        ada = true;
                                        break;
                                    }
                                }
                            }while(ada);
                            cout << "masukkan harga barang baru : ";
                            cin >> barang[no_update-1].harga;
                            cout << "masukkan stok barang baru : ";
                            cin >> barang[no_update-1].stok;
                            cout << "masukkan status barang baru : ";
                            cin >> barang[no_update-1].status;
                            cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
                            cout << "               barang berhasil di update" << endl;
                            cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
                        }else{
                            cout << "!!! barang tidak ditemukan !!!" << endl;
                        }
                    }
                    system("pause");
                    continue;
                case 4:
                    cout << "=========================================================" << endl;
                    cout << "hapus daftar barang" << endl;
                    if (jmlhbarang == 0){
                        cout << "!!! daftar barang kosong !!!" << endl;
                        system("pause");
                        continue;
                    }else{
                        cout << "=========================================================\n";
                        cout << left << setw(5) << "No"
                        << setw(20) << "Nama Barang"
                        << setw(10) << "Harga"
                        << setw(10) << "Stok"
                        << setw(10) << "Status" << endl;
                        cout << "=========================================================\n";

                        for(int i = 0; i < jmlhbarang; i++){
                            cout << left << setw(5) << i+1
                                << setw(20) << barang[i].nama
                                << setw(10) << barang[i].harga
                                << setw(10) << barang[i].stok
                                << setw(10) << barang[i].status << endl;
                        }
                        cout << "=========================================================\n";
                        int no_hapus;
                        cout << "masukkan NOMOR barang yang ingin di hapus (1-" << jmlhbarang << "): ";
                        cin >> no_hapus;
                        cin.ignore();
                        if(no_hapus >= 1 && no_hapus <= jmlhbarang){
                            for(int j = no_hapus - 1; j < jmlhbarang - 1; j++){
                                barang[j] = barang[j + 1];
                            }
                            jmlhbarang--;
                            cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
                            cout << "                barang berhasil di hapus" << endl;
                            cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
                        }else{
                            cout << "!!! barang tidak ditemukan !!!" << endl;
                        }
                    }
                    system("pause");
                    continue;
                case 5:
                    system("pause");
                    login_admin = false;
                    break;
                default:
                    cout << "!!! pilihan tidak valid !!!" << endl;
                    system("pause");
                    continue;
            }
        }
    }
}