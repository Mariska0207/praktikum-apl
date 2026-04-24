#include <iostream>
#include <iomanip>
#include <cmath>
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
int pilihan, p2, jmlhsewa, jumlahpengguna = 0, percobaan = 0, jmlhbarang = 0;

void takvalid(){
    cout << "!!! pilihan tidak valid !!!" << endl;
    system("pause");
}
void judul(string judul){
    cout << "=============================" << endl;
    cout << setw(23) << judul << setw(22) <<endl;
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

int carinama(data_barang* arr, int n, string nama){
    for (int i = 0; i < n; i++) {
        if ((arr + i)->nama == nama){
            return i;
        }
    }
    return -1;
}

int cariharga(int target){
    if (jmlhbarang == 0) return -1;
    int n = jmlhbarang;
    int step = sqrt(n);
    int prev = 0;
    while (prev < n && barang[min(step, n)-1].harga < target) {
        prev = step;
        step += (int)sqrt(n);
        if (prev >= n) return -1;
    }
    int batas = step;
    if (batas > n) batas = n;
    while (prev < batas){
        if(barang[prev].harga == target){
            return prev;
        }
        prev++;
    }
    return -1;
}

void lihatbrng(int index){
    cout << left << setw(5) << "No"
        << setw(20) << "nama"
        << setw(10) << "harga"
        << setw(10) << "stok"
        << setw(10) << "status" << endl;
    cout << left << setw(5) << index+1
        << setw(20) << barang[index].nama
        << setw(10) << barang[index].harga
        << setw(10) << barang[index].stok
        << setw(10) << barang[index].status << endl;
    cout << "=========================================================\n";
}

void tambah_stok(data_barang *barang){
    int jstok;
    cout << "masukkan jumlah stok: ";
    try{
        cin >> jstok;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Input harus berupa angka!");
        }
        if(jstok < 0){
            throw invalid_argument("Input harus berupa angka positif!");
        }
    }
    catch(const invalid_argument& e){
        cout << e.what() << endl;
        return;
    }
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
    try{
        cin >> nobarang;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Input harus berupa angka!");
        }
    }
    catch(const invalid_argument& e){
        cout << e.what() << endl;
        return;
    }
    if(nobarang < 1 || nobarang > jmlhbarang){
        cout << "!!! barang tidak ditemukan !!!" << endl;
        return;
    }else{
        cout << "masukkan jumlah barang yang ingin di sewa : ";
        try{
            cin >> jmlhsewa;
            if(jmlhsewa < 0){
                throw invalid_argument("Input harus berupa angka positif!");
            }
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Input harus berupa angka!");
            }
        }
        catch(const invalid_argument& e){
            cout << e.what() << endl;
            return;
        }
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
        cin.ignore();
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
        try{
            cin >> barang[jmlhbarang].harga;
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Input harus berupa angka!");
            }
        }
        catch(const invalid_argument& e){
            cout << e.what() << endl;
            return;
        }
        cout << "masukkan stok barang : ";
        try{
            cin >> barang[jmlhbarang].stok;
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Input harus berupa angka!");
            }
        }
        catch(const invalid_argument& e){
            cout << e.what() << endl;
            return;
        }
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
    try{
        cin >> no_update;
        if(no_update < 0){
            throw invalid_argument("Input harus berupa angka positif!");
        }
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Input harus berupa angka!");
        }
    }
    catch(const invalid_argument& e){
        cout << e.what() << endl;
        return;
    }
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
    try{
        cin >> no_hapus;
        if(no_hapus < 0){
            throw invalid_argument("Input harus berupa angka positif!");
        }
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Input harus berupa angka!");
        }
    }
    catch(const invalid_argument& e){
        cout << e.what() << endl;
        return;
    }
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

void urutharga(data_barang* arr, int n){
    for (int i = 0; i < n - 1; i++){
        int min_idx = i;
        for (int j = i + 1; j < n; j++){
            if ((arr + j)->harga < (arr + min_idx)->harga){
                min_idx = j;
            }
        }
        if(min_idx != i){
            swap(*(arr + i), *(arr + min_idx));
        }
    }
} 

void nama(data_barang* arr, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    data_barang L[n1], R[n2];

    for (int i = 0; i < n1; i++){
        *(L + i) = *(arr + l + i);
    }
    for (int j = 0; j < n2; j++){
        *(R + j) = *(arr + m + 1 + j);
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2){
        if((L + i)->nama >= (R + j)->nama){
            *(arr + k) = *(L + i);
            i++;
        }else{
            *(arr + k) = *(R + j);
            j++;
        }
        k++;
    }
    while (i < n1){
        *(arr + k) = *(L + i);
        i++;k++;
    }
    while (j < n2){
        *(arr + k) = *(R + j);
        j++;k++;
    }
}

void namasort(data_barang* arr, int l, int r){
    if (l < r){
        int m = (l + r) / 2;
        namasort(arr, l, m);
        namasort(arr, m + 1, r);
        nama(arr, l, m, r);
    }
}

void urutstok(data_barang* arr, int n){
    for (int i = 1; i < n ; i++){
        data_barang key = *(arr + i);
        int j = i - 1;
        while (j >= 0 && (arr + j)->stok > key.stok){
            *(arr + j + 1) = *(arr + j);
            j = j - 1;
        }
        *(arr + j + 1) = key;
    }
}

