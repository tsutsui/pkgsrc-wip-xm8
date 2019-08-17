$NetBSD$

- add NetBSD denitions

--- Source/UI/platform.h.orig	2015-07-08 21:49:42.000000000 +0000
+++ Source/UI/platform.h
@@ -66,7 +66,7 @@ private:
 	int find_drive;
 										// find drive count
 #endif // _WIN32
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 	bool FindUp(const char *dir);
 										// find ..
 	void *dir_handle;
