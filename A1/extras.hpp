class Chair {
    unsigned char state;
public:
    Chair() {
        state = 0;
    };

    bool C() { return state & 0x01; }
    bool F() { return state & 0x02; }
    bool B() { return state & 0x04; }
    bool S() { return state & 0x08; }
    bool P() { return state & 0x10; }

    
};
