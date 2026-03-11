#include "display.h"
#include "main.h"
#include "stm32_lcd.h"
#include "stm32h750b_discovery_lcd.h"
#include "stm32h750b_discovery_sdram.h"

void display_init(void)
{
    if (BSP_SDRAM_Init(0) != BSP_ERROR_NONE) { Error_Handler(); }

    if (BSP_LCD_Init(0, LCD_ORIENTATION_LANDSCAPE) != BSP_ERROR_NONE) { Error_Handler(); }

    if (BSP_LCD_SetLayerVisible(0, 0, ENABLE) != BSP_ERROR_NONE) { Error_Handler(); }

    if (BSP_LCD_SetTransparency(0, 0, 255) != BSP_ERROR_NONE) { Error_Handler(); }


    if (BSP_LCD_SetActiveLayer(0, 0) != BSP_ERROR_NONE) { Error_Handler(); }

    UTIL_LCD_SetFuncDriver(&LCD_Driver);

    if (BSP_LCD_DisplayOn(0) != BSP_ERROR_NONE) { Error_Handler(); }
}
