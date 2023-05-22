/*
 Name:		BasicExample.ino
 Created:	5/22/2023 6:10:38 PM
 Author:	jiaji
*/
#include "FilesystemUtilities.h"
#include <utility>
#include <SD.h>

// the setup function runs once when you press reset or power the board
void setup()
{
	Serial.begin(115200);
	SD.begin();

	DirectoryIterator iterator(SD, "/");

	Serial.print("For loop:\n");
	for (DirectoryIterator it = iterator.begin(); it != iterator.end(); it++)
		Serial.println(it->path());

	Serial.print("\n\nRange-based for loop:\n");
	for (auto& entry : iterator)
		Serial.println(entry.path());

	Serial.print("\n\nFor_each loop:\n");
	std::for_each(iterator.begin(), iterator.end(), [](File& entry)
		{
			Serial.println(entry.path());
		});

	Serial.print("\nTest ended");
}

// the loop function runs over and over again until power down or reset
void loop() {

}
