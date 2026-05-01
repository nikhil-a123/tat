#ifndef TAT_CO2_SENSOR_H_
#define TAT_CO2_SENSOR_H_

int tat_co2_sensor_init(void);
int tat_co2_sensor_get_co2_ppm(uint32_t *co2_ppm);
int tat_co2_sensor_get_temperature(float *temperature);
int tat_co2_sensor_get_humidity(float *humidity);

#endif /* TAT_CO2_SENSOR_H_ */