void menulihat(){
    bool keluar = false;
    while(!keluar){
        system("cls");
        judul("SILAHKAN PILIH MENU");
        cout << "1. harga termurah-termahal\n2. nama urut(z-a)\n3. stok terdikit-terbanyak\n4. cari berdasarkan nama\n5. cari berdasarkan harga\n6.keluar" << endl;
        cout << "=============================" << endl;
        cout << "masukkan pilihan anda : ";
        try{
            cin >> p2;
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Input harus berupa angka!");
            }
        }
        catch(const invalid_argument& e){
            cout << e.what() << endl;
            system("pause");
            continue;
        }
        system("cls");
        switch(p2){
            case 1:
                judulpnjng("                    DAFTAR BARANG URUT HARGA");
                if (jmlhbarang == 0){
                    cout << "!!! daftar barang kosong !!!" << endl;
                    system("pause");
                    continue;
                }else{
                    urutharga(barang, jmlhbarang);
                    lihat_barang();
                    system("pause");
                    continue;
                }
                case 2:
                    judulpnjng("                    DAFTAR BARANG URUT NAMA");
                    if(jmlhbarang == 0){
                        cout << "!!! daftar barang kosong !!!" << endl;
                        system("pause");
                        continue;
                    }else{
                        namasort(barang, 0, jmlhbarang-1);
                        lihat_barang();
                        system("pause");
                        continue;
                    }
                case 3:
                    judulpnjng("                    DAFTAR BARANG URUT STOK");
                    if(jmlhbarang == 0){
                        cout << "!!! daftar barang kosong !!!" << endl;
                        system("pause");
                        continue;                    
                    }else{
                        urutstok(barang, jmlhbarang);
                        lihat_barang();
                        system("pause");
                        continue;
                    }
                case 4:
                    judulpnjng("               CARI BARANG BERDASARKAN NAMA");
                    if(jmlhbarang == 0){
                        cout << "!!! daftar barang kosong !!!" << endl;
                        system("pause");
                        continue;
                    }else{
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "masukkan nama barang yang ingin dicari : ";
                        try{
                            getline(cin, namabarang);
                            if(namabarang.empty()){
                                throw invalid_argument("Input tidak boleh kosong!");
                            }
                        }
                        catch(const invalid_argument& e){
                            cout << e.what() << endl;
                            continue;
                        }
                        int index = carinama(barang, jmlhbarang, namabarang);
                        if (index == -1){
                            cout << "!!! barang tidak ditemukan !!!" << endl;
                        }else{
                            judulpnjng("              Barang ditemukan pada index ke- " + to_string(index + 1));
                            lihatbrng(index);
                        }
                        system("pause");
                        break;
                    }
                case 5:
                    judulpnjng("               CARI BARANG BERDASARKAN HARGA");
                    if(jmlhbarang == 0){
                        cout << "!!! daftar barang kosong !!!" << endl;
                        system("pause");
                        continue;
                    }else{
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        urutharga(barang, jmlhbarang);
                        cout << "masukkan harga barang yang ingin dicari : ";
                        int targetharga;
                        cin >> targetharga;
                        int index = cariharga(targetharga);
                        if(index == -1){
                            cout << "!!! barang tidak ditemukan !!!" << endl;
                        }else{
                            judulpnjng("              Barang ditemukan pada index ke- " + to_string(index + 1));
                            lihatbrng(index);
                        }
                        system("pause");
                        break;
                    }
                case 6:
                    system("pause");
                    keluar = true;
                    break;
                default:
                    takvalid();
                    continue;
        }
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
        try{
            cin >> pilihan;
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Input harus berupa angka!");
            }
        }
        catch(const invalid_argument& e){
            cout << e.what() << endl;
            system("pause");
            continue;
        }
        system("cls");
        switch(pilihan){
            case 1: 
                tambah_barang();
                system("pause");
                continue;
            case 2:
            {
                menulihat();
                continue;
            }
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
                    try{
                        cin >> bstok;
                        if(cin.fail()){
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            throw invalid_argument("Input harus berupa angka!");
                        }
                    }
                    catch(const invalid_argument& e){
                        cout << e.what() << endl;
                        system("pause");
                        continue;
                    }
                    if(bstok >= 1 && bstok <= jmlhbarang){
                        tambah_stok(&barang[bstok - 1]);
                    }else{
                        cout << "!!! barang tidak ditemukan !!!" << endl;
                    }
                }
                system("pause");
                continue;
            case 6:
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
        try{
            cin >> pilihan;
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Input harus berupa angka!");
            }
        }
        catch(const invalid_argument& e){
            cout << e.what() << endl;
            system("pause");
            continue;
        }
        system("cls");
        switch(pilihan){
            case 1:
            {
                menulihat();
                continue;
            }
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
    barang[0] = {"tenda 2 orang", 50000, 10, "tersedia"};
    barang[1] = {"sleeping Bag", 30000, 8, "tersedia"};
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
            try{
                cin >> pilihan;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument("Input harus berupa angka!");
                }
            }
            catch(const invalid_argument& e){
                cout << e.what() << endl;
                system("pause");
                continue;
            }
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