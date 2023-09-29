add_executable(print_info print_info.c)

add_library(mean_correct mean_correct.c mean.h)
add_library(mean_incorrect mean_incorrect.c mean.h)

add_library(print_int_correct print_int_correct.c print_int.h)
add_library(print_int_incorrect print_int_incorrect.c print_int.h)

add_library(read_int_correct read_int_correct.c read_int.h)
add_library(read_int_incorrect read_int_incorrect.c read_int.h)
