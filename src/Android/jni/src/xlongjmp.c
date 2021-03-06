/*
 * @file xlongjmp.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../../xlongjmp.h"
#include <setjmp.h>

xint32_t xlongjmp_set(xjmp_buf_t env)
{
	return setjmp((long*)env->buf);
}

void xlongjmp_jump(xjmp_buf_t env, xint32_t val)
{
	longjmp((long*)env->buf, val);
}
