#include <stdio.h>   // Giriþ/çýkýþ iþlemleri için gerekli kütüphane
#include <stdlib.h>  // malloc gibi bellek iþlemleri için gerekli kütüphane
#include <string.h>  // strcpy gibi string iþlemleri için gerekli kütüphane

// Baðlý liste için düðüm yapýsý tanýmlanýyor
struct LogKayit {
    char mesaj[100];           // Her kayýt için 100 karakterlik mesaj alaný
    struct LogKayit* sonraki;  // Sonraki düðümün adresini tutacak pointer
};

// Yeni kayýt ekleme fonksiyonu
void kayitEkle(struct LogKayit** bas, char* mesaj) {
    // Yeni kayýt için bellekten yer ayrýlýyor
    // sizeof ile LogKayit yapýsý kadar yer isteniyor
    struct LogKayit* yeni = (struct LogKayit*)malloc(sizeof(struct LogKayit));
    
    // Parametre olarak gelen mesaj, yeni kaydýn mesaj alanýna kopyalanýyor
    strcpy(yeni->mesaj, mesaj);
    
    // Yeni kaydýn sonraki iþaretçisi NULL yapýlýyor (son düðüm olacak)
    yeni->sonraki = NULL;
    
    // Eðer liste boþsa (baþ düðüm NULL ise)
    if (*bas == NULL) {
        *bas = yeni;           // Yeni düðüm listenin baþý olur
        return;                // Fonksiyondan çýk
    }
    
    // Liste boþ deðilse son düðümü bul
    struct LogKayit* temp = *bas;  // Geçici pointer ile liste üzerinde ilerle
    
    // Son düðüme ulaþana kadar ilerle
    while (temp->sonraki != NULL) {
        temp = temp->sonraki;      // Bir sonraki düðüme geç
    }
    
    // Son düðümün sonraki iþaretçisine yeni düðümü baðla
    temp->sonraki = yeni;
}

// Tüm kayýtlarý ekrana yazdýrma fonksiyonu
void kayitlariGoster(struct LogKayit* bas) {
    int sayac = 1;  // Kayýtlarý numaralandýrmak için sayaç
    
    printf("\n=== Log Kayitlari ===\n");
    
    // Liste sonuna kadar ilerle
    while (bas != NULL) {
        // Sýra numarasý ve mesajý yazdýr
        printf("%d. %s\n", sayac++, bas->mesaj);
        
        // Bir sonraki düðüme geç
        bas = bas->sonraki;
    }
}

// Ana program
int main() {
    // Liste baþlangýç iþaretçisi NULL olarak tanýmlanýyor
    struct LogKayit* liste = NULL;
    
    // Örnek kayýtlar ekleniyor
    kayitEkle(&liste, "Sistem acildi");          // Ýlk kayýt
    kayitEkle(&liste, "Kullanici giris yapti");  // Ýkinci kayýt
    kayitEkle(&liste, "Program baslatildi");     // Üçüncü kayýt
    
    // Tüm kayýtlarý ekrana yazdýr
    kayitlariGoster(liste);
    
    return 0;  // Programý sonlandýr
}
