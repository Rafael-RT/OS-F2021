#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <linux/input.h>
#include <stdlib.h>

int main() {
    const char *file = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    struct input_event input_ev;
    FILE *ff = fopen(file, "r");
    if (ff == NULL) {
        printf("Error to open the file\n");
        return 0;
    }
    while (fread(&input_ev, sizeof (struct input_event), 1, ff)) {
        if (input_ev.type == EV_KEY) {
            if (input_ev.value == 1) {
                    printf("%s 0x%04x (%d) \n", "PRESSED", input_ev.code, input_ev.code); // PRESSED
            }
            else if (input_ev.value == 0) {
                printf("%s 0x%04x (%d) \n", "RELEASED", input_ev.code, input_ev.code); // RELEASED
            }
        }
    }
    fclose(ff);
    return 0;
}
