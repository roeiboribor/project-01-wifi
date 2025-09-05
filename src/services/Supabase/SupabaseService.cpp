#include "SupabaseService.h"
#include "../../../env.h"

void SupabaseService::initializeSupabaseService() {
  SupabaseResponse response = getActiveTrolleyLocations();
  Serial.println("Trolley Locations: ");
  Serial.println(response.responseBody);
  Serial.println("Response code: " + String(response.statusCode));
}

SupabaseResponse SupabaseService::getActiveTrolleyLocations() {
  String url = String(getSupabaseProjectUrl()) + "/rest/v1/trolly_locations?select=*&is_active=eq.true";
  Serial.println("Get Active Trolley Locations!");

  http.begin(client, url, 443);
  http.setTimeout(5000);
  http.addHeader("apikey: " + String(getSupabaseAnonPublic()));
  http.addHeader("Authorization: Bearer " + String(getSupabaseAnonPublic()));
  http.addHeader("User-Agent: Arduino UNO R4 WiFi");
  http.addHeader("Connection: close");

  SupabaseResponse response;
  response.statusCode = http.GET();
  if (response.statusCode > 0) {
    response.responseBody = http.getBody();
  } else {
    response.responseBody = "Supabase Request Failed!";
  }

  http.close();
  return response;
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