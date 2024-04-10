# Data Definition

## MQTT protocolo

MQTT protocol is used as its light weight and can support multiple IOT devices comunucation at the same time. This protocolo allow us to send up to **256MiB** wich is enough for our expected usage.


## Topics

Below is the description of the topics to be used by the V2X first implementation of intelligent traffic lights

**/vehicle/data/{Id}**: Topic dedicated for vehile data, the model [v_data](#vehicle-information-v_data) is used to send the information. The {Id} place holder represents the id of the vehicle the data respresents.

**/trafficLigh/data/{Id}**: Topic dedicated for traffic light data, the model [tl_data](#traffic-light-information-tl_data) is used to send the information. The {Id} place holder represents the id of the traffic light the data respresents.

**trafficLigh/change/{Id}**: Topic dedicated to send the desired change for a defined traffic light, the {Id} place represent the id if the traffic light wich state should be changed. The model [tl_change](#traffic-light-change-tl_change) is used to send the information.

Unfortunately ThingSpeak doestn allow us to change the topics, thus the follow equivalences will be used for the first phase.

| Topic | ThingSpeak | Notes |
| -- | -- | -- |
| /vehicle/data/{Id} | TBD | - |
| /trafficLigh/data/{Id} | TBD | - |
| /trafficLigh/change/{Id} | TBD | - |


## Vehicle information (v_data)

Message send by the vehicle each 20 second to the topic **/vehicle/data/{Id}**

### Details 
| Name | Type | Size | Detail |
| ---- | ---- | ---- | ------ |
| Id | int | - | Id of the vehicle |
| Position | float array | 2 | Latitud and lingitud of the vechile |
| Speed | int | - | Current speed of the vehicle in K/h |
| Heading | int | - | Current heading in degrees of the vehicle |
| Next_Turn? | Object | 2 | Distance in meters and heading of the next turn |

> NOTES: Check if it will be posible to get the next turn information, also the amount of posible options for the turn.
> 
> Is there streen names? relative headings or absolute headings?
>
> Define frecuency of message for vechicles

### Example

```json
{
    "Id": 1,
    "Position": [48.738534, 9.311124],
    "Speed": 60,
    "Heading": 90,
    "Next_Turn":? {
        "Distance": 100,
        "Heading": 180
    }
}
```

## Traffic light information (tl_data)

Message by the traffic light on initial connection and each time its state changes, the topic to be used for this message is **/trafficLigh/data/{id}**

### Details 
| Name | Type | Size | Detail |
| ---- | ---- | ---- | ------ |
| Id | int | - | Id of the trafic light |
| Position | float array | 2 | Latitud and longitud of the trafic light position |
| Current_State | int | - | Current state of the traffic light |
| States? | array | n | List of states the traffic light can have |
| States? | object array | n | Detal of states the traffic light can be into |
| Headings? | object array | n | List of headings the traffic light can redirect |
 
 >NOTES: TBD How are states going to be handled?


### Example
```json
{
    "Id": 1,
    "Position": [48.738534, 9.311124],
    "Current_State": 4,
    "States":? [1, 2, 3, 4],
    "States":? [
        {
            "Id": 1,
            "Headings": [[10, 40], [30, 20], [110 180], [110 180]]
        }
    ],
    "Headings":? [
        {
            "from": 0,
            "to": 90
        },
        {
            "from": 270,
            "to": 270
        }
    ]
}
```

## Traffic light change (tl_change)

Message send by matlab each time a change is required by a traffic light, send to the topic **trafficLigh/change/{id}**

### Details 
| Name | Type | Size | Detail |
| ---- | ---- | ---- | ------ |
| Id | int | - | Id of the traffic light |
| New_State? | int | - |  New desired state for the traffic light |
| Headings? | array | 2 | Heading to allow traffic

> NOTES: How are states being handled?

### Example
```json
{
    "Id": 1,
    "New_State":? 2,
    "Headings":? [0, 90]
}
```

## Concerns

- ThingSpeak api only allow us to send one message each 15 seconds
- Free tier of ThingSpeak api only allow 80,000 messaged per day
