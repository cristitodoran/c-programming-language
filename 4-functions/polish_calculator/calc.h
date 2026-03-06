#define MAXOP 100
#define NUMBER '0'
#define PEEK '1'
#define DUPLICATE '2'
#define SWAP '3'
#define CLEAR '4'
#define SIN '5'
#define EXP '6'
#define POW '7'
#define STORE_VAR '8'
#define GET_VAR '9'
#define MAXVAL 100
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void ungets(char s[]);
