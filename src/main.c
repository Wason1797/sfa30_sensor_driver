#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>
#include "sensor/sfa30/sfa30.h"

#if !DT_HAS_COMPAT_STATUS_OKAY(sensirion_sfa30)
#error "No sensirion,sfa30 compatible node found in the device tree"
#endif

const struct device *sfa30 = DEVICE_DT_GET_ANY(sensirion_sfa30);

int main(void)
{
        if (!device_is_ready(sfa30))
        {
                printk("Device not ready\n");
                return 1;
        }

        struct sensor_value temp, hum, hco;

        while (true)
        {
                sensor_sample_fetch(sfa30);
                sensor_channel_get(sfa30, SENSOR_CHAN_AMBIENT_TEMP, &temp);
                sensor_channel_get(sfa30, SENSOR_CHAN_HUMIDITY, &hum);
                sensor_channel_get(sfa30, SENSOR_CHAN_HCO, &hco);
                printk("temp from sensor %f\n", sensor_value_to_float(&temp));
                printk("hum from sensor %f\n", sensor_value_to_float(&hum));
                printk("hco from sensor %f\n", sensor_value_to_float(&hco));
                k_sleep(K_MSEC(6000));
        }


        return 0;
}
