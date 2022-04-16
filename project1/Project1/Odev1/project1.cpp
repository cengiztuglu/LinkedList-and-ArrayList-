#include <iostream>
#include <stdlib.h>
#include<chrono>
using namespace std;


struct Node
{
    int deger;
    Node* sonraki;

};

struct ArrayList {
    int* bas; //dizinin başlangıç adresini tutar
    void ekle(int, int); //değer ve sıra numarası alarak ekleme yapar
    void olustur(); //başlangıç için gereken tanımları içerir
    void sil(int); //sıra numarası alarak silme yapar
    void yazdir(); //liste içeriğini ekrana yazar
    int sayac; //liste kaç eleman olduğunu tutar
};
struct Liste
{

    Node* bas;//listenin başlangıç adresini tutar
    void olustur();//başlangıç için gereken tanımları içerir
    void yazdir();//liste içeriğini ekrana yazar
    void ekle(int, int); //değer ve sıra numarası alarak ekleme yapar
    void guncelle(int, int);
    void sil(int);//sıra numarası alarak silme yapar
    void bosalt();//listenin bellek alanlarını iade eder
    void basaekle(int);
    void sonaekle(int);
    void ortayaekle(int);
    int kayitsayisi;//değer ve sıra numarası alarak günceller
};


int main()
{
    {


        int verisayisi = 100;
        Liste* l = new Liste();
        ArrayList* arrlist = new ArrayList();
        arrlist->olustur();
        l->olustur();
        Node* n = new Node();



        auto begin = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < verisayisi; i++)
        {
            l->ekle(i, i);

        }
        auto end = std::chrono::high_resolution_clock::now();
        auto addtime = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
        cout << "Bağlanntılı Listede ekleme  suresi => " << addtime.count() << " mikro-saniye" << endl;
        //l->yazdir();

        auto begin1 = std::chrono::high_resolution_clock::now();
        l->guncelle(4, 8);
        auto end1 = std::chrono::high_resolution_clock::now();
        auto  updatetime = std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1);
        cout << "Bağlanntılı Listede güncelleme süresi => " << updatetime.count() << " mikro-saniye" << endl;
        //l->yazdir();
        auto begin2 = std::chrono::high_resolution_clock::now();
        l->sil(4);
        auto end2 = std::chrono::high_resolution_clock::now();
        auto deletetime = std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2);
        cout << "Bağlanntılı Listede silme süresi => " << deletetime.count() << " mikro-saniye" << endl;
        //  l->yazdir();



        auto beginb = std::chrono::high_resolution_clock::now();
        l->basaekle(8);
        auto endb = std::chrono::high_resolution_clock::now();
        auto basaekletime = std::chrono::duration_cast<std::chrono::microseconds>(endb - beginb);
        cout << "Bağlanntılı Listede BasaEklene suresi => " << basaekletime.count() << " mikro-saniye" << endl;
        l->yazdir();
        cout << "\n" << endl;
        auto begins = std::chrono::high_resolution_clock::now();
        l->sonaekle(7);
        auto ends = std::chrono::high_resolution_clock::now();
        auto sonaekletime = std::chrono::duration_cast<std::chrono::microseconds>(ends - begins);
        cout << "Bağlanntılı Listede sonaekleme suresi => " << sonaekletime.count() << " mikro-saniye" << endl;
        l->yazdir();
        cout << "\n" << endl;
        auto begino = std::chrono::high_resolution_clock::now();
        l->ortayaekle(0);
        auto endo = std::chrono::high_resolution_clock::now();
        auto ortaekletime = std::chrono::duration_cast<std::chrono::microseconds>(endo - begino);
        cout << "Bağlanntılı Listede ortaya ekleme suresi => " << ortaekletime.count() << " mikro-saniye" << endl;
        l->yazdir();
        cout << "\n\n" << endl;


        auto begin3 = std::chrono::high_resolution_clock::now();
        l->bosalt();
        auto end3 = std::chrono::high_resolution_clock::now();
        auto bosalttime = std::chrono::duration_cast<std::chrono::microseconds>(end3 - begin3);
        cout << "Bağlanntılı Listede Boşaltma suresi => " << bosalttime.count() << " mikro-saniye" << endl;
        cout << "\n\n" << endl;

        cout << "ARRAYLİST İSLEMLERİ""\n";

        auto begin4 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < verisayisi; i++)
        {
            arrlist->ekle(i, i);
        }

        auto end4 = std::chrono::high_resolution_clock::now();
        auto arrekle = std::chrono::duration_cast<std::chrono::microseconds>(end4 - begin4);
        cout << "\n";
        cout << "Array Listede ekleme suresi => " << arrekle.count() << " mikro-saniye" << endl;

        arrlist->olustur();

        auto begin5 = std::chrono::high_resolution_clock::now();


        arrlist->sil(5);

        auto end5 = std::chrono::high_resolution_clock::now();
        auto arrdelete = std::chrono::duration_cast<std::chrono::microseconds>(end5 - begin5);
        cout << "\n";
        cout << "Array Listede silme suresi => " << arrdelete.count() << " mikro-saniye" << endl;






    }
}
void Liste::olustur()
{
    bas = NULL;
}
void Liste::yazdir()
{
    Node* tara;
    tara = bas;
    if (!tara)
    {
        cout << "Liste Boş" << endl;
        return;
    }
    while (tara)
    {
        cout << tara->deger << " ";
        tara = tara->sonraki;
    }
    cout << endl;
}
void Liste::ekle(int a, int b)
{
    Node* n = new Node();
    n = new Node();
    n->deger = a;
    if (bas == NULL)
    {
        bas = n;
        return;
    }
    else
    {
        n->sonraki = bas;
        bas = n;

    }
    kayitsayisi++;



}

