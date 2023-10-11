#include <stdio.h>

int main() {
    int values[] = {0, 1, 2, 3, 4, 5, 6};
    int i;

    // Calculate the maximum number of significant bits in the array
    int max_bits = 0;
    for (i = 0; i < 7; i++) {
        int temp = values[i];
        int bits = 0;
        while (temp > 0) {
            bits++;
            temp >>= 1;
        }
        if (bits > max_bits) {
            max_bits = bits;
        }
    }

    for (int bit_position = 0; bit_position < max_bits; bit_position++) {
        printf("Bit position %d:\n", bit_position);
        
        for (i = 0; i < 7; i++) {
            int current_value = values[i];
            
            // Check the bit at the given position
            int bit = (current_value >> bit_position) & 1;

            printf("Bit %d is %d in %d\n", bit_position, bit, current_value);
            // Perform your task based on the bit value
        }
    }
    return 0;
}