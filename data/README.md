

# HA/File /homeassistant/configuration.yaml

- edit ip 
for mosquitto broker in main.cpp (TODO: config)

- 

```

mqtt:
  light:
    name: "mqtt-wled/05-diskostar"
    command_topic: "wled/05-diskostar"
    brightness_command_topic: "wled/05-diskostar"
    brightness_scale: 255
    payload_on: "ON"
    payload_off: "OFF"
    on_command_type: "brightness"

```

# for AUTOMATIONS:

to auto close 
- Create a Timer
Define a timer in your configuration.yaml or via the Home Assistant UI:


```
timer:
  diskostar_timer:
    duration: "00:00:00"



```