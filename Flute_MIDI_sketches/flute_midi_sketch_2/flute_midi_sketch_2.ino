#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

///////////////////////////////////// LIST OF FLUTE FINGERING PATTERNS ////////////////////////////////////

// Each pattern is based off flute fingerings. The position of each list element corresponds with Pin number.
// **Reminder** Pin(1) (TX pin) cannot be used since it cannot act as an input. Therefore, the Pin order starts-
// with Pin(0), then Pin(2), then Pin(3) and so on until Pin(9). Half steps are represented in flat (or 'b').
// '0' means button is open. '1' means button is closed.

int flute_c_five[]    = { 0, 1, 0, 0, 0, 0, 0, 0, 1 };    // Pitch = 72
int flute_db_five[]   = { 0, 0, 0, 0, 0, 0, 0, 0, 1 };    // Pitch = 73
int flute_d_five[]    = { 1, 0, 1, 1, 0, 1, 1, 1, 0 };    // Pitch = 74
int flute_eb_five[]   = { 1, 0, 1, 1, 0, 1, 1, 1, 1 };    // Pitch = 75
int flute_e_five[]    = { 1, 1, 1, 1, 0, 1, 1, 0, 1 };    // Pitch = 76
int flute_f_five[]    = { 1, 1, 1, 1, 0, 1, 0, 0, 1 };    // Pitch = 77
int flute_gb_five[]   = { 1, 1, 1, 1, 0, 0, 0, 1, 1 };    // Pitch = 78
int flute_g_five[]    = { 1, 1, 1, 1, 0, 0, 0, 0, 1 };    // Pitch = 79
int flute_ab_five[]   = { 1, 1, 1, 1, 1, 0, 0, 0, 1 };    // Pitch = 80
int flute_a_five[]    = { 1, 1, 1, 0, 0, 0, 0, 0, 1 };    // Pitch = 81
int flute_bb_five[]   = { 1, 1, 0, 0, 0, 1, 0, 0, 1 };    // Pitch = 82
int flute_b_five[]    = { 1, 1, 0, 0, 0, 0, 0, 0, 1 };    // Pitch = 83


///////////////////////////////////// CHANGING VARIABLES AND LISTS /////////////////////////////////////

bool active_note = false;     // 'false' means note is off. 'true' means note is on.
int pitch = 0;                // MIDI value for given note (ie, '72' is note C5).
int pitch_mem = 0;            // memory pitch MIDI value.
int velocity = 64;            // Dynamic for the note (Volume or Gain). Between 0 (silent) and 127 (loudest).
int channel = 1;              // MIDI channel to send message ('1' by default).

