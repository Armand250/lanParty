typedef struct Player{
    char *firstName;
    char *secondName;
    int points;
}Player;

typedef struct Echipa{
    Player *p;
    int nrJucatori;
    char *numeEchipa;
    float punctaj;
}Team;

typedef struct evidenta{
    Team t;
}Evidence;