
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD 256

// Function declarations
int analyze_password(const char password[]);
int is_common_password(const char password[]);
void display_banner(void);
void display_report(const char password[], int score);
void display_recommendations(const char password[], int score);
void analyze_character_types(const char password[],
                             int *upper, int *lower,
                             int *digit, int *special);

// Display application banner
void display_banner(void)
{
    printf("\n");
    printf("==================================================\n");
    printf("       CYBERKNIGHT SECURITY SYSTEM\n");
    printf("             PASSWORD ANALYZER\n");
    printf("==================================================\n");
    printf("       Defensive Security Toolkit | C\n");
    printf("                  Version 1.0\n");
    printf("==================================================\n");
}

// Detect common weak passwords
int is_common_password(const char password[])
{
    const char *common_passwords[] = {
        "password",
        "123456",
        "12345678",
        "123456789",
        "qwerty",
        "admin",
        "letmein",
        "welcome",
        "iloveyou",
        "abc123"
    };

    int total = sizeof(common_passwords) /
                sizeof(common_passwords[0]);

    for (int i = 0; i < total; i++)
    {
        if (strcasecmp(password, common_passwords[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}

// Analyze character categories
void analyze_character_types(const char password[],
                             int *upper, int *lower,
                             int *digit, int *special)
{
    *upper = 0;
    *lower = 0;
    *digit = 0;
    *special = 0;

    for (int i = 0; password[i] != '\0'; i++)
    {
        unsigned char ch = (unsigned char)password[i];

        if (isupper(ch))
            *upper = 1;

        else if (islower(ch))
            *lower = 1;

        else if (isdigit(ch))
            *digit = 1;

        else
            *special = 1;
    }
}

// Calculate password strength
int analyze_password(const char password[])
{
    int score = 0;
    int length = strlen(password);

    int upper, lower, digit, special;

    analyze_character_types(password,
                            &upper, &lower,
                            &digit, &special);

    // Password length
    if (length >= 8)
        score += 20;

    if (length >= 12)
        score += 15;

    if (length >= 16)
        score += 15;

    // Character diversity
    if (upper)
        score += 15;

    if (lower)
        score += 10;

    if (digit)
        score += 10;

    if (special)
        score += 15;

    // Common password penalty
    if (is_common_password(password))
        score = 0;

    return score;
}

// Display password recommendations
void display_recommendations(const char password[], int score)
{
    int upper, lower, digit, special;

    int length = strlen(password);

    analyze_character_types(password,
                            &upper, &lower,
                            &digit, &special);

    printf("\nSECURITY RECOMMENDATIONS\n");
    printf("------------------------------------------\n");

    if (length < 12)
        printf("[!] Increase password length to at least 12 characters.\n");

    if (!upper)
        printf("[!] Add uppercase letters.\n");

    if (!lower)
        printf("[!] Add lowercase letters.\n");

    if (!digit)
        printf("[!] Include numbers.\n");

    if (!special)
        printf("[!] Include special characters.\n");

    if (is_common_password(password))
        printf("[!] This password matches a common weak-password example.\n");

    if (score >= 80)
        printf("[+] Good length and character variety. Consider using a password manager.\n");

    printf("------------------------------------------\n");
}

// Display complete security report
void display_report(const char password[], int score)
{
    int upper, lower, digit, special;

    analyze_character_types(password,
                            &upper, &lower,
                            &digit, &special);

    printf("\n");
    printf("==================================================\n");
    printf("              SECURITY ANALYSIS\n");
    printf("==================================================\n");

    printf("Password length:       %zu characters\n", strlen(password));

    printf("Uppercase letters:     %s\n", upper ? "YES" : "NO");
    printf("Lowercase letters:     %s\n", lower ? "YES" : "NO");
    printf("Numbers:               %s\n", digit ? "YES" : "NO");
    printf("Special characters:    %s\n", special ? "YES" : "NO");

    printf("Common password:       %s\n",
           is_common_password(password) ? "YES - WARNING" : "NO");

    printf("--------------------------------------------------\n");

    printf("SECURITY SCORE: %d/100\n", score);

    if (score >= 80)
        printf("STRENGTH: VERY STRONG\n");

    else if (score >= 60)
        printf("STRENGTH: STRONG\n");

    else if (score >= 40)
        printf("STRENGTH: MODERATE\n");

    else
        printf("STRENGTH: WEAK\n");

    printf("==================================================\n");

    display_recommendations(password, score);
}

// Main application
int main(void)
{
    char password[MAX_PASSWORD];
    char choice;

    do
    {
        display_banner();

        printf("\nEnter a test password: ");

        if (fgets(password, sizeof(password), stdin) == NULL)
        {
            printf("\nInput error. Exiting.\n");
            return 1;
        }

        // Check whether the input filled the buffer
        if (strchr(password, '\n') == NULL && !feof(stdin))
        {
            int ch;

            while ((ch = getchar()) != '\n' && ch != EOF)
                ;

            printf("\nError: Password is too long.\n");
            continue;
        }

        // Remove newline
        password[strcspn(password, "\n")] = '\0';

        if (strlen(password) == 0)
        {
            printf("\nError: Password cannot be empty.\n");
            continue;
        }

        // Analyze password
        int score = analyze_password(password);

        // Display results
        display_report(password, score);

        printf("\nAnalyze another test password? (y/n): ");

        if (scanf(" %c", &choice) != 1)
        {
            printf("\nInput error. Exiting.\n");
            return 1;
        }

        // Clear remaining input
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;

    } while (choice == 'y' || choice == 'Y');

    printf("\n==================================================\n");
    printf("       CYBERKNIGHT ANALYSIS COMPLETED\n");
    printf("       Thank you for using our toolkit.\n");
    printf("==================================================\n");

    return 0;
}
