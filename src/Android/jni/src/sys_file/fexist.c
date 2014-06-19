/*
 * sys_fexist.c
 *
 *  Created on: 2011-10-12
 *      Author: shizy
 */
#include "../../jni_include/sys_xfile.h"
#include "../../jni_include/jni_system.h"
#include "../../jni_include/sys_xfiledef.h"

unsigned char xsys_xfile_fExist(const char * pszFilename){
	JNIEnv * g_env;
	(*jvm)->AttachCurrentThread(jvm, &g_env, 0);
	jclass cls =(*g_env)->FindClass(g_env , "xc/api/XfileClass");

	jmethodID mid = (*g_env)->GetStaticMethodID(g_env, cls, "sys_fexist", "(Ljava/lang/String;)I");

	jstring name = 0;

	if(pszFilename){
		name = (*g_env)->NewStringUTF(g_env, pszFilename);
	}

	jint result = (*g_env)->CallStaticIntMethod(g_env, cls, mid, name);

	(*g_env)->DeleteLocalRef(g_env, cls);
	(*g_env)->DeleteLocalRef(g_env, name);

	return (unsigned char)result;
}
