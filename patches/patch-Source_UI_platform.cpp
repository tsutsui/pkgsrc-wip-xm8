$NetBSD$

- add NetBSD denitions

--- Source/UI/platform.cpp.orig	2017-12-30 13:04:42.000000000 +0000
+++ Source/UI/platform.cpp
@@ -22,11 +22,11 @@
 #include "converter.h"
 #include "platform.h"
 
-#if defined(__linux__) && !defined(__ANDROID__)
+#if (defined(__linux__) && !defined(__ANDROID__)) || defined(__NetBSD__)
 #include <locale.h>
 #endif // __linux__ && !__ANDROID__
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 #include <dirent.h>
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -63,7 +63,7 @@ Platform::Platform(App *a)
 	ImmDisableIME((DWORD)-1);
 #endif // _WIN32
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 	dir_handle = NULL;
 	dir_name[0] = '\0';
 	dir_up = false;
@@ -144,7 +144,7 @@ bool Platform::Init(SDL_Window *window)
 	}
 #endif // _WIN32 && UNICODE
 
-#if defined(__linux__) && !defined(__ANDROID__)
+#if (defined(__linux__) && !defined(__ANDROID__)) || defined(__NetBSD__)
 	char *opaque;
 
 	// set locale to UTF-8
@@ -186,7 +186,7 @@ void Platform::Deinit()
 	}
 #endif // _WIN32
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 	if (dir_handle != NULL) {
 		closedir((DIR*)dir_handle);
 		dir_handle = NULL;
@@ -282,7 +282,7 @@ const char* Platform::FindFirst(const ch
 	return NULL;
 #endif // _WIN32 && UNICODE
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 	DIR *dir_ret;
 
 	// Find ..
@@ -384,7 +384,7 @@ const char* Platform::FindNext(Uint32 *i
 	return NULL;
 #endif // _WIN32 && UNICODE
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 	struct dirent *entry;
 	Converter *converter;
 
@@ -423,7 +423,7 @@ const char* Platform::FindNext(Uint32 *i
 #endif // __liunx__
 }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 //
 // FindUp()
 // find ..
@@ -487,7 +487,7 @@ bool Platform::IsDir(Uint32 info)
 	}
 #endif // _WIN32
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 	if (info == DT_DIR) {
 		return true;
 	}
@@ -557,7 +557,7 @@ bool Platform::MakePath(char *dir, const
 	return true;
 #endif // _WIN32 && UNICODE
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 	Converter *converter;
 	struct stat filestat;
 
@@ -637,7 +637,7 @@ bool Platform::GetFileDateTime(const cha
 	return false;
 #endif // _WIN32
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 	struct stat filestat;
 	time_t timep;
 	struct tm local_time;
@@ -696,7 +696,7 @@ void Platform::MsgBox(SDL_Window *window
 	}
 #endif // _WIN32
 
-#if defined(__linux__) && !defined(__ANDROID__)
+#if (defined(__linux__) && !defined(__ANDROID__)) || defined(__NetBSD__)
 	SDL_MessageBoxData data;
 	SDL_MessageBoxButtonData button;
 	int retid;
