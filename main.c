#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tek yoÌˆnluÌˆ bagÌ†lÄ± liste duÌˆgÌ†uÌˆmuÌˆ
struct Node {
    char mesaj[256];
    struct Node* next;
};

// Yeni duÌˆgÌ†uÌˆm olusÌ§turma fonksiyonu
struct Node* yeniDugum(char* yazi) {
    struct Node* yeni = (struct Node*)malloc(sizeof(struct Node));
    if (!yeni) return NULL;

    strcpy(yeni->mesaj, yazi);
    yeni->next = NULL;
    return yeni;
}

// Liste sonuna eleman ekleme fonksiyonu
struct Node* sonaEkle(struct Node* head, char* yazi) {
    struct Node* yeni = yeniDugum(yazi);
    if (!yeni) return head;

    if (head == NULL)
        return yeni;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = yeni;
    return head;
}

// Syslog dosyasÄ±nÄ± okuma fonksiyonu
struct Node* syslogOku() {
    FILE* dosya = fopen("/var/log/syslog", "r");
    if (!dosya) return NULL;

    struct Node* head = NULL;
    char satir[256];

    while (fgets(satir, sizeof(satir), dosya)) {
        head = sonaEkle(head, satir);
    }

    fclose(dosya);
    return head;
}

// BagÌ†lÄ± listeyi yazdÄ±rma fonksiyonu
void listeYazdir(struct Node* head) {
    while (head) {
        printf("%s", head->mesaj);
        head = head->next;
    }
}

// Ana fonksiyon
int main() {
    struct Node* head = syslogOku();
    listeYazdir(head);
    return 0;
}