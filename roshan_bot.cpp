#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <unistd.h>  // For usleep() to create delay effect

using namespace std;

// ANSI Color Codes foXr Beautiful Output
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"
#define YELLOW  "\033[1;33m"
#define PURPLE  "\033[1;35m"
#define BOLD    "\033[1m"




// Function to add delay (Typing effect)
void typingEffect(string text, int speed = 50000) {
    for (char c : text) {
        cout << c << flush;
        usleep(speed);  // Delay in microseconds
    }
    cout << endl;
}

// Function to make the assistant speak
void speak(string text) {
    string command = "say \"" + text + "\"";  // Uses macOS's built-in 'say' command
    system(command.c_str());
}

// Function to display ASCII banner
void displayBanner() {
    system("clear"); // Clear screen
    cout << CYAN;
    cout << "╔══════════════════════════════════════════════════════════════════╗\n";
    cout << "║                    🌟 WELCOME TO ROSHAN BOT 🌟                   ║\n";
    cout << "╚══════════════════════════════════════════════════════════════════╝\n";
    cout << RESET;
}

// Function to greet based on time
void wishme() {
    time_t now = time(0);
    tm *timeStruct = localtime(&now);
    
    cout << GREEN;
    if (timeStruct->tm_hour < 12) {
        typingEffect("GOOD MORNING, BOSS! ☀️");
        speak("Good morning, Boss!");
    } else if (timeStruct->tm_hour >= 12 && timeStruct->tm_hour <= 16) {
        typingEffect("GOOD AFTERNOON, BOSS! 🌤️");
        speak("Good afternoon, Boss!");
    } else {
        typingEffect("GOOD EVENING, BOSS! 🌙");
        speak("Good evening, Boss!");
    }
    cout << RESET;
}

// Function to display current date & time
void datetime() {
    time_t now = time(0);
    char *dt = ctime(&now);
    cout << YELLOW << "📅 The current date and time is: " << dt << RESET;
    speak("The current date and time is " + string(dt));
}

int main() {
    displayBanner();

    string password;
    string query;

    do {
        cout << BOLD << YELLOW;
        cout << "╔════════════════════════╗\n";
        cout << "║ 🔑 ENTER YOUR PASSWORD ║\n";
        cout << "╚════════════════════════╝\n" << RESET;
        
        cout << "👉 ";
        getline(cin, password);  // Get password input

        if (password == "Roshan") {
            cout << GREEN << "✅ Access Granted! Welcome Back, Boss! 🤖\n" << RESET;
            speak("Access granted. Welcome back, Boss!");
            usleep(700000);
            wishme();

            while (true) {
                cout << CYAN;
                cout << "╔═════════════════════════════════════╗\n";
                cout << "║   💬 How can I assist you today?    ║\n";
                cout << "╚═════════════════════════════════════╝\n" << RESET;
                
                cout << "Your Query ===> ";
                getline(cin, query);
                cout << endl;

                if (query == "hi" || query == "hey" || query == "hello") {
                    typingEffect("👋 Hello Boss, How can I assist you?");
                    speak("Hello Boss, How can I assist you?");
                } 
                else if (query == "bye" || query == "stop" || query == "exit") {
                    typingEffect("Goodbye Boss, Have a great day! 🥰");
                    speak("Goodbye Boss, Have a great day!");
                    exit(0);
                } 
                else if (query == "who are you" || query == "tell me about yourself" || query == "about") {
                    typingEffect("I am ur BOT, your personal virtual assistant! 🦾");
                    speak("I am ur BOT, your personal virtual assistant!");
                } 
                else if (query == "how are you" || query == "whatsup" || query == "how is your day") {
                    typingEffect("I'm doing great, Boss! Ready to assist you. 😊");
                    speak("I'm doing great, Boss! Ready to assist you.");
                } 
                else if (query == "time" || query == "date") {
                    datetime();
                } 
                else if (query == "open notepad") {
                    cout << GREEN << "📝 Opening TextEdit...\n" << RESET;
                    speak("Opening TextEdit");
                    system("open -a TextEdit");
                } 
                else if (query == "open google") {
                    cout << GREEN << "🌐 Opening Google...\n" << RESET;
                    speak("Opening Google");
                    system("open https://www.google.com");
                } 
                else if (query == "open youtube") {
                    cout << GREEN << "📺 Opening YouTube...\n" << RESET;
                    speak("Opening YouTube");
                    system("open https://www.youtube.com");
                } 
                else {
                    cout << RED << "⚠️ Sorry, I didn't understand that. Try again!" << RESET << endl;
                    speak("Sorry, I didn't understand that. Please try again.");
                }
            }
        } else {
            cout << RED << "❌ Incorrect Password! Try Again.\n" << RESET;
            speak("Incorrect password. Please try again.");
        }
    } while (true);

    return 0;
}
