# RTOS LCD template (STM32H750B-DK)

Mini template za **STM32H750B-DK** z uporabo **FreeRTOS-a** in LCD zaslona

## Kaj je vključeno

- inicializacija SDRAM-a in LCD zaslona,
- zagon FreeRTOS schedulerja,
- periodično izpisovanje `osTick`-a na zaslon (~ 1x / s),
- ločeno opravilo za utripanje zelene LED-ice (PD3) (~ 1x / 0.5s)

## Delovanja

https://github.com/mati5kova/stm32-rtos-bsp-lcd-template/preview.mp4

## Bodi pazljiv

- popravljen `RCC`: prehod na `HSE + PLL` in stabilen `SYSCLK`
- najprej `BSP_SDRAM_Init()`, nato `BSP_LCD_Init()` (čeprav BSP_LCD_Init znotraj kliče BSP_SDRAM_Init mi dela samo če dam sdram init prej), nastavitev layerja in šele potem izpis.
- pazi da je nastavljen font pred prvim izpisom drugače funkcije za text dereferencirajo null pointer
- pazi na task stack size lol.
- MPU region za SDRAM framebuffer (`0xD0000000`, full access, non-cacheable)
