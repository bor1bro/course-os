#include <winsock2.h>
#include <ws2tcpip.h>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#ifndef INDLL_H
#define INDLL_H
#ifdef EXPORTING_DLL
extern __declspec(dllexport) void runServer();
#else
extern __declspec(dllimport) void runServer();
#endif
#endif