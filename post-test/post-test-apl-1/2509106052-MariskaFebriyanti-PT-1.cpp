#include <iostream>
using namespace std;

int main(){
    system("cls");
    int percobaan = 0;
    string ulangi;
    cout << "=================================================" << endl;
    cout << "    Selamat Datang di Program Konversi Waktu" << endl;
    cout << "=================================================" << endl;
    
    while(percobaan < 3){
        string username;
        string password;
        cout << "Masukkan username : ";
        cin >> username;
        cout << "Masukkan Password : ";
        cin >> password;
        
        if(username == "mariska" && password == "052"){
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "     Login Berhasil" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            system("cls");
            break;
        } else {
            percobaan++;
            cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
            cout << "     Login anda ke-" << percobaan << " Gagal" << endl;
            cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
            
            if(percobaan == 3){
                cout << "Anda telah gagal login sebanyak 3 kali. Program berhenti." << endl;
                return 0;
            }
        }
    }
    
    while(true){
        int pilihan;
        float jam, menit, detik;
        cout << "=================================================" << endl;
        cout << "              MENU KONVERSI WAKTU" << endl;
        cout << "=================================================" << endl;
        cout << "1. Jam ke menit dan detik" << endl;
        cout << "2. Menit ke jam dan detik" << endl;
        cout << "3. Detik ke jam dan menit" << endl;
        cout << "=================================================" << endl;
        cout << "Pilihan Anda : ";
        cin >> pilihan;
        
        if(pilihan == 1){
            cout << "Masukkan nilai waktu yang ingin dikonversi : ";
            cin >> jam;
            menit = jam * 60;
            detik = jam * 3600;
            cout << "=================================================" << endl;
            cout << "hasil konversi " << jam << " jam , yaitu : " << menit << " menit " << detik << " detik" << endl;
            cout << "=================================================" << endl;
        } else if(pilihan == 2){
            cout << "Masukkan nilai waktu yang ingin dikonversi : ";
            cin >> menit;
            jam = menit / 60;
            detik = menit * 60;
            cout << "=================================================" << endl;
            cout << "hasil konversi " << menit << " menit , yaitu : " << jam << " jam " << detik << " detik" << endl;
            cout << "=================================================" << endl;
        } else if(pilihan == 3){
            cout << "Masukkan nilai waktu yang ingin dikonversi : ";
            cin >> detik;
            jam = detik / 3600;
            menit = detik / 60;
            cout << "=================================================" << endl;
            cout << "hasil konversi " << detik << " detik , yaitu : " << jam << " jam " << menit << " menit" << endl;
            cout << "=================================================" << endl;
        } else {
            cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
            cout << "     Pilihan tidak valid." << endl;
            cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
            continue;
        }
        
        cout << "\nApakah Anda ingin mengulang konversi? (ya/tidak): ";
        cin >> ulangi;
        
        if (ulangi == "tidak" || ulangi == "t" || ulangi == "Tidak" || ulangi == "T" || ulangi == "TIDAK") {
            cout << "Terima kasih! Program selesai." << endl;
            cout << " (˶ᵔ ᵕ ᵔ˶) " ;
            break;
        } else if (ulangi == "ya" || ulangi == "y" || ulangi == "Ya" || ulangi == "Y" || ulangi == "YA") {
            system("cls");
            continue;
        } else {
            cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
            cout << "     inputan tidak valid" << endl;
            cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
            break;
        }
    }
    return 0;
}