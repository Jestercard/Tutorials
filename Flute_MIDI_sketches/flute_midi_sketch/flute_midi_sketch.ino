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
int velocity = 64;            // Dynamic for the note (Volume or Gain). Between 0 (silent) and 127 (loudest).
int channel = 1;              // MIDI channel to send message ('1' by default).

///////////////////////////////////////////// MAIN PROGRAM /////////////////////////////////////////////
    
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

void loop(){
  
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
// If a pattern matches, checks to see if another note is currently being played. 
// If another note is currently active, the previous active note is turned off.
// If no active note is being played, the current pattern's note is turned on.
// If the current pitch is turned on, then no messages should be sent.

// C5 //

  if (sensefinger[0] == flute_c_five[0] && sensefinger[1] == flute_c_five[1] && sensefinger[2] == flute_c_five[2] &&
      sensefinger[3] == flute_c_five[3] && sensefinger[4] == flute_c_five[4] && sensefinger[5] == flute_c_five[5] &&
      sensefinger[6] == flute_c_five[6] && sensefinger[7] == flute_c_five[7] && sensefinger[8] == flute_c_five[8]) { 
    if (active_note == true && pitch != 72) {
      MIDI.sendNoteOff(pitch, velocity, channel);
      pitch = 72;
      MIDI.sendNoteOn(pitch, velocity, channel);   
      }
    else if (active_note == false) {
      active_note = true;
      pitch = 72;
      MIDI.sendNoteOn(pitch, velocity, channel);          
      }
    }

// Db5 //
    
  else if (sensefinger[0] == flute_db_five[0] && sensefinger[1] == flute_db_five[1] && sensefinger[2] == flute_db_five[2] &&
           sensefinger[3] == flute_db_five[3] && sensefinger[4] == flute_db_five[4] && sensefinger[5] == flute_db_five[5] &&
           sensefinger[6] == flute_db_five[6] && sensefinger[7] == flute_db_five[7] && sensefinger[8] == flute_db_five[8]) { 
    if (active_note == true && pitch != 73) {
      MIDI.sendNoteOff(pitch, velocity, channel);
      pitch = 73;
      MIDI.sendNoteOn(pitch, velocity, channel);   
      }
    else if (active_note == false) {
      active_note = true;
      pitch = 73;
      MIDI.sendNoteOn(pitch, velocity, channel);          
      }
    }

// D5 //
    
  else if (sensefinger[0] == flute_d_five[0] && sensefinger[1] == flute_d_five[1] && sensefinger[2] == flute_d_five[2] &&
           sensefinger[3] == flute_d_five[3] && sensefinger[4] == flute_d_five[4] && sensefinger[5] == flute_d_five[5] &&
           sensefinger[6] == flute_d_five[6] && sensefinger[7] == flute_d_five[7] && sensefinger[8] == flute_d_five[8]) { 
    if (active_note == true && pitch != 74) {
      MIDI.sendNoteOff(pitch, velocity, channel);
      pitch = 74;
      MIDI.sendNoteOn(pitch, velocity, channel);   
      }
    else if (active_note == false) {
      active_note = true;
      pitch = 74;
      MIDI.sendNoteOn(pitch, velocity, channel);          
      }
    }

// Eb5 //
    
  else if (sensefinger[0] == flute_eb_five[0] && sensefinger[1] == flute_eb_five[1] && sensefinger[2] == flute_eb_five[2] &&
           sensefinger[3] == flute_eb_five[3] && sensefinger[4] == flute_eb_five[4] && sensefinger[5] == flute_eb_five[5] &&
           sensefinger[6] == flute_eb_five[6] && sensefinger[7] == flute_eb_five[7] && sensefinger[8] == flute_eb_five[8]) {  
    if (active_note == true && pitch != 75) {
      MIDI.sendNoteOff(pitch, velocity, channel);
      pitch = 75;
      MIDI.sendNoteOn(pitch, velocity, channel);   
      }
    else if (active_note == false) {
      active_note = true;
      pitch = 75;
      MIDI.sendNoteOn(pitch, velocity, channel);          
      }
    }

// E5 //
    
  else if (sensefinger[0] == flute_e_five[0] && sensefinger[1] == flute_e_five[1] && sensefinger[2] == flute_e_five[2] &&
           sensefinger[3] == flute_e_five[3] && sensefinger[4] == flute_e_five[4] && sensefinger[5] == flute_e_five[5] &&
           sensefinger[6] == flute_e_five[6] && sensefinger[7] == flute_e_five[7] && sensefinger[8] == flute_e_five[8]) { 
    if (active_note == true && pitch != 76) {
      MIDI.sendNoteOff(pitch, velocity, channel);
      pitch = 76;
      MIDI.sendNoteOn(pitch, velocity, channel);   
      }
    else if (active_note == false) {
      active_note = true;
      pitch = 76;
      MIDI.sendNoteOn(pitch, velocity, channel);          
      }
    }

// F5 //
    
  else if (sensefinger[0] == flute_f_five[0] && sensefinger[1] == flute_f_five[1] && sensefinger[2] == flute_f_five[2] &&
           sensefinger[3] == flute_f_five[3] && sensefinger[4] == flute_f_five[4] && sensefinger[5] == flute_f_five[5] &&
           sensefinger[6] == flute_f_five[6] && sensefinger[7] == flute_f_five[7] && sensefinger[8] == flute_f_five[8]) { 
    if (active_note == true && pitch != 77) {
      MIDI.sendNoteOff(pitch, velocity, channel);
      pitch = 77;
      MIDI.sendNoteOn(pitch, velocity, channel);   
      }
    else if (active_note == false) {
      active_note = true;
      pitch = 77;
      MIDI.sendNoteOn(pitch, velocity, channel);          
      }
    }

// Gb5 //
    
  else if (sensefinger[0] == flute_gb_five[0] && sensefinger[1] == flute_gb_five[1] && sensefinger[2] == flute_gb_five[2] &&
           sensefinger[3] == flute_gb_five[3] && sensefinger[4] == flute_gb_five[4] && sensefinger[5] == flute_gb_five[5] &&
           sensefinger[6] == flute_gb_five[6] && sensefinger[7] == flute_gb_five[7] && sensefinger[8] == flute_gb_five[8]) { 
    if (active_note == true && pitch != 78) {
      MIDI.sendNoteOff(pitch, velocity, channel);
      pitch = 78;
      MIDI.sendNoteOn(pitch, velocity, channel);   
      }
    else if (active_note == false) {
      active_note = true;
      pitch = 78;
      MIDI.sendNoteOn(pitch, velocity, channel);          
      }
    }

// G5 //
    
  else if (sensefinger[0] == flute_g_five[0] && sensefinger[1] == flute_g_five[1] && sensefinger[2] == flute_g_five[2] &&
           sensefinger[3] == flute_g_five[3] && sensefinger[4] == flute_g_five[4] && sensefinger[5] == flute_g_five[5] &&
           sensefinger[6] == flute_g_five[6] && sensefinger[7] == flute_g_five[7] && sensefinger[8] == flute_g_five[8]) { 
    if (active_note == true && pitch != 79) {
      MIDI.sendNoteOff(pitch, velocity, channel);
      pitch = 79;
      MIDI.sendNoteOn(pitch, velocity, channel);   
      }
    else if (active_note == false) {
      active_note = true;
      pitch = 79;
      MIDI.sendNoteOn(pitch, velocity, channel);          
      }
    }

// Ab5 //
    
  else if (sensefinger[0] == flute_ab_five[0] && sensefinger[1] == flute_ab_five[1] && sensefinger[2] == flute_ab_five[2] &&
           sensefinger[3] == flute_ab_five[3] && sensefinger[4] == flute_ab_five[4] && sensefinger[5] == flute_ab_five[5] &&
           sensefinger[6] == flute_ab_five[6] && sensefinger[7] == flute_ab_five[7] && sensefinger[8] == flute_ab_five[8]) { 
    if (active_note == true && pitch != 80) {
      MIDI.sendNoteOff(pitch, velocity, channel);
      pitch = 80;
      MIDI.sendNoteOn(pitch, velocity, channel);   
      }
    else if (active_note == false) {
      active_note = true;
      pitch = 80;
      MIDI.sendNoteOn(pitch, velocity, channel);          
      }
    }

// A5 //
    
  else if (sensefinger[0] == flute_a_five[0] && sensefinger[1] == flute_a_five[1] && sensefinger[2] == flute_a_five[2] &&
           sensefinger[3] == flute_a_five[3] && sensefinger[4] == flute_a_five[4] && sensefinger[5] == flute_a_five[5] &&
           sensefinger[6] == flute_a_five[6] && sensefinger[7] == flute_a_five[7] && sensefinger[8] == flute_a_five[8]) { 
    if (active_note == true && pitch != 81) {
      MIDI.sendNoteOff(pitch, velocity, channel);
      pitch = 81;
      MIDI.sendNoteOn(pitch, velocity, channel);   
      }
    else if (active_note == false) {
      active_note = true;
      pitch = 81;
      MIDI.sendNoteOn(pitch, velocity, channel);          
      }
    }
    
// Bb5 //
    
  else if (sensefinger[0] == flute_bb_five[0] && sensefinger[1] == flute_bb_five[1] && sensefinger[2] == flute_bb_five[2] &&
           sensefinger[3] == flute_bb_five[3] && sensefinger[4] == flute_bb_five[4] && sensefinger[5] == flute_bb_five[5] &&
           sensefinger[6] == flute_bb_five[6] && sensefinger[7] == flute_bb_five[7] && sensefinger[8] == flute_bb_five[8]) { 
    if (active_note == true && pitch != 82) {
      MIDI.sendNoteOff(pitch, velocity, channel);
      pitch = 82;
      MIDI.sendNoteOn(pitch, velocity, channel);   
      }
    else if (active_note == false) {
      active_note = true;
      pitch = 82;
      MIDI.sendNoteOn(pitch, velocity, channel);          
      }
    }

// B5 //
    
  else if (sensefinger[0] == flute_b_five[0] && sensefinger[1] == flute_b_five[1] && sensefinger[2] == flute_b_five[2] &&
           sensefinger[3] == flute_b_five[3] && sensefinger[4] == flute_b_five[4] && sensefinger[5] == flute_b_five[5] &&
           sensefinger[6] == flute_b_five[6] && sensefinger[7] == flute_b_five[7] && sensefinger[8] == flute_b_five[8]) { 
    if (active_note == true && pitch != 83) {
      MIDI.sendNoteOff(pitch, velocity, channel);
      pitch = 83;
      MIDI.sendNoteOn(pitch, velocity, channel);   
      }
    else if (active_note == false) {
      active_note = true;
      pitch = 83;
      MIDI.sendNoteOn(pitch, velocity, channel);          
      }
    }
    
// If the pattern returns as unknown note (or all open), turns off any active note 
// and keeps cycling until a new pattern is detected.
// A delay is set to keep the program running stable.

  else {
    if (active_note == true) {
      MIDI.sendNoteOff(pitch, velocity, channel);
      active_note = false; 
      pitch = 0;
      }    
  }
  delay(5);
}
