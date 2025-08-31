#include "SupabaseService.h"
#include "../../../env.h"

void initializeSupabaseService() {
  // Serial.begin(115200);
  Serial.println("SUPABASE_PROJECT_URL: " + String(SUPABASE_PROJECT_URL));
  Serial.println("SUPABASE_ANON_PUBLIC: " + String(SUPABASE_ANON_PUBLIC));
  Serial.println("SUPABASE_SECRET: " + String(SUPABASE_SECRET));
}
