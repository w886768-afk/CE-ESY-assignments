#include <stdio.h>
#include <string.h>

// تعريف حجم المخزن
#define SIZE 15 

// تعريف هيكل المخزن الدائري [cite: 48, 49, 50, 51, 52]
typedef struct {
    char buffer[SIZE];
    int head;
    int tail;
    int count;
} CircularBuffer;

// دالة تهيئة المخزن [cite: 54, 55, 56, 57]
void init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

// دالة التحقق من الامتلاء [cite: 59]
int isFull(CircularBuffer *cb) {
    return cb->count == SIZE;
}

// دالة التحقق من الفراغ [cite: 61]
int isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
}

// دالة الكتابة في المخزن مع التعامل مع حالة الامتلاء [cite: 15, 64, 65, 66]
void write(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("\nBuffer Overflow!\n");
        return;
    }
    cb->buffer[cb->tail] = data;
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count++;
}

// دالة القراءة من المخزن مع التعامل مع حالة الفراغ [cite: 16, 69, 70, 71]
char read(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("\nBuffer Underflow!\n");
        return '\0';
    }
    char data = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % SIZE;
    cb->count--;
    return data;
}

// الدالة الرئيسية [cite: 76]
int main() {
    CircularBuffer cb;
    init(&cb);

    char name[100];
    char suffix[] = "CE-ESY"; // اللاحقة المطلوبة [cite: 20, 83]

    // إدخال الاسم [cite: 80]
    printf("Enter your name: ");
    scanf("%s", name);

    // دمج الاسم مع اللاحقة [cite: 83]
    strcat(name, suffix);

    // كتابة كل حرف في المخزن [cite: 85, 86]
    for (int i = 0; i < strlen(name); i++) {
        write(&cb, name[i]);
    }

    // القراءة من المخزن والعرض [cite: 88, 90, 91]
    printf("Output from buffer: ");
    while (!isEmpty(&cb)) {
        printf("%c", read(&cb));
    }
    printf("\n");

    return 0;
}