int noteon_threshold = 200;   // threshold to trigger the active_note to true.
int noteoff_threshold = 50;   // threshold to trigger the active_note to false.
int snapshot[] = { 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // list that scans for the thresholds.
int snapshot_mem[] = { 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // list that takes the previous snapshot and applies it back again.

int delaytimer = 1; // timer setting for the delays

///////////////////////////////////////////// MAIN PROGRAM /////////////////////////////////////////////

void check_fingering() {

// Since pins are INPUT_PULLUP, voltage is being sent through them and read as HIGH when open.
// Function 'sensefinger' reads pin states and returns opposite voltage values. 
// **Reminder** HIGH is read as '1' and LOW is read as '0'. '!' changes to opposite.
// In short, '0' returned if state is open. '1' returned if state is closed. 

  int sensefinger[] = {
    !digitalRead(0), !digitalRead(2), !digitalRead(3),
    !digitalRead(4), !digitalRead(5), !digitalRead(6),
    !digitalRead(7), !digitalRead(8), !digitalRead(9)
    };
  
// The following lines check to see if 'sensefinger' matches any known pattern.
// This sets the pitch for the MIDI message.

// C5 //

  if (sensefinger[0] == flute_c_five[0] && sensefinger[1] == flute_c_five[1] && sensefinger[2] == flute_c_five[2] &&
      sensefinger[3] == flute_c_five[3] && sensefinger[4] == flute_c_five[4] && sensefinger[5] == flute_c_five[5] &&
      sensefinger[6] == flute_c_five[6] && sensefinger[7] == flute_c_five[7] && sensefinger[8] == flute_c_five[8]) {pitch = 72;}

// Db5 //
    
  else if (sensefinger[0] == flute_db_five[0] && sensefinger[1] == flute_db_five[1] && sensefinger[2] == flute_db_five[2] &&
           sensefinger[3] == flute_db_five[3] && sensefinger[4] == flute_db_five[4] && sensefinger[5] == flute_db_five[5] &&
           sensefinger[6] == flute_db_five[6] && sensefinger[7] == flute_db_five[7] && sensefinger[8] == flute_db_five[8]) {pitch = 73;}

// D5 //
    
  else if (sensefinger[0] == flute_d_five[0] && sensefinger[1] == flute_d_five[1] && sensefinger[2] == flute_d_five[2] &&
           sensefinger[3] == flute_d_five[3] && sensefinger[4] == flute_d_five[4] && sensefinger[5] == flute_d_five[5] &&
           sensefinger[6] == flute_d_five[6] && sensefinger[7] == flute_d_five[7] && sensefinger[8] == flute_d_five[8]) {pitch = 74;}

// Eb5 //
    
  else if (sensefinger[0] == flute_eb_five[0] && sensefinger[1] == flute_eb_five[1] && sensefinger[2] == flute_eb_five[2] &&
           sensefinger[3] == flute_eb_five[3] && sensefinger[4] == flute_eb_five[4] && sensefinger[5] == flute_eb_five[5] &&
           sensefinger[6] == flute_eb_five[6] && sensefinger[7] == flute_eb_five[7] && sensefinger[8] == flute_eb_five[8]) {pitch = 75;}

// E5 //
    
  else if (sensefinger[0] == flute_e_five[0] && sensefinger[1] == flute_e_five[1] && sensefinger[2] == flute_e_five[2] &&
           sensefinger[3] == flute_e_five[3] && sensefinger[4] == flute_e_five[4] && sensefinger[5] == flute_e_five[5] &&
           sensefinger[6] == flute_e_five[6] && sensefinger[7] == flute_e_five[7] && sensefinger[8] == flute_e_five[8]) {pitch = 76;}

// F5 //
    
  else if (sensefinger[0] == flute_f_five[0] && sensefinger[1] == flute_f_five[1] && sensefinger[2] == flute_f_five[2] &&
           sensefinger[3] == flute_f_five[3] && sensefinger[4] == flute_f_five[4] && sensefinger[5] == flute_f_five[5] &&
           sensefinger[6] == flute_f_five[6] && sensefinger[7] == flute_f_five[7] && sensefinger[8] == flute_f_five[8]) {pitch = 77;}

// Gb5 //
    
  else if (sensefinger[0] == flute_gb_five[0] && sensefinger[1] == flute_gb_five[1] && sensefinger[2] == flute_gb_five[2] &&
           sensefinger[3] == flute_gb_five[3] && sensefinger[4] == flute_gb_five[4] && sensefinger[5] == flute_gb_five[5] &&
           sensefinger[6] == flute_gb_five[6] && sensefinger[7] == flute_gb_five[7] && sensefinger[8] == flute_gb_five[8]) {pitch = 78;}

// G5 //
    
  else if (sensefinger[0] == flute_g_five[0] && sensefinger[1] == flute_g_five[1] && sensefinger[2] == flute_g_five[2] &&
           sensefinger[3] == flute_g_five[3] && sensefinger[4] == flute_g_five[4] && sensefinger[5] == flute_g_five[5] &&
           sensefinger[6] == flute_g_five[6] && sensefinger[7] == flute_g_five[7] && sensefinger[8] == flute_g_five[8]) {pitch = 79;}

// Ab5 //
    
  else if (sensefinger[0] == flute_ab_five[0] && sensefinger[1] == flute_ab_five[1] && sensefinger[2] == flute_ab_five[2] &&
           sensefinger[3] == flute_ab_five[3] && sensefinger[4] == flute_ab_five[4] && sensefinger[5] == flute_ab_five[5] &&
           sensefinger[6] == flute_ab_five[6] && sensefinger[7] == flute_ab_five[7] && sensefinger[8] == flute_ab_five[8]) {pitch = 80;}

// A5 //
    
  else if (sensefinger[0] == flute_a_five[0] && sensefinger[1] == flute_a_five[1] && sensefinger[2] == flute_a_five[2] &&
           sensefinger[3] == flute_a_five[3] && sensefinger[4] == flute_a_five[4] && sensefinger[5] == flute_a_five[5] &&
           sensefinger[6] == flute_a_five[6] && sensefinger[7] == flute_a_five[7] && sensefinger[8] == flute_a_five[8]) {pitch = 81;}
    
// Bb5 //
    
  else if (sensefinger[0] == flute_bb_five[0] && sensefinger[1] == flute_bb_five[1] && sensefinger[2] == flute_bb_five[2] &&
           sensefinger[3] == flute_bb_five[3] && sensefinger[4] == flute_bb_five[4] && sensefinger[5] == flute_bb_five[5] &&
           sensefinger[6] == flute_bb_five[6] && sensefinger[7] == flute_bb_five[7] && sensefinger[8] == flute_bb_five[8]) {pitch = 82;}

// B5 //
    
  else if (sensefinger[0] == flute_b_five[0] && sensefinger[1] == flute_b_five[1] && sensefinger[2] == flute_b_five[2] &&
           sensefinger[3] == flute_b_five[3] && sensefinger[4] == flute_b_five[4] && sensefinger[5] == flute_b_five[5] &&
           sensefinger[6] == flute_b_five[6] && sensefinger[7] == flute_b_five[7] && sensefinger[8] == flute_b_five[8]) {pitch = 83;}
    
  else {pitch = 0;}    
}

void check_snapshot() {
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
      active_note = true;
      check_fingering();
      if (pitch != 0) {
        MIDI.sendNoteOn(pitch, velocity, channel);
        pitch_mem = pitch;
      }
    }
  else if (active_note == true) {
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
      active_note = false;
      MIDI.sendNoteOff(pitch, velocity, channel);
    }
    check_fingering();
    if (pitch != pitch_mem){
      MIDI.sendNoteOff(pitch_mem, velocity, channel);
      MIDI.sendNoteOn(pitch, velocity, channel);
      pitch_mem = pitch;
    }
  }
}
    
void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);
  pinMode (0, INPUT_PULLUP);      //thumb key
  pinMode (2, INPUT_PULLUP);      //index LH
  pinMode (3, INPUT_PULLUP);      //middle LH
  pinMode (4, INPUT_PULLUP);      //ring LH
  pinMode (5, INPUT_PULLUP);      //pinky LH
  pinMode (6, INPUT_PULLUP);      //index RH
  pinMode (7, INPUT_PULLUP);      //middle RH
  pinMode (8, INPUT_PULLUP);      //ring RH
  pinMode (9, INPUT_PULLUP);      //pinky RH
  
}


void loop() {
  snapshot[0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
           10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
           20, 21, 22, 23, 24, 25, 26, 27, 28, 29] =
  snapshot_mem[0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
         10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
         20, 21, 22, 23, 24, 25, 26, 27, 28, 29];     
  for (int i = 0; i < 29; i++){
    snapshot[i] = analogRead(0);
    snapshot_mem[i] = snapshot[i];
    check_snapshot();
    delay(delaytimer);
  }
}
