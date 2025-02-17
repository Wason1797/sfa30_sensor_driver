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
        return 0;
}
