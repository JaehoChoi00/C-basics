#include <stdio.h>
#include <stdint.h>
#include <float.h>
#include <stdbool.h>
#include <unistd.h> // For thread sleep
#include <wchar.h> // For wide character support. Unicode
#include <locale.h> // Required to tell the terminal to support Unicode

// --- ANSI ESCAPE STYLE MACROS ---
#define RESET          "\033[0m"
#define BOLD           "\033[1m"
#define DIM            "\033[2m"
#define UNDERLINE      "\033[4m"
#define BLINK          "\033[5m"
#define INVERT         "\033[7m"
#define STRIKETHROUGH  "\033[9m"

// --- FOREGROUND COLORS ---
#define FG_BLACK       "\033[30m"
#define FG_RED         "\033[31m"
#define FG_GREEN       "\033[32m"
#define FG_YELLOW      "\033[33m"
#define FG_BLUE        "\033[34m"
#define FG_MAGENTA     "\033[35m"
#define FG_CYAN        "\033[36m"
#define FG_WHITE       "\033[37m"

// --- BACKGROUND COLORS ---
#define BG_BLACK       "\033[40m"
#define BG_RED         "\033[41m"
#define BG_GREEN       "\033[42m"
#define BG_YELLOW      "\033[43m"
#define BG_BLUE        "\033[44m"
#define BG_MAGENTA     "\033[45m"
#define BG_CYAN        "\033[46m"
#define BG_WHITE       "\033[47m"

// --- ADVANCED LAYOUT UTILITIES ---
#define CLEAR_LINE     "\033[2K\r"

