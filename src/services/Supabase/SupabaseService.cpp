#include "SupabaseService.h"
#include "../../../env.h"

void SupabaseService::initializeSupabaseService() {
  printAllSupabaseCredentials();

  String path = "/rest/v1/" + String(SUPABASE_TABLE_NAME) + "?select=*&is_active=eq.true";
  String url = String(getSupabaseProjectUrl()) + path;
  Serial.println("Making GET request to: " + url);

  http.begin(client, url, 443);
  http.setTimeout(5000);
  http.addHeader("apikey: " + String(getSupabaseAnonPublic()));
  http.addHeader("Authorization: Bearer " + String(getSupabaseAnonPublic()));
  http.addHeader("User-Agent: Arduino UNO R4 WiFi");
  http.addHeader("Connection: close");

  int responseNum = http.GET();
  if (responseNum > 0) {
    String responseBody = http.getBody();
    Serial.println("Supabase Response: " + responseBody);
    Serial.println("Response code: " + String(responseNum));
  } else {
    Serial.println("Supabase Request Failed: " + String(responseNum));
  }

  http.close();
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
