#include "SupabaseService.h"
#include "../../../env.h"

// Private helper function to execute a Supabase GET request
// SupabaseResponse SupabaseService::executeSupabaseGet(String endpoint) {
//   String url = String(getSupabaseProjectUrl()) + endpoint;
//   
//   http.begin(client, url, 443);
//   http.setTimeout(5000);
//   http.addHeader("apikey: " + String(getSupabaseAnonPublic()));
//   http.addHeader("Authorization: Bearer " + String(getSupabaseAnonPublic()));
//   http.addHeader("User-Agent: Arduino UNO R4 WiFi");
//   http.addHeader("Connection: close");

//   SupabaseResponse response;
//   response.statusCode = http.GET();
//   if (response.statusCode > 0) {
//     response.responseBody = http.getBody();
//   } else {
//     response.responseBody = "Supabase Request Failed!";
//   }

//   http.close();
//   return response;
// }

// Generic public GET method
SupabaseResponse SupabaseService::get(String tableName, String queryString) {
  String endpoint = "/rest/v1/" + tableName + (queryString.length() > 0 ? "?" + queryString : "");
  String url = String(getSupabaseProjectUrl()) + endpoint;
  
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

void SupabaseService::initializeSupabaseService() {
  // Example usage of the new generic get method
  // SupabaseResponse locations = get("trolly_locations", "select=*&is_active=eq.true");
  // Serial.println("Trolley Locations: ");
  // Serial.println(locations.responseBody);
  // Serial.println("Response code: " + String(locations.statusCode));

  // SupabaseResponse trolley = get("trollies", "select=*&limit=1");
  // Serial.println("Single Trolley: ");
  // Serial.println(trolley.responseBody);
  // Serial.println("Response code: " + String(trolley.statusCode));
  get("trolly_locations", "select=*&is_active=eq.true"); // Call to keep logic, but response won't be printed here
  get("trollies", "select=*&limit=1"); // Call to keep logic, but response won't be printed here
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