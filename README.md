# Log Kayıt Sistemi
Bu program, basit bir log kayıt sistemi uygulamasıdır. Bağlı liste veri yapısı kullanarak log kayıtlarını saklar ve görüntüler.
## Özellikler
Dinamik bellek yönetimi ile sınırsız log kaydı ekleme

Bağlı liste yapısı ile esnek depolama

Kronolojik sırada log görüntüleme

Her kayıt için 100 karaktere kadar mesaj desteği
## Teknik Detaylar
### Kullanılan Kütüphaneler
stdio.h: Giriş/çıkış işlemleri için

stdlib.h: Dinamik bellek yönetimi için

string.h: String işlemleri için
## Ana Fonksiyonlar
### void kayitEkle(struct LogKayit** bas, char* mesaj)
Yeni log kaydı ekler
#### Parametreler:
bas: Liste başlangıç işaretçisinin adresi

mesaj: Eklenecek log mesajı

### void kayitlariGoster(struct LogKayit* bas)
Tüm kayıtları numaralı şekilde görüntüler
#### Parametre:
bas: Liste başlangıç işaretçisi 
## Sınırlamalar
Her log mesajı maksimum 100 karakter uzunluğunda olabilir
Program sonlandığında kayıtlar kalıcı olarak saklanmaz
Kayıt silme fonksiyonu bulunmamaktadır
## Geliştirme Önerileri

Kayıtları dosyaya kaydetme özelliği

Kayıt silme fonksiyonu

Tarih ve saat bilgisi ekleme

Kayıt arama fonksiyonu

Bellek sızıntılarını önlemek için kayıtları temizleme fonksiyonu

## Lisans
Bu program eğitim amaçlı olarak geliştirilmiştir ve açık kaynak kodludur.
