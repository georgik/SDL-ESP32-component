idf_component_register(
    SRCS "SDL_system.c" "SDL_video.c" "SDL_input.c" "spi_lcd.c" "SDL_event.c" "SDL_audio.c"
    INCLUDE_DIRS "."
    REQUIRES driver fatfs esp_timer esp_adc esp_lcd littlefs
)
