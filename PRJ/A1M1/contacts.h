struct Name {
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

struct Address {
    unsigned int streetNumber;
    unsigned int apartmentNumber;
    char street[41];
    char postalCode[8];
    char city[41];
};

struct Numbers {
    char cell[11];
    char home[11];
    char business[11];
};
