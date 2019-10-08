#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

bool note = false;
int noteon_threshold = 200;
int noteoff_threshold = 50;
int delaytimer = 1;
int snapshot[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int memory[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

void check_snapshot() {
  if (note == false) {
    if (snapshot[0] > noteon_threshold || snapshot[1] > noteon_threshold || snapshot[2] > noteon_threshold || 
        snapshot[3] > noteon_threshold || snapshot[4] > noteon_threshold || snapshot[5] > noteon_threshold || 
        snapshot[6] > noteon_threshold || snapshot[7] > noteon_threshold || snapshot[8] > noteon_threshold ||
        snapshot[9] > noteon_threshold || snapshot[10] > noteon_threshold || snapshot[11] > noteon_threshold || 
        snapshot[12] > noteon_threshold || snapshot[13] > noteon_threshold || snapshot[14] > noteon_threshold || 
        snapshot[15] > noteon_threshold || snapshot[16] > noteon_threshold || snapshot[17] > noteon_threshold || 
        snapshot[18] > noteon_threshold || snapshot[19] > noteon_threshold || snapshot[20] > noteon_threshold || 
        snapshot[21] > noteon_threshold || snapshot[22] > noteon_threshold || snapshot[23] > noteon_threshold || 
        snapshot[24] > noteon_threshold || snapshot[25] > noteon_threshold || snapshot[26] > noteon_threshold || 
        snapshot[27] > noteon_threshold || snapshot[28] > noteon_threshold || snapshot[29] > noteon_threshold) {
      note = true;
      MIDI.sendNoteOn(65, 64, 1);
    }
  }
  else if (note == true) {
    if (snapshot[0] <= noteoff_threshold && snapshot[1] <= noteoff_threshold && snapshot[2] <= noteoff_threshold && 
        snapshot[3] <= noteoff_threshold && snapshot[4] <= noteoff_threshold && snapshot[5] <= noteoff_threshold && 
        snapshot[6] <= noteoff_threshold && snapshot[7] <= noteoff_threshold && snapshot[8] <= noteoff_threshold &&
        snapshot[9] <= noteoff_threshold && snapshot[10] <= noteoff_threshold && snapshot[11] <= noteoff_threshold && 
        snapshot[12] <= noteoff_threshold && snapshot[13] <= noteoff_threshold && snapshot[14] <= noteoff_threshold && 
        snapshot[15] <= noteoff_threshold && snapshot[16] <= noteoff_threshold && snapshot[17] <= noteoff_threshold &&
        snapshot[18] <= noteoff_threshold && snapshot[19] <= noteoff_threshold && snapshot[20] <= noteoff_threshold && 
        snapshot[21] <= noteoff_threshold && snapshot[22] <= noteoff_threshold && snapshot[23] <= noteoff_threshold && 
        snapshot[24] <= noteoff_threshold && snapshot[25] <= noteoff_threshold && snapshot[26] <= noteoff_threshold && 
        snapshot[27] <= noteoff_threshold && snapshot[28] <= noteoff_threshold && snapshot[29] <= noteoff_threshold) {
      note = false;
      MIDI.sendNoteOff(65, 64, 1);
    }
  }
}

void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);
  pinMode (2, OUTPUT);
  digitalWrite(2, HIGH);
}

void loop() {
  snapshot[0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
           10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
           20, 21, 22, 23, 24, 25, 26, 27, 28, 29] =
  memory[0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
         10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
         20, 21, 22, 23, 24, 25, 26, 27, 28, 29];     
  for (int i = 0; i < 29; i++){
    snapshot[i] = analogRead(0);
    memory[i] = snapshot[i];
    check_snapshot();
    delay(delaytimer);
  }
}
