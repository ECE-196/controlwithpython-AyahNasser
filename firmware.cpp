
const int LED{14};

// add these
const int S_OK{0xaa};
const int S_ERR{0xff};

void on_receive(void* event_handler_arg, esp_event_base_t event_base, int32_t event_id, void* event_data) {
    // read one byte
    int state = USBSerial.read();

    // guard byte is valid LED state
    if (!(state == LOW || state == HIGH)) {
    // invalid byte received
    // report error
    USBSerial.write(S_ERR);
    return;
    }

    // update LED with valid state
    digitalWrite(33, state);
    USBSerial.write(S_OK);
}

 void setup() {
    pinMode(33, OUTPUT);
    pinMode(33, OUTPUT);
    // register "on_receive" as callback for RX event
    USBSerial.onEvent(ARDUINO_HW_CDC_RX_EVENT, on_receive);
    USBSerial.begin(9600);
}


void loop() {
    // digitalWrite(47, HIGH);
}