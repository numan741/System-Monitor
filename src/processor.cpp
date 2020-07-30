#include "processor.h"
#include "linux_parser.h"

#include <unistd.h> // for usleep
// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  long delta_active, delta_total;
  total_jiffies_start = LinuxParser::Jiffies();
  active_jiffies_start = LinuxParser::ActiveJiffies();
  // Wait 100ms
  usleep(100000); // in microseconds
  total_jiffies_end = LinuxParser::Jiffies();
  active_jiffies_end = LinuxParser::ActiveJiffies();
  
  delta_total = total_jiffies_end - total_jiffies_start;
  delta_active = active_jiffies_end - active_jiffies_start;
  
  return ((float)delta_active / (float)delta_total);
}