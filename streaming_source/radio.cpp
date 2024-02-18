#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // For system()
#include <unistd.h> // For usleep

// Function to restart the Liquidsoap process with the updated script
void StartLiquidsoapForMusic() {
    // Stop current Liquidsoap process
    system("pkill -f 'liquidsoap'");

    // Small delay to ensure the process has stopped
    usleep(500000); // 500 ms

    // Start Liquidsoap with the updated script
    system("nice -n -10 liquidsoap music.liq &");
}

void StartLiquidsoapForVoice() {
    // Stop current Liquidsoap process
    system("pkill -f 'liquidsoap'");

    // Small delay to ensure the process has stopped
    usleep(500000); // 500 ms

    // Start Liquidsoap with the updated script
    system("nice -n -10 liquidsoap voice.liq &");
}

void StartLiquidsoapForMixed() {
    // Stop current Liquidsoap process
    system("pkill -f 'liquidsoap'");

    // Small delay to ensure the process has stopped
    usleep(500000); // 500 ms

    // Start Liquidsoap with the updated script
    system("nice -n -10 liquidsoap mixed.liq &");
}

int main() {
    std::string command;
	printf("Commands: start music , start voice, start mixed, stop radio\n");

    while (true) {
        std::getline(std::cin, command);

        if (command == "start music") {
            StartLiquidsoapForMusic();
        } else if (command == "start voice") {
            StartLiquidsoapForVoice();
        } else if (command == "start mixed") {
            StartLiquidsoapForMixed();
        } else if (command == "help") {
            printf("Commands: start music , start voice, start mixed, stop radio\n");
        }
		 else if (command == "stop radio") {
            system("pkill -f 'liquidsoap'");
        }
		else
		{
			printf("Invalid Command. Type 'Help' to check the list of valid command\n");
		}
    }

    return 0;
}
