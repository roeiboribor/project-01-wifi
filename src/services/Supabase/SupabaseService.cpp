#include "SupabaseService.h"
#include "../../../env.h"

void SupabaseService::initializeSupabaseService() {
  printAllSupabaseCredentials();
}

const char* SupabaseService::getSupabaseProjectUrl() {
  return SUPABASE_PROJECT_URL;
}

const char* SupabaseService::getSupabaseAnonPublic() {
  return SUPABASE_ANON_PUBLIC;
}

const char* SupabaseService::getSupabaseSecret() {
  return SUPABASE_SECRET;
}

void SupabaseService::printAllSupabaseCredentials() {
  Serial.println("SUPABASE_PROJECT_URL: " + String(getSupabaseProjectUrl()));
  Serial.println("SUPABASE_ANON_PUBLIC: " + String(getSupabaseAnonPublic()));
  Serial.println("SUPABASE_SECRET: " + String(getSupabaseSecret()));
}
