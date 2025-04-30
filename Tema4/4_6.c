#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

const char* unitNames[] = {"gram", "metru", "litru"};
const double multiplierFactors[] = {
    1e-12, 1e-9, 1e-6, 1e-3, 1e-2, 1e-1, 1, 10, 100, 1000, 1000000, 1000000000
};
const char* multiplierNames[] = {
    "pico", "nano", "micro", "mili", "centi", "deci", "", "deca", "hecto", "kilo", "mega", "giga"
};

// inseram masuratorile in 16 biti (uint16_t)
uint16_t encode_measurement(unsigned int value, const char* unit_str) {
    int unit_code = -1;
    for (int i = 0; i < 3; ++i) {
        if (strcmp(unit_str, unitNames[i]) == 0) { //cautam codul pentru marimea de baza
            unit_code = i; 
            break;
        }
    }
    if (unit_code == -1) {
        printf("Eroare: Unitate necunoscută.\n");
        return 0xFFFF;
    }

    // Căutăm cel mai mare multiplicator astfel încât value / factor <= 1023
    for (int i = 11; i >= 0; --i) {
        double factor = pow(10, i - 6);  // index 6 corespunde cu baza
        double scaled = value / factor;
        if (fabs(scaled - (int)scaled) < 1e-6 && scaled <= 1023) { //verificam daca se mai poate simplifica
            uint16_t encoded_value = (uint16_t)scaled;
            uint16_t result = (encoded_value << 6) | (unit_code << 4) | i; //construim numarul pe 16 biti care va fi rezultatul
            printf("Valoare stocată: %u\n", encoded_value);
            printf("Unitate: %s\n", unitNames[unit_code]);
            printf("Multiplicator: %s\n", multiplierNames[i]);
            return result;
        }
    }

    printf("Eroare: Valoarea nu poate fi stocată fără pierderi.\n");
    return 0xFFFF;
}

// Decodare
void decode_measurement(uint16_t encoded) {
    uint16_t value = encoded >> 6; //valoare se afla pe primi 10 biti a rezultatului
    uint16_t unit = (encoded >> 4) & 0x3; //marimea de baza (gram, litru, metru)
    uint16_t mult = encoded & 0xF; //multiplicatorul

    double real_value = value * pow(10, mult - 6);
    printf("Valoare originală: %.0f %s\n", real_value, unitNames[unit]);
    printf("Stocat: %u, Unitate: %s, Multiplicator: %s\n", value, unitNames[unit], multiplierNames[mult]);
}

int main() {
    unsigned int val;
    char unit[10];
    printf("Introdu valoarea si unitatea (gram/metru/litru): ");
    scanf("%u %s", &val, unit);

    uint16_t encoded = encode_measurement(val, unit);
    if (encoded != 0xFFFF) {
        decode_measurement(encoded);
    }

    return 0;
}
