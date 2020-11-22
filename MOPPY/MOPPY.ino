IntervalTimer myTimer;

//Conditions and constraints
unsigned int period[60] = {     30402,  28696 , 27085 , 25565 , 24130 , 22776 , 21497 , 20291 , 19152 , 18077 , 17063 , 16105,
                                15201 , 14348 , 13543 , 12782 , 12065 , 11388 , 10749 , 10145 , 9576  , 9039  , 8531  , 8052,
                                7600  , 7174  , 6771  , 6391  , 6033  , 5694  , 5374  , 5073  , 4788  , 4519  , 4266  , 4026,
                                3800  , 3587  , 3386  , 3196  , 3016  , 2847  , 2687  , 2536  , 2394  , 2260  , 2133  , 2013,
                                1900  , 1793  , 1693  , 1598  , 1508  , 1423  , 1344  , 1268  , 1197  , 1130  , 1066  , 1007

                                //                               Uncorrected frequencies. I find that pulsing at 20 cents above the nominal frequency gets each note better tuned.
                                //                               https://docs.google.com/spreadsheets/d/12MbrmTmzfQR1kzVH3Orp17z25sn0WuJCodh59aa5hxo/edit?usp=sharing
                                //30581 , 28864 , 27244 , 25715 , 24272 , 22909 , 21624 , 20410 , 19264 , 18183 , 17163 , 16199 ,
                                //                           15290 , 14432 , 13622 , 12857 , 12136 , 11454 , 10812 , 10205 , 9632 , 9091 , 8581 , 8099 ,
                                //                           7645 , 7216 , 6811 , 6428 , 6068 , 5727 , 5406 , 5102 , 4816 , 4545 , 4290 , 4049 ,
                                //                           3822 , 3608 , 3405 , 3214 , 3034 , 2863 , 2703 , 2551 , 2408 , 2272 , 2145 , 2024,
                                //                           1911 , 1804 , 1702 , 1607 , 1517 , 1431 , 1351 , 1275 , 1204 , 1136 , 1072 , 1012 ,


                          };

float pitchfactor[164] = {0.500 , 0.504 , 0.509 , 0.513 , 0.517 , 0.522 , 0.526 , 0.531 , 0.535 , 0.540 , 0.544 , 0.549 , 0.554 , 0.558 , 0.563 , 0.568 , 0.573 , 0.578 , 0.583 , 0.588 ,
                          0.593 , 0.598 , 0.603 , 0.608 , 0.613 , 0.618 , 0.624 , 0.629 , 0.634 , 0.640 , 0.645 , 0.651 , 0.656 , 0.662 , 0.668 , 0.673 , 0.679 , 0.685 , 0.691 , 0.697 ,
                          0.703 , 0.709 , 0.715 , 0.721 , 0.727 , 0.733 , 0.739 , 0.746 , 0.752 , 0.759 , 0.765 , 0.772 , 0.778 , 0.785 , 0.791 , 0.798 , 0.805 , 0.812 , 0.819 , 0.826 ,
                          0.833 , 0.840 , 0.847 , 0.854 , 0.862 , 0.869 , 0.876 , 0.884 , 0.892 , 0.899 , 0.907 , 0.915 , 0.922 , 0.930 , 0.938 , 0.946 , 0.954 , 0.962 , 0.971 , 0.979 ,
                          0.987 , 1.000 , 1.004 , 1.013 , 1.021 , 1.030 , 1.039 , 1.048 , 1.057 , 1.066 , 1.075 , 1.084 , 1.093 , 1.103 , 1.112 , 1.122 , 1.131 , 1.141 , 1.151 , 1.160 ,
                          1.170 , 1.180 , 1.190 , 1.201 , 1.211 , 1.221 , 1.232 , 1.242 , 1.253 , 1.263 , 1.274 , 1.285 , 1.296 , 1.307 , 1.318 , 1.330 , 1.341 , 1.352 , 1.364 , 1.376 ,
                          1.387 , 1.399 , 1.411 , 1.423 , 1.435 , 1.448 , 1.460 , 1.473 , 1.485 , 1.498 , 1.511 , 1.523 , 1.536 , 1.550 , 1.563 , 1.576 , 1.590 , 1.603 , 1.617 , 1.631 ,
                          1.645 , 1.659 , 1.673 , 1.687 , 1.702 , 1.716 , 1.731 , 1.746 , 1.760 , 1.775 , 1.791 , 1.806 , 1.821 , 1.837 , 1.853 , 1.868 , 1.884 , 1.901 , 1.917 , 1.933 ,
                          1.950 , 1.966 , 1.983 , 2.000
                         };

const byte RESOLUTION = 25;     
const byte MAX_POSITION = 158;

