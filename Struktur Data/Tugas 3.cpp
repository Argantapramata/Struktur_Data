#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//========================================================
struct node {
	int data;
    struct node *next;
    struct node *prev;
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
void tranverseMundur(node *head);
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
     printf("3. Tambah data di akhir linkked list\n");
     printf("4. Hapus data di awal linked list\n");
     printf("5. Hapus data di tengah linked list\n");
     printf("6. Hapus data di akhir linked list\n");
     printf("7. Pencarian data dalam linked list\n");
     printf("8. Menampilkan informasi jumlah data di linked list\n");         
     printf("9. Menampilkan hasil penjumlahan dari semua data di linked list\n");
     printf("a. Cetak isi list mundur\n");
     printf("0. Cetak isi list maju\n");
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
     else if (pilih == 'a') {
            tranverseMundur(head);
            getch();
        }
  } while (pilih != 'q');
  system("cls");
  return 0;
}
//========================================================
/*node *createNode(void){
  node *ptr;
  ptr = (node *)malloc(sizeof(node));
  return(ptr);
}*/
//========================================================
void tambahAwal(node **head){
    int bil;
    node *pNew;
    system("cls");
    fflush(stdin);
    printf("Masukkan bilangan : ");
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL){
        pNew->data = bil;
        pNew->next = *head;
        pNew->prev = NULL;
        if (*head != NULL) {
            (*head)->prev = pNew;
        }
        *head = pNew;
    } else {
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
  while (pCur != NULL && pCur -> data != pos) {
    pCur = pCur -> next;
  }
  pNew = (node *)malloc(sizeof(node));
  if (pCur == NULL){
     printf("\nNode tidak ditemukan");
     getch();
  }
  else if (pNew == NULL){
     printf("\nAlokasi memori gagal");
     getch();
  }
  else{
     pNew->data = bil;
     pNew->next = NULL;
     pNew -> next = pCur -> next;
     pCur -> next = pNew;
  }
}
//========================================================
void tranverse(node *head) {
    node *pWalker = head;
    system("cls");
    if (pWalker == NULL) {
        printf("List kosong\n");
        return;
    }
    printf("NULL <-> ");
    while (pWalker != NULL) {
        printf("%d <-> ", pWalker->data);
        pWalker = pWalker->next;
    }
    printf("NULL\n");
}
//========================================================
void tambahAkhir(node **head) {
    int bil;
    node *pNew, *pCur;
    system("cls");
    fflush(stdin);
    printf("Masukkan bilangan : ");
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = NULL;
    } else {
        printf("Alokasi memori gagal");
        getch();
        return;
    }
    if (*head == NULL) {
        pNew->prev = NULL;
        *head = pNew;
    } else {
        pCur = *head;
        while (pCur->next != NULL) {
            pCur = pCur->next;
        }
        pCur->next = pNew;
        pNew->prev = pCur;
    }
}
//========================================================
void hapusAwal(node **head) {
    if (*head == NULL) {
        printf("Linked list kosong, tidak ada yang bisa dihapus.\n");
        return;
    }
    node *pTemp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(pTemp);
    printf("Node pertama berhasil dihapus.\n");
}
//========================================================
void hapusTengah(node **head, int target) { //Menu 5
    node *pCur, *pPrev;
    if (*head == NULL) {
        printf("Linked list kosong, tidak ada yang bisa dihapus.\n");
        return;
    }
    if ((*head)->data == target) {
        pCur = *head;
        *head = (*head)->next;
        free(pCur);
        printf("Node dengan nilai %d berhasil dihapus.\n", target);
        return;
    }
    pCur = *head;
    while (pCur != NULL && pCur->data != target) {
        pPrev = pCur;
        pCur = pCur->next;
    }
    if (pCur == NULL) {
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
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Node terakhir berhasil dihapus, linked list sekarang kosong.\n");
        return;
    }
    node *pCur = *head;
    while (pCur->next != NULL) {
        pCur = pCur->next;
    }
    pCur->prev->next = NULL;
    free(pCur);
    printf("Node terakhir berhasil dihapus.\n");
}
//========================================================
void cariData(node *head, int target) { //Menu 7
    node *pCur = head;
    int posisi = 0;
    int ditemukan = 0;
    while (pCur != NULL) {
        if (pCur->data == target) {
            printf("Data %d ditemukan di posisi ke-%d.\n", target, posisi);
            ditemukan = 1;
        }
        pCur = pCur->next;
        posisi++;
    }
    if (!ditemukan) {
        printf("Data %d tidak ditemukan di dalam linked list.\n", target);
    }
}
//========================================================
int hitungJumlahData(node *head) { //Menu 8
    int count = 0;
    node *pCur = head;
    while (pCur != NULL) {
        count++;
        pCur = pCur->next;
    }
    return count;
}
//========================================================
int jumlahkanData(node *head) { //Menu 9
    int total = 0;
    node *pCur = head;
    while (pCur != NULL) {
        total += pCur->data;
        pCur = pCur->next;
    }
    return total;
}
//========================================================
void insertNode(node **head, node *pPre, node *pNew){
    if (pPre == NULL){
       //add before first logical node or to an empty list
	    pNew -> next = *head;
       *head = pNew;
    }
    else {
       //add in the middle or at the end
       pNew -> next = pPre -> next;
       pPre -> next = pNew;
   }
}
//========================================================
void tranverseMundur(node *head) {
    node *pWalker = head;
    system("cls");
    if (pWalker == NULL) {
        printf("List kosong\n");
        return;
    }
    while (pWalker->next != NULL) {
        pWalker = pWalker->next;
    }
    printf("NULL <-> ");
    while (pWalker != NULL) {
        printf("%d <-> ", pWalker->data); // Hanya menampilkan data
        pWalker = pWalker->prev;
    }
    printf("NULL\n");
}
//========================================================