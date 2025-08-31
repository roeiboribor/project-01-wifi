#ifndef SUPABASE_SERVICE_H
#define SUPABASE_SERVICE_H

#include <Arduino.h>

void initializeSupabaseService();
const char* getSupabaseProjectUrl();
const char* getSupabaseAnonPublic();
const char* getSupabaseSecret();
void printAllSupabaseCredentials();

#endif