void Liste::sil(int a)
{

    Node* tara = new Node;
    Node* arka = new Node;
    int sayac = 1;
    tara = bas;
    if (a <= 0)
    {
        cout << "hatali kayit Numarasi\n";
        return;
    }
    if (a == 1)
    {
        bas = bas->sonraki;
        delete tara;
        kayitsayisi--;
        return;


    }
    while ((tara != NULL) && (sayac < a))
    {

        arka = tara;
        tara = tara->sonraki;
        sayac++;

    }
    if (sayac < a)
    {
        cout << "kayıt bulunamadı\n";


    }
    else
    {
        arka->sonraki = tara->sonraki;
        delete tara;
        kayitsayisi--;



    }


}

void Liste::guncelle(int x, int y)
{

    Node* tara;
    Node* n = new Node;
    n = new Node;
    int sayac = 1;
    tara = bas;
    if (y <= 0)
    {
        cout << "hatali kayit Numarasi\n";
        return;
    }

    while ((tara != NULL) && (sayac < y))
    {

        tara = tara->sonraki;
        sayac++;

    }

    tara->deger = x;



}



void Liste::bosalt()
{

    Node* tara2;
    Node* arka;
    int sayac = 1;
    tara2 = bas;


    while ((tara2 != NULL) && (sayac < kayitsayisi))
    {

        arka = tara2;
        tara2 = tara2->sonraki;
        arka->sonraki = tara2->sonraki;
        delete arka;
        sayac++;

    }





}

void Liste::basaekle(int a)
{
    Node* n = new Node();
    n = new Node();
    n->deger = a;
    if (bas == NULL)
    {
        bas = n;
        return;
    }
    else
    {
        n->sonraki = bas;
        bas = n;

    }
    kayitsayisi++;
}
void Liste::sonaekle(int a)
{
    Node* n = new Node();
    n = new Node();
    n->deger = a;
    if (bas == NULL)
    {
        bas = n;
        return;
    }
    Node* tara1;
    tara1 = bas;
    while (tara1->sonraki) {
        tara1 = tara1->sonraki;

    }
    tara1->sonraki = n;
    kayitsayisi++;
}

void Liste::ortayaekle(int a)
{
    Node* n = new Node();
    n = new Node();
    n->deger = a;


    if (bas == NULL)
    {
        bas = n;
        return;
    }
    int dugumsayisi = 0;
    Node* tara;
    tara = bas;
    while (tara) {
        dugumsayisi++;
        tara = tara->sonraki;

    }
    tara = bas;

    for (int i = 0; i < dugumsayisi / 2 - 1; i++)
    {
        tara = tara->sonraki;
    }

    n->sonraki = tara->sonraki;
    tara->sonraki = n;
    kayitsayisi++;
}


void ArrayList::olustur()
{
    int dizi[100];
    bas = &dizi[0];


}
void ArrayList::ekle(int a, int b)
{

    *(bas + a) = b;
    sayac++;
    cout << *(bas + a) << "\t";
}

void ArrayList::sil(int a)
{

    int b = 0;
    for (int i = a; i < sayac - 1;i++)
    {
        b = a + 1;
        *(bas + a) = *(bas + b);


    }

}
void ArrayList::yazdir()
{
    cout << endl;
    for (int i = 0; i < sayac; i++)
    {
        cout << *(bas + i) << "\t";
    }
    cout << endl;
}



