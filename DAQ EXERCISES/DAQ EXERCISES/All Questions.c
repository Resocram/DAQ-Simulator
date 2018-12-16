/*#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <DAQlib.h>
#define TRUE 1
#define FALSE 0
void workFunction(void);
int main(void) {
	int setupNum;
	printf("Enter an integer value (0 for hardware) (1 for simulator):\n");
	scanf("%d", &setupNum);
	if (setupDAQ(setupNum) == TRUE) {
		workFunction();
	}
	else {
		printf("Error opening DAQ.\n");
	}
	system("PAUSE");
	return 0;

}
void workFunction(void) {
	while (continueSuperLoop() == TRUE) {
		printf("HELLO");
	}
}
*/
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define OUTFILENAME "Values.txt"
int main(void) {
	FILE* outfile;

	outfile = fopen(OUTFILENAME, "w");
	if (outfile == NULL) {
		printf("Error opening file.\n");
	}
	else {
		int x = 0;
		int y;
		do {
			y = x * x + 2;
			fprintf(outfile, "%d %d\n", x, y);
			x++;
		} while (x <= 10);
	}
	fclose(outfile);
	system("PAUSE");
	return 0;
}
*/
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <DAQlib.h>
#define TRUE 1
#define FALSE 0
#define ON 1 
#define OFF 0 
#define SWITCH0 0 
#define SWITCH1 1
#define LED0 0
#define LED1 1
#define LED2 2
void workFunction(void);
void setupLED(int toggle1, int toggle2, int toggle3);

int main(void) {
	int setupNum;
	printf("Enter a number (0 for the hardware)(1 for the simulator):\n");
	scanf("%d", &setupNum);
	if (setupDAQ(setupNum) == TRUE) {
		 workFunction();
	}
	else {
		printf("Error initializing DAQ.\n");
	}
	system("PAUSE");
	return 0;
}
void workFunction(void) {
	while (continueSuperLoop() == TRUE) {
		if (digitalRead(SWITCH0) == OFF && digitalRead(SWITCH1) == OFF) {
			setupLED(OFF, OFF, OFF);
		}
		else if (digitalRead(SWITCH0) == ON && digitalRead(SWITCH1) == OFF) {
			setupLED(ON, OFF, OFF);
		}
		else if (digitalRead(SWITCH0) == OFF && digitalRead(SWITCH1) == ON) {
			setupLED(OFF, ON, OFF);
		}
		else {
			setupLED(OFF, OFF, ON);
		}
	}
}
void setupLED(int toggle1, int toggle2, int toggle3) {
	digitalWrite(LED0, toggle1);
	digitalWrite(LED1, toggle2);
	digitalWrite(LED2, toggle3);
}
*/
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <DAQlib.h>
#define TRUE 1
#define FALSE 0
void writeNumber(int number);
void writeDigit(int digit, int position);
int main(void) {
	int setupNum;
	printf("Enter a number (0 for the hardware)(1 for the simulator):\n");
	scanf("%d", &setupNum);
	if (setupDAQ(setupNum) == TRUE) {
		writeNumber(123456789);
	}
	else {
		printf("Error initializing DAQ.\n");
	}
	system("PAUSE");
	return 0;
}

void writeNumber(int number) {
	int counter = number;
	int value;
	int digits =0;
	while (counter != 0 && digits < 8) {
		value = counter % 10;
		writeDigit(value, digits);
		counter = counter / 10;
		digits++;
	}
	while (digits < 8) {
		displayWrite(0, digits);
		digits++;
	}
}

void writeDigit(int digit, int position) {
	static int digits[] = { 252,96,218,242,102,182,190,224,254,246 };
	displayWrite(digits[digit], position);
}
*/
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <DAQlib.h>
#include <Windows.h>
#define ON 1
#define OFF 0
#define TRUE 1
#define FALSE 0
#define EWRED 2
#define EWYELLOW 1
#define EWGREEN 0
#define NSRED 5
#define NSYELLOW 4
#define NSGREEN 3

void setLEDS_EW(int green, int yellow, int red);
void setLEDS_NS(int green, int yellow, int red);
void workFunction(void);
int main(void) {
	int setupNum;
	printf("Enter a number (0 for the hardware)(1 for the simulator):\n");
	scanf("%d", &setupNum);
	if (setupDAQ(setupNum) == TRUE) {
		workFunction();
	}
	else {
		printf("Error initializing DAQ.\n");
	}
	system("PAUSE");
	return 0;
}

