#include <iostream>
#include<cmath>

using namespace std;
class karmasik {//karmasık sayı icin class olusturma
public:
    float reel, sanal;//karmasık sayı classının üyeleri
    karmasik(float r, float s) {//classın constructorı
        reel = r;
        sanal = s;
    }
    float pi = 3.14;
    void kutupsalGosterim() {//kutupsal gösterim
        float z, aci;
        aci = (atan(sanal / reel)) * 180 / pi;
        z = pow((pow(reel, 2) + pow(sanal, 2)), 0.5); //karmasik sayinin orijine uzaklıgı
        cout << "Karmasik sayinin kutupsal gosterim= " << z << "* cis(" << aci << ")" << endl;

    }
    void yaz() {//karmasık sayının standart gösterimini ekrana yazdırma
        if (sanal > 0) {//sanal kısmın isaretine göre  gösterim degisiyor
            cout << reel << "+" << sanal << "i" << endl;
        }
        else if (sanal < 0) {
            cout << reel << "-" << -sanal << "i" << endl;
        }
        else {
            cout << reel << endl;
        }
    }

    karmasik operator*(karmasik karmasik1) {//operator overloading *
        karmasik carpim(0, 0);
        carpim.reel = (reel * karmasik1.reel) - (sanal * karmasik1.sanal);
        carpim.sanal = (reel * karmasik1.sanal) + (sanal * karmasik1.reel);
        return carpim;
    };
    karmasik operator+(karmasik karmasik1) {//operator overloading +
        karmasik toplam(0, 0);
        toplam.reel = reel + karmasik1.reel;
        toplam.sanal = sanal + karmasik1.sanal;
        return toplam;
    };
    karmasik operator-(karmasik karmasik1) {//operator overloading -
        karmasik fark(0, 0);
        fark.reel = reel - karmasik1.reel;
        fark.sanal = sanal - karmasik1.sanal;
        return fark;
    };
    karmasik operator/ (karmasik karmasik1) {//operator overloading /
        karmasik bolum(0, 0);
        bolum.reel = (reel / karmasik1.reel) + (sanal / karmasik1.sanal);
        bolum.sanal = (sanal / karmasik1.reel) - (reel / karmasik1.sanal);
        return bolum;

    }
    karmasik operator+=(karmasik* karmasik2) {//operator overloading +=
        karmasik2->reel += reel;
        karmasik2->sanal += sanal;
        return *karmasik2;
    }
    karmasik operator-=(karmasik* karmasik2) {//operator overloading -=
        karmasik2->reel -= reel;
        karmasik2->sanal -= sanal;
        return *karmasik2;
    }
    karmasik operator*=(karmasik* karmasik2) {//operator overloading *=

        float a, b;
        a = (reel * karmasik2->reel) - (sanal * karmasik2->sanal);
        b = (reel * karmasik2->sanal) + (sanal * karmasik2->reel);
        karmasik2->reel = a; karmasik2->sanal = b;
        return *karmasik2;
    }
    karmasik operator/=(karmasik* karmasik2) {//operator overloading /=
        float c, d;
        c = (reel / karmasik2->reel) + (sanal / karmasik2->sanal);
        d = (sanal / karmasik2->reel) - (reel / karmasik2->sanal);
        karmasik2->reel = c; karmasik2->sanal = d;
        return *karmasik2;
    }
};
int main()
{
    float r1, r2, s1, s2;
    int tamamdevam, islemsec, hangisayi, sayidegis;
    cout << "Ilk karmasik sayinin reel kismini giriniz." << endl; cin >> r1;
    cout << "Ilk karmasik sayinin sanal kismini giriniz." << endl; cin >> s1;
    cout << "Ikincik armasik sayinin reel kismini giriniz." << endl; cin >> r2;
    cout << "Ikinci karmasik sayinin sanal kismini giriniz." << endl; cin >> s2;
    karmasik karmasik1(r1, s1);
    karmasik karmasik2(r2, s2);
    do {//istedigi müddetce işlem yaptırabilsin diye do while ekledim.

        karmasik sonuc(0, 0);//sonuclar burada toplanacak (sonuc=karmasik1+karmasik2 gibi) 

        cout << "Yapmak istediginiz islemi seciniz!\n IKI KARMASIK SAYIYI TOPLAMA=1\n IKI KARMASIK SAYIYI CIKARMA=2\n IKI KARMASIK SAYIYI CARPMA=3\n IKI KARMASIK SAYIYI BOLME = 4\n += = 5\n -= = 6\n *= = 7\n /= =\n KUTUPSAL GOSTERIM= 9" << endl;
        cin >> islemsec;//switch casein deger girimi
        switch (islemsec)//menü için switch case
        {
        case 1:

            sonuc = karmasik1.operator+(karmasik2);
            sonuc.yaz();
            break;
        case 2:

            sonuc = karmasik1.operator-(karmasik2);
            sonuc.yaz();
            break;
        case 3:
            sonuc = karmasik1.operator*(karmasik2);
            sonuc.yaz();
            break;
        case 4:
            sonuc = karmasik1.operator/(karmasik2);
            sonuc.yaz();
            break;
        case 5:
            cout << "Sonucu ilk girdiginiz karmasik sayiya atamak icin 1'e\n İkinci girdiginiz karmasik sayiya atamak icin 2'ye basiniz." << endl;
            cin >> hangisayi;
            if (hangisayi == 1) {//sonuç girilen iki karmasik sayidan hangisine atansın 
                karmasik2.operator+=(&karmasik1);
                karmasik1.yaz();
            }
            else if (hangisayi == 2) {
                karmasik1.operator+=(&karmasik2);
                karmasik2.yaz();
            }
            else {
                cout << "yanlis secim" << endl;
                break;
            }
            break;
        case 6:
            cout << "Sonucu ilk girdiginiz karmasik sayiya atamak icin 1'e\n İkinci girdiginiz karmasik sayiya atamak icin 2'ye basiniz." << endl;
            cin >> hangisayi;
            if (hangisayi == 1) {//sonuç girilen iki karmasik sayidan hangisine atansın 
                karmasik2.operator-=(&karmasik1);
                karmasik1.yaz();
            }
            else if (hangisayi == 2) {
                karmasik1.operator-=(&karmasik2);
                karmasik2.yaz();
            }
            else {
                cout << "yanlis secim" << endl;
                break;
            }
            break;
        case 7:
            cout << "Sonucu ilk girdiginiz karmasik sayiya atamak icin 1'e\n İkinci girdiginiz karmasik sayiya atamak icin 2'ye basiniz." << endl;
            cin >> hangisayi;
            if (hangisayi == 1) {//sonuç girilen iki karmasik sayidan hangisine atansın 
                karmasik2.operator*=(&karmasik1);
                karmasik1.yaz();
            }
            else if (hangisayi == 2) {
                karmasik1.operator*=(&karmasik2);
                karmasik2.yaz();
            }
            else {
                cout << "yanlis secim" << endl;
                break;
            }
            break;
        case 8:
            cout << "Sonucu ilk girdiginiz karmasik sayiya atamak icin 1'e\n İkinci girdiginiz karmasik sayiya atamak icin 2'ye basiniz." << endl;
            cin >> hangisayi;
            if (hangisayi == 1) {//sonuç girilen iki karmasik sayidan hangisine atansın 
                karmasik2.operator/=(&karmasik1);
                karmasik1.yaz();
            }
            else if (hangisayi == 2) {
                karmasik1.operator/=(&karmasik2);
                karmasik2.yaz();
            }
            else {
                cout << "yanlis secim" << endl;
                break;
            }
            break;
        case 9:
            cout << "İlk girdiginiz karmasik sayinin kutupsal gosterimi icin 1'e\n İkinci girdiginiz karmasik sayinin kutupsal gosterimi icin 2'ye basiniz." << endl;
            cin >> hangisayi;

            if (hangisayi == 1) {//girilen iki karmasik sayidan hangisiyle islem yapmak istiyorsunuz?
                karmasik1.kutupsalGosterim();
            }
            else if (hangisayi == 2) {
                karmasik2.kutupsalGosterim();
            }
            else {
                cout << "yanlis secim" << endl;
                break;
            }
            break;
        default:
            cout << "Hatalı secim yaptiniz" << endl;
            break;
        }

        cout << " islem yapmaya devam etmek icin 1 e basiniz" << endl; cin >> tamamdevam;//islem yapmaya devam edecek misiniz?

        do {//ayni sayilarla devam edip etmeyecegini sorma
            cout << "ayni sayilarla devam etmek icin 0'a\n farkli sayilar girmek icin 1'e basiniz.!" << endl;
            cin >> sayidegis;
            if (sayidegis == 1) {//farkli sayılarla işlem yapmak isterse tekrar değer alma
                cout << "Ilk karmasik sayinin reel kismini giriniz." << endl; cin >> r1;
                cout << "Ilk karmasik sayinin sanal kismini giriniz." << endl; cin >> s1;
                cout << "Ikincik armasik sayinin reel kismini giriniz." << endl; cin >> r2;
                cout << "Ikinci karmasik sayinin sanal kismini giriniz." << endl; cin >> s2;
                karmasik karmasik1(r1, s1);
                karmasik karmasik2(r2, s2);
            }
            else if (sayidegis == 0) {
                cout << "ayni sayilarla devam ediliyor." << endl;
            }
            else {
                cout << "yanlis secim yaptiniz" << endl;
            }
            system("cls");//ekranı silme

        } while (sayidegis != 0 and sayidegis != 1);

    } while (tamamdevam == 1);

    system("pause");
    return 0;

}

