#ifndef SUPABASE_SERVICE_H
#define SUPABASE_SERVICE_H

#include <Arduino.h>

#include <R4HttpClient.h>
#include <WiFiS3.h>
class SupabaseService {
public:
  void initializeSupabaseService();
  const char* getSupabaseProjectUrl();
  const char* getSupabaseAnonPublic();
  const char* getSupabaseSecret();
  void printAllSupabaseCredentials();

private:
  WiFiSSLClient client;
  R4HttpClient http;
};

#endif
