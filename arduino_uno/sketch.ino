{
  "version": 1,
  "author": "No_Idea - Metropolia Robotics",
  "editor": "wokwi",
  "parts": [
    {
      "type": "wokwi-arduino-uno",
      "id": "uno",
      "top": -20,
      "left": -260,
      "attrs": {}
    },
    {
      "type": "wokwi-led",
      "id": "flF",
      "top": -220,
      "left": 140,
      "attrs": {
        "color": "green",
        "label": "FL FWD"
      }
    },
    {
      "type": "wokwi-resistor",
      "id": "res_flF",
      "top": -165,
      "left": 141,
      "rotate": 90,
      "attrs": {
        "value": "220"
      }
    },
    {
      "type": "wokwi-led",
      "id": "flR",
      "top": -220,
      "left": 230,
      "attrs": {
        "color": "red",
        "label": "FL REV"
      }
    },
    {
      "type": "wokwi-resistor",
      "id": "res_flR",
      "top": -165,
      "left": 231,
      "rotate": 90,
      "attrs": {
        "value": "220"
      }
    },
    {
      "type": "wokwi-led",
      "id": "frF",
      "top": -80,
      "left": 140,
      "attrs": {
        "color": "green",
        "label": "FR FWD"
      }
    },
    {
      "type": "wokwi-resistor",
      "id": "res_frF",
      "top": -25,
      "left": 141,
      "rotate": 90,
      "attrs": {
        "value": "220"
      }
    },
    {
      "type": "wokwi-led",
      "id": "frR",
      "top": -80,
      "left": 230,
      "attrs": {
        "color": "red",
        "label": "FR REV"
      }
    },
    {
      "type": "wokwi-resistor",
      "id": "res_frR",
      "top": -25,
      "left": 231,
      "rotate": 90,
      "attrs": {
        "value": "220"
      }
    },
    {
      "type": "wokwi-led",
      "id": "rlF",
      "top": 60,
      "left": 140,
      "attrs": {
        "color": "green",
        "label": "RL FWD"
      }
    },
    {
      "type": "wokwi-resistor",
      "id": "res_rlF",
      "top": 115,
      "left": 141,
      "rotate": 90,
      "attrs": {
        "value": "220"
      }
    },
    {
      "type": "wokwi-led",
      "id": "rlR",
      "top": 60,
      "left": 230,
      "attrs": {
        "color": "red",
        "label": "RL REV"
      }
    },
    {
      "type": "wokwi-resistor",
      "id": "res_rlR",
      "top": 115,
      "left": 231,
      "rotate": 90,
      "attrs": {
        "value": "220"
      }
    },
    {
      "type": "wokwi-led",
      "id": "rrF",
      "top": 200,
      "left": 140,
      "attrs": {
        "color": "green",
        "label": "RR FWD"
      }
    },
    {
      "type": "wokwi-resistor",
      "id": "res_rrF",
      "top": 255,
      "left": 141,
      "rotate": 90,
      "attrs": {
        "value": "220"
      }
    },
    {
      "type": "wokwi-led",
      "id": "rrR",
      "top": 200,
      "left": 230,
      "attrs": {
        "color": "red",
        "label": "RR REV"
      }
    },
    {
      "type": "wokwi-resistor",
      "id": "res_rrR",
      "top": 255,
      "left": 231,
      "rotate": 90,
      "attrs": {
        "value": "220"
      }
    }
  ],
  "connections": [
    [
      "uno:2",
      "res_flF:1",
      "green",
      []
    ],
    [
      "res_flF:2",
      "flF:A",
      "green",
      []
    ],
    [
      "flF:C",
      "uno:GND.1",
      "black",
      []
    ],
    [
      "uno:3",
      "res_flR:1",
      "red",
      []
    ],
    [
      "res_flR:2",
      "flR:A",
      "red",
      []
    ],
    [
      "flR:C",
      "uno:GND.1",
      "black",
      []
    ],
    [
      "uno:4",
      "res_frF:1",
      "green",
      []
    ],
    [
      "res_frF:2",
      "frF:A",
      "green",
      []
    ],
    [
      "frF:C",
      "uno:GND.1",
      "black",
      []
    ],
    [
      "uno:5",
      "res_frR:1",
      "red",
      []
    ],
    [
      "res_frR:2",
      "frR:A",
      "red",
      []
    ],
    [
      "frR:C",
      "uno:GND.1",
      "black",
      []
    ],
    [
      "uno:6",
      "res_rlF:1",
      "green",
      []
    ],
    [
      "res_rlF:2",
      "rlF:A",
      "green",
      []
    ],
    [
      "rlF:C",
      "uno:GND.1",
      "black",
      []
    ],
    [
      "uno:7",
      "res_rlR:1",
      "red",
      []
    ],
    [
      "res_rlR:2",
      "rlR:A",
      "red",
      []
    ],
    [
      "rlR:C",
      "uno:GND.1",
      "black",
      []
    ],
    [
      "uno:8",
      "res_rrF:1",
      "green",
      []
    ],
    [
      "res_rrF:2",
      "rrF:A",
      "green",
      []
    ],
    [
      "rrF:C",
      "uno:GND.1",
      "black",
      []
    ],
    [
      "uno:9",
      "res_rrR:1",
      "red",
      []
    ],
    [
      "res_rrR:2",
      "rrR:A",
      "red",
      []
    ],
    [
      "rrR:C",
      "uno:GND.1",
      "black",
      []
    ]
  ],
  "dependencies": {}
}