// Terminal code
// gcc Variables.c -o Variables && ./Variables 
int main() {
    // Invisible characters
    // These invisible ASCII codes are for manipulating the terminal windows.

    // Screen & Keyboard Controls.
    char endOfString = 0; // ASCII code for NUL - NULL
    char bell = 7; // ASCII code to play system alert sound
    char backSpace = 8; // ASCII code to move terminal cursor backward one space.
    char horizontalTab = 9; // ASCII code to shift text by a tab key column amount.
    char lineFeed = 10;
    char carriageReturn = 13; // ASCII code for \r return to start of current line.
    char escape = 27; // ASCII code for ESC Escape that tells the system that the following characters are special formatting commands (like text color).

    // Data transmissions.
    char startOfHeading = 1; // Marks the beginning of meta data [file name or address]
    char startOfText = 2; // Signals that the actual body of the message is starting
    char endOfText = 3; // Signals that the body of the message is finished.
    char endOfTransmission = 4; // Closes data stream.
    char enquiry = 5; // Asks the computer "Are you there? Send your status."
    char acknowledge = 6; // The receiving computer replies "Yes, I am here and ready."
    char negativeAcknowledge = 21; // The receiving computer replies "Error! The last data packet was corrupted, send again."
    char synchronousIdle = 22; // Sent periodically to keep two communication devices in perfect sync.
    char endOfTransmitBlock = 23; // Marks the end of a single chunk of data when dividing a massive file.

    // Physical machine control. For Teletypewriters
    char verticalTab = 11;       // Jumped the paper roller downward to a pre-set row (like skip to invoice totals box).
    char formFeed = 12;          // Ejected the entire current physical piece of paper out of the printer for a fresh page.
    char shiftOut = 14;          // Switched the mechanical printing ribbons to an alternate color or font set (e.g., red ink or bold).
    char shiftIn = 15;           // Switched the printing ribbon back to the default black/standard text font.
    char dataLinkEscape = 16;    // Changes the meaning of the very next transmission character to a raw hardware command.
    char deviceControl1 = 17;    // Custom hardware switch. Universally used as "XON" to resume a paused paper tape reader.
    char deviceControl2 = 18;    // Custom hardware switch for secondary attached device operations.
    char deviceControl3 = 19;    // Custom hardware switch. Universally used as "XOFF" to pause a paper tape reader machine.
    char deviceControl4 = 20;    // Custom hardware switch for secondary attached device operations.
    char cancel = 24;            // Tells a mechanical printer, "Ignore everything typed on this current line, it was a mistake."
    char endOfMedium = 25;       // Triggered an alarm indicating the machine was entirely out of paper tape or printer ink ribbon.
    char substitute = 26;        // Used to replace a character that the machine physically could not read or print due to data corruption.

    // Ancient Database Separators
    char fileSeparator = 28;     // Acted like a modern "Folder" boundary to separate different data files in a raw stream.
    char groupSeparator = 29;    // Acted like a sub-folder boundary to separate collections of records within a file.
    char recordSeparator = 30;   // Acted like a spreadsheet row boundary to separate individual data records.
    char unitSeparator = 31;     // Acted like a spreadsheet column boundary to separate individual fields within a record.
    
    // The Hardware Eraser
    char deleteChar = 127;       // ASCII code for DEL. Written in binary as 1111111 to physically punch holes over tape mistakes.
    
    // Simple downloading terminal program
    char spinner[4] = {'|', '/', '-', '\\'};
    printf("\nDownloading package...\n");

    for (int i = 0; i < 101; i += 5) {
        printf("%cProgress[", carriageReturn);
        for (int j = 0; j < i / 5; j++) {
            printf("#");
        }
        for (int j = i / 5; j < 20; j++) {
            printf(".");
        }
        printf("] %d%% %c", i, spinner[(i/5)%4]);
        fflush(stdout); // C buffers output. fflush forces the terminal to show it immediately.
        usleep(10000); // #include <unistd.h> needed. 
    }
    printf("%c[2K\r", escape); // Uses ANSI menu command '2K' to erase the entire line, then resets cursor.
    printf("%cProgress[###################] 100%%", carriageReturn);
    printf("\nDownload Complete!\n");

    // Use case for special formats after 27.
    printf("%c[32m", escape); // 32 = green and m = menu code.
    printf("\nGreen text\n");
    printf("%c[0m", escape); // 0 resets the format.

    // Combining codes.
    printf("%c[1;31m", escape); // 1 = bold, 31 = red text.
    printf("ERROR: Something went dangerously wrong!\n");
    printf("%c[0m", escape);

    // RGB.
    printf("%c[38;2;255;165;0m", escape);

    // The verdict is that, nobody really wants to sit down and write all that code.
    // So instead, you would #define at the top of the files to use.
    printf(FG_GREEN  BOLD "Success!" RESET "\n");
    
    /* 
        Character
    */ 

    // Visible characters
    printf(BOLD UNDERLINE "\n[Characters]\n\n" RESET);
    char character = 'a'; // Signed and counts from -128 to 127 for bits

    char minVisibleCharacter = 32;
    printf("[%c]\n", minVisibleCharacter); // Results in printing the [ ] space character
    char maxVisibleCharacter = 126;
    printf("%c\n", maxVisibleCharacter); // Results in printing the [~] space character

    // Specifier %c
    printf("%c\n", character);
    character++;
    printf("%c\n", character); // Results in printing 'b'
    character -= 2;
    printf("%c\n", character); // Results in printing [']
    character += 1; // Resets to 'a'

    // Specifier %d
    printf("%d\n", character); // Result in printing 97. the ASCII integer for 'a'.
    character++;
    printf("%d\n", character); // Results in printing 98
    character -= 2;
    printf("%d\n", character); // Results in printing 96
    character += 1; // Resets to 'a'

    unsigned char rgb = 255; // For RGB, raw binary file data, raw data
    unsigned char encryption_key[4] = { 0xDE, 0xAD, 0xBE, 0xEF }; 

    /*
        Unicode Characters 
    */
    setlocale(LC_ALL, ""); // Tells terminal to interpret outputs as UTF-8 Unicode

    wchar_t rocketEmoji = L'🚀';
    
    // Specifier %lc
    printf("\nRocket: %lc\n", rocketEmoji);


    /* 
        Integers
    */ 
    printf(BOLD UNDERLINE "\n[Integers]\n\n" RESET);

    int integer = 2147483647; // Signed 2^32 halved to share between negative and positive
    unsigned int unsignedInteger = 4294967295; // Unsigned 2^32 full from 0 to 2^32.

    // Specifier %d, %i
    printf("Signed integers:\n");
    printf("%d\n", integer);
    printf("%i\n", integer); // Prints the variable as a signed base-10 integer (identical to %d here)
    integer++;
    printf("%d\n", integer); // Will output -2147483648. As the sign has been inverted.
    integer--;

    // Specifier %u
    printf("\nUnsigned integers:\n");
    printf("%u\n", unsignedInteger);
    unsignedInteger++;
    printf("%u\n", unsignedInteger);
    unsignedInteger--;

    // Specifier %o Octal
    printf("\nOctal integers:\n");
    printf("%d -> %o\n", integer, integer); 

    // Specifier %x Hexadecimal
    printf("\nHexadecimal integers:\n");
    printf("%d -> %x\n", integer, integer); 

    /* 
        Shorts
    */ 
    printf(BOLD UNDERLINE "\n[Shorts]\n\n" RESET);

    // Specifier %hd
    short shortNum = 32767; // Signed
    printf("%hd\n", shortNum);

    // Specifier %hu
    unsigned short unsignedShortNum = 65535; // Unsigned
    printf("%hu\n", unsignedShortNum);

    /* 
        Long
    */ 
    printf(BOLD UNDERLINE "\n[Long]\n\n" RESET);

    // Specifier %ld, %li
    long longNum = 9223372036854775807L; // Signed and dependent on OS
    printf("%ld\n", longNum);
    printf("%li\n\n", longNum);

    // Specifier %lli, %lld
    long long tooLongNum = 9223372036854775807; // Signed and same on all OS
    printf("%lli\n", tooLongNum);
    printf("%lld\n\n", tooLongNum);

    // Specifier %llu
    unsigned long long tooMuchNum = 18446744073709551615ULL; 
    printf("%llu\n", tooMuchNum);

    /* 
        Floats
    */ 
    printf(BOLD UNDERLINE "\n[Floats]\n\n" RESET);
    float floatSize = FLT_MAX; // 2^128

    // Specifier %f, %e, %E
    printf("Maximum float number: %f\n", floatSize); 
    printf("Maximum float number: %e\n", floatSize); // Using the exponentional notation
    printf("Maximum float number: %E\n", floatSize); // Using the exponentional notation
    
    float floatExample = 3.1415926;
    printf("pi = %.2f\n",floatExample); // .2 = 2 decimal place.
    
    /* 
        Double
    */ 
    printf(BOLD UNDERLINE "\n[Double]\n\n" RESET);

    // Specifier %lf
    double doubleSize = DBL_MAX;
    printf("Maximum double number: %lf\n", doubleSize);

    /* 
        Strings
    */ 
    printf(BOLD UNDERLINE "\n[Strings]\n\n" RESET);
    char string[] = "Hello World!";
    
    // Specifier %s
    printf("%s\n", string); 
    string[0] = 'Y';
    printf("%s\n", string);
    string[0]-=17;
    printf("%s\n", string);
    printf("[%c]\n", string[12]); // This is the null terminator

    /* 
        Pointers & Address
    */ 
    printf(BOLD UNDERLINE "\n[Pointers & Address]\n\n" RESET);

    // Specifier %p
    printf("Memory Address of [string]: %p\n", &string);

    bool yesOrNo = true; // 1 or 0. It doesn't matter if the value is assigned to be greater than 1. It will still be 1
    bool fuse = false; // If we link the fuse variable to any circuit or logic. It becomes a very simple and elegant single use detector.

    int foo; // foo is just a generic statement. Mostly to mean absolutely nothing but the variable it represents.
    int bar; // This too.
    int bax; // And this.
    int quz; // This four.

    int alice; // for cyber security. The person trying to send a message
    int bob; // This too. The person trying to receive.
    int eve; // And this. The person trying to hack.
}