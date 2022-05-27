#include <iostream>
#include <ctime>  // class needs this inclusion

using namespace std;
//////////////////////////////////////////
// class declaration:


class timer {
  public:
    timer();
    void           start();
    void           stop();
    void           reset();
    bool           isRunning();
    unsigned long  getTime();
    bool           isOver(unsigned long seconds);
  private:
    bool           resetted;
    bool           running;
    unsigned long  beg;
    unsigned long  end;
};


//////////////////////////////////////////
// class implementation:


timer::timer() {
  resetted = true;
  running = false;
  beg = 0;
  end = 0;
}


void timer::start() {
  if(! running) {
    if(resetted)
      beg = (unsigned long) clock();
    else
      beg -= end - (unsigned long) clock();
    running = true;
    resetted = false;
  }
}


void timer::stop() {
  if(running) {
    end = (unsigned long) clock();
    running = false;
  }
}


void timer::reset() {
  bool wereRunning = running;
  if(wereRunning)
    stop();
  resetted = true;
  beg = 0;
  end = 0;
  if(wereRunning)
    start();
}


bool timer::isRunning() {
  return running;
}


unsigned long timer::getTime() {
  if(running)
    return ((unsigned long) clock() - beg) / CLOCKS_PER_SEC;
  else
    return end - beg;
}


bool timer::isOver(unsigned long seconds) {
  return seconds >= getTime();
}


//////////////////////////////////////////
// class test program:


int main() 
{
  bool quit1 = false;
  bool quit2 = false;
  bool quit3 = false;
  bool quit4 = false;
  char choice;
  timer t;
  while(! quit1) {
    cout << "Timer for Player 1:" << endl;
    cout << " s   start/stop " << endl;
    cout << " r   reset" << endl;
    cout << " v   view time" << endl;
    cout << " q   quit" << endl;
    cout << endl;
    choice = getchar();
    switch(choice) {
      case 's':
        if(t.isRunning()) {
          t.stop();
          cout << "stopped" << endl;
        }
        else {
          t.start();
          cout << "started" << endl;
        }
        break;
      case 'r':
        t.reset();
        cout << "resetted" << endl;
        break;
      case 'v':
        cout << "time = " << t.getTime()/10 << " s" << endl;
        break;
      case 'q':
        quit1 = true;
        break;
    }
    cout << "------------------------------" << endl;
  }
  timer z;
  while(! quit2) {
    cout << "Timer for Player 2:" << endl;
    cout << " s   start/stop " << endl;
    cout << " r   reset" << endl;
    cout << " v   view time" << endl;
    cout << " q   quit" << endl;
    cout << endl;
    choice = getchar();
    switch(choice) {
      case 's':
        if(z.isRunning()) {
          z.stop();
          cout << "stopped" << endl;
        }
        else {
          z.start();
          cout << "started" << endl;
        }
        break;
      case 'r':
        z.reset();
        cout << "resetted" << endl;
        break;
      case 'v':
        cout << "time = " << z.getTime()/10 << " s" << endl;
        break;
      case 'q':
        quit2 = true;
        break;
    }
    cout << "------------------------------" << endl;
  }
  while(! quit3) {
    cout << "Timer for Player 1:" << endl;
    cout << " s   start/stop " << endl;
    cout << " r   reset" << endl;
    cout << " v   view time" << endl;
    cout << " q   quit" << endl;
    cout << endl;
    choice = getchar();
    switch(choice) {
      case 's':
        if(t.isRunning()) {
          t.stop();
          cout << "stopped" << endl;
        }
        else {
          t.start();
          cout << "started" << endl;
        }
        break;
      case 'r':
        t.reset();
        cout << "resetted" << endl;
        break;
      case 'v':
        cout << "time = " << t.getTime()/10 << " s" << endl;
        break;
      case 'q':
        quit3 = true;
        break;
    }
    cout << "------------------------------" << endl;
  }
  while(! quit4) {
    cout << "Timer for Player 2:" << endl;
    cout << " s   start/stop " << endl;
    cout << " r   reset" << endl;
    cout << " v   view time" << endl;
    cout << " q   quit" << endl;
    cout << endl;
    choice = getchar();
    switch(choice) {
      case 's':
        if(z.isRunning()) {
          z.stop();
          cout << "stopped" << endl;
        }
        else {
          z.start();
          cout << "started" << endl;
        }
        break;
      case 'r':
        z.reset();
        cout << "resetted" << endl;
        break;
      case 'v':
        cout << "time = " << z.getTime()/10 << " s" << endl;
        break;
      case 'q':
        quit4 = true;
        break;
    }
    cout << "------------------------------" << endl;
  }
  return 0;
}