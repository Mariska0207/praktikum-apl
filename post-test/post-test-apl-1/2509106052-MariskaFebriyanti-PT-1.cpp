#include <iostream>
using namespace std;
int main(){
    int percobaan = 0;
    string ulangi;
    while(percobaan < 3){
        string username;
        string password;
        cout << "Masukkan username : ";
        cin >> username;
        cout << "Masukkan Password : ";
        cin >> password;
        if(username == "mariska" && password == "052"){
            cout << "Login Berhasil" << endl;
            break;
        }else{
            percobaan++;
            cout << "Login anda ke-" << percobaan << " Gagal" << endl;
            if(percobaan == 3){
                cout << "Anda telah gagal login sebanyak 3 kali. Program berhenti." << endl;
                return 0;
            }
        }
    }
    while(true){
        int pilihan;
        float jam, menit, detik;
        cout << "\npilih waktu yang ingin di konversi : " << endl;
        cout << "1. Jam" << endl;
        cout << "2. Menit" << endl;
        cout << "3. Detik" << endl;
        cout << "Pilihan Anda : ";
        cin >> pilihan;
        if(pilihan == 1){
            cout << "Masukkan nilai waktu yang ingin dikonversi : ";
            cin >> jam;
            menit = jam * 60;
            detik = jam * 3600;
            cout << "hasil konversi " << jam << " jam , yaitu : " << menit << " menit " << detik << " detik" << endl;
        }
        else if(pilihan == 2){
            cout << "Masukkan nilai waktu yang ingin dikonversi : ";
            cin >> menit;
            jam = menit / 60;
            detik = menit * 60;
            cout << "hasil konversi " << menit << " menit , yaitu : " << jam << " jam " << detik << " detik" << endl;
        }
        else if(pilihan == 3){
            cout << "Masukkan nilai waktu yang ingin dikonversi : ";
            cin >> detik;
            jam = detik / 3600;
            menit = detik / 60;
            cout << "hasil konversi " << detik << " detik , yaitu : " << jam << " jam " << menit << " menit" << endl;
        } else {
            cout << "Pilihan tidak valid." << endl;
            continue;
        }

        cout << "\nApakah Anda ingin mengulang konversi? (ya/tidak): ";
        cin >> ulangi;

    if (ulangi == "tidak" || ulangi == "t" || ulangi == "Tidak" || ulangi == "T" || ulangi == "TIDAK") {
        cout << "Terima kasih! Program selesai." << endl;
        break;
        }else if (ulangi == "ya" || ulangi == "y" || ulangi == "Ya" || ulangi == "Y" || ulangi == "YA") {
        continue;
        }else{
        cout << "inputan tidak valid";
        break;
        }
    }
    return 0;
}