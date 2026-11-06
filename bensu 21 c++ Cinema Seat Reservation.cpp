
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int SATIR = 5;
    int SUTUN = 6;
     int FILM_SAYISI = 3;

    char koltuklar[SATIR][SUTUN];   // Koltuklarin bos veya dolu oldugunu tutan iki boyutlu dizi
    for (int i = 0; i < SATIR; i++)
        {                                        // Baslangicta tum koltuklar bos yapiliyor
            for (int j = 0; j < SUTUN; j++)
            {koltuklar[i][j] = 'B';}
        }



    string filmler[FILM_SAYISI] = {         // Filmleri tutan string dizi
        "Komedi",
        "Aksiyon",
        "Korku"
    };


    string *filmPtr = filmler;   // Film dizisini gosteren pointer

    cout << "=== SINEMA SALONU KAYIT SISTEMI ===" << endl;
    cout << "Bu programda film secip koltuk ayirtabilirsiniz." << endl;
    cout << "B harfi bos koltugu, D harfi dolu koltugu gosterir." << endl;

  // Kullanicidan alinacak bilgiler
    string isim;
    int secim;
    char satirHarf;
    int sutunNo;

    // Kullanici cikmak istemedigi surece program devam eder
    char devam = 'E';

    while (devam == 'E' || devam == 'e') {
        cout << endl;
        cout << "Adinizi giriniz: ";
        getline(cin, isim);

        cout << endl;
        cout << "Mevcut Filmler:" << endl;

        // Filmler pointer ile ekrana yazdiriliyor
        for (int i = 0; i < FILM_SAYISI; i++) {
            cout << i + 1 << ". " << *(filmPtr + i) << endl;
        }

        cout << endl;
        cout << "Film seciniz: ";
        cin >> secim;

        // Film secimi yanlissa tekrar film secimi yaptirilir
        while (secim < 1 || secim > FILM_SAYISI) {
            cout << "Yanlis film secimi yaptiniz." << endl;
            cout << "Lutfen tekrar film seciniz: ";
            cin >> secim;
        }


        int koltukSecildi = 0;

        while (koltukSecildi == 0) {
            cout << endl;
            cout << "Koltuk Durumu" << endl;
            cout << "   ";

            // Ust kisimda koltuk numaralari yazdiriliyor
            for (int j = 0; j < SUTUN; j++) {
                cout << j + 1 << " ";
            }

            cout << endl;

            // Koltuklar ekrana yazdiriliyor
            for (int i = 0; i < SATIR; i++)
                {cout << char('A' + i) << "  ";

                for (int j = 0; j < SUTUN; j++)
                  {cout << koltuklar[i][j] << " ";}

                     cout << endl;
                }

            cout << endl;
            cout << "Koltuk satiri seciniz (A-E): ";
            cin >> satirHarf;

            cout << "Koltuk numarasi seciniz (1-6): ";
            cin >> sutunNo;


            // Harf ve numara dizi indeksine cevriliyor
            int satirIndex = satirHarf - 'A';
            int sutunIndex = sutunNo - 1;

            if (satirIndex < 0 || satirIndex >= SATIR || sutunIndex < 0 || sutunIndex >= SUTUN) {
                cout << "Yanlis koltuk sectiniz. Tekrar deneyiniz." << endl;
            } else if (koltuklar[satirIndex][sutunIndex] == 'D') {
                cout << "Bu koltuk dolu. Baska koltuk seciniz." << endl;
            } else {
                koltuklar[satirIndex][sutunIndex] = 'D';

                cout << endl;
                cout << "Kayit yapildi." << endl;
                cout << "Ad: " << isim << endl;
                cout << "Film: " << *(filmPtr + secim - 1) << endl;
                cout << "Koltuk: " << satirHarf << sutunNo << endl;

                koltukSecildi = 1;
            }
        }

        cout << endl;
        cout << "Yeni kayit yapmak ister misiniz? (E/H): ";
        cin >> devam;

        getline(cin, isim);
    }

    cout << endl;
    cout << "Program bitti." << endl;

    return 0;
}
