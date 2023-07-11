#include <glib.h>

int main() {

  g_log(NULL, G_LOG_LEVEL_MESSAGE, "This is message. Function: \"%s\", line: %d.", __FUNCTION__, __LINE__);
  g_log(NULL, G_LOG_LEVEL_WARNING, "This is warning message. Function: \"%s\", line: %d.", __FUNCTION__, __LINE__);
  g_log(NULL, G_LOG_LEVEL_CRITICAL, "This is critical message! Function: \"%s\", line: %d.", __FUNCTION__, __LINE__);

  g_message("This is a message. Function: \"%s\", line: %d.", __FUNCTION__, __LINE__);
  g_warning("This is a warning message. Function: \"%s\", line: %d.", __FUNCTION__, __LINE__);
  g_critical("This is a critical message. Function: \"%s\", line: %d.", __FUNCTION__, __LINE__);
  g_debug("This is a debug message. Function: \"%s\", line: %d.", __FUNCTION__, __LINE__);
  g_error("This is an error message. Function: \"%s\", line: %d.", __FUNCTION__, __LINE__);
  
  return 0;
}
