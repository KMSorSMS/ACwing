/*
将全部输入装进同一个字符串数组中
一趟扫描，动态标记当前字符的状态 state
状态一：位于某个字符串或某个字符常量内
状态二：位于某个单行注释段内
状态三：位于某个多行注释段内
默认状态：普通代码段
不同状态的字符输出
对于字符串或字符常量：全部输出
对于注释：注释结束时输出一个空格
对于普通字符：全部输出
*/
#include <stdio.h>
#include <string.h>
const int N = 1e5 + 5;

#define NORMAL 0
#define STR 1
#define SINGLE_ANNO 2
#define MULTI_ANNO 3

char s[N], str;
int state = NORMAL;
int main()
{
    while (fgets(s + strlen(s), N, stdin))
        ; // fgets 函数会保留输入数据中的 ‘\n’ 字符
    for (int i = 0; s[i]; i++)
        switch (state)
        {
        case STR:
            printf("%c", s[i]);
            if (s[i] == '\\')
                printf("%c", s[++i]);
            else if (s[i] == str) // str 为单引号或双引号
                state = NORMAL;
            break;
        case SINGLE_ANNO:
            if (s[i] == '\\' && s[i + 1] == '\n')
                i++;
            else if (s[i] == '\n') // 注意输出 ‘\n’ 字符
                printf(" \n"), state = NORMAL;
            break;
        case MULTI_ANNO:
            if (s[i] == '*' && s[i + 1] == '/')
                i++, printf(" "), state = NORMAL;
            break;
        default:
            if (s[i] == '\"' || s[i] == '\'') // 二者处理方式相同
                printf("%c", s[i]), str = s[i], state = STR;
            else if (s[i] == '/' && s[i + 1] == '/')
                i++, state = SINGLE_ANNO;
            else if (s[i] == '/' && s[i + 1] == '*')
                i++, state = MULTI_ANNO;
            else
                printf("%c", s[i]);
            break;
        }
}