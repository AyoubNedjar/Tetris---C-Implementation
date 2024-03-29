#include "View.h"
#include "Controller.h"

/*
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <termios.h>
#endif
*/

using namespace std;



/*#ifdef _WIN32
void enableRawMode() {
    HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hstdin, &mode);
    mode &= ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT); // Désactive l'écho et l'entrée ligne
    SetConsoleMode(hstdin, mode);
}

void disableRawMode() {
    HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hstdin, &mode);
    mode |= (ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT); // Réactive l'écho et l'entrée ligne
    SetConsoleMode(hstdin, mode);
}
#else
void enableRawMode() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
}

void disableRawMode() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
}
#endif

*/


int main()
{

    //enableRawMode();
    Game g;
    View v;
    Controller c(g, v);

    g.addObserver(&c);

    c.start();
    //disableRawMode();

    return 0;
}
