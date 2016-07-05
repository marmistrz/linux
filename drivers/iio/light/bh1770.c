/*
 * This file is part of the ROHM BH1770GLC / OSRAM SFH7770 sensor driver.
 * Chip is combined proximity and ambient light sensor.
 *
 * Copyright (C) 2016 Marcin Mielniczuk
 */

 #include <linux/i2c.h>
 #include <linux/module.h>

static int bh1770_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
    return 0;
}

static int bh1770_remove(struct i2c_client *client)
{
    return 0;
}

static const struct i2c_device_id bh1770_id[] = {
	{ "bh1770", 0 },
	{ }
};

#ifdef CONFIG_OF
static const struct of_device_id of_bh1770_match[] = {
	{ .compatible = "rohm,bh1770glc", },
	{},
};
MODULE_DEVICE_TABLE(of, of_bh1770_match);
#endif

static struct i2c_driver bh1770_driver = {
	.probe		= bh1770_probe,
	.remove		= bh1770_remove,
	.id_table	= bh1770_id,
	.driver = {
		.name = "bh1770",
		.of_match_table = of_match_ptr(of_bh1770_match),
	},
};

module_i2c_driver(bh1770_driver);

MODULE_DESCRIPTION("ROHM BH1770GLC Ambient Light Sensor Driver");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Marcin Mielniczuk <marmistrz@openmailbox.org>");
