#include "esp_log.h"

namespace {
constexpr char kTag[] = "postcard";
}  // namespace

extern "C" void app_main(void) {
  ESP_LOGI(kTag, "postcard firmware skeleton up");
}
