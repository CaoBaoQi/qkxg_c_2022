void basic01_demo01();

void basic01_demo02();

void basic01_demo03();

void basic01_demo04();

void basic01_demo05();

void basic01_demo06();

void basic01_demo07();

#include "../common/cbq.h"

/**
 * @author caobaoqi
 * @name C 程序设计-01-基本数据类型与运算符
 * @date 2024/1/8 12:18
 */
int main() {
    basic01_demo01();
    basic01_demo02();

    basic01_demo05();
    basic01_demo06();
    basic01_demo07();

    basic01_demo03();
    basic01_demo04();
    return 0;
}

/**
 * 表达式运算后的值为表达式本身的值
 * eg: int a = (3 + (c = 2)) * 6 中 (c=2) ==> 2
 * result: a = (3 + 2) * 6 = 30
 */
void basic01_demo01() {
    printHeader("basic01_demo01");
    int c;
    int a = (3 + (c = 2)) * 6;
    printf("a = %d", a);
    printFooter("basic01_demo01");
}

/**
 * 逗号运算符从前往后依次执行，赋值结果是最后边的结果
 * eg: a = (b = 5, c = b + 8) 中 (b = 5, c = b + 8)  ==> c=13
 * result: a = 13
 */
void basic01_demo02() {
    printHeader("basic01_demo02");
    int b, c;
    int a = (b = 5, c = b + 8);
    printf("a = %d", a);
    printFooter("basic01_demo02");
}

/**
 * if-else if 适用于对 范围 判断
 */
void basic01_demo03() {
    printHeader("basic01_demo03");

    int score = 0;
    printf("Please Input Your Score: \n");
    scanf_s("%d", &score);
    if (score >= 90) {
        printf("Score is: %d Level is: Very Good", score);
    } else if (score >= 70) {
        printf("Score is: %d Level is: Good", score);
    } else if (score >= 60) {
        printf("Score is: %d Level is: just so so", score);
    } else {
        printf("Score is: %d Level is: bad", score);
    }
    printFooter("basic01_demo03");
}

/**
 * switch 适用于对 精确值 进行判断
 */
void basic01_demo04() {
    printHeader("basic01_demo04");

    char level = ' ';
    printf("Please Input Your Level (A|B|C): \n");
    /*
     ?* 当在 basic01_demo03 中使用 scanf_s 读取分数时，它读取了你输入的整数值
     ?* 但没有消耗按下回车键时生成的换行符（\n）这个换行符留在了输入缓冲区中然后当
     ?* 执行到 basic01_demo04 并调用 scanf_s 来读取一个字符时，它立即读取了缓冲区中剩下的这个换行符
     ?* 而不是等待新的输入。这就是为什么看起来像是跳过了输入
     !* 为了解决这个问题，可以在 basic01_demo04 的 scanf_s格 式字符串中的 %c 前面加一个空格
     !* 这个空格告诉scanf_s跳过可能存在的任何空白字符（包括换行符）即 scanf_s(" %c", &level)
     */
    scanf_s(" %c", &level);
    switch (level) {
        case 'A':
            printf("Level is: %c GO to 985 ", level);
            break;
        case 'B':
            printf("Level is:  %c GO to 211 ", level);
            break;
        case 'C':
            printf("Level is:  %c GO to One ", level);
            break;
        default:
            printf("Level is:  %c GO to Two ", level);
            break;
    }

    printFooter("basic01_demo04");
}

/**
 ?* 水仙花数（Narcissistic number）也被称为超完全数字不变数（pluperfect digital invariant, PPDI）
 ?* 自恋数、自幂数、阿姆斯壮数或阿姆斯特朗数（Armstrong number）
 ?* 水仙花数是指 一个 3 位数，它的每个位上的数字的 3 次幂之和等于它本身
 * <p>
 ** 现在请你设计一个 C 语言程序，打印出所有 1000 以内的水仙花数。
 !* eg: 1^3 + 5^3+ 3^3 = 153
 */
void basic01_demo05() {
    printHeader("basic01_demo05");
    int num = 1000;
    int first = 0, second = 0, third = 0;

    while (num != -1) {
        third = num / 100;
        second = num / 10 % 10;
        first = num % 10;
        if (num == ((first * first * first) + (second * second * second) + (third * third * third))) {
            printf("num = %d is PPDI\n", num);
        }
        num--;
    }

    printFooter("basic01_demo05");
}

/**
 * 九九乘法表
 */
void basic01_demo06() {
    printHeader("basic01_demo06");

    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= i; ++j) {
            printf("%d x %d = %d \t", j, i, i * j);
        }
        printf("\n");
    }

    printFooter("basic01_demo06");
}

/**
 * 斐波那契数列
 * @param index index
 * @return  result
 */
int fibonacciSequence(int index){
    int result;
    if(index > 2){
        result = fibonacciSequence(index - 1) + fibonacciSequence(index - 2);
        return result;
    } else{
        result = 1;
        return result;
    }
}

/**
 ?* 斐波那契数列（Fibonacci sequence）又称黄金分割数列因数学家莱昂纳多·斐波那契（Leonardo Fibonacci）
 ?* 以兔子繁殖为例子而引入故又称为 “兔子数列”，指的是这样一个数列：1、1、2、3、5、8、13、21、34、……
 ?* 在数学上，斐波那契数列以如下被以递推的方法定义：
 !* F(0)=0，F(1)=1
 !* F(n)=F(n - 1) + F(n - 2)（n ≥ 2，n ∈ N）
 ?* 在现代物理、准晶体结构、化学等领域，斐波纳契数列都有直接的应用，为此，美国数学会从 1963 年起出版了以《斐波纳契数列季刊》为名的一份数学杂志
 ?* 用于专门刊载这方面的研究成果
 ** 斐波那契数列：1，1，2，3，5，8，13，21，34，55，89...，不难发现一个规律，实际上从第三个数开始，每个数字的值都是前两个数字的和，
 * <p>
 !* 现在请你设计一个 C 语言程序，可以获取斐波那契数列上任意一位的数字，比如获取第 5 个数，那么就是 5
 */
void basic01_demo07() {
    printHeader("basic01_demo07");

    int index;
    printf("Please Input Your index: \n");
    scanf_s("%d", &index);

    printf("index = %d | result = %d ", index, fibonacciSequence(index));

    printFooter("basic01_demo07");
}

