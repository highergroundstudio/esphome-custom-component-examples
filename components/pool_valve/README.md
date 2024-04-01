# Custom Pool Valve Component for ESPHome

This custom component for ESPHome enables control over a pool valve with two selectable directions, incorporating the time it takes for the valve to switch directions. It also provides a sensor in Home Assistant to display the current direction of the valve, enhancing usability and integration for manual control and automation purposes.

## Features

- **Two-Way Control**: Manage the direction of your pool valve with two configurable GPIO pins.
- **Adjustable Change Time**: Customize the time it takes for the valve to change directions, ensuring precise control.
- **Direction Feedback**: A sensor reports the current direction of the valve, improving visibility and control within Home Assistant.

## Installation

1. Copy the custom component files (`__init__.py`, `pool_valve.h`, and `pool_valve.cpp`) into your ESPHome configuration directory, under `custom_components/pool_valve/`.
2. Ensure the `output` and `sensor` components are configured in your ESPHome setup, as this custom component relies on them.

## Configuration

### Basic Configuration

Add the following to your ESPHome configuration file, adjusting GPIO pins and IDs as necessary:

```yaml
output:
  - platform: gpio
    pin: GPIO12
    id: valve_direction_1
  - platform: gpio
    pin: GPIO14
    id: valve_direction_2

sensor:
  - platform: template
    name: "Pool Valve Direction"
    id: pool_valve_direction
    icon: mdi:swap-horizontal
    lambda: |-
      return id(my_pool_valve).get_current_direction() ? "Direction 1" : "Direction 2";
    update_interval: 5s

pool_valve:
  id: my_pool_valve
  valve_direction_1: valve_direction_1
  valve_direction_2: valve_direction_2
  change_time: 60s
  direction_sensor: pool_valve_direction
```

### Parameters

- `valve_direction_1`: Output component controlling the first direction.
- `valve_direction_2`: Output component controlling the second direction.
- `change_time`: Duration it takes for the valve to switch directions. Default is `60s`.
- `direction_sensor`: Sensor component that will display the current valve direction in Home Assistant.

## Usage

Control the pool valve directly from ESPHome or through Home Assistant automations and scripts. The direction sensor will update in Home Assistant, providing clear visibility of the valve's current state.

### Example: Automating Valve Direction Change

Here’s an example Home Assistant script to change the pool valve direction and monitor its status:

```yaml
script:
  change_pool_valve_direction:
    sequence:
      - service: esphome.my_pool_valve_change_direction
        data:
          direction: true  # Change to `false` to switch to the opposite direction
```

Replace `my_pool_valve_change_direction` with the appropriate service name based on your ESPHome device's name.

## Troubleshooting

- **Valve Not Changing Direction**: Verify the GPIO pins are correctly defined and wired.
- **Incorrect Change Time**: Adjust the `change_time` parameter to match the actual time it takes for your valve to switch directions.
- **Direction Sensor Not Updating**: Check the sensor configuration and ensure it is correctly linked to the pool valve component.

For further assistance, refer to the ESPHome documentation or seek support from the ESPHome community.
```

This README.md provides a detailed guide for installing, configuring, and using the custom Pool Valve component with direction feedback in ESPHome. Adjustments or further details might be required based on the specifics of your setup and hardware.
