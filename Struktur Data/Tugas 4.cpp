#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct Stack {
    int arr[MAXSIZE];
    int top;
} Stack;
void inisialisasiStack(Stack *s) {
    s->top = -1;
}
int isEmpty(Stack *s) {
    return (s->top == -1);
}
int isFull(Stack *s) {
    return (s->top == MAXSIZE - 1);
}
void push(Stack *s, int elemen) {
    if (!isFull(s)) {
        s->arr[++s->top] = elemen;
        printf("%d berhasil ditambahkan ke stack\n", elemen);
    } else {
        printf("Stack Penuh\n");
    }
}
int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[s->top--];
    } else {
        printf("Stack Kosong\n");
        return -1;
    }
}
int top(Stack *s) {
    return isEmpty(s) ? -1 : s->arr[s->top];
}
int count(Stack *s) {
    return s->top + 1;
}
void destroy(Stack *s) {
    s->top = -1;
    printf("Stack berhasil dihancurkan\n");
}
int main() {
    Stack s;
    inisialisasiStack(&s);
    int pilihan, elemen;
    do {
        printf("\nMenu Operasi Stack\n");
        printf("1. Tambah Data (Push)\n");
        printf("2. Hapus Data (Pop)\n");
        printf("3. Lihat elemen teratas (Top)\n");
        printf("4. Hitung jumlah elemen (Count)\n");
        printf("5. Hancurkan stack (Destroy)\n");
        printf("6. Keluar\n");
        printf("Masukkan operasi yang diinginkan: ");
        scanf("%d", &pilihan);
        switch (pilihan) {
            case 1:
                printf("Masukkan elemen yang akan ditambahkan: ");
                scanf("%d", &elemen);
                push(&s, elemen);
                break;
            case 2:
                elemen = pop(&s);
                if (elemen != -1) {
                    printf("%d berhasil dihapus dari stack\n", elemen);
                }
                break;
            case 3:
                elemen = top(&s);
                if (elemen == -1) {
                    printf("Stack kosong\n");
                } else {
                    printf("Elemen teratas adalah %d\n", elemen);
                }
                break;
            case 4:
                printf("Jumlah elemen dalam stack: %d\n", count(&s));
                break;
            case 5:
                destroy(&s);
                break;
            
            case 6:
                printf("Keluar dari program\n");
                break;
            default:
                printf("Pilihan tidak valid, silahkan coba lagi\n");
        }
    } while (pilihan != 6);
    system ("cls");
    return 0;
}