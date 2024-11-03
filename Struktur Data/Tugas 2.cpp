#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//========================================================
struct node {
    int data;
    struct node *next;
};
typedef struct node node;
//node *createNode(void);
void tambahAwal(node **head); //Menu 1
void tambahData(node **head); //Menu 2
void tranverse(node *head); //Menu 0
void tambahAkhir(node **head); //Menu 3
void hapusAwal(node **head); //Menu 4
void hapusTengah(node **head, int target); //Menu 5
void hapusAkhir(node **head); //Menu 6
void cariData(node *head, int target); //Menu 7
int hitungJumlahData(node *head); //Menu 8
int jumlahkanData(node *head); //Menu 9
void insertNode(node **head, node *pPre, node *pNew);
//========================================================
int main()
{
    node *head;
    char pilih;
    head = NULL;
    do{
        system("cls");
        printf("Masukkan pilihan\n");
        printf("1. Tambah data di awal\n");
        printf("2. Tambah data di tengah list\n");
        printf("3. Tambah data di akhir linked list\n");
        printf("4. Hapus data di awal linked list\n");
        printf("5. Hapus data di tengah linked list\n");
        printf("6. Hapus data di akhir linked list\n");
        printf("7. Pencarian data dalam linked list\n");
        printf("8. Menampilkan informasi jumlah data di linked list\n");         
        printf("9. Menampilkan hasil penjumlahan dari semua data di linked list\n");
        printf("0. Cetak isi list\n");
        printf("MASUKKAN PILIHAN (Tekan q untuk keluar) : ");
        fflush(stdin);
        scanf("%c", &pilih);
        if (pilih == '1')
            tambahAwal(&head);
        else if (pilih == '2')
            tambahData(&head);
        else if (pilih == '3')
            tambahAkhir(&head);
        else if (pilih == '4') {
            hapusAwal(&head);
            printf("\nSetelah penghapusan node pertama:\n");
            tranverse(head);
            getch();
        }
        else if (pilih == '5') {
            int target;
            system("cls");
            printf("Masukkan nilai yang akan dihapus: ");
            scanf("%d", &target);
            hapusTengah(&head, target);
            printf("\nSetelah penghapusan:\n");
            tranverse(head);
            getch();
        }
        else if (pilih == '6') {
            hapusAkhir(&head);
            printf("\nSetelah penghapusan node terakhir:\n");
            tranverse(head);
            getch();
        }
        else if (pilih == '7') {
            int target;
            printf("Masukkan data yang ingin dicari: ");
            scanf("%d", &target);
            cariData(head, target);
            getch();
        }
        else if (pilih == '8') {
            int jumlahData = hitungJumlahData(head);
            printf("Jumlah data dalam linked list: %d\n", jumlahData);
            getch();
        }
        else if (pilih == '9') {
            int total = jumlahkanData(head);
            printf("Hasil penjumlahan semua data dalam linked list: %d\n", total);
            getch();
        }
        else if (pilih == '0'){
            tranverse(head);
            getch();
        }
    } while (pilih != 'q');
    system("cls");
    return 0;
}
//========================================================
void tambahAwal(node **head){
    int bil;
    node *pNew, *pCur;
    system("cls");
    fflush(stdin);
    printf("Masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL){
        pNew->data = bil;
        pNew->next = *head;
        if (*head == NULL) {
            pNew->next = pNew; // circular link
        } else {
            pCur = *head;
            while (pCur->next != *head) {
                pCur = pCur->next;
            }
            pCur->next = pNew; // set the last node to point to new node
        }
        *head = pNew;
    }
    else{
        printf("Alokasi memori gagal");
        getch();
    }
}
//========================================================
void tambahData(node **head){
    int pos, bil;
    node *pNew, *pCur;
    system("cls");
    tranverse(*head);
    printf("\nPosisi penyisipan setelah data bernilai : ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nBilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pCur = *head;
    if (*head == NULL) {
        printf("List kosong, gunakan opsi 'Tambah Awal' terlebih dahulu.");
        return;
    }
    while (pCur->data != pos && pCur->next != *head) {
        pCur = pCur->next;
    }
    if (pCur->data != pos) {
        printf("Node tidak ditemukan\n");
        getch();
        return;
    }
    pNew = (node *)malloc(sizeof(node));
    if (pNew == NULL){
        printf("\nAlokasi memori gagal");
        getch();
        return;
    }
    pNew->data = bil;
    pNew->next = pCur->next;
    pCur->next = pNew;
}
//========================================================
void tranverse(node *head){
    if (head == NULL) {
        printf("List kosong.\n");
        return;
    }
    node *pWalker = head;
    system("cls");
    do {
        printf("%d -> ", pWalker->data);
        pWalker = pWalker->next;
    } while (pWalker != head);
    printf("(kembali ke head)\n");
}
//========================================================
void tambahAkhir(node **head) {
    int bil;
    node *pNew, *pCur;
    system("cls");
    fflush(stdin);
    printf("Masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = *head;
    } else {
        printf("Alokasi memori gagal");
        getch();
        return;
    }
    if (*head == NULL) {
        *head = pNew;
        pNew->next = pNew;
    } else {
        pCur = *head;
        while (pCur->next != *head) {
            pCur = pCur->next;
        }
        pCur->next = pNew;
    }
}
//========================================================
void hapusAwal(node **head) {
    if (*head == NULL) {
        printf("Linked list kosong, tidak ada yang bisa dihapus.\n");
        return;
    }
    node *pTemp = *head;
    node *pCur = *head;
    if ((*head)->next == *head) {
        *head = NULL;
    } else {
        while (pCur->next != *head) {
            pCur = pCur->next;
        }
        *head = (*head)->next;
        pCur->next = *head;
    }
    free(pTemp);
    printf("Node pertama berhasil dihapus.\n");
}
//========================================================
void hapusTengah(node **head, int target) {
    node *pCur, *pPrev;
    if (*head == NULL) {
        printf("Linked list kosong, tidak ada yang bisa dihapus.\n");
        return;
    }
    pCur = *head;
    if ((*head)->data == target) {
        hapusAwal(head);
        return;
    }
    do {
        pPrev = pCur;
        pCur = pCur->next;
    } while (pCur != *head && pCur->data != target);
    if (pCur == *head) {
        printf("Node dengan nilai %d tidak ditemukan.\n", target);
        return;
    }
    pPrev->next = pCur->next;
    free(pCur);
    printf("Node dengan nilai %d berhasil dihapus.\n", target);
}
//========================================================
void hapusAkhir(node **head) {
    if (*head == NULL) {
        printf("Linked list kosong, tidak ada yang bisa dihapus.\n");
        return;
    }
    node *pCur = *head;
    node *pPrev = NULL;
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        printf("Node terakhir berhasil dihapus, linked list sekarang kosong.\n");
        return;
    }
    while (pCur->next != *head) {
        pPrev = pCur;
        pCur = pCur->next;
    }
    pPrev->next = *head;
    free(pCur);
    printf("Node terakhir berhasil dihapus.\n");
}
//========================================================
void cariData(node *head, int target) {
    if (head == NULL) {
        printf("List kosong\n");
        return;
    }
    node *pCur = head;
    int posisi = 0;
    int ditemukan = 0;
    do {
        if (pCur->data == target) {
            printf("Data %d ditemukan di posisi ke-%d.\n", target, posisi);
            ditemukan = 1;
        }
        pCur = pCur->next;
        posisi++;
    } while (pCur != head);
    if (!ditemukan) {
        printf("Data %d tidak ditemukan di dalam linked list.\n", target);
    }
}
//========================================================
int hitungJumlahData(node *head) {
    if (head == NULL) return 0;
    int count = 0;
    node *pCur = head;
    do {
        count++;
        pCur = pCur->next;
    } while (pCur != head);
    return count;
}
//========================================================
int jumlahkanData(node *head) {
    if (head == NULL) return 0;
    int total = 0;
    node *pCur = head;
    do {
        total += pCur->data;
        pCur = pCur->next;
    } while (pCur != head);
    return total;
}
//========================================================