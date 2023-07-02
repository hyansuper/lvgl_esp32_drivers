/**
 * @file disp_driver.h
 */

#ifndef DISP_DRIVER_H
#define DISP_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#if defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ILI9341
#include "ili9341.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ILI9481
#include "ili9481.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ILI9488
#include "ili9488.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ST7789
#include "st7789.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ST7796S
#include "st7796s.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ST7735S
#include "st7735s.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_HX8357
#include "hx8357.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ILI9486
#include "ili9486.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_SH1107
#include "sh1107.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_SSD1306
#include "ssd1306.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_FT81X
#include "FT81x.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_IL3820
#include "il3820.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_RA8875
#include "ra8875.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_GC9A01
#include "GC9A01.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_JD79653A
#include "jd79653a.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_UC8151D
#include "uc8151d.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ILI9163C
#include "ili9163c.h"
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_PCD8544
#include "pcd8544.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/* Initialize display */
void *disp_driver_init(void);


/**********************
 *      MACROS
 **********************/
#if defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ILI9341
    #define disp_driver_flush ili9341_flush
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ILI9481
    #define disp_driver_flush ili9481_flush
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ILI9488
    #define disp_driver_flush ili9488_flush
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ST7789
    #define disp_driver_flush st7789_flush
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ST7796S
    #define disp_driver_flush st7796s_flush
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ST7735S
    #define disp_driver_flush st7735s_flush
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_HX8357
    #define disp_driver_flush hx8357_flush
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ILI9486
    #define disp_driver_flush ili9486_flush
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_SH1107
    #define disp_driver_flush sh1107_flush
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_SSD1306
    #define disp_driver_flush ssd1306_flush
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_FT81X
    #define disp_driver_flush FT81x_flush
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_IL3820
    #define disp_driver_flush il3820_flush
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_RA8875
    #define disp_driver_flush ra8875_flush
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_GC9A01
    #define disp_driver_flush GC9A01_flush
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_JD79653A
    #define disp_driver_flush jd79653a_lv_fb_flush
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_UC8151D
    #define disp_driver_flush uc8151d_lv_fb_flush
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_ILI9163C
    #define disp_driver_flush ili9163c_flush
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_PCD8544
    #define disp_driver_flush pcd8544_flush
#endif


#if defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_SSD1306
    #define disp_driver_rounder ssd1306_rounder
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_SH1107
    #define disp_driver_rounder sh1107_rounder
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_IL3820
    #define disp_driver_rounder il3820_rounder
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_JD79653A
    #define disp_driver_rounder jd79653a_lv_rounder_cb
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_UC8151D
    #define disp_driver_rounder uc8151d_lv_rounder_cb
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_PCD8544
    #define disp_driver_rounder pcd8544_rounder
#endif


#if defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_SSD1306
    #define disp_driver_set_px ssd1306_set_px_cb
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_SH1107
    #define disp_driver_set_px sh1107_set_px_cb
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_IL3820
    #define disp_driver_set_px il3820_set_px_cb
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_JD79653A
    #define disp_driver_set_px jd79653a_lv_set_fb_cb
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_UC8151D
    #define disp_driver_set_px uc8151d_lv_set_fb_cb
#elif defined CONFIG_LV_TFT_DISPLAY_CONTROLLER_PCD8544
   #define disp_driver_set_px pcd8544_set_px_cb
#endif



#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*DISP_DRIVER_H*/