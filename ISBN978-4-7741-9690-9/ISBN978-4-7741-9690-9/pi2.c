#include<stdio.h>
#include<math.h>

int main()
{
    int i;
    double a, b, s, t, last;

    // 初期値の設定
    a = 1;                  // 初期値a
    b = 1 / sqrt(2.0);      // 初期値b
    s = 1;                  // 初期値s
    t = 4;                  // 初期値t

    // メインループ: 3回の反復計算を行う
    for (i = 0; i < 3; i++) {
        last = a;                           // 前回のaを保存
        a = (a + b) / 2;                    // aの更新: aとbの平均
        b = sqrt(last * b);                 // bの更新: 前回のaとbの積の平方根
        s -= t * (a - last) * (a - last);   // sの更新: (a - last)^2にtを掛けてsから減算
        t *= 2;                             // tの更新: tを2倍にする

        // 計算結果を出力: (a + b)^2 / s
        printf("%16.14f\n", (a + b) * (a + b) / s);
    }
}