void basic01_demo01();

void basic01_demo02();

#include "../common/cbq.h"

/**
 * @author caobaoqi
 * @name C 程序设计-01-基本数据类型与运算符
 * @date 2024/1/8 12:18
 */
int main() {
    basic01_demo01();
    basic01_demo02();
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