

/* 
trying this again 
*/

int redLed = 13;
int greenLed = 12;
int switchPin = 8; 
bool previousStatus;
unsigned long timer;

bool deBounce(bool prevStatus)
{
  bool curr = digitalRead(switchPin);
	if (curr != prevStatus){
		delay(5);
		curr = digitalRead(switchPin);
	}
	return curr;
}


void void setup() 
{
	pinMode(redLed, OUTPUT);
	pinMode(greenLed, OUTPUT);
	pinMode(switchPin, INPUT);
	previousStatus = LOW;
}

void void loop() 
{
	bool currStatus = deBounce(previousStatus);
	if (currStatus == HIGH){
		previousStatus = !previousStatus;
		digitalWrite(redLed, previousStatus);
		digitalWrite(greenLed, previousStatus);
		if (previousStatus) timer = millis(); 
	}

	unsigned long currTime = millis(); 
	if (currTime - timer > 5000 && previousStatus == HIGH){
		previousStatus = !previousStatus;
		digitalWrite(redLed, previousStatus);
		digitalWrite(greenLed, previousStatus);
	} 
}
