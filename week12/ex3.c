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
    int key_status[200];
    for (int i = 0; i < 200; i++) {
        key_status[i] = 0;
    }

    printf("P + E -> \"I passed the Exam!\"\n");
    printf("C + A + P -> \"Get some cappuccino!\"\n");
    printf("H + I -> \"Hello world!\"\n");

    while (fread(&input_ev, sizeof (struct input_event), 1, ff)) {
        if (input_ev.type == EV_KEY) {
            if (input_ev.value == 0) {
                key_status[input_ev.code] = 0;
            }
            else if (input_ev.value == 1) {
                key_status[input_ev.code] = 1;
                if(key_status[25] && key_status[18]) {
                    printf("I passed the Exam!\n");
                }
                else if(key_status[46] && key_status[30] && key_status[25]) {
                    printf("Get some cappuccino!\n");
                }
                else if(key_status[35] && key_status[23]) {
                    printf("Hello world!\n");
                }
            }
        }
    }
    fclose(ff);
    return 0;
}