// data
byte currentPosition[17] = {LOW, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int basePeriod[17] = {LOW, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
bool currentStateStep[17] = {0 , LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
bool currentStateDir[17] = {0 , LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
int currentTick[] = {LOW, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte note2note;
byte note2octave;
float pitchShift[17];
byte currentNote[] = {LOW, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

//pin assignments
const byte STEPPIN[17] = {LOW, // Teensy MIDI channels are given as channels 1-16, not 0-15
                          2,    //Device 1
                          4,    //Device 2
                          6,    //Device 3
                          8,    //Device 4
                          10,   //Device 5
                          24,   //Device 6
                          26,   //Device 7
                          28,   //Device 8
                          14,     //Device 9
                          16,   //Device 10
                          18,   //Device 11
                          20,   //Device 12
                          22,   //Device 13
                          34,   //Device 14
                          36,   //Device 15
                          38,   //Device 16
                         };

const byte DIRPIN[] = { LOW,
                        3,    //Device 1
                        5,    //Device 2
                        7,    //Device 3
                        9,    //Device 4
                        11,   //Device 5
                        25,   //Device 6
                        27,   //Device 7
                        29,   //Device 8
                        15,     //Device 9
                        17,   //Device 10
                        19,   //Device 11
                        21,   //Device 12
                        23,   //Device 13
                        35,   //Device 14
                        37,   //Device 15
                        39,   //Device 16
                      };

void setup() {
  for (int channel = 1; channel <= 16; channel++) {
    pinMode(STEPPIN[channel], OUTPUT);
    pinMode(DIRPIN[channel], OUTPUT);
  }

  for (int i = 0; i<17; i++){
    pitchShift[i] = 1.000;
  }

  //If you're curious how microperiods are calculated:
  //Serial.begin(250000);
  //period_lib();
  //pitchbend_Calculate();

  usbMIDI.setHandleNoteOff(OnNoteOff);
  usbMIDI.setHandleNoteOn(OnNoteOn);
  usbMIDI.setHandlePitchChange(OnPitchChange);

  myTimer.begin(processNotes, RESOLUTION);
}

void loop() {
  usbMIDI.read();
}

void OnNoteOn(byte channel, byte note, byte velocity) {
  currentNote[channel] = note;
  note2note = note % 12;
  note2octave = note / 12;
  if (note2octave < 4) { //0-48
    basePeriod[channel] = period[note2note];
  }
  else if (note2octave < 5) { //49-60
    basePeriod[channel] = period[12 + note2note];
  }
  else if (note2octave < 6) { //61-72
    basePeriod[channel] = period[24 + note2note];
  }
  else if (note2octave < 7) { //73-84
    basePeriod[channel] = period[36 + note2note];
  }
  else if (note2octave < 8) { //85-96
    basePeriod[channel] = period[48 + note2note];
  }
  else if (note == 127) {
    resetDrives();
  }
}

void OnNoteOff(byte channel, byte note, byte velocity) {
  if (currentNote[channel] == note) {
    basePeriod[channel] = 0;
  }
}

void OnPitchChange(byte channel, int pitch) {
  pitch = pitch / 100;
  pitchShift[channel] = pitchfactor[pitch+81];
  Serial.println(pitch);
}

void processNotes() {
  for (byte channel = 1; channel <= 16; channel++) {
    if (basePeriod[channel]) {                                                            // if currentPeriod of a channel is nonzero
      if (currentTick[channel] >= basePeriod[channel] / pitchShift[channel]) {            //and if the currentTick has past its period including pitch bends
        currentTick[channel] = 0;                                                         //reset the tick count
        if (currentPosition[channel] >= MAX_POSITION) {    // check if direction needs to change due to read carriage bounds
          currentPosition[channel] = 0;
          currentStateDir[channel] = !currentStateDir[channel];
          digitalWrite(DIRPIN[channel], currentStateDir[channel]) ;
        }
        currentPosition[channel]++;
        currentStateStep[channel] = !currentStateStep[channel];                             //Step by changing the pin state
        digitalWrite(STEPPIN[channel], currentStateStep[channel]) ;

      }
      else currentTick[channel] += RESOLUTION;
    }
  }
}

void period_lib() {     // generates the periods used. Equation derived from site: http://www.phy.mtu.edu/~suits/NoteFreqCalcs.html
  float c0 = 16.35;
  float a = 1.059463094359;
  long period_data[128];

  for (int i = 0; i < 128; i++) {
    period_data[i] = long(1000000 / (c0 * pow(a, i)));
    if ((i % 12) < 1) Serial.println();
    Serial.print(period_data[i]);
    Serial.print(" , ");
  }
}

void pitchbend_Calculate() {
  for (int pitchbend = 0; pitchbend <= 163; pitchbend++) {
    pitchfactor[pitchbend] = pow(2.0, (pitchbend - 81.5) / 81.5); //calculates ratio f_new/f_old
    if ((pitchbend % 20) < 1) Serial.println();
    Serial.print(pitchfactor[pitchbend], 3);
    Serial.print(" , ");
  }
}

void resetDrives() {
  //Serial.println("resetDrives activated");
  myTimer.end();                                                                 //Turn Interrupt off
  for (byte channel = 1; channel <= 16; channel++) {                                        // Set all drives direction to backwards
    currentStateDir[channel] = HIGH;
    digitalWrite(DIRPIN[channel], currentStateDir[channel]);
  }
  for (byte t = 0; t < 200; t++) {                                                          // All drives go backwards 200 ticks (max is 158)
    for (byte channel = 1; channel <= 16; channel++) {
      currentStateStep[channel] = !currentStateStep[channel];
      digitalWrite(STEPPIN[channel], currentStateStep[channel]);
    }
    delayMicroseconds(7645);                                                                  // add delay
  }
  for (byte channel = 1; channel <= 16; channel++) {                                         // Set all drives direction to forwards
    currentStateDir[channel] = LOW;
    digitalWrite(DIRPIN[channel], currentStateDir[channel]);
    currentPosition[channel] = 0;
  }
  myTimer.begin(processNotes, RESOLUTION);                                                   // Turn interrupt back on
}
