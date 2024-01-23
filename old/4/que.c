#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 必要なもの

// キューの配列
// キューの最大収納数
#define MAX 5
int g_que[MAX];
int head;
int tail;

//初期化
void initialize(void)
{
    head = tail = 0;
}

// 空か判定する
// headがtailを追い越しそうになったら(並ぶのまではOK)
int is_empty(void)
{
    return (head == tail);
}

// 一杯か判定する
// 追加するとき、tailがheadに並びそうになったら
int is_full(void)
{
    return (head == (tail + 1) % MAX);
}

// キューの追加
void enque(int x)
{
    if (is_full()) {
        printf("stack over flow\n");
        return ;
    }
    g_que[tail] = x;
    if (tail + 1 == MAX)
        tail = 0;
    else
        ++tail;
}

void print_que(void)
{
    int h = head;
    int t = tail;
    while (h != t) {
        printf("%d ", g_que[h]);
        if (h + 1 == MAX)
            h = 0;
        else
            ++h;
    }
}

// キューの削除
int deque(void)
{
    if (is_empty()) {
        printf("stack under flow\n");
        return -1;
    }
    int x = g_que[head];
    if (head + 1 == MAX)
        head = 0;
    else {
        ++head;
    }
    return x;
}

int main(void)
{
    initialize();
    const int limit = 5;
    srand(time(0)); 
    for (int i = 0; i < limit; i++) {
        enque(rand() % 10);
    }
    print_que();
    printf("\n");
    for (int i = 0; i < limit; i++) {
        deque();
    }
}

