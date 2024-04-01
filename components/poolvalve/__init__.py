from esphome.components import sensor
from esphome.const import CONF_ID, ICON_ARROW_RIGHT_BOLD, UNIT_EMPTY

CONF_DIRECTION_SENSOR = 'direction_sensor'
CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(PoolValve),
    cv.Required(CONF_VALVE_DIRECTION_1): cv.use_id(output.BinaryOutput),
    cv.Required(CONF_VALVE_DIRECTION_2): cv.use_id(output.BinaryOutput),
    cv.Optional(CONF_CHANGE_TIME, default='60s'): cv.positive_time_period_milliseconds,
    cv.Optional(CONF_DIRECTION_SENSOR): cv.use_id(sensor.Sensor),
}).extend(cv.COMPONENT_SCHEMA)

def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)
    yield output.register_output(var.set_valve_direction_1(config[CONF_VALVE_DIRECTION_1]))
    yield output.register_output(var.set_valve_direction_2(config[CONF_VALVE_DIRECTION_2]))
    cg.add(var.set_change_time(config[CONF_CHANGE_TIME]))
    if CONF_DIRECTION_SENSOR in config:
        sens = yield cg.get_variable(config[CONF_DIRECTION_SENSOR])
        cg.add(var.set_direction_sensor(sens))
