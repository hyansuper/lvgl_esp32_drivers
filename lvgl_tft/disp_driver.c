/**
 * @file disp_driver.c
 */

#include "disp_driver.h"
#include "disp_spi.h"
#include "esp_lcd_backlight.h"
#include "sdkconfig.h"

void *disp_driver_init(void)
{
#if defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ILI9341
    ili9341_init();
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ILI9481
    ili9481_init();
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ILI9488
    ili9488_init();
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ST7789
    st7789_init();
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ST7796S
    st7796s_init();
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ST7735S
    st7735s_init();
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_HX8357
    hx8357_init();
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ILI9486
    ili9486_init();
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_SH1107
    sh1107_init();
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_SSD1306
    ssd1306_init();
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_FT81X
    FT81x_init();
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_IL3820
    il3820_init();
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_RA8875
    ra8875_init();
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_GC9A01
   GC9A01_init();
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_JD79653A
   jd79653a_init();
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_UC8151D
   uc8151d_init();
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ILI9163C
    ili9163c_init();
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_PCD8544
    pcd8544_init();
#endif

    // We still use menuconfig for these settings
    // It will be set up during runtime in the future
#if (defined(CONFIG_LV_DISP_BACKLIGHT_SWITCH) || defined(CONFIG_LV_DISP_BACKLIGHT_PWM))
    const disp_backlight_config_t bckl_config = {
        .gpio_num = CONFIG_LV_DISP_PIN_BCKL,
#if defined CONFIG_LV_DISP_BACKLIGHT_PWM
        .pwm_control = true,
#else
        .pwm_control = false,
#endif
#if defined CONFIG_LV_BACKLIGHT_ACTIVE_LVL
        .output_invert = false, // Backlight on high
#else
        .output_invert = true, // Backlight on low
#endif
        .timer_idx = CONFIG_LV_DISP_BACKLIGHT_PWM_TIMER,
        .channel_idx = CONFIG_LV_DISP_BACKLIGHT_PWM_CH
    };
    disp_backlight_h bckl_handle = disp_backlight_new(&bckl_config);
#if defined(CONFIG_LV_DISP_BACKLIGHT_PWM)
    disp_backlight_set(bckl_handle, CONFIG_LV_DISP_BACKLIGHT_PWM_DEFAULT_PCT);
#else
    disp_backlight_set(bckl_handle, 100);
#endif
    return bckl_handle;
#else
    return NULL;
#endif
}


