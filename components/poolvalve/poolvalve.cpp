#include "poolvalve.h"
#include "esphome/core/log.h"

namespace esphome
{
  namespace poolvalve
  {

    void PoolValve::change_direction(bool direction)
    {
      // Change the valve direction logic here

      current_direction_ = direction;
      if (direction_sensor_ != nullptr)
      {
        direction_sensor_->publish_state(current_direction_ ? "Direction 1" : "Direction 2");
      }
    }

    void PoolValve::on_direction_change_complete()
    {
      ESP_LOGD(TAG, "Valve direction change complete.");
      // Additional actions once the direction change is completed
    }

  } // namespace poolvalve
} // namespace esphome