void workFunction(void) {
	while (continueSuperLoop() == TRUE) {
		setLEDS_EW(ON, OFF, OFF);
		setLEDS_NS(OFF, OFF, ON);
		Sleep(5000);
		setLEDS_EW(OFF, ON, OFF);
		setLEDS_NS(OFF, OFF, ON);
		Sleep(2000);
		setLEDS_EW(OFF, OFF, ON);
		setLEDS_NS(OFF, OFF, ON);
		Sleep(2000);
		setLEDS_EW(OFF, OFF, ON);
		setLEDS_NS(ON, OFF, OFF);
		Sleep(5000);
		setLEDS_EW(OFF, OFF, ON);
		setLEDS_NS(OFF, ON, OFF);
		Sleep(2000);
		setLEDS_EW(OFF, OFF, ON);
		setLEDS_NS(OFF, OFF, ON);
		Sleep(2000);
	}
}

void setLEDS_EW(int green, int yellow, int red) {
	digitalWrite(EWGREEN, green);
	digitalWrite(EWYELLOW, yellow);
	digitalWrite(EWRED, red);

}
void setLEDS_NS(int green, int yellow, int red) {
	digitalWrite(NSGREEN, green);
	digitalWrite(NSYELLOW, yellow);
	digitalWrite(NSRED, red);

}
*/
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<DAQlib.h>
#include <Windows.h>
#define CHANNEL 0
#define SWITCH0 0 
#define TRUE 1
#define FALSE 0 
#define ON 1
#define OFF 0
int convertToKelvin(double voltage);
void readTemperature(void);
void workFunction(void);
void writeNumber(int number);
void writeDigit(int digit, int position);
int main(void) {
	int setupNum;
	printf("Enter number:\n");
	scanf("%d", &setupNum);
	if (setupDAQ(setupNum) == TRUE) {
		workFunction();
	}
	else {
		printf("Error initializing DAQ\n");
	}
	system("PAUSE");
	return 0;
}

int convertToKelvin(double voltage) {
	int kelvin;
	kelvin = voltage * 100;
	return kelvin;
}
void readTemperature(void) {
	double value = analogRead(CHANNEL);
	int kelvin = convertToKelvin(value);
	writeNumber(kelvin);
}

void workFunction(void) {
	while (continueSuperLoop() == TRUE) {
		if (digitalRead(SWITCH0) == ON) {
			readTemperature();
		}
		else {
			int value = analogRead(CHANNEL);
			writeNumber(value);
		}
		Sleep(1000);

	}
}
void writeNumber(int number) {
	int counter = number;
	int value;
	int digits = 0;
	while (counter != 0 && digits < 8) {
		value = counter % 10;
		writeDigit(value, digits);
		counter = counter / 10;
		digits++;
	}
	while (digits < 8) {
		displayWrite(0, digits);
		digits++;
	}
}

void writeDigit(int digit, int position) {
	static int digits[] = { 252,96,218,242,102,182,190,224,254,246 };
	displayWrite(digits[digit], position);
}
*/
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int length(char s[]);
void getFileName(char FileName[]);

int main(void) {
	char aFilename[80];
	getFileName(aFilename);
	printf("%s\n", aFilename);
	system("PAUSE");
	return 0;
}

int length(char s[]) {
	int count = 0;
	while (s[count] != '\0') {
		count++;
	}
	return count;
}

void getFileName(char Filename[]) {
	char ToAdd[] = { '.','t','x','t','\0' };
	int index2 = 0;
	printf("Please enter a file name:\n");
	scanf("%s", Filename);
	int index = length(Filename);
	while (ToAdd[index2] != '\0') {
		Filename[index+index2] = ToAdd[index2];
		index2++;
	}
	Filename[index + index2] = '\0';
}
*/
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void toLowercase(char word[]);
int main(void) {
	char word[] = "APSC 160 IS INTERESTING";
	toLowercase(word);
	printf("%s\n", word);
	system("PAUSE");
	return 0;
}
void toLowercase(char word[]) {
	
	int index;

	for (index = 0; word[index] != '\0'; index++) {
		if (word[index] >= 'A' && word[index] <= 'Z') {
			word[index] = word[index] + 32;
		}
	}
	
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <>