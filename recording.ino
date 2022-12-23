void startRecording() {
  
  magnetBtnState = digitalRead(magnetBtnPin);
  //magnet
  if(magnet_prevState != magnetBtnState){
    magnet_memory[magnet_index] = magnetBtnState;
    seq_pointer[seq_index] = 5000 + magnet_index;
    magnet_index++;
    seq_index++;
  }
  magnet_prevState = magnetBtnState;
  
  //  motor 1
  if (m1_prevDist != counter1) {
    gotoPosition(counter1, 1, stepPin1, dirPin1);
    m1_memory[m1_index] = counter1;
    seq_pointer[seq_index] = 1000 + m1_index;
    m1_index++;
    seq_index++;
  }
  m1_prevDist = counter1;

  //motor 2
  if (m2_prevDist != counter2) {
    gotoPosition(counter2, 2, stepPin2, dirPin2);
    m2_memory[m2_index] = counter2;
    seq_pointer[seq_index] = 2000 + m2_index;
    m2_index++;
    seq_index++;
  }
  m2_prevDist = counter2;

  //motor 3
  if (m3_prevDist != counter3) {
    gotoPosition(counter3, 3, stepPin3, dirPin3);
    m3_memory[m3_index] = counter3;
    seq_pointer[seq_index] = 3000 + m3_index;
    m3_index++;
    seq_index++;
  }
  m3_prevDist = counter3;
}
