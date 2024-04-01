#include "esphome/core/component.h"
#include "esphome/components/output/binary_output.h"
#include "esphome/components/sensor/sensor.h"

namespace esphome {
namespace pool_valve {

class PoolValve : public Component {
 public:
  void setup() override;
  void loop() override;
  void dump_config() override;
  
  void set_valve_direction_1(output::BinaryOutput *valve_direction_1);
  void set_valve_direction_2(output::BinaryOutput *valve_direction_2);
  void set_change_time(uint32_t change_time);
  void change_direction(bool direction);
  void set_direction_sensor(sensor::Sensor *direction_sensor) { direction_sensor_ = direction_sensor; }
  
 protected:
  output::BinaryOutput *valve_direction_1_;
  output::BinaryOutput *valve_direction_2_;
  sensor::Sensor *direction_sensor_;
  uint32_t change_time_;
  bool current_direction_ = true;

  void on_direction_change_complete();
};

}  // namespace pool_valve
}  // namespace esphome
