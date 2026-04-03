#include <iostream>
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

void takvalid(){
    cout << "!!! pilihan tidak valid !!!" << endl;
    system("pause");
}
void judul(string judul){
    cout << "=============================" << endl;
    cout << setw(22) << judul << endl;
    cout << "=============================" << endl;
}
void judulpnjng(string judul){
    cout << "=========================================================" << endl;
    cout << setw(35) << judul << endl;
    cout << "=========================================================\n";
}
bool cek_username(string username, int index){
    if(index >= jumlahpengguna){
        return false;
    }
    if(username == pengguna[index].username){
        return true;
    }
    return cek_username(username, index + 1);
}
void registrasi(){
    cout << "=============================" << endl;
    cout << "           REGISTER" << endl;
    cout << "=============================" << endl;
    if (jumlahpengguna < MAX){
        cout << "masukkan username : ";
        cin >> username;
        cout << "masukkan password : ";
        cin >> password;
        if(cek_username(username, 0)){
            cout << "!!! username sudah ada !!!" << endl;
            system("pause");
            return;
        }
        cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
        cout << "  REGISTRASI ANDA BERHASIL" << endl;
        cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
        pengguna[jumlahpengguna].username = username;
        pengguna[jumlahpengguna].password = password;
        jumlahpengguna++;
        system("pause");
    }else{
        cout << "!!! daftar pengguna penuh !!!" << endl;
    }
}
bool admin_login(string &username, string &password){
    cout << "=============================" << endl;
    cout << "           ADMIN" << endl;
    cout << "=============================" << endl;
    cout << "MASUKKAN USERNAME : ";
    cin >> username;
    cout << "MASUKKAN PASSWORD : ";
    cin >> password;
    if(username == "mariska" && password == "052"){
        return true;
    }
    return false;
}
bool login_pengguna(string &username, string &password){
    cout << "=============================" << endl;
    cout << "       PENGGUNA BIASA" << endl;
    cout << "=============================" << endl;
    cout << "MASUKKAN USERNAME : ";
    cin >> username;
    cout << "MASUKKAN PASSWORD : ";
    cin >> password;    
    for(int i = 0; i < jumlahpengguna; i++){
        if(username == pengguna[i].username && password == pengguna[i].password){
            return true;
        }
    }
    return false;
}
void lihat_barang(){
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
void tambah_stok(data_barang *barang){
    int jstok;
    cout << "masukkan jumlah stok: ";
    cin >> jstok;
    barang->stok += jstok;
    if(barang->stok > 0){
        barang->status = "tersedia";
    }else{
        barang->status = "habis";
    }
    cout << "stok berhasil ditambahkan!" << endl;
}
int total_harga(int jmlhsewa, int harga){
    return jmlhsewa * harga;
}
void sewa_barang(){
    lihat_barang();
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
            cout << "total harga : " << total_harga(jmlhsewa, barang[nobarang - 1].harga) << endl;
            cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
            cout << "   barang berhasil di sewa" << endl;
            cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
        }
    }else{
        cout << "!!! barang tidak ditemukan !!!" << endl;
    }
}
void tambah_barang(){
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
}
void update_barang(){
    lihat_barang();
    int no_update;
    cout << "masukkan NOMOR barang yang ingin di update (1-" << jmlhbarang << "): ";
    cin >> no_update;
    if(no_update >= 1 && no_update <= jmlhbarang){
        cin.ignore();
        bool ada;
        do{
            ada = false;
            cout << "masukkan nama barang : ";
            getline(cin, barang[no_update - 1].nama);
            for(int i = 0; i < jmlhbarang; i++){
                if(barang[no_update - 1].nama == barang[i].nama && i != no_update - 1){
                    cout << "nama barang sudah ada" << endl;
                    ada = true;
                    break;
                }
            }
        }while(ada);
        cout << "masukkan harga barang baru : ";
        cin >> barang[no_update - 1].harga;
        cout << "masukkan stok barang baru : ";
        cin >> barang[no_update - 1].stok;
        cout << "masukkan status barang baru : ";
        cin >> barang[no_update - 1].status;
        cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
        cout << "               barang berhasil di update" << endl;
        cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    }else{
        cout << "!!! barang tidak ditemukan !!!" << endl;
    }
}
void hapus_barang(){
    lihat_barang();
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
void menuadmin(){
    while(login_admin){
        system("cls");
        judul("SILAHKAN PILIH MENU");
        cout << "1. tambah daftar barang" << endl;
        cout << "2. lihat daftar barang" << endl;
        cout << "3. update daftar barang" << endl;
        cout << "4. hapus daftar barang" << endl;
        cout << "5. tambah stok barang" << endl;
        cout << "6. keluar" << endl;
        cout << "=============================" << endl;
        cout << "masukkan pilihan anda : ";
        cin >> pilihan;
        system("cls");
        cin.ignore();
        switch(pilihan){
            case 1: 
                tambah_barang();
                system("pause");
                continue;
            case 2:
                system("cls");
                if (jmlhbarang == 0){
                    cout << "!!! daftar barang kosong !!!" << endl;
                    system("pause");
                    continue;
                }else{
                    judulpnjng("                    DAFTAR BARANG");
                    lihat_barang();
                }
                system("pause");
                continue;
            case 3:
                judulpnjng("                    UPDATE BARANG");
                if (jmlhbarang == 0){
                    cout << "!!! daftar barang kosong !!!" << endl;
                    system("pause");
                    continue;
                }else{
                    update_barang();
                }
                system("pause");
                continue;
            case 4:
                judulpnjng("                    HAPUS BARANG");
                if (jmlhbarang == 0){
                    cout << "!!! daftar barang kosong !!!" << endl;
                    system("pause");
                    continue;
                }else{
                    hapus_barang();
                }
                system("pause");
                continue;
            case 5:
                judulpnjng("                    TAMBAH STOK BARANG");
                if (jmlhbarang == 0){
                    cout << "!!! daftar barang kosong !!!" << endl;
                    system("pause");
                    continue;
                }else{
                    lihat_barang();
                    int bstok;
                    cout << "masukkan NOMOR barang yang ingin ditambah stoknya (1-" << jmlhbarang << "): ";
                    cin >> bstok;
                    if(bstok >= 1 && bstok <= jmlhbarang){
                        tambah_stok(&barang[bstok - 1]);
                    }else{
                        cout << "!!! barang tidak ditemukan !!!" << endl;
                    }
                }
                system("pause");
                continue;
            case 6:
                system("pause");
                login_admin = false;
                break;
            default:
                takvalid();
                continue;
        }
    }
}
void menuuser(){
    while(login_user){
        system("cls");
        judul("     SILAHKAN PILIH MENU");
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
                    judulpnjng("                    DAFTAR BARANG");
                    lihat_barang();
                }
                system("pause");
                continue;
            case 2:
                judulpnjng("                    SEWA BARANG");
                if (jmlhbarang == 0){
                    cout << "!!! daftar barang kosong !!!" << endl;
                    system("pause");
                    continue;
                }else{
                    sewa_barang();
                }
                system("pause");
                continue;
            case 3:
                login_user = false;
                break;
            default:
                takvalid();
                continue;
        }
    }
}

