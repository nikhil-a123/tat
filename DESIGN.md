# Design rough notes

## User needs

### Measurement needs

- User needs to be able to evaluate CO2 concentration, temperature, humidity and pressure at the current time
- User needs to be notified whether the current CO2 concentration is considered healthy or not in an easy to understand way
- User needs to be able to track the changes in recent ambient conditions for at least the past week

### Device needs

- User should be able to place the device in many common spaces they will occupy such as a desk, bedstand or car
- User should not have to constantly interact with the device for it to operate
- User should be able to easily move the device around
- User should find the device's footprint unobtrusive

## Design inputs

- Device needs a clear and easy to understand on-device method for reading enviromental data
- Device needs a way to store enviromental data on-device and either display it immediately or export it to another device
- Device needs an easy way to interact with the device
- Device needs to have a small footprint
- Device must have all components internal to device i.e no wires
- Device needs to operate autonomously once it has been initially setup

## Design outputs

### Hardware design

- Device should be battery powered to remove reliance on external cables
- Device should be easily rechargable
- Device should use a low-power design to reduce user need to recharge the device
- Device should use a low-power on-device graphic display in order to display data
- Device should include hardware buttons to operate the device
- Device should be smaller than a phone so it can be placed easily around

### Measurement

- Device should be able to be calibrated to ensure measurement accuracy
- Device should know whether it is calibrated or not and prompt user to do so
- Device should include non-volatile memory to store measurements
- Device should be able to modify the measurement rate to switch between better battery life or more measurements
- Device should be able to export data wirelessly

# Enviromental data requirements

Enviromental data includes CO2, temperature, humidity and pressure.

### Calibration requirements
The CO2 sensor has relatively strict requirements in order to achieve optimum measurement accuracy. We can accomplish this by doing the following steps:
- At first power-on prompt the user to take the device outside
- Perform a forced recalibration following the instructions shown in STCC4 datasheet (chapter 3.4.15)
- Perform conditioning by following the instructions shown in STCC4 datasheet (chapter 3.4.9)

# Firmware tasks

- Implement main measurement screen to display the most recent enviromental data
- Implement startup calibration application to calibrate the CO2 sensor
- Implement settings system to store user options
- Implement history system to store recent previous data to enable previous battery life etc