

/* 
trying this again 
*/

int redLed = 13;
int greenLed = 12;
int switchPin = 8; 
bool ledOn; 
bool prevButtonStatus;

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

void dimmer(int ledPin, bool on)
{
	int dimLevel;
	for(int i = 20; i < 256; i++)
	{
		if (on){
			dimLevel = i;
		}
		else {
			dimLevel = 	256 - i;
		}
		analogWrite(ledPin, dimLevel);
		delay(50);
	}
}


void autoOff(int ledPin, int seconds)
{
	unsigned long currTime = millis();
	if (currTime - timer > seconds * 1000 && ledOn == HIGH)
	{
		ledOn = !ledOn;
		// digitalWrite(ledPin, ledOn);
		dimmer(ledPin, ledOn);
	}
}

void void setup() 
{
	pinMode(redLed, OUTPUT);
	pinMode(greenLed, OUTPUT);
	pinMode(switchPin, INPUT);
	prevButtonStatus = LOW;
	ledOn = LOW;
}

void void loop() 
{
	bool currButtonStatus = deBounce(prevButtonStatus);
	if (currButtonStatus == HIGH && prevButtonStatus == LOW)
	{
		ledOn = !ledOn; 
		if (ledOn == HIGH) timer = millis(); 
	}
	
	prevButtonStatus = currButtonStatus;

	dimmer(redLed, HIGH);
	dimmer(greenLed, HIGH);

	// digitalWrite(redLed, ledOn);
	// digitalWrite(greenLed, ledOn);

	autoOff(redLed);
	autoOff(greenLed);
}

