//
// Created by Jiayu on 2024/12/24.
//

#ifndef TCOUNT_TCOUNT_H
#define TCOUNT_TCOUNT_H

#include <stdio.h>

/// count chines string from char*
/// \param str to be count
/// \param cn_count_p count number point
void count_cn(char *str,unsigned long long *cn_count_p);

/// count alpha from char *
/// \param str to be count
/// \param alpha_count_p count number point
void count_alpha(char *str,unsigned long long *alpha_count_p);

#endif //TCOUNT_TCOUNT_H
