//
// Created by Jiayu on 2024/12/24.
//

#include "tcount.h"

/// count chines string from char*
/// \param str to be count
/// \param cn_count_p count number point
void count_cn(char *str, unsigned long long *cn_count_p)
{
    unsigned long long cur_idx = 0, cn = 0;
    unsigned long long *p_cn = cn_count_p;

    do {
        // 双字节四字节的第一字节范围
        if(str[cur_idx] >= 0xFFFFFF81 && str[cur_idx] <= 0xFFFFFFFE){
            // 如果第二字节在如下范围，说明是四字节
            if(str[cur_idx + 1] >= 0xFFFFFF30 && str[cur_idx + 1] <= 0xFFFFFF39){
                cur_idx+=4;
            }else{
                // 如果是双字节
                // 根据GB 18030标准中的汉字码位表判断是否属于汉字
                if(str[cur_idx] >= 0xFFFFFFB0 && str[cur_idx] <= 0xFFFFFFF7){
                    if(str[cur_idx + 1] >= 0xFFFFFFA1 && str[cur_idx + 1] <= 0xFFFFFFFE)
                    {
                        cn++;
                    }
                }
                else if(str[cur_idx] >= 0xFFFFFF81 && str[cur_idx] <= 0xFFFFFFA0){
                    if(str[cur_idx + 1] >= 0xFFFFFF40 && str[cur_idx + 1] <= 0xFFFFFF7E)
                    {
                        cn++;
                    }
                    else if(str[cur_idx + 1] >= 0xFFFFFF80 && str[cur_idx + 1] <= 0xFFFFFFFE)
                    {
                        cn++;
                    }
                }
                else if(str[cur_idx] >= 0xFFFFFFAA && str[cur_idx] <= 0xFFFFFFFE){
                    if(str[cur_idx + 1] >= 0xFFFFFF40 && str[cur_idx + 1] <= 0xFFFFFF7E)
                    {
                        cn++;
                    }
                    else if(str[cur_idx + 1] >= 0xFFFFFF80 && str[cur_idx + 1] <= 0xFFFFFFA0)
                    {
                        cn++;
                    }
                }
                cur_idx += 2;
            }
        }
        // 单字节区的第一字节
        else if(str[cur_idx] >= 0x00 && str[cur_idx] <= 0x7F){
            cur_idx += 1;
        }
    } while (str[cur_idx] != '\0');

    *p_cn = cn;
}

/// count alpha from char *
/// \param str to be count
/// \param alpha_count_p count number point
void count_alpha(char *str,unsigned long long *alpha_count_p)
{
    unsigned long long cur_idx = 0, alpha = 0;
    unsigned long long *p_alpha = alpha_count_p;

    do {
        if(str[cur_idx] >= 'a' && str[cur_idx] <= 'z'){
            alpha++;
        } else if(str[cur_idx] >= 'A' && str[cur_idx] <= 'Z'){
            alpha++;
        }
        cur_idx++;
    } while (str[cur_idx] != '\0');
    *p_alpha = alpha;
}