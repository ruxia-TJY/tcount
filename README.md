# TCount

C语言检测中文字符数量



## 如何使用
下载相应头文件
```c
#include "tcount.h"
#include <stdio.h>

int main(int argc,char *argv[])
{
    char *str = "你好China";
    unsigned long long count = 0;
    count_cn(str,&count);
    printf("%d",count);
    
    return 0;
}
```
程序将会输出
```c
2
```



## 支持编码

+ [x] ASCII

+ [x] GB 2312

+ [x] GBK

+ [x] GB 18030

+ [ ] UTF-8

  ...



## 数据来源

+ 国家标准全文公开系统

