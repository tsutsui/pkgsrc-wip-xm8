$NetBSD$

- add NetBSD denitions

--- Source/UI/os.h.orig	2015-06-07 13:33:50.000000000 +0000
+++ Source/UI/os.h
@@ -38,6 +38,16 @@
 #endif // __linux__ && !__ANDROID__
 
 //
+// NetBSD
+//
+#if  defined(__NetBSD__)
+#include <SDL.h>
+#include <stdio.h>
+#include <string.h>
+#include <time.h>
+#endif // __NetBSD__
+
+//
 // Android
 //
 #ifdef __ANDROID__
