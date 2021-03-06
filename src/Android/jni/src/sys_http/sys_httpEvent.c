/*
 * @file sys_httpEvent.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../jni_include/sys_xhttp.h"
#include "../../jni_include/jni_http.h"
#include "../../jni_include/jni_system.h"

void sys_httpEvent(void * pHttp, unsigned int dwEvent, unsigned int dwParam1, unsigned int dwParam2){
	SYS_Http * http = (SYS_Http*)pHttp;

	if (!http || !http->pfn){
		return;
	}

	(*(http->pfn))(http->pvUser, dwEvent, dwParam1, dwParam2);
}
