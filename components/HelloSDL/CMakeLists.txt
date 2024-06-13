idf_component_register(
    SRCS  "file.c"
        "hello.c"
        # "keyboard.c"
        "palette.c"
        "pcxload.c"
        "video.c"
        "video_scale.c"
    INCLUDE_DIRS "."
    REQUIRES "SDL"
)
