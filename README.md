# syslog.isleme
 Linux işletim sisteminde sistem günlüklerini (syslog) anlamak ve bu verileri işlemek için bağlı liste (linked list) veri yapısını kullanarak bir uygulama tasarlamaktır.
# Syslog Günlüklerini Bağlı Liste ile Yönetme

## Proje Açıklaması
Bu proje, Linux işletim sistemlerinde **syslog günlüklerini** okuyarak bir **tek yönlü bağlı liste (singly linked list)** veri yapısında saklamayı amaçlamaktadır. Program, **/var/log/syslog** dosyasını okuyarak her satırı bir bağlı liste düğümü olarak ekler ve ardından logları ekrana yazdırır.

## Syslog Mekanizması Nedir? Ne İçin Kullanılır?
**Syslog**, Linux ve Unix tabanlı sistemlerde **sistem olaylarını, hata mesajlarını ve uygulama kayıtlarını** merkezi bir dosyada saklayan bir günlükleme mekanizmasıdır. Örneğin:
- **Kullanıcı giriş-çıkış işlemleri**
- **Sistem servisleri ve hataları**
- **Güvenlik olayları**

Syslog kayıtları genellikle **/var/log/syslog** veya **/var/log/messages** gibi dosyalarda saklanır.

## Bağlı Liste ile Günlüklerin Saklanması
Bağlı liste, **dinamik bellek yönetimi sağlayan, sıralı veri saklamaya uygun bir veri yapısıdır**. Syslog kayıtları birer **düğüm (node)** olarak saklanır ve her düğüm bir sonraki düğümü gösterir.

### Kullanılan Bağlı Liste Türü
Projede **tek yönlü bağlı liste** (singly linked list) kullanılmıştır. Her düğüm:
- **Bir syslog satırını içerir.**
- **Bir sonraki log kaydına işaret eder.**

### Neden Tek Yönlü Bağlı Liste Kullanıldı?
- **Syslog kayıtları sürekli eklenen verilerdir.** Tek yönlü bağlı liste, **yeni log ekleme işlemlerini verimli hale getirir**.
- **Bellek kullanımı optimizasyonu**: Çift yönlü bağlı listeye kıyasla **daha az bellek tüketir**.
- **Ters erişim ihtiyacı yoktur**: Syslog kayıtları genellikle baştan sona okunur, geriye doğru erişim gerekmez.

## Kullanım
### Derleme ve Çalıştırma
Kodu derlemek için terminalde şu komutları çalıştırın:
```bash
gcc -o syslog_reader syslog_reader.c
./syslog_reader
```
### Örnek Çıktı
Eğer **/var/log/syslog** içinde aşağıdaki kayıtlar varsa:
```
Feb 22 10:15:30 mypc systemd[1]: Started Session 1 of user root.
Feb 22 10:16:02 mypc sudo: user : TTY=pts/0 ; PWD=/home/user ; USER=root ; COMMAND=/bin/ls
Feb 22 10:16:10 mypc systemd[1]: Stopped User Manager for UID 1000.
```
Program şu çıktıyı verir:
```
Tüm loglar:
Feb 22 10:15:30 mypc systemd[1]: Started Session 1 of user root.
Feb 22 10:16:02 mypc sudo: user : TTY=pts/0 ; PWD=/home/user ; USER=root ; COMMAND=/bin/ls
Feb 22 10:16:10 mypc systemd[1]: Stopped User Manager for UID 1000.
```

## Geliştirme Fikirleri
- **Anahtar kelime ile log arama** eklenebilir.
- **Logları tarih sırasına göre sıralama** yapılabilir.
- **Windows uyumluluğu** için `syslogOku()` fonksiyonu adapte edilebilir.

Bu proje, **syslog günlüklerini bağlı liste ile yönetmek ve analiz etmek** için temel bir yapıdır. Geliştirmeye açıktır!
