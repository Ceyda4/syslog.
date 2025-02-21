#include <stdio.h>   // Giri�/��k�� i�lemleri i�in gerekli k�t�phane
#include <stdlib.h>  // malloc gibi bellek i�lemleri i�in gerekli k�t�phane
#include <string.h>  // strcpy gibi string i�lemleri i�in gerekli k�t�phane

// Ba�l� liste i�in d���m yap�s� tan�mlan�yor
struct LogKayit {
    char mesaj[100];           // Her kay�t i�in 100 karakterlik mesaj alan�
    struct LogKayit* sonraki;  // Sonraki d���m�n adresini tutacak pointer
};

// Yeni kay�t ekleme fonksiyonu
void kayitEkle(struct LogKayit** bas, char* mesaj) {
    // Yeni kay�t i�in bellekten yer ayr�l�yor
    // sizeof ile LogKayit yap�s� kadar yer isteniyor
    struct LogKayit* yeni = (struct LogKayit*)malloc(sizeof(struct LogKayit));
    
    // Parametre olarak gelen mesaj, yeni kayd�n mesaj alan�na kopyalan�yor
    strcpy(yeni->mesaj, mesaj);
    
    // Yeni kayd�n sonraki i�aret�isi NULL yap�l�yor (son d���m olacak)
    yeni->sonraki = NULL;
    
    // E�er liste bo�sa (ba� d���m NULL ise)
    if (*bas == NULL) {
        *bas = yeni;           // Yeni d���m listenin ba�� olur
        return;                // Fonksiyondan ��k
    }
    
    // Liste bo� de�ilse son d���m� bul
    struct LogKayit* temp = *bas;  // Ge�ici pointer ile liste �zerinde ilerle
    
    // Son d���me ula�ana kadar ilerle
    while (temp->sonraki != NULL) {
        temp = temp->sonraki;      // Bir sonraki d���me ge�
    }
    
    // Son d���m�n sonraki i�aret�isine yeni d���m� ba�la
    temp->sonraki = yeni;
}

// T�m kay�tlar� ekrana yazd�rma fonksiyonu
void kayitlariGoster(struct LogKayit* bas) {
    int sayac = 1;  // Kay�tlar� numaraland�rmak i�in saya�
    
    printf("\n=== Log Kayitlari ===\n");
    
    // Liste sonuna kadar ilerle
    while (bas != NULL) {
        // S�ra numaras� ve mesaj� yazd�r
        printf("%d. %s\n", sayac++, bas->mesaj);
        
        // Bir sonraki d���me ge�
        bas = bas->sonraki;
    }
}

// Ana program
int main() {
    // Liste ba�lang�� i�aret�isi NULL olarak tan�mlan�yor
    struct LogKayit* liste = NULL;
    
    // �rnek kay�tlar ekleniyor
    kayitEkle(&liste, "Sistem acildi");          // �lk kay�t
    kayitEkle(&liste, "Kullanici giris yapti");  // �kinci kay�t
    kayitEkle(&liste, "Program baslatildi");     // ���nc� kay�t
    
    // T�m kay�tlar� ekrana yazd�r
    kayitlariGoster(liste);
    
    return 0;  // Program� sonland�r
}
