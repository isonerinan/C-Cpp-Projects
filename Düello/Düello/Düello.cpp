// BİRDEN FAZLA KOMUT İSTEYEN PROGRAMLARDA SOLOLEARN ÇALIŞMIYOR.
// LÜTFEN KODU IDE'NİZE YAPIŞTIRARAK DENEYİN.

#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <cstdio>
#include <time.h>
using namespace std;

int sersemledi;

class eleman {
public:
    void ozellikler() {
        cout << "isim: " << isim << endl;
        cout << "can: " << can << endl;
        cout << "saldiriGucu: " << saldiriGucu << endl << endl;
    };

    void ozellikBelirle(string yeniAd, int yeniCan, int yeniSaldiriGucu) {
        isim = yeniAd;
        can = yeniCan;
        saldiriGucu = yeniSaldiriGucu;
    };

    int canlilikKontrol() {
        if (can <= 0) {
            if (isim == "Dusman") {
                cout << "KAZANDINIZ!";
            }

            else {
                cout << "KAYBETTINIZ!";
            }
            exit(0);
        }

        else
            return 0;
    }

    void saldir() {
        cout << "Guclu bir saldiri yapmayi deniyorsunuz." << endl;
        int randomSayi;
        srand(time(0));
        randomSayi = rand() % 3;
        Sleep(1000);

        switch (randomSayi) {
        case 0:
            can = can - 5;
            cout << "Saldirarak dusmana 5 hasar verdiniz!" << endl;
            Sleep(1000);
            break;

        case 1:
            can = can - 2;
            cout << "Saldirdiniz ancak dusman savundu. Dusmana 2 hasar verdiniz!" << endl;
            Sleep(1000);
            break;

        case 2:
            cout << "Saldiriniz basarisiz oldu! Hasar verilmedi." << endl;
            Sleep(1000);
            break;

        default:
            cout << "Saldiriniz basarisiz oldu! Hasar verilmedi." << endl;
            Sleep(1000);
            break;
        }
    };

    void savun() {

        cout << "Dusman saldiriyor." << endl;
        Sleep(1000);

        int randomSayi;
        srand(time(0));
        randomSayi = rand() % 4;
        Sleep(1000);

        switch (randomSayi) {
        case 0:
            cout << "Saldiriyi basariyla savundunuz! Hasar alinmadi." << endl;
            Sleep(1000);
            break;

        case 1:
            can = can - 2;
            cout << "Savunmaniz yetersiz oldu. 3 yerine 2 hasar aldiniz." << endl;
            Sleep(1000);
            break;

        case 2:
            can = can - 1;
            cout << "Fena olmayan bir savunmayla 3 yerine 1 hasar aldiniz." << endl;
            Sleep(1000);
            break;

        case 3:
            can = can - 3;
            cout << "Savunmaniz basarisiz! 3 hasar aldiniz." << endl;
            Sleep(1000);
            break;

        default:
            can = can - 3;
            cout << "Savunmaniz basarisiz! 3 hasar aldiniz." << endl;
            Sleep(1000);
            break;
        }

    }

    void kac() {

        cout << "Kacmayi deniyorsunuz." << endl;
        int randomSayi;
        srand(time(0));
        randomSayi = rand() % 4;
        Sleep(1000);

        switch (randomSayi) {
        case 0:
            cout << "Basariyla kactiniz! Artik dusman tehlikesi altinda degilsiniz." << endl;
            cout << "KAZANDINIZ!";
            exit(0);
            break;

        case 1:
            cout << "Kacamadiniz ve bu hatanizin bedelini caninizla odediniz!" << endl;
            can = 0;
            break;

        case 2:
            cout << "Dusman onunuzu kesti ve kacamadiniz! Ancak hasar da almadiniz." << endl;
            Sleep(1000);
            break;

        case 3:
            cout << "Kacmaya calisirken dusman tarafindan yaralandiniz! 3 hasar aldiniz." << endl;
            can = can - 3;
            Sleep(1000);
            break;

        default:
            cout << "Dusman onunuzu kesti ve kacamadiniz! Ancak hasar da almadiniz." << endl;
            Sleep(1000);
            break;
        }
    }

    void iksir() {
        cout << isim << " iksir icti." << endl;
        int randomSayi;
        srand(time(0));
        randomSayi = rand() % 10;
        Sleep(1000);

        if (randomSayi >= 0 && randomSayi < 7) {
            cout << "Iksir etkisini gosterdi. " << isim << " 3 can kazandi." << endl;
            can += 3;
            Sleep(1000);
        }

        else {
            cout << "Iksir etkisini gostermedi. " << isim << " can kazanmadi." << endl;
            Sleep(1000);
        }
    }

    void sersemleme() {
        int yeniRandom;
        srand(time(0));
        yeniRandom = rand() % 2;
        Sleep(1000);
        switch (yeniRandom) {
        case 0:
            sersemledi = 0;
            cout << isim << " saldiriya hazir gorunuyor." << endl;
            Sleep(1000);
            break;

        case 1:
            sersemledi = 1;
            cout << isim << " sersemledi ve yeni bir hamle yapamayacak." << endl;
            Sleep(1000);
        }
    }





private:
    string isim;
    int can;
    int saldiriGucu;

};

int secim;
string adimiz;
int sayi1, sayi2;


int main() {

    cout << "Isim belirleyin lutfen." << endl;
    getline(cin, adimiz);

    eleman dusman;
    dusman.ozellikBelirle("Dusman", 25, 3);

    eleman kahraman;
    kahraman.ozellikBelirle(adimiz, 15, 5);

    while (true) {
        cout << "\n";
        kahraman.ozellikler();
        dusman.ozellikler();

        cout << "Ne yapacaksin?\n1. Saldir\n2. Savun\n3. Kac\n4. Can iksiri ic (+3 Can, %30 basarisizlik riski)\n";

        cin >> secim;
        switch (secim) {
        case 1:
            dusman.saldir();
            dusman.canlilikKontrol();
            dusman.sersemleme();

            switch (sersemledi) {
            case 0:
                kahraman.savun();
                kahraman.canlilikKontrol();
                kahraman.sersemleme();

                switch (sersemledi) {
                case 0:
                    cout << "Sersemlemediniz." << endl;
                    break;

                case 1:
                    cout << "Sersemlediniz. Bu sirada dusman can iksiri kullandi." << endl;
                    dusman.iksir();
                    break;

                default:
                    cout << "Sersemlemediniz." << endl;
                    break;
                }
                break;

            default:
                break;
            }

            break;

        case 2:
            kahraman.savun();
            kahraman.canlilikKontrol();
            kahraman.sersemleme();

            switch (sersemledi) {
            case 0:
                cout << "Sersemlemediniz." << endl;
                break;

            case 1:
                cout << "Sersemlediniz. Bu sirada dusman can iksiri kullandi." << endl;
                dusman.iksir();
                break;

            default:
                cout << "Sersemlemediniz." << endl;
                break;
            }
            break;

        case 3:
            kahraman.kac();
            kahraman.canlilikKontrol();
            break;

        case 4:
            kahraman.iksir();
            kahraman.savun();
            kahraman.canlilikKontrol();
            kahraman.sersemleme();

            switch (sersemledi) {
            case 0:
                cout << "Sersemlemediniz." << endl;
                break;

            case 1:
                cout << "Sersemlediniz. Bu sirada dusman can iksiri kullandi." << endl;
                dusman.iksir();
                break;

            default:
                cout << "Sersemlemediniz." << endl;
                break;
            }
            break;

        default:
            cout << "hata" << endl;
            break;
        }
    }

    return 0;
}