int main(){
    barang[0] = {"Tenda 2 orang", 50000, 10, "tersedia"};
    barang[1] = {"Sleeping Bag", 30000, 8, "tersedia"};
    barang[2] = {"kursi lipat", 40000, 5, "tersedia"};
    jmlhbarang = 3;
    while(true){
        while(!login_admin && !login_user){
            system("cls");
            judul("TOKO PENYEWAAN ALAT CAMPING");
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
                    if(admin_login(username, password)){
                        judul("LOGIN BERHASIL");
                        system("pause");
                        login_admin = true;
                        login_user = false;
                        percobaan = 0;
                        menuadmin();
                        break;
                    }else{
                        percobaan++;
                        if(percobaan == 3){
                            cout << "percobaan login anda habis, program keluar" << endl;
                            return 0;
                        }else{
                            cout << "!!! percobaan anda tersisa " << 3 - percobaan << " kali, coba lagi !!!" << endl;
                            system("pause");
                        }
                        continue;
                    }
                    case 2:
                    if(login_pengguna(username, password)){
                        judul("LOGIN BERHASIL");
                        system("pause");
                        login_admin = false;
                        login_user = true;
                        percobaan = 0;
                        menuuser();
                        break;
                    }else{
                        percobaan++;
                        if(percobaan == 3){
                            cout << "percobaan login anda habis, program keluar" << endl;
                            return 0;
                        }else{
                            cout << "!!! percobaan anda tersisa " << 3 - percobaan << " kali, coba lagi !!!" << endl;
                            system("pause");
                        }
                        continue;
                    }
                case 3:
                    registrasi();
                    continue;
                case 4:
                    cout << "TERIMA KASIH TELAH  MENGGUNAKAN PROGRAM INI" << endl;
                    return 0;
                default:
                    takvalid();
                    continue;
            }
        }
    }
}